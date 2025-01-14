////////////////////////
//
// PROPRIETARY / CONFIDENTIAL.
// Use of this product is subject to license terms.
// Copyright � 2006 Symantec Corporation.
// All rights reserved.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"

#include "ccEventId.h"
#include "ccSerializableEventEx.h"
#include "ccResourceLoader.h"
#include "SNLogLogViewerSymNetiEvent.h"
#include "SNLookup.h"
#include "resource.h"
#include "..\SNLogRes\ResResource.h"
#include "UnicodeSupport.h"

#ifndef DEBUG_NEW
    #include <new>
    #include <new.h>
    // Use debug version of operator new if _DEBUG
    #ifdef _DEBUG
        #include <crtdbg.h>
        #define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
    #else // _DEBUG
        #define DEBUG_NEW new
    #endif // _DEBUG
#endif // DEBUG_NEW

#ifdef _DEBUG
    #define new DEBUG_NEW
#endif

using namespace cc;
using namespace NisEvt;
using namespace ccLib;

#define MAX_EVENT_TEXT_SIZE  (4*1024)  // Legacy !!

typedef unsigned __int64 QWORD;
typedef QWORD *PQWORD;

// Resource Loader
extern cc::CResourceLoader g_ResLoader;

CLogViewerSymNetiEvent::CLogViewerSymNetiEvent()
{
	m_bSupported		= false;
	m_bSupportTested	= false;

	m_dwSNID			= 0;
	m_dwNISEvtIDShort	= 0;
	m_dwNISEvtIDNormal	= 0;
	m_dwNISEvtIDHTML	= 0;

    m_pLogEvent = NULL;
	m_szDetail = NULL;
	m_bShowUser = FALSE;
}

CLogViewerSymNetiEvent::~CLogViewerSymNetiEvent()
{
    if (m_pLogEvent != NULL)
    {
        m_pLogEvent->Release();
        m_pLogEvent = NULL;
    }

	if (m_szDetail)
	{
		free(m_szDetail);
		m_szDetail=NULL;
	}
}

void CLogViewerSymNetiEvent::TestSupport()
{
	if ( m_bSupportTested == false )
	{
		m_bSupportTested = true;

		if ( !FAILED( m_pLogEvent->GetEventMessageID(m_dwSNID) ) )
			if ( !FAILED( LookupMessageID( m_dwSNID, m_dwNISEvtIDShort, m_dwNISEvtIDNormal, m_dwNISEvtIDHTML ) ) )
				m_bSupported = true; 
	}
}

DWORD CLogViewerSymNetiEvent::GetMsgID( LVEVENT_DETAILSTYPE eType )
{
	TestSupport();
	switch (eType)
	{
	case LVEDT_SHORT:
		return m_dwNISEvtIDShort;
	case LVEDT_NORMAL:
		return m_dwNISEvtIDNormal;
	case LVEDT_HTML:
		return m_dwNISEvtIDHTML;
	default:
		return 0;
	};
}
 
HRESULT CLogViewerSymNetiEvent::GetImageListIndex(int& iImageListIndex)
{
	if (m_pLogEvent == NULL)
    {
        return E_FAIL;
    }

	int iSubtype;
	if (m_pLogEvent->GetEventSubtype(iSubtype) == SymNeti::SN_EVTOK)
	{
		typedef struct 
		{
			DWORD dwSubtype;
			DWORD dwIndex;
		} IMAGELOOKERUPPER;

		static IMAGELOOKERUPPER aLookupIndex[] =
		{
			// Common
			{SymNeti::CSNLogEventEx::SubTypeError, 0},
			{SymNeti::CSNLogEventEx::SubTypeWarning, 1},
			{SymNeti::CSNLogEventEx::SubTypeInfo, 2},
			{SymNeti::CSNLogEventEx::SubTypeAlert, 3},

			// System-specific
			{SymNeti::CSNLogEventEx::SubTypeSettingChange, 2},

			// Connections Tab
			{SymNeti::CSNLogEventEx::SubTypeConnectionOutbound, 7},
			{SymNeti::CSNLogEventEx::SubTypeConnectionInbound, 8},

			// Firewall, Alert, IDS
			{SymNeti::CSNLogEventEx::SubTypeRuleException, 11},
			{SymNeti::CSNLogEventEx::SubTypeRuleMatch, 11},
			{SymNeti::CSNLogEventEx::SubTypeFWScanDetected, 5},
			{SymNeti::CSNLogEventEx::SubTypeIDSDetected, 5},
		};


		// Special case IDS alert to display the 'stop' icon
		if (iSubtype == SymNeti::CSNLogEventEx::SubTypeAlert &&
			m_pLogEvent->GetType() == CC_SYMNETDRV_EVENT_LOG_IDS)
		{
			iImageListIndex = 5;
			return S_OK;
		}


		for (int i=0; i < CCDIMOF(aLookupIndex); i++)
			if (iSubtype == static_cast<int> (aLookupIndex[i].dwSubtype) )
			{
				iImageListIndex = aLookupIndex[i].dwIndex;
				return S_OK;
			}
	}

	return E_FAIL;

}


