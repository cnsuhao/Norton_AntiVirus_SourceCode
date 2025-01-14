//************************************************************************
//
// $Header:   S:/NAVEX/VCS/navexsf.cpv   1.168   11 Jan 1999 17:44:48   CNG  $
//
// Description:
//      Contains NAVEX EXTScanFile code.
//
//************************************************************************
// $Log:   S:/NAVEX/VCS/navexsf.cpv  $
// 
//    Rev 1.168   11 Jan 1999 17:44:48   CNG
// changed lpbyInfectionBuffer to lpbyWorkBuffer on TMCB
// 
//    Rev 1.167   16 Dec 1998 15:51:16   DCHI
// Removed #ifdef 0 around MSX.
// 
//    Rev 1.166   16 Dec 1998 13:29:52   DCHI
// #ifdef'd out MSX.
// 
//    Rev 1.165   09 Dec 1998 17:45:28   DCHI
// Added #include "gdefines.h"
// 
//    Rev 1.164   09 Dec 1998 14:33:36   DKESSNE
// removed #ifdefs for zoo viruses
// 
//    Rev 1.163   09 Dec 1998 12:22:28   MMAGEE
// removed #ifdef/endif for SARC_CUST_7839
// 
//    Rev 1.162   08 Dec 1998 19:10:44   ECHIEN
// Added TMCB
// 
//    Rev 1.161   08 Dec 1998 13:13:18   DCHI
// Changes for MSX.
// 
//    Rev 1.160   02 Dec 1998 14:36:28   DKESSNE
// added scan function for Lexotran, VID 0x25c5
// 
//    Rev 1.159   30 Nov 1998 17:33:14   DKESSNE
// added scan function for Zombie.ZCME.8192, 0x25c4
// 
//    Rev 1.158   30 Nov 1998 15:21:30   CFORMUL
// Added FP fix to Hare
// 
//    Rev 1.157   25 Nov 1998 15:25:46   relniti
// FP 7839 on a NAVEXSF function for Neuroquilla
// 
//    Rev 1.156   11 Nov 1998 11:33:18   MMAGEE
// removed #ifdef/endif for SARC_CST_5935
// 
//    Rev 1.155   10 Nov 1998 13:09:40   rpulint
// OS/2 platform change: ifdef'ed extern reference to glpstEngineExportTable
// declaration for NAVEX15
// 
//    Rev 1.153   06 Nov 1998 17:54:48   rpulint
// Added changes for OS/2 Platform
// 
//    Rev 1.152   04 Nov 1998 18:47:18   CFORMUL
// Added another cheese FP fix for Hare
// 
//    Rev 1.151   02 Nov 1998 11:35:06   ECHIEN
// Added new cruncher variant
// 
//    Rev 1.150   20 Oct 1998 16:01:26   DKESSNE
// change to EXTScanFileSSR19834 due to FP w/ CI 5935
// 
//    Rev 1.149   14 Oct 1998 12:16:10   MMAGEE
// removed #ifdef/endif for SARC_CST_5401, vid 0x7b70
// 
//    Rev 1.148   14 Oct 1998 10:47:04   DKESSNE
// removed ifdefs for zoo defs
// 
//    Rev 1.147   13 Oct 1998 13:46:32   DKESSNE
// added scan function for Cezar.4567
// 
//    Rev 1.146   12 Oct 1998 16:51:44   CFORMUL
// Made a fix in the Widowmaker def to detect the original sample.
// 
//    Rev 1.145   12 Oct 1998 10:59:38   CNACHEN
// Added support for AOL pws heuristics.
// 
// 
//    Rev 1.144   09 Oct 1998 17:20:42   CFORMUL
// Added Widowmake detection
// 
//    Rev 1.143   06 Oct 1998 14:44:10   CFORMUL
// Added a fix for and FP on Hare.
// 
//    Rev 1.142   05 Oct 1998 12:34:56   DKESSNE
// added detection for Lightning.4251 0x2545
// 
//    Rev 1.141   01 Oct 1998 15:52:16   DKESSNE
// added detection for variants of Vanitas.3712, VID 0x2544
// 
//    Rev 1.140   09 Sep 1998 12:44:50   ECHIEN
// Fixed bug in reloading for Sailor
// 
//    Rev 1.139   01 Sep 1998 11:42:16   AOONWAL
// Updated from SNDBOT after the corruption in USSM-SARC\VOL1
// 
//    Rev 1.139   28 Aug 1998 18:12:22   ECHIEN
// Added opcode to profile
// 
//    Rev 1.138   27 Aug 1998 14:08:26   JWILBER
// Removed SARC_ZOO #ifdefs.
//
//    Rev 1.137   27 Aug 1998 13:36:30   ECHIEN
// Removed ifdefs for SARC_ZOO_SAILOR
//
//    Rev 1.136   25 Aug 1998 23:09:14   ECHIEN
// Added Sailor.Pluto #ifdef'd with SARC_ZOO_SAILOR
//
//    Rev 1.135   24 Aug 1998 19:21:06   DKESSNE
// added EXTScanFileSSR19834 for SSR.19834 0x258a
//
//    Rev 1.134   12 Aug 1998 11:21:08   CNACHEN
// Added Strange Brew virus (Java) scanning code.
//
//    Rev 1.133   03 Aug 1998 12:14:28   PDEBATS
// Removed if/def for sarc_cst_2242 cih v1.2
//
//    Rev 1.132   07 Jul 1998 16:57:38   AOONWAL
// commented out ifdef SARC_CST_2242
//
//    Rev 1.131   02 Jul 1998 18:20:26   DCHI
// Implemented NOMACRO env var checking for building without macro engine.
//
//    Rev 1.130   30 Jun 1998 17:10:08   DKESSNE
// added CheckForPEHeader(), which is called from EXTScanFile().
// This function checks the open file for PE header, and if it has one,
// adds ID_WINDOWS to the list of Navex scan requests.
// NAV had not been scanning xcopy32.exe, since no virscan def was calling
// Navex for this file.
//
//    Rev 1.129   05 Jun 1998 19:26:30   DCHI
// #ifdef'ed out Access 2.0 scanning.
//
//    Rev 1.128   11 May 1998 18:15:34   DCHI
// Changes for Access 2.0 scanning and Access datafile conversion.
//
//    Rev 1.127   17 Apr 1998 13:43:52   DCHI
// Added ID_ACCESS97 to switch to call ExtScanFileAccess97().
//
//    Rev 1.126   13 Mar 1998 06:12:06   CFORMUL
// Added Cryptor.4161
//
//    Rev 1.125   10 Mar 1998 17:12:22   CNACHEN
// Added trojan support for all platforms.
//
//    Rev 1.124   28 Jan 1998 17:50:32   JWILBER
// Reconciled w/ DEFWORK - no real changes.
//
//    Rev 1.123   21 Jan 1998 18:02:46   CFORMUL
// Added break after call to Cryptor.2169 code
//
//    Rev 1.122   19 Jan 1998 16:51:18   CFORMUL
// Added Cryptor.2582
//
//    Rev 1.121   14 Jan 1998 18:18:50   CNACHEN
// Updated Trojan Scan to only be used for Picasso and NAV 4.0 products.
//
//    Rev 1.120   12 Jan 1998 13:32:44   CFORMUL
// Removed unreferenced local var from cryptor code
//
//    Rev 1.119   10 Jan 1998 03:06:52   CFORMUL
// Added Cryptor.2169 detection
//
//    Rev 1.118   09 Jan 1998 04:13:50   RELNITI
// SET Trojan Scanner
//
//    Rev 1.117   08 Jan 1998 17:06:14   CFORMUL
// Added Mad.5054 detection
//
//    Rev 1.116   22 Dec 1997 18:40:12   JWILBER
// Rolled back to rev 1.114 to disable trojan scanning.
//
//    Rev 1.114   20 Nov 1997 19:44:48   JWILBER
// Modified during Dec97 build.
//
//    Rev DEC97   17 Nov 1997 18:17:10   DCHI
// Added code_seg() pragma for SYM_WIN16.
//
//    Rev 1.113   04 Nov 1997 16:34:02   CNACHEN
// Commented out bloodhound for the time being...
//
//    Rev 1.112   04 Nov 1997 15:57:20   CNACHEN
// Changed nibble global variable name so we don't have a conflict with
// bloodhound global variable.
//
//    Rev 1.111   04 Nov 1997 15:44:18   CNACHEN
// Added bloodhound-file support to picasso.
//
//    Rev 1.110   14 Oct 1997 20:17:56   JWILBER
// Removed DWORD cast from lpbyInfectionBuffer in dwTemp assignment
// in EXTScanNightfall() to avoid compiler warning about "segment
// lost in conversion".  AVDEREF_DWORD figures the argument is
// a void pointer, anyway.
//
//    Rev 1.109   13 Oct 1997 14:02:02   CNACHEN
// Added trojan scanner support (ifdefed out).
//
//    Rev 1.108   08 Sep 1997 19:07:56   RELNITI
// RE-work Digi.3547 detection
//
//    Rev 1.107   06 Sep 1997 00:08:10   RELNITI
// ADD Digi.3547 detection, note that this is also detected by PAM 0x2fE4
//
//    Rev 1.106   29 Aug 1997 15:02:52   CFORMUL
// Fixed Neuroquila sig to not FP on a customer sample.
//
//    Rev 1.105   16 Jul 1997 17:31:14   DCHI
// Added check for version >= 3 for enabling heuristics on WIN and DX.
//
//    Rev 1.104   23 Jun 1997 15:04:16   AOONWAL
// Modified during JULY 97 build
//
//    Rev JULY97  17 Jun 1997 15:10:04   CFORMUL
// Modified Neurquila code to not false ID on a particular file.
//
//    Rev 1.103   04 Jun 1997 12:10:38   CNACHEN
// Added support for engine15 invocation
//
//    Rev 1.102   07 Apr 1997 18:46:12   DCHI
// Added code to speed up excel scanning by being more selective.
//
//    Rev 1.101   27 Mar 1997 16:38:00   JWILBER
// Added cheez due to FP w/ Nightfall/Neuroquila detection.
// Customer Issue 11319.
//
//    Rev 1.100   16 Jan 1997 19:06:54   JWILBER
// Added cast to an assignment in Tentatrickle repair to avoid a
// compiler warning.
//
//    Rev 1.99   08 Jan 1997 18:07:14   JWILBER
// Added detection for Tentatrickle.
//
//    Rev 1.98   26 Dec 1996 15:22:38   AOONWAL
// No change.
//
//    Rev 1.97   05 Dec 1996 14:59:08   CRENERT
// Removed Bosnia from NAVEX.
//
//    Rev 1.96   02 Dec 1996 14:00:42   AOONWAL
// No change.
//
//    Rev 1.95   29 Oct 1996 12:59:30   AOONWAL
// No change.
//
//    Rev 1.94   11 Oct 1996 18:20:10   CFORMUL
// Removed an int 3 from Freddy_Krueger code
//
//    Rev 1.93   10 Oct 1996 17:35:30   CFORMUL
// Added detection for Freddy_Krueger
//
//    Rev 1.92   03 Oct 1996 14:52:06   AOONWAL
// Removed comments from SMEG detection for QA testing
//
//    Rev 1.91   02 Oct 1996 12:00:06   AOONWAL
// Added Navex exclusion for a customer file to avoid False positive
// on "SMEG" detection
//
//    Rev 1.90   18 Sep 1996 12:53:16   RSTANEV
// Fixed what was supposed to be fixed in the previous rev.
//
//    Rev 1.89   16 Sep 1996 12:05:42   CFORMUL
// Fixed a bug in Smeg code that was causing a core dump.  Improper
// error checking was fixed.
//
//    Rev 1.88   13 Sep 1996 18:39:42   JSULTON
// Hare changes to detect variants uncommented.
//
//    Rev 1.87   06 Sep 1996 14:53:52   DCHI
// Added SYM_VXD to pack changes.
//
//    Rev 1.86   06 Sep 1996 14:21:14   DCHI
// pack changes
//
//    Rev 1.85   29 Aug 1996 12:14:28   DCHI
// Corrected incrementation order on index to external call array.
//
//    Rev 1.84   28 Aug 1996 16:37:44   DCHI
// Endianized everything.
//
//    Rev 1.83   21 Aug 1996 13:09:38   CFORMUL
// Fixed bug in detection of individual Hare infections. Still commented
//
//    Rev 1.82   12 Aug 1996 17:17:26   CFORMUL
// Fixed up w32 problems with hare.  I actully tested it under
// win95 and it didn't crash!
//
//    Rev 1.81   05 Aug 1996 16:28:06   CRENERT
// Regressed all of Formy's changes due to W32 build problems.
//
//    Rev 1.80   01 Aug 1996 17:06:44   CFORMUL
// Missed another declaration that was only used in commented code. oops
//
//    Rev 1.79   01 Aug 1996 15:51:32   CFORMUL
// Moved a declaration of a variable that used only in commented code
// so it was causing a warning when compilng navex32.
//
//    Rev 1.78   31 Jul 1996 18:31:50   CFORMUL
// Added VICE5 detection
//
//    Rev 1.77   30 Jul 1996 17:21:14   CFORMUL
// Added code to Hare detection to detect individual variants.
//
//    Rev 1.76   25 Jul 1996 18:11:48   DCHI
// Addition of Excel macro virus scanning.
//
//    Rev 1.75   15 Jul 1996 15:53:08   CNACHEN
// Corrected promotion problem in RDA detection.
//
//    Rev 1.74   11 Jul 1996 16:08:36   CFORMUL
// Removed an int 3 from the Hare code
//
//    Rev 1.73   11 Jul 1996 15:28:42   CFORMUL
// Made some changes to Hare code so it will detect some damaged samples
//
//    Rev 1.72   11 Jul 1996 14:25:22   CFORMUL
// Added detection for Hare.7610
//
//    Rev 1.71   08 Jul 1996 18:22:22   CNACHEN
// Fixed RDA scanner to use proper variable for bytes read (uMaxBytes).
//
//    Rev 1.70   28 Jun 1996 17:03:52   CNACHEN
// #ifdef'd out Cruncher debugging code.
//
//    Rev 1.69   28 Jun 1996 16:34:28   CNACHEN
// Weakened cruncher EXE sig to detect more variants.
//
//    Rev 1.68   28 Jun 1996 15:38:04   CNACHEN
// Added 3rd Cruncher variant support (COM only)
//
//    Rev 1.67   28 Jun 1996 15:17:16   CNACHEN
// Added Cruncher COM and EXE detection (for the two variants that we have).
//
//    Rev 1.66   26 Jun 1996 14:46:10   CNACHEN
// Added RDA detection.
//
//    Rev 1.65   14 Jun 1996 15:39:32   CBROWN
// Added opcode 01 for one half detection...
//
//    Rev 1.64   14 Jun 1996 15:23:00   CBROWN
// Added 0x29 as valid opcode for One Half decryption...
//
//    Rev 1.63   31 May 1996 12:53:46   CRENERT
// Fixed false positive for Track #2991.
//
//    Rev 1.62   16 Apr 1996 09:12:10   RSTANEV
// TCHAR support.
//
//    Rev 1.61   15 Apr 1996 23:11:50   JWILBER
// Made mongo changes to Cordobes detection.
//
//    Rev 1.60   12 Apr 1996 20:14:32   JWILBER
// Added detection for 1f7a, Cordobes.
//
//    Rev 1.59   04 Apr 1996 14:55:22   DCHI
// Added #ifdef'd out call to EXTScanFileJava() for Java scan requests.
//
//    Rev 1.58   01 Apr 1996 21:04:18   JWILBER
// Whoops!  Commented out int 3 in SMEGma detection.
//
//    Rev 1.57   01 Apr 1996 21:00:24   JWILBER
// Added more cheez to SMEG detection.  Name should be changed to SMEGma,
// as in "head cheese".
//
//    Rev 1.56   27 Mar 1996 14:12:46   JWILBER
// Added forgotten #define for CLVB_LEN to SMEG detection.
//
//    Rev 1.55   26 Mar 1996 17:40:30   JWILBER
// Fixed SMEG detection to stop a few more FP's.
//
//    Rev 1.54   19 Mar 1996 21:04:32   JSULTON
// Uncommented Gripe.  It's ready to go.
//
//    Rev 1.53   19 Mar 1996 14:41:14   JALLEE
// Added gripe.2040
// Commented out pending QA.
//
//    Rev 1.52   11 Mar 1996 17:38:30   JWILBER
// Made all pointer parameters to ReloadBuffer() into far pointers, to
// avoid far/near casting problems w/ Windows versions of NAVEX.
//
//    Rev 1.51   08 Mar 1996 20:48:34   JWILBER
// Added detection for Vagabond virus.
//
//    Rev 1.50   21 Feb 1996 15:11:10   JALLEE
// Added entry point vs EOF checking to Urug 4 detection.
//
//    Rev 1.49   16 Feb 1996 10:43:00   DCHI
// One Half fix - lpbyInfectionBuffer+256 is first 64 bytes of file.
//
//    Rev 1.48   15 Feb 1996 19:06:52   MKEATIN
// Loosened up Nightfall.5815 detection.
//
//    Rev 1.47   14 Feb 1996 13:43:58   JALLEE
// Added Nightfall.5815 detection and reworked old Nightfall/Neuroquila detect
//
//    Rev 1.46   13 Feb 1996 18:23:12   DCHI
// Fixed lpbyWorkBuffer to lpbyInfectionBuffer
//
//    Rev 1.45   13 Feb 1996 18:01:30   MKEATIN
// Added DX support
//
//    Rev 1.44   13 Feb 1996 17:57:26   DCHI
// Added One Half scan.
//
//    Rev 1.43   13 Feb 1996 16:18:50   JALLEE
// Changed allowable size of encrypted body for Uruguay 4.
//
//    Rev 1.42   08 Feb 1996 10:37:58   DCHI
// (void)lpCallBack and (void)hFile in EXTScanFileUrug4 for NLM compilation.
//
//    Rev 1.41   07 Feb 1996 18:11:12   CRENERT
// Removed "_asm INT 3" reference.
//
//    Rev 1.40   07 Feb 1996 18:10:12   CRENERT
// Changed return value of Uruguay 4 detection to VID_URUG4
//
//    Rev 1.39   06 Feb 1996 10:52:30   JALLEE
// Added Uruguay 4 detection
//
//    Rev 1.38   05 Feb 1996 17:22:18   DCHI
// Added case to switch in EXTScanFile for Windows executable scanning.
//
//    Rev 1.37   23 Jan 1996 17:32:24   JSULTON
// Replaced hard-coded Natas VID with global constant.
//
//    Rev 1.36   10 Jan 1996 14:58:26   CRENERT
// Regression to accomodate mid-month release.
//
//    Rev 1.34   03 Jan 1996 17:14:00   DCHI
// Added fast Word Macro virus scan.
//
//    Rev 1.33   12 Dec 1995 16:41:48   JALLEE
// Added detection for FormatC macro virus.
//
//    Rev 1.32   17 Nov 1995 17:51:24   DDUPERAU
// Added more detection abilities to Natas.
//
//    Rev 1.31   17 Nov 1995 17:50:28   DDUPERAU
//
//    Rev 1.30   17 Nov 1995 17:18:42   JALLEE
// Changed test in Nightfall enhanced detection to search for inc di not
// inc dx.  This was causing us to miss samples.
//
//    Rev 1.29   16 Nov 1995 20:46:20   JALLEE
// Smeg def reworked to eliminate false positive.
//
//    Rev 1.28   16 Nov 1995 10:56:34   JALLEE
// Fixed possibility of read out of buffer in Smeg detection.
//
//    Rev 1.27   15 Nov 1995 13:52:38   JALLEE
// Kludge for enhanced checking neuroquila/nightfall.
//
//    Rev 1.26   15 Nov 1995 10:33:28   JALLEE
//
//    Rev 1.24   10 Nov 1995 11:21:02   JALLEE
// Added detection for DMV and Colors macro viruses.
//
//    Rev 1.23   09 Nov 1995 14:23:26   JALLEE
// Moved #defines for function ID's to navexshr.h
//
//    Rev 1.22   08 Nov 1995 16:22:22   JALLEE
// Changed VID_SMEG to 23fb
// Changed VID_NIGHTFALL to 23da
//
//    Rev 1.21   06 Nov 1995 17:08:56   RAY
// Added lpszFileName and wVersionNumber params to EXTQAScanFileTest()
//
//    Rev 1.20   01 Nov 1995 16:13:24   RWALDIN
// Added ifdef'd calls to VIRLIB\NAVEX.QA\NAVEXQSF.CPP functions.
//
//    Rev 1.19   01 Nov 1995 10:49:02   DCHI
// Removed include of navexhdr.h due to change in format of navexshr.h.
//
//    Rev 1.18   26 Oct 1995 16:28:46   JALLEE
// CallBack->Progress added under NLM to relinquish control during long scans
// for macro viruses.
//
//    Rev 1.17   20 Oct 1995 15:22:36   DDUPERAU
// Adjusted returned VID for Natas.
//
//    Rev 1.16   20 Oct 1995 15:13:54   DDUPERAU
// Added Natas External.
//
//    Rev 1.15   20 Oct 1995 14:25:18   DDUPERAU
// No change.
//
//    Rev 1.14   20 Oct 1995 14:24:44   DDUPERAU
// No change.
//
//    Rev 1.13   20 Oct 1995 14:24:08   DDUPERAU
//
//    Rev 1.12   19 Oct 1995 17:17:36   CNACHEN
// LONG -> long
//
//    Rev 1.11   19 Oct 1995 15:41:06   SCOURSE
// Minor bug.  Only one that would cause a page fault.  No biggy...NOT! :(
//
//    Rev 1.10   19 Oct 1995 14:20:56   DCHI
// Added LOADDS to external functions for WIN16.  Modified DOS export
// table structure to support tiny model modules.
//
//    Rev 1.9   18 Oct 1995 14:26:16   cnachen
// Voided unused parameters to compile without errors on NLM.
// Commented out EXTExcludeFile function.
//
//    Rev 1.8   18 Oct 1995 11:51:36   SCOURSE
// Modifications to TPE.Bosnia detection
//
//    Rev 1.7   16 Oct 1995 16:05:12   CNACHEN
// fixed bug in W32 where WORD return of -1 was compared with DWORD -1...
//
//    Rev 1.6   16 Oct 1995 13:01:28   DCHI
// Added include of navexhdr.h.
//
//    Rev 1.5   16 Oct 1995 12:38:08   JALLEE
// Fixed bug in FileSeek error checking, cast return value to LONG.
//
//    Rev 1.4   16 Oct 1995 12:37:08   SCOURSE
// Added comments for TPE.Bosnia detection
//
//    Rev 1.3   16 Oct 1995 12:15:14   JALLEE
// Per instruction from Carey, have removed all unreferenced function
// parameters.
//
//    Rev 1.2   16 Oct 1995 11:50:26   SCOURSE
// Added code for TPE.Bosnia detection
//
//    Rev 1.1   16 Oct 1995 10:08:32   JALLEE
// Added detection for Smeg, Neuroquila, Nightfall, and Word Macro viruses.
//
//    Rev 1.0   13 Oct 1995 13:05:52   DCHI
// Initial revision.
//
//************************************************************************

#include "gdefines.h"

#ifdef SARCBOT
#include "config.h"
#endif

#ifdef SYM_WIN16
#pragma code_seg("NAVEX_NAVEXSF","NAVEX_FILE_CODE")
#endif

#include "platform.h"

#include "endutils.h"

#ifdef WIN16        // VIRSCAN QUAKE 2
#include "cts4.h"
#else
#include "ctsn.h"
#include "callback.h"
#endif

#include "navex.h"

// Declare shared routines

#include "navexshr.h"

#include "winconst.h"

#include "trojscan.h"

#ifdef SYM_DOSX
#undef SYM_DOS
#endif

#if defined(SYM_DOS)

WORD wDS, wES;                      // save loader's DS,ES

#endif

#include "macrscan.h"

#include "nepescan.h"
#include "pespscan.h"
#include "javascan.h"

#include "exclscan.h"

#include "a2scn.h"
#include "a97scn.h"

#ifdef NAVEX15
  #ifdef __WATCOMC__
    extern PEXPORT15_TABLE_TYPE     glpstEngineExportTable;
  #endif
#endif

#include "aolpw.h"                  // AOL Pw stealer

#ifdef MSX
#include "msx.h"
#endif // #ifdef MSX

// java scanning code below

#include "javashr.h"

// java scanning code above



// Prototypes for local functions

EXTSTATUS EXTScanFileNightfall(LPCALLBACKREV1 lpCallBack,
                        HFILE  hFile,
                        LPBYTE lpbyInfectionBuffer,
                        LPWORD lpwVID);

EXTSTATUS EXTScanFileSmeg(LPCALLBACKREV1 lpCallBack,
                        HFILE  hFile,
                        LPBYTE lpbyInfectionBuffer,
                        LPBYTE lpbyWorkBuffer,
                        LPWORD lpwVID);

BOOL SmegHelp (LPBYTE lpbySearchBuffer);


//EXTSTATUS EXTScanFileTPEBOSNIA(LPCALLBACKREV1 lpCallBack,
//                       LPBYTE lpbyInfectionBuffer,
//                        LPWORD lpwVID);
// Commented out -- 12/5/96

EXTSTATUS EXTScanFileNatas(LPCALLBACKREV1 lpCallBack,
                        HFILE  hFile,
                        LPBYTE lpbyInfectionBuffer,
                        LPBYTE lpbyWorkBuffer,
                        LPWORD lpwVID);


EXTSTATUS EXTScanFileUrug4(LPCALLBACKREV1 lpCallBack,
                        HFILE  hFile,
                        LPBYTE lpbyInfectionBuffer,
                        LPWORD lpwVID);

EXTSTATUS EXTScanForOneHalf(LPCALLBACKREV1 lpCallBack,
                        HFILE  hFile,
                        LPBYTE lpbyInfectionBuffer,
                        LPWORD lpwVID);

EXTSTATUS EXTScanFileVagabond(LPCALLBACKREV1 lpCallBack,
                        HFILE  hFile,
                        LPBYTE lpbyInfectionBuffer,
                        LPWORD lpwVID);

EXTSTATUS ReloadBuffer(LPCALLBACKREV1 lpCB, HFILE hF, LPDWORD pdwFP, LPWORD i,
                        LPBYTE lpbyIB);


EXTSTATUS EXTScanFileGripe(LPCALLBACKREV1 lpCallBack,
                        HFILE  hFile,
                        LPBYTE lpbyInfectionBuffer,
                        LPWORD lpwVID);

EXTSTATUS EXTScanFileCordobes(LPCALLBACKREV1 lpCallBack,
                        HFILE  hFile,
                        LPBYTE lpbyInfectionBuffer,
                        LPWORD lpwVID);


EXTSTATUS EXTScanFileRDA(LPCALLBACKREV1 lpCallBack,
                         HFILE  hFile,
                         LPBYTE lpbyInfectionBuffer,
                         LPWORD lpwVID);


EXTSTATUS EXTScanFileCruncher(LPCALLBACKREV1 lpCallBack,
                              HFILE  hFile,
                              LPBYTE lpbyInfectionBuffer,
                              LPWORD lpwVID);

EXTSTATUS EXTScanFileHare(LPCALLBACKREV1 lpCallBack,
                          HFILE  hFile,
                          LPBYTE lpbyInfectionBuffer,
						  LPBYTE lpbyWorkBuffer,
                          LPWORD lpwVID);

EXTSTATUS EXTScanFileWidow(LPCALLBACKREV1 lpCallBack,
                           HFILE  hFile,
                           LPBYTE lpbyInfectionBuffer,
						   LPBYTE lpbyWorkBuffer,
                           LPWORD lpwVID);

EXTSTATUS EXTScanFileVICE(LPCALLBACKREV1 lpCallBack,
                          HFILE  hFile,
                          LPBYTE lpbyInfectionBuffer,
                          LPWORD lpwVID);

EXTSTATUS EXTScanFileFreddy(LPCALLBACKREV1 lpCallBack,
                            HFILE  hFile,
                            LPBYTE lpbyInfectionBuffer,
                            LPWORD lpwVID);

EXTSTATUS EXTScanFileMad(LPCALLBACKREV1 lpCallBack,
                         HFILE  hFile,
                         LPBYTE lpbyInfectionBuffer,
                         LPWORD lpwVID);

EXTSTATUS EXTScanFileCryptor(LPCALLBACKREV1 lpCallBack,
                             HFILE  hFile,
                             LPBYTE lpbyInfectionBuffer,
                             LPWORD lpwVID);

EXTSTATUS EXTScanFileCryptor2(LPCALLBACKREV1 lpCallBack,
                              HFILE  hFile,
                              LPBYTE lpbyInfectionBuffer,
                              LPWORD lpwVID);

EXTSTATUS EXTScanFileCryptor4(LPCALLBACKREV1 lpCallBack,
                              HFILE  hFile,
                              LPBYTE lpbyInfectionBuffer,
                              LPWORD lpwVID);

EXTSTATUS EXTScanFileDigi3547(LPCALLBACKREV1 lpCallBack,
                             HFILE  hFile,
                             LPBYTE lpbyInfectionBuffer,
                             LPWORD lpwVID);
EXTSTATUS EXTScanFileTentatrick(LPCALLBACKREV1 lpCallBack,
                                HFILE  hFile,
                                LPBYTE lpbyInfectionBuffer,
                                LPWORD lpwVID);

EXTSTATUS EXTScanFileSSR19834(LPCALLBACKREV1 lpCallBack,
                              HFILE  hFile,
                              LPBYTE lpbyWorkBuffer,
                              LPBYTE lpbyInfectionBuffer,
                              LPWORD lpwVID);

EXTSTATUS EXTScanFileVanitas3712(LPCALLBACKREV1 lpCallBack,
                                 HFILE  hFile,
                                 LPBYTE lpbyWorkBuffer,
                                 LPBYTE lpbyInfectionBuffer,
                                 LPWORD lpwVID);

EXTSTATUS EXTScanFileLightning(LPCALLBACKREV1 lpCallBack,
                                 HFILE  hFile,
                                 LPBYTE lpbyWorkBuffer,
                                 LPBYTE lpbyInfectionBuffer,
                                 LPWORD lpwVID);

EXTSTATUS EXTScanFileCezar(LPCALLBACKREV1 lpCallBack,
                                 HFILE  hFile,
                                 LPBYTE lpbyWorkBuffer,
                                 LPBYTE lpbyInfectionBuffer,
                                 LPWORD lpwVID);

EXTSTATUS EXTScanFileSailor(LPCALLBACKREV1 lpCallBack,
                             HFILE  hFile,
                             LPBYTE lpbyInfectionBuffer,
                             LPWORD lpwVID);

