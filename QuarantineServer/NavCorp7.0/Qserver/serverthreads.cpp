
#include "stdafx.h"
#include "threadpool.h"
#include "serverthreads.h"
#include "winsock2.h"
#include "wsipx.h"
#include "qsprotocol.h"
#include "qspak.h"
#include "time.h"
#include "const.h"
#include "qsfields.h"

///////////////////////////////////////////////////////////////////////////////
// Local prototypes.

static DWORD GetXferFileSize( SOCKET s );
static void SendStatus( SOCKET s, DWORD dwCode );
static HANDLE CreateUniqueFile( LPCTSTR szPath, LPTSTR szDestPath, DWORD* pdwFileID = NULL );
static void xorBuffer( void* pBuffer, int iSize );
static SOCKET CreateIPListenSocket( int iPort, HANDLE hEvent );
static SOCKET CreateIPXListenSocket( int iPort, HANDLE hEvent );
static DWORD GetRealFileSize( LPCTSTR szFileName );


///////////////////////////////////////////////////////////////////////////////
// Macros.

#define SEND_BEGIN_XFER(ss) \
        SendStatus( ss, BEGIN_XFER )

#define SEND_DONE_XFER(ss) \
        SendStatus( ss, DONE_XFER )

#define SEND_SERVER_BUSY(ss) \
        SendStatus( ss, SERVER_ERROR_BUSY )

#define SEND_ERROR(ss, ee) \
        SendStatus( ss, ee )

#define SIZE_OF_ARRAY(expr) (sizeof(expr) / sizeof(expr[0]))

///////////////////////////////////////////////////////////////////////////////
// Private structures used by worker threads.
// 

typedef struct WORKERTHREADATA        
{
    SOCKET socket;
    CServiceModule* pModule;
}WORKERTHREADATA;

// Unnamed namespace for "local to translation unit" (instead of static, which is deprecated in ANSI C++)
namespace {
	// Constants
	const _TCHAR CcNULL(_T('\0'));
	const _TCHAR CcDriveSeparator(_T(':'));
	const _TCHAR* const CpCcPathParsing = _T("\\\\?\\");
	const _TCHAR CacDirectorySeparator[] = {
		_T('\\'),
		_T('/')
	};

	// CreateDirectory implementation that can create a complete directory path (and not just the last node)
	bool CreateDirectoryPath(const _TCHAR* const CpCcDirectory)
	{
		_ASSERT(CpCcDirectory != NULL);
		_ASSERT(*CpCcDirectory != CcNULL);

		// Initialize pointer start of directory path
		const _TCHAR* pCcStart = CpCcDirectory;

		// Start directory search after path parsing identifier, if it exists
		const _TCHAR* const CpCcAtPathParsing = _tcsstr(pCcStart, CpCcPathParsing);
		if (CpCcAtPathParsing != NULL) {
			// Make sure that path parsing identifier was the first characters in the directory path string
			_ASSERT(CpCcAtPathParsing == pCcStart);
			
			// Path parsing identifier found, skip it
			pCcStart = CpCcAtPathParsing + _tcsclen(CpCcPathParsing);
			
			// Make sure that there is something after the path parsing identifier
			_ASSERT(*pCcStart != CcNULL);
		}

		// Start directory search after drive letter specification, if it exists
		const _TCHAR* const CpCcAtDriveSeparator = _tcschr(pCcStart, CcDriveSeparator);
		if (CpCcAtDriveSeparator != NULL)
			// Drive letter specification found, skip it
			pCcStart = _tcsinc(CpCcAtDriveSeparator);

		// Calculate difference between directory path search start and string start
		const size_t CstStartDifference(pCcStart - CpCcDirectory + 1);
		
		// Start search after path parsing identifier and drive letter specification
		const _TCHAR* pCcCurrent = pCcStart;
		
		// Initialize loop variables
		bool bCreateDirSucceeded(true);
		bool bKeepGoing(true);
		
		// Check for empty [root] directory name
		if (*pCcCurrent != CcNULL)
			// Loop along directory path
			do {
				// Search for next directory separator
				const _TCHAR* pCcNextDirectorySeparator = NULL;
				for (unsigned int ui(0); ui<SIZE_OF_ARRAY(CacDirectorySeparator) && pCcNextDirectorySeparator == NULL; ++ui)
					pCcNextDirectorySeparator = _tcschr(pCcCurrent, CacDirectorySeparator[ui]);
				
				if (pCcNextDirectorySeparator == pCcCurrent)
					// Skip [initial root] directory separator
					pCcCurrent = _tcsinc(pCcCurrent);
				else {
					// Create current directory path
					_TCHAR* pcCurrentPath = NULL;
					if (pCcNextDirectorySeparator != NULL) {
						// Next path separator found, construct current directory path to check for
						const size_t CstCurrentPathIndex((pCcNextDirectorySeparator - pCcStart) + CstStartDifference);
						pcCurrentPath = new _TCHAR[CstCurrentPathIndex + 1];
						_tcsncpy(pcCurrentPath, CpCcDirectory, CstCurrentPathIndex);
						
						// Zero-terminate current directory path
						pcCurrentPath[CstCurrentPathIndex] = CcNULL;
					}
					else {
						// No more path separators found, so use original directory path (which should now be OK to be created by CreateDirectory), and terminate loop
						pcCurrentPath = new _TCHAR[_tcslen(CpCcDirectory) + 1];
						_tcscpy(pcCurrentPath, CpCcDirectory);
						bKeepGoing = false;
					}
					
					// See if current directory path exists
					const HANDLE ChDirectory(CreateFile(pcCurrentPath, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL));
					if (ChDirectory == INVALID_HANDLE_VALUE) {
						// Doesn't exist, so create current directory path
						if (CreateDirectory(pcCurrentPath, NULL) != 0)
							// Created current directory path successfully
							bCreateDirSucceeded = true;
						else {
							// CreateDirectry failed, so terminate
							bCreateDirSucceeded = false;
							bKeepGoing = false;
						}
					}
					else
						// Directory exists
#if defined(_DEBUG)
						_ASSERT(CloseHandle(ChDirectory) != 0);
#else
						CloseHandle(ChDirectory);
#endif

					// Free memory for current path
					delete[] pcCurrentPath;
						
					// Move on to next path separator
					if (bKeepGoing == true)
						pCcCurrent = _tcsinc(pCcNextDirectorySeparator);
				}
			}
			while (bKeepGoing == true);
		
		return bCreateDirSucceeded;
	}
}