#pragma message ("This is a dup of what's in the NisEvtLogViewerSymNetiCategory.cpp !!")
#define SN_MAX_COLUMNS 9
enum
{
	EV_END=0,
	EV_STRING,
	EV_DWORD,
	EV_CY
};

typedef struct tagLOGTYPELOOKUP
{
	DWORD dwSNType;
	DWORD dwColumnCount;
	struct 
	{
		DWORD dwColumnNameID;		// Column heading string ID
		DWORD dwColumnDataPosition;	// Position, within log event data list for this column
		DWORD dwVTDataType;			// How to represent the data
	} aColumnInfo[SN_MAX_COLUMNS];
} SNLOGTYPELOOKUP, *PSNLOGTYPELOOKUP; 

static const SNLOGTYPELOOKUP aLogTypeLookupTable[] = 
{
	{CC_SYMNETDRV_EVENT_LOG_SYSTEM,		3,     {{IDS_COLTEXT_DATE, 0, EV_STRING},
												{IDS_COLTEXT_USER, 0, EV_STRING},
												{IDS_COLTEXT_MESSAGE, -1, EV_STRING}}},
	{CC_SYMNETDRV_EVENT_LOG_FIREWALL,	3,     {{IDS_COLTEXT_DATE, 0, EV_STRING},
												{IDS_COLTEXT_USER, 0, EV_STRING},
												{IDS_COLTEXT_MESSAGE, 0, EV_STRING}}},
	{CC_SYMNETDRV_EVENT_LOG_CONNECTIONS,	9, {{IDS_COLTEXT_DATE, 0, EV_STRING},
												{IDS_COLTEXT_USER, 0, EV_STRING},
												{IDS_COLTEXT_LOCAL_IP, 3, EV_STRING},
												{IDS_COLTEXT_LOCAL_PORT, 4, EV_STRING},
												{IDS_COLTEXT_REMOTE_IP,   0, EV_STRING},
												{IDS_COLTEXT_REMOTE_PORT,   1, EV_STRING},
												{IDS_COLTEXT_SENT, 5, EV_DWORD},
												{IDS_COLTEXT_RECV, 6, EV_DWORD},
												{IDS_COLTEXT_CONNTIME, 7, EV_CY}}},
	{CC_SYMNETDRV_EVENT_LOG_ALERTS,		3,	   {{IDS_COLTEXT_DATE, 0, EV_STRING},
												{IDS_COLTEXT_USER, 0, EV_STRING},
												{IDS_COLTEXT_MESSAGE, -1, EV_STRING}}},
	{CC_SYMNETDRV_EVENT_LOG_IDS,			3, {{IDS_COLTEXT_DATE, 0, EV_STRING},
												{IDS_COLTEXT_USER, 0, EV_STRING},
												{IDS_COLTEXT_MESSAGE}, -1, EV_STRING}},
	{CC_SYMNETDRV_EVENT_LOG_DEBUG,		2,     {{IDS_COLTEXT_DATE, 0, EV_STRING},
												{IDS_COLTEXT_USER, 0, EV_STRING}}},
};


