/////////////////////////////////////////////////////////////////////////////////////////////
// PreInstall.cpp
//
// --Contains exported functions used in MSI custom actions for performing any pre-install
// tests before installing NAV
//
/////////////////////////////////////////////////////////////////////////////////////////////

//navinst headers
#include "helper.h"

//windows headers
#include <Wtsapi32.h>
#include <objbase.h>

//nav headers
#include "Instoptsnames.h"
#include "globalmutex.h"

//cc headers
//#include "SymReg.h"

//installtoolBox headers
#include "IE_Check.h"
#include "PathValidation.h"
#include "OSVerInfo.h"
#include "UnMark.h"
#include "NavDetection.h"
#include "utilities.h"
#include "fileaction.h"
#include "instopts.h"

// HPP headers
#include "HPPUtilityLoader.h"


using namespace InstallToolBox;


/////////////////////////////////////////////////////////////////////////////////////////////
// RemoveBackslashFromCommonAppDataDir(): removes the trailing backslash if it exists
//
/////////////////////////////////////////////////////////////////////////////////////////////
extern "C" __declspec(dllexport) UINT __stdcall RemoveBackslashes(MSIHANDLE hInstall)
{
#ifdef _DEBUG
	MessageBox(NULL, "Attach to this MessageBox to Debug RemoveBackslashes()", "Debug Break", NULL);
#endif

	g_Log.Log("RemoveBackslashes() Starting.");

	TCHAR szPath[MAX_PATH];
	DWORD dwSize = MAX_PATH;	

	dwSize = MAX_PATH;	
	if (MsiGetProperty(hInstall, _T("INSTALLDIR"), szPath, &dwSize) == ERROR_SUCCESS)
	{
		// remove the backslash with installtoolbox
		RemoveBackslash(szPath);
		MsiSetProperty(hInstall, _T("NOBACKSLASHINSTALLDIR"), szPath);	
	}

	g_Log.Log("RemoveBackslashes() Finished.");

	return S_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////
//  GetInstallType(): Checks if the install is Suite install
//
//  --if its a suite install, set the SuiteInstall RegKey to "1"
//
/////////////////////////////////////////////////////////////////////////////////////////////
extern "C" __declspec(dllexport) BOOL __stdcall GetInstallType(MSIHANDLE hInstall)
{
#ifdef _DEBUG
	MessageBox(NULL, "Attach to this MessageBox to Debug GetInstallType()", "Debug Break", NULL);
#endif

	g_Log.Log("GetInstallType() Starting.");
	
	TCHAR szInstallType[MAX_PATH]={0};
	DWORD dwSize = MAX_PATH;
	HKEY hKey;
	DWORD dwInstallType = 1;

	MsiGetProperty(hInstall, _T("NSW"), szInstallType, &dwSize);	
	
	if (atoi(szInstallType) == 1)
	{		
		if (RegCreateKeyEx(HKEY_LOCAL_MACHINE, szNAVAppsKey, NULL, 
							NULL, NULL, KEY_READ | KEY_WRITE, NULL, &hKey, NULL) == ERROR_SUCCESS)
		{			
			RegSetValueEx(hKey, _T("SuiteInstall"), NULL, REG_DWORD, (BYTE*)&dwInstallType, sizeof(dwInstallType));
		}

	}
	
	RegCloseKey(hKey);

	g_Log.Log("GetInstallType() Finished.");
	
	return ERROR_SUCCESS;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// SetSupportProperties(): sets the properties for the files in the support folder.
//  tell the msi where to find the installers for LU, LR, etc..
//
// TODO: since these installer will now be called by SymSetup instead of our MSI we can 
//	drop this function soon
/////////////////////////////////////////////////////////////////////////////////////////////
extern "C" __declspec(dllexport) UINT __stdcall SetSupportProperties(MSIHANDLE hInstall)
{
#pragma message("TODO: Remove SetSupportProperties once these are moved to symsetup")

#ifdef _DEBUG
	MessageBox(NULL, "Attach to this MessageBox to Debug SetSupportProperties()", "Debug Break", NULL);
#endif

	g_Log.Log("SetSupportProperties() Starting.");

	TCHAR szRootPath[MAX_PATH] = {0};
	TCHAR szLUPath[MAX_PATH] = {0};
	TCHAR szLRPath[MAX_PATH] = {0};
	TCHAR szAdvChkPath[MAX_PATH] = {0};
	TCHAR szAdvChkISSPath[MAX_PATH] = {0};
	DWORD dwSize = MAX_PATH;
	HKEY hKey;

	
	MsiGetProperty(hInstall, _T("SourceDir"), szRootPath, &dwSize);		
	
	// Chop off the directory we added, and another directory down.
	for(int i = 0; i < 2; i++)
	{
		TCHAR* pStr = _tcsrchr(szRootPath, _T('\\'));
		if(pStr != NULL)
			*pStr = _T('\0');
		else
			break;			
	}
		
	wsprintf(szLUPath, _T("%s\\Support\\LUpdate\\LUSETUP.EXE"), szRootPath);
	wsprintf(szLRPath, _T("%s\\Support\\LiveReg\\LRSETUP.EXE"), szRootPath);
	wsprintf(szAdvChkPath, _T("%s\\AdvTools\\SETUP.EXE"), szRootPath);
	wsprintf(szAdvChkISSPath, _T("%s\\AdvTools\\SETUP.ISS"), szRootPath);

	MsiSetProperty(hInstall, _T("LUPath"), szLUPath);
	MsiSetProperty(hInstall, _T("LRPath"), szLRPath);
	
	//
	// Set paths for AdvTools in the registry... We cannot set in MSI property, since
	// AdvTools custom actions are now deferred actions, so MSI property gets blown away.
	//
	// AlsoCheck to see if we upgraded NAV, this will be used in determining whether
	// or not to reboot.  This also must go into the registry
	//
	if (RegCreateKeyEx (HKEY_LOCAL_MACHINE, szNAVAppsKey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL) == ERROR_SUCCESS)
	{		
		RegSetValueEx(hKey, _T("AdvChkPath"), 0, REG_SZ, (BYTE*) &szAdvChkPath, sizeof(szAdvChkPath));
		RegSetValueEx(hKey, _T("AdvChkISSPath"), 0, REG_SZ, (BYTE*) &szAdvChkISSPath, sizeof(szAdvChkISSPath));
		RegCloseKey(hKey);
	}

	g_Log.Log("SetSupportProperties() Finished.");

	return ERROR_SUCCESS;

}

/////////////////////////////////////////////////////////////////////////////////////////////
// CheckForNoIcon(): checks the instopts.dat file for the no icon value. 
//
// --set the "NoIcon" property if the value is set in the instopts.dat file
// 
/////////////////////////////////////////////////////////////////////////////////////////////
extern "C" __declspec(dllexport) UINT __stdcall CheckForNoIcon(MSIHANDLE hInstall)
{
#ifdef _DEBUG
	MessageBox(NULL, "Attach to this MessageBox to Debug CheckForNoIcon()", "Debug Break", NULL);
#endif

	g_Log.Log("CheckForNoIcon() Starting.");

	TCHAR szInstopts[MAX_PATH] = {0};
	HNAVOPTS32 hOptions = NULL;	
	DWORD dwSize = MAX_PATH;
	DWORD dwValue = 0;
	HKEY hKey = NULL;
	bool bTempInstoptsFound = false;
	
	try
	{

		//
		// Find the instopts.dat file.  first check the regkey to see if setup made a copy of it
		// for OEM options.  otherwise use the one on the layout.
		//
		if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, INSTOPTS_LOCATION_KEY, 0, KEY_READ, &hKey) == ERROR_SUCCESS)
		{
			if(RegQueryValueEx(hKey, INSTOPTS_LOCATION_VALUE, NULL, NULL, (BYTE*)szInstopts, &dwSize) == ERROR_SUCCESS)
				bTempInstoptsFound = true;
			RegCloseKey(hKey);
		}
		if(!bTempInstoptsFound)
		{

			MsiGetProperty(hInstall, _T("SourceDir"), szInstopts, &dwSize);			
			wsprintf(szInstopts, _T("%s\\Instopts.dat"), szInstopts);
		}

		NAVOPTS32_STATUS Status = NavOpts32_Allocate(&hOptions);
		if (Status != NAVOPTS32_OK)
			throw runtime_error("Unable to initialize the options library.");

		// initialize the Instopts option file.
		Status = NavOpts32_Load(szInstopts, hOptions, true);
		if (Status != NAVOPTS32_OK)
			throw runtime_error("Unable to load the Instopts option file.");

		Status = NavOpts32_GetDwordValue(hOptions, INSTALL_NoIcon, &dwValue, 0);
		if (Status == NAVOPTS32_OK && dwValue == 1)
			MsiSetFeatureState(hInstall, _T("DesktopShortcut"), INSTALLSTATE_ABSENT);

		Status = NavOpts32_GetDwordValue(hOptions, INSTALL_NoUpsellIcon, &dwValue, 0);
		if (Status == NAVOPTS32_OK && dwValue == 1)
			MsiSetFeatureState(hInstall, _T("UpsellShortcut"), INSTALLSTATE_ABSENT);
		
		// the default is NOT to have an uninstall shortcut, so only add it
		Status = NavOpts32_GetDwordValue(hOptions, INSTALL_UninstallShortcut, &dwValue, 0);
		if (Status == NAVOPTS32_OK && dwValue == 1)
			MsiSetFeatureState(hInstall, _T("UninstallShortcut"), INSTALLSTATE_LOCAL);
		else
			MsiSetFeatureState(hInstall, _T("UninstallShortcut"), INSTALLSTATE_ABSENT);
	}
	catch(exception& ex)
	{
		g_Log.LogEx(ex.what());
	}
	catch(...)
	{
		g_Log.LogEx("Unknown exception in FilesMarkedForDeletionHelp().");
	}

    // Clean up
    if(hOptions)
        NavOpts32_Free(hOptions);
	
	g_Log.Log("CheckForNoIcon() Finished.");

	return ERROR_SUCCESS;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// DisableCommon(): something we found out is that Nested installs are not allowed to 
//	share components.  When NIS install NAV we need to not install all of the Common Common
//  Client merge modules & shared licensing merge modules, so we put them in a feature of their
//	own and do not install them if "NOCOMMON" property is set.
//
//	TODO: once we move away from being nested in our install under NIS and NSW we won't have
//	to worry about this anymore.  Remove this logic from the install after its been moved to
//	symsetup.
/////////////////////////////////////////////////////////////////////////////////////////////
extern "C" __declspec(dllexport) UINT __stdcall DisableCommon(MSIHANDLE hInstall)
{
#ifdef _DEBUG
	MessageBox(NULL, "Attach to this MessageBox to Debug DisableCommon()", "Debug Break", NULL);
#endif

	g_Log.Log("DisableCommon() Starting.");
	
	if(ERROR_SUCCESS  == MsiSetFeatureState(hInstall, _T("CommonClientShared"), INSTALLSTATE_ABSENT))
	{
		g_Log.Log("DisableCommon() Succeeded in turning off CommonClientShared Feature.");
	}
	else
	{
		g_Log.Log("DisableCommon() Failed to turn off CommonClientShared Feature.");
	}

	g_Log.Log("DisableCommon() Finished.");

	return ERROR_SUCCESS;
}

/////////////////////////////////////////////////////////////////////////////////////////////
//  SetReboot(): Sets a Reboot to be forced
//	checks various conditions to see if a reboot is needed.  this action must be the LAST
//	action to run in the Script generation sequence in order to work properly.  We will
//	honor any other components previous requests for a reboot UNLESS the noreboot option
//	has been set by an OEM vendor (they are aware of the potential issues and aggree to them).
//
//	TODO: resolve how this will fit into Symsetup's need to supress reboots.  May need to 
//	move this code to symsetup and have the MSI NEVER reboot...?
/////////////////////////////////////////////////////////////////////////////////////////////
extern "C" __declspec(dllexport) BOOL __stdcall SetReboot(MSIHANDLE hInstall)
{
#ifdef _DEBUG
	MessageBox(NULL, "Attach to this MessageBox to Debug SetReboot()", "Debug Break", NULL);
#endif

	g_Log.Log("SetReboot() Starting.");

	try
	{	
		SetSymSetupRebootKey(hInstall);
	}
	catch(exception& ex)
	{
		g_Log.LogEx(ex.what());
	}
	catch(...)
	{
		g_Log.LogEx("Unknown exception in SetReboot().");
	}

	g_Log.Log("SetReboot() Finished.");

	return ERROR_SUCCESS;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// ResolveShortcutDir():

/////////////////////////////////////////////////////////////////////////////////////////////
extern "C" __declspec(dllexport) UINT __stdcall ResolveShortcutDir(MSIHANDLE hInstall)
{
#ifdef _DEBUG
	MessageBox(NULL, "Attach to this MessageBox to Debug ResolveShortcutDir()", "Debug Break", NULL);
#endif

	try
	{
		CRegKey NAVKey;
		TCHAR szShortCutPath[MAX_PATH] = {0};
		DWORD dwSize = MAX_PATH;

		if(ERROR_SUCCESS == NAVKey.Open(HKEY_LOCAL_MACHINE, _T("Software\\Symantec\\Norton AntiVirus")))
		{
			if(ERROR_SUCCESS == NAVKey.QueryStringValue(_T("ShortcutPath"), szShortCutPath, &dwSize))
			{
				MsiSetProperty(hInstall, _T("NAV_SHORTCUT_MENU"), szShortCutPath);
			}
		}
	}
	catch(exception& ex)
	{
		g_Log.LogEx(ex.what());
	}
	catch(...)
	{
		g_Log.LogEx("Unknown exception in ResolveShortcutDir().");
	}

	return ERROR_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////
// CheckNoThreatCat():
//  checks the instopts.dat or navopts.dat (in the case of an
//  uninstall rollback) for whether or not Spyware/Adware detection
//  is enabled.  If not, we shouldn't install the NSC feature keys
//  that refer to Spyware protection.
//////////////////////////////////////////////////////////////////////////
extern "C" __declspec(dllexport) UINT __stdcall CheckNoThreatCat(MSIHANDLE hInstall)
{
	DWORD dwNoThreatCat = 0;

	if(ERROR_SUCCESS == InstallToolBox::CInstoptsDat::VerifyInstoptsPath())
	{
		InstallToolBox::CInstoptsDat InstOpts(hInstall);
		InstOpts.ReadDWORD(INSTALL_NoThreatCat, dwNoThreatCat, 0);
	}
	else
	{
		HKEY hKey = NULL;
		TCHAR szInstallDir[MAX_PATH] = {0};
		DWORD dwSize = MAX_PATH;
		LONG lRet;

		if(lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Symantec\\InstalledApps"), 0, KEY_READ, &hKey) == ERROR_SUCCESS)
		{
			if(RegQueryValueEx(hKey, _T("NAV"), NULL, NULL, (BYTE*)szInstallDir, &dwSize) == ERROR_SUCCESS)
			{                   
				TCHAR szNAVOptsDat[MAX_PATH] = {0};
				wsprintf(szNAVOptsDat, "%s\\NAVOpts.dat", szInstallDir);
				InstallToolBox::CInstoptsDat NAVOptsDat(NULL, szNAVOptsDat, TRUE);

				if(NAVOptsDat.ReadDWORD(THREAT_NoThreatCat, dwNoThreatCat, 0))
				{
					CCTRACEI(_T("CheckNoThreatCat: Successfully read NoThreatCat status from NAVOpts.dat, value = %i"), dwNoThreatCat);
				}
				else
				{
					CCTRACEW(_T("CheckNoThreatCat: NoThreatCat status not found in NAVOpts.dat, value = %i"), dwNoThreatCat);
				}

			}
			else
			{
				CCTRACEW(_T("CheckNoThreatCat: Could not read NAV string from InstalledApps key."));
				CCTRACEW(_T("CheckNoThreatCat: NoThreatCat status defaulting to %i"), dwNoThreatCat);
			}
			RegCloseKey(hKey);
		}
		else
		{
			TCHAR messageText[MAX_PATH];
			FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, lRet, 0, messageText, MAX_PATH, NULL);
			CCTRACEW(_T("CheckNoThreatCat: Could not open InstalledApps key: %s.  NoThreatCat status defaulting to %i"), messageText, dwNoThreatCat);
		}
	}
	if(1 == dwNoThreatCat)
	{
		MsiSetProperty(hInstall, _T("NSC_SPYWARE"), _T("0"));
	}
	else
	{
		MsiSetProperty(hInstall, _T("NSC_SPYWARE"), _T("1"));
	}

	return ERROR_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////
// PreInstall():
//	this export is called by SymSetup via the customaction table
//	it is responsible for taking care of anything that needs to be done
//	BEFORE the MSI is run
//
//////////////////////////////////////////////////////////////////////////
extern "C" __declspec(dllexport) UINT __stdcall PreInstall()
{
	//currently we dont need to do anything here.. its ok if the MSI
	//calls this stuff itself.
	
	return ERROR_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////
// PreUninstall():
//	this export is called by SymSetup via the customaction table
//	it is responsible for taking care of anything that needs to be done
//	BEFORE the MSI is run
//
//////////////////////////////////////////////////////////////////////////
extern "C" __declspec(dllexport) UINT __stdcall PreUninstall()
{
    g_Log.LogEx("PreUninstall -  begin.");
    
    HRESULT hrCoInit = ::CoInitialize(NULL);
    g_Log.LogEx("PreUninstall -  CoInitialize() returned 0x%08X.", hrCoInit);

	UINT nError = ERROR_SUCCESS;

    while(TRUE)
    {
        // call into HPP to remove Spyware BB rules
        HPP::CHPPUtilityLoader cLoader;
        HPP::IHPPUtilityInterfacePtr spUtility;
        g_Log.LogEx("PreUninstall -  removing HPP Spyware BB rules.");

        //
        // Load up HPP utility object
        //
        SYMRESULT sr;
        sr = cLoader.CreateObject(&spUtility);
        if(SYM_FAILED(sr) || !spUtility)
        {
            if(FAILED(sr))
            {
                g_Log.LogEx("PreUninstall -  CHPPUtilityLoader::CreateObject() failed. sr = 0x%08X", sr);
            }

            // not fatal error, return success
            nError = ERROR_SUCCESS;
            break;
        }

        //
        // Call the uninstall prep routine
        //
        HRESULT hr = E_FAIL;
        hr = spUtility->PrepHPPForUninstall();
        if(FAILED(hr))
        {
            g_Log.LogEx("PreUninstall -  IHPPUtilityInterface::PrepHPPForUninstall() failed. hr = 0x%08X", hr);
        }

        g_Log.LogEx("PreUninstall -  done removing HPP Spyware BB rules.");
        spUtility.Release();

        // always return success
        nError = ERROR_SUCCESS;
        break;

    }
    
    // each successful call to CoInitialize or CoInitializeEx, 
    // including any call that returns S_FALSE, must call CoUnintialize
    if(SUCCEEDED(hrCoInit))
    {
        ::CoUninitialize();
    }

    g_Log.LogEx("PreUninstall -  done.");
    return nError;
}