///////////////////////////////////////////////////////////////////////////////
//
// Function name: IP_ListenerThread
//
// Description: This routine will listen on a given WinSock port for incomming
//              files from quarantine clients.  When connections are made, they
//              are relagated to worker threads for processing.
//
// Return type: void 
//
// Argument: DWORD dwData - pointer to our main object.
//
///////////////////////////////////////////////////////////////////////////////
// 12/17/98 - DBUCHES: Function created / header added 
///////////////////////////////////////////////////////////////////////////////
void IP_ListenerThread( DWORD dwData )
{
    // 
    // Make sure our pointer is good.
    // 
    CServiceModule* pModule = (CServiceModule*) dwData;
    _ASSERT( pModule );

    // 
    // Create event for accepting connections
    // 
    HANDLE hAcceptEvent = CreateEvent( NULL, FALSE, FALSE, NULL );

    //
    // Create a socket
    //
    SOCKET s = INVALID_SOCKET;
    
    if( pModule->GetListenIP() )
        {
        s = CreateIPListenSocket( pModule->GetIPPort(), hAcceptEvent );
        if( INVALID_SOCKET == s )
            {
            if( hAcceptEvent != INVALID_HANDLE_VALUE )
                CloseHandle( hAcceptEvent );
            
            pModule->LogEvent( IDM_ERR_CREATING_IP_LISTENING_SOCKET );
            ATLTRACE( _T("Error creating listener socket. LastError = %d\n"), WSAGetLastError() );
            return;
            }
        }

    // 
    // Create waiting event array.  
    // 
    HANDLE aEvents[3];
    aEvents[0] = pModule->m_hStopping;
    aEvents[1] = hAcceptEvent;
    aEvents[2] = pModule->m_hSocketConfig;

    // 
    // Wait for connections and set them in motion.
    // 
    while( TRUE )
        {
        
        // 
        // Wait here for one of 3 things to happen:
        // 1) An incomming connection.
        // 2) Server shutdown.
        // 3) Server configuration change.
        //
        DWORD dwWait = WaitForMultipleObjects( 3, aEvents, FALSE, INFINITE );
        if( WAIT_OBJECT_0 == dwWait )
            {
            // 
            // WAIT_OBJECT_0 == shutdown event.
            // 
            break;
            }
        else if( dwWait - WAIT_OBJECT_0 == 2 )
            {
            // 
            // Configuration changed.  Reinitialize.
            // 
            if( s != INVALID_SOCKET )
                {
                closesocket( s );
                }
            
            // 
            // Check to make sure we should be listening.
            // 
            if( pModule->GetListenIP() )
                {
                ResetEvent( hAcceptEvent );
                s = CreateIPListenSocket( pModule->GetIPPort(), hAcceptEvent );
            
                if( INVALID_SOCKET == s )
                    {
                    pModule->LogEvent( IDM_ERR_CREATING_IP_LISTENING_SOCKET );
                    ATLTRACE( _T("Error creating listener socket. LastError = %d\n"), WSAGetLastError() );
                    }
                }

            continue;
            }

        // 
        // Get next connection.
        // 
        sockaddr clientAddress;
        sockaddr_in* pClientAddr = (sockaddr_in*) &clientAddress;
        memset( &clientAddress, 0, sizeof( sockaddr ) );
        int iSize = sizeof( sockaddr );
        SOCKET sClient = accept( s, &clientAddress, &iSize );

        if( INVALID_SOCKET == sClient )
            {
            pModule->LogEvent(IDM_ERR_ACCEPTING_CONNECTION);
            ATLTRACE( _T("Error accepting IP client socket. LastError = %d\n"), WSAGetLastError() );
            continue;
            }

        // 
        // Relegate this socket to a worker thread.
        // 
        WORKERTHREADATA* pThreadData = new WORKERTHREADATA;
        _ASSERT( pThreadData );
        pThreadData->socket = sClient;
        pThreadData->pModule = pModule;
        if( FALSE == pModule->m_pThreadPool->DoWork( WorkerThread, 
                                                     (DWORD) pThreadData, 
                                                     THREAD_PRIORITY_BELOW_NORMAL ) ) 
            {
            // 
            // No worker threads availiable, so we need to tell the client to try
            // again later.
            //
            SEND_SERVER_BUSY( sClient );
            shutdown( sClient, 0 ); 
            closesocket( sClient );
            }
        }

    // 
    // Cleanup 
    // 
    if( hAcceptEvent != INVALID_HANDLE_VALUE )
        CloseHandle( hAcceptEvent );
    if( s != INVALID_SOCKET )
        {
        shutdown( s, 0 ); 
        closesocket( s );
        }
}


