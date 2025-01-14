;****************************************************************************
; Copyright 1996 Symantec, Peter Norton Product Group
;****************************************************************************
; WDVARSIG.WDF
;
; $Header:   S:/NAVEX/VCS/wdvarsig.wdv   1.94   07 Jul 1998 14:16:26   RELNITI  $
;
; This source file contains definitions for the variant Word viruses.
;
;****************************************************************************
; $Log:   S:/NAVEX/VCS/wdvarsig.wdv  $
   
      Rev 1.94   07 Jul 1998 14:16:26   RELNITI
   ADD NotFullSet to W7H2 trigger macrosig. FP on #2286
   
      Rev 1.93   02 Jul 1998 14:55:50   RELNITI
   ADD several NamedCRCSig to Macro Trashcan for #2275 totally corrupted
    WM.Schumann's macros
   
      Rev 1.92   01 Jul 1998 16:36:00   RELNITI
   REVISE Appder Family to catch more
   
      Rev 1.91   29 Jun 1998 15:33:22   RELNITI
   REVISE WM.Showoff Family
   
      Rev 1.90   16 Jun 1998 17:29:50   JWILBER
   Added sig for corrupted AutoOpen macro for CI 2139.
 
      Rev 1.89   10 Jun 1998 13:03:24   DCHI
   Added W7H2 calloff signatures.
 
      Rev 1.88   04 Jun 1998 19:32:58   AOONWAL
   Modified CAP family detection.
 
      Rev 1.87   22 May 1998 12:37:20   RELNITI
   MOVE the previous revision CRCWD8 into Cap.AY in WD7SIGS5.WDF
 
      Rev 1.86   22 May 1998 00:43:04   JWILBER
   Added a WD8 version of CAP_DAMAGED, VID 4f21, for CI 1979.
 
      Rev 1.85   15 Apr 1998 10:58:04   RELNITI
   REMOVE XL97 flag from MacroComponent (FullSet detection). It's in
    XLVARSIG.WDF now.
 
      Rev 1.84   14 Apr 1998 12:09:40   RELNITI
   ADD AUTOCLOSE_SWITCHERG & K to Switcher Family
 
      Rev 1.83   09 Apr 1998 11:36:18   RELNITI
   MODIFY WM.Niceday Family detection to include variants of .G, .N, .V
 
      Rev 1.82   08 Apr 1998 11:18:46   RELNITI
   ADD Concept.Z Family
 
      Rev 1.81   03 Apr 1998 15:29:24   DKESSNE
   added Macro Trashcan for WD8 macros, and two CRC's for CI 1679
 
      Rev 1.80   13 Mar 1998 22:55:02   RELNITI
   No change.
 
      Rev 1.79   09 Mar 1998 14:47:38   JWILBER
   Added CRC sig for corrupted SHOW macro for CI 1480.
 
      Rev 1.78   02 Mar 1998 11:29:54   AOONWAL
   Updated from defwork
 
      Rev MAR98  24 Feb 1998 17:37:42   ECHIEN
   Added Concept.I Family
 
      Rev 1.77   13 Jan 1998 15:29:32   DCHI
   Two main modifications to heuristic call-off signature:
   1. For Word 6.0/95 now takes care of Big Endian macros
   2. For OrganizerCopies, now verifies the presence of .Tab = 3
 
      Rev 1.76   02 Dec 1997 19:41:04   RELNITI
   ADD CRC_CAP_660 for #660 into corrupted Cap detection.
 
      Rev 1.75   02 Dec 1997 18:44:34   RELNITI
   MODIFY PayCheck Family to repair 8-macros variant
 
      Rev 1.74   02 Dec 1997 18:42:58   RELNITI
   MODIFY PayCheck Family to detect more variants
 
      Rev 1.73   02 Dec 1997 15:07:04   RELNITI
    ADD WM.PayCheck Family
 
      Rev 1.72   01 Dec 1997 23:33:42   RELNITI
   ADD MDMA Variant Detection for 97 upconverted ones.... #639
 
      Rev 1.71   20 Nov 1997 19:54:14   JWILBER
   Modified during Dec97 build.
 
      Rev DEC97  18 Nov 1997 17:37:12   RELNITI
   ADD CRC_CAP_CAP557 for #557
 
      Rev DEC97  18 Nov 1997 10:04:30   RELNITI
   ADD CRC_CAP_CAP562 for #562 corrupted non infectious Cap variant that
    Solly detected as "looks like Cap"
 
      Rev DEC97  17 Nov 1997 19:21:02   AOONWAL
   Added (CRC_AUTOEXIT_GOODNIGHT_CORRUPT) to make it compile
 
      Rev DEC97  13 Nov 1997 17:18:26   RELNITI
   ADD WM.Niknat Family for #531
 
      Rev DEC97  12 Nov 1997 13:47:30   RELNITI
   ADD WM.Temple Family
 
      Rev 1.70   11 Nov 1997 12:01:26   RELNITI
   MODIFY WM.GoodNight Family detection to catch more variants and remnants
    partly due to #490
 
      Rev 1.69   11 Nov 1997 08:52:38   RELNITI
   ADD WM.Appder Family; detects both WM & W97M
 
      Rev 1.68   04 Nov 1997 15:38:12   AOONWAL
   Moved Goodnight Family def from wd7sigs5.wdf to wdvarsig.wdf
 
      Rev 1.67   31 Oct 1997 12:48:58   RELNITI
   ADD CRC of ShowOff.CK's AutoClose & AutoOpen into ShowOff Family
    to let it detect variants of this later on.
 
      Rev 1.66   27 Oct 1997 12:51:30   JWILBER
   Modified during NOV97 build.
 
      Rev NOV97  24 Oct 1997 13:38:22   AOONWAL
   Added yet another corrupted CAP to "Trash_Can"
 
      Rev 1.65   15 Oct 1997 18:13:56   DCHI
   Added Word 97 heuristics call signature.
 
      Rev 1.64   25 Sep 1997 14:00:20   ECHIEN
   Added Hybrid Family
 
      Rev 1.63   23 Sep 1997 23:40:58   JWILBER
   Modified during Oct97 def build.
 
      Rev Sep97  22 Sep 1997 18:59:36   RELNITI
   ADD WM.Anak Family
 
      Rev Sep97  22 Sep 1997 14:01:12   ECHIEN
   Added WD8 to Muck Family
 
      Rev 1.62   05 Sep 1997 13:55:00   AOONWAL
   Added one more corrupted_CAP to VID_CAP_CORRUPTED

	  Rev 1.61	 03 Sep 1997 15:16:38	RELNITI
   ADD one more Algo-Sig to Cap Family

	  Rev 1.60	 02 Sep 1997 18:06:02	RELNITI
   ADD another corrupted CAP for #13052

	  Rev 1.59	 26 Aug 1997 10:35:38	JWILBER
   Modified during Sep 97 build.

	  Rev 1.61	 22 Aug 1997 13:02:40	RELNITI
   ADD WM.DNTC Family detection using Algorithmic signature

	  Rev 1.60	 21 Aug 1997 15:32:00	RELNITI
   ADD WM.Switcher Family

	  Rev 1.59	 20 Aug 1997 15:26:22	RELNITI
   MODIFY ShowOff Family to detect and repair more variants
   ADD Muck Family partially for #12953

	  Rev 1.58	 28 Jul 1997 13:02:46	AOONWAL
   Modified during AUG97 build

	  Rev AUG97  24 Jul 1997 17:13:00	DCHI
   Changed QA status from PASSED to HEU for VID_MACRO_HEURISTICS.

	  Rev AUG97   21 Jul 1997 12:54:18	 JWILBER
   Added CRC_AUTOOPEN_12630 to Trashcan sig for CI 12630.

	  Rev AUG97  18 Jul 1997 14:41:36	CFORMUL
   Added Corrupted cap macro to CAP CORRUPTED.

	  Rev 1.56	 16 Jul 1997 20:39:12	CFORMUL
   Added CRC's for two more completely corrupted CAP variants.

	  Rev 1.55	 16 Jul 1997 16:02:26	JWILBER
   Added algorithmic sig for macros that are all zeros to Trashcan sig.
   Done in response to CI 12594.  If 1st 16 bytes of macro are 0x00, the
   macro "hits".

	  Rev 1.54	 16 Jul 1997 14:44:18	CFORMUL
   Added two more CRC's to Concept Damaged def.

	  Rev 1.53	 16 Jul 1997 13:37:50	CFORMUL
   Added Corrupted CAP macros to the Trash Can def.

	  Rev 1.52	 09 Jul 1997 17:01:56	DCHI
   Added Word 6.0/95 calloff macro signature.

	  Rev 1.51	 07 Jul 1997 14:47:32	AOONWAL
   Removed build error.

	  Rev 1.50	 07 Jul 1997 13:44:20	AOONWAL
   Removed one CRC from TRASH CAN because the same CRC is added to WM.Appder.G
   detection

	  Rev 1.49	 03 Jul 1997 21:48:48	RELNITI
   PULL OUT Rapi Variant detection
   ADD a FileOpen-based Rapi Family detection

	  Rev 1.48	 03 Jul 1997 17:07:48	RELNITI
   REWORK WM.Johnny Family to get more variant

	  Rev 1.47	 03 Jul 1997 13:14:16	ECHIEN
   Added CAP Family

	  Rev 1.45	 02 Jul 1997 15:28:04	DANG
   Added another mangled CAP macro to corrupted list of Cap for CI#12453

	  Rev 1.44	 01 Jul 1997 17:55:20	ECHIEN
   Added Twolines and NIceday family

	  Rev 1.43	 01 Jul 1997 15:40:24	JWILBER
   Added CRC for slightly mangled WM.Appder macro (named Appder) to
   TrashCan sig for CI 12423.

	  Rev 1.42	 01 Jul 1997 13:30:48	JWILBER
   Added a CRC to the CAP_CORRUPTED/MACRO_COMPONENT def, 4e00,
   for CI 12413.

	  Rev 1.41	 01 Jul 1997 11:51:16	AOONWAL
   Modified during July-MidMonth build

	  Rev July-MidMonth  30 Jun 1997 20:05:14	RELNITI
   ADD CRC_MSRUN_TRASH for #12406, it's a remnant of some variant of TwoLines

	  Rev July-MidMonth  27 Jun 1997 14:42:22	RELNITI
   OOPS should have done cut&paste instead of copy&paste on previous mod.

	  Rev July-MidMonth  27 Jun 1997 14:30:40	RELNITI
   MIRROR the Cap Corrupted detection changes in Newvir

	  Rev July-MidMonth  26 Jun 1997 17:56:04	JWILBER
   Removed NamedCRCSigs ToolsMacro_CapA and FileTemplates_CapA
   from TrashCan sig to eliminate risk of FPs.

	  Rev July-MidMonth  26 Jun 1997 13:14:24	RELNITI
   ADD several NamedCRCSig from Cap.A to trashcan to let Macro Component
	pick it up in case of corrupted-non-infectious-but-annyoing CAP
	is there as in some old customer issue.
   The changes in Cap.* signature makes this necessary.

	  Rev 1.37	 25 Jun 1997 16:26:44	JWILBER
   Added CRC for a mangled FileSaveAs macro for CI ??? to
   TrashCan sig.

	  Rev 1.36	 25 Jun 1997 16:13:46	JWILBER
   Added more crap to macro component to detect more mangled macros.

	  Rev 1.35	 25 Jun 1997 14:32:52	JWILBER
   Added sigs to trashcan to detect another mangled CAP sample
   for CI ???.

	  Rev 1.34	 25 Jun 1997 13:10:38	AOONWAL
   Added "or" in Concept Damage sig to make it work

	  Rev 1.33	 25 Jun 1997 12:57:58	AOONWAL
   Added two new crc to concept damage.

	  Rev 1.32	 24 Jun 1997 19:45:14	JWILBER
   Added cheez to detect sample in CI 12355.

	  Rev 1.31	 24 Jun 1997 14:36:14	JWILBER
   Added junk to Concept.Damaged d&r for CI 12355.

	  Rev 1.30	 24 Jun 1997 13:30:00	JWILBER
   Added a NamedCRCSig to the Trashcan sig for some DZT remnant crap.
   Done for CI 12357.

	  Rev 1.29	 24 Jun 1997 12:09:24	JWILBER
   Added sig to catch mangled version of WM.Johnny for CI 12356.

	  Rev 1.28	 23 Jun 1997 18:47:46	JWILBER
   Added macros to Trashcan sig to d&r a mangled version of Cap.

	  Rev 1.27	 23 Jun 1997 15:20:36	AOONWAL
   Modified during JULY 97 build

	  Rev JULY97 18 Jun 1997 16:49:22	ECHIEN
   REMOVE repair of ScanProt's modified Concept's macro from Concept Variant
   Strengthen the signature

	  Rev JULY97 18 Jun 1997 16:13:32	RELNITI
   MODIFY Concept Damaged to use NamedCRC in detecting VISPY-damaged Concept

	  Rev JULY97 16 Jun 1997 19:31:56	RELNITI
   TYPO on CRCs

	  Rev JULY97 16 Jun 1997 18:51:50	JWILBER
   Added CRCs to Concept Damaged detection for samples with changed
   macro names.

	  Rev JULY97 16 Jun 1997 18:28:48	RELNITI
   ADD several more BLANKS damaged Concept to Concept Damaged
   ADD a trashed CAP macro to TrashCan

	  Rev 1.26	 12 Jun 1997 20:42:42	JWILBER
   Added NamedCRC sig for mangled AutoOpen macro from Kompu.A, 1e31 to
   Trashcan sig.

	  Rev 1.25	 12 Jun 1997 12:31:08	RELNITI
   ADD Macro Family detection (by macro dependency):
	ShowOff, Bandung, Rapi, Colors, Irish, Johnny
   ADD name&size repair to NPAD Var WD7 detection

	  Rev 1.24	 11 Jun 1997 19:54:22	JWILBER
   Added CRC sig to Trashcan def for a mangled ToolsMacro from
   Colors - CI 12170.

	  Rev 1.23	 11 Jun 1997 00:08:04	JWILBER
   Added sigs to Trashcan for no-name Concept macros, so variant repair
   will take care of them for CI 12165.

	  Rev 1.22	 10 Jun 1997 20:44:54	JWILBER
   Added sig for WM.Johnny Variant, VID 4d14.  This is currently
   customer-centric cheez, but will be modified for true variant
   detection later.

	  Rev 1.21	 09 Jun 1997 17:51:06	RELNITI
   ADD D&R FOR another Damaged Concept. Refer to #12029

	  Rev 1.20	 05 Jun 1997 15:15:50	RELNITI
   ADD an RPTM version of CRC_TOOLSMACRO_COLORSV into Macro Trashcan
	for #12111, #12113 where 4 RP__ macros present = non infectious

	  Rev 1.19	 05 Jun 1997 13:09:48	RELNITI
   ADD one more set of repair to Concept Variant
	special for #12095,97,98 due to ScanProt mess.

	  Rev 1.18	 02 Jun 1997 19:39:38	JWILBER
   Made changes to pick up more NPad 97 variants.

	  Rev 1.17	 02 Jun 1997 18:44:58	JWILBER
   Added Office97 detection for NPad Variants.	Works for Office97
   dumb virus, too.

	  Rev 1.16	 27 May 1997 11:23:48	AOONWAL
   Modified during JUNE97 build

	  Rev JUNE97 27 May 1997 10:24:24	RELNITI
   ADD 2 Junk NamedCRC:FileSaveAs & ToolsMacro for #11956
	it suspiciously looks like an incomplete repair (5 of 10 macros gone)

	  Rev JUNE97 22 May 1997 18:20:28	AOONWAL
   ADDED FULLSET REPAIR FOR NPAD VARIANT

	  Rev 1.15	 15 May 1997 19:51:42	RELNITI
   ADD FullSetRepair to Variant Repair (but NJ's which is still UNTESTED)

	  Rev 1.14	 14 May 1997 12:40:36	RELNITI
   ADD FullSetRepair to Colors Variant

	  Rev 1.13	 14 May 1997 11:44:54	RELNITI
   CHANGE all occurances of _BANDUNGD => _BANDUNGA

	  Rev 1.12	 12 May 1997 21:38:16	RELNITI
   ADD another Junk NamedCRC for #11921

	  Rev 1.11	 12 May 1997 20:30:36	RELNITI
   MODIFY Concept Variant Signature: remove the AUTOOPEN-only restriction

	  Rev 1.10	 09 May 1997 19:24:42	RELNITI
   ADD TrashCan for Junked WM macros, i.e. corrupted CAP, so
	this can be picked up by FullSet detection

	  Rev 1.9	08 May 1997 13:20:24   CFORMUL
   Added FullsetRepair to MDMA variant

	  Rev 1.8	08 May 1997 12:37:24   JWILBER
   Added FullSetRepair to Concept_Variant.

	  Rev 1.7	06 May 1997 19:25:40   RELNITI
   ADD FullSetRepair to Rapi Variant detection #11739

	  Rev 1.6	05 May 1997 19:03:16   RELNITI
   UNCOMMENTED Colors Remnant Detection due to #11714

	  Rev 1.5	29 Apr 1997 17:35:24   AOONWAL
   Comented out Colors Remnant signature for mid-month build

	  Rev 1.4	29 Apr 1997 16:55:00   RELNITI
   CHANGE the comment on FullSet detection since Chuck already moved it
   to the end of the file.

	  Rev 1.3	29 Apr 1997 11:42:34   CRENERT
   Moved FullSet() to the end of the file.

	  Rev 1.2	25 Apr 1997 17:06:12   AOONWAL
   Modified during MAY97 update

	  Rev MAY97  23 Apr 1997 11:36:30	ECHIEN
   Moved the Colors Remnant VID_COLORSBREMN block from wd7sigs.wdf to here

	  Rev MAY97  23 Apr 1997 00:04:26	JWILBER
   Commented out Concept.Damaged.

	  Rev 1.1	18 Apr 1997 17:51:32   AOONWAL
   Modified during DEV1 malfunction

	  Rev ABID	 14 Apr 1997 17:25:44	AOONWAL
   Modified WM.Twno.Variant signature

	  Rev ABID	 14 Apr 1997 09:14:40	RELNITI
   ADD FullSetRepair (WD7 WD8 XL97)

	  Rev 1.0	07 Apr 1997 16:45:28   CFORMUL
   Initial revision.

;
;****************************************************************************


#################################################################
#
# U n k n o w n   V i r u s   S i g n a t u r e s
#
#################################################################

#################################################################
# Unknown Macro Sigs
#################################################################

# The following is a Bandung Remnant due to a double infection
# with NPADA AutoOpen  Putting it here will ensure that it is
# only detected after any real Bandung
#[UnknownVirusSigStart]
#[Comment]		 WM.Bandung.Rem  Same as Bandung.I without AutoOpen
#[Type] 		 WD7
#[QAStatus] 	 PASSED
#[ID]			 VID_BANDUNGREM
#[Signature]	 Not NameSig(NAME_ONLY_AUTOOPEN) and
#[Signature]	 NamedCRCSig(CRC_AUTOEXEC_BANDUNGI) and
#[Signature]	 NamedCRCSig(CRC_FILESAVE_BANDUNGA) and
#[Signature]	 NamedCRCSig(CRC_FILESAVEAS_BANDUNGA) and
#[Signature]	 NamedCRCSig(CRC_TOOLSMACRO_BANDUNGA) and
#[Signature]	 NamedCRCSig(CRC_TOOLSCUSTOMIZE_BANDUNGA)
#[Repair]		 UseSignature
#[UnknownVirusSigEnd]
#

#The following two sigs MUST come after all the other Concepts' sig
# and also Nicedays'
#Moving them to UnknownVirusSig guarantees that.
#BTW, these two will be useless when we have engine-base remnant removal
#For now, it will clean up some customer issues
#
;[UnknownVirusSigStart]
;[Comment]		 WM.ConceptDamaged	 Damaged Concept jjw 25 Feb 97
;[Type] 		 WD7
;[QAStatus] 	 PASSED
;[ID]			 VID_CONDAM
;[Signature]	 (NamedCRCSig(CRC_AAAZAO_CONCEPTA) and
;[Signature]	  NamedCRCSig(CRC_AAAZFS_CONCEPTA)) or
;[Signature]	 (Not NameSig(NAME_ONLY_MACROS) and
;[Signature]	 NamedCRCSig(CRC_AUTOOPEN_CONCEPTA)) or

;[Repair]		 UseSignature,
;[Repair]		 NamedCRCSig(CRC_PAYLOAD_CONCEPTA)
;[UnknownVirusSigEnd]

;[UnknownVirusSigStart]
;[Comment]		 WM.ConceptRem		 Concept Remnant jjw 25 Feb 97
;[Type] 		 WD7
;[QAStatus] 	 PASSED
;[ID]			 VID_CONREM
;[Signature]	 NamedCRCSig(CRC_PAYLOAD_CONCEPTA)
;[Repair]		 UseSignature
;[UnknownVirusSigEnd]


# This is the home of the COLORS REMNANT
# It detects a bunch of non-infectious remnant of Colors
# ... will be USELESS when FULLSET is online
#[KnownVirusSigStart]
#[Comment]		 WM.Colors Remnant
#[Type] 		 WD7
#[QAStatus] 	 PASSED
#[ID]			 VID_COLORSBREMN
#[Signature]	 Not NameSig(NAME_ONLY_AUTOOPEN) and
#[Signature]	 NamedCRCSig(CRC_FILENEW_COLORSB) and
#[Signature]	 NamedCRCSig(CRC_MACROS_COLORSA) and
#[Signature]	 NamedCRCSig(CRC_FILESAVE_COLORSA) and
#[Signature]	 NamedCRCSig(CRC_FILEEXIT_COLORSA) and
#[Signature]	 NamedCRCSig(CRC_FILESAVEAS_COLORSA) and
#[Signature]	 (NamedCRCSig(CRC_TOOLSMACRO_COLORSA) or
#[Signature]	  NamedCRCSig(CRC_TOOLSMACRO_COLORSV))
#[Repair]		 UseSignature,
#[Repair]		 NamedCRCSig(CRC_AUTOEXEC_COLORSA),
#[Repair]		 NamedCRCSig(CRC_AUTOCLOSE_COLORSA),
#[Repair]		 NamedCRCSig(CRC_AUTOCLOSE_KOMPUA)
#[KnownVirusSigEnd]



#################################################################
#
#		  Macro Virus Family Detection by Macro Dependency
#
#################################################################

[KnownVirusSigStart]
[Comment]		Wm.Twolines.Family : D&R
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_TWOLINES_FAMILY
[Signature] 	NamedCRCSig(CRC_AUTOOPEN_TWOLINESA) or
[Signature] 	NamedCRCSig(CRC_AUTOCLOSE_TWOLINESA)
[Repair]		UseSignature,
[Repair]		NameSig(NAME_ONLY_MSRUN),
[Repair]		NameSig(NAME_ONLY_AUTOEXEC),
[Repair]		NameSig(NAME_ONLY_FILESAVEAS)
[KnownVirusSigEnd]


[KnownVirusSigStart]
[Comment]       Wm.Niceday.Family : Document Infection
[Type]			WD7
[QAStatus]		PASSED
[ID]            VID_NICEDAY_FAMILY1
#A
[Signature]     NamedCRCSig(CRC_AUTOOPEN_NICEDAY) and
[Signature]     NameSig(NAME_ONLY_VCLOSE) or
[Signature]     NameSig(NAME_ONLY_AUTOOPEN) and
[Signature]     NamedCRCSig(CRC_VCLOSE_NICEDAY) or
#G
[Signature]     NameSig(NAME_ONLY_AUTOOPEN) and
[Signature]     NamedCRCSig(CRC_VCLOSE_NICEDAYG) or
#N
[Signature]     NamedCRCSig(CRC_AUTOOPEN_NICEDAYN) and
[Signature]     NameSig(NAME_ONLY_VCLOSE) or
[Signature]     NameSig(NAME_ONLY_AUTOOPEN) and
[Signature]     NamedCRCSig(CRC_VCLOSE_NICEDAYN) or
#V
[Signature]     NamedCRCSig(CRC_AUTOOPEN_NICEDAYV) and
[Signature]     NameSig(NAME_ONLY_VCLOSE) or
[Signature]     NameSig(NAME_ONLY_AUTOOPEN) and
[Signature]     NamedCRCSig(CRC_VCLOSE_NICEDAYV)
[Repair]        NameSig(NAME_ONLY_VCLOSE),
[Repair]        NameSig(NAME_ONLY_AUTOOPEN),
[Repair]		NameSig(NAME_ONLY_AUTOEXIT),
[Repair]		NameSig(NAME_ONLY_PAYLOAD)
[KnownVirusSigEnd]

[KnownVirusSigStart]
[Comment]       Wm.Niceday.Family : Global Template Infection
[Type]			WD7
[QAStatus]		PASSED
[ID]            VID_NICEDAY_FAMILY2
#A
[Signature]     NamedCRCSig(CRC_AUTOCLOSE_NICEDAY) and
[Signature]     NameSig(NAME_ONLY_VOPEN) or
[Signature]     NameSig(NAME_ONLY_AUTOCLOSE) and
[Signature]     NamedCRCSig(CRC_VOPEN_NICEDAY) or
#G
[Signature]     NamedCRCSig(CRC_AUTOCLOSE_NICEDAYG) and
[Signature]     NameSig(NAME_ONLY_VOPEN) or
#N
[Signature]     NamedCRCSig(CRC_AUTOCLOSE_NICEDAYN) and
[Signature]     NameSig(NAME_ONLY_VOPEN) or
[Signature]     NameSig(NAME_ONLY_AUTOCLOSE) and
[Signature]     NamedCRCSig(CRC_VOPEN_NICEDAYN) or
#V
[Signature]     NamedCRCSig(CRC_AUTOCLOSE_NICEDAYV) and
[Signature]     NameSig(NAME_ONLY_VOPEN) or
[Signature]     NameSig(NAME_ONLY_AUTOCLOSE) and
[Signature]     NamedCRCSig(CRC_VOPEN_NICEDAYV)
[Repair]        NameSig(NAME_ONLY_AUTOCLOSE),
[Repair]		NameSig(NAME_ONLY_VOPEN),
[Repair]		NameSig(NAME_ONLY_AUTOEXIT),
[Repair]		NameSig(NAME_ONLY_PAYLOAD)
[KnownVirusSigEnd]


[KnownVirusSigStart]
[Comment]		WM.Colors Family : D&R based on Dependency of FileNew
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_COLORS_FAMILY
[Signature] 	NameSig(NAME_ONLY_MACROS) and
[Signature] 	(NamedCRCSig(CRC_FILENEW_COLORSA) or
[Signature] 	 NamedCRCSig(CRC_FILENEW_COLORSB) or
[Signature] 	 NamedCRCSig(CRC_AUTOOPEN_COLORSA) or
[Signature] 	 NamedCRCSig(CRC_FILEEXIT_COLORSA) or
[Signature] 	 NamedCRCSig(CRC_FILESAVE_COLORSA) or
[Signature] 	 NamedCRCSig(CRC_AUTOCLOSE_COLORSA) or
[Signature] 	 NamedCRCSig(CRC_FILESAVEAS_COLORSA) or
[Signature] 	 NamedCRCSig(CRC_TOOLSMACRO_COLORSA) or
[Signature] 	 NamedCRCSig(CRC_AUTOEXEC_COLORSA))
[Repair]		NameSig(NAME_ONLY_AUTOOPEN),
[Repair]		NameSig(NAME_ONLY_FILESAVEAS),
[Repair]		NameSig(NAME_ONLY_MACROS),
[Repair]		NameSig(NAME_ONLY_AUTOEXEC),
[Repair]		NameSig(NAME_ONLY_TOOLSMACRO),
[Repair]		NameSig(NAME_ONLY_AUTOCLOSE),
[Repair]		NameSig(NAME_ONLY_FILESAVE),
[Repair]		NameSig(NAME_ONLY_FILEEXIT),
[Repair]		NameSig(NAME_ONLY_FILENEW),
[Repair]		NameSig(NAME_ONLY_PAYLOAD),
[Repair]		CRC(0x8F2C4C07),
[Repair]		NameSig(NAME_ONLY_OFXX)
[KnownVirusSigEnd]


[KnownVirusSigStart]
[Comment]		WM.Rapi Family : D&R based on Dependency of AutoOpen
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_RAPI_FAMILY
[Signature] 	NamedCRCSig(CRC_AUTOOPEN_RAPIA)
[Repair]		NamedCRCSig(CRC_AUTOOPEN_RAPIA),
[Repair]		NameSig(NAME_ONLY_RPAE),
[Repair]		NameSig(NAME_ONLY_RPFO),
[Repair]		NameSig(NAME_ONLY_RPFS),
[Repair]		NameSig(NAME_ONLY_RPFSA),
[Repair]		NameSig(NAME_ONLY_RPTC),
[Repair]		NameSig(NAME_ONLY_RPTM)
[KnownVirusSigEnd]

[KnownVirusSigStart]
[Comment]		WM.Rapi Family : D&R based on Dependency of FileSave
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_RAPI_FAMILY2
[Signature] 	NamedCRCSig(CRC_FILESAVE_RAPIA)
[Repair]		NamedCRCSig(CRC_FILESAVE_RAPIA),
[Repair]		NameSig(NAME_ONLY_RPAE),
[Repair]		NameSig(NAME_ONLY_RPFO),
[Repair]		NameSig(NAME_ONLY_RPFS),
[Repair]		NameSig(NAME_ONLY_RPFSA),
[Repair]		NameSig(NAME_ONLY_RPAO),
[Repair]		NameSig(NAME_ONLY_AUTOEXEC),
[Repair]		NameSig(NAME_ONLY_FILEOPEN),
[Repair]		NameSig(NAME_ONLY_FILESAVEAS),
[Repair]		NameSig(NAME_ONLY_TOOLSCUSTOMIZE),
[Repair]		NameSig(NAME_ONLY_TOOLSMACRO)
[KnownVirusSigEnd]

[KnownVirusSigStart]
[Comment]		WM.Rapi Family : D&R based on Dependency of FileSaveAs
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_RAPI_FAMILY3
[Signature] 	NamedCRCSig(CRC_FILESAVEAS_RAPIA)
[Repair]		NamedCRCSig(CRC_FILESAVEAS_RAPIA),
[Repair]		NameSig(NAME_ONLY_RPAE),
[Repair]		NameSig(NAME_ONLY_RPFO),
[Repair]		NameSig(NAME_ONLY_RPFS),
[Repair]		NameSig(NAME_ONLY_RPFSA),
[Repair]		NameSig(NAME_ONLY_RPAO),
[Repair]		NameSig(NAME_ONLY_AUTOEXEC),
[Repair]		NameSig(NAME_ONLY_FILEOPEN),
[Repair]		NameSig(NAME_ONLY_FILESAVE),
[Repair]		NameSig(NAME_ONLY_TOOLSCUSTOMIZE),
[Repair]		NameSig(NAME_ONLY_TOOLSMACRO)
[KnownVirusSigEnd]

[KnownVirusSigStart]
[Comment]		WM.Rapi Family : D&R based on Dependency of FileOpen
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_RAPI_FAMILY4
[Signature] 	NamedCRCSig(CRC_FILEOPEN_RAPIA)
[Repair]		NamedCRCSig(CRC_FILEOPEN_RAPIA),
[Repair]		NameSig(NAME_ONLY_RPAE),
[Repair]		NameSig(NAME_ONLY_RPFO),
[Repair]		NameSig(NAME_ONLY_RPFS),
[Repair]		NameSig(NAME_ONLY_RPFSA),
[Repair]		NameSig(NAME_ONLY_RPAO),
[Repair]		NameSig(NAME_ONLY_AUTOEXEC),
[Repair]		NameSig(NAME_ONLY_FILESAVEAS),
[Repair]		NameSig(NAME_ONLY_FILESAVE),
[Repair]		NameSig(NAME_ONLY_TOOLSCUSTOMIZE),
[Repair]		NameSig(NAME_ONLY_TOOLSMACRO)
[KnownVirusSigEnd]


[KnownVirusSigStart]
[Comment]		WM.Bandung Family : D&R based on Dependency of AutoOpen
#									 or FileSave or FileSaveAs
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_BANDUNG_FAMILY
[Signature] 	NamedCRCSig(CRC_AUTOOPEN_BANDUNGA) or
[Signature] 	NamedCRCSig(CRC_FILESAVE_BANDUNGA) or
[Signature] 	NamedCRCSig(CRC_FILESAVEAS_BANDUNGA)
[Repair]		NameSig(NAME_ONLY_AUTOOPEN),
[Repair]		NameSig(NAME_ONLY_FILESAVE),
[Repair]		NameSig(NAME_ONLY_AUTOEXEC),
[Repair]		NameSig(NAME_ONLY_FILESAVEAS),
[Repair]		NameSig(NAME_ONLY_TOOLSMACRO),
[Repair]		NameSig(NAME_ONLY_TOOLSCUSTOMIZE)
[KnownVirusSigEnd]


[KnownVirusSigStart]
[Comment]		WM.Showoff Family : D&R based on Dependency of AutoOpen/AutoClose
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_SHOWOFF_FAMILY
[Signature] 	NamedCRCSig(CRC_AUTOOPEN_SHOWOFF) or
[Signature] 	NamedCRCSig(CRC_AUTOOPEN_SHOWOFFAD) or
[Signature] 	NamedCRCSig(CRC_AUTOOPEN_SHOWOFFBS) or
[Signature]     NamedCRCSig(CRC_AUTOOPEN_SHOWOFFCK) or
[Signature]     NamedCRCSig(CRC_AUTOOPEN_SHOWOFFCD) or
[Signature]     ((NamedCRCSig(CRC_CFXX_SHOWOFF) or
[Signature] 	  NamedCRCSig(CRC_CFXX_SHOWOFFAW) or
[Signature] 	  NamedCRCSig(CRC_CFXX_SHOWOFFBM) or
[Signature]       NamedCRCSig(CRC_CFXX_SHOWOFFBV) or
[Signature]       NamedCRCSig(CRC_CFXX_SHOWOFFCK)) and
[Signature] 	 NameSig(NAME_ONLY_AUTOOPEN))
[Repair]		NameSig(NAME_ONLY_AUTOOPEN),
[Repair]		NameSig(NAME_ONLY_CFXX),
[Repair]		NameSig(NAME_ONLY_SHOW),
[KnownVirusSigEnd]

[KnownVirusSigStart]
[Comment]		WM.Showoff Family : D&R based on Dependency of AutoOpen/AutoClose
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_SHOWOFF_FAMILY2
[Signature] 	NamedCRCSig(CRC_AUTOCLOSE_SHOWOFF) or
[Signature] 	NamedCRCSig(CRC_AUTOCLOSE_SHOWOFFAW) or
[Signature] 	NamedCRCSig(CRC_AUTOCLOSE_SHOWOFFBM) or
[Signature] 	NamedCRCSig(CRC_AUTOCLOSE_SHOWOFFBV) or
[Signature]     NamedCRCSig(CRC_AUTOCLOSE_SHOWOFFCK) or
[Signature]     ((NamedCRCSig(CRC_OFXX_SHOWOFF) or
[Signature] 	  NamedCRCSig(CRC_OFXX_SHOWOFFAD) or
[Signature]       NamedCRCSig(CRC_OFXX_SHOWOFFBS) or
[Signature]       NamedCRCSig(CRC_OFXX_SHOWOFFCD) or
[Signature]       NamedCRCSig(CRC_OFXX_SHOWOFFCK)) and
[Signature] 	 NameSig(NAME_ONLY_AUTOCLOSE))
[Repair]		NameSig(NAME_ONLY_AUTOCLOSE),
[Repair]		NameSig(NAME_ONLY_OFXX),
[Repair]		NameSig(NAME_ONLY_AUTOEXEC)
[KnownVirusSigEnd]


[KnownVirusSigStart]
[Comment]		WM.Irish Variant : D&R based on Dependency of AutoOpen
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_IRISH_FAMILY
[Signature] 	NamedCRCSig(CRC_AUTOOPEN_IRISH) and
[Signature] 	NameSig(NAME_ONLY_ANTIVIRUS)
[Repair]		NameSig(NAME_ONLY_AUTOOPEN),
[Repair]		NameSig(NAME_ONLY_ANTIVIRUS),
[Repair]		NameSig(NAME_ONLY_WORDHELP),
[Repair]		NameSig(NAME_ONLY_WORDHELPNT)
[KnownVirusSigEnd]

[KnownVirusSigStart]
[Comment]		WM.Irish Variant : D&R based on Dependency of FileSave
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_IRISH_FAMILY2
[Signature] 	NamedCRCSig(CRC_FILESAVE_IRISH) and
[Signature] 	NameSig(NAME_ONLY_ANTIVIRUS)
[Repair]		NameSig(NAME_ONLY_FILESAVE),
[Repair]		NameSig(NAME_ONLY_ANTIVIRUS),
[Repair]		NameSig(NAME_ONLY_WORDHELP),
[Repair]		NameSig(NAME_ONLY_WORDHELPNT)
[KnownVirusSigEnd]

[NamedCRCSigStart]
[Comment]
[ID]				CRC_FILESAVEAS_JOHNNYMANGLE
[CRCWD7]			0x0abe19d5
[Signature] 		NameSig(NAME_ONLY_FILESAVEAS)
[NamedCRCSigEnd]

[KnownVirusSigStart]
[Comment]		WM.Johnny Family
# used to be cheeze detection to remove a remnant of FileSaveAs
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_JOHNNY_VARIANT
[Signature] 	NamedCRCSig(CRC_AUTOOPEN_JOHNNY) or
[Signature] 	NamedCRCSig(CRC_AUTOOPEN_JOHNNYB) or
[Signature] 	NamedCRCSig(CRC_FILESAVE_JOHNNY) or
[Signature] 	NamedCRCSig(CRC_FILESAVE_JOHNNYB) or
[Signature] 	NamedCRCSig(CRC_FILESAVEAS_JOHNNY) or
[Signature] 	NamedCRCSig(CRC_FILESAVEAS_JOHNNYB) or
[Signature] 	NamedCRCSig(CRC_FILESAVEAS_JOHNNYMANGLE) or
[Signature] 	(NamedCRCSig(CRC_PRESENTZ_JOHNNY) and
[Signature] 	 NameSig(NAME_ONLY_AUTOOPEN)) or
[Signature] 	(NamedCRCSig(CRC_PRESENTW_JOHNNY) and
[Signature] 	 NameSig(NAME_ONLY_AUTOOPEN)) or
[Signature] 	(NamedCRCSig(CRC_PRESENTV_JOHNNY) and
[Signature] 	 (NameSig(NAME_ONLY_FILESAVE) or
[Signature] 	  NameSig(NAME_ONLY_FILESAVEAS)))
[Repair]		NameSig(NAME_ONLY_FILESAVEAS),
[Repair]		NameSig(NAME_ONLY_FILESAVE),
[Repair]		NameSig(NAME_ONLY_AUTOOPEN),
[Repair]		NameSig(NAME_ONLY_PRESENTV),
[Repair]		NameSig(NAME_ONLY_PRESENTW),
[Repair]		NameSig(NAME_ONLY_PRESENTZ),
[Repair]		NameSig(NAME_ONLY_VGOJOHNNY)
[KnownVirusSigEnd]


[MacroSigStart]
[Comment]		CAP Macro sig on S$ = "F%" and MacroCopy B$ , F$ + ":"
[ID]			CAP_VARIANT
[Signature] 	SeekSet(224) NameSig(NAME_ONLY_CAP) Size(=2348)
[Signature]     0x53 0x24 0x0C 0x6A 0x02 0x46 0x25 SeekSet(1930)
[Signature]     ScanString(5, 0x67) 0xC2 0x80 0x69 0x02 0x42 0x24 0x12 0x69 0x02
[Signature] 	0x46 0x24 0x07 0x6A 0x01 0x3A 0x07 0x69 0x02 0x42
[Signature] 	0x24 0x12 0x69 0x01 0x4B
[MacroSigEnd]

[MacroSigStart]
[Comment]		CAP Macro sig on  MacroCopy B$ , F$ + ":" and SUB FSA
[ID]			CAP_VARIANT2
[Signature] 	SeekSet(1934) NameSig(NAME_ONLY_CAP) Size(=2348)
[Signature] 	0x67 0xC2 0x80 0x69 0x02 0x42 0x24 0x12 0x69 0x02
[Signature] 	0x46 0x24 0x07 0x6A 0x01 0x3A 0x07 0x69 0x02 0x42
[Signature] 	0x24 0x12 0x69 0x01 0x4B SeekSet(2132)
[Signature] 	0x1B 0x69 0x03 "FSA"
[MacroSigEnd]

[KnownVirusSigStart]
[Comment]			Wm.Cap.Family
[Type]				WD7
[QAStatus]			PASSED
[ID]				VID_CAP_FAMILY
[Signature] 		MacroSig(CAP_VARIANT) or
[Signature] 		MacroSig(CAP_VARIANT2)
[Repair]			UseOtherRepair(VID_CAPA)
[KnownVirusSigEnd]


[KnownVirusSigStart]
[Comment]		WM.Muck Family : D&R based on Dependency of AutoOpen
[Type]          WD7 WD8
[QAStatus]		PASSED
[ID]			VID_MUCK_FAMILY1
[Signature] 	NamedCRCSig(CRC_AUTOOPEN_MUCKA) or
[Signature] 	NamedCRCSig(CRC_AUTOOPEN_MUCKF)
[Repair]		NameSig(NAME_ONLY_AUTOOPEN),
[Repair]		NameSig(NAME_ONLY_FILESAVEAS),
[Repair]		NameSig(NAME_ONLY_FILESAVE),
[Repair]		NameSig(NAME_ONLY_AUTOCLOSE),
[Repair]		NameSig(NAME_ONLY_AUTOEXIT),
[Repair]		NameSig(NAME_ONLY_AUTONEW)
[KnownVirusSigEnd]

[KnownVirusSigStart]
[Comment]		WM.Muck Family : D&R based on Dependency of FileSave
[Type]          WD7 WD8
[QAStatus]		PASSED
[ID]			VID_MUCK_FAMILY2
[Signature] 	NamedCRCSig(CRC_FILESAVE_MUCKA) or
[Signature] 	NamedCRCSig(CRC_FILESAVE_MUCKF)
[Repair]		UseOtherRepair(VID_MUCK_FAMILY1)
[KnownVirusSigEnd]

[KnownVirusSigStart]
[Comment]		WM.Muck Family : D&R based on Dependency of FileSaveAs
[Type]          WD7 WD8
[QAStatus]		PASSED
[ID]			VID_MUCK_FAMILY3
[Signature] 	NamedCRCSig(CRC_FILESAVEAS_MUCKA) or
[Signature] 	NamedCRCSig(CRC_FILESAVEAS_MUCKF)
[Repair]		UseOtherRepair(VID_MUCK_FAMILY1)
[KnownVirusSigEnd]


[KnownVirusSigStart]
[Comment]		WM.Switcher Family : D&R based on Dependency of AutoClose
#All the infection routine is in AutoClose
#Other macros simply call the subfunction of AutoClose that does infection
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_SWITCHER_FAMILY
[Signature]     NamedCRCSig(CRC_AUTOCLOSE_SWITCHERA) or
[Signature]     NamedCRCSig(CRC_AUTOCLOSE_SWITCHERG) or
[Signature]     NamedCRCSig(CRC_AUTOCLOSE_SWITCHERK)
[Repair]		NameSig(NAME_ONLY_AUTOEXEC),
[Repair]		NameSig(NAME_ONLY_AUTOOPEN),
[Repair]		NameSig(NAME_ONLY_FILEOPEN),
[Repair]		NameSig(NAME_ONLY_FILESAVE),
[Repair]		NameSig(NAME_ONLY_AUTOCLOSE),
[Repair]		NameSig(NAME_ONLY_FILECLOSE),
[Repair]		NameSig(NAME_ONLY_FILEPRINT),
[Repair]		NameSig(NAME_ONLY_FILESAVEAS),
[Repair]		NameSig(NAME_ONLY_TOOLSMACRO),
[Repair]		NameSig(NAME_ONLY_FILETEMPLATES)
[KnownVirusSigEnd]

[MacroSigStart]
[Comment]
[ID]			MACROCOPY_DNTC
[Signature] 	0xC2 0x80 SeekCur(-3) 0x67 ScanString(0x30, "DNTC")
[MacroSigEnd]

[KnownVirusSigStart]
[Comment]		WM.DNTC Family a.k.a. WM.Concept.BB Family
#All infection routine has "MacroCopy ... DNTC"
#at least one variant has modified code (added message box)
#most variant by macro-snatching or corruption
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_DNTC_FAMILY
[Signature] 	MacroSig(MACROCOPY_DNTC)
[Repair]		NameSig(NAME_ONLY_DNTC),
[Repair]		NameSig(NAME_ONLY_AUTOOPEN),
[Repair]		NameSig(NAME_ONLY_FS),
[Repair]		NameSig(NAME_ONLY_FILESAVE),
[Repair]		NameSig(NAME_ONLY_AC),
[Repair]		NameSig(NAME_ONLY_AUTOCLOSE),
[Repair]		NameSig(NAME_ONLY_FSA),
[Repair]		NameSig(NAME_ONLY_FILESAVEAS),
[Repair]		NameSig(NAME_ONLY_FO),
[Repair]		NameSig(NAME_ONLY_FILEOPEN)
[KnownVirusSigEnd]

[KnownVirusSigStart]
[Comment]       WM.Anak Family
[Type]          WD7
[QAStatus]      PASSED
[ID]            VID_ANAK_FAMILY
[Signature]     NamedCRCSig(CRC_FILESAVE_ANAKA) or
[Signature]     NamedCRCSig(CRC_AUTOOPEN_ANAKA) or
[Signature]     (NamedCRCSig(CRC_ANAKAO_ANAKA) and
[Signature]      NameSig(NAME_ONLY_FILESAVE)) or
[Signature]     (NamedCRCSig(CRC_ANAKSA_ANAKA) and
[Signature]      NameSig(NAME_ONLY_AUTOOPEN))
[Repair]        NameSig(NAME_ONLY_ANAKAE),
[Repair]        NameSig(NAME_ONLY_ANAKAO),
[Repair]        NameSig(NAME_ONLY_ANAKSA),
[Repair]        NameSig(NAME_ONLY_ANAKSMU),
[Repair]        NameSig(NAME_ONLY_AUTOOPEN),
[Repair]        NameSig(NAME_ONLY_AUTOEXEC),
[Repair]        NameSig(NAME_ONLY_FILESAVE)
[KnownVirusSigEnd]

[KnownVirusSigStart]
[Comment]       Wm.Hybrid Family
[Type]          WD7
[QAStatus]      PASSED
[ID]            VID_HYBRID_FAMILY
[Signature]     NamedCRCSig(CRC_FILESAVEAS_HYBRID) and
[Signature]     NamedCRCSig(CRC_AUTOOPEN_HYBRID) and
[Signature]     NameSig(NAME_ONLY_AUTOCLOSE)
[Repair]        UseSignature
[KnownVirusSigEnd]


[KnownVirusSigStart]
[Comment]       WM.Goodnight Family
[Type]          WD7
[QAStatus]      PASSED
[ID]            VID_GOODNIGHTFAM
[Signature]     NameSig(NAME_ONLY_AUTOEXEC) and
[Signature]     NameSig(NAME_ONLY_AUTOEXIT) and
[Signature]     NameSig(NAME_ONLY_AUTOCLOSE) and
[Signature]     NameSig(NAME_ONLY_FILECLOSE) and
[Signature]     NameSig(NAME_ONLY_FILECLOSEALL) and
[Signature]     NameSig(NAME_ONLY_FILESAVE) and
[Signature]     (NamedCRCSig(CRC_FILECLOSEALL_GOODNIGHT) or
[Signature]      NamedCRCSig(CRC_FILECLOSEALL_GOODNIGHTE) or
[Signature]      NamedCRCSig(CRC_FILECLOSEALL_GOODNIGHTI) or
[Signature]      NamedCRCSig(CRC_FILECLOSE_GOODNIGHT) or
[Signature]      NamedCRCSig(CRC_AUTOCLOSE_GOODNIGHT) or
[Signature]      NamedCRCSig(CRC_AUTOCLOSE_GOODNIGHTI) or
[Signature]      NamedCRCSig(CRC_AUTOCLOSE_GOODNIGHTK) or
[Signature]      NamedCRCSig(CRC_AUTOCLOSE_GOODNIGHTM) or
[Signature]      NamedCRCSig(CRC_FILESAVE_GOODNIGHT) or
[Signature]      NamedCRCSig(CRC_FILESAVE_GOODNIGHTI))
[Repair]        UseSignature,
[Repair]        NameSig(NAME_ONLY_FILESAVEAS),
[Repair]		NameSig(NAME_ONLY_FILEOPEN),
[Repair]		NameSig(NAME_ONLY_AUTOOPEN),
[Repair]		NameSig(NAME_ONLY_EXIT)
[KnownVirusSigEnd]


;NamedCRCsig(CRC_AUTOEXIT_GOODNIGHT_CORRUPT) is used to make
;it compile and be part of FULL_SET
[KnownVirusSigStart]
[Comment]       WM.Goodnight Family
[Type]          WD8
[QAStatus]      PASSED
[ID]            VID_GOODNIGHTFAM
[Signature]     NameSig(NAME_ONLY_AUTOEXEC) and
[Signature]     NameSig(NAME_ONLY_AUTOEXIT) and
[Signature]     NameSig(NAME_ONLY_AUTOCLOSE) and
[Signature]     NameSig(NAME_ONLY_FILECLOSE) and
[Signature]     NameSig(NAME_ONLY_FILECLOSEALL) and
[Signature]     NameSig(NAME_ONLY_FILESAVE) and
[Signature]     (NamedCRCSig(CRC_FILECLOSEALL_GOODNIGHT) or
[Signature]      NamedCRCSig(CRC_FILECLOSEALL_GOODNIGHTI) or
[Signature]      NamedCRCSig(CRC_FILECLOSE_GOODNIGHT) or
[Signature]      NamedCRCSig(CRC_AUTOCLOSE_GOODNIGHT) or
[Signature]      NamedCRCSig(CRC_AUTOCLOSE_GOODNIGHTI) or
[Signature]      NamedCRCSig(CRC_AUTOCLOSE_GOODNIGHTM) or
[Signature]      NamedCRCSig(CRC_FILESAVE_GOODNIGHT) or
[Signature]      NamedCRCSig(CRC_FILESAVE_GOODNIGHTI))
[Repair]        UseSignature,
[Repair]        NameSig(NAME_ONLY_FILESAVEAS),
[Repair]		NameSig(NAME_ONLY_FILEOPEN),
[Repair]		NameSig(NAME_ONLY_AUTOOPEN),
[Repair]        NameSig(NAME_ONLY_EXIT),
[Repair]        NamedCRCSig(CRC_AUTOEXIT_GOODNIGHT_CORRUPT)
[KnownVirusSigEnd]


[KnownVirusSigStart]
[Comment]       Wm.Appder Family
[Type]          WD7
[QAStatus]      PASSED
[ID]            VID_APPDER_FAMILY
[Signature]     NameSig(NAME_ONLY_APPDER) and
[Signature]     (NamedCRCSig(CRC_AUTOCLOSE_APPDER) or
[Signature]      NamedCRCSig(CRC_AUTOCLOSE_APPDERD) or
[Signature]      NamedCRCSig(CRC_AUTOCLOSE_APPDERG) or
[Signature]      NamedCRCSig(CRC_AUTOCLOSE_APPDERI))
[Repair]        NameSig(NAME_ONLY_APPDER),
[Repair]        NameSig(NAME_ONLY_AUTOCLOSE),
[Repair]        NameSig(NAME_ONLY_AUTOOPEN)
[KnownVirusSigEnd]

[KnownVirusSigStart]
[Comment]       Wm.Appder Family
[Type]          WD8
[QAStatus]      PASSED
[ID]            VID_APPDER_FAMILY
[Signature]     NameSig(NAME_ONLY_APPDER) and
[Signature]     (NamedCRCSig(CRC_AUTOCLOSE_APPDER) or
[Signature]      NamedCRCSig(CRC_AUTOCLOSE_APPDER13051) or
[Signature]      NamedCRCSig(CRC_AUTOCLOSE_APPDERD) or
[Signature]      NamedCRCSig(CRC_AUTOCLOSE_APPDERI))
[Repair]        NameSig(NAME_ONLY_APPDER),
[Repair]        NameSig(NAME_ONLY_AUTOCLOSE),
[Repair]        NameSig(NAME_ONLY_AUTOOPEN)
[KnownVirusSigEnd]

[KnownVirusSigStart]
[Comment]       Wm.Appder Family
[Type]          WD7
[QAStatus]      PASSED
[ID]            VID_APPDER_FAMILY2
[Signature]     NameSig(NAME_ONLY_AUTOCLOSE) and
[Signature]     (NamedCRCSig(CRC_APPDER_APPDER) or
[Signature]      NamedCRCSig(CRC_APPDER_APPDERB) or
[Signature]      NamedCRCSig(CRC_APPDER_APPDERC) or
[Signature]      NamedCRCSig(CRC_APPDER_APPDERD) or
[Signature]      NamedCRCSig(CRC_APPDER_APPDERE) or
[Signature]      NamedCRCSig(CRC_APPDER_APPDERF) or
[Signature]      NamedCRCSig(CRC_APPDER_APPDERG) or
[Signature]      NamedCRCSig(CRC_APPDER_APPDERH) or
[Signature]      NamedCRCSig(CRC_APPDER_APPDERI) or
[Signature]      NamedCRCSig(CRC_APPDER_APPDERJ))
[Repair]        NameSig(NAME_ONLY_APPDER),
[Repair]        NameSig(NAME_ONLY_AUTOCLOSE),
[Repair]        NameSig(NAME_ONLY_AUTOOPEN)
[KnownVirusSigEnd]

[KnownVirusSigStart]
[Comment]       Wm.Appder Family
[Type]          WD8
[QAStatus]      PASSED
[ID]            VID_APPDER_FAMILY2
[Signature]     NameSig(NAME_ONLY_AUTOCLOSE) and
[Signature]     (NamedCRCSig(CRC_APPDER_APPDER) or
[Signature]      NamedCRCSig(CRC_APPDER_APPDERB) or
[Signature]      NamedCRCSig(CRC_APPDER_APPDERC) or
[Signature]      NamedCRCSig(CRC_APPDER_APPDERD) or
[Signature]      NamedCRCSig(CRC_APPDER_APPDERE) or
#[Signature]      NamedCRCSig(CRC_APPDER_APPDERF) or
#[Signature]      NamedCRCSig(CRC_APPDER_APPDERG) or
#[Signature]      NamedCRCSig(CRC_APPDER_APPDERH) or
[Signature]      NamedCRCSig(CRC_APPDER_APPDERI) or
[Signature]      NamedCRCSig(CRC_APPDER_APPDERJ))
[Repair]        NameSig(NAME_ONLY_APPDER),
[Repair]        NameSig(NAME_ONLY_AUTOCLOSE),
[Repair]        NameSig(NAME_ONLY_AUTOOPEN)
[KnownVirusSigEnd]


[KnownVirusSigStart]
[Comment]       Wm.Temple Family based on AutoOpen (DOC infection)
[Type]          WD7
[QAStatus]      PASSED
[ID]            VID_TEMPLE_FAMILY1
[Signature]     NamedCRCSig(CRC_AUTOOPEN_TEMPLEA) and
[Signature]     NameSig(NAME_ONLY_TEMPFILESAVE) and
[Signature]     NameSig(NAME_ONLY_TEMPFILEOPEN) and
[Signature]     NameSig(NAME_ONLY_TEMPAUTOEXEC)
[Repair]        UseSignature
[KnownVirusSigEnd]

[KnownVirusSigStart]
[Comment]       Wm.Temple Family based on FileSave
[Type]          WD7
[QAStatus]      PASSED
[ID]            VID_TEMPLE_FAMILY2
[Signature]     NamedCRCSig(CRC_FILESAVE_TEMPLEA) and
[Signature]     NameSig(NAME_ONLY_FILEOPEN) and
[Signature]     NameSig(NAME_ONLY_AUTOEXEC) and
[Signature]     NameSig(NAME_ONLY_TEMPAUTOOPEN)
[Repair]        UseSignature
[KnownVirusSigEnd]

[KnownVirusSigStart]
[Comment]       Wm.Temple Family based on FileOpen
[Type]          WD7
[QAStatus]      PASSED
[ID]            VID_TEMPLE_FAMILY3
[Signature]     NamedCRCSig(CRC_FILEOPEN_TEMPLEA) and
[Signature]     NameSig(NAME_ONLY_FILESAVE) and
[Signature]     NameSig(NAME_ONLY_AUTOEXEC) and
[Signature]     NameSig(NAME_ONLY_TEMPAUTOOPEN)
[Repair]        UseSignature
[KnownVirusSigEnd]


[KnownVirusSigStart]
[Comment]       Wm.Niknat Family based on AutoClose (DOC infection)
[Type]          WD7
[QAStatus]      PASSED
[ID]            VID_NIKNAT_FAMILY1
//even with AutoClose and TcloseAN only, it is still infectious
[Signature]     NamedCRCSig(CRC_AUTOCLOSE_NIKNATA) and
[Signature]     NameSig(NAME_ONLY_TCLOSEAN) or
[Signature]     NamedCRCSig(CRC_TCLOSEAN_NIKNATA) and
[Signature]     NameSig(NAME_ONLY_AUTOCLOSE)
[Repair]        NameSig(NAME_ONLY_EVAHZG),
[Repair]        NameSig(NAME_ONLY_AUTOCLOSE),
[Repair]        NameSig(NAME_ONLY_TCLOSEAN),
[Repair]        NameSig(NAME_ONLY_TOOLSMACRO),
[Repair]        NameSig(NAME_ONLY_FILETEMPLATES)
[KnownVirusSigEnd]

[KnownVirusSigStart]
[Comment]       Wm.Niknat Family based on AutoClose (GLOBAL infection)
[Type]          WD7
[QAStatus]      PASSED
[ID]            VID_NIKNAT_FAMILY2
//even with AutoClose and DcloseAN only, it is still infectious
[Signature]     NamedCRCSig(CRC_AUTOCLOSE1_NIKNATA) and
[Signature]     NameSig(NAME_ONLY_DCLOSEAN) or
[Signature]     NamedCRCSig(CRC_DCLOSEAN_NIKNATA) and
[Signature]     NameSig(NAME_ONLY_AUTOCLOSE)
[Repair]        NameSig(NAME_ONLY_EVAHZG),
[Repair]        NameSig(NAME_ONLY_AUTOCLOSE),
[Repair]        NameSig(NAME_ONLY_DCLOSEAN),
[Repair]        NameSig(NAME_ONLY_TOOLSMACRO),
[Repair]        NameSig(NAME_ONLY_FILETEMPLATES)
[KnownVirusSigEnd]


[KnownVirusSigStart]
[Comment]       Wm,PayCheck Family based on AutoOpen (DOC infection)
[Type]          WD7
[QAStatus]      PASSED
[ID]            VID_PAYCHECK_FAMILY
[Signature]     (NamedCRCSig(CRC_AUTOOPEN_PAYCHECKA) or
[Signature]      NamedCRCSig(CRC_AUTOOPEN_PAYCHECKG) or
[Signature]      NamedCRCSig(CRC_FILESAVE_PAYCHECKG) or
[Signature]      NamedCRCSig(CRC_FILESAVE_PAYCHECKA)) and
[Signature]     NameSig(NAME_ONLY_AUTOEXEC)
[Repair]        NameSig(NAME_ONLY_AUTOOPEN),
[Repair]        NameSig(NAME_ONLY_AUTOEXEC),
[Repair]        NameSig(NAME_ONLY_FILESAVE),
[Repair]        NameSig(NAME_ONLY_FILESAVEAS),
[Repair]        NameSig(NAME_ONLY_TOOLSMACRO),
[Repair]        NameSig(NAME_ONLY_SHELLOPEN),
[Repair]        NameSig(NAME_ONLY_FILEOPEN),
[Repair]        NameSig(NAME_ONLY_FILETEMPLATES)
[KnownVirusSigEnd]

[KnownVirusSigStart]
[Comment]       Wm.Concept.I Family based on Concept.I DocClose
[Type]          WD7
[QAStatus]      PASSED
[ID]            VID_CONCEPTI_FAMILY
[Signature]     NamedCRCSig(CRC_DOCCLOSE_CONCEPTI) and
[Signature]     NameSig(NAME_ONLY_CEPAYLOAD)
[Repair]        UseSignature,
[Repair]        NameSig(NAME_ONLY_AAACBCAD0),
[Repair]        NameSig(NAME_ONLY_AAAD9DBD2),
[Repair]        NameSig(NAME_ONLY_TOOLSSPELLING)
[KnownVirusSigEnd]

[KnownVirusSigStart]
[Comment]       WM.Concept.Z family based on AutoOpen
[Type]          WD7
[QAStatus]      PASSED
[ID]            VID_CONCEPTZ_FAMILY1
[Signature]     NamedCRCSig(CRC_AUTOOPEN_CONCEPTZ)
[Repair]        NameSig(NAME_ONLY_AUTOOPEN),
[Repair]        NameSig(NAME_ONLY_AAAAAD),
[Repair]        NameSig(NAME_ONLY_AAAAAC),
[Repair]        NameSig(NAME_ONLY_AAAAAB)
[KnownVirusSigEnd]

[KnownVirusSigStart]
[Comment]       WM.Concept.Z family based on FileSave or FileSaveAs
[Type]          WD7
[QAStatus]      PASSED
[ID]            VID_CONCEPTZ_FAMILY2
[Signature]     NamedCRCSig(CRC_FILESAVE_CONCEPTZ) or
[Signature]     NamedCRCSig(CRC_FILESAVEAS_CONCEPTZ)
[Repair]        NameSig(NAME_ONLY_FILESAVE),
[Repair]        NameSig(NAME_ONLY_FILESAVEAS),
[Repair]        NameSig(NAME_ONLY_TOOLSMACRO),
[Repair]        NameSig(NAME_ONLY_AAAAAA)
[KnownVirusSigEnd]


# These are for a non-infectious Concept variant for CI 12165, 12201
[NamedCRCSigStart]
[Comment]
[ID]				CRC_6_BLANK
[CRCWD7]			0xF9188E50
[Signature] 		NameSig(NAME_6_BLANK)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Concept Variant: <6 Blanks>
[ID]				CRC_6BLANKA_CONCEPTVARIANT
[CRCWD7]			0xcafe3e91
[Signature] 		NameSig(NAME_6_BLANK)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Concept Variant: <6 Blanks>
[ID]				CRC_6BLANKB_CONCEPTVARIANT
[CRCWD7]			0x5dc3acb3
[Signature] 		NameSig(NAME_6_BLANK)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Concept Variant: <6 Blanks)
[ID]				CRC_6BLANKC_CONCEPTVARIANT
[CRCWD7]			0x5aabcd81
[Signature] 		NameSig(NAME_6_BLANK)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Concept Variant: <6 Blanks)
[ID]				CRC_6BLANKD_CONCEPTVARIANT
[CRCWD7]			0x1ED9F36B
[Signature] 		NameSig(NAME_6_BLANK)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Concept Variant: <6 Blanks)
[ID]				CRC_6BLANKE_CONCEPTVARIANT
[CRCWD7]			0xA77D1870
[Signature] 		NameSig(NAME_6_BLANK)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]
[ID]				CRC_6BLANKF_CONCEPTVARIANT
[CRCWD7]			0x5A6415C1
[Signature] 		NameSig(NAME_6_BLANK)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]
[ID]				CRC_6BLANKG_CONCEPTVARIANT
[CRCWD7]			0x390403DD
[Signature] 		NameSig(NAME_6_BLANK)
[NamedCRCSigEnd]


