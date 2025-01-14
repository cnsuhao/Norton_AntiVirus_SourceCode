// BlockingSocket.h: interface for the CBlockingSocket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOCKINGSOCKET_H__A80D90BA_E83C_11D2_9134_0004ACEC70EC__INCLUDED_)
#define AFX_BLOCKINGSOCKET_H__A80D90BA_E83C_11D2_9134_0004ACEC70EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning(disable:4251)

#include "AVISSendMailDLL.h"

#include <winsock.h>

typedef const struct sockaddr *LPCSOCKADDR;

//////////////////////////////////////////////////////////////////////////////
//
// Class Name:  CSockAddr
//
// Author: C. Falterer.
//
// Purpose: 
//			.
//
//
//
//
/////////////////////////////////////////////////////////////////////////////
class CSockAddr : public sockaddr_in 
{

public:

	// constructors
	CSockAddr()
		{ sin_family = AF_INET;
		  sin_port = 0;
		  sin_addr.s_addr = 0; } // Default

	CSockAddr(const SOCKADDR& sa) { memcpy(this, &sa, sizeof(SOCKADDR)); }

	CSockAddr(const SOCKADDR_IN& sin) { memcpy(this, &sin, sizeof(SOCKADDR_IN)); }


	CSockAddr(const ULONG ulAddr, const USHORT ushPort = 0) // parms are host byte ordered
	{ 
			sin_family      = AF_INET;
			sin_port        = htons(ushPort);
			sin_addr.s_addr = htonl(ulAddr); 
	}

	CSockAddr(const char* pchIP, const USHORT ushPort = 0) // dotted IP addr string
	{
			sin_family      = AF_INET;
			sin_port        = htons(ushPort);
			sin_addr.s_addr = inet_addr(pchIP);

	} // already network byte ordered

	// Return the address in dotted-decimal format
//	CString DottedDecimal()	{ return inet_ntoa(sin_addr); } // constructs a new CString object

	// Get port and address (even though they're public)
	USHORT Port() const
		{ return ntohs(sin_port); }

	ULONG IPAddr() const
		{ return ntohl(sin_addr.s_addr); }

	// operators added for efficiency
	const CSockAddr& operator=(const SOCKADDR& sa)
	{ 
		memcpy(this, &sa, sizeof(SOCKADDR));
		return *this; 
	}

	const CSockAddr& operator=(const SOCKADDR_IN& sin)
	{ 
		memcpy(this, &sin, sizeof(SOCKADDR_IN));
		return *this;
	}

	operator SOCKADDR( )
		{ return *((LPSOCKADDR) this); }

	operator LPSOCKADDR( )
		{ return (LPSOCKADDR) this; }

	operator LPSOCKADDR_IN( )
		{ return (LPSOCKADDR_IN) this; }

};


//////////////////////////////////////////////////////////////////////////////
//
// Class Name: CBlockingSocket  
//
// Author: C. Falterer.
//
// Purpose: 
//			.
//
// 
//
// 
//
//
/////////////////////////////////////////////////////////////////////////////
class AVISSENDMAIL_API CBlockingSocket  
{

public:

	// constructor/destructor
	CBlockingSocket();

	virtual ~CBlockingSocket();

	//
	// methods
	//
	void GetSockAddr( LPSOCKADDR psa );

	void GetPeerAddr( LPSOCKADDR psa );

	int Receive( char *pch, const int nSize, const int nSecs );

	int Write( const char *pch, const int nSize, const int nSecs );

	int Send( const char *pch, const int nSize, const int nSecs );

	BOOL Accept( CBlockingSocket &sConnect, LPSOCKADDR psa);

	void Connect( LPCSOCKADDR psa );

	void Listen( );

	void Bind( LPCSOCKADDR psa );

	void Close();

	int Create( int nType );

	void CleanUp();

	SOCKET m_hSocket;

	operator SOCKET() { return m_hSocket; }

};

#endif // !defined(AFX_BLOCKINGSOCKET_H__A80D90BA_E83C_11D2_9134_0004ACEC70EC__INCLUDED_)