///////////////////////////////////////////////////////////////////////////////
//
// Function name : CreateIPListenSocket
//
// Description   : Create an IP listening socket.
//
// Return type   : SOCKET 
//
// Argument      : int iPort
//
///////////////////////////////////////////////////////////////////////////////
// 1/25/99 - DBUCHES: Function created / header added 
///////////////////////////////////////////////////////////////////////////////
SOCKET CreateIPListenSocket( int iPort, HANDLE hEvent )
{
    //
    // Create a socket
    //
    SOCKET s = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
    if( INVALID_SOCKET == s )
        {
        return s;
        }

    //
    // Intialize sockaddr structure, and bind to socket
    //
    sockaddr address;
    sockaddr_in* pAddr = (sockaddr_in*) &address;
    ZeroMemory( &address, sizeof( sockaddr ) );
    pAddr->sin_port = iPort;        
    pAddr->sin_family = PF_INET;
    pAddr->sin_addr.S_un.S_addr = INADDR_ANY;
    if( bind( s, &address, sizeof( sockaddr ) ) )
        {
        closesocket( s );
        return INVALID_SOCKET;
        }
    
    //
    // Note that the call to WSAEventSelect() sets the specified 
    // socket to NON-blocking mode.
    //
    if( SOCKET_ERROR == WSAEventSelect( s, hEvent, FD_ACCEPT ) )
        {
        _ASSERT(FALSE);
        return INVALID_SOCKET;
        }

    //
    // Listen for connections
    //
    if( 0 != listen( s, 20 ) )
        {
        closesocket( s );
        return INVALID_SOCKET;
        }

    return s;
}