[NamedCRCSigStart]
[Comment]			WM.Concept_Variant: <7 Blanks> Same as PAYLOAD_CONCEPTA
[ID]				CRC_7BLANK_CONCEPTVARIANT
[CRCWD7]			0x17bbf5d7
[Signature] 		NameSig(NAME_7_BLANK)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]
[ID]				CRC_8_BLANK
[CRCWD7]			0x5A6415C1
[Signature] 		NameSig(NAME_8_BLANK)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Concept Variant: <8 Blanks>
[ID]				CRC_8BLANK_CONCEPTVARIANT
[CRCWD7]			0x5aabcd81
[Signature] 		NameSig(NAME_8_BLANK)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Concept Variant: <8 Blanks>
[ID]				CRC_8BLANKB_CONCEPTVARIANT
[CRCWD7]			0xC9DF1FD9
[Signature] 		NameSig(NAME_8_BLANK)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Concept Variant: <8 Blanks>
[ID]				CRC_9BLANK_CONCEPTVARIANT
[CRCWD7]			0xfc674ce1
[Signature] 		NameSig(NAME_9_BLANK)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Concept Variant: VIRUS...
[ID]				CRC_VIRUS_CONCEPTVARIANT1
[CRCWD7]			0x8E6C5538
[Signature] 		NameSig(NAME_START_VIRUS)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Concept Variant: VISPY...
[ID]				CRC_VISPY_CONCEPTVARIANT2
[CRCWD7]			0xADEB2750
[Signature] 		NameSig(NAME_START_VISPY)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Concept Variant: VIRUS...
[ID]				CRC_VIRUS_CONCEPTVARIANT2
[CRCWD7]			0xADEB2750
[Signature] 		NameSig(NAME_START_VIRUS)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Concept Variant: VISPY...
[ID]				CRC_VISPY_CONCEPTVARIANT3
[CRCWD7]			0x17BBF5D7
[Signature] 		NameSig(NAME_START_VISPY)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Concept Variant: <ANYNAME>
[ID]				CRC_ANY_CONCEPTVARIANT3
[CRCWD7]			0x17BBF5D7
[Signature] 		NameSig(NAME_ANY_NAME)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Concept Variant: VISPY...
[ID]				CRC_VISPY_CONCEPTVARIANT4
[CRCWD7]			0x052F609F
[Signature] 		NameSig(NAME_START_VISPY)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Concept Variant: <ANYNAME>
[ID]				CRC_ANY_CONCEPTVARIANT4
[CRCWD7]			0x0933749e
[Signature] 		NameSig(NAME_ANY_NAME)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Concept Variant: <ANYNAME>
[ID]				CRC_ANY_CONCEPTVARIANT5
[CRCWD7]			0x6986baf5
[Signature] 		NameSig(NAME_ANY_NAME)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Concept Variant: <ANYNAME>
[ID]				CRC_ANY_CONCEPTVARIANT6
[CRCWD7]			0x9b287498
[Signature] 		NameSig(NAME_ANY_NAME)
[NamedCRCSigEnd]

