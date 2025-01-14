////////////////////////
//
// PROPRIETARY / CONFIDENTIAL.
// Use of this product is subject to license terms.
// Copyright � 2006 Symantec Corporation.
// All rights reserved.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#define _WIN32_WINNT 0x0400
#define VC_EXTRALEAN		

#include <afxwin.h>         
#include <afxcmn.h>

#include <atlbase.h>
extern CComModule _Module;
#include <atlcom.h>

#include <comdef.h>

#import "ccEventManager.tlb"
#import "NAVEvents.tlb"

// Identifier was truncated to x characters in the debug information
#pragma warning(disable:4786)

#include "ccLib.h"