///////////////////////////////////////////////////////////////////////////////
//
// Function name: SPX_ListenerThread
//
// Description: This routine will listen on a given WinSock port for incomming
//              files from quarantine clients.  When connections are made, they
//              are relagated to worker threads for processing.
//
// Return type: void 
//
// Argument: DWORD dwData - pointer to our main object.
//
///////////////////////////////////////////////////////////////////////////////
// 12/17/98 - DBUCHES: Function created / header added 
///////////////////////////////////////////////////////////////////////////////
void SPX_ListenerThread( DWORD dwData )
{
    // 
    // Make sure our pointer is good.
    // 
    CServiceModule* pModule = (CServiceModule*) dwData;
    _ASSERT( pModule );

    // 
    // Create event for accepting connections
    // 
    HANDLE hAcceptEvent = CreateEvent( NULL, FALSE, FALSE, NULL );

    // 
    // Create a socket
    // 
    SOCKET s = INVALID_SOCKET;
    if( pModule->GetListenSPX() )
        {
        s = CreateIPXListenSocket( pModule->GetSPXPort(), hAcceptEvent );
        if( INVALID_SOCKET == s )
            {
            if( hAcceptEvent != INVALID_HANDLE_VALUE )
                CloseHandle( hAcceptEvent );
            pModule->LogEvent(IDM_ERR_CREATING_SPX_LISTENING_SOCKET);
            ATLTRACE( _T("Error creating SPX listener socket. LastError = %d\n"), WSAGetLastError() );
            return;
            }
        }

    //
    // Create waiting event array. 
    // 
    HANDLE aEvents[3];
    aEvents[0] = pModule->m_hStopping;
    aEvents[1] = hAcceptEvent;
    aEvents[2] = pModule->m_hSocketConfig;

    // 
    // Wait for connections and set them in motion.
    // 
    while( TRUE )
        {
        
        // 
        // Wait here for one of 3 things to happen:
        // 1) An incomming connection.
        // 2) Server shutdown.
        // 3) Configuration change.
        //
        DWORD dwWait = WaitForMultipleObjects( 3, aEvents, FALSE, INFINITE );
        if( WAIT_OBJECT_0 == dwWait )
            {
            // 
            // WAIT_OBJECT_0 == shutdown event.
            // 
            break;
            }
        else if( dwWait - WAIT_OBJECT_0 == 2 )
            {
            // 
            // Configuration changed.  Reinitialize.
            // 
            if( s != INVALID_SOCKET )
                {
                closesocket( s );
                }
            
            // 
            // Check to make sure we should be listening.
            // 
            if( pModule->GetListenSPX() )
                {
                ResetEvent( hAcceptEvent );
                s = CreateIPXListenSocket( pModule->GetSPXPort(), hAcceptEvent );
                if( INVALID_SOCKET == s )
                    {
                    pModule->LogEvent(IDM_ERR_CREATING_SPX_LISTENING_SOCKET);
                    ATLTRACE( _T("Error creating SPX listener socket. LastError = %d\n"), WSAGetLastError() );
                    }
                }
            continue;
            }


        // 
        // Get next connection.
        // 
        SOCKADDR_IPX clientAddress;
        memset( &clientAddress, 0, sizeof( SOCKADDR_IPX ) );
        int iSize = sizeof( SOCKADDR_IPX );
        SOCKET sClient = accept( s, (sockaddr*)&clientAddress, &iSize );

        if( INVALID_SOCKET == sClient )
            {
            pModule->LogEvent(IDM_ERR_ACCEPTING_CONNECTION);
            ATLTRACE( _T("Error accepting SPX client socket. LastError = %d\n"), WSAGetLastError() );
            continue;
            }

        // 
        // Relegate this socket to a worker thread.
        // 
        WORKERTHREADATA* pThreadData = new WORKERTHREADATA;
        _ASSERT( pThreadData );
        pThreadData->socket = sClient;
        pThreadData->pModule = pModule;
        if( FALSE == pModule->m_pThreadPool->DoWork( WorkerThread, 
                                                     (DWORD) pThreadData, 
                                                     THREAD_PRIORITY_BELOW_NORMAL ) ) 
            {
            // 
            // No worker threads availiable, so we need to tell the client to try
            // again later.
            //
            SEND_SERVER_BUSY( sClient );
            shutdown( sClient, 0 ); 
            closesocket( sClient );
            }
        }

    // 
    // Cleanup 
    // 
    if( hAcceptEvent != INVALID_HANDLE_VALUE )
        CloseHandle( hAcceptEvent );
    
    if( s != INVALID_SOCKET )
        {
        shutdown( s, 0 ); 
        closesocket( s );
        }
}


///////////////////////////////////////////////////////////////////////////////
//
// Function name : CreateIPXListenSocket
//
// Description   : Creates an IPX listening socket.
//
// Return type   : SOCKET 
//
// Argument      : int iPort
// Argument      : HANDLE hEvent
//
///////////////////////////////////////////////////////////////////////////////
// 1/25/99 - DBUCHES: Function created / header added 
///////////////////////////////////////////////////////////////////////////////
SOCKET CreateIPXListenSocket( int iPort, HANDLE hEvent )
{
    // 
    // Create a socket
    // 
    SOCKET s = socket( AF_IPX, SOCK_STREAM, NSPROTO_SPXII );
    if( INVALID_SOCKET == s )
        {
        return s;
        }

    //
    // Intialize sockaddr structure, and bind to socket
    //
    SOCKADDR_IPX address;
    ZeroMemory( &address, sizeof( SOCKADDR_IPX ) );
    address.sa_family = AF_IPX;
    address.sa_socket = iPort;
    if( bind( s, (sockaddr*)&address, sizeof( SOCKADDR_IPX ) ) )
        {
        closesocket( s );
        return INVALID_SOCKET;
        }

    //
    // Listen for connections
    //
    if( 0 != listen( s, 20 ) )
        {
        closesocket( s );
        return INVALID_SOCKET;
        }

    //
    // Note that the call to WSAEventSelect() sets the specified 
    // socket to NON-blocking mode.
    //
    if( SOCKET_ERROR == WSAEventSelect( s, hEvent, FD_ACCEPT ) )
        {
        closesocket( s );
        return INVALID_SOCKET;
        }

    return s;
}