[KnownVirusSigStart]
[Comment]		Damaged Concept.A: blanked name, refer to case #12029, 12182
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_CONDAM
[Signature] 	NamedCRCSig(CRC_6_BLANK) or
[Signature] 	NamedCRCSig(CRC_6BLANKA_CONCEPTVARIANT) or
[Signature] 	NamedCRCSig(CRC_6BLANKB_CONCEPTVARIANT) or
[Signature] 	NamedCRCSig(CRC_6BLANKC_CONCEPTVARIANT) or
[Signature] 	NamedCRCSig(CRC_6BLANKD_CONCEPTVARIANT) or
[Signature] 	NamedCRCSig(CRC_6BLANKE_CONCEPTVARIANT) or
[Signature] 	NamedCRCSig(CRC_6BLANKF_CONCEPTVARIANT) or
[Signature] 	NamedCRCSig(CRC_6BLANKG_CONCEPTVARIANT) or
[Signature] 	NamedCRCSig(CRC_7BLANK_CONCEPTVARIANT) or
[Signature] 	NamedCRCSig(CRC_8_BLANK) or
[Signature] 	NamedCRCSig(CRC_8BLANK_CONCEPTVARIANT) or
[Signature] 	NamedCRCSig(CRC_8BLANKB_CONCEPTVARIANT) or
[Signature] 	NamedCRCSig(CRC_9BLANK_CONCEPTVARIANT) or
[Signature] 	CRC(0xF9188E50) or
[Signature] 	NamedCRCSig(CRC_VIRUS_CONCEPTVARIANT1) or
[Signature] 	NamedCRCSig(CRC_VIRUS_CONCEPTVARIANT2) or
[Signature] 	NamedCRCSig(CRC_ANY_CONCEPTVARIANT3) or
[Signature] 	NamedCRCSig(CRC_VISPY_CONCEPTVARIANT2) or
[Signature] 	NamedCRCSig(CRC_VISPY_CONCEPTVARIANT3) or
[Signature] 	NamedCRCSig(CRC_VISPY_CONCEPTVARIANT4) or
[Signature] 	NamedCRCSig(CRC_ANY_CONCEPTVARIANT4) or
[Signature] 	NamedCRCSig(CRC_ANY_CONCEPTVARIANT5) or
[Signature] 	NamedCRCSig(CRC_ANY_CONCEPTVARIANT6) or
[Signature] 	CRC(0x0933749e) or
[Signature] 	CRC(0x6986baf5) or
[Signature] 	CRC(0x17bbf5d7) or
[Signature] 	CRC(0x9b287498) or
[Signature] 	CRC(0x5d31d4ce) or
[Signature] 	CRC(0xadeb2750)
[Repair]		UseSignature
[KnownVirusSigEnd]

