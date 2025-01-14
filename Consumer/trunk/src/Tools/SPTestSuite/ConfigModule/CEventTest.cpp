////////////////////////
//
// PROPRIETARY / CONFIDENTIAL.
// Use of this product is subject to license terms.
// Copyright � 2006 Symantec Corporation.
// All rights reserved.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
//#define INITIIDS
#include "CEventTest.h"
#include "BBEventID.h"
#include <vector>
#include <sstream> 

#define SYMPROTECT_EVENT_TIMEOUT_MS 30000
using namespace ccEvtMgr;
using namespace SymProtectEvt;
using namespace ATL;
#define MD5_DIGEST_SIZE 16
#define SHA_DIGEST_SIZE 20


CEventTest::CEventTest(void)
{
	if (CoInitializeEx(NULL, COINIT_APARTMENTTHREADED) == S_OK)
	{
		CCTRACEW(L"STARTING COM...\n");
	}
	else
	{
		CCTRACEW(L"Can not start COM, exiting...\n");
	}

    if (!Initialize()){
        CCTRACEW(L"Fail to init CEventTest!! \n");
        return;
    }
}

CEventTest::~CEventTest(void)
{
}

bool CEventTest::Initialize()
{
    return m_EventProvider.Initialize();
}
bool CEventTest::SendAddUser(const wchar_t* szAccountName)
{
    CEventExPtr pEvent;
    if( !m_EventProvider.GetNewEvent(IBBAuthorizedUsersSetEvent::TypeId, pEvent) )
        return false;

    if( SYM_FAILED(IBBAuthorizedUsersSetEventQIPtr(pEvent)->
        AddUser(szAccountName)) )
        return false;

    bool rt = m_EventProvider.SendConfigEvent(pEvent);
    size_t sz = 0;
    wchar_t* wstr = NULL;
    IBBAuthorizedUsersSetEventQIPtr(pEvent)->GetErrorString(wstr,sz);
    if (wstr)
        CCTRACEW(L"\npOutEvent return following string: %s\n",wstr);
    else
        CCTRACEW(L"\tNo error\n");
    return rt;
}

bool CEventTest::SendAddMD5Hash(const wchar_t* szHashName, const void* pHash, unsigned long ulFileLength)
{
    CEventExPtr pEvent;
    if( !m_EventProvider.GetNewEvent(IBBAuthorizedHashesSetEvent::TypeId, pEvent) )
        return false;

    if( SYM_FAILED(IBBAuthorizedHashesSetEventQIPtr(pEvent)->
        AddHash(szHashName, BB_HASH_MD5, pHash, 16, ulFileLength)) )
        return false;

    return m_EventProvider.SendConfigEvent(pEvent);
}

bool CEventTest::SendAddSHA1Hash(const wchar_t* szHashName, const void* pHash, unsigned long ulFileLength)
{
    CEventExPtr pEvent;
    if( !m_EventProvider.GetNewEvent(IBBAuthorizedHashesSetEvent::TypeId, pEvent) )
        return false;

    if( SYM_FAILED(IBBAuthorizedHashesSetEventQIPtr(pEvent)->
        AddHash(szHashName, BB_HASH_SHA1, pHash, 20, ulFileLength)) )
        return false;

    return m_EventProvider.SendConfigEvent(pEvent);
}

bool CEventTest::SendAddLocation(const wchar_t* szLocation, bool bFileOnly)
{
    CEventExPtr pEvent;
    if( !m_EventProvider.GetNewEvent(IBBAuthorizedLocationsSetEvent::TypeId, pEvent) )
    return false;

    if( SYM_FAILED(IBBAuthorizedLocationsSetEventQIPtr(pEvent)->
        AddLocation(szLocation, bFileOnly)) )
        return false;

    return m_EventProvider.SendConfigEvent(pEvent);
}
bool CEventTest::SendGetLocationCount(void)
{
    CEventEx* pOutEvent = NULL; 
    ULONG ulCount = 0;
    if (!SendQueryEvent(IBBAuthorizedLocationsQueryEvent::TypeId,pOutEvent))
        return false;
    if(SYM_FAILED(IBBAuthorizedLocationsQueryEventQIPtr(pOutEvent)->GetLocationCount(ulCount)))
        return false;
    CCTRACEW(L"There are total authorized locations :  %d\n", ulCount);
    return true;
}
bool CEventTest::SendGetLocationName(ULONG ulIndex)
{
    CEventEx* pOutEvent = NULL; 
    bool bDontAuthSubdirs = false;
    const wchar_t* ppszPath = NULL;

    if (!SendQueryEvent(IBBAuthorizedLocationsQueryEvent::TypeId,pOutEvent))
        return false;
    if(SYM_FAILED(IBBAuthorizedLocationsQueryEventQIPtr(pOutEvent)->
        GetLocation(ulIndex,&ppszPath,bDontAuthSubdirs)))
        return false;
    CCTRACEW(L"\tAuthorized locations Name is:  %s\n", ppszPath);
    if (bDontAuthSubdirs)
        CCTRACEW(L"\tbDontAuthSubdirs value is true\n");
    else
        CCTRACEW(L"\tbDontAuthSubdirs value is false\n");
    return true;
}

bool CEventTest::sendSetInstallSecurityLevel(int level)
{
    CEventExPtr pEvent;
    if( !m_EventProvider.GetNewEvent(IBBAuthorizedMSISetEvent::TypeId, pEvent) )
        return false;

    if( SYM_FAILED(IBBAuthorizedMSISetEventQIPtr(pEvent)->
        SetInstallSecurityLevel((SymProtectEvt::MSI_SECURITY_LEVEL)level)) )
        return false;
    return m_EventProvider.SendConfigEvent(pEvent);
}    
bool CEventTest::sendQueryInstallSecurityLevel(void)
{
    CEventEx* pEvent;
    CEventEx* pOutEvent = NULL;
    long nEventId;
    ccEvtMgr::CError::ErrorType ret;

    // Validate
    if( m_EventProvider.m_EventFactory == NULL )
    {
        CCTRACEE(L"CEventTest::SendConfigEvent() - m_EventProvider.m_EventFactory == NULL\n");
        ASSERT(FALSE);
        return false;
    }

    ret = m_EventProvider.m_EventManagerHelper.NewEvent(IBBAuthorizedMSIQueryEvent::TypeId, pEvent);
    if( ret != CError::eNoError || pEvent == NULL )
        return false;

    // Can't send the event as a broadcast event because we're relying on
    // synchronous delivery
    if( m_EventProvider.m_ProviderHelper.CreateEvent(*pEvent, false, 
                                     nEventId, NULL, 
                                     SYMPROTECT_EVENT_TIMEOUT_MS, TRUE, 
                                     pOutEvent) != CError::eNoError )
        return false;

    SymProtectEvt::MSI_SECURITY_LEVEL level = UNKNOWN_LEVEL;
    if(SYM_FAILED(IBBAuthorizedMSIQueryEventQIPtr(pOutEvent)->GetInstallSecurityLevel(level)))
        return false;
    CCTRACEW(L"\tCurrent install security level is : %d \n",(int)level);
    return true;

 }