///////////////////////////////////////////////////////////////////////////////
//
// Function name: WorkerThread
//
// Description: This routine will save data pushed from a client to a temporary
//              file and move it to the quarantine folder.
//
// Return type: void 
//
// Argument: DWORD dwData
//
///////////////////////////////////////////////////////////////////////////////
// 12/17/98 - DBUCHES: Function created / header added 
///////////////////////////////////////////////////////////////////////////////
void WorkerThread( DWORD dwData )
{
    // 
    // Get data pointers.
    // 
    WORKERTHREADATA* pData = (WORKERTHREADATA*) dwData;
    CServiceModule* pModule = pData->pModule;
    _ASSERT( pData );
    _ASSERT( pModule );


    // 
    // Create temporary file for this buffer.
    // 
    TCHAR szFileName[ MAX_PATH ];
    TCHAR szTempPath[ MAX_PATH ];
    GetTempPath( MAX_PATH, szTempPath );
    GetTempFileName( szTempPath, _T("Q"), 0, szFileName );
    HANDLE hFile = CreateFile( szFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL );
    if( hFile != INVALID_HANDLE_VALUE )
        {
        int iCount;
        int iChunkCount = 0;
        DWORD dwBytesWritten;
        BOOL bError = FALSE;
        BOOL bShutdown = FALSE;
        DWORD dwCount = 0;
        char* pBuffer = new char[ 0xFFFF ];


        // 
        // Need to make sure we aren't going over our number-of-files quota.
        // 
				const ULONG CulFileQuota(_Module.GetFileQuota());
        if( CulFileQuota != 0 && (_Module.m_ulItemCount >= CulFileQuota) )
            {
            _Module.LogEvent( IDM_WARNING_SERVER_FULL, EVENTLOG_WARNING_TYPE );
            SEND_ERROR( pData->socket, SERVER_ERROR_DISK_SPACE );
            bError = TRUE;
            }

        // 
        // Q: How many bytes are we expecting?  Get byte count from client.
        // 
        DWORD dwFileSize = GetXferFileSize( pData->socket );
        if( dwFileSize == 0xFFFFFFFF )
            {
            bError = TRUE;
            SEND_ERROR( pData->socket, SERVER_ERROR );
            }

        // 
        // Need to make sure we aren't going over our disk space quota.
        // 
        if( (_Module.m_uQserverByteCount + dwFileSize) >
            _Module.GetDiskQuota() * 0x100000 )
            {
            _Module.LogEvent( IDM_WARNING_SERVER_FULL, EVENTLOG_WARNING_TYPE );
            SEND_ERROR( pData->socket, SERVER_ERROR_DISK_SPACE );
            bError = TRUE;
            }
        else
            {
            dwCount = dwFileSize;
            }
        
        // 
        // Tell client to begin sending file data
        // 
        if( !bError )
            {
            SEND_BEGIN_XFER( pData->socket );

            // 
            // Write all pieces of the file.
            // 
            while( dwCount )
                {
                // 
                // Check for shutdown.
                // 
                if( WAIT_OBJECT_0 == WaitForSingleObject( pModule->m_hStopping, 0 ) )
                    {
                    // 
                    // We are shutting down, so bail out now.
                    // 
                    bShutdown = TRUE;
                    break;
                    }

                // 
                // Get data from socket
                // 
                iCount = recv( pData->socket, pBuffer, 0x7FFF, 0 );
                if( iCount == 0 )
                    {
                    //
                    // This will happen when the socket is closed at the client end.
                    //
                    break;
                    }

                // 
                // Since ee are in non blocking mode, we need to check to see
                // if were are getting ahead of ourselves.
                // 
                if( iCount == SOCKET_ERROR )
                    {
                    if( WSAGetLastError() == WSAEWOULDBLOCK )
                        {
                        // 
                        // Looks like we are, continue processing
                        // 
                        continue;
                        }
                    else 
                        {
                        // 
                        // Something bad has happened.
                        // 
                        //SEND_ERROR( pData->socket, SERVER_ERROR_SOCKET );
                        bError = TRUE;
                        break;
                        }
                    }
            
                // 
                // Decrement bytes remaining 
                // 
                dwCount -= iCount;

                // 
                // Check the first chunk of data.  Should look like a quarantine file header.
                // if not, then bail out.
                // 
                if( 0 == iChunkCount++ )
                    {
                    xorBuffer( pBuffer, iCount );
                    // 
                    // Examine buffer.  If it doesn't look like a quarantine file header,
                    // bail out now.
                    // 
                    if( QSPAKSTATUS_OK != QsPakIsQserverHeaderBuffer( (LPBYTE) pBuffer, iCount ) )
                        {
                        // 
                        // Tell client that something went wrong.
                        // 
                        _ASSERT( FALSE );
                        SEND_ERROR( pData->socket, SERVER_ERROR_BOGUS_FILE );
                        bError = TRUE;
                        }
                    xorBuffer( pBuffer, iCount );
                    }
                                                  
                // 
                // Write data to file.
                // 
                if( !bError )
                    {
                    if( FALSE == WriteFile( hFile, pBuffer, iCount, &dwBytesWritten, NULL ) ||
                        (DWORD) iCount != dwBytesWritten )
                        {
                        // 
                        // Tell client that something went wrong.
                        // 
                        _ASSERT( FALSE );
                        switch( GetLastError() )
                            {
                            case ERROR_HANDLE_DISK_FULL:
                            case ERROR_DISK_FULL:
																_Module.LogEvent( IDM_WARNING_SERVER_FULL, EVENTLOG_WARNING_TYPE );
                                SEND_ERROR( pData->socket, SERVER_ERROR_DISK_SPACE );
                                break;
                            default:
                                SEND_ERROR( pData->socket, SERVER_ERROR );
                            }
                        bError = TRUE;
                        }
                    }
                } 
            }

        // 
        // Cleanup.
        // 
        delete [] pBuffer;
        CloseHandle( hFile );

        // 
        // Move file to quarantine folder where it belongs.
        // 
        if( !bError && !bShutdown )
            {
            // 
            // Create file in quarantine folder
            // 
            DWORD dwFileID;
            TCHAR szDestPath[ MAX_PATH + 1];
            TCHAR szQuarantineFolder[ MAX_PATH + 1];
            pModule->GetQuarantineDir( szQuarantineFolder );
            HANDLE hNewFile = CreateUniqueFile( szQuarantineFolder, szDestPath, &dwFileID );
            if( hNewFile == NULL )
                {
                // 
                // Tell client that something went wrong.
                // 
                _ASSERT( FALSE );                
                switch( GetLastError() )
                    {
                    case ERROR_DISK_FULL:
                        SEND_ERROR( pData->socket, SERVER_ERROR_DISK_SPACE );
                        break;
                    default:
                        SEND_ERROR( pData->socket, SERVER_ERROR );
                    }
                }
            else
                {
                USES_CONVERSION;
                //
                // Close handle to new file
                //
                CloseHandle( hNewFile );

                // 
                // Safe off file ID value 
                // 
                HQSERVERITEM hItem;
                if( QSPAKSTATUS_OK == QsPakOpenItem( T2A(szFileName), &hItem ) )
                    {
                    QsPakSetItemValue( hItem, QSERVER_ITEM_INFO_FILEID, QSPAK_TYPE_DWORD, &dwFileID, sizeof( DWORD ) );
                    if( QSPAKSTATUS_OK == QsPakSaveItem( hItem ) )
                        {
                        // 
                        // Copy file to quarantine folder
                        // 
                        if( FALSE == CopyFile( szFileName, szDestPath, FALSE ) )
                            {
                            // 
                            // Tell client that something went wrong.
                            // 
                            _ASSERT( FALSE );                
                            switch( GetLastError() )
                                {
                                case ERROR_DISK_FULL:
                                    SEND_ERROR( pData->socket, SERVER_ERROR_DISK_SPACE );
                                    break;
                                default:
                                    SEND_ERROR( pData->socket, SERVER_ERROR );
                                }
                            }
                        else
                            {
                            // 
                            // Success!
                            // 
                            SEND_DONE_XFER( pData->socket );

                            // 
                            // Bump total number of bytes in quarantine.
                            // 
							DWORD dwRealSize = GetRealFileSize( szDestPath ); 
                            InterlockedExchangeAdd( (LONG*)&_Module.m_uQserverByteCount, dwRealSize );
                            
                            // 
                            // Bump total number of quarantine items.
                            // 
                            InterlockedIncrement( (LONG*)&_Module.m_ulItemCount );
                            }
                        }
                    else
                        {
                        // 
                        // Not enough room to save attribute.  
                        // 
                        SEND_ERROR( pData->socket, SERVER_ERROR_DISK_SPACE );
                        }

                    // 
                    // Close item
                    // 
                    QsPakReleaseItem( hItem );
                    }
                else
                    {
                    // 
                    // Can't open Qserver item.
                    // 
                    SEND_ERROR( pData->socket, SERVER_ERROR );
                    }
                }
            }

        // 
        // Delete temporary file
        // 
        DeleteFile( szFileName );
        }

    

    // 
    // Cleanup.
    // 
    HANDLE hEvent = CreateEvent( NULL, FALSE, FALSE, NULL );
    WSAEventSelect( pData->socket, hEvent, FD_CLOSE );
    shutdown( pData->socket, SD_SEND );
    WaitForSingleObject( hEvent, INFINITE );
    CloseHandle( hEvent );

    
    closesocket( pData->socket );
    delete pData;
}