#
# NPAD Variants
#

# Sigs on 'SetProfileString("Compatibility", "Npad328", JAkses$)',
# then 'If Encrypt <> 0 Then MacroCopy'

[MacroSigStart]
[Comment]		NPAD is always in one macro - AutoOpen
[ID]			NPAD_VARIANT
[Signature] 	SeekSet(284) NameSig(NAME_ONLY_AUTOOPEN)
[Signature] 	ScanString(296, 0x67 0x46 0x80 0x05 0x6a) 0x0d
[Signature] 	"Compatibility" 0x12 0x6a HotByteSkip() 0x12 0x69
[Signature] 	ScanString(285, 0x52 0x1d 0x69) HotByteSkip()
[Signature] 	0x0d 0x6c 0x00 0x00 0x1e 0x64 0x6f 0x02 0x67 0xc2 0x80
[MacroSigEnd]

[MacroSigStart]
[Comment]		NPAD AutoOpen w/ size = 1831
[ID]			NPAD_AUTOOPEN_1831
[Signature] 	SeekSet(0) Size(=1831)
[Signature] 	NameSig(NAME_ONLY_AUTOOPEN)
[NotFullSet]
[MacroSigEnd]

# Office 97 Variant Detection

[MacroSigStart]
[Comment]		NPAD is always in one macro - AutoOpen
[ID]			NPAD_VARIANT97
[Signature] 	SeekSet(427) NameSig(NAME_ONLY_AUTOOPEN)
[Signature] 	ScanString(338, "Compa")
[Signature] 	ScanString(338, 0x22 "NPad") "328" 0x22
[Signature] 	ScanString(338, "JAkse") "s$" SeekSet(752)
[Signature] 	ScanString(550, "If En") "crypt <> 0"
[MacroSigEnd]

#
# Nuclear Variants
#

# Trigger Detection

[MacroSigStart]
[Comment]		Sigs on If Second(Now()) > ?? Then EndOfDocument Insert
[ID]			NUCLEAR_VARIANT0
[Signature] 	0x1d 0x67 0xff 0x80 0x05 0x67 0xf7 0x80 0x05 0x06 0x06 0x0f
[Signature] 	0x6c SeekCur(2) 0x1e ScanString(0x80, 0x67 0x11 0xc0)
[Signature] 	ScanString(0x60, 0x67 0x12 0x80)
[Signature] 	ScanString(0x60, 0x67 0x12 0x80)
[NotFullSet]
[MacroSigEnd]

# System File Tweaking Detection

[MacroSigStart]
[Comment]		Sigs on the Opening of IO.SYS for Output
[ID]			NUCLEAR_VARIANT1A
[Signature] 	0x67 0x03 0x81 0x6a ScanStringI(0xc0, "IO.SYS")
[Signature] 	ScanString(0x18, 0x3d 0x6a) ScanStringI(0x10, "IO.SYS")
[Signature] 	ScanString(0x0c, 0x23 0x3b 0x34) 0x71 0x6c SeekCur(1) 0x00
[Signature] 	ScanString(8, 0x4c 0x71 0x6c) SeekCur(1) 0x00
[MacroSigEnd]

[MacroSigStart]
[Comment]		Sigs on the Opening of MSDOS.SYS for Output
[ID]			NUCLEAR_VARIANT1B
[Signature] 	0x67 0x03 0x81 0x6a
[Signature] 	ScanStringI(0xc0, "MSDOS.SYS") ScanString(0x18, 0x3d 0x6a)
[Signature] 	ScanStringI(0x10, "MSDOS.SYS") ScanString(4, 0x12 0x6c)
[Signature] 	ScanString(0x18, 0x4c 0x71 0x6c) SeekCur(1) 0x00
[MacroSigEnd]

[MacroSigStart]
[Comment]		Sigs on the Opening and Deletion of COMMAND.COM
[ID]			NUCLEAR_VARIANT1C
[Signature] 	0x67 0x03 0x81 0x6a ScanStringI(0xc0, "COMMAND.COM")
[Signature] 	ScanString(0x18, 0x3d 0x6a) ScanStringI(0x10, "COMMAND.COM")
[Signature] 	ScanString(0x0c, 0x23 0x3b 0x34) 0x71 0x6c SeekCur(1) 0x00
[Signature] 	ScanString(8, 0x4c 0x71 0x6c) SeekCur(1) 0x00
[Signature] 	ScanString(8, 0x67 0xab 0x80) 0x6a
[Signature] 	ScanStringI(0x0c, "COMMAND.COM")
[MacroSigEnd]

#
# MDMA Variants
#

[MacroSigStart]
[Comment]		Finds Loop that Checks for Previous Infection, Kill("****")
[ID]			MDMA_VARIANT
[Signature] 	0x0c 0x67 0xb7 0x80 0x05 0x6c NameSig(NAME_ONLY_AUTOCLOSE)
[Signature] 	0x00 0x00 0x06 ScanString(8, 0x69) HotByteSkip()
[Signature] 	0x0c 0x6c 0x00 0x00 ScanString(8, 0x1d, 0x69) HotByteSkip()
[Signature] 	0x0f 0x6c 0x00 0x00 0x1e ScanString(8, 0x23, 0x69)
[Signature] 	HotByteSkip() 0x0c 0x6c 0x01 0x00 0x24 0x69 HotByteSkip()
[Signature] 	ScanString(8, 0x1d, 0x67) 0xb8 0x80 0x05 0x69 HotByteSkip()
[Signature] 	0x12 0x6c 0x00 0x00 0x06 0x0c 0x6a ScanStringI(3, "AUTOCLOSE")
[Signature] 	0x1e ScanString(0x480, 0x67 0xab 0x80 0x67) 0x6e 0x81 0x05
[Signature] 	0x6a 0x04 0x2a 0x2a 0x2a 0x2a 0x06
[MacroSigEnd]

