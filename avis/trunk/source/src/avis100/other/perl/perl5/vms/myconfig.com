$! #!/bin/sh  ---> MYCONFIG.COM

$! # This script is designed to provide a handy summary of the configuration
$! # information being used to build perl. This is especially useful if you
$! # are requesting help from comp.lang.perl.misc on usenet or via mail.

$! DCL-ified by Peter Prymmer <pvhp@lns62.lns.cornell.edu> 22-DEC-1995
$! DCL usage (choose one):
$!      @MYCONFIG                                                       !or
$!      @MYCONFIG/OUTPUT=MYCONFIG.OUT                                   !or
$!      @MYCONFIG [node::][which$disk:][[dir.subdir]]CONFIG.SH          !or
$!      @MYCONFIG/OUTPUT=MYCONFIG.OUT [node::][w$disk:][[dir]]CONFIG.SH
$!  version 2:
$! Incorporates Charles Bailey's ideas about bootstrapping system info - 
$! myconfig.com is now callable as a "myconfig" target in your maker and
$! may even work if miniperl.exe and config.sh files fail to be made.
$! Thus if: 
$!      MMK/DESCRIP=[.VMS]                             !(or MMS or MAKE)
$! does not work then try:
$!      MMK/DESCRIP=[.VMS]/OUTPUT=MYPERLBUILD.PROBLEM  !(or MMS or MAKE)
$! Then discuss the MYPERLBUILD.PROBLEM file with a local expert.
$! If that still does not work then try:
$!      MMK/DESCRIP=[.VMS]/OUT=MYNONFIG.OUT MYCONFIG   !(or MMS or MAKE)
$! send output (MYNONFIG.OUT) to an outside expert and ask politely for help.

$ ECHO = "WRITE SYS$OUTPUT " 
$ RATHER_LONG_DEFAULT_DIRECTORY_NAME = F$ENVIRONMENT("DEFAULT")

$ if (p1.nes."").and.(p2.eqs."")
$   then RATHER_LONG_FILENAME_TO_FIND = p1 !no typo-checking (experts only)
$   else RATHER_LONG_FILENAME_TO_FIND = "CONFIG.SH"
$ endif
$Research:
$ RATHER_LONG_FILENAME_SEARCH = F$Search(RATHER_LONG_FILENAME_TO_FIND)
$ if RATHER_LONG_FILENAME_SEARCH.EQS."" 
$   then
$     if f$parse(f$environment("DEFAULT"),,,"DIRECTORY",).NES."[000000]"
$       then 
$         set default [-]
$         goto Research
$       else
$ 	  ECHO "Can't find the perl config.sh file produced by Configure"
$         set default 'RATHER_LONG_DEFAULT_DIRECTORY_NAME'
$!         exit 3
$         goto cannot_find_config_sh
$     endif
$ endif

$ open/read RATHER_LONG_CONFIG_FILE_HANDLE 'RATHER_LONG_FILENAME_SEARCH' 
$Loop:
$  read/end_of_file = Done RATHER_LONG_CONFIG_FILE_HANDLE  line
$  name = f$extract(0,f$locate("=",line),line)
$  start = f$locate("'",line)+1
$  stop = f$locate("'",line)
$  value = f$extract(start,stop-start,line)
$  if (f$locate("#",name).eqs.f$length(name)).and. -
      (name.nes."").and. -
      (name.nes."'") -               !bug in genconfig.pl (vms) for osvers='' ?
        then $$'name' = "'" + value  !$ not necessary but looks more sh-ish
$ goto Loop

$Done:
$ close RATHER_LONG_CONFIG_FILE_HANDLE 
$ goto spit_it_out

$cannot_find_config_sh:
$! these parameters are assumed to be passed from make/mm[s|k]:
$!   p1=$(CC),    p2=$(CFLAGS), p3=$(LINKFLAGS), 
$!   p4=$(LIBS1), p5=$(LIBS2),  p6=$(SOCKLIB),
$!   p7=$(EXT),   p8=$(DBG)
$! so assign to appropriate $var:
$ $cc = "'"+p1+"'"            ! p1=$(CC) from make
$ $ccflags = "'"+p2+"'"       ! p2=$(CFLAGS) from make
$ $ldflags = "'"+p3+"'"       ! p3=$(LINKFLAGS) from make 
$ $libs = "'"+p4+" "+p5+" "+p6+"'" ! p4$(LIBS1),p5$(LIBS2),p6$(SOCKLIB)frm make
$ $staticexts = "'"+p7+"'"         ! p7=$(EXT) from make