HRESULT CLogViewerSymNetiEvent::GetColumnData(int iColumn, 
                                              DWORD dwFlags,
                                              VARIANT& varData)
{
	HRESULT hRet = E_FAIL;

	if (m_pLogEvent == NULL)
    {
        return hRet;
    }

	VariantClear(&varData);

	if (!m_bShowUser && iColumn > 0)
		iColumn++;

	switch (iColumn)
	{
		case 0: // Date/time
			hRet = m_pLogEvent->GetEventDate(dwFlags, varData);
			break;

		case 1:	// User
			hRet = m_pLogEvent->GetEventUser(dwFlags, varData);

			if (hRet == S_OK &&
				SysStringLen(V_BSTR(&varData)) == 0)
			{
				// Load the localized string describing 'no user logged in'
				TCHAR szBuffer[128];
				szBuffer[0] = _T('\0');

				if (g_ResLoader.LoadString(IDS_NO_USER_LOGGED,
							   szBuffer,
							   CCDIMOF(szBuffer) - 1))
				{
					VariantClear(&varData);

					_bstr_t bs ( szBuffer );
					V_VT(&varData) = VT_BSTR;
					V_BSTR(&varData) = bs.copy();
				}

			}
			break;

		default:
			{
				if (m_szDetail == NULL)
				{
					char szTmp[MAX_EVENT_TEXT_SIZE]={0};
					ULONG ulSize=sizeof(szTmp);
					if (GetDetails(LVEDT_NORMAL, dwFlags, szTmp, ulSize) == S_OK)
					{
						m_szDetail = _strdup(szTmp);
					}
					else
					{
						m_szDetail = _strdup("");
					}
				}

				switch (m_pLogEvent->GetType())
				{
					// These types have one extra column, the message
					case CC_SYMNETDRV_EVENT_LOG_IDS:
					case CC_SYMNETDRV_EVENT_LOG_ALERTS:
					case CC_SYMNETDRV_EVENT_LOG_SYSTEM:
					case CC_SYMNETDRV_EVENT_LOG_FIREWALL:
					case CC_SYMNETDRV_EVENT_LOG_DEBUG:
						{
							if (iColumn == 2)
							{
								char szTmp[1024]={0};

								if (strlen(m_szDetail))
								{
									strncpy(szTmp, m_szDetail, sizeof(szTmp)-1);
									szTmp[sizeof(szTmp)-1]=0;
									
									// Terminate at first cr/lf
									for (LPSTR p=szTmp; *p; p++)
										if (*p == '\r' || *p == '\n')
										{
											*p = 0;
											break;
										}
								}

								_bstr_t bs (szTmp);
								V_VT(&varData) = VT_BSTR;
								V_BSTR(&varData) = bs.copy();
								hRet = S_OK;
							}

						}
						break;

					// Handle the connection category columns
					case CC_SYMNETDRV_EVENT_LOG_CONNECTIONS:
						{
							BYTE buf[100];
							if (m_pLogEvent->GetAttribute(aLogTypeLookupTable[2].aColumnInfo[iColumn].dwColumnDataPosition, buf, sizeof(buf)) == SymNeti::SN_EVTOK)
							{
								PSNDATAVALUE pData = (PSNDATAVALUE)buf;

								if (aLogTypeLookupTable[2].aColumnInfo[iColumn].dwVTDataType == EV_DWORD)
								{
									V_VT(&varData) = VT_UI4;
									V_UI4(&varData) = *((unsigned long *) &(pData->abyData) );
									hRet = S_OK;
								}
								else if(aLogTypeLookupTable[2].aColumnInfo[iColumn].dwVTDataType == EV_CY)
								{
                    				QWORD q = *((PQWORD)pData->abyData);
                       				//
				                    // n.b. 100 ns = 10^-7 secs
				                    //				                  
								    V_VT(&varData) = VT_CY;
    							    V_CY(&varData).int64 = (q / 10000i64);;
	    						    hRet = S_OK;
								}
								else
								{
									char formattedBuf[256];
									DWORD dwIgnore;
									
									pData = (PSNDATAVALUE) (buf+pData->wSize);

									pData->wSize = sizeof(SNDATAVALUE);
									pData->byDataType = EV_END;
									pData->byContext = 0;

									if (EventFormatArgumentsEx( buf,
																g_ResLoader.GetResourceInstance(), 
																formattedBuf, 
																sizeof(formattedBuf), 
																&dwIgnore) == 0)
									{
										_bstr_t bs (*((LPCSTR *)formattedBuf));
										V_VT(&varData) = VT_BSTR;
										V_BSTR(&varData) = bs.copy();
										hRet = S_OK;
									}


								}
							}
						}

						break;

					default:
						ASSERT(FALSE);
						break;
				}
			}
		}

	return this->IsSupported() == true ? hRet : E_FAIL;
}