#################################################################
# Unknown Virus Sigs
#################################################################

#
# NPAD
#

[UnknownVirusSigStart]
[Comment]		NPAD Variant
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_NPAD_VARIANT
[Signature] 	MacroSig(NPAD_VARIANT)
[Repair]		MacroSig(NPAD_AUTOOPEN_1831)
[UnknownVirusSigEnd]

# Office97 Version of NPad Variant

[UnknownVirusSigStart]
[Comment]		NPAD Variant
[Type]			WD8
[QAStatus]		PASSED
[ID]			VID_NPAD_VARIANT
[Signature] 	MacroSig(NPAD_VARIANT97)
[Repair]		FullSetRepair
[UnknownVirusSigEnd]

#
# Nuclear
#

# A "Hit" with 0 sig and (1C sig and (1A or 1B) sigs)

[UnknownVirusSigStart]
[Comment]		Nuclear Variant
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_NUCLEAR_VARIANT
[Signature] 	MacroSig(NUCLEAR_VARIANT0) and
[Signature] 	(MacroSig(NUCLEAR_VARIANT1C) and
[Signature] 	(MacroSig(NUCLEAR_VARIANT1A) or MacroSig(NUCLEAR_VARIANT1B)))
[Repair]		FullSetRepair
[UnknownVirusSigEnd]

#
# MDMA
#

[UnknownVirusSigStart]
[Comment]		MDMA Variant
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_MDMA_VARIANT
[Signature] 	MacroSig(MDMA_VARIANT)
#[Repair]		 UseSignature
[Repair]		FullSetRepair
[UnknownVirusSigEnd]

############################################################################
# MDMA Variants 97
############################################################################

[MacroSigStart]
[Comment]       MacroCopy WindowName$() + "AutoClose", "Global:AutoClose", 1
[ID]            MDMA_AUTOCLOSE_COPY97
[Signature]     "WordBasic.MacroCopy WordBasic.[WindowName$]() + "
[Signature]     0x22 ":AutoClose" 0x22 0x2C 0x20 0x22 "Global:AutoClose"
[Signature]     0x22 ", 1"
[MacroSigEnd]

[MacroSigStart]
[Comment]       If (WordBasic.Day(WordBasic.Now()) = 1) Then
[ID]            MDMA_SELECT_CASE97
[Signature]     "If (WordBasic.Day(WordBasic.Now()) = 1) Then"
[Signature]     ScanSlide(40, 'S') "elect Case get_platform"
[MacroSigEnd]

[MacroSigStart]
[Comment]       WordBasic.Call "infect_mac"
[ID]            MDMA_INFECT_MAC97
[Signature]     "WordBasic.Call " 0X22 "infect_mac" 0X22
[MacroSigEnd]

[UnknownVirusSigStart]
[Comment]       MDMA Variant, most likely non-infectious
[Type]          WD8
[QAStatus]		PASSED
[ID]			VID_MDMA_VARIANT
[Signature]     MacroSig(MDMA_AUTOCLOSE_COPY97) and
[Signature]     MacroSig(MDMA_SELECT_CASE97) and
[Signature]     MacroSig(MDMA_INFECT_MAC97)
[Repair]        FullSetRepair
[UnknownVirusSigEnd]


######################################################################
#
# for WM.Atom variant
#  Little Endian version on AUTOOPEN macro for:
#  FileName$() ....
#  MacroCopy VAR, ""
#  Call
#  FUNCTION
#
######################################################################
[MacroSigStart]
[Comment]		... FileName$() .... MacroCopy VAR, "" ... Call Atom
[ID]			MAC_ATOM_FAM_AUTOOPEN_LTL_E
[Signature] 	SeekSet(0) 0x01 0x00 NameSig(NAME_ONLY_AUTOOPEN)
[Signature] 	ScanString(500, 0x67 0x25 0x80)
[Signature] 	ScanString(200, 0x67 0xc2 0x80 0x69)
[Signature] 	 HotByteSkip() ScanString(10, 0x07 0x6A)
[Signature] 	ScanSlide(500, 0x29)
[Signature] 	ScanSlide(100, 0x1c)
[MacroSigEnd]

######################################################################
#
# for WM.Atom variant
#  Big Endian version on AUTOOPEN macro for:
#  FileName$() ....
#  MacroCopy VAR, ""
#  Call
#  FUNCTION
#
######################################################################
[MacroSigStart]
[Comment]		... FileName$() .... MacroCopy VAR, "" ... Call Atom
[ID]			MAC_ATOM_FAM_AUTOOPEN_BIG_E
[Signature] 	SeekSet(0) 0x00 0x01 NameSig(NAME_ONLY_AUTOOPEN)
[Signature] 	ScanString(500, 0x67 0x80 0x25)
[Signature] 	ScanString(200, 0x67 0x80 0xc2 0x69)
[Signature] 	 HotByteSkip() ScanString(10, 0x07 0x6A)
[Signature] 	ScanSlide(500, 0x29)
[Signature] 	ScanSlide(100, 0x1c)
[MacroSigEnd]

######################################################################
#
# for WM.Atom variant
#  Little Endian version on FILESAVEAS macro for:
#  MacroCopy "", WindowName$
#  Dlg .Password
#
######################################################################
[MacroSigStart]
[Comment]
[ID]			MAC_ATOM_FAM_FILESAVEAS_BIG_E
[Signature] 	SeekSet(0) 0x01 0x00 NameSig(NAME_ONLY_FILESAVEAS)
[Signature] 	ScanString(500, 0x67 0xc2 0x80 0x6a)
[Signature] 	 HotByteSkip() ScanString(10, 0x67 0x3b 0x80)
[Signature] 	ScanString(500, 0x73 0x60 0x00)
[MacroSigEnd]

######################################################################
#
# for WM.Atom variant
#  Big Endian version on FILESAVEAS macro for:
#  MacroCopy "", WindowName$
#  Dlg .Password
#
######################################################################
[MacroSigStart]
[Comment]
[ID]			MAC_ATOM_FAM_FILESAVEAS_LTL_E
[Signature] 	SeekSet(0) 0x00 0x01 NameSig(NAME_ONLY_FILESAVEAS)
[Signature] 	ScanString(500, 0x67 0x80 0xc2 0x6a)
[Signature] 	 HotByteSkip() ScanString(10, 0x67 0x80 0x3b)
[Signature] 	ScanString(500, 0x73 0x00 0x60)
[MacroSigEnd]


######################################################################
#
# WM.Atom variant detection:
#	hit on MAC_ATOM_FAM_AUTOOPEN_LTL_E
#		or MAC_ATOM_FAM_AUTOOPEN_BIG_E
#		or MAC_ATOM_FAM_FILESAVEAS_LTL_E
#		or MAC_ATOM_FAM_FILESAVEAS_BIG_E
#
######################################################################
[UnknownVirusSigStart]
[Comment]		WM.Atom variant detection
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_ATOM_VARIANT
[Signature] 	MacroSig(MAC_ATOM_FAM_AUTOOPEN_LTL_E) or
[Signature] 	MacroSig(MAC_ATOM_FAM_AUTOOPEN_BIG_E) or
[Signature] 	MacroSig(MAC_ATOM_FAM_FILESAVEAS_LTL_E) or
[Signature] 	MacroSig(MAC_ATOM_FAM_FILESAVEAS_BIG_E)
[Repair]		FullSetRepair
[UnknownVirusSigEnd]


######################################################################
#
# for WM.Bandung variant
# sig on AUTOOPEN macro frm offset #8 for:
# "On Error Goto" which is commented out.
#
######################################################################
[MacroSigStart]
[Comment]		WM.Bandung: AUTOOPEN byte match from offset #8
[ID]			MAC_BANDUNG_FAM_AUTOOPEN
[Signature] 	SeekSet(8) NameSig(NAME_ONLY_AUTOOPEN)
[Signature] 	ScanStringI(500, "On Error Goto")
[MacroSigEnd]

######################################################################
#
# for WM.Bandung variant
# sig on AUTOOPEN macro for:
#  MacroCopy ... , "Global:Autoexec"
#
######################################################################
[MacroSigStart]
[Comment]		WM.Bandung: AUTOOPEN byte match from offset #8
[ID]			MAC_BANDUNG_FAM_AUTOOPEN2
[Signature] 	0x67 0xc2 0x80 0x69 HotByteSkip() 0x12 0x6a 0x0f
[Signature]  ScanStringI(1, "Global:AutoExec")
[MacroSigEnd]

######################################################################
#
# for WM.Bandung variant
# sig on FILESAVE macro starting from offset #8
# ...FileSave...
# ...Dim ... As FileSaveAs
# ...GetCurValues...
# ...MacroCopy...
#
######################################################################
[MacroSigStart]
[Comment]		WM.Bandung: FILESAVE byte match from offset #8
[ID]			MAC_BANDUNG_FAM_FILESAVE
[Signature] 	SeekSet(8) NameSig(NAME_ONLY_FILESAVE)
[Signature] 	ScanString(500, 0x67 0x53 0x00)
[Signature] 	ScanSlide(500, 0x2f) ScanString(100, 0x34 0x67 0x54 0x00)
[Signature] 	ScanSlide(500, 0x3e)
[Signature] 	ScanString(1000, 0x67 0xc2 0x80)
[MacroSigEnd]

######################################################################
#
# for WM.Bandung variant
# sig on FILESAVEAS macro starting from offset #8:
# ...On Error Goto...
# ...Dim ... As FileSaveAs
# ...GetCurValues...
# ...MacroCopy...
#
######################################################################
[MacroSigStart]
[Comment]		WM.Bandung: FILESAVEAS byte match from offset #8
[ID]			MAC_BANDUNG_FAM_FILESAVEAS
[Signature] 	SeekSet(8) NameSig(NAME_ONLY_FILESAVEAS)
[Signature] 	ScanString(100, 0x2c 0x2d 0x2a)
[Signature] 	ScanSlide(500, 0x2f) ScanString(100, 0x34 0x67 0x54 0x00)
[Signature] 	ScanSlide(500, 0x3e)
[Signature] 	ScanString(1000, 0x67 0xc2 0x80)
[MacroSigEnd]


######################################################################
#
# WM.Bandung variant detection:
#  1. and hit on MAC_BANDUNG_FAM_AUTOOPEN
#			  or MAC_BANDUNG_FAM_FILESAVE
#			  or MAC_BANDUNG_FAM_FILESAVEAS
#  2. also has AUTOEXEC, TOOLSMACRO and TOOLSCUSTOMIZE
#
######################################################################
[UnknownVirusSigStart]
[Comment]		WM.Bandung Variant: has all 6 macros & hit one of the MacroSigs
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_BANDUNG_VARIANT
[Signature] 	(MacroSig(MAC_BANDUNG_FAM_AUTOOPEN) and
[Signature]  MacroSig(MAC_BANDUNG_FAM_AUTOOPEN2)  or
[Signature] 	 MacroSig(MAC_BANDUNG_FAM_FILESAVE)   or
[Signature] 	 MacroSig(MAC_BANDUNG_FAM_FILESAVEAS)  ) and
[Signature] 	(NameSig(NAME_ONLY_AUTOEXEC)			 and
[Signature] 	 NameSig(NAME_ONLY_TOOLSMACRO)			 and
[Signature] 	 NameSig(NAME_ONLY_TOOLSCUSTOMIZE) )
[Repair]		FullSetRepair
[UnknownVirusSigEnd]

######################################################################
#
# for WM.Colors variant, A has this AUTOOPEN, B&C has CONCEPT's
#
#  in AUTOOPEN
#  IF ... external macro call THEN
#  ... external macro call ... FileName$
#
######################################################################
[MacroSigStart]
[Comment]
[ID]			MAC_COLORS_FAM_AUTOOPEN
[Signature] 	0x1d NameSig(NAME_ONLY_AUTOOPEN) SeekCur(1) HotByteSkip()
[Signature] 	 0x76 ScanSlide(50, 0x1e)
[Signature] 	ScanSlide(200, 0x76) HotByteSkip()
[Signature] 	 ScanString(10, 0x05 0x67 0x25 0x80 0x05 0x06 0x06)
[MacroSigEnd]

######################################################################
#
# for WM.Colors variant
#
#  in AUTOCLOSE
#  IF ... external macro call THEN
#  ... external macro call ... FileName$
#
######################################################################
[MacroSigStart]
[Comment]
[ID]			MAC_COLORS_FAM_AUTOCLOSE
[Signature] 	0x1d NameSig(NAME_ONLY_AUTOCLOSE) SeekCur(1) HotByteSkip()
[Signature] 	 0x76 ScanSlide(50, 0x1e)
[Signature] 	ScanSlide(200, 0x76) HotByteSkip()
[Signature] 	 ScanString(10, 0x05 0x67 0x25 0x80 0x05 0x06 0x06)
[MacroSigEnd]

######################################################################
#
# for WM.Colors variant
#
#  in FILESAVEAS
#  IF ... external macro call THEN
#  ...DisableAutoMacros 0
#  ...DIM ... AS FileSaveAs
#
######################################################################
[MacroSigStart]
[Comment]
[ID]			MAC_COLORS_FAM_FILESAVEAS
[Signature] 	0x1d NameSig(NAME_ONLY_FILESAVEAS) SeekCur(1) HotByteSkip()
[Signature] 	 0x76 ScanSlide(50, 0x1e)
[Signature] 	ScanString(200, 0x67 0xd6 0x80 0x6c 0x00 0x00)
[Signature] 	ScanSlide(200, 0x2f) ScanString(50, 0x34 0x67 0x54 0x00)
[MacroSigEnd]

######################################################################
#
# for WM.Colors variant, not in C
#
#  in FILEEXIT
#  IF ... external macro call THEN
#  ... DisableAutoMacros 0
#  ... external macro call ... FileName$
#
######################################################################
[MacroSigStart]
[Comment]
[ID]			MAC_COLORS_FAM_FILEEXIT
[Signature] 	0x1d NameSig(NAME_ONLY_FILEEXIT) SeekCur(1) HotByteSkip()
[Signature] 	 0x76 ScanSlide(50, 0x1e)
[Signature] 	ScanString(200, 0x67 0xd6 0x80 0x6c 0x00 0x00)
[Signature] 	ScanSlide(200, 0x76) HotByteSkip()
[Signature] 	 ScanString(10, 0x67 0x25 0x80)
[MacroSigEnd]

######################################################################
#
# for WM.Colors variant
#
#  in FILESAVE
#  IF ... external macro call THEN
#  ... DisableAutoMacros 0
#  ... external macro call ... FileName$
#  ... external macro call ... FileName$
#
######################################################################
[MacroSigStart]
[Comment]
[ID]			MAC_COLORS_FAM_FILESAVE
[Signature] 	0x1d NameSig(NAME_ONLY_FILESAVE) SeekCur(1) HotByteSkip()
[Signature] 	 0x76 ScanSlide(50, 0x1e)
[Signature] 	ScanString(200, 0x67 0xd6 0x80 0x6c 0x00 0x00)
[Signature] 	ScanSlide(200, 0x76) HotByteSkip()
[Signature] 	 ScanString(10, 0x67 0x25 0x80)
[Signature] 	ScanSlide(200, 0x76) HotByteSkip()
[Signature] 	 ScanString(10, 0x67 0x25 0x80)
[MacroSigEnd]

######################################################################
#
# for WM.Colors variant
#
#  in FILENEW				;not in Colors.C
#  IF ... external macro call THEN
#  ...DisableAutoMacros 0
#  ...DIM ... AS FileNew
#
#
#
######################################################################
[MacroSigStart]
[Comment]
[ID]			MAC_COLORS_FAM_FILENEW
[Signature] 	0x1d NameSig(NAME_ONLY_FILENEW) SeekCur(1) HotByteSkip()
[Signature] 	 0x76 ScanSlide(50, 0x1e)
[Signature] 	ScanString(200, 0x67 0xd6 0x80 0x6c 0x00 0x00)
[Signature] 	ScanSlide(200, 0x2f) ScanString(50, 0x34 0x67 0x4f 0x00)
[MacroSigEnd]

######################################################################
#
# for WM.Colors variant
#
#  in MACROS
#
#  ...
#  MacroCopy
#
#
#
######################################################################
[MacroSigStart]
[Comment]
[ID]			MAC_COLORS_FAM_MACROS1
[Signature] 	0x67 0xc2 0x80 NameSig(NAME_ONLY_MACROS)
[MacroSigEnd]

######################################################################
#
# for WM.Colors variant
#
#  in MACROS
#
#  ...
#  SetProfileString("colors",
#
#
#
######################################################################
[MacroSigStart]
[Comment]
[ID]			MAC_COLORS_FAM_MACROS2
[Signature] 	0x67 0x46 0x80 0x05 0x6a 0x06 "colors" NameSig(NAME_ONLY_MACROS)
[MacroSigEnd]


######################################################################
#
# WM.Colors variant detection:
#  hit on one of the MacroSig for AUTOOPEN, AUTOCLOSE, FILESAVEAS,
#  FILEEXIT, FILESAVE, FILENEW.
#  and has MacroCopy instruction in MACROS
#  and has SetProfileString("colors" ... in MACROS
#
# notes: B&C has Concept's AUTOOPEN
#		 C does not have FILEEXIT & FILENEW
#
######################################################################
[UnknownVirusSigStart]
[Comment]		WM.Colors variant detection
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_COLORS_VARIANT
[Signature] 	(MacroSig(MAC_COLORS_FAM_AUTOOPEN)	 or
[Signature] 	 MacroSig(MAC_COLORS_FAM_AUTOCLOSE)  or
[Signature] 	 MacroSig(MAC_COLORS_FAM_FILESAVEAS) or
[Signature] 	 MacroSig(MAC_COLORS_FAM_FILEEXIT)	 or
[Signature] 	 MacroSig(MAC_COLORS_FAM_FILESAVE)	 or
[Signature] 	 MacroSig(MAC_COLORS_FAM_FILENEW)		) and
[Signature] 	MacroSig(MAC_COLORS_FAM_MACROS1) and
[Signature] 	MacroSig(MAC_COLORS_FAM_MACROS2)
[Repair]		FullSetRepair
[UnknownVirusSigEnd]


######################################################################
#
# for WM.Concept variant
# Little Endian version
# sig on any macro for:
# ... ON ERROR GOTO ...
# ....... Val(GetDocumentVar$ ....
# .... MacroCopy .... ,"Global:... (x4)
#
######################################################################
[MacroSigStart]
[Comment]		ON ERROR GOTO, FileName$()... 4 MacroCopy to Global:
[ID]			MAC_CONCEPT_FAM_AUTOOPEN_LTL_E
[Signature] 	SeekSet(0) 0x01 0x00
#NameSig(NAME_ONLY_AUTOOPEN)
[Signature] 	ScanString(200, 0x2c 0x2d 0x2a 0x69)
[Signature] 	ScanString(500, 0x67 0x06 0x80 0x05 0x67 0x4d 0x81)
[Signature] 	ScanString(1000, 0x67 0xc2 0x80) ScanStringI(50, "Global:")
[Signature] 	ScanString(100, 0x67 0xc2 0x80) ScanStringI(50, "Global:")
[Signature] 	ScanString(100, 0x67 0xc2 0x80) ScanStringI(50, "Global:")
[Signature] 	ScanString(100, 0x67 0xc2 0x80) ScanStringI(50, "Global:")
[MacroSigEnd]