bool CEventTest::sendQueryMSIAuthorizationCount(void)
{
    CEventEx* pEvent;
    CEventEx* pOutEvent = NULL;
    long nEventId;
    ccEvtMgr::CError::ErrorType ret;

    // Validate
    if( m_EventProvider.m_EventFactory == NULL )
    {
        CCTRACEE(L"CEventTest::SendConfigEvent() - m_EventProvider.m_EventFactory == NULL\n");
        ASSERT(FALSE);
        return false;
    }

    ret = m_EventProvider.m_EventManagerHelper.NewEvent(IBBAuthorizedMSIQueryEvent::TypeId, pEvent);
    if( ret != CError::eNoError || pEvent == NULL )
        return false;

    // Can't send the event as a broadcast event because we're relying on
    // synchronous delivery
    if( m_EventProvider.m_ProviderHelper.CreateEvent(*pEvent, false, 
                                     nEventId, NULL, 
                                     SYMPROTECT_EVENT_TIMEOUT_MS, TRUE, 
                                     pOutEvent) != CError::eNoError )
        return false;

    ULONG count = 0;
    if(SYM_FAILED(IBBAuthorizedMSIQueryEventQIPtr(pOutEvent)->GetAuthorizationCount(count)))
        return false;
    CCTRACEW(L"\tNumber of authorized MSIs is : %d \n",(ULONG)count);
    return true;

}


bool CEventTest::SendAddMSILocation(const wchar_t* szInstallLocation,const wchar_t* szInstallLocation2)
{
    CEventExPtr pEvent;
    if( !m_EventProvider.GetNewEvent(IBBAuthorizedMSISetEvent::TypeId, pEvent) )
        return false;

    if( SYM_FAILED(IBBAuthorizedMSISetEventQIPtr(pEvent)->
        AddAuthorization(SymProtectEvt::authPath,szInstallLocation,0)) )
        return false;
    if (szInstallLocation2){
        if( SYM_FAILED(IBBAuthorizedMSISetEventQIPtr(pEvent)->
            AddAuthorization(SymProtectEvt::authPath,szInstallLocation2,0)) )
            return false;
        }

    return m_EventProvider.SendConfigEvent(pEvent);
}

bool CEventTest::SendAddMSIGUID(const wchar_t* guid,const wchar_t* guid2)
{
    GUID gd,gd2;
	
    if (RPC_S_OK != UuidFromStringW( reinterpret_cast<unsigned short*>(const_cast<wchar_t*>(guid)), (GUID*)&gd ))
    {    
        CCTRACEW(L"\tCan not convert string to GUID, GUID is invalid: %s \n",guid);
        return false;
    }
    CEventExPtr pEvent;
    if( !m_EventProvider.GetNewEvent(IBBAuthorizedMSISetEvent::TypeId, pEvent) )
    {
        return false;
    }
    if( SYM_FAILED(IBBAuthorizedMSISetEventQIPtr(pEvent)->
        AddAuthorization(SymProtectEvt::authGUID,&gd,sizeof(GUID))) )
        return false;
    if (NULL != guid2){
        if (RPC_S_OK != UuidFromStringW( reinterpret_cast<unsigned short*>(const_cast<wchar_t *>(guid2)), (GUID*)&gd2 ))
        {    
            CCTRACEW(L"\tCan not convert string to GUID, GUID2 is invalid: %s \n",guid2);
            return false;
        }
        if( SYM_FAILED(IBBAuthorizedMSISetEventQIPtr(pEvent)->
            AddAuthorization(SymProtectEvt::authGUID,&gd2,sizeof(GUID))) )
            return false;
        }
    return m_EventProvider.SendConfigEvent(pEvent);
}
bool CEventTest::SendAddMSIGUIDLocation(const wchar_t* guid,const wchar_t* szInstallLocation)
{
    GUID gd;
    if (RPC_S_OK != UuidFromStringW( reinterpret_cast<unsigned short*>(const_cast<wchar_t*>(guid)), (GUID*)&gd ))
    {    
        CCTRACEW(L"\tCan not convert string to GUID, GUID is invalid: %s \n",guid);
        return false;
    }
    CEventExPtr pEvent;
    if( !m_EventProvider.GetNewEvent(IBBAuthorizedMSISetEvent::TypeId, pEvent) )
    {
        return false;
    }
    if( SYM_FAILED(IBBAuthorizedMSISetEventQIPtr(pEvent)->
        AddAuthorization(SymProtectEvt::authGUID,&gd,sizeof(GUID))) )
        return false;
    if( SYM_FAILED(IBBAuthorizedMSISetEventQIPtr(pEvent)->
        AddAuthorization(SymProtectEvt::authPath,szInstallLocation,0)) )
        return false;
    return m_EventProvider.SendConfigEvent(pEvent);
}

bool CEventTest::SendDeleteMSIGUID(const wchar_t* guid)
{
    GUID gd;
    if (RPC_S_OK != UuidFromStringW( reinterpret_cast<unsigned short*>(const_cast<wchar_t *>(guid)), (GUID*)&gd ))
    {
        CCTRACEW(L"\tCan not convert string to GUID, GUID is invalid %s\n",guid);
        return false;
    }
    CEventExPtr pEvent;
    if( !m_EventProvider.GetNewEvent(IBBAuthorizedMSISetEvent::TypeId, pEvent) )
        return false;
    if( SYM_FAILED(IBBAuthorizedMSISetEventQIPtr(pEvent)->
        DeleteAuthorization(SymProtectEvt::authGUID,&gd,sizeof(GUID))) )
        return false;
    return m_EventProvider.SendConfigEvent(pEvent);
}