EXTSTATUS EXTScanFileZombieZCME(LPCALLBACKREV1 lpCallBack,
                                 HFILE  hFile,
                                 LPBYTE lpbyWorkBuffer,
                                 LPBYTE lpbyInfectionBuffer,
                                 LPWORD lpwVID);

EXTSTATUS EXTScanFileLexotran(LPCALLBACKREV1 lpCallBack,
                                 HFILE  hFile,
                                 LPBYTE lpbyInfectionBuffer,
                                 LPWORD lpwVID);

EXTSTATUS EXTScanFileTMCB(LPCALLBACKREV1 lpCallBack,
                                 HFILE  hFile,
                                 LPBYTE lpbyInfectionBuffer,
                                 LPBYTE lpbyWorkBuffer,
                                 LPWORD lpwVID);



// java virus scanner below

EXTSTATUS EXTScanFileStrangeBrew
(
    LPCALLBACKREV1 lpCallBack,
    HFILE          hFile,
    LPWORD         lpwVID
);

// java virus scanner above

int OpcodeLength(LPBYTE lpbyInstructionStream);

#if defined(NAVEX_QA)                  // QA ScanFile function Prototypes

EXTSTATUS EXTQAScanFilePre (
                            LPCALLBACKREV1   lpCallBack,
                            LPTSTR           lpszFileName,
                            HFILE            hFile,
                            LPBYTE           lpbyInfectionBuffer,
                            LPBYTE           lpbyWorkBuffer,
                            WORD             wVersionNumber,
                            LPWORD           lpwVID
                           );


EXTSTATUS EXTQAScanFileTest (
                             LPCALLBACKREV1 lpCallBack,
                             LPTSTR         lpszFileName,
                             HFILE          hFile,
                             LPBYTE         lpbyInfectionBuffer,
                             LPBYTE         lpbyWorkBuffer,
                             WORD           wVersionNumber,
                             LPWORD         lpwVID
                            );

EXTSTATUS EXTQAScanFilePost (
                             LPCALLBACKREV1   lpCallBack,
                             LPTSTR           lpszFileName,
                             HFILE            hFile,
                             LPBYTE           lpbyInfectionBuffer,
                             LPBYTE           lpbyWorkBuffer,
                             WORD             wVersionNumber,
                             LPWORD           lpwVID,
                             WORD             wResult
                            );

#endif                                  // NAVEX_QA

// EXTExcludeFile arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// lpszFileName         : file name of infected host.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 4K fstart buffers containing TOF, ENTRY, etc.
// lpwExclude			: TRUE to exclude, FALSE otherwise
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if OK
//                        EXTSTATUS_DISK_READ_ERROR     if disk read error
//                        EXTSTATUS_MEM_ERROR           if memory error
//
//
//
//EXTSTATUS EXTExcludeFile(LPCALLBACKREV1 lpCallBack,
//                         LPTSTR         lpszFileName,
//                         HFILE          hFile,
//                         LPBYTE         lpbyInfectionBuffer,
//                         LPWORD         lpwExclude)
//{
//
//    // no exclusions
//
//
//    return(EXTSTATUS_OK);
//}



// CheckForPEHeader arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 4K fstart buffers containing TOF, ENTRY, etc.
//                         +0   256 fstart bytes of target program.
//                         +256 64 bytes from TOF of target program.
//                         +512 256 unused
//                         +768 2 Number of external defs called.
//                         +770 2 ID of first external called.
//                         +772 ? ID of additional externals called.
//
// Returns:  void
//
// This function checks the file for PE header.  If it has one, it looks
// for ID_WINDOWS in the NAVEX_CALL_T list, and if it's not there, adds it,
// so that the file will be scanned using the windows signatures.
//
// NE files should be scanned automatically due to the 0x40 in the
// Relocation Table Offset field in the MZ header.
//

typedef struct tagNAVEX_CALL
{
    WORD    wCount;
    WORD    wID[256];
} NAVEX_CALL_T, FAR *LPNAVEX_CALL;


void CheckForPEHeader(LPCALLBACKREV1    lpCallBack,
                      HFILE             hFile,
                      LPBYTE            lpbyInfectionBuffer)
{

    LPNAVEX_CALL    lpNAVEXCall = (LPNAVEX_CALL)(lpbyInfectionBuffer + 768);

    DWORD           dwOffsetOfWindowsHeader;
    WORD            wSignature, i;


    dwOffsetOfWindowsHeader = AVDEREF_DWORD(lpbyInfectionBuffer + 256 + 0x3c);

    //check for MZ header

    if ( 0 != lpCallBack->FileSeek(hFile,0,SEEK_SET) )
        return;

    if ( lpCallBack->FileRead(hFile,&wSignature,2) != 2)
        return;

    if ( wSignature != 0x4d5a && wSignature != 0x5a4d )
        return;


    //check for PE header

    if ( dwOffsetOfWindowsHeader !=
         lpCallBack->FileSeek(hFile,dwOffsetOfWindowsHeader,SEEK_SET) )
        return;

    if ( lpCallBack->FileRead(hFile,&wSignature,2) != 2)
        return;

    wSignature = WENDIAN(wSignature);

    if (wSignature == 0x4550)  //PE
    {
        for (i=0;i<lpNAVEXCall->wCount;i++)
        {
            if ( lpNAVEXCall->wID[i] == ID_WINDOWS ) break;
        }

        if (i == lpNAVEXCall->wCount && lpNAVEXCall->wCount < 256)
        {
            lpNAVEXCall->wCount++;
            lpNAVEXCall->wID[i] = ID_WINDOWS;
        }
    }

    return;

}//CheckForPEHeader



// EXTScanFile arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// lpszFileName         : pointer to the name of the file
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 4K fstart buffers containing TOF, ENTRY, etc.
//                         +0   256 fstart bytes of target program.
//                         +256 64 bytes from TOF of target program.
//                         +512 256 unused
//                         +768 2 Number of external defs called.
//                         +770 2 ID of first external called.
//                         +772 ? ID of additional externals called.
// lpbyWorkBuffer       : 2-4K buffer for temporary operations (STACK OK also)
// wVersionNumber       : Engine version number so detections are not performed
//                        by an external DLL if the engine has been updated
//                        to provide the detection itself.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                        EXTSTATUS_FILE_ERROR          if file error occured
//                        EXTSTATUS_VIRUS_FOUND         if virus was found
//                        EXTSTATUS_MEM_ERROR           if memory alloc. error

#if defined(SYM_WIN32) || defined(SYM_NTK) || defined(SYM_VXD)
#include "pshpack1.h"
#else
#pragma PACK1
#endif


#if defined(SYM_WIN32) || defined(SYM_NTK) || defined(SYM_VXD)
#include "poppack.h"
#else
#pragma PACK
#endif

