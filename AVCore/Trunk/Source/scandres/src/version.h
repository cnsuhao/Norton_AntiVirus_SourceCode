/////////////////////////////////////////////////////////////////////////////
// $Header:   S:/SCANDRES/VCS/version.h_v   1.0   29 Jun 1998 17:44:44   jtaylor  $
/////////////////////////////////////////////////////////////////////////////
//
// version.h - used to include the version resource information.
//
/////////////////////////////////////////////////////////////////////////////
// $Log:   S:/SCANDRES/VCS/version.h_v  $
// 
//    Rev 1.0   29 Jun 1998 17:44:44   jtaylor
// Initial revision.
// 
/////////////////////////////////////////////////////////////////////////////

#ifndef _MAC
/////////////////////////////////////////////////////////////////////////////
//
// Version
//

/////////////////////////////////////////////////////////////////////////////
// Stuff needed to use the global version info block defined in nav.ver
// and navver.h

#define VR_FILEDESCRIPTION      "Norton AntiVirus Scan and Deliver\0"
#define VR_INTERNALNAME         "SCANDRES\0"
#define VR_ORIGINALFILENAME     "SCANDRES.DLL"

#include "vlib.ver"

#endif    // !_MAC