HRESULT CLogViewerSymNetiEvent::GetDetails(LVEVENT_DETAILSTYPE eType, 
                                           DWORD dwFlags,
                                           LPSTR szDetailText, 
                                           DWORD& dwSize)
{
    if (m_pLogEvent == NULL || szDetailText == NULL || dwSize == 0)
    {
        return E_FAIL;
    }
	return GetDetailsW(eType, dwFlags, unicode::AutoBufferW(szDetailText, dwSize), dwSize);
}

HRESULT CLogViewerSymNetiEvent::GetDetailsW(LVEVENT_DETAILSTYPE eType, 
                                           DWORD dwFlags,
                                           LPWSTR szDetailText, 
                                           DWORD& dwSize)
{
if (m_pLogEvent == NULL || szDetailText == NULL || dwSize == 0)
    {
        return E_FAIL;
    }

	*szDetailText = 0;
	if ( IsSupported() == false )
		return E_FAIL;

	HRESULT hRet=S_OK;


	char args[MAX_EVENT_TEXT_SIZE]={0};
	DWORD argCnt;
	BYTE  abyAttributes[1024];
	DWORD  dwAttribCount=0;
	DWORD dRet=0xffffffff;
	if (m_pLogEvent->GetAllAttributes(abyAttributes, sizeof(abyAttributes), dwAttribCount) == SymNeti::SN_EVTOK)
	{
		if (dwAttribCount == 0)
		{
			dRet = 0;	// Nothing to format (no arguments needed)
		}
		else
		{
			dRet = EventFormatArgumentsEx(abyAttributes,
											g_ResLoader.GetResourceInstance(), 
											args, 
											sizeof(args), 
											&argCnt);
		}
	}
	if (dRet) 
	{
#ifdef _DEBUG
		TCHAR fmt[128];
		TCHAR fmtBuf[256];
		*fmt = 0;
		if (LoadString(g_ResLoader.GetResourceInstance(), IDS_STR_FORMAT_ERROR, fmt, CCDIMOF(fmt)))
		{
			DWORD dwBytesWritten = wsprintf(fmtBuf, fmt, dRet, GetMsgID( eType ));
			DBG_UNREFERENCED_LOCAL_VARIABLE(dwBytesWritten);
			fmtBuf[dwSize-1]=0;
			_tcsncpy(szDetailText, fmtBuf, dwSize-1);
			dwSize = (DWORD)wcslen(fmtBuf)+sizeof(TCHAR);
		}
		else
		{
			HRESULT_FROM_WIN32(GetLastError());
		}
#endif
	} 
	else 
	{
		// Format the message.
		char * pBuffer= new char[dwSize];
		DWORD dwBytesWritten = FormatMessageA( FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_ARGUMENT_ARRAY,
											g_ResLoader.GetResourceInstance(),
											GetMsgID( eType ), 
											LANG_NEUTRAL,
											pBuffer,
											dwSize,
											(va_list *)args);

		if (dwBytesWritten == 0)
		{
			PVOID pvDummy = NULL;


			/* not enough space in the buffer passed in */

			dwBytesWritten = FormatMessageA( FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_ARGUMENT_ARRAY | FORMAT_MESSAGE_ALLOCATE_BUFFER,
											g_ResLoader.GetResourceInstance(),
											GetMsgID( eType ), 
											LANG_NEUTRAL,
											(char *)&pvDummy,
											dwSize,
											(va_list *)args);

			dwSize = dwBytesWritten ;
			hRet = E_MORE_DATA;
			LocalFree (pvDummy);
		}
		else
		{
			if ( dwBytesWritten > dwSize )
			{
				dwSize = dwBytesWritten;
				hRet = E_MORE_DATA;
			}
			else
			{
				CA2W ca2w(pBuffer);
				wcscpy(szDetailText, ca2w);
				hRet = S_OK;
			}
		}
		delete pBuffer;


		//
		// remove any trailing CR's or LFs
		//
		while (dwBytesWritten && (szDetailText[dwBytesWritten-1] == 0x0D || szDetailText[dwBytesWritten-1] == 0x0A)) 
		{
			szDetailText[--dwBytesWritten] = 0;		
		}
	}

	return hRet;
}
