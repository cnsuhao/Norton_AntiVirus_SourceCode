[Components]
component0=System Files
component1=Program Files
component2=Virus Definitions Files

[TopComponents]
component0=Program Files
component1=System Files
component2=Virus Definitions Files

[System Files]
SELECTED=Yes
FILENEED=CRITICAL
HTTPLOCATION=
STATUS=Copying Windows system files...
UNINSTALLABLE=Yes
TARGET=<WINSYS_NS>
FTPLOCATION=
VISIBLE=Yes
DESCRIPTION=
DISPLAYTEXT=
IMAGE=
DEFSELECTION=Yes
filegroup0=System DLL files
COMMENT=
INCLUDEINBUILD=Yes
INSTALLATION=NEWERVERSION\NEWERDATE
COMPRESSIFSEPARATE=No
MISC=
ENCRYPT=No
DISK=ANYDISK
TARGETDIRCDROM=
PASSWORD=
TARGETHIDDEN=Script-defined Folders\<WINSYS_NS>

[SetupType]
setuptype0=Custom

[Program Files]
SELECTED=Yes
FILENEED=CRITICAL
HTTPLOCATION=
STATUS=Copying Quarantine console files...
UNINSTALLABLE=Yes
TARGET=<TARGETDIR>
FTPLOCATION=
VISIBLE=No
DESCRIPTION=
DISPLAYTEXT=
IMAGE=
DEFSELECTION=Yes
filegroup0=COM DLL files
COMMENT=
INCLUDEINBUILD=Yes
filegroup1=DAT files
INSTALLATION=ALWAYSOVERWRITE
filegroup2=Help Files
filegroup3=Support DLL files
COMPRESSIFSEPARATE=No
MISC=
ENCRYPT=No
DISK=ANYDISK
TARGETDIRCDROM=
PASSWORD=
TARGETHIDDEN=General Application Destination

[Virus Definitions Files]
SELECTED=Yes
FILENEED=STANDARD
HTTPLOCATION=
STATUS=Copying Virus definitions...
UNINSTALLABLE=Yes
TARGET=<COMMONFILES>\Symantec Shared
FTPLOCATION=
VISIBLE=Yes
DESCRIPTION=
DISPLAYTEXT=
IMAGE=
DEFSELECTION=Yes
filegroup0=Virus Definitions
COMMENT=
INCLUDEINBUILD=Yes
INSTALLATION=ALWAYSOVERWRITE
COMPRESSIFSEPARATE=No
MISC=
ENCRYPT=No
DISK=ANYDISK
TARGETDIRCDROM=
PASSWORD=
TARGETHIDDEN=Program Files Folder\Common Files Folder\Symantec Shared

[SetupTypeItem-Custom]
Comment=
item0=System Files
item1=Program Files
Descrip=
DisplayText=

[Info]
Type=CompDef
Version=1.00.000
Name=