bool CEventTest::SendDeleteMSILocation(const wchar_t* szInstallLocation)
{
    CEventExPtr pEvent;
    if( !m_EventProvider.GetNewEvent(IBBAuthorizedMSISetEvent::TypeId, pEvent) )
        return false;
    if( SYM_FAILED(IBBAuthorizedMSISetEventQIPtr(pEvent)->
        DeleteAuthorization(SymProtectEvt::authPath,szInstallLocation,0)) )
        return false;

    return m_EventProvider.SendConfigEvent(pEvent);
}

bool CEventTest::SendAddDeviceEnabled(unsigned long ulDeviceType)
{
    CEventExPtr pEvent;
    if( !m_EventProvider.GetNewEvent(IBBAuthorizedDevicesSetEvent::TypeId, pEvent) )
    return false;

    if( SYM_FAILED(IBBAuthorizedDevicesSetEventQIPtr(pEvent)->
        SetDeviceTypeAuthorization(ulDeviceType, true)) )
        return false;

    return m_EventProvider.SendConfigEvent(pEvent);
}
bool CEventTest::SendGetUserCount()
{
    CEventEx* pOutEvent = NULL; 
    ULONG ulCount = 0;
    if (!SendQueryEvent(IBBAuthorizedUsersQueryEvent::TypeId,pOutEvent))
        return false;
    if(SYM_FAILED(IBBAuthorizedUsersQueryEventQIPtr(pOutEvent)->GetUserCount(ulCount)))
        return false;
    CCTRACEW(L"\tThere are total users :  %d\n", ulCount);
    return true;
}
bool CEventTest::SendGetUserName(ULONG ulIndex)
{
    CEventEx* pOutEvent = NULL;
    const wchar_t* pszAccountName = NULL;
    if (!SendQueryEvent(IBBAuthorizedUsersQueryEvent::TypeId,pOutEvent))
        return false;
    if(SYM_FAILED(IBBAuthorizedUsersQueryEventQIPtr(pOutEvent)->GetUser(ulIndex,&pszAccountName)))
        return false;
    CCTRACEW(L"\tThe user name is :  %s\n", pszAccountName);
    return true;
}


bool CEventTest::SendGetDeviceStatus(unsigned long ulDeviceType)
{
    CEventEx* pOutEvent = NULL;
    bool bAuthorized = false;

    if (!SendQueryEvent(IBBAuthorizedDevicesQueryEvent::TypeId,pOutEvent))
        return false;
    if(SYM_FAILED(IBBAuthorizedDevicesQueryEventQIPtr(pOutEvent)
        ->GetDeviceTypeAuthorization(ulDeviceType,bAuthorized)))
        return false;
   
    if (bAuthorized)
        CCTRACEW(L"\tThe status of this device type is authorized. \n");
    else
        CCTRACEW(L"\tThe status of this device type is NOT authorized. \n");

    return true;
}

bool CEventTest::SendAddDeviceDisabled(unsigned long ulDeviceType)
{
    CEventExPtr pEvent;
    if( !m_EventProvider.GetNewEvent(IBBAuthorizedDevicesSetEvent::TypeId, pEvent) )
    return false;

    if( SYM_FAILED(IBBAuthorizedDevicesSetEventQIPtr(pEvent)->
        SetDeviceTypeAuthorization(ulDeviceType, false)) )
        return false;

    return m_EventProvider.SendConfigEvent(pEvent);
}

//bool CEventTest::SendAddInstallGuid(const GUID& iid)
//{
//    CEventExPtr pEvent;
//    if( !m_EventProvider.GetNewEvent(IBBAuthorizedInstallGuidsSetEvent::TypeId, pEvent) )
//        return false;

//    if( SYM_FAILED(IBBAuthorizedInstallGuidsSetEventQIPtr(pEvent)->
//        AddGuid(iid)) )
//        return false;

//    return m_EventProvider.SendConfigEvent(pEvent);
//}
bool CEventTest::SendSetSymProtectEnabled(bool bEnabled)
{
    CEventExPtr pNewEvent;
	if( !m_EventProvider.GetNewEvent(IBBSymProtectSetConfigEvent::TypeId, pNewEvent) )
	{
		CCTRACEW(L"GetNewEvent Failed \n");
        return false;
	}

    IBBSymProtectSetConfigEventQIPtr pEvent(pNewEvent);
    if( pEvent == NULL )
	{
		CCTRACEW(L"pEVent is null \n");
        return false;
	}

    if( SYM_FAILED(pEvent->SetSymProtectComponentState(bEnabled)) )
	{
		CCTRACEW(L"Sym Protect Component State Enable failed \n");
        return false;
	}

    return m_EventProvider.SendConfigEvent(CEventExQIPtr(pEvent));
}
bool CEventTest::SendSetFileProtection(bool bEnabled, bool bLogOnly)
{
    if( !bEnabled && bLogOnly )
        return false;

    CEventExPtr pNewEvent;
    if( !m_EventProvider.GetNewEvent(IBBSymProtectSetConfigEvent::TypeId, pNewEvent) )
        return false;

    IBBSymProtectSetConfigEventQIPtr pEvent(pNewEvent);
    if( pEvent == NULL )
        return false;

    SymProtectEvt::SP_PROTECTION_LEVEL eLevel;

    if( !bEnabled )
        eLevel = PROTECTION_DISABLED;
    else if( !bLogOnly )
        eLevel = PROTECTION_ENABLED;
    else
        eLevel = PROTECTION_LOG_ONLY;

    if( SYM_FAILED(pEvent->SetFileProtectionLevel(eLevel)) )
        return false;

    return m_EventProvider.SendConfigEvent(CEventExQIPtr(pEvent));
}
bool CEventTest::SendSetRegistryProtection(bool bEnabled, bool bLogOnly)
{
    if( !bEnabled && bLogOnly )
        return false;

    CEventExPtr pNewEvent;
    if( !m_EventProvider.GetNewEvent(IBBSymProtectSetConfigEvent::TypeId, pNewEvent) )
        return false;

    IBBSymProtectSetConfigEventQIPtr pEvent(pNewEvent);
    if( pEvent == NULL )
        return false;

    SymProtectEvt::SP_PROTECTION_LEVEL eLevel;

    if( !bEnabled )
        eLevel = PROTECTION_DISABLED;
    else if( !bLogOnly )
        eLevel = PROTECTION_ENABLED;
    else
        eLevel = PROTECTION_LOG_ONLY;

    if( SYM_FAILED(pEvent->SetRegistryProtectionLevel(eLevel)) )
        return false;

    return m_EventProvider.SendConfigEvent(CEventExQIPtr(pEvent));
}

