// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__54C0385C_754C_4D1F_81DC_B9A42FFD4916__INCLUDED_)
#define AFX_STDAFX_H__54C0385C_754C_4D1F_81DC_B9A42FFD4916__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_APARTMENT_THREADED

#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>
#include <atlstr.h>
#include <atlctl.h> // for scripting
#include <comdef.h> // for _bstr_t and other COM helpers

#include "NAVInfo.h"
#include "ccLib.h"

////////////////////////////////////////////////////////////////////// 
// disable warning C4786: symbol greater than 255 character,
// okay to ignore, MSVC chokes on STL templates!
#pragma warning(disable: 4786)

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__54C0385C_754C_4D1F_81DC_B9A42FFD4916__INCLUDED)
