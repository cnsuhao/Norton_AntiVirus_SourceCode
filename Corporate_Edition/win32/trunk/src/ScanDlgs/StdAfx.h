// PROPRIETARY/CONFIDENTIAL. Use of this product is subject to license terms.
// Copyright (c) 2005 Symantec Corporation. All rights reserved.
// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

// Suppress warnings normally generated when using STL
#pragma warning(disable : 4786)
#pragma warning(disable : 4010)
#pragma warning(disable : 4018)
#pragma warning(disable : 4146)

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#define _WIN32_WINNT   0x0500  // We're targeting 2000 with IE 4
#define WINVER         0x0500
#define _WIN32_IE      0x0400

#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1

#include <new>

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE classes
#include <afxodlgs.h>       // MFC OLE dialog classes
#include <afxdisp.h>        // MFC OLE automation classes
#endif // _AFX_NO_OLE_SUPPORT


#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>			// MFC ODBC database classes
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>			// MFC DAO database classes
#endif // _AFX_NO_DAO_SUPPORT

#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls

#endif // _AFX_NO_AFXCMN_SUPPORT