bool CEventTest::SendSetProcessProtection(bool bEnabled, bool bLogOnly)
{
    if( !bEnabled && bLogOnly )
        return false;

    CEventExPtr pNewEvent;
    if( !m_EventProvider.GetNewEvent(IBBSymProtectSetConfigEvent::TypeId, pNewEvent) )
        return false;

    IBBSymProtectSetConfigEventQIPtr pEvent(pNewEvent);
    if( pEvent == NULL )
        return false;

    SymProtectEvt::SP_PROTECTION_LEVEL eLevel;

    if( !bEnabled )
        eLevel = PROTECTION_DISABLED;
    else if( !bLogOnly )
        eLevel = PROTECTION_ENABLED;
    else
        eLevel = PROTECTION_LOG_ONLY;

    if( SYM_FAILED(pEvent->SetProcessProtectionLevel(eLevel)) )
        return false;

    return m_EventProvider.SendConfigEvent(CEventExQIPtr(pEvent));
}


//Named Object Protection
bool CEventTest::SendSetNamedObjectProtection(bool bEnabled, bool bLogOnly)
{
    if( !bEnabled && bLogOnly )
        return false;

    CEventExPtr pNewEvent;
    if( !m_EventProvider.GetNewEvent(IBBSymProtectSetConfigEvent2::TypeId, pNewEvent) )
        return false;

    IBBSymProtectSetConfigEvent2QIPtr pEvent(pNewEvent);
    if( pEvent == NULL )
        return false;

    SymProtectEvt::SP_PROTECTION_LEVEL eLevel;

    if( !bEnabled )
        eLevel = PROTECTION_DISABLED;
    else if( !bLogOnly )
        eLevel = PROTECTION_ENABLED;
    else
        eLevel = PROTECTION_LOG_ONLY;

    if( SYM_FAILED(pEvent->SetNamedObjectProtectionLevel(eLevel)) )
        return false;

    return m_EventProvider.SendConfigEvent(CEventExQIPtr(pEvent));
}

bool CEventTest::SendStartSymProtect()
{
    return SendSetSymProtectEnabled(true);
}

bool CEventTest::SendStopSymProtect()
{
    return SendSetSymProtectEnabled(false);
}

bool CEventTest::SendRefreshManifests()
{
    return SendConfigEvent(CManifestChangeEventEx::TypeId);
}

bool CEventTest::SendUpdateEvent()
{
    return SendConfigEvent(CReloadDllEventEx::TypeId);
}

bool CEventTest::SendGetSymProtectStatus()
{
    SymProtectEvt::CQueryStateEventEx::SP_QUERY_STATE 
        st = GetSymProtectStatus();        
    switch (st)
        {
            default:
                CCTRACEW(L"\twe got unknow SymProtect status, %d\n", st);
                break;
            case SymProtectEvt::CQueryStateEventEx::SP_STATE_OFF:// SymProtect is operating correctly, driver and service are not loaded.
                CCTRACEW(L"\tstatus of SymProtect is SP_STATE_OFF,SymProtect is operating correctly, driver and service are not loaded.\n");
                break;
            case SymProtectEvt::CQueryStateEventEx::SP_STATE_ON:// SymProtect is operating correctly, driver and service are loaded.
                CCTRACEW(L"\tstatus of SymProtect is SP_STATE_ON,SymProtect is operating correctly, driver and service are loaded.\n");
                break;
            case SymProtectEvt::CQueryStateEventEx::SP_STATE_UPDATING:// SymProtect is being updated, driver and service are not loaded.
                CCTRACEW(L"\tstatus of SymProtect is SP_STATE_UPDATING,SymProtect is being updated, driver and service are not loaded.\n");
                break;
            case SymProtectEvt::CQueryStateEventEx::SP_STATE_ERROR_ON:// SymProtect is intended to be active, but not operating correctly, driver and service are not loaded.
                CCTRACEW(L"\tstatus of SymProtect is SP_STATE_ERROR_ON,SymProtect is intended to be active, but not operating correctly, driver and service are not loaded.\n");
                break;
            case SymProtectEvt::CQueryStateEventEx::SP_STATE_ERROR_OFF:// SymProtect is not operating correctly, driver and service are not loaded.
                CCTRACEW(L"\tstatus of SymProtect is SP_STATE_ERROR_OFF,SymProtect is not operating correctly, driver and service are not loaded.\n");
                break;
            case SymProtectEvt::CQueryStateEventEx::SP_STATE_ERROR_UNKNOWN:// Either the state is not present in ccSettings, it's corrupt, or no one responded to the query.
                CCTRACEW(L"\tstatus of SymProtect is SP_STATE_ERROR_UNKNOWN,Either the state is not present in ccSettings, it's corrupt, or no one responded to the query.\n");
                break;
        };
    return true;
}

