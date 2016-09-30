////////////////////////
//
// PROPRIETARY / CONFIDENTIAL.
// Use of this product is subject to license terms.
// Copyright � 2006 Symantec Corporation.
// All rights reserved.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ccSymInterfaceLoader.h"
#include "ccSymPathProvider.h"
#include "ScanTask.h"

namespace AV
{
extern const LPCTSTR sz_AVScanTask_dll;

typedef CSymInterfaceDLLHelper<&sz_AVScanTask_dll,
                               ccSym::CNAVPathProvider, 
                               cc::CSymInterfaceTrustedCacheLoader,
                               IScanTask, 
                               &IID_IScanTask, 
                               &IID_IScanTask> AVScanTask_CScanTaskFactory;
} // end namespace AV