EXTSTATUS FAR WINAPI NLOADDS EXTScanFile(LPCALLBACKREV1 lpCallBack,
                                         LPTSTR          lpszFileName,
                                         HFILE          hFile,
                                         LPBYTE         lpbyInfectionBuffer,
                                         LPBYTE         lpbyWorkBuffer,
                                         WORD           wVersionNumber,
                                         LPWORD         lpwVID)
{

#if defined(SYM_DOS)

    _asm
        {
        mov cs:[wDS], ds
        mov cs:[wES], es
        mov ax, cs
        mov ds, ax
        mov es, ax
        }

#endif

    WORD            wResult = EXTSTATUS_OK;
    LPNAVEX_CALL    lpNAVEXCall = (LPNAVEX_CALL)(lpbyInfectionBuffer + 768);
    WININFO         stNEHeader;
    DWORD           dwNEOffset = 0;

#if defined(NAVEX_QA)                  // QA ScanFile Entry Point function

    EXTQAScanFilePre (lpCallBack,
                      lpszFileName,
                      hFile,
                      lpbyInfectionBuffer,
                      lpbyWorkBuffer,
                      wVersionNumber,
                      lpwVID);

#endif                                  // NAVEX_QA

    (void)lpszFileName;
    (void)wVersionNumber;



    CheckForPEHeader(lpCallBack,
                     hFile,
                     lpbyInfectionBuffer);


                                        // Do not scan files unless
                                        // specifically called from a def
                                        // in virscan.dat.  *lpwIDCalled
                                        // is the number of externls called.
    if (0 == lpNAVEXCall->wCount)
    {
        //wResult = EXTSTATUS_OK;         // No virus found.
    }
    else                                // External is called on this file
    {                                   // by at least one def in virscan.dat
        int i = 0;

                                        // Cycle through externls called from
                                        // virscan.dat definitions.
        while( i < lpNAVEXCall->wCount &&
                  wResult != EXTSTATUS_VIRUS_FOUND)
        {
            switch (lpNAVEXCall->wID[i++])
            {
                case ID_NIGHTFALL : wResult=EXTScanFileNightfall(lpCallBack,
                                                            hFile,
                                                            lpbyInfectionBuffer,
                                                            lpwVID);
                                    break;

                case ID_SMEG      : wResult=EXTScanFileSmeg(lpCallBack,
                                                            hFile,
                                                            lpbyInfectionBuffer,
                                                            lpbyWorkBuffer,
                                                            lpwVID);
                                    break;

#ifndef NOMACRO

                case ID_MACRO     : lpbyWorkBuffer[0] = (BYTE)wVersionNumber;
#ifdef MSX
                                    if (MSXFileIsExcluded(lpCallBack,
                                                          hFile) != FALSE)
                                        wResult = EXTSTATUS_OK;
                                    else
#endif // #ifdef MSX
                                        wResult=EXTScanFileMacro(lpCallBack,
                                                                 hFile,
                                                                 lpbyWorkBuffer,
                                                                 lpwVID);

                                    break;
#if 0
                case ID_ACCESS2   : lpbyWorkBuffer[0] = (BYTE)wVersionNumber;
                                    wResult=EXTScanFileAccess2(lpCallBack,
                                                               hFile,
                                                               lpbyWorkBuffer,
                                                               lpwVID);

                                    break;
#endif
                case ID_ACCESS97  : lpbyWorkBuffer[0] = (BYTE)wVersionNumber;
                                    wResult=EXTScanFileAccess97(lpCallBack,
                                                                hFile,
                                                                lpbyWorkBuffer,
                                                                lpwVID);

                                    break;

#endif // #ifndef NOMACRO

//                case ID_TPEBOSNIA : wResult=EXTScanFileTPEBOSNIA(lpCallBack,
//                                                            lpbyInfectionBuffer,
//                                                            lpwVID);
//                                    break;
//  Commented out, 12/5/96

                case ID_NATAS     : wResult=EXTScanFileNatas(lpCallBack,
                                                            hFile,
                                                            lpbyInfectionBuffer,
                                                            lpbyWorkBuffer,
                                                            lpwVID);
                                    break;


                case ID_URUG4     : wResult=EXTScanFileUrug4(lpCallBack,
                                                            hFile,
                                                            lpbyInfectionBuffer,
                                                            lpwVID);
                                    break;

                case ID_WINDOWS:    wResult = EXTScanFileWindows(lpCallBack,
                                                            hFile,
                                                            lpbyWorkBuffer,
                                                            lpwVID,
                                                            &stNEHeader,
                                                            &dwNEOffset);
                                    break;

                case ID_ONEHALF:    wResult = EXTScanForOneHalf(lpCallBack,
                                                            hFile,
                                                            lpbyInfectionBuffer,
                                                            lpwVID);
                                    break;

                case ID_VAGABOND:   wResult = EXTScanFileVagabond(lpCallBack,
                                                            hFile,
                                                            lpbyInfectionBuffer,
                                                            lpwVID);
                                    break;


                case ID_GRIPE :     wResult=EXTScanFileGripe(lpCallBack,
                                                            hFile,
                                                            lpbyInfectionBuffer,
                                                            lpwVID);
                                    break;

                case ID_CORDOBES:   wResult=EXTScanFileCordobes(lpCallBack,
                                                            hFile,
                                                            lpbyInfectionBuffer,
                                                            lpwVID);
                                    break;

                case ID_RDA:        wResult=EXTScanFileRDA(lpCallBack,
                                                           hFile,
                                                           lpbyInfectionBuffer,
                                                           lpwVID);
                                    break;

                case ID_CRUNCHER:   wResult=EXTScanFileCruncher(lpCallBack,
                                                                hFile,
                                                                lpbyInfectionBuffer,
                                                                lpwVID);
                                    break;

                case ID_HARE:       wResult=EXTScanFileHare(lpCallBack,
                                                            hFile,
                                                            lpbyInfectionBuffer,
															lpbyWorkBuffer,
                                                            lpwVID);
                                    break;


                case ID_WIDOW:      wResult=EXTScanFileWidow(lpCallBack,
                                                             hFile,
                                                             lpbyInfectionBuffer,
                                                             lpbyWorkBuffer,
                                                             lpwVID);
                                    break;

                case ID_VICE:       wResult=EXTScanFileVICE(lpCallBack,
                                                            hFile,
                                                            lpbyInfectionBuffer,
                                                            lpwVID);
                                    break;

                case ID_FREDDY:     wResult=EXTScanFileFreddy(lpCallBack,
                                                              hFile,
                                                              lpbyInfectionBuffer,
                                                              lpwVID);
                                    break;

                case ID_MAD5054:    wResult=EXTScanFileMad(lpCallBack,
                                                           hFile,
                                                           lpbyInfectionBuffer,
                                                           lpwVID);
                                    break;

                case ID_CRYPTOR:    wResult=EXTScanFileCryptor(lpCallBack,
                                                               hFile,
                                                               lpbyInfectionBuffer,
                                                               lpwVID);
                                    break;

                case ID_CRYPTOR2582: wResult=EXTScanFileCryptor2(lpCallBack,
                                                                 hFile,
                                                                 lpbyInfectionBuffer,
                                                                 lpwVID);
                                     break;

                case ID_CRYPTOR4161: wResult=EXTScanFileCryptor4(lpCallBack,
                                                                 hFile,
                                                                 lpbyInfectionBuffer,
                                                                 lpwVID);
                                     break;



                case ID_DIGI3547:  wResult=EXTScanFileDigi3547(lpCallBack,
                                                               hFile,
                                                               lpbyInfectionBuffer,
                                                               lpwVID);
                                   break;
                case ID_TENTRK:     wResult=EXTScanFileTentatrick(lpCallBack,
                                                        hFile,
                                                        lpbyInfectionBuffer,
                                                        lpwVID);
                                    break;

                case ID_SAILOR:    wResult=EXTScanFileSailor(lpCallBack,
                                                               hFile,
                                                               lpbyInfectionBuffer,
                                                               lpwVID);
                                    break;

                case ID_JAVA:

                                    wResult = EXTScanFileStrangeBrew(lpCallBack,
                                                                     hFile,
                                                                     lpwVID);
                                    break;

#if 0
                case ID_JAVA:       wResult = EXTScanFileJava(lpCallBack,
                                                            hFile,
                                                            lpbyWorkBuffer,
                                                            lpwVID);
                                    break;
#endif // #if 0

                case ID_SSR19834:   wResult=EXTScanFileSSR19834(lpCallBack,
                                                        hFile,
                                                        lpbyWorkBuffer,
                                                        lpbyInfectionBuffer,
                                                        lpwVID);
                                    break;

                case ID_VANITAS3712: wResult = EXTScanFileVanitas3712(lpCallBack,
                                                        hFile,
                                                        lpbyWorkBuffer,
                                                        lpbyInfectionBuffer,
                                                        lpwVID);
                                    break;

                case ID_LIGHTNING: wResult = EXTScanFileLightning(lpCallBack,
                                                        hFile,
                                                        lpbyWorkBuffer,
                                                        lpbyInfectionBuffer,
                                                        lpwVID);
                                    break;

                case ID_CEZAR: wResult = EXTScanFileCezar(lpCallBack,
                                                        hFile,
                                                        lpbyWorkBuffer,
                                                        lpbyInfectionBuffer,
                                                        lpwVID);
                                    break;

                case ID_ZOMBIEZCME: wResult = EXTScanFileZombieZCME(lpCallBack,
                                                        hFile,
                                                        lpbyWorkBuffer,
                                                        lpbyInfectionBuffer,
                                                        lpwVID);
                                    break;

                case ID_LEXOTRAN: wResult = EXTScanFileLexotran(lpCallBack,
                                                        hFile,
                                                        lpbyInfectionBuffer,
                                                        lpwVID);
                                    break;


                case ID_TMCB: wResult = EXTScanFileTMCB(lpCallBack,
                                                        hFile,
                                                        lpbyInfectionBuffer,
                                                        lpbyWorkBuffer,
                                                        lpwVID);
                                    break;


#if defined(NAVEX_QA)                  // QA ScanFile Test External Def

                case ID_QATESTDEF : wResult=EXTQAScanFileTest(lpCallBack,
                                                              lpszFileName,
                                                              hFile,
                                                              lpbyInfectionBuffer,
                                                              lpbyWorkBuffer,
                                                              wVersionNumber,
                                                              lpwVID);
                                    break;

#endif                                  // NAVEX_QA

                default           : break;
            }
        } // end of while
    } // end else

    //////////////////////////////////////////////////////////////////////////
    // Now check for trojans; always do this even if there's no request to do
    // so...
    //////////////////////////////////////////////////////////////////////////

//#ifdef USE_TROJAN_SCAN

    if (wResult == EXTSTATUS_OK)
    {
        // nothing found yet; check for trojans

        // supported for NAVEX15 products

        wResult = ScanForTrojans(lpCallBack,
                                 hFile,
                                 lpbyInfectionBuffer,
                                 lpbyWorkBuffer,
                                 lpwVID);
    }

//#endif // #ifdef USE_TROJAN_SCAN

#if defined(SYM_WIN16) || defined(SYM_DOSX)
#if !defined(NAVEX15) && defined(USE_BLOODHOUND_PICASSO)

    //////////////////////////////////////////////////////////////////////////
    // Now do Bloodhound for picasso (DOS/WIN16)
    // so...
    //////////////////////////////////////////////////////////////////////////

    if (wResult == EXTSTATUS_OK)
    {
        // nothing found so far, try for BH

        EXTSTATUS FAR WINAPI NLOADDS ScanBloodFile
        (
            LPCALLBACKREV1  lpCallBack,
            LPTSTR          lpszFileName,
            HFILE           hFile,
            LPBYTE          lpbyInfectionBuffer,
            LPBYTE          lpbyWorkBuffer,
            WORD            wVersionNumber,
            LPWORD          lpwVID
        );

        wResult = ScanBloodFile(lpCallBack,
                                lpszFileName,
                                hFile,
                                lpbyInfectionBuffer,
                                lpbyWorkBuffer,
                                wVersionNumber,
                                lpwVID);

    }

#endif      // #if !defined(NAVEX15) && defined(USE_BLOODHOUND_PICASSO)
#endif      // #if defined(SYM_WIN16) || defined(SYM_DOSX)

    //////////////////////////////////////////////////////////////////////////
    // Now check for AOL Password Stealers
    //////////////////////////////////////////////////////////////////////////

    if (wResult == EXTSTATUS_OK)
    {
        wResult = AOLPWBloodhound(lpCallBack,
                                  hFile,
                                  &stNEHeader,
                                  dwNEOffset,
                                  lpbyWorkBuffer,
                                  lpwVID);
    }

    //////////////////////////////////////////////////////////////////////////
    // Done checking for AOL Password Stealers
    //////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////////////////////////////////////////
    // Now see if we have an engine virus if we havent' found one so far
    //////////////////////////////////////////////////////////////////////////

#ifdef NAVEX15
    if (wResult == EXTSTATUS_OK)
    {
#ifndef __WATCOMC__
        extern PEXPORT15_TABLE_TYPE     glpstEngineExportTable;
#endif

        if (glpstEngineExportTable != NULL)
        {
            wResult = glpstEngineExportTable->
                        EXTScanFile(lpCallBack,
                                    lpszFileName,
                                    hFile,
                                    lpbyInfectionBuffer,
                                    lpbyWorkBuffer,
                                    wVersionNumber,
                                    lpwVID);
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    // Done with engine work
    //////////////////////////////////////////////////////////////////////////////
#endif // #ifdef NAVEX15

#if defined(NAVEX_QA)                  // QA ScanFile Exit Point function

    EXTQAScanFilePost (lpCallBack,
                       lpszFileName,
                       hFile,
                       lpbyInfectionBuffer,
                       lpbyWorkBuffer,
                       wVersionNumber,
                       lpwVID,
                       wResult);

#endif                                  // NAVEX_QA

#if defined(SYM_DOS)

    _asm
        {
        mov ds, cs:[wDS]
        mov es, cs:[wES]
        }

#endif
    return ( wResult );
}


// Custom Navex Functions

// EXTScanFileNightfall arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 4K fstart buffers containing TOF, ENTRY, etc.
//                         +0   256 fstart bytes of target program.
//                         +256 64 bytes from TOF of target program.
//                         +512 256 unused
//                         +768 2 Number of external defs called.
//                         +770 2 ID of first external called.
//                         +772 ? ID of additional externals called.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                        EXTSTATUS_VIRUS_FOUND         if virus was found

EXTSTATUS EXTScanFileNightfall(LPCALLBACKREV1 lpCallBack,
                      HFILE          hFile,
                      LPBYTE         lpbyInfectionBuffer,
                      LPWORD         lpwVID)
{
    WORD    wReturn = EXTSTATUS_OK;
    WORD    i, k, wTemp, wContinue = FALSE, wNight5815 = TRUE;
    BYTE    bInc_rX;
    DWORD   dwFileSize, dwEntryPt, dwTemp;

    dwTemp = AVDEREF_DWORD(lpbyInfectionBuffer);

    // This is major cheez to eliminate an FP with the OS2 Warp 4.0
    //  file MUGWEPOP.EXE - Customer Issue #11319 - jjw 27 Mar 97
    // more cheez FP exclusion for #7839 Raul 112598

    if (0x21cd30b4 == dwTemp || 0xf200009a == dwTemp || 0x0500009a == dwTemp
        || 0xe100009a == dwTemp )
        return(EXTSTATUS_OK);


    // Check first 64 bytes of fstart buffer for one of 8 different
    // methods of decryption loop index incrementation.
    // rX in all cases must be BX, SI, or DI.
    //
    // 1)   0xa7                CMPSW           Nightfall.5815 only
    // 2)   0x81 xx 0x02 0x00   ADD rX, 0002
    // 3)   0x81 xx 0xfe 0xff   SUB rX, FEFF
    // 4)   0x83 xx 0x02        ADD rX, 02
    // 5)   0x83 xx 0xfe        SUB rX, -02
    // 6)   0x8d xx 0x02        LEA rX, rx + 02
    // 7)   0xff xx 0xff        INC rX INC rX
    // 8)   0x4x ... 0x4x       INC rX ... INC rX

    wContinue = FALSE;
    for (i=0;i < 96;i++)
    {
        // Check 1

        if (lpbyInfectionBuffer[i] == 0xa7)
        {
            wContinue = TRUE;
            // Do not break out of loop, keep checking for a better
            // signature, if we don't find one we will check only
            // for Nightfall.5815 using entry point stuff below.
        }

        // Check 2 & 3

        else if (lpbyInfectionBuffer[i] == 0x81)
        {

            // 2
            if (lpbyInfectionBuffer[i + 2] == 0x02 &&
                lpbyInfectionBuffer[i + 3] == 0x00)
            {
                if (lpbyInfectionBuffer[i + 1] == 0xc3 ||
                    lpbyInfectionBuffer[i + 1] == 0xc6 ||
                    lpbyInfectionBuffer[i + 1] == 0xc7)
                {
                    wContinue = TRUE;
                    wNight5815 = FALSE;
                    break;
                }
            }
            // 3
            if (lpbyInfectionBuffer[i + 2] == 0xfe &&
                lpbyInfectionBuffer[i + 3] == 0xff)
            {
                if (lpbyInfectionBuffer[i + 1] == 0xeb ||
                    lpbyInfectionBuffer[i + 1] == 0xee ||
                    lpbyInfectionBuffer[i + 1] == 0xef)
                {
                    wContinue = TRUE;
                    wNight5815 = FALSE;
                    break;
                }
            }
        }

        // Check 4 & 5


        else if (lpbyInfectionBuffer[i] == 0x83)
        {

            // 4
            if (lpbyInfectionBuffer[i + 2] == 0x02)
            {
                if (lpbyInfectionBuffer[i + 1] == 0xc3 ||
                    lpbyInfectionBuffer[i + 1] == 0xc6 ||
                    lpbyInfectionBuffer[i + 1] == 0xc7)
                {
                    wContinue = TRUE;
                    wNight5815 = FALSE;
                    break;
                }
            }
            // 5
            if (lpbyInfectionBuffer[i + 2] == 0xfe)
            {
                if (lpbyInfectionBuffer[i + 1] == 0xeb ||
                    lpbyInfectionBuffer[i + 1] == 0xee ||
                    lpbyInfectionBuffer[i + 1] == 0xef)
                {
                    wContinue = TRUE;
                    wNight5815 = FALSE;
                    break;
                }
            }
        }

        // 6)

        else if (lpbyInfectionBuffer[i] == 0x8d     &&
                 lpbyInfectionBuffer[i + 2] == 0x02)
        {
            wTemp = lpbyInfectionBuffer[i+1];
            wTemp &= 0x3f;
            if (wTemp == 0x1f ||
                wTemp == 0x34 ||
                wTemp == 0x3d)
            {
                wContinue = TRUE;
                wNight5815 = FALSE;
                break;
            }
        }

        // 7)
        else if (lpbyInfectionBuffer[i] == 0xff &&
                 lpbyInfectionBuffer[i + 2] == 0xff)
        {

            if (lpbyInfectionBuffer[i + 1] == 0xc3 ||
                lpbyInfectionBuffer[i + 1] == 0xc6 ||
                lpbyInfectionBuffer[i + 1] == 0xc7)
            {
                wContinue = TRUE;
                wNight5815 = FALSE;
                break;
            }
        }

        // 8)

        else if (lpbyInfectionBuffer[i] == 0x47 ||
                 lpbyInfectionBuffer[i] == 0x43 ||
                 lpbyInfectionBuffer[i] == 0x46)
        {
            bInc_rX = lpbyInfectionBuffer[i];

            for (k=1;k < 8;k++)
            {
                if (lpbyInfectionBuffer[i + k] == bInc_rX)
                {
                     wContinue = TRUE;
                     wNight5815 = FALSE;
                     break;
                }
            }
        }

    }
    if (wContinue == FALSE)
        return (EXTSTATUS_OK);


    // Check for conditional jump at end of decrpytion loop followed
    // by another jump.  This jump pair is after the index incrementation.


    wContinue = FALSE;
    for (i=10;i < 96;i++)
    {
        if (lpbyInfectionBuffer[i] <=0x77 &&
            lpbyInfectionBuffer[i] >=0x72   )
        {
            for (k=1;k < 24;k++)
            {
                if ((lpbyInfectionBuffer[i + k] <=0x77 &&
                     lpbyInfectionBuffer[i + k] >=0x72) ||
                     lpbyInfectionBuffer[i + k] == 0xe9  ||
                     lpbyInfectionBuffer[i + k] == 0xeb)
                {
                    wContinue = TRUE;

                }
            }
            if (wContinue)
                break;

        }
        else if (lpbyInfectionBuffer[i] == 0xe3)
        {
            if (lpbyInfectionBuffer[i + 1] & 0x80)
            wContinue = TRUE;
        }
    }
    if (wContinue == FALSE)
        return (EXTSTATUS_OK);

    // Determine entry point

    // exe files
    if (*(lpbyInfectionBuffer + 256)== 'Z' || *(lpbyInfectionBuffer + 256)== 'M')
    {
        // segment offset + initial ip + header size = entry point
        dwEntryPt = ((DWORD) AVDEREF_WORD(lpbyInfectionBuffer + 256 + 0x16)) << 4;
        dwEntryPt +=(DWORD) AVDEREF_WORD(lpbyInfectionBuffer + 256 + 0x14);
        dwEntryPt +=((DWORD) AVDEREF_WORD(lpbyInfectionBuffer + 256 + 0x8)) << 4;
    }
    else

    // Determine entryp point of com files.
    {
        // nightfall and neuroquila don't do com's always starts with a jump
        // The 3 + word value at offset 1 = virus entry point
        dwEntryPt = (DWORD) AVDEREF_WORD(lpbyInfectionBuffer + 256 + 1) + 3;
    }

    // Get file size

    dwFileSize = lpCallBack->FileSize(hFile);

    // If the actual entry point and the expected entry point for file size x
    // match then we have an infection.  Both Neuroquila and Nightfall do
    // padding to a 32 byte boundary but allowing for that we get a constant
    // value for distance between EOF and entry point.

    if (dwEntryPt == dwFileSize - (5832 - ((dwEntryPt + 9) %32)))
    {
        // Nightfall.5815
        *lpwVID = VID_NIGHTFALLB;
        wReturn = EXTSTATUS_VIRUS_FOUND;
    }
    else if (wNight5815)
    {
        // This is true if we detected via method 1 above.
        // Therefore we only want to check for Nightfall.5815.
    }
    else if (dwEntryPt == dwFileSize - (4585 - ((dwEntryPt +10) %32)))
    {
        // Nightfall
        *lpwVID = VID_NIGHTFALL;
        wReturn = EXTSTATUS_VIRUS_FOUND;
    }
    else if (lpbyInfectionBuffer[256] == 0xe9)
    {
        // If we are here for a com infection, exlude the Neuroquila
        // test.  Neuroquila only infects exe (and MBR)
    }
    else
    {
        dwTemp = dwFileSize - (4675 - ((dwEntryPt + 4) % 32));

        // we check for two sizes here, the second is a kludge to detect
        // a damaged sample.
        if (dwEntryPt == dwTemp || dwEntryPt == dwTemp - 65)
        {
            // Neuroquila
            *lpwVID = VID_NEUROQUILA;
            wReturn = EXTSTATUS_VIRUS_FOUND;
        }
    }
    return(wReturn);
}
// End EXTScanFileNightfall

// EXTScanFileSmeg arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyWorkBuffer       : 2-4K buffer for temporary operations (STACK OK also)
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                        EXTSTATUS_VIRUS_FOUND         if virus was found

#define FP_STRING_LEN   8      // Check string length for Creative Labs
                               // Video Blaster or HP Palmtop DISK
#define CALL_INST       0xe8   // Opcode for near CALL instruction
#define CALL_SIZ        3      // Number of bytes in near call instruction

EXTSTATUS EXTScanFileSmeg(LPCALLBACKREV1 lpCallBack,
                      HFILE          hFile,
                      LPBYTE         lpbyInfectionBuffer,
                      LPBYTE         lpbyWorkBuffer,
                      LPWORD         lpwVID)
{
    BYTE    byCLVB[FP_STRING_LEN] =
                        { 0x32, 0xff, 0x8a, 0x1e, 0x80, 0x00, 0xbe, 0x81 };
    BYTE    byHPPP[FP_STRING_LEN] =
                        { 0xb8, 0xd4, 0x4d, 0xcd, 0x15, 0x81, 0xfb, 0x50 };
    BYTE    byEXTRA[FP_STRING_LEN] =
                        { 0xb4, 0x30, 0xe8, 0x2d, 0xfd, 0x0a, 0xc0, 0x74 };
    WORD    wReturn = EXTSTATUS_OK;
    WORD    wResult, cwI, cwDS = 0, wCallCnt;
    DWORD   dResult;
    long    lOffset;

    //_asm    int 3                               // &&S

    for (cwI = 0; cwI < 256; cwI++)
    {
        if ((lpbyInfectionBuffer[cwI] & 0xf0) == 0xd0)
            cwDS++;
    }

    // First we need a 2k buffer starting near fstart.
    // This should always be entirely within the virus, but we will check...

    dResult = lpCallBack->FileSize(hFile);

    if ((0xffffffff == dResult) || (2500 > dResult))
        return (EXTSTATUS_OK);

        // We would be losing data by this cast, except dResult is guaranteed
        // to be less than 5120.
    lOffset = (dResult > 5120) ? -5120 : - (long) dResult;

                                        // Start 5k from EOF
                                        // The fixed id solution
                                        // used 2k of viral code from
                                        // the fstart entry point, but
                                        // this appears unnecessary.
    if (0 > (long)lpCallBack->FileSeek(hFile, lOffset ,SEEK_END))
        return (EXTSTATUS_OK);

    if ((WORD) -1 == (wResult=(WORD)lpCallBack->FileRead(hFile,
                                                    lpbyWorkBuffer, 2048)))
        return (EXTSTATUS_OK);

    // If you don't have enough meat, you can always add more cheez!

    if (cwDS < 16)
    {           // If the D-byte search failed, look for two adjacent CALLs
        wCallCnt = 0;                               // to the same destination

        for (cwI = 0; cwI < 2040; cwI++)
        {
            if ((CALL_INST == lpbyWorkBuffer[cwI]) &&   // Two adjacent CALLs
                (CALL_INST == lpbyWorkBuffer[cwI + CALL_SIZ]))
            {                                   // Get offset from 1st CALL
                cwDS = AVDEREF_WORD(lpbyWorkBuffer + cwI + 1);
                cwDS -= CALL_SIZ;
                                            // Compare w/ offset to 2nd CALL
                if (cwDS == AVDEREF_WORD(lpbyWorkBuffer + cwI + 1
                                                                + CALL_SIZ))
                    wCallCnt++;
            }
        }

        if (0 == wCallCnt)
            return(EXTSTATUS_OK);
    }
                                    // set target to opcode 0x75 JNZ
    cwI = 3;
                                    // wResult - 64 - 64 because we must not
                                    // go out of  buffer.

    while (cwI < (wResult - 64 - 64 - 3 ) && wReturn == EXTSTATUS_OK)
    {                                   // possible match
        if ((lpbyWorkBuffer[cwI] == 0x75) &&
            (lpbyWorkBuffer[cwI + 1] & 0xc0) == 0)
        {
                                        // Confirm jnz is to short
                                        // distance fwd, 2 hi bits are reset.
                                        // Look for any of 3 variants.

                                        // extended if used for clarity

                                        // jnz preceded by sub rX, 1
            if ( AVDEREF_WORD(lpbyWorkBuffer + cwI - 2) == (WORD) 1 )
            {
                if (TRUE == SmegHelp(lpbyWorkBuffer + cwI + 1))
                     wReturn = EXTSTATUS_VIRUS_FOUND;
                     *lpwVID = VID_SMEG;
            }
                                    // jnz preceded by dec rX
            else if ((lpbyWorkBuffer[cwI - 1] & 0xfc) == 0x48)
            {
                if (TRUE == SmegHelp(lpbyWorkBuffer + cwI + 1))
                     wReturn = EXTSTATUS_VIRUS_FOUND;
                     *lpwVID = VID_SMEG;
            }

                                    // jnz preceded by and rX, rX
            else if (lpbyWorkBuffer[cwI - 2] == 0x23 &&
                     (lpbyWorkBuffer[cwI - 1] == 0xc0 ||
                      lpbyWorkBuffer[cwI - 1] == 0xc9 ||
                      lpbyWorkBuffer[cwI - 1] == 0xd2 ||
                      lpbyWorkBuffer[cwI - 1] == 0xdb))
            {
                if (TRUE == SmegHelp(lpbyWorkBuffer + cwI + 1))
                     wReturn = EXTSTATUS_VIRUS_FOUND;
                     *lpwVID = VID_SMEG;
            }


        }// end if
                                        // increment loop counter
        cwI++;
    }// end while

    // Cheez below (spelling is not a typo)

    if (EXTSTATUS_VIRUS_FOUND == wReturn)   // If we think we have a virus,
    {                                       // make sure it's not the Video
        cwI = 0;                            // Blaster driver

        while ((cwI < FP_STRING_LEN) && (byCLVB[cwI] == lpbyInfectionBuffer[cwI]))
            cwI++;

        if (FP_STRING_LEN == cwI)
            wReturn = EXTSTATUS_OK;
    }
    // More Cheez below (spelling is not a typo)

    if (EXTSTATUS_VIRUS_FOUND == wReturn)   // If we think we have a virus,
    {                                       // make sure it's not the HP
        cwI = 0;                            // Palmtop Paper disk (HKFON.COM)

        while ((cwI < FP_STRING_LEN) && (byHPPP[cwI] == lpbyInfectionBuffer[cwI]))
            cwI++;

        if (FP_STRING_LEN == cwI)
            wReturn = EXTSTATUS_OK;
    }
    // Even more Cheez below (spelling is not a typo)

    if (EXTSTATUS_VIRUS_FOUND == wReturn)   // If we think we have a virus,
    {                                       // make sure it's not false +ve.
        cwI = 0;                            // Provide EXTRA protection for customer

        while ((cwI < FP_STRING_LEN) && (byEXTRA[cwI] == lpbyInfectionBuffer[cwI]))
            cwI++;

        if (FP_STRING_LEN == cwI)
            wReturn = EXTSTATUS_OK;
    }

    return(wReturn);
}   // End EXTScanFileSmeg

// SmegHelp expects a LPBYTE which >= 64 bytes from end of
// lpbyWorkBuffer.

BOOL SmegHelp (LPBYTE lpbySearchBuffer)
{
    BYTE    cbCount, cbLimit;
    cbLimit = lpbySearchBuffer[0] + 1;

    for (cbCount = 1;cbCount < cbLimit; cbCount++)
        if (lpbySearchBuffer[cbCount] == 0xe9 &&
            lpbySearchBuffer[cbCount + 2] == 0x00)
            return(TRUE);
    return(FALSE);
}
///////////////////////////////////////////////////////////////////////////////
// Commented out, 12/5/96
///////////////////////////////////////////////////////////////////////////////
// EXTScanFileTPEBOSNIA arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// lpbyInfectionBuffer  : 4K fstart buffers containing TOF, ENTRY, etc.
//                         +0   256 fstart bytes of target program.
//                         +256 64 bytes from TOF of target program.
//                         +512 256 unused
//                         +768 2 Number of external defs called.
//                         +770 2 ID of first external called.
//                         +772 ? ID of additional externals called.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                        EXTSTATUS_VIRUS_FOUND         if virus was found
//
//EXTSTATUS EXTScanFileTPEBOSNIA(LPCALLBACKREV1 lpCallBack,
//                      LPBYTE         lpbyInfectionBuffer,
//                      LPWORD         lpwVID)
//{
//    int c=0;
//    int index=0;
//    int range = 0;
//    int VirusFound = 0;
//
//    LPBYTE  pTable;
//
//    BYTE Table[14] = {0x00, 0x01, 0x10, 0x11, 0x18, 0x19, 0x28,
//                            0x29, 0x30, 0x31, 0x80, 0x81, 0x82, 0x83};
//
//    (void)lpCallBack;
//
//    pTable = Table;
//
//
//    // As long as we are in the Fstart buffer...                        //
//    // look for a (POP AX) 0x58.  If one is found,                      //
//    // look at location-2 bytes for a loop/jn? byte.                    //
//    // This signifies the end of the decryption loop.                   //
//    //                                                                  //
//    // Follow, by looking at the loop data byte.  It                    //
//    // should be within a certain range (within 0xC2 bytes).            //
//    // If not, continue search for next 0x58.                           //
//    //                                                                  //
//    // Assuming everything is right so far, look for a 0x2E             //
//    // (CS Overide) at location-range.  If no 0x2E is found within that //
//    // range, continue search for a 0x58.  Also, make sure we don't     //
//    // go before Fstart boundary (c-range)                              //
//    //                                                                  //
//    // If a 2E is found, look at byte following the 2E for              //
//    // a byte matching one of the bytes in Table                        //
//    //                                                                  //
//    // If matching byte is found, then we have a virus.  Turn           //
//    // on VirusFound flag, and exit returning EXTSTATUS_VIRUS_FOUND     //
//    //                                                                  //
//    // If we reach the end of the Fstart buffer with VirusFound=0,      //
//    // return EXTSTATUS_OK                                              //
//
//    do
//    {
//        if (lpbyInfectionBuffer[c] == 0x58 &&
//            c >= 2 && lpbyInfectionBuffer[c-1] >= 0xC2)
//        {
//            BYTE b;
//            b = lpbyInfectionBuffer[c-2];
//
//            if(b == 0x75 || b == 0x7F || b == 0xE0 || b == 0xE2)
//
//                for(range=0; range <= 0x2F && c-range >= 0; range++)
//                {
//                    if (VirusFound)
//                        break;
//
//                    if (lpbyInfectionBuffer[c-range] == 0x2E)
//                    {
//                        pTable = Table;
//                        for(index=0; index < sizeof(Table); index++)
//                        {
//                            if (lpbyInfectionBuffer[c-range+1] == *pTable++)
//                            {
//                                VirusFound = 1;
//                                break;
//                            }
//                        }
//                    }
//                }
//        }
//
//    }while(c++ < 256 && VirusFound == 0);
//
//    if(VirusFound)
//    {
//        *lpwVID = VID_TPEBOSNIA;
//        return(EXTSTATUS_VIRUS_FOUND);
//    }
//
//    return(EXTSTATUS_OK);
//}
// Commented out, 12/5/96

/////////////////////////////////////////////////////////////////////////////
//                                                                         //
// Def Author: Don Duperault, 10/19/95.                                    //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
// EXTScanFileNatas arguments:
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 4K fstart buffers containing TOF, ENTRY, etc.
//                         +0   256 fstart bytes of target program.
//                         +256 64 bytes from TOF of target program.
//                         +512 256 unused
//                         +768 2 Number of external defs called.
//                         +770 2 ID of first external called.
//                         +772 ? ID of additional externals called.
// lpbyWorkBuffer       : 2-4K buffer for temporary operations (STACK OK also)
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                        EXTSTATUS_VIRUS_FOUND         if virus was found


//   Shared code for EXE and COM detects.
//   Returns Zero if not detected, non-zero if detected.

UINT FindJump(LPBYTE Buffer, DWORD SizeOfBuffer)
  {DWORD i, j;

   // Look for a "E9 ?? F0/F1" 3-byte combo.
   for (i=0; i < SizeOfBuffer; ++i)
      if (*(Buffer+i) == 0xE9)
         if ((*(Buffer+i+2) == 0xF0) || (*(Buffer+i+2) == 0xF1))
            return (69);

   // Look for a "ED 08" 2-byte combo.
   for (i=0; i < SizeOfBuffer; ++i)
      if ((*(Buffer+i) == 0xED) && (*(Buffer+i+1) == 0x08))
         return (69);

   // Look for an "F8" then a "C3".
   for (i=0; i < SizeOfBuffer; ++i)
      if (*(Buffer+i) == 0xF8)
         for (j=i; j < SizeOfBuffer; ++j)
            if (*(Buffer+j) == 0xC3)
               return (69);

   // Look for a "FF E?" 2-byte combo.
   for (i=0; i < SizeOfBuffer; ++i)
      if ((*(Buffer+i) == 0xFF) && (*(Buffer+i+1)>>4 == 0x0E))
         return (69);

   // Look for a "56/52 C3" 2-byte combo...
   for (i=0; i < SizeOfBuffer; ++i)
      if ((*(Buffer+i) == 0x56) || (*(Buffer+i) == 0x52))
         if (*(Buffer+i+1) == 0xC3)
            return (69);

   return (0);
  }



EXTSTATUS EXTScanFileNatas(LPCALLBACKREV1 lpCallBack,
                           HFILE          hFile,
                           LPBYTE         lpbyInfectionBuffer,
                           LPBYTE         lpbyWorkBuffer,
                           LPWORD         lpwVID)
  {UINT    PeskyVirus=0;
   WORD    wTemp, wEntryPt;
   DWORD   dwTemp, dwEntryPt;

   const   DWORD  DistFromEOF = 174;
   const   DWORD  HostByteOff = 150;


   // Make sure the file size is at least 256 bytes in size.
   if (lpCallBack->FileSize(hFile) >= 256)      // Size of file eh...

   // Determine infection type, COM or EXE.

      // See if file starts w/ MZ or ZM.
     {wTemp = AVDEREF_WORD(lpbyInfectionBuffer + 256);
      if ((wTemp == 'MZ') || (wTemp == 'ZM'))

      // exe files //////////////////////////////////////////////////////////

         // segment offset + initial ip + header size = entry point
        {wEntryPt  =  AVDEREF_WORD(lpbyInfectionBuffer + 256 + 0x08);
         wEntryPt  += (WORD) AVDEREF_WORD(lpbyInfectionBuffer + 256 + 0x16);
         dwEntryPt =  (DWORD) wEntryPt << 4;
         dwEntryPt += AVDEREF_WORD(lpbyInfectionBuffer + 256 + 0x14);

         // Calc file size.
         // offset 4h in header, DEC, times 512, + Offset 2h in header
         wTemp =  AVDEREF_WORD(lpbyInfectionBuffer + 256 + 0x04);
         if (AVDEREF_WORD(lpbyInfectionBuffer + 256 + 0x02) != 0)
            --wTemp;
         dwTemp = (DWORD) (wTemp * 512);
         dwTemp += ((DWORD) AVDEREF_WORD(lpbyInfectionBuffer + 256 + 0x02));

         // Seek to the EntryPoint, check for seek error.
         if (-1 != (LONG)lpCallBack->FileSeek(hFile, (LONG)dwEntryPt, SEEK_SET))

         // See if *ONLY* DistFromEOF # of bytes read.
                if (DistFromEOF == (lpCallBack->FileRead(hFile, lpbyWorkBuffer, 1024)))

         // Run shared code for COM and EXE detects.
                   if (FindJump(lpbyWorkBuffer, DistFromEOF-2))

         // See if "MZ" or "ZM" exists at EOF-24.
                      {wTemp = AVDEREF_WORD(lpbyWorkBuffer + HostByteOff);
                       if ((wTemp == 'MZ') || (wTemp == 'ZM'))
                          ++PeskyVirus;        // WooHoo!  Finally got it!
                      }
        }


      // com files //////////////////////////////////////////////////////////

      else if (*(lpbyInfectionBuffer + 256) == 0xE9)
         // Follow the JMP.
        {wEntryPt =  (AVDEREF_WORD(lpbyInfectionBuffer + 256 + 1) + 3);

         // Seek to the EntryPoint, check for seek error.
         if (-1 != (LONG)lpCallBack->FileSeek(hFile, (LONG)wEntryPt, SEEK_SET))

         // See if *ONLY* DistFromEOF # of bytes read.
            if (DistFromEOF == (lpCallBack->FileRead(hFile, lpbyWorkBuffer, 1024)))

         // Run shared code for COM and EXE detects.
             if (FindJump(lpbyWorkBuffer, DistFromEOF-2))

         // See if "word" 00 exists right before stored host bytes.
                 {wTemp = AVDEREF_WORD(lpbyWorkBuffer + HostByteOff - 2);
                  if (wTemp == 0)
                     ++PeskyVirus;        // WooHoo!  Finally got it!
                 }
        }
     }

   // Time to return now...
   if (PeskyVirus)
     {*lpwVID = VID_NATAS;
      return(EXTSTATUS_VIRUS_FOUND);          // Say virus  *WAS*  detected.
     }
   else
      return(EXTSTATUS_OK);                   // Say virus WAS NOT detected.
  }
// End EXTScanFileNatas


// EXTScanFileUrug4 arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 4K fstart buffers containing TOF, ENTRY, etc.
//                         +0   256 fstart bytes of target program.
//                         +256 64 bytes from TOF of target program.
//                         +512 256 unused
//                         +768 2 Number of external defs called.
//                         +770 2 ID of first external called.
//                         +772 ? ID of additional externals called.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                        EXTSTATUS_VIRUS_FOUND         if virus was found

EXTSTATUS EXTScanFileUrug4(LPCALLBACKREV1 lpCallBack,
                      HFILE          hFile,
                      LPBYTE         lpbyInfectionBuffer,
                      LPWORD         lpwVID)
{
    WORD    wReturn = EXTSTATUS_OK;
    WORD    i,k;
    WORD    wVirusCX=FALSE, wVirusInc = FALSE,wVirusIndex = FALSE;
    DWORD   dwEntryPt, dwDistEpEof;

    (void)lpCallBack;
    (void)hFile;

    // Look for 3 criteria of infected files.

    // 1) Look for initialization of CX to a number 0x500 - 0x600
    //    4 methods,
    //     a) MOV (b9)
    //     b) XOR (0x81f1)
    //     c) ADD (0x81c1)
    //     d) OR  (0x81c9)

    // 2) Look for initialization of index register BX, DI, SI.
    //    MOV rX, n
    //    n will be within 0xc0 bytes of the start of the viral body
    //    + 100h start address.
    //    We will use the jump at TOF inserted by the virus for comparison.

    // 3) Look for incrementation of the index register.
    //    3 index registers, BX, DI, SI
    //    3 methods.
    //      a) Add 2, rX
    //      b) Sub -2, rX  (handled above)
    //      c) Inc rX ...garbage... Inc rX.


    for (i=0;i<250;i++)
    {
        // Check for 1a, loop counter initialization by MOV.
        if (lpbyInfectionBuffer[i] == 0xb9)
        {
            if ((AVDEREF_WORD(lpbyInfectionBuffer + i + 1) > 0x500) &&
                (AVDEREF_WORD(lpbyInfectionBuffer + i + 1) < 0x600))
            {
                wVirusCX = TRUE;
            }
        }
        else if (lpbyInfectionBuffer[i] == 0x81)
        {
            // CX loop counter initialized by XOR or ADD

            if (lpbyInfectionBuffer[i+1] == 0xc1 ||
                lpbyInfectionBuffer[i+1] == 0xc9 ||
                lpbyInfectionBuffer[i+1] == 0xf1)
            {
                if ((AVDEREF_WORD(lpbyInfectionBuffer + i + 2) > 0x500) &&
                    (AVDEREF_WORD(lpbyInfectionBuffer + i + 2) < 0x600))
                {
                    wVirusCX = TRUE;
                }
            }

            // Check for index incrementation sub rX, 0xfffe
            else if (AVDEREF_WORD(lpbyInfectionBuffer +i +2) == 0xfffe)
            {
                if (lpbyInfectionBuffer[i+1] == 0xeb ||
                    lpbyInfectionBuffer[i+1] == 0xee ||
                    lpbyInfectionBuffer[i+1] == 0xef)

                    wVirusInc = TRUE;
            }
        }
        // Check for index incrementation by add rX, 0x02

        else if (lpbyInfectionBuffer[i] == 0x83)
        {
            if (lpbyInfectionBuffer[i+2] == 0x02)
            {
                if (lpbyInfectionBuffer[i+1] == 0xc3 ||
                    lpbyInfectionBuffer[i+1] == 0xc6 ||
                    lpbyInfectionBuffer[i+1] == 0xc7)
                {
                    wVirusInc = TRUE;
                }
            }
        }
        // Check for index incrementation by inc rX ... inc rX

        else if (lpbyInfectionBuffer[i] == 0x43 ||
                 lpbyInfectionBuffer[i] == 0x46 ||
                 lpbyInfectionBuffer[i] == 0x47)
        {

            k = (i > 207) ? 255 - i : 48;

            while (k > 0)
            {
                if (lpbyInfectionBuffer[i+k] == lpbyInfectionBuffer[i])
                    wVirusInc = TRUE;
                k--;
            }
        }

        // Check for index initialization.

        else if (lpbyInfectionBuffer[i] == 0xbb ||
                 lpbyInfectionBuffer[i] == 0xbe ||
                 lpbyInfectionBuffer[i] == 0xbf)

        {
            // lpbyInfectionBuffer[256] is 64 bytes from TOF.
            // Virus TOF looks like this e9 xx xx

            if ( (AVDEREF_WORD(lpbyInfectionBuffer + 257) + 0x103 <
                  AVDEREF_WORD(lpbyInfectionBuffer + i + 1)) &&

                 (AVDEREF_WORD(lpbyInfectionBuffer + 257) + 0x203 >
                 AVDEREF_WORD(lpbyInfectionBuffer + i + 1)))
            {
                wVirusIndex = TRUE;
            }
        }
    }

    // Determine entry point.

    dwEntryPt = (DWORD) AVDEREF_WORD(lpbyInfectionBuffer + 256 + 1) + 3;

    // Get file size

    dwDistEpEof = lpCallBack->FileSize(hFile) - dwEntryPt;

    if (dwDistEpEof > 2700 && dwDistEpEof < 2900)
    {
        if (wVirusCX == TRUE && wVirusInc == TRUE && wVirusIndex == TRUE)
        {
            wReturn = EXTSTATUS_VIRUS_FOUND;
            *lpwVID = VID_URUG4;
        }
    }

    return(wReturn);
}
// End EXTScanFileUrug4


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//
//  O n e   H a l f
//
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

typedef struct
{
	char exesig[2];                 /* MZ */
	WORD len_mod_512;       /* length of file % 512 */
	WORD page_size;         /* size of file in 512 byte pages */
	WORD reloc_table_items; /* # of relocation table items */
	WORD header_size;       /* size of header in paragraphs */
	WORD min_par_above;     /* min # of pars needed above program */
	WORD max_par_above;     /* max " */
	WORD ss;
	WORD sp;
	WORD checksum;
	WORD ip;
	WORD cs;
	WORD first_rel_offset;  /* offset of first relocation table */
} EXETYPE;

typedef EXETYPE FAR *LPEXE;

#define ONE_HALF_BUFFER_LEN     64
#define ONE_HALF_COM_TYPE       1
#define ONE_HALF_EXE_TYPE       2

EXTSTATUS ScanForOneHalfAux(LPCALLBACKREV1 lpCallBack,
    HFILE hFile, DWORD dwSegStart, WORD wIP, WORD wType, LPWORD lpwVID)
{
    BYTE    byBuffer[ONE_HALF_BUFFER_LEN], byOff;
    WORD    wResult, wIndex;
    WORD    wJumps = 0;
    WORD    wMoves = 0;
    WORD    wReload;
    WORD    wOff;

    do
    {
        // Offset in file depends on whether it is COM or EXE.

        if (wType == ONE_HALF_COM_TYPE)
            wOff = wIP-0x100;
        else
            wOff = wIP;

        // Seek and read ONE_HALF_BUFFER_LEN bytes from wOff

        if (lpCallBack->FileSeek(hFile,dwSegStart+wOff,SEEK_SET) !=
            dwSegStart+wOff)
            return (EXTSTATUS_FILE_ERROR);

        wResult = lpCallBack->FileRead(hFile,byBuffer,ONE_HALF_BUFFER_LEN);
        if (wResult != ONE_HALF_BUFFER_LEN)
            return(EXTSTATUS_OK);

        wIndex = 0;
        wReload = FALSE;

        while (wIndex < ONE_HALF_BUFFER_LEN-3 &&
               wReload == FALSE)
        {
            switch (byBuffer[wIndex])
            {
                // Single byte instructions

                case 0x0E:
                case 0x16:
                case 0x1F:
                case 0x2E:
                case 0x36:
                case 0x3E:
                case 0x43:
                case 0x46:
                case 0x47:
                case 0x50:
                case 0x90:
                case 0xF5:
                case 0xf8:
                case 0xF9:
                case 0xFB:
                case 0xFC:
                case 0xFD:
					wIndex++;
					wIP++;
					break;

				case 0xB8:
				case 0xB9:
				case 0xBA:
				case 0xBB:
				case 0xBD:
				case 0xBE:
				case 0xBF:  // MOVs
					wIndex += 3;
					wIP += 3;
					wMoves++;
					break;

                case 0x01:      // ADD [BX], DI for example
                case 0x29:
				case 0x31:
				case 0x81:      // XOR/ADD/ETC
					if (wJumps > 3 && wMoves == 2)
                    {
                        *lpwVID = VID_ONEHALF;
						return(EXTSTATUS_VIRUS_FOUND);
                    }

					return(FALSE);

                // Near jump

				case 0xE9:
                    wIP += AVDEREF_WORD(byBuffer+wIndex+1) + 3;
					wJumps++;
					wReload = TRUE;
					break;

                // Short jump

				case 0xEB:
					byOff = byBuffer[wIndex+1];
					wIP += (WORD)(signed short)(signed char)byOff + 2;
					wJumps++;
					wReload = TRUE;
					break;

				default:
					return(EXTSTATUS_OK);

			}
		}

		if (wReload == FALSE)
			return(EXTSTATUS_OK);
	}
	while (wJumps < 7);

    return(EXTSTATUS_OK);
}

// EXTScanFileOneHalf arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 64 bytes from TOF of target program.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                        EXTSTATUS_VIRUS_FOUND         if virus was found

EXTSTATUS EXTScanForOneHalf(LPCALLBACKREV1 lpCallBack,
                        HFILE  hFile,
                        LPBYTE lpbyInfectionBuffer,
                        LPWORD lpwVID)
{

    if (AVDEREF_WORD(lpbyInfectionBuffer+256) == 0x4D5A ||
        AVDEREF_WORD(lpbyInfectionBuffer+256) == 0x5A4D)
    {
        // exe case

        LPEXE   lpHeader;
        DWORD   dwStartOff;
        WORD    wPar;

        lpHeader = (LPEXE)(lpbyInfectionBuffer + 256);

        wPar = (WENDIAN(lpHeader->cs) + WENDIAN(lpHeader->header_size));
        dwStartOff = (DWORD)wPar << 4;

        return(ScanForOneHalfAux(lpCallBack,
                                 hFile,
                                 dwStartOff,
                                 WENDIAN(lpHeader->ip),
                                 ONE_HALF_EXE_TYPE,lpwVID));
	}
    else if (lpbyInfectionBuffer[256] == 0xE9 ||
             lpbyInfectionBuffer[256] == 0xEB)
	{
		// com case

        return(ScanForOneHalfAux(lpCallBack,
            hFile, 0, 0x100, ONE_HALF_COM_TYPE,lpwVID));
    }

    return(EXTSTATUS_OK);
}

// EXTScanFileVagabond arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyWorkBuffer       : 2-4K buffer for temporary operations (STACK OK also)
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                      : EXTSTATUS_VIRUS_FOUND         if virus was found
//                        EXTSTATUS_FILE_ERROR          if file error
//
// Read notes for this in def1f.src!
//

#define VAGA_LENGTH     1246            // Infection length
#define CHECKSTR_LEN    13              // Length of check string
#define GOOD_BYTES      7               // Number of different repeating bytes

EXTSTATUS EXTScanFileVagabond(LPCALLBACKREV1 lpCallBack,
                      HFILE          hFile,
                      LPBYTE         lpbyInfectionBuffer,
                      LPWORD         lpwVID)
{
    BYTE    bFirst;                     // Byte at entry point
    BYTE    bCheckStr[CHECKSTR_LEN] = { 0xbf, 0x00, 0x00, 0xb9, 0xcf, 0x03,
                                        0x2e, 0x80, 0x35, 0x00, 0x47, 0xe2,
                                        0xf9 };     // Virus Match Bytes
    BYTE    bGoodByte[GOOD_BYTES] = {   0x27, 0x2f, 0x37, 0x3f, 0x40, 0x41,
                                        0x42 };     // Virus begins w/ these
    WORD    wReturn = EXTSTATUS_OK;                 // bytes above
    WORD    i, wCheck;                              // Miscellaneous variable
    DWORD   dwFilePos = 0;

    //_asm    int 3                                 // Remove after debugging

    bFirst = lpbyInfectionBuffer[FSTART_OFF];   // Get entry point byte

    // Virus begins w/ a string of 0 or more identical bytes, so we scan until
    // we find a different byte, unless there are 0 bytes at the beginning

    if (bFirst != bCheckStr[0])         // If virus doesn't start w/ "meat"
    {
        for (i = 0; (bFirst != bGoodByte[i]) && (i < GOOD_BYTES); i++);
                    // Make sure repeated bytes are the ones we want
        if (GOOD_BYTES == i)
            return(EXTSTATUS_OK);

        for (i = FSTART_OFF + 1; bFirst == lpbyInfectionBuffer[i]; i++)
        {
            if (FSTART_LEN == i)        // Don't go past the end of the buffer
            {
                wReturn = ReloadBuffer(lpCallBack, hFile, &dwFilePos, &i,
                                        lpbyInfectionBuffer);

                if (EXTSTATUS_OK != wReturn)
                    return(wReturn);
            }
        }

        wCheck = 0;                     // Init Check String Index for loop
    }                                   // below
    else
    {
        i = FSTART_OFF + 1;
        wCheck = 1;
    }

    while ((wCheck < CHECKSTR_LEN) &&
                ((0 == bCheckStr[wCheck]) ||
                (bCheckStr[wCheck] == lpbyInfectionBuffer[i])))
    {
        wCheck++;
        i++;

        if (FSTART_LEN == i)        // Don't go past the end of the buffer
        {
            wReturn = ReloadBuffer(lpCallBack, hFile, &dwFilePos, &i,
                                    lpbyInfectionBuffer);

            if (EXTSTATUS_OK != wReturn)
                return(wReturn);
        }
    }

    if (CHECKSTR_LEN == wCheck)
    {
        *lpwVID = VID_VAGABOND;
        wReturn = EXTSTATUS_VIRUS_FOUND;
    }

    return(wReturn);
}   // End EXTScanFileVagabond

// This reloads the buffer so we can continue to scan for Vagabond

EXTSTATUS ReloadBuffer(LPCALLBACKREV1 lpCB, HFILE hF, LPDWORD pdwFP, LPWORD i,
                        LPBYTE lpbyIB)
{
    UINT    uResult;

    if (0 == *pdwFP)        // If we don't have a valid file pos
    {                       // We make one
        *pdwFP = lpCB->FileSize(hF);
                                    // Get file size and compute
        if (DWERROR == *pdwFP)
            return(EXTSTATUS_FILE_ERROR);

        *pdwFP -= (VAGA_LENGTH - FSTART_LEN);       // Go back to virus entry
        *pdwFP = lpCB->FileSeek(hF, *pdwFP, SEEK_SET);  // point and forward
                                                        // FSTART_LEN
        if (DWERROR == *pdwFP)
            return(EXTSTATUS_FILE_ERROR);
    }

    *i -= FSTART_LEN;               // Reset buffer position
                                    // Read in more from disk
    uResult = lpCB->FileRead(hF, (lpbyIB + *i), FSTART_LEN);

    if (UERROR == uResult)
        return(EXTSTATUS_FILE_ERROR);

    return(EXTSTATUS_OK);
}

// EXTScanFileGripe arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// lpbyInfectionBuffer  : 4K fstart buffers containing TOF, ENTRY, etc.
//                         +0   256 fstart bytes of target program.
//                         +256 64 bytes from TOF of target program.
//                         +512 256 unused
//                         +768 2 Number of external defs called.
//                         +770 2 ID of first external called.
//                         +772 ? ID of additional externals called.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                        EXTSTATUS_VIRUS_FOUND         if virus was found

#define GRP_MAX_DECR_LEN    110

EXTSTATUS EXTScanFileGripe(LPCALLBACKREV1 lpCallBack,
                          HFILE          hFile,
                          LPBYTE         lpbyInfectionBuffer,
                          LPWORD         lpwVID)
{

    WORD    i,
            wVerifyLoop = FALSE,
            wVerifyInc = FALSE,
            wVerifyXor = FALSE;
    DWORD   dwEntryPoint,
            dwDistEpEof;
    switch (lpbyInfectionBuffer[256])
    {
        case 'M' :
        case 'Z' :
            // get entry point
            // segment offset + initial ip + header size = entry point
            dwEntryPoint = ((DWORD) AVDEREF_WORD(lpbyInfectionBuffer + 256 + 0x16)) << 4;
            dwEntryPoint +=(DWORD) AVDEREF_WORD(lpbyInfectionBuffer + 256 + 0x14);
            dwEntryPoint +=((DWORD) AVDEREF_WORD(lpbyInfectionBuffer + 256 + 0x8)) << 4;
            break;

        case 0xe9 :
            // get entry point
            dwEntryPoint = (DWORD) AVDEREF_WORD(lpbyInfectionBuffer + 256 + 1) + 3;
            break;

        default :
            // file is not infected if it isnt exe or e9 com.
            return(EXTSTATUS_OK);
    }

    dwDistEpEof = lpCallBack->FileSize(hFile) - dwEntryPoint;

    if ((dwDistEpEof < 2000) || (dwDistEpEof > 2150))
    {
        // virus entry point vs eof is always in the range 2000 - 2150.
        return(EXTSTATUS_OK);
    }

    // We will always loop through max virus decryptor length bytes
    // only checking if we have a virus after the loop.
    for (i=16;i<96;i++)
    {
        switch (lpbyInfectionBuffer[i])
        {
            // xor encrypt, 2 kinds

            case 0x30 :
            case 0x31 :
                // Look for cs or es override 0x2e or 0x26
                if (((lpbyInfectionBuffer[i-1] & 0xf7) ^ 0x26) == 0)
                    wVerifyXor = TRUE;
                break;

            case 0x33 :
                // Look for
                //mov bx, cs:[si]   2e8b1c
                //xor bx , ax       33d8
                //mov cs:[si], bx   2e891c

                if ((AVDEREF_DWORD(lpbyInfectionBuffer + i + 1) == 0x1c892ed8) &&
                    (AVDEREF_DWORD(lpbyInfectionBuffer + i - 3) == 0x331c8b2e))
                {
                    wVerifyXor = TRUE;
                }
                break;

            // index incrementation, 5 kinds

            case 0x46 :
                // inc si
                // inc si

                if (lpbyInfectionBuffer[i + 1] == 0x46)
                    wVerifyInc = TRUE;
                break;

            case 0x96 :
                // xchg si, ax    0x96
                // inc ax         0x40
                // inc ax         0x40
                // xchg si, ax    0x96

                if (AVDEREF_DWORD(lpbyInfectionBuffer + i) == 0x96404096)
                {
                    wVerifyInc = TRUE;
                }


            case 0x83 :
                // 3 possible

                // dec si
                // add si, 3

                if (AVDEREF_DWORD(lpbyInfectionBuffer + i -1) == 0x03c6834e)
                    wVerifyInc = TRUE;

                // push si
                // pop bx
                // add bx , 2
                // xchg bx, si

                if ((AVDEREF_DWORD(lpbyInfectionBuffer + i -2) == 0xc3835b56)&&
                    (AVDEREF_DWORD(lpbyInfectionBuffer + i + 1) == 0xde8702c3))
                {
                    wVerifyInc = TRUE;
                }

                // add si, 2

                if (AVDEREF_WORD(lpbyInfectionBuffer + i +1) == 0x02c6)
                    wVerifyInc = TRUE;

            // loop, Both the jnz and the loop are followed by a 0xd? or 0xe?
            // 0xc? is allowed for safety.
            case 0x75 :
                // jnz
            case 0xe2 :
                // loop

                if ((lpbyInfectionBuffer[i+1] & 0xc0) == 0xc0)
                {
                    wVerifyLoop = TRUE;
                }
                break;

            default   :
                break;

        }
    }

    if (wVerifyXor && wVerifyInc && wVerifyLoop)
    {
        *lpwVID = VID_GRIPE;
        return(EXTSTATUS_VIRUS_FOUND);
    }
    else
        return(EXTSTATUS_OK);

} // end EXTScanFileGripe

// EXTScanFileCordobes arguments:           &&C
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyWorkBuffer       : 2-4K buffer for temporary operations (STACK OK also)
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                      : EXTSTATUS_VIRUS_FOUND         if virus was found
//                        EXTSTATUS_FILE_ERROR          if file error
//
//      This detects the polymorphic Cordobes virus by looking for the
//      following:
//              1) 2e8c062f00   MOV     CS:[002f], ES   ; Offset 3 to 1b
//              2) 0e0e         PUSH    CS              ; Offset 3 to 1c
//                              PUSH    CS
//              3) 1f           POP     DS      ; These 2 can be in any order
//                 07           POP     ES      ; #2 < last one < off. 1f
//              4) 51           PUSH    CX      ;
//              5) ad           LODSW
//              6) d3(c0 | c8)  ROL/ROR AX, CL
//              7) ab           STOSW
//              8) 59           POP CX
//              9) e2f3         LOOP    001f
//                 eb03         JMP     0031
//                 90           NOP

#define MAXSRCH     16          // Maximum length to search
#define PRELOOP     0x1f        // Length of code before decrypt loop
#define MIDLOOP     0x25        // Middle of loop - setup is done before this
#define ENDLOOP     0x2d        // Ending loop string is here
#define STR1LEN     5           // Lengths of check strings
#define STR2LEN     2
#define STR3LEN     2
#define STR4LEN     4

#define CRPUSHFND   0x01
#define CRPOPFND    0x02
#define CRLODSFND   0x04
#define CRSTOSFND   0x08
#define CRADDSUBFD  0x10
#define CRROTCLFND  0x20
#define CRMOVCLFND  0x40
#define CRLOOPFND   0x80
#define CRALLFOUND  0xff

EXTSTATUS EXTScanFileCordobes(LPCALLBACKREV1 lpCallBack,
                      HFILE          hFile,
                      LPBYTE         lpbyInfectionBuffer,
                      LPWORD         lpwVID)
{
    BYTE    byString1[STR1LEN] = { 0x2e, 0x8c, 0x06, 0x2f, 0x00 },
            byString2[STR2LEN] = { 0x0e, 0x0e },
            byString3[STR3LEN] = { 0x07, 0x1f },
            byString4[STR4LEN] = { 0xf3, 0xeb, 0x03, 0x90 },
            byFound;
    WORD    i, j, wOff, wRes, wToggle;              // Miscellaneous variables
    LPBYTE  lpbySrch;

    // _asm    int 3                            // Remove after debugging &&C

    wOff = FSTART_OFF;                              // Check for #1
    wRes = ScanString((lpbyInfectionBuffer + wOff), PRELOOP, byString1,
                                                                    STR1LEN);
    if (WERROR != wRes)                             // Check for #2
    {
        wRes = ScanString((lpbyInfectionBuffer + wOff), (PRELOOP - 3),
                                                        byString2, STR2LEN);
        if (WERROR != wRes)
        {
            wOff += (wRes + STR2LEN);
            lpbySrch = lpbyInfectionBuffer + wOff;
            i = 0;                              // Look for POP DS or POP ES
                                                // This is number 3
            while ((0x1f != lpbySrch[i]) && (0x07 != lpbySrch[i]) &&
                                                                (MAXSRCH > i))
                i++;

            wRes = wOff + i;

            if (PRELOOP > wRes)             // If we found POP DS or POP ES,
            {                               // We look for the one we didn't
                wToggle = (0x1f == lpbySrch[i++]) ? 0 : 1;          // find
                wOff += i;
                lpbySrch = lpbyInfectionBuffer + wOff;
                i = 0;
                wRes = wOff;

                while ((byString3[wToggle] != lpbySrch[i++]) &&
                                                            (PRELOOP > wRes))
                    wRes++;

                if (PRELOOP >= wRes)            // If we found the other POP
                {
                    i = PRELOOP - 1;            // Look for everything else
                    byFound = 0;

                    do
                    {
                        switch (lpbyInfectionBuffer[i++])
                        {
                            case 0x05 :                 // ADD  AX, ????
                            case 0x2d :                 // SUB  AX, ????
                                if (0 != (byFound & CRLODSFND)) // Make sure
                                {                               // LODSW has
                                    byFound |= CRADDSUBFD;      // been found
                                    i += 2;
                                }
                                break;

                            case 0x51 :                 // PUSH CX
                                byFound |= CRPUSHFND;
                                break;

                            case 0x59 :                 // POP  CX
                                if (0 != (byFound & CRPUSHFND))
                                    byFound |= CRPOPFND;    // Make sure PUSH
                                break;                      // has been found

                            case 0xab :                 // STOSW
                                if (0 != (byFound & CRLODSFND))
                                    byFound |= CRSTOSFND;   // Make sure LODSW
                                break;                      // has been found

                            case 0xad :                 // LODSW
                                byFound |= CRLODSFND;
                                break;

                            case 0xb1 :                 // MOV  CL, ??
                                if (CRPUSHFND ==
                                        (byFound & (CRROTCLFND | CRPUSHFND)))
                                {                           // Make sure PUSH
                                    byFound |= CRMOVCLFND;  // has been found
                                    i++;                    // and RO? hasn't
                                }
                                break;

                            case 0xd3 :                 // RO?  AX, CL
                                if (((CRMOVCLFND | CRLODSFND) ==
                                    (byFound & (CRMOVCLFND | CRLODSFND))) &
                                    (0xc0 == (lpbyInfectionBuffer[i] & 0xf7)))
                                {   // If MOV CL & LODSW found and 2nd byte of
                                    byFound |= CRROTCLFND;  // instruction is
                                    i++;                    // OK
                                }
                                break;

                            case 0xe2 :                 // LOOP
                                if (0 != (byFound & CRPOPFND))
                                {   // If POP CX has been found
                                    for (wRes = 0, j = 0; j < STR4LEN; j++)
                                        if (byString4[j] ==
                                                lpbyInfectionBuffer[i + j])
                                            wRes++;
                                                        // This is a string
                                    if (STR4LEN == wRes)    // comparision
                                    {
                                        byFound |= CRLOOPFND;
                                        i += STR4LEN;
                                    }
                                }

                            default :
                                break;
                        }
                    } while (ENDLOOP > i);

                    if (CRALLFOUND == byFound)
                    {
                        *lpwVID = VID_CORDOBES;

                        return(EXTSTATUS_VIRUS_FOUND);
                    }
                }
            }
        }
    }

    return(EXTSTATUS_OK);
}   // End EXTScanFileCordobes


///////////////////////////////////////////////////////////////////////////////
// RDA detection
///////////////////////////////////////////////////////////////////////////////

// the following array contains 256 bits specifying those instructions that
// RDA can use in its decryption routines. 1=usable, 0=not.  The least sig.
// bit of the first word corresponds to opcode 0, and so on.

WORD gwRDAInstrProfile[] =
{
    0x3FFF,
    0xC03C,
    0x7F7F,
    0x3C7F,
    0xEFEF,
    0xCF4D,
    0x0000,
	0xFFFF,
	0x5F83,
	0x000B,
	0xF300,
	0xEF11,
	0xA0D0,
	0x0007,
	0x0B1C,
	0xFFEC,
};

#define     RDA_STATE_FIND_MOV          0       // initial state
#define     RDA_STATE_FIND_INC_DEC      1       // after finding MOV Index, val
#define     RDA_STATE_FIND_JNZ          2       // after INC or DEC index

#define     RDA_INDEX_NONE              0

#define 	RDA_INDEX_DI				0x5
#define 	RDA_INDEX_BP				0x6
#define 	RDA_INDEX_BX				0x7
#define 	RDA_INDEX_SI				0x4

#define     MOD_MASK                    0xC0    // mask MOD bits of MODRM byte
#define     RM_MASK                     0x07    // mask RM bits of MODRM byte


// EXTScanFileRDA arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 2-4K buffer for temporary operations (STACK OK also)
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                      : EXTSTATUS_VIRUS_FOUND         if virus was found
//                        EXTSTATUS_FILE_ERROR          if file error
//
//      This detects the polymorphic RDA virus by looking for the
//      instructions below.  In addition, each instruction examined must be
//      of the set that RDA is known to use.
//
//          Dummy code...
//          MOV INDEX_REG, VALUE                        (state 0)
//  TOP:    [CS:]                                       (state 0)
//          XOR/ADD/SUB/INC/DEC/ROL/ROR [INDEX], ??     (state 0)
//          INC/DEC INDEX                               (state 1)
//          JNZ/LOOP TOP                                (state 2)


EXTSTATUS EXTScanFileRDA(LPCALLBACKREV1 lpCallBack,
                         HFILE          hFile,
                         LPBYTE         lpbyInfectionBuffer,
                         LPWORD         lpwVID)
{


    int             i, nOffset, nState, nIndexRegister, nNextInstr,
                    nFirstDecryptOffset, nIncDecInstr, nInstrCount;
    BYTE            byOpcode, byNext, byMOVBits;
    UINT            uMaxBytes;
    DWORD           dwSeekOffset;
    LPEXEHEADER_T   lpEXEHeader;
    WORD            wSeg;
    BYTE            byBuffer[1024];

    nInstrCount = nOffset = 0;
    nIndexRegister = RDA_INDEX_NONE;    // no index register as of yet
    nState = RDA_STATE_FIND_MOV;        // initial state

    // first perform a prelim verification on our FSTART data...
    // make sure the first 16 instructions in the FSTART buffer match those
    // that are usable by RDA decryptors...

    for (i=0;i<16;i++)
    {
        byOpcode = lpbyInfectionBuffer[nOffset];
		if ((gwRDAInstrProfile[byOpcode >> 4] & (1 << (byOpcode & 0x0F))) == 0)
            return(EXTSTATUS_OK);
        nOffset += OpcodeLength(lpbyInfectionBuffer+nOffset);
    }

    // next read in 1K of RDA decryptor (potentially) and find our decryptor
    // parts

    lpEXEHeader = (LPEXEHEADER_T)(lpbyInfectionBuffer + 256);

    // determine the location of the entry-point and re-read 1K of data...

    if (lpEXEHeader->exesig[0] == 0xE9)
    {
        // use offset of E9 jump to determine start of virus

        dwSeekOffset = AVDEREF_WORD(lpbyInfectionBuffer + 257) + 3;
    }
    else
    {
        wSeg = WENDIAN(lpEXEHeader->cs) + WENDIAN(lpEXEHeader->header_size);
        dwSeekOffset = (DWORD)wSeg * 16 + WENDIAN(lpEXEHeader->ip);
    }

    if (lpCallBack->FileSeek(hFile,dwSeekOffset,SEEK_SET) == (DWORD)-1)
        return(EXTSTATUS_FILE_ERROR);

    uMaxBytes = lpCallBack->FileRead(hFile, byBuffer, 1024);

    if (uMaxBytes == (UINT)-1)
        return(EXTSTATUS_FILE_ERROR);

    // now use our state-machine to detect the virus decryption loop

    nOffset = 0;

    while (nOffset < uMaxBytes)
	{
        // make sure that each instruction in our infection buffer match those
        // that are usable by RDA decryptors...  This is redundant for the
        // first 16 instructions, but necessary since these instructions may
        // contain important decryption instructions looked for in the state
        // machine.

        byOpcode = byBuffer[nOffset];
        if ((gwRDAInstrProfile[byOpcode >> 4] &
            (1 << (byOpcode & 0x0F))) == 0)
            return(EXTSTATUS_OK);
        nOffset += OpcodeLength(byBuffer+nOffset);

		switch (nState)
		{
			case RDA_STATE_FIND_MOV:
                if (byOpcode == 0xBF ||     // found a mov?
					byOpcode == 0xBD ||
					byOpcode == 0xBB ||
					byOpcode == 0xBE)
				{
                    // remember what register is being used...

					switch (byOpcode)
					{
						case 0xBF:
							nIndexRegister = RDA_INDEX_DI;
							break;
						case 0xBD:
							nIndexRegister = RDA_INDEX_BP;
							break;
						case 0xBB:
							nIndexRegister = RDA_INDEX_BX;
							break;
						case 0xBE:
							nIndexRegister = RDA_INDEX_SI;
							break;
					}

					byMOVBits = byOpcode & RM_MASK;

                    byNext = byBuffer[nOffset];

                    // skip over a CS: (0x2E) if it is the next byte
                    // also remember where we will continue looking for
                    // another MOV instruction should the one we located
                    // be the wrong one... (nFirstDecryptOffset)

					if (byNext == 0x2E)
					{
                        byNext = byBuffer[nOffset + 1];
						nFirstDecryptOffset = nOffset;
						nNextInstr = nOffset + 1;
					}
					else
					{
						nNextInstr = nOffset;
						nFirstDecryptOffset = nNextInstr;
					}

                    // verify that the next instruction is one of the valid
                    // decrypt instructions that RDA can use.

					switch (byNext)
					{
						case 0xD2:
						case 0xFE:
						case 0xF6:
						case 0xD0:
						case 0x28:
						case 0xB0:
                        case 0x30:
						case 0x00:
                            byNext = byBuffer[nNextInstr+1] & RM_MASK;

                            // make sure that the index register initialized
                            // matches the one used in the decryption instr.

							if (byNext == nIndexRegister)
							{
                                byNext = byBuffer[nNextInstr+1] & MOD_MASK;

								if (byNext == 0 || byNext == 0x80)
								{
                                    // if we're doing a memory modification
                                    // in our decryption instruction then
                                    // advance to the next state and look
                                    // for INC/DEC of the index register

									nState = RDA_STATE_FIND_INC_DEC;
								}
							}
							break;
					}
				}
				break;

			case RDA_STATE_FIND_INC_DEC:

                // locate an increment or decrement instruction

				if ((byOpcode & 0xF0) == 0x40 &&
					byMOVBits == (byOpcode & RM_MASK))
				{
                    // found it, and it is using the proper index register
                    // used above.  advance to the next state.

					nState = RDA_STATE_FIND_JNZ;
					nIncDecInstr = nInstrCount;
				}
				break;

			case RDA_STATE_FIND_JNZ:

                // look for a JNZ or a LOOP instruction

				if (byOpcode == 0x75 || byOpcode == 0xE2)
				{
                    // this loop/jnz instruction must be no more than
                    // 3 instructions after the INC/DEC index instruction
                    // found earlier

					if (nIncDecInstr > nInstrCount - 4)
					{
						if (nFirstDecryptOffset ==
                            nOffset + (signed char)byBuffer[nOffset-1])
						{
							// Hit

                            *lpwVID = VID_RDA;

                            return(EXTSTATUS_VIRUS_FOUND);
						}
						else
						{
                            // Start again after the mov found above

							nOffset = nFirstDecryptOffset;
							nState = RDA_STATE_FIND_MOV;
						}
					}
					else
					{
                        // Start again after the mov found above

						nOffset = nFirstDecryptOffset;
						nState = RDA_STATE_FIND_MOV;
					}
				}
				else
				if (nInstrCount >= nIncDecInstr + 3)
				{
                    // Start again after the mov found above

					nOffset = nFirstDecryptOffset;
					nState = RDA_STATE_FIND_MOV;
				}
				break;
		}

        // advance to the next instruction and up our instruction count

		nInstrCount++;
    }

    // no virus found

    return(EXTSTATUS_OK);
}   // End EXTScanFileRDA



///////////////////////////////////////////////////////////////////////////////
// OPCODE following code
///////////////////////////////////////////////////////////////////////////////

static unsigned char one[256] = {
0x00, 0x00, 0x00, 0x00, 0xfe, 0xfd, 0xff, 0xff,
0x00, 0x00, 0x00, 0x00, 0xfe, 0xfd, 0xff, 0xff,
0x00, 0x00, 0x00, 0x00, 0xfe, 0xfd, 0xff, 0xff,
0x00, 0x00, 0x00, 0x00, 0xfe, 0xfd, 0xff, 0xff,
0x00, 0x00, 0x00, 0x00, 0xfe, 0xfd, 0xff, 0xff,
0x00, 0x00, 0x00, 0x00, 0xfe, 0xfd, 0xff, 0xff,
0x00, 0x00, 0x00, 0x00, 0xfe, 0xfd, 0xff, 0xff,
0x00, 0x00, 0x00, 0x00, 0xfe, 0xfd, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
0x01, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff,
0xfd, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff,
0xfe, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd,
0xff, 0xff, 0xfd, 0xff, 0x00, 0x00, 0x01, 0x02,
0xff, 0xff, 0xfd, 0xff, 0xff, 0xfe, 0xff, 0xff,
0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0xff, 0xff,
0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x03,
0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
0xfd, 0xfd, 0xfb, 0xfe, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x06, 0x07,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00
};

static unsigned char table[8][16] = {
{0x88,0x88,0x88,0x88,0x33,0x33,0x33,0x33,0x44,0x44,0x44,0x44,0x22,0x22,0x22,0x22},
{0x99,0x99,0x99,0x99,0x44,0x44,0x44,0x44,0x55,0x55,0x55,0x55,0x33,0x33,0x33,0x33},
{0xAA,0xAA,0xAA,0xAA,0x55,0x55,0x55,0x55,0x66,0x66,0x66,0x66,0x44,0x44,0x44,0x44},
{0x8C,0x88,0x88,0x88,0x34,0x33,0x33,0x33,0x46,0x44,0x44,0x44,0x22,0x22,0x22,0x22},
{0x8C,0x88,0xC8,0xC8,0x34,0x33,0x43,0x43,0x46,0x44,0x64,0x64,0x22,0x22,0x22,0x22},
{0x8C,0x88,0x8C,0x88,0x34,0x33,0x34,0x33,0x46,0x44,0x46,0x44,0x22,0x22,0x22,0x22},
{0x98,0x88,0x88,0x88,0x43,0x33,0x33,0x33,0x54,0x44,0x44,0x44,0x32,0x22,0x22,0x22},
{0xA8,0x88,0x88,0x88,0x53,0x33,0x33,0x33,0x64,0x44,0x44,0x44,0x42,0x22,0x22,0x22}
};

#define high(n) (!((n >> 3) & 1))

int ret_table(int i,int j)
{
	int	col, rowval;

	col = j >> 4;
	if (high(j))
		rowval = (table[i][col] >> 4) & 0xf;
	else
		rowval = table[i][col] & 0xf;
	if (rowval & 8) {
		if ((j & 7) == 6) {
			if (rowval == 0xC) return 6;
			return (rowval&3) + 4;
		}
		return (rowval&3) + 2;
	}
	return rowval;
}

// Returns the number of bytes used by the instruction beginning
// at lpbyInstructionStream.

int OpcodeLength(LPBYTE lpbyInstructionStream)
{
	unsigned char firstbyte;

    firstbyte = (unsigned char)lpbyInstructionStream[0];
    if ((signed char)one[firstbyte] < 0)
		return (0-(signed char)one[firstbyte]);
    return(ret_table(one[firstbyte],lpbyInstructionStream[1] & 0xff));
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// CRUNCHER CRUNCHER  CRUNCHER CRUNCHER CRUNCHER CRUNCHER  CRUNCHER CRUNCHER
// CRUNCHER CRUNCHER  CRUNCHER CRUNCHER CRUNCHER CRUNCHER  CRUNCHER CRUNCHER
///////////////////////////////////////////////////////////////////////////////

#define DIET_WINDOW_SIZE         8192
#define DIET_PARITY_SIG_SIZE     26      // # of parity bits in our signature

// the following array of 8 bytes contains 64 parity bits that match the
// parities of the 64 bytes at the entry-point of the infected EXE file.

BYTE gbyCruncherParitySig[] =
{
    0x67,
    0xBD,
    0x8B,
    0xAF,
    0xCE,
    0x6F,
    0xBE,
    0xFC
};

typedef struct
{
    DWORD       dwEntryOffset;
    int         nBitsCheckedSoFar;
    LPBYTE      lpbySig;
    BOOL        bVirusFound;
} DIET_PARITY_SIG, FAR *LPDIET_PARITY_SIG;

typedef struct
{
    int         nIdx;
    long        lTotalBitsAdded;
    BYTE        byWindow[DIET_WINDOW_SIZE/8];

#ifdef CRUNCHER_DEBUG
    BYTE        byByteWindow[DIET_WINDOW_SIZE];
#endif // CRUNCHER_DEBUG
} DIET_WINDOW_T, FAR *LPDIET_WINDOW;

////////////////////////////////////////////////////////////////////////////
// Compute the parity of a byte
////////////////////////////////////////////////////////////////////////////

#define DIET_PARITY_EVEN 1
#define DIET_PARITY_ODD  0

int nib_parity[16] = {DIET_PARITY_EVEN, DIET_PARITY_ODD, DIET_PARITY_ODD, DIET_PARITY_EVEN,
                      DIET_PARITY_ODD, DIET_PARITY_EVEN, DIET_PARITY_EVEN, DIET_PARITY_ODD,
                      DIET_PARITY_ODD, DIET_PARITY_EVEN, DIET_PARITY_EVEN, DIET_PARITY_ODD,
                      DIET_PARITY_EVEN, DIET_PARITY_ODD, DIET_PARITY_ODD, DIET_PARITY_EVEN};

int GetParity(BYTE byValue)
{
    byValue ^= (byValue >> 4);
    byValue &= 0xFLU;
    return nib_parity[(WORD)byValue];
}

// this function fetches a diet control word that specifies the nature
// (literal or dictionary entry) of the data in the stream...

BOOL DietGetAndShiftControlWord
(
    LPCALLBACKREV1      lpCallBack,
    HFILE               hFile,
    LPINT               lpnBitCount,
    LPWORD              lpwControlWord
)
{
	BOOL        bReturn;

	bReturn = *lpwControlWord & 1;
	*lpwControlWord >>= 1;
	if (--(*lpnBitCount) == 0)
	{
        if (lpCallBack->FileRead(hFile,lpwControlWord,sizeof(WORD)) == (UINT)-1)
            return(FALSE);

        *lpwControlWord = AVDEREF_WORD(lpwControlWord);

		*lpnBitCount = 16;
	}
	return(bReturn);
}

// Add a bit to the 8K decompressed parity stream...

BOOL DietAddBit
(
    LPDIET_WINDOW   lpWindow,
    int             nBit,

#ifdef CRUNCHER_DEBUG
    int             nByte,
#endif // CRUNCHER_DEBUG

    LPDIET_PARITY_SIG lpParitySig
)
{
    BYTE    byBitMask;
    int     nBitShift;

    nBitShift = (lpWindow->nIdx & 0x7);
    byBitMask = 1 << nBitShift;
    lpWindow->byWindow[lpWindow->nIdx >> 3] =
        (lpWindow->byWindow[lpWindow->nIdx >> 3] & ~byBitMask) |
        (nBit << nBitShift);

#ifdef CRUNCHER_DEBUG
    lpWindow->byByteWindow[lpWindow->nIdx] = nByte;
#endif // CRUNCHER_DEBUG

    // wrap around at the end of the window

    if (++lpWindow->nIdx == DIET_WINDOW_SIZE)
		lpWindow->nIdx = 0;

    // up the total number of decompressed bytes...

	lpWindow->lTotalBitsAdded++;

    // Should we start checking for our signature?

    if (lpWindow->lTotalBitsAdded > lpParitySig->dwEntryOffset)
    {
        int     nSigBit;

        // What's the next parity bit in the sig?

		if ((lpParitySig->lpbySig[lpParitySig->nBitsCheckedSoFar >> 3] &
            (1 << (lpParitySig->nBitsCheckedSoFar & 0x07))) == 0)
            nSigBit = 0;
        else
            nSigBit = 1;

        if (nSigBit != nBit)
        {
            // Sig did not match where it was supposed to

            return(FALSE);
        }

        if (++(lpParitySig->nBitsCheckedSoFar) == DIET_PARITY_SIG_SIZE)
        {
            // Completed verification

            lpParitySig->bVirusFound = TRUE;
            return(FALSE);
        }
    }

    return(TRUE);
}

// copy parity bits from earlier in our decompressed stream

BOOL DietCopyBits(LPDIET_WINDOW lpWindow, int nOffset, int nNumBits,
    LPDIET_PARITY_SIG lpParitySig)
{
	int     i;
	int     nIdx;
	int     nBit;

	for (i=0;i<nNumBits;i++)
	{
		nIdx = lpWindow->nIdx + nOffset;

		if (nIdx < 0)
			nIdx += DIET_WINDOW_SIZE;

		if ((lpWindow->byWindow[nIdx >> 3] & (1 << (nIdx & 0x7))) == 0)
			nBit = 0;
		else
            nBit = 1;

        if (DietAddBit(lpWindow,
                       nBit,

#ifdef CRUNCHER_DEBUG
                       lpWindow->byByteWindow[nIdx],
#endif // CRUNCHER_DEBUG

                       lpParitySig) == FALSE)
            return(FALSE);
    }

    return(TRUE);
}

// determine if the current file is a multi-segment, diet compressed
// EXE file.  We basically match a signature in the diet EXE file that
// is found 106 bytes from the EOF.

EXTSTATUS DietIsMultiSeg
(
    LPCALLBACKREV1          lpCallBack,
    HFILE                   hFile,
    LPBOOL                  lpbIsMultiSeg
)
{
    BYTE                    bySig[] = { 0xE8, 0x69, 0xFF, 0x73, 0x27, 0xB1};
    BYTE                    byBuffer[sizeof(bySig)];
    int                     i;

    *lpbIsMultiSeg = FALSE;

    if (lpCallBack->FileSize(hFile) < 106)
        return(EXTSTATUS_FILE_ERROR);

    if (lpCallBack->FileSeek(hFile,-106,SEEK_END) == (DWORD)-1)
        return(EXTSTATUS_FILE_ERROR);

    if (lpCallBack->FileRead(hFile,byBuffer,sizeof(bySig)) == (UINT)-1)
        return(EXTSTATUS_FILE_ERROR);

    for (i=0;i<sizeof(bySig);i++)
        if (byBuffer[i] != bySig[i])
            break;

    if (i == sizeof(bySig))
        *lpbIsMultiSeg = TRUE;

    return(EXTSTATUS_OK);
}

// initialize our parity signature system

EXTSTATUS DietInitializeParitySig
(
    LPCALLBACKREV1          lpCallBack,
    HFILE                   hFile,
    LPDIET_PARITY_SIG       lpParitySig
)
{
    DWORD                   dwEntryPoint;

    if (lpCallBack->FileSeek(hFile,-4,SEEK_END) == (DWORD)-1)
        return(EXTSTATUS_FILE_ERROR);

    if (lpCallBack->FileRead(hFile,&dwEntryPoint,sizeof(DWORD)) !=
        sizeof(DWORD))
        return(EXTSTATUS_FILE_ERROR);

    dwEntryPoint = DWENDIAN(dwEntryPoint);

    lpParitySig->dwEntryOffset =
        (dwEntryPoint >> 12) + (dwEntryPoint & 0xFFFFU);
    lpParitySig->nBitsCheckedSoFar = 0;
    lpParitySig->lpbySig = gbyCruncherParitySig;
    lpParitySig->bVirusFound = FALSE;

    return(EXTSTATUS_OK);
}

// Scan for cruncher in EXE files...
// This uses a direct port of the ASM code found in DIET for EXE files...

EXTSTATUS EXTScanFileCruncherEXE
(
    LPCALLBACKREV1          lpCallBack,
    HFILE                   hFile,
    LPWORD                  lpwVID
)
{
    BOOL            bIsMultiSeg;
    int             nBitCount, nByteCopyCount, nBitCheckCount;
    WORD            wControlWord;
    BOOL            bBitSet;
    BYTE            byLowOff, byHighOff;
    BYTE            byData;
    DIET_WINDOW_T   stDietWindow;
    DIET_PARITY_SIG      stParitySig;

    // determine whether or not we have a multi-segment host

    if (DietIsMultiSeg(lpCallBack,hFile,&bIsMultiSeg) != EXTSTATUS_OK)
        return(EXTSTATUS_FILE_ERROR);

    // initialize our diet decompression parity window

    stDietWindow.nIdx = 0;
    stDietWindow.lTotalBitsAdded = 0;

    // initialize our diet parity signature structure

    if (DietInitializeParitySig(lpCallBack,
                                hFile,
                                &stParitySig) != EXTSTATUS_OK)
        return(EXTSTATUS_FILE_ERROR);

    // seek to the start of the data stream...

    if (lpCallBack->FileSeek(hFile,0x5A,SEEK_SET) == (DWORD)-1)
        return(EXTSTATUS_FILE_ERROR);

    // load up our starting control word...

    if (lpCallBack->FileRead(hFile,&wControlWord,sizeof(WORD)) !=
        sizeof(WORD))
        return(EXTSTATUS_FILE_ERROR);

    wControlWord = WENDIAN(wControlWord);

    // start that decompression

	nBitCount = 16;

	goto label_1002;

label_0F95:

    // Input hFile = 01

    bBitSet = DietGetAndShiftControlWord(lpCallBack,hFile,&nBitCount,&wControlWord);

    byHighOff <<= 1;
    byHighOff |= bBitSet;

    bBitSet = DietGetAndShiftControlWord(lpCallBack,hFile,&nBitCount,&wControlWord);

    if (bBitSet)
        goto label_0FB3;

    nByteCopyCount = 2;
    nBitCheckCount = 3;

label_0FA3:

    bBitSet = DietGetAndShiftControlWord(lpCallBack,hFile,&nBitCount,&wControlWord);

    if (bBitSet)
        goto label_0FB1;

    bBitSet = DietGetAndShiftControlWord(lpCallBack,hFile,&nBitCount,&wControlWord);

    byHighOff <<= 1;
    byHighOff |= bBitSet;

    nByteCopyCount *= 2;

    if (--nBitCheckCount > 0)
        goto label_0FA3;

label_0FB1:

    byHighOff -= nByteCopyCount;

label_0FB3:

    nByteCopyCount = 2;
    nBitCheckCount = 4;

label_0FB7:

    nByteCopyCount++;

    bBitSet = DietGetAndShiftControlWord(lpCallBack,hFile,&nBitCount,&wControlWord);

    if (bBitSet)
        goto label_0FCE;

    if (--nBitCheckCount > 0)
        goto label_0FB7;

    bBitSet = DietGetAndShiftControlWord(lpCallBack,hFile,&nBitCount,&wControlWord);

    if (!bBitSet)
        goto label_0FD2;

    nByteCopyCount++;

    bBitSet = DietGetAndShiftControlWord(lpCallBack,hFile,&nBitCount,&wControlWord);

    if (!bBitSet)
        goto label_0FCE;

    nByteCopyCount++;

    goto label_0FFC;

label_0FCE:

    goto label_0FFC;

label_0FD2:

    bBitSet = DietGetAndShiftControlWord(lpCallBack,hFile,&nBitCount,&wControlWord);

    if (bBitSet)
        goto label_0FE7;

    nByteCopyCount = 0;
    nBitCheckCount = 3;

label_0FDB:

    bBitSet = DietGetAndShiftControlWord(lpCallBack,hFile,&nBitCount,&wControlWord);

    nByteCopyCount <<= 1;
    nByteCopyCount |= bBitSet;

    if (--nBitCheckCount > 0)
        goto label_0FDB;

    nByteCopyCount += 9;
    goto label_0FCE;

label_0FE7:

    if (lpCallBack->FileRead(hFile,&byData,sizeof(BYTE)) !=
        sizeof(BYTE))
        return(EXTSTATUS_FILE_ERROR);

    nByteCopyCount = byData;
    nByteCopyCount += 0x11;

    goto label_0FFC;

label_0FEF:

    nBitCheckCount = 3;

label_0FF1:

    bBitSet = DietGetAndShiftControlWord(lpCallBack,hFile,&nBitCount,&wControlWord);

    byHighOff <<= 1;
    byHighOff |= bBitSet;

    if (--nBitCheckCount > 0)
        goto label_0FF1;

    byHighOff--;

label_0FFA:

    nByteCopyCount = 2;

    goto label_0FFC;        // fall through

label_0FFC:

    if (DietCopyBits(&stDietWindow,(short)(((WORD)byHighOff << 8) | byLowOff),
        nByteCopyCount,&stParitySig) == FALSE)
        goto label_done;

    goto label_1002;

label_1002:

    bBitSet = DietGetAndShiftControlWord(lpCallBack,hFile,&nBitCount,&wControlWord);

    if (!bBitSet)
        goto label_100A;

    if (lpCallBack->FileRead(hFile,&byData,sizeof(BYTE)) !=
        sizeof(BYTE))
        return(EXTSTATUS_FILE_ERROR);

    if (DietAddBit(&stDietWindow,
                   GetParity(byData),

#ifdef CRUNCHER_DEBUG
                   byData,
#endif // CRUNCHER_DEBUG

                   &stParitySig) == FALSE)
        goto label_done;

    goto label_1002;

label_100A:

    bBitSet = DietGetAndShiftControlWord(lpCallBack,hFile,&nBitCount,&wControlWord);

    if (lpCallBack->FileRead(hFile,&byData,sizeof(BYTE)) !=
        sizeof(BYTE))
        return(EXTSTATUS_FILE_ERROR);

    byLowOff = byData;
    byHighOff = 0xFF;

    if (bBitSet)
        goto label_0F95;

    bBitSet = DietGetAndShiftControlWord(lpCallBack,hFile,&nBitCount,&wControlWord);

    if (bBitSet)
        goto label_0FEF;

    // Input hFile = 000

    if (byLowOff != byHighOff)
        goto label_0FFA;

    if (bIsMultiSeg)
    {
        bBitSet = DietGetAndShiftControlWord(lpCallBack,hFile,&nBitCount,&wControlWord);
        if (bBitSet)
            goto label_1002;
    }

    goto label_done;

label_done:

    if (stParitySig.bVirusFound == TRUE)
        return(EXTSTATUS_VIRUS_FOUND);

    return(EXTSTATUS_OK);
}

// Scan for cruncher in COM files...
// Algorithm:
// Verify there's an E9 jump at the TOF
// Check destination of this jump and make sure its the proper distance from
// the end of the decompressed program's image.  There are 4 valid values,
// because of the two cruncher variants.

EXTSTATUS EXTScanFileCruncherCOM(LPBYTE lpbyTOFBuffer)
{
    LPWORD      lpwPtr;
    WORD        wCOMEndOffset, wEntryOffset, wEOFDist;

    // is there a JMP at the top of the stream

    if (lpbyTOFBuffer[0x27] != 0xE9)
        return(EXTSTATUS_OK);

    // examine the decompressed size of the COM file

    lpwPtr = (LPWORD)(lpbyTOFBuffer + 1);
    wCOMEndOffset = AVDEREF_WORD(lpwPtr);

    // examine the destination of the JMP at the top of the stream

    lpwPtr = (LPWORD)(lpbyTOFBuffer + 0x28);
    wEntryOffset = AVDEREF_WORD(lpwPtr);

    wEOFDist = wCOMEndOffset - wEntryOffset;

    /* Variant 1 */

    if (wEOFDist == 0xdf1 || wEOFDist == 0xdf0)
        return(EXTSTATUS_VIRUS_FOUND);

    /* Variant 2 */

    if (wEOFDist == 0x1564 || wEOFDist == 0x1565)
        return(EXTSTATUS_VIRUS_FOUND);

    /* Variant 3 (original one that asks politely to infect) */

    if (wEOFDist == 0x1884 || wEOFDist == 0x1885)
        return(EXTSTATUS_VIRUS_FOUND);

    /* New Variant */
    if (wEOFDist == 0x156A || wEOFDist == 0x156B)
        return(EXTSTATUS_VIRUS_FOUND);


    return(EXTSTATUS_OK);
}


// EXTScanFileCruncher arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 2-4K buffer for temporary operations (STACK OK also)
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                      : EXTSTATUS_VIRUS_FOUND         if virus was found
//                        EXTSTATUS_FILE_ERROR          if file error
//
//      This detects the compressed Cruncher virus in COM and EXE files.

EXTSTATUS EXTScanFileCruncher(LPCALLBACKREV1 lpCallBack,
                              HFILE          hFile,
                              LPBYTE         lpbyInfectionBuffer,
                              LPWORD         lpwVID)
{
    LPWORD                  lpwPtr;
    EXTSTATUS               extStatus;

    lpwPtr = (LPWORD)(lpbyInfectionBuffer + 256);

    if (lpbyInfectionBuffer[256] == 0xBF)
    {
        // dealing with potential COM infection
        // Send in a pointer to the TOF and verify...

        if (EXTScanFileCruncherCOM(lpbyInfectionBuffer + 256) ==
            EXTSTATUS_VIRUS_FOUND)
        {
            *lpwVID = VID_CRUNCHER_COM;

            return(EXTSTATUS_VIRUS_FOUND);
        }
    }
    else if (*lpwPtr == 0x4D5A || *lpwPtr == 0x5A4D)
    {
        // dealing with potential EXE infection

        extStatus = EXTScanFileCruncherEXE(lpCallBack,hFile,lpwVID);
        if (extStatus == EXTSTATUS_VIRUS_FOUND)
        {
            *lpwVID = VID_CRUNCHER_EXE;
            return(EXTSTATUS_VIRUS_FOUND);
        }
        else if (extStatus != EXTSTATUS_OK)
            return(extStatus);
    }

    return(EXTSTATUS_OK);
}

///////////////////////////////////////////////////////////////////////////////
// CRUNCHER CRUNCHER  CRUNCHER CRUNCHER CRUNCHER CRUNCHER  CRUNCHER CRUNCHER
// CRUNCHER CRUNCHER  CRUNCHER CRUNCHER CRUNCHER CRUNCHER  CRUNCHER CRUNCHER
///////////////////////////////////////////////////////////////////////////////


// EXTScanFileHare arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 4K fstart buffers containing TOF, ENTRY, etc.
//                         +0   256 fstart bytes of target program.
//                         +256 64 bytes from TOF of target program.
//                         +512 256 unused
//                         +768 2 Number of external defs called.
//                         +770 2 ID of first external called.
//                         +772 ? ID of additional externals called.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                        EXTSTATUS_VIRUS_FOUND         if virus was found

#define ADD	0x00
#define XOR 0x30
#define SUB 0x28

EXTSTATUS EXTScanFileHare(LPCALLBACKREV1 lpCallBack,
                          HFILE          hFile,
                          LPBYTE         lpbyInfectionBuffer,
						  LPBYTE		 lpbyWorkBuffer,
                          LPWORD         lpwVID)
{
    WORD    wReturn = EXTSTATUS_OK;
    WORD    i,j,k,l;
    BOOL    bVirusIndex = FALSE,
			bVirusKey   = FALSE,
			bLoopCntr	= FALSE,
			bDecrypt	= FALSE;
    DWORD   dwEntryPt, dwDistEpEof;
	BYTE	byEncryption;
	DWORD	dwSeekLen;
    DWORD   dwCheese;
	WORD 	wKey,
			Hare[3] = {7610, 7750, 7786},
			HareVid[3] = {VID_HARE7610, VID_HARE7750, VID_HARE7786};
	BYTE	byIndex1 = 3,
			byIndex2 = 6;


	// Table of encodings for Segment override and type of Encryption

	// WORD	wSegOvRdEnc[] = { 0x0026, 0x2826, 0x3026,
    //                          0x002e, 0x282e, 0x302e,
    //                         0x0036, 0x2836, 0x3036,
    //                          0x003e, 0x283e, 0x303e };

	WORD	wSegOvRdEnc[] = { 0x0026, 0x002e, 0x0036, 0x003e,
							  0x2826, 0x282e, 0x2836, 0x283e,
						      0x3026, 0x302e, 0x3036, 0x303e };

	// Table of Register encodings for encryption

	BYTE	byRegEncode[] = { 0x07, 0x27, 0x0f, 0x2f, 0x17,
                              0x37, 0x04, 0x24, 0x0c, 0x2c,
                              0x14, 0x34, 0x05, 0x25, 0x0d,
                              0x2d, 0x15, 0x3d, 0x1d, 0x3c,
                              0x1c, 0x35 };



    // 1) Look for initialization of index register BX, DI, SI.
    //    MOV rX, n
    //    n can be any number since the virus will sometime do
	//    MOV rX, n ... ... ADD rX, n
    //    or some other combination of that with SUB, etc

	// 2) Look for initialization of the key which is in
	//    AL, AH, CL, CH, DL, DH

	// 3) Look for initialization of loop counter AX, BX, CX, DX, SI, DI, BP
	//	  MOV rX, n
	//	  n is between 1da0 and 1e75

	// 4) Look for decryption.
	//	  Virus always uses a segment register DS, CS, ES, SS
	//	  Encryption is byte ADD, SUB, XOR with an 8-bit register


    // This is major cheez to eliminate an FP with some cheese
    // cheat program for some game that's about 8 years old.

    dwCheese = AVDEREF_DWORD(lpbyInfectionBuffer);
    if (0x00bbc4b0 == dwCheese || 0x00bbccb0 == dwCheese)
        return(EXTSTATUS_OK);

    dwCheese = AVDEREF_DWORD(lpbyInfectionBuffer+2);
    if (0x530100bb == dwCheese)
        return(EXTSTATUS_OK);


	//_asm int 3

    for (i = 0; i < 50 ; i++)
    {

        // Check for index initialization.

        if (lpbyInfectionBuffer[i] == 0xbb ||
            lpbyInfectionBuffer[i] == 0xbe ||
            lpbyInfectionBuffer[i] == 0xbf)

		{
            bVirusIndex = TRUE;
			break;
        }
    }


	// If we didn't find a mov into an index register then there's
    // no virus here.

	if (!bVirusIndex)
		return (wReturn);


	for(i = 0 ; i < 50 ; i++)
	{
		// Check for key initialization

		if ((lpbyInfectionBuffer[i] & 0xf8) == 0xb0 )
		{
			bVirusKey = TRUE;
			break;
		}
	}

	
	if (!bVirusKey)
		return (wReturn);



	for (i = 0; i < 50 ; i++)
	{

		// Check for init of loop counter

		if ((lpbyInfectionBuffer[i] & 0xf8) == 0xb8 )
		{
            if (AVDEREF_WORD(lpbyInfectionBuffer + i + 1) > 0x1da0 &&
                AVDEREF_WORD(lpbyInfectionBuffer + i + 1) < 0x1e75   )
			{
				bLoopCntr = TRUE;
				break;
			}
		}
	}


	if (!bLoopCntr)
		return (wReturn);


	for (j = i ; i < j + 50 ; i++)
	{
		// Look for decryption

		for (k = 0 ; k < 12 ; k++)
        {
            if( AVDEREF_WORD(lpbyInfectionBuffer + i) == wSegOvRdEnc[k])
			{
				if (k < 4) byEncryption = ADD;
				if (k > 7) byEncryption = XOR;
				if (k > 3 && k < 8) byEncryption = SUB;

				for (l = 0; l < 22 ; l++)
				{
					if (lpbyInfectionBuffer[i+2] == byRegEncode[l])
					{
						bDecrypt = TRUE;
						break;
					}
				}
			}

			if (bDecrypt)
				break;
		}

		if (bDecrypt)
			break;

	}


	if (!bDecrypt)
		return (wReturn);




    // Determine entry point

    // exe files
    if (*(lpbyInfectionBuffer + 256)== 'Z' || *(lpbyInfectionBuffer + 256)== 'M')
    {
        // segment offset + initial ip + header size = entry point
        dwEntryPt = ((DWORD) AVDEREF_WORD(lpbyInfectionBuffer + 256 + 0x16)) << 4;
        dwEntryPt +=(DWORD) AVDEREF_WORD(lpbyInfectionBuffer + 256 + 0x14);
        dwEntryPt +=((DWORD) AVDEREF_WORD(lpbyInfectionBuffer + 256 + 0x8)) << 4;
    }
    else

    // Determine entryp point of com files.
    {
        // The 3 + word value at offset 1 = virus entry point
        dwEntryPt = (DWORD) AVDEREF_WORD(lpbyInfectionBuffer + 256 + 1) + 3;
    }

    // Get file size

    dwDistEpEof = lpCallBack->FileSize(hFile) - dwEntryPt;

    if (dwDistEpEof > 25 && dwDistEpEof < 120)
    {
        wReturn = EXTSTATUS_VIRUS_FOUND;
        *lpwVID = VID_HARE;
    }

	// See if we can figure out which variant of Hare this is
	// if we can this will the return the VID for the specific
	// variant (in either def2f or def2e).  If we can't we'll
	// still return the VID for Hare (in def1f).


	for (i = 0 ; i < 3 ; i++)
    {

		dwSeekLen = dwEntryPt - Hare[i];

		if (i > 0)
		{
			byIndex1 = 5;
			byIndex2 = 8;
		}

		// Seek to the second decryption loop

		if ((lpCallBack->FileSeek(hFile, (LONG) dwSeekLen, SEEK_SET)) == -1)
			return(wReturn);


		// Read in the loop

		if ((lpCallBack->FileRead(hFile, lpbyWorkBuffer, 0x12)) == -1)
			return(wReturn);


		// Since we know which type of encryption was used we can try to
		// decrypt the loop and if we find what we want then we know which
		// variant we have.

		for (wKey = 0 ; wKey < 256; wKey++)
        {
			switch (byEncryption)
			{
				case ADD:
	
					if (((BYTE) (lpbyWorkBuffer[0] + (BYTE) wKey) == 0xBE) &&
						((BYTE) (lpbyWorkBuffer[byIndex1] + (BYTE) wKey) == 0xB9) &&
						((BYTE) (lpbyWorkBuffer[byIndex2] + (BYTE) wKey) == 0xBF) )
					{
						*lpwVID = HareVid[i];
						return (wReturn);
					}
	
 					break;

				case SUB:

					if (((BYTE) (lpbyWorkBuffer[0] - (BYTE) wKey) == 0xBE) &&
						((BYTE) (lpbyWorkBuffer[byIndex1] - (BYTE) wKey) == 0xB9) &&
						((BYTE) (lpbyWorkBuffer[byIndex2] - (BYTE) wKey) == 0xBF) )
					{
						*lpwVID = HareVid[i];
						return(wReturn);
					}
	
					break;
	
				case XOR:

					if (((BYTE) (lpbyWorkBuffer[0] ^ (BYTE) wKey) == 0xBE) &&
						((BYTE) (lpbyWorkBuffer[byIndex1] ^ (BYTE) wKey) == 0xB9) &&
						((BYTE) (lpbyWorkBuffer[byIndex2] ^ (BYTE) wKey) == 0xBF) )
					{
						*lpwVID = HareVid[i];
						return(wReturn);
					}
	
					break;

			}
		}
	}

    return(wReturn);

}
// End EXTScanFileHare


// EXTScanFileWidow arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 4K fstart buffers containing TOF, ENTRY, etc.
//                         +0   256 fstart bytes of target program.
//                         +256 64 bytes from TOF of target program.
//                         +512 256 unused
//                         +768 2 Number of external defs called.
//                         +770 2 ID of first external called.
//                         +772 ? ID of additional externals called.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                        EXTSTATUS_VIRUS_FOUND         if virus was found

EXTSTATUS EXTScanFileWidow(LPCALLBACKREV1 lpCallBack,
                           HFILE          hFile,
                           LPBYTE         lpbyInfectionBuffer,
						   LPBYTE		 lpbyWorkBuffer,
                           LPWORD         lpwVID)
{
    WORD    wReturn = EXTSTATUS_OK;
    BYTE    byCheck;
    int     i;

	//_asm int 3

    // This detections is quick and dirty.  In Virscan we've already
    // Verified two bytes in the header and that the EOF entry point
    // distance is 128.  That's proabably about as strong as a good
    // CRC def.  So we are just adding one more little check verify
    // that this is truely an infection and not an FP.

    // Seek to EOF - VSIZE
    if (lpCallBack->FileSeek(hFile,-5747,SEEK_END) == (DWORD)-1)
        return(EXTSTATUS_FILE_ERROR);

    if ((lpCallBack->FileRead(hFile, lpbyWorkBuffer, 100)) == -1)
        return(EXTSTATUS_FILE_ERROR);

    byCheck = lpbyWorkBuffer[50];

    for (i = 51; i < 62; i++)
        if (byCheck != lpbyWorkBuffer[i])
            return (wReturn);

    if (byCheck == lpbyWorkBuffer[i])
        return (wReturn);


    wReturn = EXTSTATUS_VIRUS_FOUND;
    *lpwVID = VID_WIDOW;

    return(wReturn);

}
// End EXTScanFileWidow



WORD gwVICEInstrProfile[] =
{
    0x0021,
    0xC000,
    0x6100,
    0x0243,
    0x0FE0,
    0x080F,
    0x0000,
	0x0230,
	0x4D2B,
	0x3001,
	0x0000,
	0xEFFF,
	0xD008,
	0x0000,
	0x0805,
	0x1F20,
};

#define VICE_BUFFER_LEN     0x100

// EXTScanFileVICE arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 64 bytes from TOF of target program.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                        EXTSTATUS_VIRUS_FOUND         if virus was found

EXTSTATUS EXTScanFileVICE(LPCALLBACKREV1 lpCallBack,
                        HFILE  hFile,
                        LPBYTE lpbyInfectionBuffer,
                        LPWORD lpwVID)
{

    BYTE            byOpcode, byOff,
     		        byBuffer[VICE_BUFFER_LEN];
    WORD            wIndex, wSeg, wIP = 0, wOpLen,
	        		wJumps = 0;
	BOOL			wReload, wInitCount = FALSE;
    DWORD           dwSeekOffset, dwDistEpEof;
    LPEXEHEADER_T   lpEXEHeader;


    lpEXEHeader = (LPEXEHEADER_T)(lpbyInfectionBuffer + 256);

    // determine the location of the entry-point and re-read 0x100 bytes

    if (lpEXEHeader->exesig[0] == 0xE9)
    {
        // use offset of E9 jump to determine start of virus

        dwSeekOffset = AVDEREF_WORD(lpbyInfectionBuffer + 257) + 3;
    }
    else
    {
        wSeg = WENDIAN(lpEXEHeader->cs) + WENDIAN(lpEXEHeader->header_size);
        dwSeekOffset = (DWORD)wSeg * 16 + WENDIAN(lpEXEHeader->ip);
    }


    // Get file size

    dwDistEpEof = lpCallBack->FileSize(hFile) - dwSeekOffset;


	// If the distance from EOF to EP is not within 4600-4900 then
    // we aren't infected

    if (dwDistEpEof < 4600 || dwDistEpEof > 4900)
		return (EXTSTATUS_OK);


 	do
	{

	    if (lpCallBack->FileSeek(hFile,dwSeekOffset+wIP,SEEK_SET) == (DWORD)-1)
		    return(EXTSTATUS_FILE_ERROR);

	    if ((lpCallBack->FileRead(hFile, byBuffer, VICE_BUFFER_LEN)) == -1)
    		return(EXTSTATUS_FILE_ERROR);

	
	    wIndex = 0;
		wReload = FALSE;

        while (wIndex < VICE_BUFFER_LEN-3 && !wReload)
        {

	        byOpcode = byBuffer[wIndex];
			if ((gwVICEInstrProfile[byOpcode >> 4] &
				(1 << (byOpcode & 0x0F))) == 0)
        	    return(EXTSTATUS_OK);


            switch (byBuffer[wIndex])
            {
				case 0x74:
				case 0x75:
				case 0x79:
				case 0xe0:
				case 0xe2:
					if (wJumps > 5 && wInitCount)
                    {
                        *lpwVID = VID_VICE;
						return(EXTSTATUS_VIRUS_FOUND);
                    }

					return(EXTSTATUS_OK);
					break;

				case 0x05:
				case 0x2D:
				case 0x83:
				case 0xB8:
				case 0xB9:
				case 0xBA:
				case 0xBB:
                    if (AVDEREF_WORD(byBuffer+wIndex+1) == 0x0f70 ||
                        AVDEREF_WORD(byBuffer+wIndex+1) == 0xf090 )
						wInitCount = TRUE;
					break;


				case 0x81:
				case 0x8b:
				case 0x8e:
                    if (AVDEREF_WORD(byBuffer+wIndex+2) == 0x0f70 ||
                        AVDEREF_WORD(byBuffer+wIndex+2) == 0xf090 )
						wInitCount = TRUE;
					break;


				case 0xEB:
					byOff = byBuffer[wIndex+1];
					wIP += (WORD)(signed short)(signed char)byOff + 2;
					wJumps++;
					wReload = TRUE;
					break;

			}

			if (!wReload)
			{
				wOpLen = OpcodeLength(byBuffer+wIndex);
		        wIndex += wOpLen;
				wIP += wOpLen;
			}

		}

		if (!wReload)
			return(EXTSTATUS_OK);

    }
	while (wJumps < 25);


    return(EXTSTATUS_OK);
}


WORD gwFreddyInstrProfile[] =
{
    0x40C0,
    0xC000,
    0x0000,
    0x0272,
    0x2EEC,
    0x0C09,
    0x0000,
	0x0038,
	0x4F81,
	0x0001,
	0x3C00,
	0xC2CC,
	0x0000,
	0x0003,
	0x0A04,
	0x1F00,
};

#define FREDDY_BUFFER_LEN     0x100

// EXTScanFileFreddy arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 64 bytes from TOF of target program.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                        EXTSTATUS_VIRUS_FOUND         if virus was found

EXTSTATUS EXTScanFileFreddy(LPCALLBACKREV1 lpCallBack,
                            HFILE  hFile,
                            LPBYTE lpbyInfectionBuffer,
                            LPWORD lpwVID)
{

    BYTE            byOpcode, byOff,
     		        byBuffer[FREDDY_BUFFER_LEN];
    WORD            wIndex, wSeg, wIP = 0, wOpLen,
	        		wInstructions = 0;
	BOOL			wReload,
                    wInitCount = FALSE,
                    wInitIndexReg = FALSE,
                    wCopyIndexReg = FALSE,
                    wGetEncByte = FALSE,
                    wPutDecByte = FALSE,
                    wDecrypt = FALSE,
                    wFredProfile = FALSE;
    DWORD           dwSeekOffset, dwDistEpEof;
    LPEXEHEADER_T   lpEXEHeader;


    lpEXEHeader = (LPEXEHEADER_T)(lpbyInfectionBuffer + 256);

    // determine the location of the entry-point and re-read 0x100 bytes

    if (lpEXEHeader->exesig[0] == 0xE9)
    {
        // use offset of E9 jump to determine start of virus

        dwSeekOffset = AVDEREF_WORD(lpbyInfectionBuffer + 257) + 3;
    }
    else
    {
        wSeg = WENDIAN(lpEXEHeader->cs) + WENDIAN(lpEXEHeader->header_size);
        dwSeekOffset = (DWORD)wSeg * 16 + WENDIAN(lpEXEHeader->ip);
    }


    // Get file size

    dwDistEpEof = lpCallBack->FileSize(hFile) - dwSeekOffset;


	// If the distance from EOF to EP is not > 2300
    // we aren't infected

    if (dwDistEpEof < 2300)
		return (EXTSTATUS_OK);


 	do
	{

	    if (lpCallBack->FileSeek(hFile,dwSeekOffset+wIP,SEEK_SET) == (DWORD)-1)
		    return(EXTSTATUS_FILE_ERROR);

	    if ((lpCallBack->FileRead(hFile, byBuffer, VICE_BUFFER_LEN)) == -1)
    		return(EXTSTATUS_FILE_ERROR);

	
	    wIndex = 0;
		wReload = FALSE;

        while (wIndex < FREDDY_BUFFER_LEN-3 && !wReload)
        {

	        byOpcode = byBuffer[wIndex];
			if ((gwFreddyInstrProfile[byOpcode >> 4] &
				(1 << (byOpcode & 0x0F))) == 0)
        	    return(EXTSTATUS_OK);


            switch (byBuffer[wIndex])
            {
				case 0x49:
                    if (byBuffer[wIndex+1] == 0x75 && wFredProfile)
                    {
                        *lpwVID = VID_FREDDY;
						return(EXTSTATUS_VIRUS_FOUND);
                    }

					return(EXTSTATUS_OK);
					break;

				case 0xe2:
					if (wFredProfile)
                    {
                        *lpwVID = VID_FREDDY;
						return(EXTSTATUS_VIRUS_FOUND);
                    }

					return(EXTSTATUS_OK);
					break;

                case 0x34:
                case 0x35:
                    wDecrypt = TRUE;

                case 0xAC:
                case 0xAD:
                    wGetEncByte = TRUE;
                    break;

                case 0x8A:
                case 0x8B:
                    if (byBuffer[wIndex+1] == 0x04 ||
                        byBuffer[wIndex+1] == 0x05 )
                        wGetEncByte = TRUE;
                    break;

                case 0xAA:
                case 0xAB:
                    wPutDecByte = TRUE;
                    break;

                case 0x88:
                    if (byBuffer[wIndex+1] == 0x04 ||
                        byBuffer[wIndex+1] == 0x05 )
                        wPutDecByte = TRUE;
                    break;

				case 0xB9:
                    if (AVDEREF_WORD(byBuffer+wIndex+1) == 0x08df ||
                        AVDEREF_WORD(byBuffer+wIndex+1) == 0x046f )
						wInitCount = TRUE;
					break;

                case 0xBF:
                case 0xBE:
                    wInitIndexReg = TRUE;
                    break;

                case 0x89:
                    if (byBuffer[wIndex+1] == 0xfe ||
                        byBuffer[wIndex+1] == 0xf7 )
                        wCopyIndexReg = TRUE;
                    if (byBuffer[wIndex+1] == 0x04 ||
                        byBuffer[wIndex+1] == 0x05 )
                        wPutDecByte = TRUE;
                    break;
 
                case 0x73:
				case 0xEB:
					byOff = byBuffer[wIndex+1];
					wIP += (WORD)(signed short)(signed char)byOff + 2;
					wReload = TRUE;
					break;

			}

            wInstructions++;

			if ( wInitCount && wInitIndexReg && wCopyIndexReg &&
                 wGetEncByte && wPutDecByte && wDecrypt)
                wFredProfile = TRUE;

			if (!wReload)
			{
				wOpLen = OpcodeLength(byBuffer+wIndex);
		        wIndex += wOpLen;
				wIP += wOpLen;
			}

		}

		if (!wReload)
			return(EXTSTATUS_OK);

    }
	while (wInstructions < 2048);


    return(EXTSTATUS_OK);
}


WORD gwMadInstrProfile[] =
{
    0x30C8, // 0001 0011 0000 1100 | 0011 0000 1100 1000
    0xC021, // 1000 0100 0000 0011 | 1100 0000 0010 0001
    0x4050, // 0000 1010 0000 0010 | 0100 0000 0101 0000
    0x6060, // 0000 0110 0000 0110 | 0110 0000 0110 0000
    0xEDEF, // 1111 0111 1011 0111 | 1110 1101 1110 1111
    0xEFFF, // 1111 1111 1111 0111 | 1110 1111 1111 1111
    0x0000, // 0000 0000 0000 0000 | 0000 0000 0000 0000
    0x00FF, // 1111 1111 0000 0000 | 0000 0000 1111 1111
    0x4C83, // 1100 0001 0011 0010 | 0100 1100 1000 0011
    0x0401, // 1000 0000 0010 0000 | 0000 0100 0000 0001
    0x0004, // 0010 0000 0000 0000 | 0000 0000 0000 0100
    0xEF01, // 1000 0000 1111 0111 | 1110 1111 0000 0001
    0xB8C8, // 0001 0011 0001 1101 | 1011 1000 1100 1000
    0x008A, // 0101 0001 0000 0000 | 0000 0000 1000 1010
    0x0B1C, // 0011 1000 1101 0000 | 0000 1011 0001 1100
    0x8002  // 0100 0000 0000 0001 | 1000 0000 0000 0010
};

#define MAD_BUFFER_LEN     0x100

// EXTScanFileMad arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 64 bytes from TOF of target program.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                        EXTSTATUS_VIRUS_FOUND         if virus was found

EXTSTATUS EXTScanFileMad(LPCALLBACKREV1 lpCallBack,
                         HFILE  hFile,
                         LPBYTE lpbyInfectionBuffer,
                         LPWORD lpwVID)
{

    BYTE            byOpcode, byOff,
                    byBuffer[MAD_BUFFER_LEN];
    WORD            wIndex, wSeg, wIP = 0, wOpLen,
                    wInstructions = 0;
    BOOL            wReload,
                    wInitIndexReg = FALSE,
                    wXORIndexReg = FALSE,
                    wDecrypt1 = FALSE,
                    wDecrypt2 = FALSE,
                    wIncIndexReg = FALSE,
                    wMadProfile = FALSE;
    DWORD           dwSeekOffset, dwDistEpEof;
    LPEXEHEADER_T   lpEXEHeader;



    lpEXEHeader = (LPEXEHEADER_T)(lpbyInfectionBuffer + 256);

    // determine the location of the entry-point and re-read 0x100 bytes

    if (lpEXEHeader->exesig[0] == 0xE9)
    {
        // use offset of E9 jump to determine start of virus

        dwSeekOffset = AVDEREF_WORD(lpbyInfectionBuffer + 257) + 3;

        // Mad only infects COM that start with an E9, so we need to
        // follow that jump to get to the jump to Mad's code.

        if (lpCallBack->FileSeek(hFile,dwSeekOffset+wIP,SEEK_SET) == (DWORD)-1)
            return(EXTSTATUS_FILE_ERROR);

        if ((lpCallBack->FileRead(hFile, byBuffer, MAD_BUFFER_LEN)) == -1)
            return(EXTSTATUS_FILE_ERROR);

        // If we don't see another jump then we aren't infected

        if (byBuffer[0] != 0xE9)
            return (EXTSTATUS_OK);

        // Get the offset of the virus code

        dwSeekOffset += AVDEREF_WORD(byBuffer + 1) + 3;

    }
    else
    {
        wSeg = WENDIAN(lpEXEHeader->cs) + WENDIAN(lpEXEHeader->header_size);
        dwSeekOffset = (DWORD)wSeg * 16 + WENDIAN(lpEXEHeader->ip);
    }


    // Get file size

    dwDistEpEof = lpCallBack->FileSize(hFile) - dwSeekOffset;


	// If the distance from EOF to EP is not 5054
    // we aren't infected

    if (dwDistEpEof != 5054)
		return (EXTSTATUS_OK);


 	do
	{

	    if (lpCallBack->FileSeek(hFile,dwSeekOffset+wIP,SEEK_SET) == (DWORD)-1)
		    return(EXTSTATUS_FILE_ERROR);

	    if ((lpCallBack->FileRead(hFile, byBuffer, MAD_BUFFER_LEN)) == -1)
    		return(EXTSTATUS_FILE_ERROR);

	
	    wIndex = 0;
		wReload = FALSE;

        while (wIndex < MAD_BUFFER_LEN-3 && !wReload)
        {

	        byOpcode = byBuffer[wIndex];
			if ((gwMadInstrProfile[byOpcode >> 4] &
				(1 << (byOpcode & 0x0F))) == 0)
        	    return(EXTSTATUS_OK);


            switch (byBuffer[wIndex])
            {
				case 0x81:
                    if ((byBuffer[wIndex+1] == 0xfb  ||
                         byBuffer[wIndex+1] == 0xfe  ||
                         byBuffer[wIndex+1] == 0xff) &&
                         byBuffer[wIndex+4] == 0x75  &&
                         byBuffer[wIndex+5] != 0x00  )
                    {
                        if (!wMadProfile)
                            return(EXTSTATUS_OK);

                        *lpwVID = VID_MAD5054;
						return(EXTSTATUS_VIRUS_FOUND);
                        break;
                    }
 

                    if (byBuffer[wIndex+1] == 0xf3 ||
                        byBuffer[wIndex+1] == 0xf6 ||
                        byBuffer[wIndex+1] == 0xf7 )
                    {
                        wXORIndexReg = TRUE;
                        break;
                    }

                    break;

                case 0xe2:
                    if (!wMadProfile)
                        return(EXTSTATUS_OK);

                    *lpwVID = VID_MAD5054;
                    return(EXTSTATUS_VIRUS_FOUND);
                    break;

                case 0xBE:
                case 0xBF:
                case 0xBB:
                    wInitIndexReg = TRUE;
                    break;


                case 0x43:
                case 0x46:
                case 0x47:
                    wIncIndexReg = TRUE;
                    break;


                case 0x80:
                    if (byBuffer[wIndex+1] == 0x04 ||
                        byBuffer[wIndex+1] == 0x05 ||
                        byBuffer[wIndex+1] == 0x07 ||
                        byBuffer[wIndex+1] == 0x34 ||
                        byBuffer[wIndex+1] == 0x35 ||
                        byBuffer[wIndex+1] == 0x37 )
                    {
                        if (wDecrypt1)
                            wDecrypt2 = TRUE;
                        else
                            wDecrypt1 = TRUE;
                    }

                    break;


                case 0xE9:
                    byOff = byBuffer[wIndex+1];
                    wIP += (WORD)(signed short)(signed char)byOff + 3;
                    wReload = TRUE;
                    break;

            }

            wInstructions++;

            if ( wInitIndexReg && wXORIndexReg &&
                wDecrypt1 && wDecrypt2 && wIncIndexReg)
                wMadProfile = TRUE;

            if (!wReload)
            {
                wOpLen = OpcodeLength(byBuffer+wIndex);
                wIndex += wOpLen;
                wIP += wOpLen;
            }

	    }

	    if (!wReload)
            return(EXTSTATUS_OK);

    }
    while (wInstructions < 0x200);


    return(EXTSTATUS_OK);
}


WORD gwCryptorInstrProfile[] =
{
  0x3CFE,   // 0111 1111 0011 1100
  0xFC3C,   // 0011 1100 0011 1111
  0xFEFC,   // 0011 1111 0111 1111
  0xF7FE,   // 0111 1111 1110 1111
  0xEFEF,   // 1111 0111 1111 0111
  0xE808,   // 0001 0000 0001 0111
  0x0000,   // 0000 0000 0000 0000
  0x0030,   // 0000 1100 0000 0000
  0x6F3B,   // 1101 1100 1111 0110
  0x83EF,   // 1111 0111 1100 0001
  0xF3C0,   // 0000 0011 1100 1111
  0xEF11,   // 1000 1000 1111 0111
  0xA000,   // 0000 0000 0000 0101
  0x008F,   // 1111 0001 0000 0000
  0x0304,   // 0010 0000 1100 0000
  0xFBE0    // 0000 0111 1101 1111
};

#define CRYPTOR_BUFFER_LEN     0x200

// EXTScanFileCryptor arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 64 bytes from TOF of target program.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                        EXTSTATUS_VIRUS_FOUND         if virus was found

EXTSTATUS EXTScanFileCryptor(LPCALLBACKREV1 lpCallBack,
                             HFILE  hFile,
                             LPBYTE lpbyInfectionBuffer,
                             LPWORD lpwVID)
{

    BYTE            byOpcode, byOff,
                    byBuffer[CRYPTOR_BUFFER_LEN];
    WORD            wIndex, wIP = 0, wOpLen,
                    wInstructions = 0;
    BOOL            wReload,
                    wCallLoop = FALSE,
                    wPopAddr = FALSE,
                    wMustBePop = FALSE,
                    wCryptorProfile = FALSE;
    DWORD           dwSeekOffset;
    LPEXEHEADER_T   lpEXEHeader;



    lpEXEHeader = (LPEXEHEADER_T)(lpbyInfectionBuffer + 256);

    // determine the location of the entry-point and re-read 0x100 bytes

    if (lpEXEHeader->exesig[0] == 0xE9)
    {
        // use offset of E9 jump to determine start of virus

        dwSeekOffset = AVDEREF_WORD(lpbyInfectionBuffer + 257) + 3;
    }
    else
    {
        // Mad doesn't infect EXE's although this code should never
        // be executed since we check for this in virscan
		return (EXTSTATUS_OK);
    }


 	do
	{

	    if (lpCallBack->FileSeek(hFile,dwSeekOffset+wIP,SEEK_SET) == (DWORD)-1)
		    return(EXTSTATUS_FILE_ERROR);

	    if ((lpCallBack->FileRead(hFile, byBuffer, CRYPTOR_BUFFER_LEN)) == -1)
    		return(EXTSTATUS_FILE_ERROR);

	
	    wIndex = 0;
		wReload = FALSE;

        while (wIndex < CRYPTOR_BUFFER_LEN-3 && !wReload)
        {

	        byOpcode = byBuffer[wIndex];
			if ((gwCryptorInstrProfile[byOpcode >> 4] &
				(1 << (byOpcode & 0x0F))) == 0)
        	    return(EXTSTATUS_OK);


            switch (byBuffer[wIndex])
            {
				case 0x75:
                case 0xE2:
                    if (!wCryptorProfile || wMustBePop)
                        return(EXTSTATUS_OK);

                    *lpwVID = VID_CRYPTOR2169;
                    return(EXTSTATUS_VIRUS_FOUND);

                    break;

                case 0x5B:
                case 0x5D:
                case 0x5E:
                case 0x5F:
                    wPopAddr = TRUE;
                    wMustBePop = FALSE;

                    break;

                case 0xE8:
                    if (byBuffer[wIndex+2])
                        return(EXTSTATUS_OK);

                    byOff = byBuffer[wIndex+1];
                    wIP += (WORD)(signed short)(signed char)byOff + 3;
                    wReload = TRUE;
                    wMustBePop = TRUE;
                    wCallLoop = TRUE;
                    break;

                default:
                    if (wMustBePop)
                        return(EXTSTATUS_OK);

                    break;

            }

            wInstructions++;

            if ( wCallLoop && wPopAddr)
                wCryptorProfile = TRUE;

            if (!wReload)
            {
                wOpLen = OpcodeLength(byBuffer+wIndex);
                wIndex += wOpLen;
                wIP += wOpLen;
            }

	    }

	    if (!wReload)
            return(EXTSTATUS_OK);

    }
    while (wInstructions < 0x400);


    return(EXTSTATUS_OK);
}

// EXTScanFileCryptor2582 arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 4K fstart buffers containing TOF, ENTRY, etc.
//                         +0   256 fstart bytes of target program.
//                         +256 64 bytes from TOF of target program.
//                         +512 256 unused
//                         +768 2 Number of external defs called.
//                         +770 2 ID of first external called.
//                         +772 ? ID of additional externals called.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                        EXTSTATUS_VIRUS_FOUND         if virus was found


EXTSTATUS EXTScanFileCryptor2(LPCALLBACKREV1 lpCallBack,
                              HFILE  hFile,
                              LPBYTE lpbyInfectionBuffer,
                              LPWORD lpwVID)
{
    WORD            wReturn = EXTSTATUS_OK;
    WORD            i,j,k,l, wCnt;
    BOOL            bCallPop    = FALSE,
                    bPushPush   = FALSE,
                    bPopPop     = FALSE,
                    bLoopCntr   = FALSE;
    BYTE            byOff, byOP, byBuffer[CRYPTOR_BUFFER_LEN];
    WORD            byPushReg1, byPushReg2;
    DWORD           dwSeekOffset;
    LPEXEHEADER_T   lpEXEHeader;

    BYTE    byPush[] = { 0x50, 0x51, 0x52, 0x53, 0x55, 0x56, 0x57 };
    BYTE    byPop[]  = { 0x58, 0x59, 0x5A, 0x5B, 0x5D, 0x5E, 0x5F };


    lpEXEHeader = (LPEXEHEADER_T)(lpbyInfectionBuffer + 256);

    // determine the location of the entry-point and re-read 0x100 bytes

    if (lpEXEHeader->exesig[0] == 0xE9)
    {
        // use offset of E9 jump to determine start of virus

        dwSeekOffset = AVDEREF_WORD(lpbyInfectionBuffer + 257) + 3;
    }
    else
    {
        // Mad doesn't infect EXE's although this code should never
        // be executed since we check for this in virscan
		return (EXTSTATUS_OK);
    }


    if (lpCallBack->FileSeek(hFile,dwSeekOffset,SEEK_SET) == (DWORD)-1)
        return(EXTSTATUS_FILE_ERROR);

    if ((lpCallBack->FileRead(hFile, byBuffer, CRYPTOR_BUFFER_LEN)) == -1)
        return(EXTSTATUS_FILE_ERROR);



    // 1) Look for initialization of the loop counter
    //    MOV rX, 050C
    //    LEA rX, [050C]

    // 2) Look for a CALL shorter than 0x10 bytes away
    //    that lands at a pop to get the address

    // 3) Look for a CALL to a bogus subroutine that is
    //    flanked by PUSH and POPs to save the registers
    //    PUSH rX1
    //    PUSH rX2
    //    ; some code
    //    POP rX2
    //    POP rX1
    //
    //    The a little further down we look for the same
    //    thing, but with the order switched
    //    PUSH rX2
    //    PUSH rX1
    //    ; some code
    //    POP rX1
    //    POP rX2


    // 4) Look for loop control
    //    A LOOP or JNZ that lands at our previous
    //    PUSH PUSH combo


//    _asm int 3

    for (i = 0; i < CRYPTOR_BUFFER_LEN-1 ; i++)
    {

        // Check for short E8 call

        if (byBuffer[i] == 0xe8 && byBuffer[i+2] == 0x00)
        {
            byOff = byBuffer[i+1];
            byOP = byBuffer[i+byOff+3];
            if (byOP == 0x5B || byOP == 0x5F || byOP == 0x5E || byOP == 0x5D)
            {

                bCallPop = TRUE;

                if (bLoopCntr)
                {
                    i += byOff + 4;
                    break;
                }
            }
        }

        // Check for loop counter initialization.
        // MOV rX, 050C

        if (byBuffer[i] == 0xBE || byBuffer[i] == 0xBF ||
            byBuffer[i] == 0xB8 || byBuffer[i] == 0xB9 ||
            byBuffer[i] == 0xBB || byBuffer[i] == 0xBD ||
            byBuffer[i] == 0xBA )
        {
 
            wCnt = AVDEREF_WORD((LPBYTE)(byBuffer+i+1));
            if (wCnt == 0x050C)
		    {
                bLoopCntr = TRUE;
                if (bCallPop)
                    break;
            }
        }

        // Check for loop counter initialization.
        // LEA rX, [050C]

        if (byBuffer[i] == 0x8D)
        {
            if (byBuffer[i+1] == 0x2E || byBuffer[i+1] == 0x0E ||
                byBuffer[i+1] == 0x16 || byBuffer[i+1] == 0x1E ||
                byBuffer[i+1] == 0x06 || byBuffer[i+1] == 0x3E ||
                byBuffer[i+1] == 0x36 )
            {
 
                wCnt = AVDEREF_WORD((LPBYTE)(byBuffer+i+2));
                if (wCnt == 0x050C)
                {
                    bLoopCntr = TRUE;
                    if (bCallPop)
                        break;
                }
            }
        }
    }


    if (!(bCallPop && bLoopCntr))
        return (wReturn);


    for (j = i ; i < j + 35 ; i++)
    {
        // Look for PUSH PUSH

        for (k = 0 ; k < 7 ; k++)
        {
            if(byBuffer[i] == byPush[k])
            {
                for (l = 0; l < 7; l++)
                    if (byBuffer[i+1] == byPush[l])
                    {
                        byPushReg1 = k;
                        byPushReg2 = l;
                        bPushPush = TRUE;
                        i += 2;
                        break;
                    }
            }

            if (bPushPush)
                break;
        }

        if (bPushPush)
            break;

    }


    if (!bPushPush)
        return (wReturn);


    for (j = i ; i < j + 20 ; i++)
    {
        // Look for POP POP

        if(byBuffer[i] == byPop[byPushReg2] &&
           byBuffer[i+1] == byPop[byPushReg1] )
        {
            bPopPop = TRUE;
            i += 2;
            break;
        }
    }

    if (!bPopPop)
        return (wReturn);


    bPushPush = bPopPop = FALSE;

    for (j = i ; i < j + 50 ; i++)
    {
        // Look for PUSH PUSH

        if((byBuffer[i] == byPush[byPushReg2]    &&
            byBuffer[i+1] == byPush[byPushReg1]) ||
           (byBuffer[i] == byPush[byPushReg1]    &&
            byBuffer[i+1] == byPush[byPushReg2]) )
        {
            bPushPush = TRUE;
            i += 2;
            break;
        }
    }

    if (!bPushPush)
        return (wReturn);


    for (j = i ; i < j + 30 ; i++)
    {
        // Look for POP POP

        if((byBuffer[i] == byPop[byPushReg1]    &&
            byBuffer[i+1] == byPop[byPushReg2]) ||
           (byBuffer[i] == byPop[byPushReg2]    &&
            byBuffer[i+1] == byPop[byPushReg1]) )
        {
            bPopPop = TRUE;
            i += 2;
            break;
        }
    }

    if (!bPopPop)
        return (wReturn);
 
    *lpwVID = VID_CRYPTOR2582;
    return(EXTSTATUS_VIRUS_FOUND);

}

#define CRYPTOR4_BUFFER_LEN     0x400

// EXTScanFileCryptor4161 arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 4K fstart buffers containing TOF, ENTRY, etc.
//                         +0   256 fstart bytes of target program.
//                         +256 64 bytes from TOF of target program.
//                         +512 256 unused
//                         +768 2 Number of external defs called.
//                         +770 2 ID of first external called.
//                         +772 ? ID of additional externals called.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                        EXTSTATUS_VIRUS_FOUND         if virus was found


EXTSTATUS EXTScanFileCryptor4(LPCALLBACKREV1 lpCallBack,
                              HFILE  hFile,
                              LPBYTE lpbyInfectionBuffer,
                              LPWORD lpwVID)
{
    WORD            wReturn = EXTSTATUS_OK;
    WORD            i,j,k,l, wCnt;
    BOOL            bCallPop    = FALSE,
                    bPushPush   = FALSE,
                    bPopPop     = FALSE,
                    bLoopCntr   = FALSE;
    BYTE            byOP, byBuffer[CRYPTOR4_BUFFER_LEN];
    WORD            byPushReg1, byPushReg2;
    DWORD           dwSeekOffset;
    LPEXEHEADER_T   lpEXEHeader;

    BYTE    byPush[] = { 0x50, 0x51, 0x52, 0x53, 0x55, 0x56, 0x57 };
    BYTE    byPop[]  = { 0x58, 0x59, 0x5A, 0x5B, 0x5D, 0x5E, 0x5F };


    lpEXEHeader = (LPEXEHEADER_T)(lpbyInfectionBuffer + 256);

    // determine the location of the entry-point and re-read 0x100 bytes

    if (lpEXEHeader->exesig[0] == 0xE9)
    {
        // use offset of E9 jump to determine start of virus

        dwSeekOffset = AVDEREF_WORD(lpbyInfectionBuffer + 257) + 3;
    }
    else
    {
        // Cryptor doesn't infect EXE's although this code should never
        // be executed since we check for this in virscan
		return (EXTSTATUS_OK);
    }


    if (lpCallBack->FileSeek(hFile,dwSeekOffset,SEEK_SET) == (DWORD)-1)
        return(EXTSTATUS_FILE_ERROR);

    if ((lpCallBack->FileRead(hFile, byBuffer, CRYPTOR4_BUFFER_LEN)) == -1)
        return(EXTSTATUS_FILE_ERROR);



    // 1) Look for initialization of the loop counter
    //    MOV rX, 7d5-821
    //    LEA rX, [7d5-821]

    // 2) Look for a CALL followd by a pop

    // 3) Look for a CALL to a bogus subroutine that is
    //    flanked by PUSH and POPs to save the registers
    //    PUSH rX1
    //    PUSH rX2
    //    ; some code
    //    POP rX2
    //    POP rX1
    //

    // 4) Look for loop control
    //    A LOOP or JNZ that lands at our previous
    //    PUSH PUSH combo


    // _asm int 3

    for (i = 0; i < CRYPTOR4_BUFFER_LEN-1 ; i++)
    {

        if (byBuffer[i] == 0xe8)
        {
            byOP = byBuffer[i+3];
            if (byOP == 0x5B || byOP == 0x5F || byOP == 0x5E ||
                byOP == 0x5D || byOP == 0x55 )
            {

                bCallPop = TRUE;

                if (bLoopCntr)
                    break;
            }
        }

        // Check for loop counter initialization.
        // MOV rX, 050C

        if (byBuffer[i] == 0xBE || byBuffer[i] == 0xBF ||
            byBuffer[i] == 0xB8 || byBuffer[i] == 0xB9 ||
            byBuffer[i] == 0xBB || byBuffer[i] == 0xBD ||
            byBuffer[i] == 0xBA )
        {
 
            wCnt = AVDEREF_WORD((LPBYTE)(byBuffer+i+1));
            if (wCnt > 0x0760 && wCnt < 0x0860)
		    {
                bLoopCntr = TRUE;
                if (bCallPop)
                    break;
            }
        }

        // Check for loop counter initialization.
        // LEA rX, [050C]

        if (byBuffer[i] == 0x8D)
        {
            if (byBuffer[i+1] == 0x2E || byBuffer[i+1] == 0x0E ||
                byBuffer[i+1] == 0x16 || byBuffer[i+1] == 0x1E ||
                byBuffer[i+1] == 0x06 || byBuffer[i+1] == 0x3E ||
                byBuffer[i+1] == 0x36 )
            {
 
                wCnt = AVDEREF_WORD((LPBYTE)(byBuffer+i+2));
                if (wCnt > 0x0760 && wCnt < 0x0860)
	            {
                    bLoopCntr = TRUE;
                    if (bCallPop)
                        break;
                }
            }
        }
    }


    if (!(bCallPop && bLoopCntr))
        return (wReturn);


    for (j = i ; i < j + 100 ; i++)
    {
        // Look for PUSH PUSH

        for (k = 0 ; k < 7 ; k++)
        {
            if(byBuffer[i] == byPush[k])
            {
                for (l = 0; l < 7; l++)
                    if (byBuffer[i+1] == byPush[l])
                    {
                        byPushReg1 = k;
                        byPushReg2 = l;
                        bPushPush = TRUE;
                        i += 2;
                        break;
                    }
            }

            if (bPushPush)
                break;
        }

        if (bPushPush)
            break;

    }


    if (!bPushPush)
        return (wReturn);


    for (j = i ; i < j + 50 ; i++)
    {
        // Look for POP POP

        if(byBuffer[i] == byPop[byPushReg2] &&
           byBuffer[i+1] == byPop[byPushReg1] )
        {
            bPopPop = TRUE;
            i += 2;
            break;
        }
    }

    if (!bPopPop)
        return (wReturn);


    for (j = i; i < j + 100; i++)
    {
        // Look for loop control

        if (byBuffer[i] == 0xe2 || byBuffer[i] == 0x75)
        {
 
            *lpwVID = VID_CRYPTOR4161;
            return(EXTSTATUS_VIRUS_FOUND);
        }
    }

    return (wReturn);

}


//Converted from PAM entry of Digital.3547
WORD gwDigi3547InstrProfile[] =
{
0x40EC, // 0011 0111 0000 0010
0xC040, // 0000 0010 0000 0011
0x5C4C, // 0011 0010 0011 1010
0x484E, // 0111 0010 0001 0010
0x0FEF, // 1111 0111 1111 0000
0xEF1F, // 1111 1000 1111 0111
0x0000, // 0000 0000 0000 0000
0x0030, // 0000 1100 0000 0000
0x5E8B, // 1101 0001 0111 1010
0x004F, // 1111 0010 0000 0000
0x0002, // 0100 0000 0000 0000
0xEF1B, // 1101 1000 1111 0111
0xA000, // 0000 0000 0000 0101
0x000A, // 0101 0000 0000 0000
0x0B04, // 0010 0000 1101 0000
0x9F00  // 0000 0000 1111 1001
};

#define DIGI3547_BUFFER_LEN     128
#define DIGISIZE 3547
// EXTScanFileDigi3547 arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 64 bytes from TOF of target program.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                        EXTSTATUS_VIRUS_FOUND         if virus was found

EXTSTATUS EXTScanFileDigi3547(LPCALLBACKREV1 lpCallBack,
                              HFILE  hFile,
                              LPBYTE lpbyInfectionBuffer,
                              LPWORD lpwVID)
{

    BYTE            byOpcode, byOff,
                    byBuffer[DIGI3547_BUFFER_LEN];
    WORD            wIndex, wSeg = 0, wOpLen, wOff;
    BOOL            wJNZfound, wRORfound = FALSE;
    DWORD           dwSeekOffset, dwDistEpEof;
    LPEXEHEADER_T   lpEXEHeader;


    lpEXEHeader = (LPEXEHEADER_T)(lpbyInfectionBuffer + 256);

    // determine the location of the entry-point and re-read 128 bytes
    if (lpEXEHeader->exesig[0] == 0xE9) //COM
    {
        // use offset of E9 jump to determine start of virus
        dwSeekOffset = AVDEREF_WORD(lpbyInfectionBuffer + 257) + 3;
    }
    else //EXE
    {
        wSeg = WENDIAN(lpEXEHeader->cs) + WENDIAN(lpEXEHeader->header_size);
        dwSeekOffset = (DWORD)wSeg * 16 + WENDIAN(lpEXEHeader->ip);
    }


    // Get file size
    dwDistEpEof = lpCallBack->FileSize(hFile) - dwSeekOffset;

    // If the distance from EOF to EP is not 3547
    // the file is not infected
    if (dwDistEpEof != DIGISIZE)
        return (EXTSTATUS_OK);

    if (lpCallBack->FileSeek(hFile,dwSeekOffset,SEEK_SET) == (DWORD)-1)
        return(EXTSTATUS_FILE_ERROR);

    if ((lpCallBack->FileRead(hFile, byBuffer, DIGI3547_BUFFER_LEN)) == -1)
        return(EXTSTATUS_FILE_ERROR);

    wJNZfound = FALSE;
    wRORfound = FALSE;
    wIndex = 0;
    while (wIndex < DIGI3547_BUFFER_LEN-3)
     {
        byOpcode = byBuffer[wIndex];
        wOff = 0;

        //Valid Opcode?
        if ((gwDigi3547InstrProfile[byOpcode >> 4] &
            (1 << (byOpcode & 0x0F))) == 0)
           return(EXTSTATUS_OK);

        switch (byBuffer[wIndex])
         {
            case 0xd3:
              if ((byBuffer[wIndex+1] == 0x08)     // ROR WordPtr [BX+SI], CL
                  || (byBuffer[wIndex+1] == 0x09)) // ROR WordPtr [BX+DI], CL
               {
                wRORfound = TRUE;
               }
              break;
            case 0x75:       //JNZ 0xB?
             if ((wRORfound) //if ROR is already found above, virus detected
                 && ((byBuffer[wIndex+1] & 0xF0) == 0xB0))
               {
                *lpwVID = VID_DIGI3547;
                return(EXTSTATUS_VIRUS_FOUND);
               }
              break;
            case 0xE8: //near CALL before the decryption loop
                       //need special handling since it skips some junk-bytes
              //set the displacement
              wOff = ((WORD) (byBuffer[wIndex+2]) << 8)
                     + (WORD) byBuffer[wIndex+1];
              break;
            case 0xEB: //short JMP in the middle of decryption loop
              //set the displacement
              byOff = byBuffer[wIndex+1];
              wOff = (WORD)(signed short)(signed char)byOff;
              break;
            }//switch

        wOpLen = OpcodeLength(byBuffer+wIndex); //size of operation
        wIndex += (wOpLen + wOff);              //update IP
     }//while

    return(EXTSTATUS_OK);
}

// EXTScanFileTentatrick arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyWorkBuffer       : 2-4K buffer for temporary operations (STACK OK also)
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                      : EXTSTATUS_VIRUS_FOUND         if virus was found
//                        EXTSTATUS_FILE_ERROR          if file error
//
// Read notes for this in def1f.src!
//

#define TENBACKJMP  10424               // Far Jump goes this far back
#define TTTREAD     0x2c                // Number of bytes to read for det
#define TTMAXSRCH   0x12                // Max number to search for 0xb0 bytes
#define TMOVBYTE    0xb0                // Move instructions to look for
#define TTLOOP      0xe2                // Loop instruction

EXTSTATUS EXTScanFileTentatrick(LPCALLBACKREV1 lpCallBack,
                      HFILE          hFile,
                      LPBYTE         lpbyInfectionBuffer,
                      LPWORD         lpwVID)
{
    BYTE    bXOR[] = {0x2e, 0x30, 0x07};
    BYTE    i, j;
    WORD    wReturn = EXTSTATUS_OK;
    WORD    wCheck;                                 // Miscellaneous variables
    UINT    uCheck;
    DWORD   dwres;
    DWORD   dwFilePos = 0;

    //_asm    int 3                                 // Remove after debugging

    dwFilePos = GetEntryPtOffset(lpbyInfectionBuffer + HEADER_OFF);

    if ((0 == dwFilePos) || (TENBACKJMP > dwFilePos))
        return(wReturn);

    dwFilePos -= TENBACKJMP;

    dwres = FILESEEK(dwFilePos);

    if (dwres != dwFilePos)
        return(wReturn);

    uCheck = FILEREAD(lpbyInfectionBuffer, TTTREAD);

    if (TTTREAD != uCheck)
        return(EXTSTATUS_FILE_ERROR);
 
    i = j = 0;
                        // Look for three 0xb0 bytes < TTMAXSRCH bytes apart
    while ((TMOVBYTE != (lpbyInfectionBuffer[j] & 0xf0)) && (TTMAXSRCH > j))
        j++;

    if (TMOVBYTE != (lpbyInfectionBuffer[j] & 0xf0))
        return(wReturn);

    i = ++j;
    j = 0;

    while ((TMOVBYTE != (lpbyInfectionBuffer[i + j] & 0xf0)) &&
                                    (TTMAXSRCH > j) && (TTTREAD > (i + j)))
        j++;

    if (TMOVBYTE != (lpbyInfectionBuffer[i + j] & 0xf0))
        return(wReturn);

    i = ++j;
    j = 0;
 
    while ((TMOVBYTE != (lpbyInfectionBuffer[i + j] & 0xf0)) &&
                                    (TTMAXSRCH > j) && (TTTREAD > (i + j)))
        j++;

    i += j;

    if (TMOVBYTE != (lpbyInfectionBuffer[i] & 0xf0))
        return(wReturn);

    if (TTTREAD < i++)
        return(wReturn);

    wCheck = ScanString((lpbyInfectionBuffer + i), (TTTREAD - i), bXOR, 3);

    if (WERROR == wCheck)
        return(wReturn);

    i += (BYTE) (wCheck + 3);

    do
    {
        while ((TTLOOP != lpbyInfectionBuffer[i]) && (TTTREAD > i))
            i++;

        if (TTLOOP == lpbyInfectionBuffer[i++])
        {
            j = i + lpbyInfectionBuffer[i] + 1;

            if (bXOR[0] == lpbyInfectionBuffer[j])
            {
                *lpwVID = VID_TENTRK;
                return(EXTSTATUS_VIRUS_FOUND);
            }
        }
    } while (TTTREAD > i);

    return(wReturn);
}   // End EXTScanFileTentatrick


/////////////////////////
// Sailor.Pluto.3672   //
/////////////////////////
//
//  This definition also has a PAM definition that did not catch
//  all variants.  It perform a AX,3305 INT21 and AH,2D INT21
//  operation and then checks return values.  PAM would need
//  modifications to low.asm
//
//  This navex definition checks for:
//  1. Profile of opcodes
//  2. Only CD 21|16|10|20 allowed
//  3. MOV CX|DX|BP|SI|DI|BX 0E??h|07??h
//  4. OR|CMP|XOR|DEC|AND CX|DX|BP|SI|DI|BX
//     JNZ|JAE (0x7?03)
//     JMP (0xE9????)
//      or
//     OR|CMP|XOR|DEC|AND CX|DX|BP|SI|DI|BX
//     JNZ|JAE 0x7?[0xDA-0x80]
//
//  The register used for the MOV 0E??h|07??h is recorded
//  This register must be used for the OR|CMP|XOR|DEC|AND
//  operation later.
//  -ECC 8/25/1998

WORD gwSailorInstrProfile[] =
{
    0x4CEC, // 0100 1100 1110 1100 | 0011 0111 0011 0010
    0xCC0C, // 1100 1100 0000 1100 | 0011 0000 0011 0011
    0x4CCC, // 0100 1100 1100 1100 | 0011 0011 0011 0010
    0x0C0C, // 0000 1100 0000 1100 | 0011 0000 0011 0000
    0xEFEF, // 1110 1111 1110 1111 | 1111 0111 1111 0111
    0xEFFF, // 1110 1111 1111 1111 | 1111 1111 1111 0111
    0x0000, // 0000 0000 0000 0000 | 0000 0000 0000 0000
    0x00FC, // 0000 0000 1111 1100 | 0011 1111 0000 0000
    0x7F0F, // 0111 1111 0000 1111 | 1111 0000 1111 1110
    0x0100, // 0000 0001 0000 0000 | 0000 0000 1000 0000
    0x0000, // 0000 0000 0000 0000 | 0000 0000 0000 0000
    0xFFFF, // 1111 1111 1111 1111 | 1111 1111 1111 1111
    0xB008, // 1011 0000 0000 1000 | 0001 0000 0000 1101
    0x000F, // 0000 0000 0000 1111 | 1111 0000 0000 0000
    0x0B04, // 0000 1011 0000 0100 | 0010 0000 1101 0000
    0x1580  // 0001 0101 1000 0000 | 0000 0001 1010 1000
};

#define SAILOR_BUFFER_LEN     0x400

#define SAILOR_CX_COUNTER   0x01
#define SAILOR_DX_COUNTER   0x02
#define SAILOR_BP_COUNTER   0x04
#define SAILOR_SI_COUNTER   0x08
#define SAILOR_DI_COUNTER   0x10
#define SAILOR_BX_COUNTER   0x20

// EXTScanFileSailor arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 64 bytes from TOF of target program.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                        EXTSTATUS_VIRUS_FOUND         if virus was found

EXTSTATUS EXTScanFileSailor(LPCALLBACKREV1 lpCallBack,
                             HFILE  hFile,
                             LPBYTE lpbyInfectionBuffer,
                             LPWORD lpwVID)
{

    BYTE            byOpcode;
    BYTE            byBuffer[SAILOR_BUFFER_LEN];
    BYTE            byValidCounter = 0, byReload=0;
    WORD            wIndex, wOpLen, wSeg, wLastOp=0, wIP=0;
    DWORD           dwSeekOffset;
    LPEXEHEADER_T   lpEXEHeader;

    lpEXEHeader = (LPEXEHEADER_T)(lpbyInfectionBuffer + 256);

    // determine the location of the entry-point and re-read 0x100 bytes

    if (lpEXEHeader->exesig[0] == 0xE9)
    {
        // use offset of E9 jump to determine start of virus
        dwSeekOffset = AVDEREF_WORD(lpbyInfectionBuffer + 257) + 3;
        *lpwVID=VID_SAILORCOM;
    }
    else
    {
        wSeg = WENDIAN(lpEXEHeader->cs) + WENDIAN(lpEXEHeader->header_size);
        dwSeekOffset = (DWORD)wSeg * 16 + WENDIAN(lpEXEHeader->ip);
        *lpwVID=VID_SAILOREXE;
    }

    do
	{

        if (lpCallBack->FileSeek(hFile,dwSeekOffset+wIP,SEEK_SET) == (DWORD)-1)
            return(EXTSTATUS_FILE_ERROR);

        if ((lpCallBack->FileRead(hFile, byBuffer, SAILOR_BUFFER_LEN)) == -1)
            return(EXTSTATUS_FILE_ERROR);


        wIndex = 0;

        while (wIndex < SAILOR_BUFFER_LEN-3)
        {

            // Opcode Profile Check
            byOpcode = byBuffer[wIndex];
            if ((gwSailorInstrProfile[byOpcode >> 4] &
                  (1 << (byOpcode & 0x0F))) == 0)
            {
                return(EXTSTATUS_OK);
            }


            switch (byBuffer[wIndex])
            {
                // Verify
                //        Cmp Operation on register
                //        7?03 JZ|JNZ 03
                //        E9???? JMP
                //           or
                //        Cmp Operation on register
                //        7?XX where XX is between 0xDA and 0x80
                case 0x77:
                case 0x76:
                case 0x75:
                case 0x74:
                    if (((byBuffer[wIndex+2] == 0xE9) &&
                         (byBuffer[wIndex+1] == 0x03)) ||
                        ((byBuffer[wIndex+1] >= 0x80) &&
                         (byBuffer[wIndex+1] <= 0xDA)))
                    {
                        // Verify Zero-flag (Cmp) operation on a register
                        // And compare register with valid counter
                        switch(byBuffer[wLastOp])
                        {
                            case 0x4F:  // DEC DI
                                if ((SAILOR_DI_COUNTER & byValidCounter)
                                    == SAILOR_DI_COUNTER)
                                {
                                    return(EXTSTATUS_VIRUS_FOUND);
                                }

                                return(EXTSTATUS_OK);
                                break;
                            case 0x4E:  // DEC SI
                                if ((SAILOR_SI_COUNTER & byValidCounter)
                                    == SAILOR_SI_COUNTER)
                                {
                                    return(EXTSTATUS_VIRUS_FOUND);
                                }

                                return(EXTSTATUS_OK);
                                break;
                            case 0x4D:  // DEC BP
                                if ((SAILOR_BP_COUNTER & byValidCounter)
                                    == SAILOR_BP_COUNTER)
                                {
                                    return(EXTSTATUS_VIRUS_FOUND);
                                }
                                return(EXTSTATUS_OK);
                                break;

                            case 0x4A:  // DEC DX
                                if ((SAILOR_DX_COUNTER & byValidCounter)
                                    == SAILOR_DX_COUNTER)
                                {
                                    return(EXTSTATUS_VIRUS_FOUND);
                                }
                                return(EXTSTATUS_OK);
                                break;
                            case 0x49:  // DEC CX
                                if ((SAILOR_CX_COUNTER & byValidCounter)
                                    == SAILOR_CX_COUNTER)
                                {
                                    return(EXTSTATUS_VIRUS_FOUND);
                                }
                                return(EXTSTATUS_OK);
                                break;
                            case 0x4B:  // DEC BX
                                if ((SAILOR_BX_COUNTER & byValidCounter)
                                    == SAILOR_BX_COUNTER)
                                {
                                    return(EXTSTATUS_VIRUS_FOUND);
                                }
                                return(EXTSTATUS_OK);
                                break;

                            case 0x21:  // AND
                            case 0x23:  // AND
                            case 0x0B:  // OR
                            case 0x09:  // OR
                            case 0x83:  // XOR OR CMP

                                // CX
                                if (((byBuffer[wLastOp + 1] == 0xC9) ||
                                    (byBuffer[wLastOp + 1] == 0xF9) ||
                                    (byBuffer[wLastOp + 1] == 0xF1)) &&
                                    ((SAILOR_CX_COUNTER & byValidCounter)
                                    == SAILOR_CX_COUNTER))
                                {
                                    return(EXTSTATUS_VIRUS_FOUND);
                                }
                                // DX
                                if (((byBuffer[wLastOp + 1] == 0xD2) ||
                                    (byBuffer[wLastOp +1] == 0xCA) ||
                                    (byBuffer[wLastOp +1] == 0xFA) ||
                                    (byBuffer[wLastOp + 1] == 0xF2)) &&
                                    ((SAILOR_DX_COUNTER & byValidCounter)
                                    == SAILOR_DX_COUNTER))
                                {
                                    return(EXTSTATUS_VIRUS_FOUND);
                                }
                                // BX
                                if (((byBuffer[wLastOp + 1] == 0xCB) ||
                                    (byBuffer[wLastOp + 1] == 0xDB) ||
                                    (byBuffer[wLastOp + 1] == 0xFB) ||
                                    (byBuffer[wLastOp + 1] == 0xF3)) &&
                                    ((SAILOR_BX_COUNTER & byValidCounter)
                                    == SAILOR_BX_COUNTER))
                                {
                                    return(EXTSTATUS_VIRUS_FOUND);
                                }

                                // BP
                                if (((byBuffer[wLastOp + 1] == 0xED) ||
                                    (byBuffer[wLastOp + 1] == 0xCD) ||
                                    (byBuffer[wLastOp + 1] == 0xFD) ||
                                    (byBuffer[wLastOp + 1] == 0xF5)) &&
                                    ((SAILOR_BP_COUNTER & byValidCounter)
                                    == SAILOR_BP_COUNTER))
                                {
                                    return(EXTSTATUS_VIRUS_FOUND);
                                }
                                // SI
                                if (((byBuffer[wLastOp + 1] == 0xF6) ||
                                    (byBuffer[wLastOp + 1] == 0xCE) ||
                                    (byBuffer[wLastOp + 1] == 0xFE)) &&
                                    ((SAILOR_SI_COUNTER & byValidCounter)
                                    == SAILOR_SI_COUNTER))
                                {
                                    return(EXTSTATUS_VIRUS_FOUND);
                                }
                                // DI
                                if (((byBuffer[wLastOp + 1] == 0xFF) ||
                                    (byBuffer[wLastOp + 1] == 0xF7) ||
                                    (byBuffer[wLastOp + 1] == 0xCF)) &&
                                    ((SAILOR_DI_COUNTER & byValidCounter)
                                    == SAILOR_DI_COUNTER))
                                {
                                    return(EXTSTATUS_VIRUS_FOUND);
                                }

                                // There wasn't a cmp (zero-flag) operation
                                // on the right register before the C-Jump
                                return(EXTSTATUS_OK);
                                break;

                            default:
                                // There wasn't a cmp (zero-flag) operation
                                // before the C-Jump
                                return(EXTSTATUS_OK);
                                break;
                        }
                        // This didn't have the right operations before
                        // and/or after the C-Jump so keep looking
                    }
                    // This didn't have the right operations before
                    // and/or after the C-Jump so keep looking
                    break;

                // MOV operations
                // Check which register is being MOV'd and what
                // the value is.  If 0E or 07 with the proper
                // register, set the bit in byValidCounter
                case 0xB9:                                  // MOV CX
                    if ((byBuffer[wIndex+2] == 0x0E) ||     // MOV 0E??
                        (byBuffer[wIndex+2] == 0x07))       // MOV 07??
                        {
                            // Set CX as valid counter
                            byValidCounter = byValidCounter | SAILOR_CX_COUNTER;
                        }
                    break;
                case 0xBA:                                  // MOV DX
                    if ((byBuffer[wIndex+2] == 0x0E) ||     // MOV 0E??
                        (byBuffer[wIndex+2] == 0x07))       // MOV 07??
                        {
                            // Set DX as valid counter
                            byValidCounter = byValidCounter | SAILOR_DX_COUNTER;

                        }
                    break;

                case 0xBB:                                  // MOV DX
                    if ((byBuffer[wIndex+2] == 0x0E) ||     // MOV 0E??
                        (byBuffer[wIndex+2] == 0x07))       // MOV 07??
                        {
                            // Set BX as valid counter
                            byValidCounter = byValidCounter | SAILOR_BX_COUNTER;
                        }
                    break;

                case 0xBD:                                  // MOV BP
                    if ((byBuffer[wIndex+2] == 0x0E) ||     // MOV 0E??
                        (byBuffer[wIndex+2] == 0x07))       // MOV 07??
                        {
                            // Set BP as valid counter
                            byValidCounter = byValidCounter | SAILOR_BP_COUNTER;
                        }
                    break;

                case 0xBE:                                  // MOV SI
                    if ((byBuffer[wIndex+2] == 0x0E) ||     // MOV 0E??
                        (byBuffer[wIndex+2] == 0x07))       // MOV 07??
                        {
                            // Set SI as valid counter
                            byValidCounter = byValidCounter | SAILOR_SI_COUNTER;
                        }
                    break;

                case 0xBF:                                  // MOV DI
                    if ((byBuffer[wIndex+2] == 0x0E) ||     // MOV 0E??
                        (byBuffer[wIndex+2] == 0x07))       // MOV 07??
                        {
                            // Set DI as valid counter
                            byValidCounter = byValidCounter | SAILOR_DI_COUNTER;
                        }
                    break;

                // Check Interrupts
                // Check to make sure it is only 21|16|10|20
                // CD20 means quit.  We need to allow this
                // because it is in the code buffer.
                // If we followed the C-Jumps we'd never hit it, but
                // we aren't following the C-Jumps because we don't
                // know when to and when not to
                case 0xCD:
                    if ((byBuffer[wIndex+1] != 0x21) &&
                        (byBuffer[wIndex+1] != 0x16) &&
                        (byBuffer[wIndex+1] != 0x20) &&
                        (byBuffer[wIndex+1] != 0x10))
                    {
                        return(EXTSTATUS_OK);
                    }
                    break;

                default:
                    // Not a special opcode, keep going
                    break;

            }
                // Figure out what opcode we had and
                // the length of its parameters.  Increment
                // so we look at the next opcode.  Save the
                // old one.
                wOpLen = OpcodeLength(byBuffer+wIndex);
                wLastOp = wIndex;
                wIndex += wOpLen;
                wIP = wLastOp;
        }
        byReload++;
        wLastOp = 0;
        // we finished with our buffer and found nothing
        // increment our reload count
    }
    while (byValidCounter != 0 && byReload < 2);
    // keep looking for two buffers worth

    return(EXTSTATUS_OK);
}
// End EXTScanFileSailor


/////////
// TMC.B ZOO for VTC WildList
/////////
// There are many variants of TMC  This should take care of 
// TMC.B which is on the VTC Wildlist and needs to be identified
// by name.  The strings for this were taken from IBM.
// 48 8E D8 %9 A1 03 00 %9 3D 00 19 %9 73 03 %9 E9 at the EP
// or 26 C7 06 01 00 AD DE %9 26 C7 06 0C 00 00 00 %9 26 C7 06 04 00 00 10
// 2K from EOF

#define TMC_EPBUFFER_LEN 0x200
#define TMC_EOFBUFFER_LEN 0x800

// EXTScanFileTMCB arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                        EXTSTATUS_VIRUS_FOUND         if virus was found

EXTSTATUS EXTScanFileTMCB(LPCALLBACKREV1 lpCallBack,
                             HFILE  hFile,
                             LPBYTE lpbyInfectionBuffer,
                             LPBYTE lpbyWorkBuffer,
                             LPWORD lpwVID)
{
    BYTE            bMOVAX[]  = {0xA1, 0x03, 0x00};
    BYTE            bDECMOV[] = {0x48, 0x8E, 0xD8};
    BYTE            bJNB[] = {0x73, 0x03};
    BYTE            bCMPAX[] =  {0x3D, 0x00, 0x19};
    BYTE            bSearchC[] = {0x26, 0xC7, 0x06, 0x04, 0x00, 0x00, 0x10};
    BYTE            bSearchA[] = {0x26, 0xC7, 0x06, 0x01, 0x00, 0xAD, 0xDE};
    BYTE            bSearchB[] = {0x26, 0xC7, 0x06, 0x0C, 0x00, 0x00, 0x00};
    BYTE            i=0;

    WORD            wSeg;
    WORD            wBufferIndex=0,wI=0;
    DWORD           dwSeekOffset=0;
    LPEXEHEADER_T   lpEXEHeader;

    lpEXEHeader = (LPEXEHEADER_T)(lpbyInfectionBuffer + 256);

    *lpwVID=VID_TMCB;
    // determine the location of the entry-point and re-read 0x100 bytes

    if (lpEXEHeader->exesig[0] == 0xE9)
    {
        // use offset of E9 jump to determine start of virus
        dwSeekOffset = AVDEREF_WORD(lpbyInfectionBuffer + 257) + 3;
    }
    else
    {
        wSeg = WENDIAN(lpEXEHeader->cs) + WENDIAN(lpEXEHeader->header_size);
        dwSeekOffset = (DWORD)wSeg * 16 + WENDIAN(lpEXEHeader->ip);
    }

    if (lpCallBack->FileSeek(hFile,dwSeekOffset,SEEK_SET) == (DWORD)-1)
        return(EXTSTATUS_FILE_ERROR);

    if ((lpCallBack->FileRead(hFile, lpbyInfectionBuffer, TMC_EPBUFFER_LEN)) == -1)
        return(EXTSTATUS_FILE_ERROR);

    // First find DEC AX MOV DS,AX at the EP
    if ((WORD)-1 != (wI = ScanString(lpbyInfectionBuffer,
                                     TMC_EPBUFFER_LEN,
                                     bDECMOV,
                                     sizeof(bDECMOV))))
     {
        // Next find MOV AX,[0003] in the next 15 bytes
        if (((wBufferIndex = wBufferIndex + wI) < (TMC_EPBUFFER_LEN-0x0F)) &&
            ((WORD)-1 != (wI = ScanString(lpbyInfectionBuffer+wBufferIndex,
                                          0x0F,
                                          bMOVAX,
                                          sizeof(bMOVAX)))))
        {
            // Next look for CMP AX,1900 in the next 15 bytes
            if (((wBufferIndex = wBufferIndex + wI) < (TMC_EPBUFFER_LEN-0x0F)) &&
                ((WORD)-1 != (wI = ScanString(lpbyInfectionBuffer+wBufferIndex,
                                              0x0F,
                                              bCMPAX,
                                              sizeof(bCMPAX)))))
            {
                // Next look for JNB in the next 15 bytes
                if (((wBufferIndex = wBufferIndex + wI) < (TMC_EPBUFFER_LEN-0x0F)) &&
                    ((WORD)-1 != (wI = ScanString(lpbyInfectionBuffer+wBufferIndex,
                                                  0x0F,
                                                  bJNB,
                                                  sizeof(bJNB)))))
                {
                    // Finally find 0xE9 in the next 15 bytes
                    if ((wBufferIndex = wBufferIndex + wI) < (TMC_EPBUFFER_LEN-0x0F))
                    {
                        for (i=0;i<0x10;i++)
                        {
                            if (*(lpbyInfectionBuffer+wBufferIndex+i) == 0xE9)
                                return(EXTSTATUS_VIRUS_FOUND);
                        }
                    }
                } // if bJNB
            } // if CMPAX
        } // if MOVAX
    } // if DECMOV

    // if we didn't find it in the EP, the sig could be another one in the
    // last 2K
    // 26 C7 06 01 00 AD DE %9 26 C7 06 0C 00 00 00 %9 26 C7 06 04 00 00 10

    wBufferIndex = 0;

    if (lpCallBack->FileSeek(hFile,-TMC_EOFBUFFER_LEN,SEEK_END) == (DWORD)-1)
        return(EXTSTATUS_FILE_ERROR);

    if ((lpCallBack->FileRead(hFile, lpbyWorkBuffer, TMC_EOFBUFFER_LEN)) == -1)
        return(EXTSTATUS_FILE_ERROR);

    // First find bSearchA

    if ((WORD)-1 != (wI = ScanString(lpbyWorkBuffer,
                                     TMC_EOFBUFFER_LEN,
                                     bSearchA,
                                     sizeof(bSearchA))))
     {
        // Next find bSearchB in the next 25 bytes
        if (((wBufferIndex = wBufferIndex + wI) < (TMC_EOFBUFFER_LEN-0x19)) &&
            ((WORD)-1 != (wI = ScanString(lpbyWorkBuffer+wBufferIndex,
                                         0x19,
                                         bSearchB,
                                         sizeof(bSearchB)))))
        {
            // Finally find bSearchB in the next 25 bytes
            if (((wBufferIndex = wBufferIndex + wI) < (TMC_EOFBUFFER_LEN-0x19)) &&
                ((WORD)-1 != (wI = ScanString(lpbyWorkBuffer+wBufferIndex,
                                             0x19,
                                             bSearchC,
                                             sizeof(bSearchC)))))
            {
                        return(EXTSTATUS_VIRUS_FOUND);
            } // if bSearchC

        } // if bSearchB

    } // if bSearchA

    return(EXTSTATUS_OK);
}
// End EXTScanFileTMCB




//////////////////////////////////////////////////////////////////////////////
// Start of new java virus scanning code
//////////////////////////////////////////////////////////////////////////////

EXTSTATUS JavaSkipOverConstantPool
(
    LPCALLBACKREV1 lpCallBack,
    HFILE          hFile,
    LPBOOL         lpbFoundMethodName
)
{
    BYTE byTag, byBuffer[sizeof(DWORD)];
    WORD i, wConstantPoolCount, wLen;
    CONSTANT_T stConstant;

    *lpbFoundMethodName = FALSE;

    // seek to constant pool count...

    if (lpCallBack->FileSeek(hFile,8,SEEK_SET) == (DWORD)-1)
        return (EXTSTATUS_FILE_ERROR);

    // Read constant_pool_count

    if (lpCallBack->FileRead(hFile,byBuffer,sizeof(WORD)) != sizeof(WORD))
       return (EXTSTATUS_FILE_ERROR);

    // big endian encoding

    wConstantPoolCount = ((WORD)byBuffer[0] << 8) | byBuffer[1];

    // don't go 64K times

    if (wConstantPoolCount == 0)
        return EXTSTATUS_FILE_ERROR;

    wConstantPoolCount--;

    // Parse constant pool and look for names

    for (i=0;i<wConstantPoolCount;i++)
    {
        if (lpCallBack->FileRead(hFile,&byTag,sizeof(BYTE)) != sizeof(BYTE))
			return (EXTSTATUS_FILE_ERROR);

    	switch (byTag)
        {
	        case CONSTANT_Class:
	        case CONSTANT_String:

            	// Class and String are the same size

                if (lpCallBack->FileRead(hFile,
                                         (LPBYTE)&stConstant,
                                         sizeof(CONSTANT_Class_T)) !=
                    sizeof(CONSTANT_Class_T))
					return (EXTSTATUS_FILE_ERROR);

	        	break;

    	    case CONSTANT_Fieldref:
	        case CONSTANT_Methodref:
        	case CONSTANT_InterfaceMethodref:
        	case CONSTANT_NameAndType:

            	// All three are the same size

                if (lpCallBack->FileRead(hFile,
                                         (LPBYTE)&stConstant,
                                         sizeof(CONSTANT_Fieldref_T)) !=
                                         sizeof(CONSTANT_Fieldref_T))
					return (EXTSTATUS_FILE_ERROR);

        		break;

        	case CONSTANT_Integer:
	        case CONSTANT_Float:

            	// Integer and Float have the same size

                if (lpCallBack->FileRead(hFile,
                                         (LPBYTE)&stConstant,
                                         sizeof(CONSTANT_Integer_T)) !=
                                         sizeof(CONSTANT_Integer_T))
					return (EXTSTATUS_FILE_ERROR);

    	    	break;

        	case CONSTANT_Long:
	        case CONSTANT_Double:

            	// Long and Double have the same size

                if (lpCallBack->FileRead(hFile,
                                         (LPBYTE)&stConstant,
                                         sizeof(CONSTANT_Long_T)) !=
                                         sizeof(CONSTANT_Long_T))
					return (EXTSTATUS_FILE_ERROR);

            	if (++i >= wConstantPoolCount)
                	return (EXTSTATUS_FILE_ERROR);

        		break;

	        case CONSTANT_Utf8:
        	case CONSTANT_Unicode:

            	// Utf8 and Unicode have the same format

                if (lpCallBack->FileRead(hFile,
                                         byBuffer,
                                         sizeof(WORD)) != sizeof(WORD))
					return (EXTSTATUS_FILE_ERROR);

                wLen = ((WORD)byBuffer[0] << 8) | byBuffer[1];

                if (wLen == 18)
                {
                    BYTE                byBuffer[18];

                    if (lpCallBack->FileRead(hFile,
                                             byBuffer,
                                             18) != 18)
                        return (EXTSTATUS_FILE_ERROR);

                    if (byBuffer[0] == 'S' &&
                        byBuffer[1] == 't' &&
                        byBuffer[2] == 'r' &&
                        byBuffer[3] == 'a' &&
                        byBuffer[4] == 'n' &&
                        byBuffer[5] == 'g' &&
                        byBuffer[6] == 'e')
                    {
                        *lpbFoundMethodName = TRUE;
                    }
                }
                else
                {
                    if (lpCallBack->FileSeek(hFile,
                                             wLen,
                                             SEEK_CUR) == (DWORD)-1)
                        return (EXTSTATUS_FILE_ERROR);
                }
        		break;

            default:
            	return (EXTSTATUS_FILE_ERROR);
		}
    }

    return (EXTSTATUS_OK);
}

EXTSTATUS JavaSkipInterfaces
(
    LPCALLBACKREV1 lpCallBack,              // File op callbacks
    HFILE          hFile                    // Handle to file to scan
)
{
    BYTE byBuffer[sizeof(WORD)];
    WORD wInterfacesCount;

    // Read interfaces_count

    if (lpCallBack->FileRead(hFile,byBuffer,sizeof(WORD)) != sizeof(WORD))
        return (EXTSTATUS_FILE_ERROR);

    wInterfacesCount = ((WORD)byBuffer[0] << 8) | byBuffer[1];

    // Parse skip interfaces

    if (lpCallBack->FileSeek(hFile,
        (DWORD)sizeof(WORD) * (DWORD)wInterfacesCount,SEEK_CUR) ==
        (DWORD)-1)
        return (EXTSTATUS_FILE_ERROR);

    return (EXTSTATUS_OK);
}

EXTSTATUS JavaSkipSingleAttribute
(
    LPCALLBACKREV1 lpCallBack,              // File op callbacks
    HFILE          hFile                    // Handle to file to scan
)
{
    DWORD dwAttrLen;
    BYTE  byBuffer[sizeof(DWORD)];

    // Skip attribute_name

    if (lpCallBack->FileSeek(hFile,sizeof(WORD),SEEK_CUR) == (DWORD)-1)
        return (EXTSTATUS_FILE_ERROR);

    // Read attribute_length

    if (lpCallBack->FileRead(hFile,byBuffer,sizeof(DWORD)) != sizeof(DWORD))
        return (EXTSTATUS_FILE_ERROR);

    dwAttrLen = ((DWORD)byBuffer[0] << 24) |
                ((DWORD)byBuffer[1] << 16) |
                ((DWORD)byBuffer[2] << 8) |
                byBuffer[3];

    // Skip attribute_length bytes

    if (lpCallBack->FileSeek(hFile,dwAttrLen,SEEK_CUR) == (DWORD)-1)
        return (EXTSTATUS_FILE_ERROR);

    return (EXTSTATUS_OK);
}


EXTSTATUS JavaSkipAttributes
(
    LPCALLBACKREV1 lpCallBack,              // File op callbacks
    HFILE          hFile                    // Handle to file to scan
)
{
    WORD wAttributesCount, i;
    BYTE byBuffer[sizeof(WORD)];

    // Read attributes_count

    if (lpCallBack->FileRead(hFile,byBuffer,sizeof(WORD)) != sizeof(WORD))
        return (EXTSTATUS_FILE_ERROR);

    wAttributesCount = ((WORD)byBuffer[0] << 8) | byBuffer[1];

    // Skip over all attributes

    for (i=0;i<wAttributesCount;i++)
    {
        if (JavaSkipSingleAttribute(lpCallBack, hFile) != EXTSTATUS_OK)
            return(EXTSTATUS_FILE_ERROR);
    }

    return (EXTSTATUS_OK);
}



EXTSTATUS JavaSkipFields
(
    LPCALLBACKREV1 lpCallBack,              // File op callbacks
    HFILE          hFile                    // Handle to file to scan
)
{
    WORD i, wFieldsCount;
    BYTE byBuffer[sizeof(WORD)];

    // Read fields_count

    if (lpCallBack->FileRead(hFile,byBuffer,sizeof(WORD)) != sizeof(WORD))
        return (EXTSTATUS_FILE_ERROR);

    wFieldsCount = ((WORD)byBuffer[0] << 8) | byBuffer[1];

    // Skip over all fields

    for (i=0;i<wFieldsCount;i++)
    {
        // Skip over:
        //  u2 access_flags;
        //  u2 name_index;
        //  u2 signature_index;

        if (lpCallBack->FileSeek(hFile,6,SEEK_CUR) == (DWORD)-1)
            return (EXTSTATUS_FILE_ERROR);

        // Skip over attributes of field

        if (JavaSkipAttributes(lpCallBack, hFile) != EXTSTATUS_OK)
            return (EXTSTATUS_FILE_ERROR);
    }

    return (EXTSTATUS_OK);
}

EXTSTATUS JavaSkipOverFieldsAndInterfaces
(
    LPCALLBACKREV1 lpCallBack,
    HFILE          hFile
)
{
    // Skip access_flags, this_class, super_class

    if (lpCallBack->FileSeek(hFile,3*sizeof(WORD),SEEK_CUR) ==
        (DWORD)-1)
		return (EXTSTATUS_FILE_ERROR);

    // Read interfaces_count and parse interfaces

    if (JavaSkipInterfaces(lpCallBack, hFile) != EXTSTATUS_OK)
        return(EXTSTATUS_FILE_ERROR);

    // Read fields_count and parse skip fields

    if (JavaSkipFields(lpCallBack, hFile) != EXTSTATUS_OK)
        return(EXTSTATUS_FILE_ERROR);

    return (EXTSTATUS_OK);
}

#define STRANGE_BREW_BUFFER_SIZE        128
#ifndef ENC
#define ENC(x) ((x)^0xFF)
#endif


EXTSTATUS EXTScanFileStrangeBrew
(
    LPCALLBACKREV1 lpCallBack,
    HFILE          hFile,
    LPWORD         lpwVID
)
{
    BOOL            bFoundMethod;
    BYTE            byBuffer[STRANGE_BREW_BUFFER_SIZE];
    int             i;
    BYTE            bySig[] = {ENC(0x4D), ENC(0x03), ENC(0x36), ENC(0x09),
                               ENC(0x11), ENC(0x0B), ENC(0x2C), ENC(0xBC),
                               ENC(0x08), ENC(0x3A), ENC(0x0E), ENC(0x11),
                               ENC(0x04), ENC(0x06), ENC(0xBC), ENC(0x08),
                               ENC(0x3A), ENC(0x0F), ENC(0x03), ENC(0x36)};

    // check for file size modulo 101

    if (lpCallBack->FileSize(hFile) % 101 != 0)
        return(EXTSTATUS_OK);

    // skip over constant pool

    if (JavaSkipOverConstantPool(lpCallBack,
                                 hFile,
                                 &bFoundMethod) != EXTSTATUS_OK)
        return(EXTSTATUS_FILE_ERROR);

    if (bFoundMethod == FALSE)
        return(EXTSTATUS_OK);

    // skip over fields, interfaces, etc

    if (JavaSkipOverFieldsAndInterfaces(lpCallBack,hFile) != EXTSTATUS_OK)
        return(EXTSTATUS_FILE_ERROR);

    // read in and check for signature in first method

    if (lpCallBack->FileRead(hFile,
                             byBuffer,
                             STRANGE_BREW_BUFFER_SIZE) !=
        STRANGE_BREW_BUFFER_SIZE)
        return (EXTSTATUS_FILE_ERROR);

    for (i=0;i<sizeof(bySig);i++)
    {
        // sig is 38 bytes from top of section.

        if ((BYTE)ENC(byBuffer[i + 38]) != bySig[i])
            return(EXTSTATUS_OK);
    }

    // virus: yes

    *lpwVID = VID_JAVATEST;

    return(EXTSTATUS_VIRUS_FOUND);
}

//////////////////////////////////////////////////////////////////////////////
// end of java virus scanning code.
//////////////////////////////////////////////////////////////////////////////


// EXTScanFileSSR19834 arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyWorkBuffer       : 2-4K buffer for temporary operations (STACK OK also)
// lpbyInfectionBuffer  : 4K fstart buffers containing TOF, ENTRY, etc.
//                         +0   256 fstart bytes of target program.
//                         +256 64 bytes from TOF of target program.
//                         +512 256 unused
//                         +768 2 Number of external defs called.
//                         +770 2 ID of first external called.
//                         +772 ? ID of additional externals called.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                      : EXTSTATUS_VIRUS_FOUND         if virus was found
//                        EXTSTATUS_FILE_ERROR          if file error
//
//


EXTSTATUS EXTScanFileSSR19834
(
    LPCALLBACKREV1 lpCallBack,
    HFILE          hFile,
    LPBYTE         lpbyWorkBuffer,
    LPBYTE         lpbyInfectionBuffer,
    LPWORD         lpwVID
)
{
    WORD    i;
    DWORD   dwEP = 0, dwFileSize = 0;
    WORD    wSearchDist = 1024;

    DWORD   dwNewHeaderOffset;
    WORD    wNewHeader;


    dwEP = GetEntryPtOffset(lpbyInfectionBuffer + HEADER_OFF);
    if (dwEP == 0)
        return(EXTSTATUS_OK);

    dwFileSize = FILESIZE();
    if (dwFileSize == DWERROR)
        return(EXTSTATUS_FILE_ERROR);

    //virus size is always 19834!
    if ( (dwFileSize-dwEP) != 19834 )
        return(EXTSTATUS_OK);


    //if it's an MZ file, make sure it's not an LX, LE, NE, PE file
    //this check due to FP with CI 5935, an LX-format DLL

    if ( AVDEREF_WORD(lpbyInfectionBuffer + HEADER_OFF) == 0x5a4d)
    {
        dwNewHeaderOffset =
            AVDEREF_DWORD(lpbyInfectionBuffer + HEADER_OFF + 0x3c);

        if (dwNewHeaderOffset == FILESEEK(dwNewHeaderOffset))
        {
            if (sizeof(WORD) != FILEREAD( (LPBYTE)&wNewHeader, sizeof(WORD)) )
                return(EXTSTATUS_FILE_ERROR);

            wNewHeader = WENDIAN(wNewHeader);

            if ( (wNewHeader == 0x584c) ||      //LX
                 (wNewHeader == 0x454c) ||      //LE
                 (wNewHeader == 0x454e) ||      //NE
                 (wNewHeader == 0x4550) )       //PE
                return(EXTSTATUS_OK);
        }
    }


    //look for int 01

    if (dwEP != FILESEEK(dwEP))
        return(EXTSTATUS_FILE_ERROR);

    if (wSearchDist != FILEREAD(lpbyWorkBuffer,wSearchDist))
        return(EXTSTATUS_FILE_ERROR);

    for (i=0;i<wSearchDist;i++)
    {
        if ( ( *(lpbyWorkBuffer+i) == 0xcd ) &&
             ( *(lpbyWorkBuffer+i+1) == 0x01 ) )
            break;
    }

    if (i == wSearchDist)
        return(EXTSTATUS_OK);


    *lpwVID = VID_SSR19834;
    return(EXTSTATUS_VIRUS_FOUND);


}//EXTScanFileSSR19834



// EXTScanFileVanitas3712 arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyWorkBuffer       : 2-4K buffer for temporary operations (STACK OK also)
// lpbyInfectionBuffer  : 4K fstart buffers containing TOF, ENTRY, etc.
//                         +0   256 fstart bytes of target program.
//                         +256 64 bytes from TOF of target program.
//                         +512 256 unused
//                         +768 2 Number of external defs called.
//                         +770 2 ID of first external called.
//                         +772 ? ID of additional externals called.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                      : EXTSTATUS_VIRUS_FOUND         if virus was found
//                        EXTSTATUS_FILE_ERROR          if file error
//
//

#define VANITAS_LOOP_MOVAX      0x0001
#define VANITAS_LOOP_DECAX      0x0002

#define VANITAS_LOOP_MOVCX      0x0010
#define VANITAS_LOOP_DECCX      0x0020

#define VANITAS_LOOP_MOVDX      0x0100
#define VANITAS_LOOP_DECDX      0x0200


EXTSTATUS EXTScanFileVanitas3712
(
    LPCALLBACKREV1 lpCallBack,
    HFILE          hFile,
    LPBYTE         lpbyWorkBuffer,
    LPBYTE         lpbyInfectionBuffer,
    LPWORD         lpwVID
)
{
    WORD    i;
    WORD    wJNZCount = 0, wLoopCount = 0;
    WORD    wLoopFlags = 0;

    //This detection is for the variants of Vanitas.3712 that put in
    //  a dummy double-loop at the top of the decryption loop.
    //The loop uses two of the registers AX, CX, DX.
    //This always occurs within the first 32 bytes.
    //The rest of the infections are caught by PAM def 0x7446


    //search for two JNZ's (backward) within the first 32 bytes
    for (i=0; i+1<32; i++)
    {
        if ( (lpbyInfectionBuffer[i] == 0x75) &&
             ( (lpbyInfectionBuffer[i+1] & 0xe0) == 0xe0 ) )
        {
            wJNZCount ++;
        }
    }

    if (wJNZCount < 2)
        return(EXTSTATUS_OK);


    //look for the loops
    for (i=0; i+4<32; i++)
    {
        if (lpbyInfectionBuffer[i] == 0xb8)
            wLoopFlags |= VANITAS_LOOP_MOVAX;

        if (lpbyInfectionBuffer[i] == 0xb9)
            wLoopFlags |= VANITAS_LOOP_MOVCX;

        if (lpbyInfectionBuffer[i] == 0xba)
            wLoopFlags |= VANITAS_LOOP_MOVDX;


        if ( (lpbyInfectionBuffer[i] == 0x48) &&
             (lpbyInfectionBuffer[i+1] == 0x75) &&
             ( (lpbyInfectionBuffer[i+2] & 0xe0) == 0xe0 ) )

        {
            wLoopFlags |= VANITAS_LOOP_DECAX;
            i += 2;
        }

        if ( (lpbyInfectionBuffer[i]   == 0x2d) &&
             (lpbyInfectionBuffer[i+1] == 0x01) &&
             (lpbyInfectionBuffer[i+2] == 0x00) &&
             (lpbyInfectionBuffer[i+3] == 0x75) &&
             ( (lpbyInfectionBuffer[i+4] & 0xe0) == 0xe0 ) )

        {
            wLoopFlags |= VANITAS_LOOP_DECAX;
            i += 4;
        }

        if ( (lpbyInfectionBuffer[i] == 0x49) &&
             (lpbyInfectionBuffer[i+1] == 0x75) &&
             ( (lpbyInfectionBuffer[i+2] & 0xe0) == 0xe0 ) )

        {
            wLoopFlags |= VANITAS_LOOP_DECCX;
            i += 2;
        }

        if ( (lpbyInfectionBuffer[i]   == 0x83) &&
             (lpbyInfectionBuffer[i+1] == 0xe9) &&
             (lpbyInfectionBuffer[i+2] == 0x01) &&
             (lpbyInfectionBuffer[i+3] == 0x75) &&
             ( (lpbyInfectionBuffer[i+4] & 0xe0) == 0xe0 ) )

        {
            wLoopFlags |= VANITAS_LOOP_DECCX;
            i += 4;
        }

        if ( (lpbyInfectionBuffer[i] == 0x4a) &&
             (lpbyInfectionBuffer[i+1] == 0x75) &&
             ( (lpbyInfectionBuffer[i+2] & 0xe0) == 0xe0 ) )

        {
            wLoopFlags |= VANITAS_LOOP_DECDX;
            i += 2;
        }

        if ( (lpbyInfectionBuffer[i]   == 0x83) &&
             (lpbyInfectionBuffer[i+1] == 0xea) &&
             (lpbyInfectionBuffer[i+2] == 0x01) &&
             (lpbyInfectionBuffer[i+3] == 0x75) &&
             ( (lpbyInfectionBuffer[i+4] & 0xe0) == 0xe0 ) )

        {
            wLoopFlags |= VANITAS_LOOP_DECDX;
            i += 4;
        }

    }//look for the loops


    //did we find two loops?
    if ( (wLoopFlags & VANITAS_LOOP_MOVAX) &&
         (wLoopFlags & VANITAS_LOOP_DECAX) )
    {
        wLoopCount++;
    }

    if ( (wLoopFlags & VANITAS_LOOP_MOVCX) &&
         (wLoopFlags & VANITAS_LOOP_DECCX) )
    {
        wLoopCount++;
    }

    if ( (wLoopFlags & VANITAS_LOOP_MOVDX) &&
         (wLoopFlags & VANITAS_LOOP_DECDX) )
    {
        wLoopCount++;
    }


    //nope
    if (wLoopCount != 2)
        return(EXTSTATUS_OK);

    //yup
    *lpwVID = VID_VANITAS3712;
    return(EXTSTATUS_VIRUS_FOUND);


}//EXTScanFileVanitas3712


// EXTScanFileLightning arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyWorkBuffer       : 2-4K buffer for temporary operations (STACK OK also)
// lpbyInfectionBuffer  : 4K fstart buffers containing TOF, ENTRY, etc.
//                         +0   256 fstart bytes of target program.
//                         +256 64 bytes from TOF of target program.
//                         +512 256 unused
//                         +768 2 Number of external defs called.
//                         +770 2 ID of first external called.
//                         +772 ? ID of additional externals called.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                      : EXTSTATUS_VIRUS_FOUND         if virus was found
//                        EXTSTATUS_FILE_ERROR          if file error
//
//


//Opcodes that can be used before the RETF in infected files:
//
//Note:  These opcodes are in the proper order, i.e. the high bit
//       in the first word corresponds to opcode 0x00, etc.
//
WORD gawLightningProfile[] =
{
    0x4202,    //0100 0010 0000 0010
    0x0203,    //0000 0010 0000 0011
    0x0040,    //0000 0000 0100 0000
    0x5000,    //0101 0000 0000 0000
    0xf7f7,    //1111 0111 1111 0111
    0xf7f7,    //1111 0111 1111 0111
    0x0000,    //0000 0000 0000 0000
    0x0000,    //0000 0000 0000 0000
    0x401a,    //0100 0000 0001 1010
    0x0008,    //0000 0000 0000 1000
    0x0000,    //0000 0000 0000 0000
    0x00f7,    //0000 0000 1111 0111
    0x0010,    //0000 0000 0001 0000
    0x5000,    //0101 0000 0000 0000
    0x0040,    //0000 0000 0100 0000
    0x0000     //0000 0000 0000 0000
};



EXTSTATUS EXTScanFileLightning
(
    LPCALLBACKREV1 lpCallBack,
    HFILE          hFile,
    LPBYTE         lpbyWorkBuffer,
    LPBYTE         lpbyInfectionBuffer,
    LPWORD         lpwVID
)
{
    WORD    wIndex = 0;
    WORD    wPushCount = 0;
    BYTE    byOpcode = 0, x, y;

    //trace thru the FSTART buffer and count the PUSHes,
    //  until we get to RETF (0xcb)

    while ( (wIndex+3 < 256) && (byOpcode != 0xcb) )
    {
        byOpcode = lpbyInfectionBuffer[wIndex];

        //make sure the opcode is in the profile;  byOpcode == xy
        x = byOpcode >> 4;
        y = byOpcode & 0x0f;
        if ( ! ( gawLightningProfile[x] & (0x8000>>y) ) )
            return(EXTSTATUS_OK);


        //record the push or pop
        switch(byOpcode)
        {
            //if it's a push
            case 0x50:
            case 0x51:
            case 0x52:
            case 0x53:
            case 0x54:
            case 0x55:
            case 0x56:
            case 0x57:
            case 0x0e:
            case 0x1e:
            case 0x06:
            case 0x16:
            case 0x9c:
                wPushCount ++;
                break;

            //if it's a pop
            case 0x58:
            case 0x59:
            case 0x5a:
            case 0x5b:
            case 0x5c:
            case 0x5d:
            case 0x5e:
            case 0x5f:
            case 0x0f:
            case 0x1f:
            case 0x07:
            case 0x17:
            case 0x9d:
                wPushCount --;
                break;


        }//switch(byOpcode)

        wIndex += OpcodeLength(lpbyInfectionBuffer+wIndex);

    } //while (wIndex+3<256)

    //if we didn't find RETF, it ain't Lightning
    if (byOpcode != 0xcb)
        return(EXTSTATUS_OK);

    //if it don't have 5 PUSHes, it ain't Lightning
    if (wPushCount != 5)
        return(EXTSTATUS_OK);


    //first XOR decryptor should be close!
    //
    //loop:
    //  xor [xx], yy       31 ??
    //  inc xx             40-47
    //  dec zz             48-4f
    //  jnz loop           75fa

    while (wIndex+5 < 256)
    {
        if ( (lpbyInfectionBuffer[wIndex] == 0x31) &&
             ( (lpbyInfectionBuffer[wIndex+2] & 0xf8) == 0x40 ) &&
             ( (lpbyInfectionBuffer[wIndex+3] & 0xf8) == 0x48 ) &&
             (lpbyInfectionBuffer[wIndex+4] == 0x75) &&
             (lpbyInfectionBuffer[wIndex+5] == 0xfa) )
        {
            //got 'em!
            *lpwVID = VID_LIGHTNING;
            return(EXTSTATUS_VIRUS_FOUND);
        }

        wIndex++;
    }


    //hmm, guess it ain't Lightning...
    return(EXTSTATUS_OK);


} //EXTScanFileLightning


// EXTScanFileCezar arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyWorkBuffer       : 2-4K buffer for temporary operations (STACK OK also)
// lpbyInfectionBuffer  : 4K fstart buffers containing TOF, ENTRY, etc.
//                         +0   256 fstart bytes of target program.
//                         +256 64 bytes from TOF of target program.
//                         +512 256 unused
//                         +768 2 Number of external defs called.
//                         +770 2 ID of first external called.
//                         +772 ? ID of additional externals called.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                      : EXTSTATUS_VIRUS_FOUND         if virus was found
//                        EXTSTATUS_FILE_ERROR          if file error
//

WORD    gawCezarSig[] = { 0xe8, 0x00, 0x00, 0x8b, 0xec, 0x8b, 0x6e, 0x00,
                          0x83, 0xed, 0x03, 0xe8, 0x34, 0x00, 0x2e, 0x8c,
                          0x86, 0x45, 0x00, 0xb4, 0x30, 0xbb, 0x77, 0x77,
                          0xcd, 0x21, 0x81, 0xfb, 0x57, 0x57, 0x74, 0x27 };

EXTSTATUS EXTScanFileCezar
(
    LPCALLBACKREV1 lpCallBack,
    HFILE          hFile,
    LPBYTE         lpbyWorkBuffer,
    LPBYTE         lpbyInfectionBuffer,
    LPWORD         lpwVID
)
{
    DWORD   dwEPOffset = 0;

    //unused storage for GenericDecrypt
    BYTE    byDecryptFlags;
    DWORD   dwDecryptKey;
    DWORD   dwDecryptDelta;

    dwEPOffset = GetEntryPtOffset(lpbyInfectionBuffer + HEADER_OFF);
    if (dwEPOffset == 0)
        return(EXTSTATUS_OK);

    //read in 35 bytes from entry point:
    //  e8 ?? ?? (call to decryptor)
    //  32 encrypted signature bytes

    if (dwEPOffset != lpCallBack->FileSeek(hFile, dwEPOffset, SEEK_SET))
        return EXTSTATUS_FILE_ERROR;

    if (UERROR == lpCallBack->FileRead(hFile, lpbyWorkBuffer, 35))
        return EXTSTATUS_FILE_ERROR;

    //verify gawCezarSig at EP+3, encrypted using byte XOR/ADD/ROT/NEG
    //Note:  definition of GenericDecrypt() in pespscan.cpp
    if ( GenericDecrypt(lpbyWorkBuffer + 3,
                        gawCezarSig,
                        32,
                        DECRYPT_BYTE | DECRYPT_XOR | DECRYPT_ADD
                            | DECRYPT_ROT | DECRYPT_NEG,
                        &byDecryptFlags,
                        &dwDecryptKey,
                        &dwDecryptDelta) == EXTSTATUS_OK)
    {
        *lpwVID = VID_CEZAR;
        return EXTSTATUS_VIRUS_FOUND;
    }

    //didn't find it
    return EXTSTATUS_OK;

}//EXTScanFileCezar



// EXTScanFileZombieZCME arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyWorkBuffer       : 2-4K buffer for temporary operations (STACK OK also)
// lpbyInfectionBuffer  : 4K fstart buffers containing TOF, ENTRY, etc.
//                         +0   256 fstart bytes of target program.
//                         +256 64 bytes from TOF of target program.
//                         +512 256 unused
//                         +768 2 Number of external defs called.
//                         +770 2 ID of first external called.
//                         +772 ? ID of additional externals called.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                      : EXTSTATUS_VIRUS_FOUND         if virus was found
//                        EXTSTATUS_FILE_ERROR          if file error
//

#define ZOMBIE_MOVDI4000    0x0001
#define ZOMBIE_MOVDXDI      0x0002
#define ZOMBIE_MOVAL5A      0x0004
#define ZOMBIE_STOSB5A      0x0008
#define ZOMBIE_MOVAL30      0x0010
#define ZOMBIE_STOSB30      0x0020
#define ZOMBIE_MOVAL4D      0x0040
#define ZOMBIE_STOSB4D      0x0080


EXTSTATUS EXTScanFileZombieZCME
(
    LPCALLBACKREV1 lpCallBack,
    HFILE          hFile,
    LPBYTE         lpbyWorkBuffer,
    LPBYTE         lpbyInfectionBuffer,
    LPWORD         lpwVID
)
{
    WORD    wIndex = 0, wOffset = 0, wInstructionCount = 0, wIncrement = 0;
    WORD    i, wFlags = 0;
    BYTE    byOpcode = 0, byAL = 0;


    //make sure TOF has:  BF0040    MOV DI, 4000
    if ( (lpbyInfectionBuffer[256+0] != 0xbf) ||
         (lpbyInfectionBuffer[256+1] != 0x00) ||
         (lpbyInfectionBuffer[256+2] != 0x40) )
        return EXTSTATUS_OK;


    //copy TOF to lpbyWorkBuffer
    for (i=0;i<64;i++)
        lpbyWorkBuffer[i] = lpbyInfectionBuffer[256+i];


    //trace the instructions
    while ( (wInstructionCount<30) && (wFlags != 0x00ff) && (wIndex+2<64) )
    {
        byOpcode = lpbyWorkBuffer[wIndex];

        switch(byOpcode)
        {
            case 0xe9:      //E9????    JMP
                //calculate the new offset into the file
                wOffset += (3 + AVDEREF_WORD(lpbyWorkBuffer+wIndex+1));
                if (wOffset > 8192)
                    return EXTSTATUS_OK;

                //read in 64 bytes from this new offset
                if (wOffset != lpCallBack->FileSeek(hFile,wOffset,SEEK_SET))
                    return EXTSTATUS_FILE_ERROR;

                if (UERROR == lpCallBack->FileRead(hFile,lpbyWorkBuffer,64))
                    return EXTSTATUS_FILE_ERROR;

                wIndex = 0;
                break;

            case 0x90:      //90        NOP
                break;

            case 0xbf:      //BF0040    MOV DI, 4000
                if (AVDEREF_WORD(lpbyWorkBuffer+wIndex+1) == 0x4000)
                    wFlags |= ZOMBIE_MOVDI4000;
                else
                    return EXTSTATUS_OK;
                break;

            case 0x8b:      //8BD7      MOV DX, DI
                if (lpbyWorkBuffer[wIndex+1] == 0xd7)
                    wFlags |= ZOMBIE_MOVDXDI;
                else
                    return EXTSTATUS_OK;
                break;

            case 0xb0:      //B0??      MOV AL, ??
                switch(lpbyWorkBuffer[wIndex+1])
                {
                    case 0x5a:
                        wFlags |= ZOMBIE_MOVAL5A;
                        byAL = 0x5a;
                        break;
                    case 0x30:
                        wFlags |= ZOMBIE_MOVAL30;
                        byAL = 0x30;
                        break;
                    case 0x4d:
                        wFlags |= ZOMBIE_MOVAL4D;
                        byAL = 0x4d;
                        break;
                    default:
                        return EXTSTATUS_OK;
                        break;
                }
                break;

            case 0xaa:      //AA        STOSB
                switch(byAL)
                {
                    case 0x5a:
                        wFlags |= ZOMBIE_STOSB5A;
                        break;
                    case 0x30:
                        wFlags |= ZOMBIE_STOSB30;
                        break;
                    case 0x4d:
                        wFlags |= ZOMBIE_STOSB4D;
                        break;
                    default:
                        return EXTSTATUS_OK;
                        break;
                }
                break;

            default:
                return EXTSTATUS_OK;
                break;

        }//switch(byOpcode)

        if (byOpcode != 0xe9)
        {
            wIncrement = OpcodeLength(lpbyWorkBuffer+wIndex);
            wIndex += wIncrement;
            wOffset += wIncrement;
        }

        wInstructionCount ++;

    } //while (tracing the instructions)


    //all the flags are set
    if (wFlags == 0x00ff)
    {
        *lpwVID = VID_ZOMBIEZCME;
        return EXTSTATUS_VIRUS_FOUND;
    }

    //didn't find it
    return EXTSTATUS_OK;

}//EXTScanFileZombieZCME


// EXTScanFileLexotran arguments:
//
// lpCallBack           : pointer to callback structure for FileOpen, etc.
// hFile                : file handle into current file to scan
// lpbyInfectionBuffer  : 4K fstart buffers containing TOF, ENTRY, etc.
//                         +0   256 fstart bytes of target program.
//                         +256 64 bytes from TOF of target program.
//                         +512 256 unused
//                         +768 2 Number of external defs called.
//                         +770 2 ID of first external called.
//                         +772 ? ID of additional externals called.
// lpwVID               : virus ID # of the virus if found
//
// Returns:
//
//     EXTSTATUS        : EXTSTATUS_OK                  if no virus found
//                      : EXTSTATUS_VIRUS_FOUND         if virus was found
//                        EXTSTATUS_FILE_ERROR          if file error
//

WORD gawLexotranProfile[16] =
{
	0x5ed6,		//	0101 1110 1101 0110 
	0xe6ca,		//	1110 0110 1100 1010 
	0xe2c7,		//	1110 0010 1100 0111 
	0xc6ce,		//	1100 0110 1100 1110 
	0x2a0c,		//	0010 1010 0000 1100 
	0xb7ff,		//	1011 0111 1111 1111 
	0x18a1,		//	0001 1000 1010 0001 
	0xe7fc,		//	1110 0111 1111 1100 
	0xf6f8,		//	1111 0110 1111 1000 
	0x080c,		//	0000 1000 0000 1100 
	0x2011,		//	0010 0000 0001 0001 
	0xf7f7,		//	1111 0111 1111 0111 
	0x3ba7,		//	0011 1011 1010 0111 
	0x266e,		//	0010 0110 0110 1110 
	0x8232,		//	1000 0010 0011 0010 
	0x4b0d		//	0100 1011 0000 1101 
};


EXTSTATUS EXTScanFileLexotran
(
    LPCALLBACKREV1 lpCallBack,
    HFILE          hFile,
    LPBYTE         lpbyInfectionBuffer,
    LPWORD         lpwVID
)
{

    //The virscan sig verifies a 4 byte signature in the MZ header,
    //and checks that EOF-EP is roughly 20k (the size of the virus).

    //This virus is fully polymorphic, but it uses very few CALLs and
    //JMPs:  note that the profile indicates that there will be no
    //E8's or E9's found within the first 200 bytes of the FSTART buffer.


    LPBYTE  lpbyIP;
    BYTE    byOpcode = 0, x, y;


    //initialization
    lpbyIP = lpbyInfectionBuffer;


    //trace the instructions for the first 200 bytes

    while (lpbyIP < lpbyInfectionBuffer + 200)
    {
        byOpcode = lpbyIP[0];

        //make sure the opcode fits the profile
        x = byOpcode >> 4;
        y = byOpcode & 0x0f;
        if ( !(gawLexotranProfile[x] & (0x8000>>y)) )
            return EXTSTATUS_OK;

        lpbyIP += OpcodeLength(lpbyIP);

    } //while (tracing the instructions)


    //all the opcodes were in the profile

    *lpwVID = VID_LEXOTRAN;
    return EXTSTATUS_VIRUS_FOUND;

}//EXTScanFileLexotran




#if defined(SYM_DOS)

MODULE_EXPORT_TABLE_TYPE module_export_table =
{
  EXPORT_STRING,
  (void (*)())EXTScanFile
};

void main(void)
{
}

#endif
