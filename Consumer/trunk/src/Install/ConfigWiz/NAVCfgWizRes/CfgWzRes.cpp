////////////////////////
//
// PROPRIETARY / CONFIDENTIAL.
// Use of this product is subject to license terms.
// Copyright � 2006 Symantec Corporation.
// All rights reserved.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

// XXXRes.cpp : Defines the entry point for the DLL application.
//


#include "stdafx.h"
#include <InitGuid.h>
#define INITGUID
#define SIMON_INITGUID
#include <SIMON.h>
#include "NAVCfgWizDll_h.h"
#include "NAVCfgWizDll_i.c"
#include "uiPEPConstants.h"

#define INITIIDS
// Windows Defender Helper Header
#include "WndDefenderHelperImpl.h"

#include "ccVerifyTrustInterface.h"
#include "ccServicesConfigInterface.h"
#include "ccSettingsManagerHelper.h"
#include "IWPSettingsInterface.h"
#include "SymIDSI.h"
#include "ScanTaskLoader.h"
#include "AVInterfaces.h"
#include "AVInterfaceLoader.h"
#include "IMConfigInterface.h"
#include "IMConfigLoader.h"
#include "IICFManager.h"

// SymProtect helpers
#include "SymProtectControlHelperNAV.h"

// IElement stuff for AP
#include "ISDataClientLoader.h"
#include "uiNISDataElementGuids.h"
#include "uiProviderInterface.h"
#include "uiElementInterface.h"
#include "uiNumberDataInterface.h"
#include "APSRTSPLoader.h"

// custom interfaces
#include "isDataNoUIInterface.h"

// Firewall Related
#include "FWInterface.h"
#include "FWHelperInterface.h"
#include "SymNetInterface.h"
#include "snlocation.h"


// PEP Headers
#define _INIT_V2LICENSINGAUTHGUIDS
#define _V2AUTHORIZATION_SIMON
#define INIT_V2AUTHORIZATION_IMPL
#define _DRM_V2AUTHMAP_IMPL
#define _SIMON_PEP_
#define _PEP_IMPL_
#include "cltLicensePEPConstants.h"
#include "cltProdInfoPepConstants.h"
#include "CLTProductHelper.h"

#include "SymInterface.h"

#include "ICfgWizHelper.h"
#include "CCfgWizHelper.h"

#include "uiPEPEventInterface.h"

SIMON::CSimonModule _SimonModule;
HMODULE g_hModule = NULL;

BEGIN_SIMON_OBJECT_MAP(ObjectMap)
    SIMON_OBJECT_ENTRY(CLSID_CCfgWizHelper, CCfgWizHelper)
END_SIMON_OBJECT_MAP()

// SymInterface map for ccVerifyTrust static lib
SYM_OBJECT_MAP_BEGIN()                          
SYM_OBJECT_MAP_END()                            

CWaitForShutdown g_Shutdown;
CString _g_csHandlerPath;

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
            {
                // Performance Optimization: see MSDN docs on DisableThreadLibraryCalls() func.
                DisableThreadLibraryCalls((HMODULE)hModule);

                g_hModule = (HMODULE)hModule;
                _SimonModule.Init(ObjectMap);
                // Fetch the handler dll path
                ///////////////////////////////////////////////////////////////////////
                CString g_sModuleLocation;
                TCHAR _szModuleLocation[_MAX_PATH*2] = {0};
                long nRet =::GetModuleFileName(static_cast<HMODULE>(hModule),_szModuleLocation,sizeof(_szModuleLocation));
                ::GetShortPathName(_szModuleLocation,_szModuleLocation,sizeof(_szModuleLocation));
                CString g_sModuleFileName = _szModuleLocation;
                if(nRet != 0)
                {
                    g_sModuleLocation = _szModuleLocation;
                    TCHAR* pLast = _tcsrchr(_szModuleLocation,_T('\\'));
                    *pLast = _T('\0');
                    g_sModuleLocation = _szModuleLocation;
                }
                _g_csHandlerPath = g_sModuleLocation;
                _g_csHandlerPath += _T("\\NavOptRF.dll");
            }
            break;
		case DLL_THREAD_ATTACH:
            break;
		case DLL_THREAD_DETACH:
            break;
		case DLL_PROCESS_DETACH:
            {
                _SimonModule.Term();
            }
			break;
    }
    return TRUE;
}

HRESULT SIMON_STDMETHODCALLTYPE SimonGetClassObject(
  REFSIMON_CLSID rclsid,    //CLSID for the class object
  REFSIMON_IID riid,        //Reference to the identifier of the interface 
                            // that communicates with the class object
  void** ppv               //Address of output variable that receives the 
                            // interface pointer requested in riid
)
{
    return _SimonModule.GetClassObject(rclsid,riid,ppv);
}

LONG SIMON_STDMETHODCALLTYPE SimonModuleGetLockCount(void)
{
    return _SimonModule.GetLockCount();
}