SymProtectEvt::CQueryStateEventEx::SP_QUERY_STATE CEventTest::GetSymProtectStatus()
{
    CQueryStateEventEx::SP_QUERY_STATE curState = 
        CQueryStateEventEx::SP_STATE_ERROR_UNKNOWN;

    // Check that we've been properly initialized
    if( m_EventProvider.m_EventFactory == NULL )
    {
        CCTRACEE(L"CSymProtectControlProvider::GetSymProtectStatus() - m_pEventFactory == NULL\n");
        return CQueryStateEventEx::SP_STATE_ERROR_UNKNOWN;
    }

    // Create a new query state event
    CEventEx* pEvent = NULL;
    CEventEx* pOutEvent = NULL;
    CQueryStateEventExQIPtr pStateEvent;
    long nEventId;
    if( m_EventProvider.m_EventManagerHelper.NewEvent(CQueryStateEventEx::TypeId, pEvent)
        != CError::eNoError || pEvent == NULL )
    {
        CCTRACEE(L"CSymProtectControlProvider::GetSymProtectStatus() - m_EventManagerHelper.NewEvent() != eNoError\n");
        goto exit;
    }

    // Send out the event. Not broadcast!
    if( m_EventProvider.m_ProviderHelper.CreateEvent(*pEvent, false, nEventId, NULL, 
        SYMPROTECT_EVENT_TIMEOUT_MS, TRUE, pOutEvent) != CError::eNoError ||
        pOutEvent == NULL )
    {
        CCTRACEE(L"CSymProtectControlProvider::GetSymProtectStatus() - EvtProvider.CreateEvent() != eNoError\n");
        goto exit;
    }

    // Check out the returned query event
    pStateEvent = pOutEvent;
    if( pStateEvent == NULL )
    {
        CCTRACEE(L"CSymProtectControlProvider::GetSymProtectStatus() - FAILED: pStateEvent = pOutEvent");
        goto exit;
    }

    // Retrieve the current state
    if( SYM_FAILED(pStateEvent->GetSymProtectState(curState)) )
    {
        CCTRACEE(L"CSymProtectControlProvider::GetSymProtectStatus() - pStateEvent->GetSymProtectState() failed");
        curState = CQueryStateEventEx::SP_STATE_ERROR_UNKNOWN;
        goto exit;
    }

exit:
    if( pOutEvent )
        m_EventProvider.m_EventManagerHelper.DeleteEvent(pOutEvent);

    if( pEvent )
        m_EventProvider.m_EventManagerHelper.DeleteEvent(pEvent);

    return curState;
}
// Sends the event and checks that the application was successful
bool CEventTest::SendConfigEvent(long nEventType)
{
    CEventEx* pEvent;
    CEventEx* pOutEvent = NULL;
    long nEventId;
    ccEvtMgr::CError::ErrorType ret;

    // Validate
    if( m_EventProvider.m_EventFactory == NULL )
    {
        CCTRACEE(L"CEventTest::SendConfigEvent() - m_EventProvider.m_EventFactory == NULL\n");
        ASSERT(FALSE);
        return false;
    }

    ret = m_EventProvider.m_EventManagerHelper.NewEvent(nEventType, pEvent);
    if( ret != CError::eNoError || pEvent == NULL )
        return false;

    // Can't send the event as a broadcast event because we're relying on
    // synchronous delivery
    if( m_EventProvider.m_ProviderHelper.CreateEvent(*pEvent, false, 
                                     nEventId, NULL, 
                                     SYMPROTECT_EVENT_TIMEOUT_MS, TRUE, 
                                     pOutEvent) != CError::eNoError )
        {
            
            return false;
        }
    ISymBBSettingsEventQIPtr pSettingsEvent(pOutEvent);
    if( pSettingsEvent == NULL )
        return false;

    ISymBBSettingsEvent::ErrorTypes eError;
    if( SYM_FAILED(pSettingsEvent->GetResult(eError)) )
        return false;

    HRESULT hr = pSettingsEvent->GetOperationResult();

    // Check that the setting was applied correctly
    if( ISymBBSettingsEvent::UNRECOVERABLE_ERROR == eError ||
        FAILED(hr) )
    {
        return false;
    }

    // Ignore the output:
    if( pOutEvent )
        m_EventProvider.m_EventManagerHelper.DeleteEvent(pOutEvent);

    // Free the original event
    m_EventProvider.m_EventManagerHelper.DeleteEvent(pEvent);

    return true;
}
bool CEventTest::SendOldConfigEvent(long nEventType)
{
    CEventEx* pEvent;
    CEventEx* pOutEvent = NULL;
    long nEventId;
    ccEvtMgr::CError::ErrorType ret;

    // Validate
    if( m_EventProvider.m_EventFactory == NULL )
    {
        CCTRACEE(L"CEventTest::SendConfigEvent() - m_EventProvider.m_EventFactory == NULL\n");
        ASSERT(FALSE);
        return false;
    }

    ret = m_EventProvider.m_EventManagerHelper.NewEvent(nEventType, pEvent);
    if( ret != CError::eNoError || pEvent == NULL )
        return false;

    // Can't send the event as a broadcast event because we're relying on
    // synchronous delivery
    if( m_EventProvider.m_ProviderHelper.CreateEvent(*pEvent, false, 
                                     nEventId, NULL, 
                                     SYMPROTECT_EVENT_TIMEOUT_MS, TRUE, 
                                     pOutEvent) != CError::eNoError )
        {
            
            return false;
        }
    // Ignore the output:
    if( pOutEvent )
        m_EventProvider.m_EventManagerHelper.DeleteEvent(pOutEvent);

    // Free the original event
    m_EventProvider.m_EventManagerHelper.DeleteEvent(pEvent);

    return true;
}

