#pragma once

class CHPPEngineSymAppPlugin : 
    public ISymBaseImpl< CSymThreadSafeRefCount >, 
    public ICCAppPlugin
{
public:
    CHPPEngineSymAppPlugin(void);
    virtual ~CHPPEngineSymAppPlugin(void);

    SYM_INTERFACE_MAP_BEGIN()                
        SYM_INTERFACE_ENTRY( IID_CCAppPlugin, ICCAppPlugin ) 
    SYM_INTERFACE_MAP_END()                  

    // ICCAppPlugin
    virtual void Run( ICCApp* pCCApp );
    virtual bool CanStopNow();
    virtual void RequestStop() ;
    virtual const char * GetObjectName();
    virtual unsigned long OnMessage( int iMessage, unsigned long ulParam );


protected:
    // Pointer to ISymApp object.
    CSymPtr< ICCApp >	m_pApp;


};
