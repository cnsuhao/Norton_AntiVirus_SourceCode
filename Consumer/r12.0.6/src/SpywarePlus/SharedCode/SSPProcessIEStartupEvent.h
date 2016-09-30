#pragma once

#include "SSPProcessEventBase.h"
#include "ccAlertInterface.h"
#include "ccLogFactoryEx.h"
#include "EventLogHelper.h"

#include <vector>
#include <map>

class CSSPProcessIEStartupEvent :
    public CSSPProcessEventBase,
    public cc::IAlertCallback,
    ISymBaseImpl<CSymThreadSafeRefCount>
{
public:
    CSSPProcessIEStartupEvent(void);
    virtual ~CSSPProcessIEStartupEvent(void);

    SYM_INTERFACE_MAP_BEGIN()
        SYM_INTERFACE_ENTRY(cc::IID_AlertCallback, IAlertCallback)
    SYM_INTERFACE_MAP_END()

    STDMETHOD(Run)();

    typedef std::vector<CEventExPtr> LST_EVENTPTR;
    typedef std::vector<CString> LST_CSTRING;
    typedef std::vector<BOOL> LST_BOOL;

    LST_EVENTPTR m_lstEvents;

protected:
    virtual HRESULT AddAlertDetail(CHPPEventCommonInterface *pEvent, cc::IAlert2 *pAlert);
    virtual HRESULT AddAlertCommon(cc::IAlert2 *pAlert);
    virtual BOOL AlreadyInActionList(CString &cszItem);

    // ICcAlertCallback methods
    virtual bool Run(HWND hWndParent, unsigned long nData, cc::IAlert* pAlert, cc::IAlertCallback::ALERTCALLBACK context);

protected:
    LST_CSTRING m_lstHomePages;
    LST_BOOL m_lstHomePageLocations;

};