///////////////////////////////////////////////////////////////////////////////
//
// Function name : GetXferFileSize
//
// Description   : Local helper routine for getting file size packet from 
//                 the wire
//
// Return type   : DWORD 
//
// Argument      : SOCKET s
//
///////////////////////////////////////////////////////////////////////////////
// 12/21/98 - DBUCHES: Function created / header added 
///////////////////////////////////////////////////////////////////////////////
DWORD GetXferFileSize( SOCKET s )
{
    // 
    // Fetch structure from stream.
    // 
    FILESIZESTRUCT fs;
    LPBYTE p = (LPBYTE) &fs;
    int iCount, iBytesSoFar;
    
    // 
    // Read in the rest of the stuff
    // 
    iBytesSoFar = 0;
    while( iBytesSoFar != sizeof( FILESIZESTRUCT ) )
        {
        p += iBytesSoFar;
        iCount = recv( s, (char*)p, sizeof( FILESIZESTRUCT) - iBytesSoFar, 0 );
        // 
        // We are non blocking, so we could be ahead of the stream.
        // 
        if( iCount == SOCKET_ERROR )
            {
            if( WSAGetLastError() == WSAEWOULDBLOCK )
                continue;
            else 
                return 0xFFFFFFFF;
            }
        iBytesSoFar += iCount;
        }

    // 
    // Verify signature.
    // 
    if( fs.dwSignature != FILE_SIZE_SIGNATURE )
        {
        return 0xFFFFFFFF;
        }

    // 
    // Return the file size.
    // 
    return fs.dwFileSize;
}