bool CEventTest::SendDeleteUser(const wchar_t* szAccountName)
{
    CEventExPtr pEvent;
    if( !m_EventProvider.GetNewEvent(IBBAuthorizedUsersSetEvent::TypeId, pEvent) )
        return false;

    if( SYM_FAILED(IBBAuthorizedUsersSetEventQIPtr(pEvent)->
        DeleteUser(szAccountName)) )
        return false;

    return m_EventProvider.SendConfigEvent(pEvent);
}
bool CEventTest::SendDeleteLocation(const wchar_t* szLocation)
{
    CEventExPtr pEvent;
    if( !m_EventProvider.GetNewEvent(IBBAuthorizedLocationsSetEvent::TypeId, pEvent) )
    return false;

    if( SYM_FAILED(IBBAuthorizedLocationsSetEventQIPtr(pEvent)->
        DeleteLocation(szLocation)) )
        return false;

    return m_EventProvider.SendConfigEvent(pEvent);
}
bool CEventTest::SendDeleteHash(const wchar_t* szName)
{
    CEventExPtr pEvent;
    if( !m_EventProvider.GetNewEvent(IBBAuthorizedHashesSetEvent::TypeId, pEvent) )
        return false;

    if( SYM_FAILED(IBBAuthorizedHashesSetEventQIPtr(pEvent)->
        DeleteHash(szName)) )
        return false;
    return m_EventProvider.SendConfigEvent(pEvent);
}
bool CEventTest::SendGetHashCount()
{
    CEventEx* pOutEvent = NULL;
    ULONG count = 0;
    if (!SendQueryEvent(IBBAuthorizedHashesQueryEvent::TypeId,pOutEvent))
        return false;
    if(SYM_FAILED(IBBAuthorizedHashesQueryEventQIPtr(pOutEvent)->GetHashCount(count)))
        return false;
    CCTRACEW(L"\tTotal hash count is :  %d\n", count);
    return true;
}
bool CEventTest::SendGetHashName(ULONG ulIndex)
{
    CEventEx* pOutEvent = NULL;
    ULONG ulHashAlgorithm = 0;
    const wchar_t* ppszName = NULL;
    const void* ppHash = NULL;
    ULONG ulHashLength = 0;
    ULONG ulFileLength = 0;
    if (!SendQueryEvent(IBBAuthorizedHashesQueryEvent::TypeId,pOutEvent))
        return false;
    if(SYM_FAILED(IBBAuthorizedHashesQueryEventQIPtr(pOutEvent)
        ->GetHash(ulIndex,ulHashAlgorithm,&ppszName,&ppHash,ulHashLength,ulFileLength)))
        return false;
    //fprintf(stdout,_T"\tTotal hash count is :  %d\n", count);
    return true;
}


//bool CEventTest::SendDeleteInstallLocation(const wchar_t* szLocation)
//{
//    CEventExPtr pEvent;
//    if( !m_EventProvider.GetNewEvent(IBBAuthorizedLocationsSetEvent::TypeId, pEvent) )
//    return false;

//    if( SYM_FAILED(IBBAuthorizedLocationsSetEventQIPtr(pEvent)->
//        DeleteMSILocation(szLocation)) )
//        return false;

//    return m_EventProvider.SendConfigEvent(pEvent);
//}
bool CEventTest::SendQueryFileProtectionLevel()
{
    CEventEx* pOutEvent = NULL;
    SP_PROTECTION_LEVEL lvl;

    if (!SendQueryEvent(IBBSymProtectQueryConfigEvent::TypeId,pOutEvent))
        return false;
    if(SYM_FAILED(IBBSymProtectQueryConfigEventQIPtr(pOutEvent)->GetFileProtectionLevel(lvl)))
        return false;

    switch(lvl)
    {
        default:
            _tprintf(L"we got unknow file protection level: %d\n", lvl);
            break;
        case PROTECTION_DISABLED:
            _tprintf(L"\tFile Protection Level is PROTECTION_DISABLED\n");
            break;
        case PROTECTION_ENABLED:
            _tprintf(L"\tFile Protection Level is PROTECTION_ENABLED\n");
            break;
        case PROTECTION_LOG_ONLY:
            _tprintf(L"\tFile Protection Level is PROTECTION_LOG_ONLY\n");
            break;

    }
    m_EventProvider.m_EventManagerHelper.DeleteEvent(pOutEvent);
    return true;
}
bool CEventTest::SendQueryRegistryProtectionLevel()
{
    CEventEx* pOutEvent = NULL;
    SP_PROTECTION_LEVEL lvl;

    if (!SendQueryEvent(IBBSymProtectQueryConfigEvent::TypeId,pOutEvent))
        return false;
    if(SYM_FAILED(IBBSymProtectQueryConfigEventQIPtr(pOutEvent)->GetRegistryProtectionLevel(lvl)))
        return false;

    switch(lvl)
    {
        default:
            _tprintf(L"we got unknow Registry protection level: %d\n", lvl);
            break;
        case PROTECTION_DISABLED:
            _tprintf(L"\tRegistry Protection Level is PROTECTION_DISABLED\n");
            break;
        case PROTECTION_ENABLED:
            _tprintf(L"\tRegistry Protection Level is PROTECTION_ENABLED\n");
            break;
        case PROTECTION_LOG_ONLY:
            _tprintf(L"\tRegistry Protection Level is PROTECTION_LOG_ONLY\n");
            break;

    }
    m_EventProvider.m_EventManagerHelper.DeleteEvent(pOutEvent);
    return true;
}
bool CEventTest::SendQueryProcessProtectionLevel()
{
    CEventEx* pOutEvent = NULL;
    SP_PROTECTION_LEVEL lvl;
    if (!SendQueryEvent(IBBSymProtectQueryConfigEvent::TypeId,pOutEvent))
        return false;
    if(SYM_FAILED(IBBSymProtectQueryConfigEventQIPtr(pOutEvent)->GetProcessProtectionLevel(lvl)))
        return false;

    switch(lvl)
    {
        default:
            _tprintf(L"we got unknow process protection level: %d\n", lvl);
            break;
        case PROTECTION_DISABLED:
            _tprintf(L"\tProcess Protection Level is PROTECTION_DISABLED\n");
            break;
        case PROTECTION_ENABLED:
            _tprintf(L"\tProcess Protection Level is PROTECTION_ENABLED\n");
            break;
        case PROTECTION_LOG_ONLY:
            _tprintf(L"\tProcess Protection Level is PROTECTION_LOG_ONLY\n");
            break;

    }
    m_EventProvider.m_EventManagerHelper.DeleteEvent(pOutEvent);
    return true;
}
bool CEventTest::SendQueryNamedObjectProtectionLevel()
{
    CEventEx* pOutEvent = NULL;
    SP_PROTECTION_LEVEL lvl;

    if (!SendQueryEvent(IBBSymProtectQueryConfigEvent2::TypeId,pOutEvent))
        return false;
    if(SYM_FAILED(IBBSymProtectQueryConfigEvent2QIPtr(pOutEvent)->GetNamedObjectProtectionLevel(lvl)))
        return false;

    switch(lvl)
    {
        default:
            _tprintf(L"we got unknow named object protection level: %d\n", lvl);
            break;
        case PROTECTION_DISABLED:
            _tprintf(L"\tNamed object Protection Level is PROTECTION_DISABLED\n");
            break;
        case PROTECTION_ENABLED:
            _tprintf(L"\tNamed object Protection Level is PROTECTION_ENABLED\n");
            break;
        case PROTECTION_LOG_ONLY:
            _tprintf(L"\tNamed object Protection Level is PROTECTION_LOG_ONLY\n");
            break;

    }
    m_EventProvider.m_EventManagerHelper.DeleteEvent(pOutEvent);
    return true;
}
bool CEventTest::SendAddMD5Hash(const wchar_t* szHashName, const wchar_t* pHash_arg, unsigned long ulFileLength)
{
    const void *pHash = CharToBhash(pHash_arg,MD5);
    if (NULL == pHash)
        return false;
    return SendAddMD5Hash(szHashName, pHash,ulFileLength);
}
bool CEventTest::SendAddSHA1Hash(const wchar_t* szHashName, const wchar_t* pHash_arg, unsigned long ulFileLength)
{
    const void *pHash = CharToBhash(pHash_arg,SHA);
    if (NULL == pHash)
        return false;
    return SendAddSHA1Hash(szHashName, pHash,ulFileLength);
}

