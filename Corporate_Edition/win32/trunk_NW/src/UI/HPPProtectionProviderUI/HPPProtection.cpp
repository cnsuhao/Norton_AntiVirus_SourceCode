// PROPRIETARY/CONFIDENTIAL. Use of this product is subject to license terms.
// Copyright (c) 2006, Symantec Corporation, All rights reserved.
// HPPProtection.cpp : Implementation of CHPPProtection

#include "stdafx.h"
#include "HPPProtection.h"
#include "HPPRTSOptions.h"
#include "TrustUtil.h"

//*********************************************************************
//
//		**** CHPPProtection ****
//
//*********************************************************************

////////////////////////////////////////////////////////////////////////
// Function:    CHPPProtection::FinalConstruct
//
// Description: Final Constructor for the CHPPProtection.  This allows
//				for work after the object has been created.  We create
//				the IGenericConfig 
//
// Parameters:  none
//
// Returns:     HRESULT S_OK if successfull, noraml error codes if not.
//
//
///////////////////////////////////////////////////////////////////////////////
CHPPProtection::CHPPProtection()
{
	m_ptrGenConfig = NULL;
}



////////////////////////////////////////////////////////////////////////
// Function:    CHPPProtection::FinalConstruct
//
// Description: Final Constructor for the CHPPProtection.  This allows
//				for work after the object has been created.  We create
//				the IGenericConfig 
//
// Parameters:  none
//
// Returns:     HRESULT S_OK if successfull, noraml error codes if not.
//
//
///////////////////////////////////////////////////////////////////////////////
HRESULT CHPPProtection::FinalConstruct()
{
	HRESULT hRc = S_OK;

	DWORD dwType = CONFIG_TYPE_REALTIME;
	DWORD dwRootID = HKEY_VP_STORAGE_REALTIME;
	CString			strName= szReg_Key_SymHPPS;
	CString			strPageType;
	IGenericConfig	*ptrGenConfig = NULL;

    // Initialize trust checking
    hRc = trustVerifier.Initialize(CTrustVerifier::VerifyMode_CommonClient);
    if (FAILED(hRc))
        return hRc;

	// create the IGenericConfig
	if( SUCCEEDED( CoCreateLDVPObject( CLSID_CliProxy, IID_IGenericConfig, (void**)&ptrGenConfig ) ) ) 
	{
		// open up the config settings store
		DWORD dwErr = ptrGenConfig->Open( NULL, dwRootID, CT2A(strName.GetBuffer( strName.GetLength() )) , GC_MODEL_SINGLE /* flags ignored in Cli* objects */ );
		strName.ReleaseBuffer();					

		if( dwErr != 0 )
		{
			TRACE1("ERROR: Open on IGenericConfig returns 0x%X\n", dwErr );
//				AfxMessageBox( IDS_ERROR_NO_OPEN );
		}
		else
		{
			m_ptrGenConfig = ptrGenConfig;
		}
	}
	else
		hRc = E_FAIL;
	
	return hRc;
}
////////////////////////////////////////////////////////////////////////
// Function:    CHPPProtection::FinalRelease
//
// Description: Final Release for the CHPPProtection.  This allows
//				for work before the object is destroyed.  We release and
//				free up any interfaces we have stored.
//
// Parameters:  none
//
// Returns:     None
//
//
///////////////////////////////////////////////////////////////////////////////
void CHPPProtection::FinalRelease() 
{
    trustVerifier.Shutdown();

	// all done release it
	if (m_ptrGenConfig != NULL)
	{
		m_ptrGenConfig->Release();
		m_ptrGenConfig = NULL;
	}

}
HRESULT CHPPProtection::get_ID( GUID *  id)
{
	// Add your function implementation here.
	return E_NOTIMPL;
}
HRESULT CHPPProtection::get_DisplayName( BSTR *  shortName)
{
	CComBSTR shortNameCBSTR;

	// Validate parameter
	if (shortName == NULL)
		return E_INVALIDARG;

    // Validate caller security
    if (trustVerifier.IsCallerProcessTrusted() != S_OK)
        return E_ACCESSDENIED;

	// TODO try catch on the load string.
	shortNameCBSTR.LoadString(IDS_HPP_AP_PROTECTION);
	*shortName = shortNameCBSTR.Detach();

	return S_OK;
}
HRESULT CHPPProtection::get_Description( BSTR *  userDescription)
{
	CComBSTR shortNameCBSTR;

	// Validate parameter
	if (userDescription == NULL)
		return E_INVALIDARG;

    // Validate caller security
    if (trustVerifier.IsCallerProcessTrusted() != S_OK)
        return E_ACCESSDENIED;

	shortNameCBSTR.LoadString(IDS_HPP_AP_DESC);
	*userDescription = shortNameCBSTR.Detach();

	return S_OK;
}
HRESULT CHPPProtection::get_ProtectionStatus( ProtectionStatus *  currStatus)
{
	// this is to return the current status of the autoprotect.
	long lRTHPSstatus = 0;
	if (currStatus == NULL)
		return E_INVALIDARG;
	
    // Validate caller security
    if (trustVerifier.IsCallerProcessTrusted() != S_OK)
        return E_ACCESSDENIED;

	SAVASSERT(m_ptrGenConfig != NULL);
	if (m_ptrGenConfig != NULL)
		m_ptrGenConfig->GetIntOption(CT2CA(szReg_Val_SymHPPS_Enabled), &lRTHPSstatus , FALSE);
	if (lRTHPSstatus != FALSE)
		*currStatus = ProtectionStatus_On;
	else
		*currStatus = ProtectionStatus_Off;

	return S_OK;
}
HRESULT CHPPProtection::get_ProtectionStatusDescription( BSTR *  statusDescription)
{
	// Add your function implementation here.
	return E_NOTIMPL;
}
HRESULT CHPPProtection::get_ProtectionStatusReadOnly( VARIANT_BOOL *  isReadOnly)
{
	// Add your function implementation here.
	return E_NOTIMPL;
}
HRESULT CHPPProtection::get_ProtectionConfiguration( VARIANT_BOOL *  protectionEnabled)
{
	long lRTHPSstatus = 0;
	if (protectionEnabled == NULL)
		return E_INVALIDARG;
	
    // Validate caller security
    if (trustVerifier.IsCallerProcessTrusted() != S_OK)
        return E_ACCESSDENIED;

	SAVASSERT(m_ptrGenConfig != NULL);
	if (m_ptrGenConfig != NULL)
		m_ptrGenConfig->GetIntOption(CT2CA(szReg_Val_SymHPPS_Enabled), &lRTHPSstatus , FALSE);
	
	if (lRTHPSstatus != FALSE)
		*protectionEnabled = VARIANT_TRUE;
	else
		*protectionEnabled = VARIANT_FALSE;

	return S_OK;
}
HRESULT CHPPProtection::put_ProtectionConfiguration( VARIANT_BOOL  newStatus)
{
    BOOL bNewStatus   = FALSE;

    // Validate caller security
    if (trustVerifier.IsCallerProcessTrusted() != S_OK)
        return E_ACCESSDENIED;

	SAVASSERT(m_ptrGenConfig != NULL);
	bNewStatus = newStatus;
	if (m_ptrGenConfig != NULL)
		m_ptrGenConfig->SetOption(CT2CA(szReg_Val_SymHPPS_Enabled), REG_DWORD, reinterpret_cast<BYTE*>(&bNewStatus), sizeof(bNewStatus));

	return S_OK;
}
HRESULT CHPPProtection::ShowConfigureUI( HWND  parentWindowHandle)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
	DWORD dwType = CONFIG_TYPE_REALTIME;
	DWORD dwRootID = HKEY_VP_STORAGE_REALTIME;
	CString			strName= szReg_Key_SymHPPS;
	CString			strPageType;
	
	IGenericConfig	*ptrGenConfig = NULL;

    // Validate caller security
    if (trustVerifier.IsCallerProcessTrusted() != S_OK)
        return E_ACCESSDENIED;
	strPageType.LoadString( IDS_REALTIME_PROTECTION );

	CWnd *ptrParentWindow = new CWnd();

	ptrParentWindow->Attach(parentWindowHandle);
	CHPPRTSOptions dlgOptions(CONFIG_MODE_CLIENT,0,ptrParentWindow);

	if( SUCCEEDED( CoCreateLDVPObject( CLSID_CliProxy, IID_IGenericConfig, (void**)&ptrGenConfig ) ) ) 
		{
			DWORD dwErr = ptrGenConfig->Open( NULL, dwRootID, CT2A(strName.GetBuffer( strName.GetLength() )) , GC_MODEL_SINGLE /* flags ignored in Cli* objects */ );
			strName.ReleaseBuffer();					

			if( dwErr != 0 )
			{
				TRACE1("ERROR: Open on IGenericConfig returns. 0x%X\n", dwErr );
//				AfxMessageBox( IDS_ERROR_NO_OPEN );
			}
			else
				dlgOptions.SetIConfig(ptrGenConfig);
		}

	dlgOptions.DoModal();
	ptrGenConfig->WriteData(TRUE);
	ptrGenConfig->Release();	
	ptrParentWindow->Detach();
	delete ptrParentWindow;
    return S_OK;
}
HRESULT CHPPProtection::ShowLogUI( HWND  parentWindowHandle)
{
    // Validate caller security
    if (trustVerifier.IsCallerProcessTrusted() != S_OK)
        return E_ACCESSDENIED;

	MessageBox(NULL, _T("No log UI for HPP yes"), _T("Log UI"), MB_OK | MB_ICONINFORMATION);

	return S_OK;
}