///////////////////////////////////////////////////////////////////////////////
//
// Function name : SendStatus
//
// Description   : This routine sends a DWORD status code to the client machine.
//
// Return type   : void 
//
// Argument      : SOCKET s
// Argument      : DWORD dwCode
//
///////////////////////////////////////////////////////////////////////////////
// 12/22/98 - DBUCHES: Function created / header added 
///////////////////////////////////////////////////////////////////////////////
void SendStatus( SOCKET s, DWORD dwCode )
{
    // 
    // Send to client, ignore return value.
    // 
    send( s, (char*) &dwCode, sizeof( DWORD ), 0 );
}


///////////////////////////////////////////////////////////////////////////////
//
// Function name : CreateUniqueFile
//
// Description   : This routine will attempt to create a unique file in the 
//                 specified path.
//
// Return type   : HANDLE - Handle to file created, NULL on error.
//
// Argument      : LPCTSTR szPath - Directory where new file should be created.
// Argument      : LPTSTR szDestPath - Full path of file created. Assumed to be
//                 MAX_PATH in size.
//
///////////////////////////////////////////////////////////////////////////////
// 1/5/99 - DBUCHES: Function created / header added 
///////////////////////////////////////////////////////////////////////////////
HANDLE CreateUniqueFile( LPCTSTR szPath, LPTSTR szDestPath, DWORD* pdwFileID )
{
    TCHAR szFullPath[ MAX_PATH ];
    HANDLE hFile = NULL;

    //
    // Seed random number gerneator.
    //
    srand( (unsigned) time( NULL ) );
    
    while( TRUE )
        {
        // 
        // Generate file name.
        // 
        DWORD dwNumber = MAKELONG( rand(), rand() );
        wsprintf( szFullPath, _T( "%s\\%.8X" ), szPath, dwNumber );

        //
        // Attempt to create the new file.
        //
        hFile = CreateFile( szFullPath,
                           GENERIC_WRITE | GENERIC_READ,
                           0,
                           NULL,
                           CREATE_NEW,
                           FILE_ATTRIBUTE_NORMAL,
                           NULL);
        //
        // If we were unable to create the file, loop only if the file could not
        // be created due to a filename collision.
        //
        if( INVALID_HANDLE_VALUE == hFile )
            {
            //
            // Find out why the file could not be created.
            //
            DWORD dwLastError = GetLastError();

            //
            // If we got a name colision, try again
            //
            if( ( ERROR_ALREADY_EXISTS == dwLastError ) ||
                ( ERROR_FILE_EXISTS == dwLastError ) )
                {
                continue;
                }
			else
				{
				break;
				}
			}
        else
            {
            //
            // Looks like we have a valid handle, so break out.
            //
            if( pdwFileID != NULL )
                *pdwFileID = dwNumber;
            break;
            }
        }

    // 
    // Copy destination file name.
    // 
    if( hFile == INVALID_HANDLE_VALUE )
        {
        hFile = NULL;
        }
    else
        {
        lstrcpy( szDestPath, szFullPath );
        }

    // 
    // Return file handle
    // 
    return hFile;

}

///////////////////////////////////////////////////////////////////////////////
//
// Function name: xorBuffer
//
// Description  : This routine will simply XOR all the bytes of the specified 
//                buffer
//
// Return type  : void 
//
// Argument     : void* pBuffer
// Argument     : int iSize
//
///////////////////////////////////////////////////////////////////////////////
// 12/29/98 - DBUCHES: Function created / header added 
///////////////////////////////////////////////////////////////////////////////
void xorBuffer( void* pBuffer, int iSize )
{
    for( int i = 0; i < iSize; i++ )
        ((BYTE*)pBuffer)[i] ^= (BYTE) 0xFF;
}



