MODULE_NAME=SYMKVxD
TARGET_TYPE=VXD
.INCLUDE <PLATFORM.MAK>
.INCLUDE <ML.MAK>

ASMOPTS+= /DMASM6

DEF+= /DSYMKRNL_MODULENAME=$(Q_SYMKRNL)

LINKER=LINK386

%if "$(CV)" != ""
  LINKOPTS=/MAP/NOD/NOE/B/F/SEGMENTS:512 /CO
%else
  LINKOPTS=/MAP/NOD/NOE/B/F/SEGMENTS:512
%endif

SYSLIBS=
MAP=MAPSYM

RESFILE = symkvxd.res

$(Q_SYMKRNL).VXD: $(MODULE_NAME).386
        COPY $(MODULE_NAME).386 $(Q_SYMKRNL).VXD
        DEL  $(MODULE_NAME).386

$(MODULE_NAME).386: $(MODULE_NAME).OBJ IOSSrv.OBJ $(RESFILE) $(MODULE_NAME).DEF

$(RESFILE):    symkvxd.rc

#UPDATE#
#ENDUPDATE#
