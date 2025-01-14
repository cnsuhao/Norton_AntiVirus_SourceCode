#!/usr/local/bin/perl
# Borland C++ builder 3 and 4 -- Janez Jere <jj@void.si>
#

$ssl=	"ssleay32";
$crypto="libeay32";
$RSAref="RSAref32";

$o='\\';
$cp='copy';
$rm='del';

# C compiler stuff
$cc='bcc32';
$lflags="-ap -Tpe -x -Gn ";
$mlflags='';

$out_def="out32";
$tmp_def="tmp32";
$inc_def="inc32";
#enable max error messages, disable most common warnings
$cflags="-DWIN32_LEAN_AND_MEAN -j255 -w-aus -w-par -w-inl  -c -tWC -tWM -DWINDOWS -DWIN32 -DL_ENDIAN ";
if ($debug)
{
    $cflags.="-Od -y -v -vi- -D_DEBUG";
    $mlflags.=' ';
}
else
{
    $cflags.="-O2 -ff -fp";
}

$obj='.obj';
$ofile="-o";

# EXE linking stuff
$link="ilink32";
$efile="";
$exep='.exe';
if ($no_sock)
	{ $ex_libs=""; }
else	{ $ex_libs="cw32mt.lib import32.lib"; }

# static library stuff
$mklib='tlib /P64';
$ranlib='';
$plib="";
$libp=".lib";
$shlibp=($shlib)?".dll":".lib";
$lfile='';

$shlib_ex_obj="";
$app_ex_obj="c0x32.obj"; 

$asm='n_o_T_a_s_m';
$asm.=" /Zi" if $debug;
$afile='/Fo';

$bn_mulw_obj='';
$bn_mulw_src='';
$des_enc_obj='';
$des_enc_src='';
$bf_enc_obj='';
$bf_enc_src='';

if (!$no_asm)
	{
	$bn_mulw_obj='crypto\bn\asm\bn-win32.obj';
	$bn_mulw_src='crypto\bn\asm\bn-win32.asm';
	$des_enc_obj='crypto\des\asm\d-win32.obj crypto\des\asm\y-win32.obj';
	$des_enc_src='crypto\des\asm\d-win32.asm crypto\des\asm\y-win32.asm';
	$bf_enc_obj='crypto\bf\asm\b-win32.obj';
	$bf_enc_src='crypto\bf\asm\b-win32.asm';
	$cast_enc_obj='crypto\cast\asm\c-win32.obj';
	$cast_enc_src='crypto\cast\asm\c-win32.asm';
	$rc4_enc_obj='crypto\rc4\asm\r4-win32.obj';
	$rc4_enc_src='crypto\rc4\asm\r4-win32.asm';
	$rc5_enc_obj='crypto\rc5\asm\r5-win32.obj';
	$rc5_enc_src='crypto\rc5\asm\r5-win32.asm';
	$md5_asm_obj='crypto\md5\asm\m5-win32.obj';
	$md5_asm_src='crypto\md5\asm\m5-win32.asm';
	$sha1_asm_obj='crypto\sha\asm\s1-win32.obj';
	$sha1_asm_src='crypto\sha\asm\s1-win32.asm';
	$rmd160_asm_obj='crypto\ripemd\asm\rm-win32.obj';
	$rmd160_asm_src='crypto\ripemd\asm\rm-win32.asm';
	$cflags.=" -DBN_ASM -DMD5_ASM -DSHA1_ASM -DRMD160_ASM";
	}

if ($shlib)
	{
	$mlflags.=" $lflags /dll";
#	$cflags =~ s| /MD| /MT|;
	$lib_cflag=" /GD -D_WINDLL -D_DLL";
	$out_def="out32dll";
	$tmp_def="tmp32dll";
	}

sub do_lib_rule
	{
	local($objs,$target,$name,$shlib)=@_;
	local($ret,$Name);

	$taget =~ s/\//$o/g if $o ne '/';
	($Name=$name) =~ tr/a-z/A-Z/;

#	$target="\$(LIB_D)$o$target";
	$ret.="$target: $objs\n";
	if (!$shlib)
		{
		#		$ret.="\t\$(RM) \$(O_$Name)\n";
		$ret.="\techo LIB $<\n";    
		$ret.="\t\$(MKLIB) $lfile$target  \$(addprefix +, $objs)\n";
		}
	else
		{
		local($ex)=($target =~ /O_SSL/)?' $(L_CRYPTO)':'';
		$ex.=' wsock32.lib gdi32.lib';
		$ret.="\t\$(LINK) \$(MLFLAGS) $efile$target /def:ms/${Name}.def @<<\n  \$(SHLIB_EX_OBJ) $objs $ex\n<<\n";
		}
	$ret.="\n";
	return($ret);
	}

sub do_link_rule
	{
	local($target,$files,$dep_libs,$libs)=@_;
	local($ret,$_);
	
	$file =~ s/\//$o/g if $o ne '/';
	$n=&bname($targer);
	$ret.="$target: $files $dep_libs\n";
	$ret.="\t\$(LINK) \$(LFLAGS) $files \$(APP_EX_OBJ), $target,, $libs\n\n";
	return($ret);
	}

1;
