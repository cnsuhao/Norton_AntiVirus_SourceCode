$! INSTALL.COM -- Installs the files in a given directory tree
$!
$! Author: Richard Levitte <richard@levitte.org>
$! Time of creation: 22-MAY-1998 10:13
$!
$! P1	root of the directory tree
$!
$	IF P1 .EQS. ""
$	THEN
$	    WRITE SYS$OUTPUT "First argument missing."
$	    WRITE SYS$OUTPUT "Should be the directory where you want things installed."
$	    EXIT
$	ENDIF
$
$	ROOT = F$PARSE(P1,"[]A.;0",,,"SYNTAX_ONLY,NO_CONCEAL") - "A.;0"
$	ROOT_DEV = F$PARSE(ROOT,,,"DEVICE","SYNTAX_ONLY")
$	ROOT_DIR = F$PARSE(ROOT,,,"DIRECTORY","SYNTAX_ONLY") -
		   - "[000000." - "][" - "[" - "]"
$	ROOT = ROOT_DEV + "[" + ROOT_DIR
$
$	DEFINE/NOLOG WRK_SSLROOT 'ROOT'.] /TRANS=CONC
$	DEFINE/NOLOG WRK_SSLVLIB WRK_SSLROOT:[VAX_LIB]
$	DEFINE/NOLOG WRK_SSLALIB WRK_SSLROOT:[ALPHA_LIB]
$	DEFINE/NOLOG WRK_SSLINCLUDE WRK_SSLROOT:[INCLUDE]
$	DEFINE/NOLOG WRK_SSLVEXE WRK_SSLROOT:[VAX_EXE]
$	DEFINE/NOLOG WRK_SSLAEXE WRK_SSLROOT:[ALPHA_EXE]
$
$	IF F$PARSE("WRK_SSLROOT:[000000]") .EQS. "" THEN -
	   CREATE/DIR/LOG WRK_SSLROOT:[000000]
$	IF F$PARSE("WRK_SSLVLIB:") .EQS. "" THEN -
	   CREATE/DIR/LOG WRK_SSLVLIB:
$	IF F$PARSE("WRK_SSLALIB:") .EQS. "" THEN -
	   CREATE/DIR/LOG WRK_SSLALIB:
$	IF F$PARSE("WRK_SSLINCLUDE:") .EQS. "" THEN -
	   CREATE/DIR/LOG WRK_SSLINCLUDE:
$	IF F$PARSE("WRK_SSLVEXE:") .EQS. "" THEN -
	   CREATE/DIR/LOG WRK_SSLVEXE:
$	IF F$PARSE("WRK_SSLAEXE:") .EQS. "" THEN -
	   CREATE/DIR/LOG WRK_SSLAEXE:
$
$	EXHEADER := ssl.h,ssl2.h,ssl3.h,ssl23.h,tls1.h
$	E_EXE := ssl_task
$	LIBS := LIBSSL
$
$	VEXE_DIR := [-.VAX.EXE.SSL]
$	AEXE_DIR := [-.AXP.EXE.SSL]
$
$	COPY 'EXHEADER' WRK_SSLINCLUDE:/LOG
$
$	I = 0
$ LOOP_EXE: 
$	E = F$EDIT(F$ELEMENT(I, ",", E_EXE),"TRIM")
$	I = I + 1
$	IF E .EQS. "," THEN GOTO LOOP_EXE_END
$	SET NOON
$	IF F$SEARCH(VEXE_DIR+E+".EXE") .NES. ""
$	THEN
$	  COPY 'VEXE_DIR''E'.EXE WRK_SSLVEXE:'E'.EXE/log
$	  SET FILE/PROT=W:RE WRK_SSLVEXE:'E'.EXE
$	ENDIF
$	IF F$SEARCH(AEXE_DIR+E+".EXE") .NES. ""
$	THEN
$	  COPY 'AEXE_DIR''E'.EXE WRK_SSLAEXE:'E'.EXE/log
$	  SET FILE/PROT=W:RE WRK_SSLAEXE:'E'.EXE
$	ENDIF
$	SET ON
$	GOTO LOOP_EXE
$ LOOP_EXE_END:
$
$	I = 0
$ LOOP_LIB: 
$	E = F$EDIT(F$ELEMENT(I, ",", LIBS),"TRIM")
$	I = I + 1
$	IF E .EQS. "," THEN GOTO LOOP_LIB_END
$	SET NOON
$	IF F$SEARCH(VEXE_DIR+E+".OLB") .NES. ""
$	THEN
$	  COPY 'VEXE_DIR''E'.OLB WRK_SSLVLIB:'E'.OLB/log
$	  SET FILE/PROT=W:RE WRK_SSLVLIB:'E'.OLB
$	ENDIF
$	! Preparing for the time when we have shareable images
$	IF F$SEARCH(VEXE_DIR+E+".EXE") .NES. ""
$	THEN
$	  COPY 'VEXE_DIR''E'.EXE WRK_SSLVLIB:'E'.EXE/log
$	  SET FILE/PROT=W:RE WRK_SSLVLIB:'E'.EXE
$	ENDIF
$	IF F$SEARCH(AEXE_DIR+E+".OLB") .NES. ""
$	THEN
$	  COPY 'AEXE_DIR''E'.OLB WRK_SSLALIB:'E'.OLB/log
$	  SET FILE/PROT=W:RE WRK_SSLALIB:'E'.OLB
$	ENDIF
$	! Preparing for the time when we have shareable images
$	IF F$SEARCH(AEXE_DIR+E+".EXE") .NES. ""
$	THEN
$	  COPY 'AEXE_DIR''E'.EXE WRK_SSLALIB:'E'.EXE/log
$	  SET FILE/PROT=W:RE WRK_SSLALIB:'E'.EXE
$	ENDIF
$	SET ON
$	GOTO LOOP_LIB
$ LOOP_LIB_END:
$
$	EXIT