$!  hard-coded stuff (for now): 
$ $cppflags = "'"+"'"  !(vestigal)
$ $optimize = "'"+"'"  !descrip.mms has /Optimize=2 in $(XTRACCFLAGS)

$!  following assigns done via `dcl` calls in genconfig.pl anyway:
$ $osname = "'"+f$edit(f$getsyi("NODE_SWTYPE"),"COLLAPSE") !genconfig.pl has "osname='VMS'"
$ $osvers = f$edit(f$getsyi("VERSION")-"V","COLLAPSE")
$ if f$getsyi("HW_MODEL").GT.1024
$   then $$archname = "'VMS_AXP'"  !string from descrip.mms vmsperl 12-21-95
$   else $$archname = "'VMS_VAX'"  !string from descrip.mms vmsperl 12-21-95
$ endif
$ $myname = ""
$  if $myname.eqs."" then $$myname = f$trnlnm("ARPANET_HOST_NAME")
$  if $myname.eqs."" then $$myname = f$trnlnm("INTERNET_HOST_NAME")
$  if $myname.eqs."" then $$myname = f$trnlnm("MULTINET_HOST_NAME")
$  if $myname.eqs."" then $$myname = f$trnlnm("UCX$INET_HOST_NAME")
$  if $myname.eqs."" then $$myname = f$trnlnm("TCPWARE_DOMAINNAME")
$  if $myname.eqs."" then $$myname = f$trnlnm("NEWS_ADDRESS")
$  if $myname.eqs."" then $$myname = f$trnlnm("SYS$NODE")
$!  Is this same as genconfig.pl ? (spacing/order unknown):
$ $myuname=$osname+" "+$myname+" "+$osvers+" "+F$GetSyi("HW_NAME")+"'"
$ $osname = $osname+"'"
$ $osvers = "'"+$osvers+"'"

$look_for_patchlevel_h:
$!
$ RATHER_LONG_FILENAME_TO_FIND = "PATCHLEVEL.H"
$Research_patchlevel_h:
$ RATHER_LONG_FILENAME_SEARCH = F$Search(RATHER_LONG_FILENAME_TO_FIND)
$ if RATHER_LONG_FILENAME_SEARCH.EQS."" 
$   then
$     if f$parse(f$environment("DEFAULT"),,,"DIRECTORY",).NES."[000000]"
$       then 
$         set default [-]
$         goto Research_patchlevel_h
$       else
$ 	  ECHO "Can't find the header file patchlevel.h used to make config.sh"
$         set default 'RATHER_LONG_DEFAULT_DIRECTORY_NAME'
$         goto look_for_genconfig.pl
$     endif
$ endif

$ open/read RATHER_LONG_CONFIG_FILE_HANDLE 'RATHER_LONG_FILENAME_SEARCH' 
$read_patchlevel_h:
$ read/end_of_file = patchlevel_h_Done RATHER_LONG_CONFIG_FILE_HANDLE  line
$ if f$locate("PATCHLEVEL",line).ne.f$length(line)
$   then
$     line = f$edit(line,"TRIM,COMPRESS")
$     $PATCHLEVEL = f$element(2," ",line)
$     if f$type($SUBVERSION).nes."" then goto patchlevel_h_Done
$ endif
$ if f$locate("SUBVERSION",line).ne.f$length(line)
$   then
$     line = f$edit(line,"TRIM,COMPRESS")
$     $SUBVERSION = f$element(2," ",line)
$     if f$type($PATCHLEVEL).nes."" then goto patchlevel_h_Done
$ endif
$ goto read_patchlevel_h

$patchlevel_h_Done:
$ close RATHER_LONG_CONFIG_FILE_HANDLE 
$ if $PATCHLEVEL.eqs.""
$   then
$     echo "warning: PATCHLEVEL was not found in ''RATHER_LONG_FILENAME_TO_FIND':" 
$ endif

