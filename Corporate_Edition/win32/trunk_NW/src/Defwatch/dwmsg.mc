;/////////////////////////////////////////////////////////////////////
;// SRVMSG.MC - Created - 11/11/98
;//
;// Copyright 1992 - 2003 Symantec Corporation. All rights reserved.
;/////////////////////////////////////////////////////////////////////
;// $Header: $
;//
;// Description:
;//
;//
;/////////////////////////////////////////////////////////////////////
;// $Log:$
;/////////////////////////////////////////////////////////////////////


SeverityNames=(Success=0x0
               Informational=0x1
               Warning=0x2
               Error=0x3
               )

MessageIdTypedef=DWORD

MessageId=0x0001
Severity=Informational
SymbolicName=IDM_TITLE
Language=English
Symantec AntiVirus Virus Definition Daemon
.

MessageId=0x8500
Severity=Error
SymbolicName=IDM_ERR_FAILED_TO_GET_DEFS
Language=English
Failed to get virus definitions folder.
.

MessageId=0x8501
Severity=Error
SymbolicName=IDM_ERR_LOAD_OPTIONS
Language=English
Unable to Load Options.
.

MessageId=0x8502
Severity=Error
SymbolicName=IDM_ERR_NO_HANDLERS
Language=English
No new virus defintions handlers found.
.

MessageId=0x8503
Severity=Error
SymbolicName=IDM_ERR_FAILED_TO_CREATE_DEF_UPDATE_EVENT
Language=English
Failed to create the virus definition update event.
.