######################################################################
#
# for WM.Concept variant
# Big Endian version
# sig on any macro for:
# ... ON ERROR GOTO ...
# ....... Val(GetDocumentVar$ ....
# .... MacroCopy .... ,"Global:... (x4)
#
######################################################################
[MacroSigStart]
[Comment]		ON ERROR GOTO...Val(GetDocumentVar$...MacroCopy to Global:
[ID]			MAC_CONCEPT_FAM_AUTOOPEN_BIG_E
[Signature] 	SeekSet(0) 0x00 0x01
#NameSig(NAME_ONLY_AUTOOPEN)
[Signature] 	ScanString(200, 0x2c 0x2d 0x2a 0x69)
[Signature] 	ScanString(500, 0x67 0x80 0x06 0x05 0x67 0x81 0x4d)
[Signature] 	ScanString(1000, 0x67 0x80 0xc2) ScanStringI(50, "Global:")
[Signature] 	ScanString(100, 0x67 0x80 0xc2) ScanStringI(50, "Global:")
[Signature] 	ScanString(100, 0x67 0x80 0xc2) ScanStringI(50, "Global:")
[Signature] 	ScanString(100, 0x67 0x80 0xc2) ScanStringI(50, "Global:")
[MacroSigEnd]


######################################################################
#
# WM.Concept variant detection:
#  1. hit on MAC_CONCEPT_FAM_AUTOOPEN_LTL_E
#		  or MAC_CONCEPT_FAM_AUTOOPEN_BIG_E
#  2. has no MACRO "macros" to distinguish from WM.Colors.B
#
######################################################################
[UnknownVirusSigStart]
[Comment]		WM.Concept variant detection
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_CONCEPT_VARIANT
[Signature] 	(MacroSig(MAC_CONCEPT_FAM_AUTOOPEN_LTL_E) or
[Signature] 	 MacroSig(MAC_CONCEPT_FAM_AUTOOPEN_BIG_E)	) and
[Signature] 	(NameSig(NAME_ONLY_AUTOOPEN) or
[Signature] 	 NameSig(NAME_ONLY_FILESAVEAS)) and
[Signature] 	(Not NameSig(NAME_ONLY_MACROS) )
[Repair]		FullSetRepair
#the following repair clause is added to remove Concept.A mess
# that's left behind by MS ScanProt
# refers to issue #12095,97,98...
# MUST BE REMOVED WHEN BETTER DETECTION (dependency-variant-detection)
#  CHECKED IN....Raul 060597
#[Repair]		 NameSig(NAME_ONLY_AAAZAO),
#[Repair]		 NameSig(NAME_ONLY_AAAZFS),
#[Repair]		 NameSig(NAME_ONLY_FILESAVEAS)
[UnknownVirusSigEnd]


######################################################################
#
# Detection for unknown WM.Wazzu variant
#
######################################################################

[MacroSigStart]
[Comment]		Unknown variant signature of Wazzu, macro AUTOOPEN
[ID]			UNKNOWN_VARIANT_WAZZU1
[Signature] 	SeekSet(0x0A)
[Signature] 	NameSig(NAME_ONLY_AUTOOPEN)
[Signature] 	ScanString(0x50, 0x67 0x56 0x00)
[Signature] 	ScanString(0x10, 0x2f)
[Signature] 	ScanString(0x10, 0x3e)
[Signature] 	ScanString(0x100, 0x67 0xc2 0x80)
[Signature] 	ScanString(0x30, 0x67 0x54 0x00)
[Signature] 	ScanString(0x20, 0x67 0xc2 0x80)
[MacroSigEnd]

[MacroSigStart]
[Comment]		Unknown variant signature of Wazzu, macro AUTOOPEN
[ID]			UNKNOWN_VARIANT_WAZZU2
[Signature] 	SeekSet(0x50)
[Signature] 	NameSig(NAME_ONLY_AUTOOPEN)
[Signature] 	ScanString(0x100, 0x67 0xAF 0x80)
[Signature] 	0x05 0x67 0x09 0x80
[Signature] 	0x05 0x67 0x8e 0x81
[Signature] 	0x05 0x67 0xB8 0x80
[Signature] 	SeekSet(0)
[Signature] 	ScanString(0x800, 0x67 0xc2 0x80)
[Signature] 	ScanString(0x30, 0x67 0x54 0x00)
[Signature] 	ScanString(0x20, 0x67 0xc2 0x80)
[MacroSigEnd]

[UnKnownVirusSigStart]
[Comment]		Wazzu Variant
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_WAZZU_VARIANT
[Signature] 	MacroSig(UNKNOWN_VARIANT_WAZZU1) or
[Signature] 	MacroSig(UNKNOWN_VARIANT_WAZZU2)
#[Repair]		 UseSignature
[Repair]		FullSetRepair
[UnKnownVirusSigEnd]

######################################################################
#
# Detection for unknown WM.Outlaw variant
#
######################################################################

[MacroSigStart]
[Comment]		Unknown variant signature of Outlaw
[ID]			UNKNOWN_VARIANT_OUTLAW
[Signature] 	SeekSet(0x50)
[Signature] 	NameSig(NAME_LETTER_FOUR_DIGITS)
[Signature] 	ScanString(0x500, 0x67 0x02 0x80)
[Signature] 	ScanString(0x10, 0x67 0x0e 0x80)
[Signature] 	ScanString(0x30, 0x67 0x07 0x80)
[Signature] 	ScanString(0x30, 0x67 0xea 0x80)
[Signature] 	ScanString(0x800, 0x67 0xc2 0x80)
[MacroSigEnd]

[UnKnownVirusSigStart]
[Comment]		Outlaw Variant
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_OUTLAW_VARIANT
[Signature] 	MacroSig(UNKNOWN_VARIANT_OUTLAW)
[Repair]		FullSetRepair
[UnKnownVirusSigEnd]

######################################################################
#
# Detection for unknown WM.Rapi variant pulled out 070397 RE
#
######################################################################
#
#[UnKnownVirusSigStart]
#[Comment]		 RAPI Variant
#[Type] 		 WD7
#[QAStatus] 	 PASSED
#[ID]			 VID_RAPI_VARIANT
#[Signature]	 (NameSig(NAME_ONLY_AUTOOPEN) or
#[Signature]	  NameSig(NAME_ONLY_AUTOEXEC) or
#[Signature]	  NameSig(NAME_ONLY_FILESAVE) or
#[Signature]	  NameSig(NAME_ONLY_FILEOPEN) or
#[Signature]	  NameSig(NAME_ONLY_FILESAVEAS)) and
#[Signature]	 (CRC(0xdfd8c1d2) or
#[Signature]	  CRC(0x7307cc13) or
#[Signature]	  CRC(0x6347ce43) or
#[Signature]	  CRC(0x672bdc09) or
#[Signature]	  CRC(0x3ab11c9c) or
#[Signature]	  CRC(0x73e48354) or
#[Signature]	  CRC(0xff1765a2))
#[Repair]		 FullSetRepair
#[UnKnownVirusSigEnd]

######################################################################
#
# Detection for unknown WM.Twno variant
#
######################################################################

[MacroSigStart]
[Comment]		Unknown variant signature of TWNO
[ID]			VARIANT_TWNO_AUTOOPEN
[Signature] 	SeekSet(0)
[Signature] 	NameSig(NAME_ONLY_AUTOOPEN)
[Signature] 	ScanString(0x150, 0x67 0x9e 0x80)
[Signature] 	ScanString(0x500, 0x67 0x2b 0x80)
[Signature] 	ScanString(0x500, 0x67 0xb7 0x80)
[Signature] 	ScanString(0x300, 0x67 0xc2 0x80)
[Signature] 	ScanString(0x300, 0x67 0xc2 0x80)
[Signature] 	ScanString(0x300, 0x67 0xc2 0x80)
[Signature] 	ScanString(0x300, 0x67 0x54 0x00)
[Signature] 	ScanString(0x300, 0x67 0xc2 0x80)
[MacroSigEnd]

[MacroSigStart]
[Comment]		Unknown variant signature of TWNO
[ID]			VARIANT_TWNO_AUTOCLOSE
[Signature] 	SeekSet(0)
[Signature] 	NameSig(NAME_ONLY_AUTOCLOSE)
[Signature] 	ScanString(0x150, 0x67 0x9e 0x80)
[Signature] 	ScanString(0x500, 0x67 0x2b 0x80)
[Signature] 	ScanString(0x500, 0x67 0xb7 0x80)
[Signature] 	ScanString(0x300, 0x67 0xc2 0x80)
[Signature] 	ScanString(0x300, 0x67 0xc2 0x80)
[Signature] 	ScanString(0x300, 0x67 0xc2 0x80)
[Signature] 	ScanString(0x300, 0x67 0x54 0x00)
[Signature] 	ScanString(0x300, 0x67 0xc2 0x80)
[MacroSigEnd]

[MacroSigStart]
[Comment]		Unknown variant signature of TWNO
[ID]			VARIANT_TWNO_AUTONEW
[Signature] 	SeekSet(0)
[Signature] 	NameSig(NAME_ONLY_AUTONEW)
[Signature] 	ScanString(0x150, 0x67 0x9e 0x80)
[Signature] 	ScanString(0x500, 0x67 0x2b 0x80)
[Signature] 	ScanString(0x500, 0x67 0xb7 0x80)
[Signature] 	ScanString(0x300, 0x67 0xc2 0x80)
[Signature] 	ScanString(0x300, 0x67 0xc2 0x80)
[Signature] 	ScanString(0x300, 0x67 0xc2 0x80)
[Signature] 	ScanString(0x300, 0x67 0x54 0x00)
[Signature] 	ScanString(0x300, 0x67 0xc2 0x80)
[MacroSigEnd]

[MacroSigStart]
[Comment]		Unknown variant signature of TWNO
[ID]			VARIANT_TWNO_AUTOEXEC
[Signature] 	SeekSet(0)
[Signature] 	NameSig(NAME_ONLY_AUTOEXEC)
[Signature] 	ScanString(0x150, 0x67 0x9e 0x80)
[Signature] 	ScanString(0x500, 0x67 0x2b 0x80)
[Signature] 	ScanString(0x500, 0x67 0xb7 0x80)
[Signature] 	ScanString(0x300, 0x67 0xc2 0x80)
[Signature] 	ScanString(0x300, 0x67 0xc2 0x80)
[Signature] 	ScanString(0x300, 0x67 0xc2 0x80)
[Signature] 	ScanString(0x300, 0x67 0x54 0x00)
[Signature] 	ScanString(0x300, 0x67 0xc2 0x80)
[MacroSigEnd]

[UnKnownVirusSigStart]
[Comment]		TWNO Variant
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_TWNO_VARIANT
[Signature] 	MacroSig(VARIANT_TWNO_AUTOOPEN) or
[Signature] 	MacroSig(VARIANT_TWNO_AUTOCLOSE) or
[Signature] 	MacroSig(VARIANT_TWNO_AUTONEW) or
[Signature] 	MacroSig(VARIANT_TWNO_AUTOEXEC)
[Repair]		FullSetRepair
[UnKnownVirusSigEnd]

######################################################################
#
# for Macro Viruses created by NJ-WMVCK generator
# sig on AUTOEXEC macro:
#  NoVir$=GetProfileString$(Section$, ProfileName$)
#  If (NoVir$<>wininistr$) AND (update=1) Then
#	DisableInput
#	DisableAutoMacros 0
#	On Error Resume Next
#	....
#	MacroCopy WindowName$()
#
######################################################################
[MacroSigStart]
[Comment]
[ID]			MAC_NJWMVCK_FAM_AUTOEXEC
[Signature] 	"NoVir$" NameSig(NAME_ONLY_AUTOEXEC)
[Signature] 	 0x0c 0x67 0x45 0x80 0x05 0x69 0x08 "Section$"
[Signature] 	 0x12 0x69 0x0c "ProfileName$" 0x06
[Signature] 	ScanSlide(100, 0x1d) 0x05 0x69 0x06 "NoVir$"
[Signature] 	 0x0d 0x69 0x0a "wininistr$" 0x06 0x03 0x05
[Signature] 	 0x69 0x06 "update" 0x0c 0x6c 0x01 0x00 0x06 0x1e
[Signature] 	ScanString(100, 0x67 0x9e 0x80)
[Signature] 	ScanString(100, 0x67 0xd6 0x80 0x6c 0x00 0x00)
[Signature] 	ScanString(100, 0x2c 0x2d 0x18 0x26)
[Signature] 	ScanString(200, 0x67 0xc2 0x80 0x67 0x3b 0x80)
[MacroSigEnd]

[UnknownVirusSigStart]
[Comment]		Macro Viruses created by NJ-WMVCK generator:
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_NJ_WMVCK_VARIANT
[Signature] 	MacroSig(MAC_NJWMVCK_FAM_AUTOEXEC)
[Repair]		NoRepair
[UnknownVirusSigEnd]

######################################################################
#
# for Macro Viruses created by NJ-WMDLK generator
# sig on AUTOOPEN macro:
#	....
#	On Error Resume Next
#	MacroCopy FileName$(), ...
#	MacroCopy FileName$(), ...
#	MacroCopy FileName$(), ...
#	MacroCopy FileName$(), ...
#	....
#	On Error Resume Next
#	FileSaveAs .Format = 1
#	MacroCopy
#	MacroCopy
#	MacroCopy
#	MacroCopy
#	FileSaveAll 1,0
#
######################################################################
[MacroSigStart]
[Comment]
[ID]			MAC_NJWMDLK_FAM_AUTOOPEN
[Signature] 	0x2c 0x2d 0x18 0x26 NameSig(NAME_ONLY_AUTOOPEN)
[Signature] 	ScanString(100, 0x67 0xc2 0x80 0x67 0x25 0x80)
[Signature] 	ScanString(100, 0x67 0xc2 0x80 0x67 0x25 0x80)
[Signature] 	ScanString(100, 0x67 0xc2 0x80 0x67 0x25 0x80)
[Signature] 	ScanString(100, 0x67 0xc2 0x80 0x67 0x25 0x80)
[Signature] 	ScanString(500, 0x2c 0x2d 0x18 0x26)
[Signature] 	ScanString(100, 0x67 0xc2 0x80)
[Signature] 	ScanString(100, 0x67 0xc2 0x80)
[Signature] 	ScanString(100, 0x67 0xc2 0x80)
[Signature] 	ScanString(100, 0x67 0xc2 0x80)
[Signature] 	ScanString(100, 0x67 0xa3 0x80)
[Signature] 	 0x6c 0x01 0x00 0x12 0x6c 0x00 0x00
[MacroSigEnd]

[UnknownVirusSigStart]
[Comment]		Macro Viruses created by NJ-WMDLK generator:
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_NJ_WMDLK_VARIANT
[Signature] 	MacroSig(MAC_NJWMDLK_FAM_AUTOOPEN)
[Repair]		NoRepair
[UnknownVirusSigEnd]


#################################################################
#
#		  NON-INFECTIOUS WM.Cap with corrupted CAP macro only!
#		  It's annoyingly hard to remove manually
#
#################################################################
[NamedCRCSigStart]
[Comment]			WM.Cap.Trash  non infectious but annoying
[ID]				CRC_CAP_CAPTRASH
[CRCWD7]			0xEF50C7FA
[Signature] 		NameSig(NAME_ONLY_CAP)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Cap.Trash  non infectious but annoying
[ID]				CRC_CAP_CAPTRASH1
[CRCWD7]			0x772F4694
[Signature] 		NameSig(NAME_ONLY_CAP)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Cap: CAP
[ID]				CRC_CAP_CAPFRAG
[CRCWD7]			0x2b0d346b
[Signature] 		NameSig(NAME_ONLY_CAP)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Cap: CAP
[ID]				CRC_CAP_CAPMANGLED
[CRCWD7]			0xf190ea11
[Signature] 		NameSig(NAME_ONLY_CAP)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Cap: CAP ; ID is from last 3 digits of customer issue
[ID]				CRC_CAP_CAPBAD413
[CRCWD7]			0x15d8865a
[Signature] 		NameSig(NAME_ONLY_CAP)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Cap: CAP ; ID is from last 3 digits of customer issue
[ID]				CRC_CAP_CAPBAD453
[CRCWD7]			0x24A81D86
[Signature] 		NameSig(NAME_ONLY_CAP)
[NamedCRCSigEnd]


[NamedCRCSigStart]
[Comment]			WM.CAP: CAP
[ID]				CRC_CAP_CAP12638
[CRCWD7]			0x21C600D8
[Signature] 		NameSig(NAME_ONLY_CAP)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: CAP
[ID]				CRC_CAP_CAP13052
[CRCWD7]			0xD5353C20
[Signature] 		NameSig(NAME_ONLY_CAP)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: CAP
[ID]				CRC_CAP_CAP13102
[CRCWD7]			0x94773550
[Signature] 		NameSig(NAME_ONLY_CAP)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: CAP
[ID]                CRC_CAP_CAP351
[CRCWD7]            0xDAB59BE1
[Signature] 		NameSig(NAME_ONLY_CAP)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: CAP
[ID]                CRC_CAP_CAP557
[CRCWD7]            0x0EFF07BE
[Signature] 		NameSig(NAME_ONLY_CAP)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: CAP
[ID]                CRC_CAP_CAP562
[CRCWD7]            0x74156400
[Signature] 		NameSig(NAME_ONLY_CAP)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: CAP
[ID]                CRC_CAP_CAP660
[CRCWD7]            0x2BB9E8FF
[Signature] 		NameSig(NAME_ONLY_CAP)
[NamedCRCSigEnd]

[KnownVirusSigStart]
[Comment]		WM.Cap corrupted non infectious but annoying
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_CAP_CORRUPTED
[Signature] 	NamedCRCSig(CRC_CAP_CAPTRASH) or
[Signature] 	NamedCRCSig(CRC_CAP_CAPTRASH1) or
[Signature] 	NamedCRCSig(CRC_CAP_CAPFRAG) or
[Signature] 	NamedCRCSig(CRC_CAP_CAPMANGLED) or
[Signature] 	NamedCRCSig(CRC_CAP_CAPBAD413) or
[Signature] 	NamedCRCSig(CRC_CAP_CAPBAD453) or
[Signature] 	NamedCRCSig(CRC_CAP_CAP12638) or
[Signature] 	NamedCRCSig(CRC_CAP_CAP13052) or
[Signature]     NamedCRCSig(CRC_CAP_CAP13102) or
[Signature]     NamedCRCSig(CRC_CAP_CAP351) or
[Signature]     NamedCRCSig(CRC_CAP_CAP557) or
[Signature]     NamedCRCSig(CRC_CAP_CAP562) or
[Signature]     NamedCRCSig(CRC_CAP_CAP660)
[Repair]        UseOtherRepair(VID_CAPA)
[KnownVirusSigEnd]

# The one from Cust #12598 is CAP with ALL the macros corrputed
######################################################################
# WORD MACRO VIRUS TRASHcan
# The following NamedCRCSigs contain Junk CRCs to let FullSet pick them up
# The macro may be one of the following:
#  1. corrupted - non-infectious remnant
#  2. partial-conversion from 95->97
# Only add more trash when necessary!
# Remember, every NamedCRCSig = 16 bytes increase in NAVEX.EXP
######################################################################

[NamedCRCSigStart]
[Comment]			WM.Colors: corrupted FILESAVEAS
[ID]				CRC_FILESAVEAS_COLORSJUNK
[CRCWD7]			0xB1C4281B
[Signature] 		NameSig(NAME_ONLY_FILESAVEAS)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Colors: corrupted TOOLSMACRO
[ID]				CRC_TOOLSMACRO_COLORSJUNK
[CRCWD7]			0x5C8B188C
[Signature] 		NameSig(NAME_ONLY_TOOLSMACRO)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Colors.V: TOOLSMACRO snatched by Rapi(?) into RPTM
#issue #12111, 12113
[ID]				CRC_RPTM_COLORSV
[CRCWD7]			0xE4BC3504
[Signature] 		NameSig(NAME_ONLY_RPTM)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Colors Variant: TOOLSMACRO	; Mangled
[ID]				CRC_TOOLSMACRO_COLORSVARIANT
[CRCWD7]			0xd196a9f2
[Signature] 		NameSig(NAME_ONLY_TOOLSMACRO)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Kompu Variant: AUTOOPEN	   ; Mangled
[ID]				CRC_AUTOOPEN_KOMPUVARIANT
[CRCWD7]			0x09de0ac7
[Signature] 		NameSig(NAME_ONLY_AUTOOPEN)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Cap: AUTOEXEC
[ID]				CRC_AUTOEXEC_CAPFRAG
[CRCWD7]			0x6f85a2f9
[Signature] 		NameSig(NAME_ONLY_AUTOEXEC)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Cap: AUTOOPEN
[ID]				CRC_AUTOOPEN_CAPFRAG
[CRCWD7]			0x6206a4a8
[Signature] 		NameSig(NAME_ONLY_AUTOOPEN)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Cap: FILEOPEN
[ID]				CRC_FILEOPEN_CAPFRAG
[CRCWD7]			0xf0e1f406
[Signature] 		NameSig(NAME_ONLY_FILEOPEN)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Cap: FILESAVE
[ID]				CRC_FILESAVE_CAPFRAG
[CRCWD7]			0xa8ba823f
[Signature] 		NameSig(NAME_ONLY_FILESAVE)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Cap: AUTOCLOSE
[ID]				CRC_AUTOCLOSE_CAPFRAG
[CRCWD7]			0xf965eef7
[Signature] 		NameSig(NAME_ONLY_AUTOCLOSE)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Cap: FILECLOSE
[ID]				CRC_FILECLOSE_CAPFRAG
[CRCWD7]			0x889ca3d0
[Signature] 		NameSig(NAME_ONLY_FILECLOSE)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Cap: FILESAVEAS
[ID]				CRC_FILESAVEAS_CAPFRAG
[CRCWD7]			0x1a85d7f7
[Signature] 		NameSig(NAME_ONLY_FILESAVEAS)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Cap: TOOLSMACRO
[ID]				CRC_TOOLSMACRO_CAPFRAG
[CRCWD7]			0x0c67103b
[Signature] 		NameSig(NAME_ONLY_TOOLSMACRO)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Cap: FILETEMPLATES
[ID]				CRC_FILETEMPLATES_CAPFRAG
[CRCWD7]			0x4ea4dc07
[Signature] 		NameSig(NAME_ONLY_FILETEMPLATES)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Dzt: FILESAVEAS
[ID]				CRC_FILESAVEAS_DZTMANGLED
[CRCWD7]			0x1826d119
[Signature] 		NameSig(NAME_ONLY_FILESAVEAS)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Cap: AUTOOPEN
[ID]				CRC_AUTOOPEN_CAPMANGLED
[CRCWD7]			0x07a67682
[Signature] 		NameSig(NAME_ONLY_AUTOOPEN)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Cap: AUTOCLOSE
[ID]				CRC_AUTOCLOSE_CAPMANGLED
[CRCWD7]			0x8fb0e296
[Signature] 		NameSig(NAME_ONLY_AUTOCLOSE)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Junk: FILESAVEAS 	A corrupted macro
[ID]				CRC_FILESAVEAS_JUNKMACRO
[CRCWD7]			0x5fb4b137
[Signature] 		NameSig(NAME_ONLY_FILESAVEAS)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.TwoLines.Trash: MSRUN corrupted remnant of #12406
[ID]				CRC_MSRUN_TRASH
[CRCWD7]			0x6267F3E2
[Signature] 		NameSig(NAME_ONLY_MSRUN)
[NamedCRCSigEnd]

#Removed since same CRC is now a part of WM.Appder.G - AO 7/797
#[NamedCRCSigStart]
#[Comment]			 WM.Appder: APPDER (Mangled)
#[ID]				 CRC_APPDER_APPDERMANGLED
#[CRCWD7]			 0x01a7cca9
#[Signature]		 NameSig(NAME_ONLY_APPDER)
#[NamedCRCSigEnd]


# This one from Cust #12598 is CAP with ALL the macros corrputed

[NamedCRCSigStart]
[Comment]			WM.CAP: CAP
[ID]				CRC_CAP_CAP12598
[CRCWD7]			0x88B75C44
[Signature] 		NameSig(NAME_ONLY_CAP)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: AUTOEXEC
[ID]				CRC_AUTOEXEC_CAP12598
[CRCWD7]			0x303A719D
[Signature] 		NameSig(NAME_ONLY_AUTOEXEC)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: FILEOPEN
[ID]				CRC_FILEOPEN_CAP12598
[CRCWD7]			0x239717D8
[Signature] 		NameSig(NAME_ONLY_FILEOPEN)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: FILESAVE
[ID]				CRC_FILESAVE_CAP12598
[CRCWD7]			0x4762D67A
[Signature] 		NameSig(NAME_ONLY_FILESAVE)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: AUTOCLOSE
[ID]				CRC_AUTOCLOSE_CAP12598
[CRCWD7]			0x0655EDF7
[Signature] 		NameSig(NAME_ONLY_AUTOCLOSE)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: FILECLOSE
[ID]				CRC_FILECLOSE_CAP12598
[CRCWD7]			0x08279AEE
[Signature] 		NameSig(NAME_ONLY_FILECLOSE)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: FILESAVEAS
[ID]				CRC_FILESAVEAS_CAP12598
[CRCWD7]			0x888700AC
[Signature] 		NameSig(NAME_ONLY_FILESAVEAS)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: TOOLSMACRO
[ID]				CRC_TOOLSMACRO_CAP12598
[CRCWD7]			0x511D87DB
[Signature] 		NameSig(NAME_ONLY_TOOLSMACRO)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: FILETEMPLATES
[ID]				CRC_FILETEMPLATES_CAP12598
[CRCWD7]			0x215F471C
[Signature] 		NameSig(NAME_ONLY_FILETEMPLATES)
[NamedCRCSigEnd]


# This one from Cust #12610 is CAP with ALL the macros corrputed

[NamedCRCSigStart]
[Comment]			WM.CAP: CAP
[ID]				CRC_CAP_CAP12610
[CRCWD7]			0x474353A4
[Signature] 		NameSig(NAME_ONLY_CAP)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: AUTOEXEC
[ID]				CRC_AUTOEXEC_CAP12610
[CRCWD7]			0xED74B325
[Signature] 		NameSig(NAME_ONLY_AUTOEXEC)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: AUTOPEN
[ID]				CRC_AUTOOPEN_CAP12610
[CRCWD7]			0x71F7B5B7
[Signature] 		NameSig(NAME_ONLY_AUTOOPEN)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: FILEOPEN
[ID]				CRC_FILEOPEN_CAP12610
[CRCWD7]			0x9535B75F
[Signature] 		NameSig(NAME_ONLY_FILEOPEN)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: FILESAVE
[ID]				CRC_FILESAVE_CAP12610
[CRCWD7]			0x52C9B8CC
[Signature] 		NameSig(NAME_ONLY_FILESAVE)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: AUTOCLOSE
[ID]				CRC_AUTOCLOSE_CAP12610
[CRCWD7]			0x521E14D7
[Signature] 		NameSig(NAME_ONLY_AUTOCLOSE)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: FILECLOSE
[ID]				CRC_FILECLOSE_CAP12610
[CRCWD7]			0x63CE3224
[Signature] 		NameSig(NAME_ONLY_FILECLOSE)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: FILESAVEAS
[ID]				CRC_FILESAVEAS_CAP12610
[CRCWD7]			0xE24B773F
[Signature] 		NameSig(NAME_ONLY_FILESAVEAS)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: TOOLSMACRO
[ID]				CRC_TOOLSMACRO_CAP12610
[CRCWD7]			0xD18BC6DE
[Signature] 		NameSig(NAME_ONLY_TOOLSMACRO)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: FILETEMPLATES
[ID]				CRC_FILETEMPLATES_CAP12610
[CRCWD7]			0x94140369
[Signature] 		NameSig(NAME_ONLY_FILETEMPLATES)
[NamedCRCSigEnd]


[NamedCRCSigStart]
[Comment]			WM.CAP: CAP
[ID]				CRC_CAP2_CAP12610
[CRCWD7]			0x94773550
[Signature] 		NameSig(NAME_ONLY_CAP)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: AUTOEXEC
[ID]				CRC_AUTOEXEC2_CAP12610
[CRCWD7]			0xC180D037
[Signature] 		NameSig(NAME_ONLY_AUTOEXEC)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: FILEOPEN
[ID]				CRC_FILEOPEN2_CAP12610
[CRCWD7]			0xA4673108
[Signature] 		NameSig(NAME_ONLY_FILEOPEN)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: FILESAVE
[ID]				CRC_FILESAVE2_CAP12610
[CRCWD7]			0x7F12163A
[Signature] 		NameSig(NAME_ONLY_FILESAVE)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: AUTOCLOSE
[ID]				CRC_AUTOCLOSE2_CAP12610
[CRCWD7]			0x8FB0E296
[Signature] 		NameSig(NAME_ONLY_AUTOCLOSE)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: FILECLOSE
[ID]				CRC_FILECLOSE2_CAP12610
[CRCWD7]			0x7F56C42E
[Signature] 		NameSig(NAME_ONLY_FILECLOSE)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: FILESAVEAS
[ID]				CRC_FILESAVEAS2_CAP12610
[CRCWD7]			0x83ACDAAC
[Signature] 		NameSig(NAME_ONLY_FILESAVEAS)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: TOOLSMACRO
[ID]				CRC_TOOLSMACRO2_CAP12610
[CRCWD7]			0xF08BB97D
[Signature] 		NameSig(NAME_ONLY_TOOLSMACRO)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.CAP: FILETEMPLATES
[ID]				CRC_FILETEMPLATES2_CAP12610
[CRCWD7]			0xD5FB8C89
[Signature] 		NameSig(NAME_ONLY_FILETEMPLATES)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]			WM.Mangled: AUTOOPEN
[ID]				CRC_AUTOOPEN_12630
[CRCWD7]			0xc0968141
[Signature] 		NameSig(NAME_ONLY_AUTOOPEN)
[NamedCRCSigEnd]