$look_for_genconfig_pl:
$!
$ if f$search("VMS.DIR").nes."" then set default [.vms]
$ RATHER_LONG_FILENAME_TO_FIND = "GENCONFIG.PL"
$ genconfig_pl_dir = ""
$Research_genconfig_pl:
$ RATHER_LONG_FILENAME_SEARCH = F$Search(RATHER_LONG_FILENAME_TO_FIND)
$ if RATHER_LONG_FILENAME_SEARCH.EQS."" 
$   then
$     if f$parse(f$environment("DEFAULT"),,,"DIRECTORY",).NES."[000000]"
$       then 
$         set default [-]
$         goto Research_genconfig_pl
$       else
$ 	  ECHO "Can't find the perl genconfig.pl used to make config.sh"
$         set default 'RATHER_LONG_DEFAULT_DIRECTORY_NAME'
$         goto look_for_config_vms
$     endif
$   else    !genconfig.pl has been found
$     genconfig_pl_dir = f$parse(f$environment("DEFAULT"),,,"DIRECTORY",)
$ endif

$ cnfg_keys = "package/hintfile/ld/dlext/d_stdstdio/"
$ cnfg_keys = cnfg_keys + "usevfork/usemymalloc/so/libpth/"
$ cnfg_keys = cnfg_keys + "dlsrc/cccdlflags/ccdlflags/lddlflags/"

$ cnfg_vars = "$package/$hint/$ld/$dlext/$d_stdstdio/"
$ cnfg_vars = cnfg_vars + "$usevfork/$usemymalloc/$so/$libpth/"
$ cnfg_vars = cnfg_vars + "$dlsrc/$cccdlflags/$ccdlflags/$lddlflags/" 

$ open/read RATHER_LONG_CONFIG_FILE_HANDLE 'RATHER_LONG_FILENAME_SEARCH' 
$read_genconfig_pl:
$ read/end_of_file = Genconfig_pl_Done RATHER_LONG_CONFIG_FILE_HANDLE  line
$ if f$locate("=",line).ne.f$length(line)   !then may be an assigment
$   then
$     name = f$edit( f$extract(0,f$locate("=",line),line), "COLLAPSE")
$     num = 0
$key_genconfig_pl:
$     key = f$element(num,"/",cnfg_keys)
$     if (key .nes. "/").and.(key .nes. "") !not end of cnfg_keys
$       then
$         if key.eqs.name  !then is key
$           then
$             start = f$locate("=",line)+1
$             stop = f$length(line)
$             value = f$extract(start,stop-start,line)
$             var = f$element(num,"/",cnfg_vars)
$             'var' = value  
$             cnfg_keys = cnfg_keys - ("''name'/" ) !trim to shorten future matches
$             cnfg_vars = cnfg_vars - ("''var'/" ) !trim to shorten future matches
$         endif
$         num = num + 1
$         goto key_genconfig_pl
$     endif ! not end of cnfg_keys
$ endif ! then may be an assigment
$ goto read_genconfig_pl

$Genconfig_pl_Done:
$ close RATHER_LONG_CONFIG_FILE_HANDLE 
$ if cnfg_vars.nes.""
$   then
$     echo "warning: the following variables were not found in ''RATHER_LONG_FILENAME_TO_FIND':" 
$     echo "''cnfg_vars'"
$ endif

$ if (p8.nes."").and.($ld.nes."") then $ld = $ld + " DBG='"+p8+"'" 

$look_for_config_vms:
$ RATHER_LONG_FILENAME_TO_FIND = "''genconfig_pl_dir'CONFIG.VMS"

$Research_config_vms:
$ RATHER_LONG_FILENAME_SEARCH = F$Search(RATHER_LONG_FILENAME_TO_FIND)
$ if RATHER_LONG_FILENAME_SEARCH.EQS."" 
$   then
$     if f$parse(f$environment("DEFAULT"),,,"DIRECTORY",).NES."[000000]"
$       then 
$         set default [-]
$         goto Research_config_vms
$       else
$ 	  ECHO "Can't find the perl config.vms used to make config.sh"
$         set default 'RATHER_LONG_DEFAULT_DIRECTORY_NAME'
$         stop
$         exit 3 
$     endif
$ endif

$ cnfg_keys = "MEM_ALIGNBYTES/CASTNEGFLOAT/CASTFLAGS/RANDBITS/STDCHAR/"
$ cnfg_keys = cnfg_keys+"CASTI32/INTSIZE/VOIDFLAGS/DLSYM_NEEDS_UNDERSCORE"

$ cnfg_vars = "$alignbytes/$d_castneg/$castflags/$randbits/$stdchar/"
$ cnfg_vars = cnfg_vars+"$d_casti32/$intsize/$voidflags/$d_dlsymun/"