const void* CEventTest::CharToBhash(const wchar_t* pHash_arg,const HASHTYPE algorithm_arg){
    // Extract the hash as a string
    CStringW sHashValue(pHash_arg);
    // Convert the hash to binary form
    int iHashLength = sHashValue.GetLength();
    if (SHA == algorithm_arg && iHashLength!= 2*SHA_DIGEST_SIZE){
        _tprintf(L"\t!!The length of SHA hash value is not %d!!\n",2*SHA_DIGEST_SIZE);
        return NULL;}
    if (MD5 == algorithm_arg && iHashLength!= 2*MD5_DIGEST_SIZE){
        _tprintf(L"\t!!The length of MD5 hash value is not %d!!\n",2*MD5_DIGEST_SIZE);
        return NULL;}
     
    int cDwords = iHashLength / sizeof(DWORD);
    DWORD* pHashValue = new DWORD[cDwords];
    for( int i = 0; i < cDwords; ++i )
    {
        const int CHARS_PER_DWORD = sizeof(DWORD) * 2;
     //   pHashValue[i] = 
     //       _byteswap_ulong(wcstoul(sHashValue.Mid(i * CHARS_PER_DWORD, CHARS_PER_DWORD), NULL, 16));
    }
    return pHashValue;
}
bool CEventTest::SendSettingsValidation()
{
    return SendConfigEvent(ISymBBSettingsValidationEvent::TypeId);
}
bool CEventTest::SendConfigurationUpdate()
{
    return SendConfigEvent(CC_BB_CONFIGURATION_UPDATE_EVENT);
}
bool CEventTest::SendForceRefreshEvent()
{
    return SendConfigEvent(ISymBBSettingsForceRefreshEvent::TypeId);
}
bool CEventTest::SendGarbage()
{
    /*char temp[16]; 
    const void *pHash = (const void *)temp;
    return SendAddMD5Hash(L"Garbage", pHash, 0);*/
    return SendConfigEvent(BB_EVENT_ID_BASE + 26);
}
bool CEventTest::SendSystemNotify()
{
    return SendConfigEvent(CC_BB_SYSTEM_NOTIFY_EVENT);
}
bool CEventTest::SendOldStartEvent()
{
    return SendOldConfigEvent(CC_SYMPROTECT_START_EVENT);
}
bool CEventTest::SendOldStopEvent()
{
    return SendOldConfigEvent(CC_SYMPROTECT_STOP_EVENT);
}
bool CEventTest::SendQueryEvent(long EventType,CEventEx*& pOutEvent)
{
    CEventEx* pEvent;
    pOutEvent = NULL;
    long nEventId;
    ccEvtMgr::CError::ErrorType ret;

    // Validate
    if( m_EventProvider.m_EventFactory == NULL )
    {
        CCTRACEE(L"CEventTest::SendConfigEvent() - m_EventProvider.m_EventFactory == NULL\n");
        ASSERT(FALSE);
        return false;
    }

    ret = m_EventProvider.m_EventManagerHelper.NewEvent(EventType, pEvent);
    if( ret != CError::eNoError || pEvent == NULL )
        return false;

    // Can't send the event as a broadcast event because we're relying on
    // synchronous delivery
    if( m_EventProvider.m_ProviderHelper.CreateEvent(*pEvent, false, 
                                     nEventId, NULL, 
                                     SYMPROTECT_EVENT_TIMEOUT_MS, TRUE, 
                                     pOutEvent) != CError::eNoError )
        return false;
    m_EventProvider.m_EventManagerHelper.DeleteEvent(pEvent);    
    return true;
 }

bool CEventTest::SendIsSymProtectTemporarilyDisabled()
{
    CEventEx* pOutEvent = NULL;
    bool bEnabled;
    if (!SendQueryEvent(IBBSymProtectQueryConfigEvent::TypeId,pOutEvent))
        return false;
    if(SYM_FAILED(IBBSymProtectQueryConfigEventQIPtr(pOutEvent)->IsSymProtectTemporarilyDisabled(bEnabled)))
        return false;

	if(bEnabled)
		_tprintf(L"\tSymProtect is temporarily disabled\n");
	else
		_tprintf(L"\tSymProtect is NOT temporarily disabled\n");
    m_EventProvider.m_EventManagerHelper.DeleteEvent(pOutEvent);
    return true;
}

bool CEventTest::SendGetDisabledTimeRemaining()
{
    CEventEx* pOutEvent = NULL;
    unsigned int uMinutes = 0;
    if (!SendQueryEvent(IBBSymProtectQueryConfigEvent::TypeId,pOutEvent))
        return false;
    if(SYM_FAILED(IBBSymProtectQueryConfigEventQIPtr(pOutEvent)->GetDisabledTimeRemaining(uMinutes)))
        return false;
	_tprintf(L"\tDisabled time remaining is %u\n",uMinutes);
	m_EventProvider.m_EventManagerHelper.DeleteEvent(pOutEvent);
    return true;
}