[MacroSigStart]
[Comment]		Macro /w all zeros in body.  We check if 1st 16 bytes are zero
[ID]			ZERO_MACRO
[Signature] 	SeekSet(0x00) 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
[Signature] 	0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
[MacroSigEnd]

[NamedCRCSigStart]
[Comment]           WM.Mangled: SHOW    jjw for CI 1480
[ID]                CRC_SHOW_1480
[CRCWD7]            0x3cbf6374
[Signature]         NameSig(NAME_ONLY_SHOW)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]           Mangled AutoOpen from WM.Schumann (CI 2139)
[ID]                CRC_AUTOOPEN_CI2139
[CRCWD7]            0x1cc82807
[Signature]         NameSig(NAME_ONLY_AUTOOPEN)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]       WM.Schumann corrupted #2275: INNLIB
[ID]            CRC_INNLIB_SCHUMANN2275
[CRCWD7]        0x2204c78d
[Signature]     NameSig(NAME_ONLY_INNLIB)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]       WM.Schumann corrupted #2275: FILEOPEN
[ID]            CRC_FILEOPEN_SCHUMANN2275
[CRCWD7]        0x83288894
[Signature]     NameSig(NAME_ONLY_FILEOPEN)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]       WM.Schumann corrupted #2275: FILESAVE
[ID]            CRC_FILESAVE_SCHUMANN2275
[CRCWD7]        0x12efd70b
[Signature]     NameSig(NAME_ONLY_FILESAVE)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]       WM.Schumann corrupted #2275: HILFEINFO
[ID]            CRC_HILFEINFO_SCHUMANN2275
[CRCWD7]        0x12f6a76b
[Signature]     NameSig(NAME_ONLY_HILFEINFO)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]       WM.Schumann corrupted #2275: INNOCENCE
[ID]            CRC_INNOCENCE_SCHUMANN2275
[CRCWD7]        0xf7ff5a35
[Signature]     NameSig(NAME_ONLY_INNOCENCE)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]       WM.Schumann corrupted #2275: FILESAVEAS
[ID]            CRC_FILESAVEAS_SCHUMANN2275
[CRCWD7]        0xb4a86e47
[Signature]     NameSig(NAME_ONLY_FILESAVEAS)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]       WM.Schumann corrupted #2275: TOOLSMACRO
[ID]            CRC_TOOLSMACRO_SCHUMANN2275
[CRCWD7]        0x1426731e
[Signature]     NameSig(NAME_ONLY_TOOLSMACRO)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]       WM.Schumann corrupted #2275: DATEIOFFNEN
[ID]            CRC_DATEIOFFNEN_SCHUMANN2275
[CRCWD7]        0x252cb3df
[Signature]     NameSig(NAME_ONLY_DATEIOFFNEN)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]       WM.Schumann corrupted #2275: DATEISPEICHERN
[ID]            CRC_DATEISPEICHERN_SCHUMANN2275
[CRCWD7]        0x1c481bbd
[Signature]     NameSig(NAME_ONLY_DATEISPEICHERN)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]       WM.Schumann corrupted #2275: DATEISPEICHERNUNTER
[ID]            CRC_DATEISPEICHERNUNTER_SCHUMANN2275
[CRCWD7]        0x356621c1
[Signature]     NameSig(NAME_ONLY_DATEISPEICHERNUNTER)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]           WM.Niknat upconvert: AutoClose  (CI 1679)
[ID]                CRC_AUTOCLOSE_NIKNAT_CI1679
[CRCWD8]            0x8328170c
[Signature]         NameSig(NAME_ONLY_AUTOCLOSE)
[NamedCRCSigEnd]

[NamedCRCSigStart]
[Comment]           WM.Niknat upconvert: DCLOSEAN  (CI 1679)
[ID]                CRC_DCLOSEAN_NIKNAT_CI1679
[CRCWD8]            0x8328170c
[Signature]         NameSig(NAME_ONLY_DCLOSEAN)
[NamedCRCSigEnd]

[UnknownVirusSigStart]
[Comment]       Macro Trashcan (WD8)
[Type]          WD8
[QAStatus]		PASSED
[ID]            VID_WM_TRASH2
[Signature] 	MacroCount(<0) and
[Signature]     NamedCRCSig(CRC_AUTOCLOSE_NIKNAT_CI1679) and
[Signature]     NamedCRCSig(CRC_DCLOSEAN_NIKNAT_CI1679)
[Repair]        NoRepair
[UnknownVirusSigEnd]