$ open/read RATHER_LONG_CONFIG_FILE_HANDLE 'RATHER_LONG_FILENAME_SEARCH' 
$read_config_vms:
$ read/end_of_file = config_vms_Done RATHER_LONG_CONFIG_FILE_HANDLE  line
$! look for "#define" or "#undef"
$ if (f$length(line).ne.0).and.-
   ((f$locate("#define",line).eq.0).or.(f$locate("#undef",line).eq.0)) 
$   then
$     line = f$edit(line,"COMPRESS, TRIM")
$     name = f$element(1," ",line) !macro
$     num = 0
$key_config_vms:
$     key = f$element(num,"/",cnfg_keys)
$     if (key .nes. "/").and.(key .nes. "") !not end of cnfg_keys
$       then
$         if key.eqs.name  !then is key
$           then
$             var = f$element(num,"/",cnfg_vars)
$             cnfg_keys = cnfg_keys - ("''name'/" ) !trim to shorten future matches
$             cnfg_vars = cnfg_vars - ("''var'/" ) !trim to shorten future matches
$             if (f$locate("#undef",line).eq.0)
$               then
$                 'var' = "'undef'"
$               else                  !is a #define
$strip_comment:
$                 start = f$locate("/*",line)
$                 if start.ne.f$length(line) !comment started
$                   then
$                     if f$locate("*/",line).ne.f$length(line) !comment stopped
$                       then stop = f$locate("*/",line)+2
$                       else stop = f$locate("*/",line)
$                     endif
$                     comment = f$extract(start,stop-start,line)
$                     line = line - comment
$                     goto strip_comment
$                 endif
$                 line = f$edit(line,"TRIM")
$                 start = f$locate(key,line)+f$length(key)
$                 stop = f$length(line)
$                 value = f$edit(f$extract(start,stop-start,line),"TRIM")
$                 if (value.nes."") 
$                   then 
$                     'var' = "'"+value+"'"
$                   else 
$                     'var' = "'define'"
$                 endif
$             endif            !#define
$         endif                ! is key of interest
$         num = num + 1
$         goto key_config_vms
$     endif ! not end of cnfg_keys
$ endif ! then may be #define or #undef of interest
$ goto read_config_vms

$config_vms_Done:
$ close RATHER_LONG_CONFIG_FILE_HANDLE 
$ if cnfg_vars.nes.""
$   then
$     echo "warning: the following variables were not found in ''RATHER_LONG_FILENAME_TO_FIND':" 
$     echo "''cnfg_vars'"
$ endif

$spit_it_out:
$! $spitshell = ECHO !<<!GROK!THIS! 
$ ECHO " "
$ ECHO "Summary of my ''$package' (patchlevel ''$PATCHLEVEL' subversion ''$SUBVERSION') configuration:"
$ ECHO "  Platform:"
$ ECHO "    osname=''$osname', osvers=''$osvers', archname=''$archname'"
$ ECHO "     uname=''$myuname'"                             !->d_has_uname?
$ ECHO "     hint=''$hint' d_sigaction='undef'"             !->hintfile?
$ ECHO "     static exts=''$staticexts'"                    ! added for VMS
$ ECHO "   Compiler:"
$ ECHO "     cc=''$cc', optimize=''$optimize', ld=''$ld'"
$ ECHO "     cppflags=''$cppflags'"
$ ECHO "     ccflags =''$ccflags'"                          !->vms_cc_type?
$ ECHO "     ldflags =''$ldflags'"
$ ECHO "     stdchar=''$stdchar', d_stdstdio=''$d_stdstdio', usevfork=''$usevfork'"
$ ECHO "     voidflags=''$voidflags', castflags=''$castflags', d_casti32=''$d_casti32', d_castneg=''$d_castneg'"
$ ECHO "     intsize=''$intsize', alignbytes=''$alignbytes', usemymalloc=''$usemymalloc', randbits=''$randbits'"
$ ECHO "   Libraries:"
$ ECHO "     so=''$so'"
$ ECHO "     libpth=''$libpth'"
$ ECHO "     libs=''$libs'"
$ ECHO "     libc=''$libc'"
$ ECHO "   Dynamic Linking:"
$ ECHO "     dlsrc=''$dlsrc', dlext=''$dlext', d_dlsymun=''$d_dlsymun'"
$ ECHO "     cccdlflags=''$cccdlflags', ccdlflags=''$ccdlflags', lddlflags=''$lddlflags'"
$ ECHO " " 
$ !GROK!THIS!
$ SET DEFAULT 'RATHER_LONG_DEFAULT_DIRECTORY_NAME'
$ EXIT
