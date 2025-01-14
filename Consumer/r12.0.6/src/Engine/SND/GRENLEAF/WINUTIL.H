//************************************************************************
//
// $Header:   S:/GRENLEAF/VCS/WINUTIL.H_v   1.0   12 Mar 1998 12:13:22   DCHI  $
//
// Description:
//  Greenleaf ArchiveLib 2.0
//
//************************************************************************
// $Log:   S:/GRENLEAF/VCS/WINUTIL.H_v  $
// 
//    Rev 1.0   12 Mar 1998 12:13:22   DCHI
// Initial revision.
// 
//************************************************************************

/*
 * WINUTIL.H
 *
 *  Header file for ArchiveLib 2.0
 *
 *  Copyright (c) 1994-1996 Greenleaf Software, Inc.
 *  All Rights Reserved
 *
 * DESCRIPTION
 *
 *  This header file contains the declaration for
 *  utility functions used under the Windows User Interface.
 *
 * CLASS DEFINITIONS:
 *
 *  None.
 *
 * REVISION HISTORY
 *
 *   February 14, 1996  2.0A : New release
 *
 */

#if !defined( _WINUTIL_H )
#define _WINUTIL_H

#ifdef __cplusplus
extern "C"
#endif

AL_LINKAGE void AL_CFUNCTION
EditDisplay( HWND hDlg, int id, char AL_DLL_FAR *fmt, ... );

#endif /* #if !defined( _WINUTIL_H ) */

