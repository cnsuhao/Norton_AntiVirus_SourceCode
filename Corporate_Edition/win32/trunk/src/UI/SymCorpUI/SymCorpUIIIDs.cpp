// SymCorpUIIIDs.cpp
// PROPRIETARY/CONFIDENTIAL. Use of this product is subject to license terms.
// Copyright 2004, 2005 Symantec Corporation. All rights reserved.
//

#include "stdafx.h"
#define INITIIDS
#include "ccVerifyTrustLoader.h"
#include "ccSymDebugOutput.h"
#include "ccCoInitialize.h"
#include "comcat.h"

// Instantiate CC's debug object and trace support - must do so or CC won't build
ccSym::CDebugOutput     g_DebugOutput(_T("SymCorpUI"));
IMPLEMENT_CCTRACE(g_DebugOutput)

// Declares any objects available from this process. Really the below is to
// get a g_DLLObjectCount instance created.
SYM_OBJECT_MAP_BEGIN()
SYM_OBJECT_MAP_END()