///////////////////////////////////////////////////////////////////////////////
//
// Function name : ConfigWatchThread
//
// Description   : This thread watches for configuration information changes.
//                 When they occur, the changes are read from the registry.
//
// Return type   : void 
//
// Argument      : DWORD dwData
//
///////////////////////////////////////////////////////////////////////////////
// 1/25/99 - DBUCHES: Function created / header added 
///////////////////////////////////////////////////////////////////////////////
void ConfigWatchThread( DWORD dwData )
{
    // 
    // Make sure our pointer is good.
    // 
    CServiceModule* pModule = (CServiceModule*) dwData;
    _ASSERT( pModule );

    // 
    // Open our reg key
    // 
    CRegKey reg;
    if( ERROR_SUCCESS != reg.Open( HKEY_LOCAL_MACHINE, REGKEY_QSERVER, KEY_READ | KEY_WRITE) )
        {
        _ASSERT( FALSE );
        return;
        }

    // 
    // Set up event array.
    // 
    HANDLE aEvents[ 2 ];
    aEvents[0] = pModule->m_hStopping;
    aEvents[1] = pModule->m_hConfigEvent;

    while( TRUE )
        {
        // 
        // Wait here for something to happen
        // 
        if( WAIT_OBJECT_0 == WaitForMultipleObjects( 2, aEvents, FALSE, INFINITE ) )
            {
            // 
            // Stop signaled, bail out now.
            // 
            break;
            }

        // 
        // Refresh all configuration data.
        // 
        DWORD dwTemp = 0xFFFFFFFF;
        DWORD dwSize = MAX_PATH * sizeof( TCHAR );
        DWORD dwAttr;
        BOOL bCommunicationChange = FALSE;
        TCHAR szQuarantineFolder[ MAX_PATH + 1];
        if( ERROR_SUCCESS == reg.QueryValue( szQuarantineFolder, REGVALUE_QUARANTINE_FOLDER, &dwSize ) )
            {
            // 
            // Q: Does this directory exist?
            // 
            dwAttr = GetFileAttributes( szQuarantineFolder );
            if( dwAttr == 0xFFFFFFFF )
                {
                // 
                // No it doesn't, so try creating it
                // 
                if( false == CreateDirectoryPath( szQuarantineFolder ) )
                    {
                    // 
                    // Could not create this folder, so assume current value is 
                    // still good.
                    // 
                    _Module.GetQuarantineDir( szQuarantineFolder );
                    reg.SetValue( szQuarantineFolder, REGVALUE_QUARANTINE_FOLDER );
                    }
                else
                    {
                    // 
                    // Looks good, update running copy of data.
                    // 
                    _Module.SetQuarantineDir( szQuarantineFolder );
                    }
                }
            else if( (dwAttr & FILE_ATTRIBUTE_DIRECTORY) )
                {
                // 
                // This directory already exists.  Cool deal, so update 
                // in-memory data.
                // 
                _Module.SetQuarantineDir( szQuarantineFolder );
                }
            else
                {
                // 
                // It is not an existing directory, so we must be colliding with 
                // and existing file.  Bogus.
                // 
                _Module.GetQuarantineDir( szQuarantineFolder );
                reg.SetValue( szQuarantineFolder, REGVALUE_QUARANTINE_FOLDER );
                }
            }


        if( ERROR_SUCCESS == reg.QueryValue( dwTemp, REGVALUE_PORT ) )
            {
            if( dwTemp != (DWORD) pModule->GetIPPort() )
                {
                pModule->SetIPPort((int)dwTemp);
                bCommunicationChange = TRUE;
                }
            }

        if( ERROR_SUCCESS == reg.QueryValue( dwTemp, REGVALUE_LISTEN_IP ) )
            {
            if( dwTemp != (DWORD) pModule->GetListenIP() )
                {
                pModule->SetListenIP( (BOOL) dwTemp );  
                bCommunicationChange = TRUE;
                }
            }

        if( ERROR_SUCCESS == reg.QueryValue( dwTemp, REGVALUE_SPXSOCKET ) )
            {
            if( dwTemp != (DWORD) pModule->GetSPXPort() )
                {
                pModule->SetSPXPort((int)dwTemp);
                bCommunicationChange = TRUE;
                }
            }

        if( ERROR_SUCCESS == reg.QueryValue( dwTemp, REGVALUE_LISTEN_SPX ) )
            {
            if( dwTemp != (DWORD) pModule->GetListenSPX() )
                {
                pModule->SetListenSPX( (BOOL )dwTemp );                
                bCommunicationChange = TRUE;
                }
            }

        if( ERROR_SUCCESS == reg.QueryValue( dwTemp, REGVALUE_MAX_SIZE ) )
            {
            pModule->SetDiskQuota( dwTemp );                
            }

        if( ERROR_SUCCESS == reg.QueryValue( dwTemp, REGVALUE_MAX_FILES ) )
            {
            pModule->SetFileQuota( dwTemp );
            }

        // 
        // Tell listening threads that options have changed
        // 
        if( bCommunicationChange )
            {
            PulseEvent( pModule->m_hSocketConfig );
            bCommunicationChange = FALSE;
            }

        }
}

///////////////////////////////////////////////////////////////////////////////
//
// Function name: GetRealFileSize
//
// Description: This routine will return the file size for a specified file.
//
// Return type: DWORD
//
// Argument: LPCTSTR szFileName
//
///////////////////////////////////////////////////////////////////////////////
// 5/11/99 - DBUCHES: Function created / header added 
///////////////////////////////////////////////////////////////////////////////
DWORD GetRealFileSize( LPCTSTR szFileName )
{
	DWORD dwSize = 0;

    HANDLE hFile = CreateFile( szFileName, 
                               GENERIC_READ, 
                               FILE_SHARE_READ, 
                               NULL,
                               OPEN_EXISTING,
                               0,
                               NULL );
    if( hFile != INVALID_HANDLE_VALUE )
        {
        dwSize = GetFileSize( hFile, NULL );
        CloseHandle( hFile );
        }

	return dwSize;
}
