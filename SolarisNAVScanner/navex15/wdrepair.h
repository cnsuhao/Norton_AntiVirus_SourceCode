//************************************************************************
//
// $Header:   S:/NAVEX/VCS/wdrepair.h_v   1.4   11 May 1998 18:02:32   DCHI  $
//
// Description:
//
//************************************************************************
// $Log:   S:/NAVEX/VCS/wdrepair.h_v  $
// 
//    Rev 1.4   11 May 1998 18:02:32   DCHI
// Changes for menu repair.
// 
//    Rev 1.3   09 Jul 1997 16:27:20   DCHI
// Added prototype for WDIsHeuristicRepair().
// 
//    Rev 1.2   08 Apr 1997 12:40:54   DCHI
// Added support for FullSet(), FullSetRepair, Or()/Not(), MacroCount(), etc.
// 
//    Rev 1.1   14 Mar 1997 16:33:38   DCHI
// Added support for Office 97 repair.
// 
//    Rev 1.0   17 Jan 1997 11:25:02   DCHI
// Initial revision.
// 
//************************************************************************

#ifndef _WDREPAIR_H_

#define _WDREPAIR_H_

WD_STATUS WDApplyRepair
(
    LPWD_SIG_SET        lpstSigSet,
    LPWD_SCAN           lpstScan,
    LPBOOL              lpbDelete,
    WORD                wID,
    int                 nDepth
);

WD_STATUS WDRepairDoc
(
    LPWD_SIG_SET        lpstSigSet,
    LPWD_SCAN           lpstScan,
    LPWD_VIRUS_SIG_INFO lpstVirusSigInfo
);

BOOL WDIsHeuristicRepair
(
    LPWD_VIRUS_SIG_INFO lpstVirusSigInfo
);

BOOL WDIsFullSetRepair
(
    LPWD_VIRUS_SIG_INFO lpstVirusSigInfo
);

WD_STATUS WDDoFullSetRepair
(
    LPWD_SIG_SET        lpstSigSet,
    LPWD_SCAN           lpstScan
);

BOOL WD7DoMenuRepair
(
    LPWD_SIG_SET        lpstSigSet,
    LPWD_SCAN           lpstScan,
    LPSS_STREAM         lpstStream,
    LPWD7ENCKEY         lpstKey,
    LPWD7_TDT_INFO      lpstTDTInfo,
    LPWD_VIRUS_SIG_INFO lpstVirusSigInfo,
    int                 nDepth
);

#endif // #ifndef _WDREPAIR_H_