[UnknownVirusSigStart]
[Comment]		Macro Trashcan ;won't hit on anything since MacroCount < 0
[Type]			WD7
[QAStatus]		PASSED
[ID]			VID_WM_TRASH1
[Signature] 	MacroCount(<0) and
[Signature] 	NamedCRCSig(CRC_FILESAVEAS_COLORSJUNK) and
[Signature] 	NamedCRCSig(CRC_TOOLSMACRO_COLORSJUNK) and
[Signature] 	NamedCRCSig(CRC_RPTM_COLORSV) and
[Signature] 	NamedCRCSig(CRC_TOOLSMACRO_COLORSVARIANT) and
[Signature] 	NamedCRCSig(CRC_AUTOOPEN_KOMPUVARIANT) and
#[Signature]	 NamedCRCSig(CRC_AUTOEXEC_CAPFRAG) and
#[Signature]	 NamedCRCSig(CRC_AUTOOPEN_CAPFRAG) and
#[Signature]	 NamedCRCSig(CRC_FILEOPEN_CAPFRAG) and
#[Signature]	 NamedCRCSig(CRC_FILESAVE_CAPFRAG) and
#[Signature]	 NamedCRCSig(CRC_AUTOCLOSE_CAPFRAG) and
#[Signature]	 NamedCRCSig(CRC_FILECLOSE_CAPFRAG) and
#[Signature]	 NamedCRCSig(CRC_FILESAVEAS_CAPFRAG) and
#[Signature]	 NamedCRCSig(CRC_TOOLSMACRO_CAPFRAG) and
#[Signature]	 NamedCRCSig(CRC_FILETEMPLATES_CAPFRAG) and
[Signature] 	NamedCRCSig(CRC_FILESAVEAS_DZTMANGLED) and
#[Signature]	 NamedCRCSig(CRC_AUTOOPEN_CAPMANGLED) and
#[Signature]	 NamedCRCSig(CRC_AUTOCLOSE_CAPMANGLED) and
#[Signature]	 NamedCRCSig(CRC_FILESAVE0_CAPA) and
#[Signature]	 NamedCRCSig(CRC_FILECLOSE0_CAPA) and
#[Signature]	 NamedCRCSig(CRC_FILESAVEAS_CAPA) and
#[Signature]	 NamedCRCSig(CRC_AUTOEXEC_CAPA) and
#[Signature]	 NamedCRCSig(CRC_FILEOPEN_CAPA) and
#[Signature]	 NamedCRCSig(CRC_AUTOOPEN_CAPA) and
#[Signature]	 NamedCRCSig(CRC_FILESAVE1_CAPA) and
#[Signature]	 NamedCRCSig(CRC_AUTOCLOSE_CAPA) and
[Signature] 	NamedCRCSig(CRC_FILESAVEAS_JUNKMACRO) and
[Signature] 	NamedCRCSig(CRC_MSRUN_TRASH) and
[Signature] 	NamedCRCSig(CRC_CAP_CAP12598) and
[Signature] 	NamedCRCSig(CRC_FILEOPEN_CAP12598) and
[Signature] 	NamedCRCSig(CRC_FILESAVE_CAP12598) and
[Signature] 	NamedCRCSig(CRC_AUTOCLOSE_CAP12598) and
[Signature] 	NamedCRCSig(CRC_FILECLOSE_CAP12598) and
[Signature] 	NamedCRCSig(CRC_FILESAVEAS_CAP12598) and
[Signature] 	NamedCRCSig(CRC_TOOLSMACRO_CAP12598) and
[Signature] 	NamedCRCSig(CRC_FILETEMPLATES_CAP12598) and
[Signature] 	NamedCRCSig(CRC_CAP_CAP12610) and
[Signature] 	NamedCRCSig(CRC_AUTOOPEN_CAP12610) and
[Signature] 	NamedCRCSig(CRC_FILEOPEN_CAP12610) and
[Signature] 	NamedCRCSig(CRC_FILESAVE_CAP12610) and
[Signature] 	NamedCRCSig(CRC_AUTOCLOSE_CAP12610) and
[Signature] 	NamedCRCSig(CRC_FILECLOSE_CAP12610) and
[Signature] 	NamedCRCSig(CRC_FILESAVEAS_CAP12610) and
[Signature] 	NamedCRCSig(CRC_TOOLSMACRO_CAP12610) and
[Signature] 	NamedCRCSig(CRC_FILETEMPLATES_CAP12610) and
[Signature] 	NamedCRCSig(CRC_AUTOEXEC_CAP12610) and
[Signature] 	NamedCRCSig(CRC_CAP2_CAP12610) and
[Signature] 	NamedCRCSig(CRC_FILEOPEN2_CAP12610) and
[Signature] 	NamedCRCSig(CRC_FILESAVE2_CAP12610) and
[Signature] 	NamedCRCSig(CRC_AUTOCLOSE2_CAP12610) and
[Signature] 	NamedCRCSig(CRC_FILECLOSE2_CAP12610) and
[Signature] 	NamedCRCSig(CRC_FILESAVEAS2_CAP12610) and
[Signature] 	NamedCRCSig(CRC_TOOLSMACRO2_CAP12610) and
[Signature] 	NamedCRCSig(CRC_FILETEMPLATES2_CAP12610) and
[Signature] 	NamedCRCSig(CRC_AUTOEXEC2_CAP12610) and
[Signature] 	NamedCRCSig(CRC_CAP_CAP12638) and
[Signature] 	NamedCRCSig(CRC_AUTOOPEN_12630) and
[Signature] 	MacroSig(ZERO_MACRO) and
[Signature] 	NamedCRCSig(CRC_AUTOEXEC_CAP12598) and
#following CRC removed since the same CRC is now a part of WM.Appder.G - AO 7/7/97
#[Signature]	 NamedCRCSig(CRC_APPDER_APPDERMANGLED)
#add new trash signatures here
[Signature]     NamedCRCSig(CRC_SHOW_1480) and
[Signature]     NamedCRCSig(CRC_AUTOOPEN_CI2139) and
[Signature]     NamedCRCSig(CRC_INNLIB_SCHUMANN2275) and
[Signature]     NamedCRCSig(CRC_FILEOPEN_SCHUMANN2275) and
[Signature]     NamedCRCSig(CRC_FILESAVE_SCHUMANN2275) and
[Signature]     NamedCRCSig(CRC_HILFEINFO_SCHUMANN2275) and
[Signature]     NamedCRCSig(CRC_INNOCENCE_SCHUMANN2275) and
[Signature]     NamedCRCSig(CRC_FILESAVEAS_SCHUMANN2275) and
[Signature]     NamedCRCSig(CRC_TOOLSMACRO_SCHUMANN2275) and
[Signature]     NamedCRCSig(CRC_DATEIOFFNEN_SCHUMANN2275) and
[Signature]     NamedCRCSig(CRC_DATEISPEICHERN_SCHUMANN2275) and
[Signature]     NamedCRCSig(CRC_DATEISPEICHERNUNTER_SCHUMANN2275)
[Repair]        NoRepair
[UnknownVirusSigEnd]


######################################################################
# The following detects that ALL macros in a document are known
# to be a part of a known virus.
# This signature renders other remnant detection useless.
######################################################################
# This signature MUST BE THE NEXT TO LAST in Unknown Macro Sigs
######################################################################

[UnknownVirusSigStart]
[Comment]		Macro Component Virus (works for Remnants, too)
[Type]          WD7 WD8
[QAStatus]		PASSED
[ID]			VID_FULL_SET
[Signature] 	FullSet()
[Repair]		FullSetRepair
[UnknownVirusSigEnd]


######################################################################
# HEURISTIC CALL OFF SIGNATURE
######################################################################
# This signature MUST BE THE ABSOLUTE LAST in Unknown Macro Sigs
######################################################################

# This macro signature looks for a MacroCopy call which is
# represented as 0x67 0xC2 0x80 in Little Endian form.
#
# The signature first looks for 0xC2 which is expected to be rare
# compared to 0x67.  It then looks for 0x80 after it, then lastly
# it seeks back to verify the 0x67.
[MacroSigStart]
[Comment]
[ID]            MACRO_SIG_MACROCOPY_0
[Signature] 	0xC2 0x80 SeekCur(-3) 0x67
[NotFullSet]
[MacroSigEnd]

# This macro signature looks for a MacroCopy call which is
# represented as 0x67 0x80 0xC2 in Big Endian form.
#
# The signature first looks for 0xC2 which is expected to be rare
# compared to 0x67.  It then looks for 0x67 0x80 before it.
[MacroSigStart]
[Comment]
[ID]            MACRO_SIG_MACROCOPY_1
[Signature]     0xC2 SeekCur(-3) 0x67 0x80
[NotFullSet]
[MacroSigEnd]

# This macro signature looks for an Organizer .Copy
# call which is represented in Little Endian form as:
# 0x67 0xDE 0x00 ...            Organizer
# 0x73 0x87 0x02 ...            .Copy
#
# The signature first looks for 0xDE which is expected to be rare
# compared to 0x67.  It then looks for 0x00 after it, then
# it seeks back to verify the 0x67.  The .Copy is searched for
# within a 255 byte window.
[MacroSigStart]
[Comment]
[ID]            MACRO_SIG_ORGANIZER_COPY_0
[Signature]     0xDE 0x00 SeekCur(-3) 0x67
[Signature]     ScanString(255, 0x73 0x87 0x02)
[NotFullSet]
[MacroSigEnd]

# This macro signature looks for an Organizer .Copy
# call which is represented in as Big Endian form as:
# 0x67 0x00 0xDE ...            Organizer
# 0x73 0x02 0x87 ...            .Copy
#
# The signature first looks for 0xDE which is expected to be rare
# compared to 0x67.  It then looks for 0x00 before it, then
# it seeks back to verify the 0x67.  The .Copy is searched for
# within a 255 byte window.
[MacroSigStart]
[Comment]
[ID]            MACRO_SIG_ORGANIZER_COPY_1
[Signature]     0xDE SeekCur(-3) 0x67 0x00
[Signature]     ScanString(255, 0x73 0x02 0x87)
[NotFullSet]
[MacroSigEnd]

# This macro signature looks for an Organizer .Tab = 3
# call which is represented in Little Endian form as:
# 0x67 0xDE 0x00 ...            Organizer
# 0x73 0x8F 0x03 ...            .Tab
# 0x0C ...                      =
# 0x6C 0x03 0x00                3
#
# The signature first looks for 0xDE which is expected to be rare
# compared to 0x67.  It then looks for 0x00 after it, then
# it seeks back to verify the 0x67. The .Tab is then searched for within
# a 255 byte window.  The = and 3 are searched for within a
# three byte window for each to allow for spaces around the = sign.
[MacroSigStart]
[Comment]
[ID]            MACRO_SIG_ORGANIZER_TAB3_0
[Signature]     0xDE 0x00 SeekCur(-3) 0x67
[Signature]     ScanString(255, 0x73 0x8F 0x03)
[Signature]     ScanString(3, 0x0C)
[Signature]     ScanString(3, 0x6C 0x03 0x00)
[NotFullSet]
[MacroSigEnd]

# This macro signature looks for an Organizer .Tab = 3
# call which is represented in as Big Endian form as:
# 0x67 0x00 0xDE ...            Organizer
# 0x73 0x03 0x8F ...            .Tab
# 0x0C ...                      =
# 0x6C 0x00 0x03                3
#
# The signature first looks for 0xDE which is expected to be rare
# compared to 0x67.  It then looks for 0x00 before it, then
# it seeks back to verify the 0x67. The .Tab is then searched for within
# a 255 byte window.  The = and 3 are searched for within a
# three byte window for each to allow for spaces around the = sign.
[MacroSigStart]
[Comment]
[ID]            MACRO_SIG_ORGANIZER_TAB3_1
[Signature]     0xDE SeekCur(-3) 0x67 0x00
[Signature]     ScanString(255, 0x73 0x03 0x8F)
[Signature]     ScanString(3, 0x0C)
[Signature]     ScanString(3, 0x6C 0x00 0x03)
[NotFullSet]
[MacroSigEnd]

# The signature looks for the presence of either a macrocopy or
# an organizer .copy.
[UnknownVirusSigStart]
[Comment]       Heuristic detection of Word 6.0/95 macro viruses
[Type]          WD7
[QAStatus]      HEU
[ID]            VID_MACRO_HEURISTICS
[Signature]     MacroSig(MACRO_SIG_MACROCOPY_0) or
[Signature]     MacroSig(MACRO_SIG_MACROCOPY_1) or
[Signature]     (MacroSig(MACRO_SIG_ORGANIZER_COPY_0) and
[Signature]      MacroSig(MACRO_SIG_ORGANIZER_TAB3_0)) or
[Signature]     (MacroSig(MACRO_SIG_ORGANIZER_COPY_1) and
[Signature]      MacroSig(MACRO_SIG_ORGANIZER_TAB3_1))
[Repair]        NoRepair
[UnknownVirusSigEnd]

#----------------------------------------------------------------
# Word 97
#----------------------------------------------------------------

# This macro signature looks for a MacroCopy call by searching
# for a lower case 'y' then seeks back nine characters to perform
# a case insensitive match for "macrocop"
[MacroSigStart]
[Comment]
[ID]            MACRO97_SIG_MACROCOPY0
[Signature]     'y' SeekCur(-9) ScanStringI(1,"macrocop")
[NotFullSet]
[MacroSigEnd]

# This macro signature looks for a MacroCopy call by searching
# for an upper case 'Y' then seeks back nine characters to perform
# a case insensitive match for "macrocop"
[MacroSigStart]
[Comment]
[ID]            MACRO97_SIG_MACROCOPY1
[Signature]     'Y' SeekCur(-9) ScanStringI(1,"macrocop")
[NotFullSet]
[MacroSigEnd]

# This macro signature looks for an Organizer Copy call by searching
# for a lower case 'z' followed by a case insensitive compare against
# the two character string "er", followed by a seek back of nine
# characters.  At the position the signature performs a case
# insensitive comparison against the string "organi".  If this
# succeeds the signature then performs a case insensitive scan
# for the string "copy" within a window of 200 characters.
[MacroSigStart]
[Comment]
[ID]            MACRO97_SIG_ORGANIZER_COPY0
[Signature]     'z' ScanStringI(1,"er") SeekCur(-9)
[Signature]     ScanStringI(1,"organi") ScanStringI(200,"copy")
[NotFullSet]
[MacroSigEnd]

# This macro signature looks for an Organizer Copy call by searching
# for a lower case 'z' followed by a case insensitive compare against
# the two character string "er", followed by a seek back of nine
# characters.  At the position the signature performs a case
# insensitive comparison against the string "organi".  If this
# succeeds the signature then performs a case insensitive scan
# for the string "tab" within a window of 200 characters.
# Following the "tab", the signature searches for a character in
# the range '0'-'3' within a window of 100 characters and verifies
# that the found character is a '3'
[MacroSigStart]
[Comment]
[ID]            MACRO97_SIG_ORGANIZER_TAB3_0
[Signature]     'z' ScanStringI(1,"er") SeekCur(-9)
[Signature]     ScanStringI(1,"organi") ScanStringI(200,"tab")
[Signature]     ScanSlide(100, '0'-'3') SeekCur(-1) '3'
[NotFullSet]
[MacroSigEnd]

# This macro signature looks for an Organizer Copy call by searching
# for a upper case 'Z' followed by a case insensitive compare against
# the two character string "er", followed by a seek back of nine
# characters.  At the position the signature performs a case
# insensitive comparison against the string "organi".  If this
# succeeds the signature then performs a case insensitive scan
# for the string "copy" within a window of 200 characters.
[MacroSigStart]
[Comment]
[ID]            MACRO97_SIG_ORGANIZER_COPY1
[Signature]     'Z' ScanStringI(1,"er") SeekCur(-9)
[Signature]     ScanStringI(1,"organi") ScanStringI(200,"copy")
[NotFullSet]
[MacroSigEnd]

# This macro signature looks for an Organizer Copy call by searching
# for an upper case 'Z' followed by a case insensitive compare against
# the two character string "er", followed by a seek back of nine
# characters.  At the position the signature performs a case
# insensitive comparison against the string "organi".  If this
# succeeds the signature then performs a case insensitive scan
# for the string "tab" within a window of 200 characters.
# Following the "tab", the signature searches for a character in
# the range '0'-'3' within a window of 100 characters and verifies
# that the found character is a '3'
[MacroSigStart]
[Comment]
[ID]            MACRO97_SIG_ORGANIZER_TAB3_1
[Signature]     'Z' ScanStringI(1,"er") SeekCur(-9)
[Signature]     ScanStringI(1,"organi") ScanStringI(200,"tab")
[Signature]     ScanSlide(100, '0'-'3') SeekCur(-1) '3'
[NotFullSet]
[MacroSigEnd]

# The signature looks for the presence of either a macrocopy or
# an organizer .copy.
[UnknownVirusSigStart]
[Comment]       Heuristic detection of Word 97 macro viruses
[Type]          WD8
[QAStatus]      HEU
[ID]            VID_MACRO_HEURISTICS
[Signature]     MacroSig(MACRO97_SIG_MACROCOPY0) or
[Signature]     MacroSig(MACRO97_SIG_MACROCOPY1) or
[Signature]     (MacroSig(MACRO97_SIG_ORGANIZER_COPY0) and
[Signature]      MacroSig(MACRO97_SIG_ORGANIZER_TAB3_0)) or
[Signature]     (MacroSig(MACRO97_SIG_ORGANIZER_COPY1) and
[Signature]      MacroSig(MACRO97_SIG_ORGANIZER_TAB3_1))
[Repair]        NoRepair
[UnknownVirusSigEnd]

################ W 7 H 2 #######################

# This macro signature looks for a FileSaveAs .Format call which is
# represented as 0x67 0x54 0x00 ... 0x73 0xCB 0x00
# in Little Endian form.
#
# The signature first looks for 0x54 which is expected to be rare
# compared to 0x67.  It then looks for 0x00 after it, then
# it seeks back to verify the 0x67.  This is the FileSaveAs part.
#
# For the .Format part, the function searches forward up to
# 255 bytes for it.
[MacroSigStart]
[Comment]
[ID]            MACRO_SIG_FILESAVEAS_FORMAT_0
[Signature]     0x54 0x00 SeekCur(-3) 0x67
[Signature]     ScanString(255, 0x73 0xCB 0x00)
[NotFullSet]
[MacroSigEnd]

# This macro signature looks for a FileSaveAs .Format call which is
# represented as 0x67 0x00 0x54 ... 0x73 0x00 0xCB
# in Big Endian form.
#
# The signature first looks for 0x54 which is expected to be rare
# compared to 0x67.  It then seeks back three and matches the
# 0x67 and 0x00.  This is the FileSaveAs part.
#
# For the .Format part, the function searches forward up to
# 255 bytes for it.
[MacroSigStart]
[Comment]
[ID]            MACRO_SIG_FILESAVEAS_FORMAT_1
[Signature]     0x54 SeekCur(-3) 0x67 0x00
[Signature]     ScanString(255, 0x73 0x00 0xCB)
[NotFullSet]
[MacroSigEnd]

# This macro signature looks for a .Edit which is
# represented as 0x73 0xF6 0x01 in Little Endian form.
#
# The signature first looks for 0xF6 which is expected to be rare
# compared to 0x73.  It then looks for 0x01 after it, then
# it seeks back to verify the 0x73.
[MacroSigStart]
[Comment]
[ID]            MACRO_SIG_EDIT_0
[Signature]     0xF6 0x01 SeekCur(-3) 0x73
[NotFullSet]
[MacroSigEnd]

# This macro signature looks for a .Edit which is
# represented as 0x73 0x01 0xF6 in Big Endian form.
#
# The signature first looks for 0xF6 which is expected to be rare
# compared to 0x73.  It then seeks back three and matches the
# 0x73 and 0x01.
[MacroSigStart]
[Comment]
[ID]            MACRO_SIG_EDIT_1
[Signature]     0xF6 SeekCur(-3) 0x73 0x01
[NotFullSet]
[MacroSigEnd]

# This macro signature looks for a GetDocumentVar$ which is
# represented as 0x67 0x4D 0x81 in Little Endian form.
#
# The signature first looks for 0x81 which is expected to be rare.
# If then seeks back three and matches the 0x67 and 0x4D.
[MacroSigStart]
[Comment]
[ID]            MACRO_SIG_GETDOCUMENTVARS_0
[Signature]     0x81 SeekCur(-3) 0x67 0x4D
[NotFullSet]
[MacroSigEnd]

# This macro signature looks for a GetDocumentVar$ which is
# represented as 0x67 0x81 0x4D in Big Endian form.
#
# The signature first looks for 0x81 which is expected to be rare.
# If then matches the 0x4D and finally seeks back three and matches
# the 0x67.
[MacroSigStart]
[Comment]
[ID]            MACRO_SIG_GETDOCUMENTVARS_1
[Signature]     0x81 0x4D SeekCur(-3) 0x67
[NotFullSet]
[MacroSigEnd]

# The signature looks for the presence of any of the following:
#       o FileSaveAs .Format
#       o .Edit
#       o GetDocumentVar$
[UnknownVirusSigStart]
[Comment]       Heuristic detection of Word 6.0/95 macro viruses
[Type]          WD7
[QAStatus]      HEU
[ID]            VID_W7H2
[Signature]     MacroSig(MACRO_SIG_FILESAVEAS_FORMAT_0) or
[Signature]     MacroSig(MACRO_SIG_FILESAVEAS_FORMAT_1) or
[Signature]     MacroSig(MACRO_SIG_EDIT_0) or
[Signature]     MacroSig(MACRO_SIG_EDIT_1) or
[Signature]     MacroSig(MACRO_SIG_GETDOCUMENTVARS_0) or
[Signature]     MacroSig(MACRO_SIG_GETDOCUMENTVARS_1)
[Repair]        NoRepair
[UnknownVirusSigEnd]