bool CEventTest::SendGetSymProtectComponentState()
{
    CEventEx* pOutEvent = NULL;
    bool bEnabled, bError;
    if (!SendQueryEvent(IBBSymProtectQueryConfigEvent::TypeId,pOutEvent))
        return false;
    if(SYM_FAILED(IBBSymProtectQueryConfigEventQIPtr(pOutEvent)->GetSymProtectComponentState(bEnabled,bError)))
        return false;

	if( bEnabled )
    {
          if( bError )
				_tprintf(L"\tSymProtect is enabled with errors\n");
                    
          else
				_tprintf(L"\tSymProtect is enabled with no errors\n");
    }
    else
    {
          if( bError )
				_tprintf(L"\tSymProtect is disabled with errors\n");
          else
			    _tprintf(L"\tSymProtect is disabled with no errors\n");
    }
		
	m_EventProvider.m_EventManagerHelper.DeleteEvent(pOutEvent);
    return true;
}

bool CEventTest::SendDisableSymProtect(unsigned int uMinutes)
{
	CEventExPtr pNewEvent;
    if( !m_EventProvider.GetNewEvent(IBBSymProtectSetConfigEvent::TypeId, pNewEvent) )
        return false;

    IBBSymProtectSetConfigEventQIPtr pEvent(pNewEvent);
    if( pEvent == NULL )
        return false;

    SYMRESULT r;
        if( uMinutes > 0 )
            r = pEvent->DisableSymProtect(uMinutes);
        else
            r = pEvent->CancelDisableSymProtect();

        if( SYM_FAILED(r) )
        {
            _tprintf(L"\tDisableSymProtect failed\n");
            return false;
        }
    return m_EventProvider.SendConfigEvent(CEventExQIPtr(pEvent));
}

bool CEventTest::SendCancelDisableSymProtect()
{
	CEventExPtr pNewEvent;
    if( !m_EventProvider.GetNewEvent(IBBSymProtectSetConfigEvent::TypeId, pNewEvent) )
        return false;

    IBBSymProtectSetConfigEventQIPtr pEvent(pNewEvent);
    if( pEvent == NULL )
        return false;

    if( SYM_FAILED(pEvent->CancelDisableSymProtect()) )
        {
            _tprintf(L"\tcancel Disable Symprotect failed\n");
            return false;
        }
    return m_EventProvider.SendConfigEvent(CEventExQIPtr(pEvent));
}

bool CEventTest::SendSetSymProtectComponentState(const wchar_t* enabled)
{
	bool bEnabled;
	if (CString(enabled).CompareNoCase(L"enable")==0)
		bEnabled= true;
	else if (CString(enabled).CompareNoCase(L"disable")==0)
		bEnabled=false;
	else
	{
		_tprintf(L"\tPlease make sure you've enter either enable or disable\n");
		return false;
	}

	CEventExPtr pNewEvent;
    if( !m_EventProvider.GetNewEvent(IBBSymProtectSetConfigEvent::TypeId, pNewEvent) )
        return false;

    IBBSymProtectSetConfigEventQIPtr pEvent(pNewEvent);
    if( pEvent == NULL )
        return false;

	
	if( SYM_FAILED(pEvent->SetSymProtectComponentState(bEnabled)))
    {
       _tprintf(L"\tSetSymProtectComponentState failed\n");
       return false;
    }

    return m_EventProvider.SendConfigEvent(CEventExQIPtr(pEvent));
}
bool CEventTest::SendAddNotificationFilter ( const wchar_t* szFilterPath )
{
	CEventExPtr pNewEvent;
    if( !m_EventProvider.GetNewEvent(IBBSymProtectSetConfigEvent2::TypeId, pNewEvent) )
        return false;

    IBBSymProtectSetConfigEvent2QIPtr pEvent(pNewEvent);
    if( pEvent == NULL )
        return false;
	
	if( SYM_FAILED(pEvent->AddNotificationFilter(szFilterPath)))
    {
       _tprintf(L"\tAddNotificationFilter failed\n");
       return false;
    }

    return m_EventProvider.SendConfigEvent(CEventExQIPtr(pEvent));
}

bool CEventTest::SendDeleteNotificationFilter ( const wchar_t* szFilterPath )
{
	CEventExPtr pNewEvent;
    if( !m_EventProvider.GetNewEvent(IBBSymProtectSetConfigEvent2::TypeId, pNewEvent) )
        return false;

    IBBSymProtectSetConfigEvent2QIPtr pEvent(pNewEvent);
    if( pEvent == NULL )
        return false;
	
	if( SYM_FAILED(pEvent->DeleteNotificationFilter(szFilterPath)))
    {
       _tprintf(L"\tDeleteNotificationFilter failed\n");
       return false;
    }

    return m_EventProvider.SendConfigEvent(CEventExQIPtr(pEvent));
}

bool CEventTest::SendGetNotificationFilterCount ( void )
{    
    CEventEx* pOutEvent = NULL;
    ULONG ulCount = 0 ;
    if (!SendQueryEvent(IBBSymProtectQueryConfigEvent2::TypeId,pOutEvent))
        return false;
    if(SYM_FAILED(IBBSymProtectQueryConfigEvent2QIPtr(pOutEvent)->GetNotificationFilterCount(ulCount)))
        return false;

    CCTRACEW(L"\tTotal number of notification filters: %d\n", ulCount);
    return true;
}

bool CEventTest::SendGetNotificationFilter ( ULONG ulIndex )
{
    CEventEx* pOutEvent = NULL;
    const wchar_t* ppszPath = NULL;
    if (!SendQueryEvent(IBBSymProtectQueryConfigEvent2::TypeId,pOutEvent))
        return false;
    if(SYM_FAILED(IBBSymProtectQueryConfigEvent2QIPtr(pOutEvent)->GetNotificationFilter(ulIndex, &ppszPath)))
        return false;

    if ( ppszPath )
        CCTRACEW(L"\tFilter path is : %s\n", ppszPath);
    else
        CCTRACEW(L"\tGetNotificationFilter return NULL;\n");
    return true;
}


//Added by Ignatius
bool CEventTest::SendDetectedEvent()
{
    bool rt = m_EventProvider.SendConfigEvent(CC_BB_BEHAVIORBLOCKING_DETECTION_EVENT);
    if (rt)
        CCTRACEW(L"\nSendEvent Successful \n");
    else
        CCTRACEW(L"\tSendEvent failed\n");
    return rt;
}