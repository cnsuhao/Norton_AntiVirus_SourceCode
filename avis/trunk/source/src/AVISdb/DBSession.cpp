//
//	IBM AntiVirus Immune System
//
//	File Name:	DBSession.cpp
//	Author:		Andy Klapper
//
//	This class represents a connection to the database.  Each thread
//	that uses the database needs to open a connection to the database.
//
//	DBSession		Constructor
//	~DBSession		Destructor
//	GetErrorMessage		Returns the error message generated by the last
//						use of the DBSession object (if any).
//
//	$Log: /DBService/DBService/DBSession.cpp $
//
//1     8/19/98 9:10p Andytk
//Initial check in.
//
//1     8/19/98 9:10p Andytk
//Initial check in
//

#include "stdafx.h"

#include <iostream>

#include "DBSession.h"
#include "AVISDBException.h"

#include <CMclAutoLock.h>

#include <Logger.h>

typedef unsigned char uchar;

using namespace std;

const AVISDBException::TypeOfException DBSession::exceptType =
													exceptType;

//
//	NOTE:	This method is NOT exception safe!

DBSession::DBSession() : sqlSession(0), badSession(true)
{
static CMclCritSec	creating;

	RETCODE	retcode;

	CMclAutoLock	autoLock(creating);

	retcode = SQLAllocHandle(SQL_HANDLE_DBC, DBService::DatabaseHandle(),
								&sqlSession);

	if (SQL_SUCCESS == retcode || SQL_SUCCESS_WITH_INFO == retcode)
	{
		if (SQL_SUCCESS_WITH_INFO == retcode)
		{
			string	errMsg("DBSession Constructor, SQLAllocHandle, success with info, ");
			string	details;

			GetErrorMessage(details);
			errMsg	+= details;
			Logger::Log(Logger::LogWarning, Logger::LogAvisDB, errMsg.c_str());
		}

		string	dbName;

		if (DBService::Name(dbName))
		{
			char	 buffer[100];

			strncpy(buffer, dbName.c_str(), 100);
			retcode = SQLConnect(sqlSession,
									(SQLCHAR *) buffer, SQL_NTS,
									(SQLCHAR *) "", SQL_NTS,
									(SQLCHAR *) "", SQL_NTS);

			if (SQL_SUCCESS == retcode || SQL_SUCCESS_WITH_INFO == retcode)
			{
				badSession = false;
				if (SQL_SUCCESS_WITH_INFO == retcode)
				{
					string	errMsg("DBSession Constructor, SQLConnect, success with info, ");
					string	details;

					GetErrorMessage(details);
					errMsg	+= details;
					Logger::Log(Logger::LogWarning, Logger::LogAvisDB, errMsg.c_str());
				}
			}
			else
			{
				SQLDisconnect(sqlSession);

				string	errMsg("Constructor, SQLConnect, failed, [ ");
				string	details;

				GetErrorMessage(details);
				errMsg	+= details;
				errMsg	+= " ]";
				SQLFreeHandle(SQL_HANDLE_DBC, sqlSession);

				throw AVISDBException(exceptType, errMsg);
			}
		}
		else
		{
			string	errMsg("Constructor, SQLAllocHandle, failed [ ");
			string	details;

			GetErrorMessage(details);
			errMsg	+= details;
			errMsg	+= " ]";

			SQLFreeHandle(SQL_HANDLE_DBC, sqlSession);

			throw AVISDBException(exceptType, errMsg);
		}
	}
	else if (SQL_INVALID_HANDLE == retcode)
	{
		throw AVISDBException(exceptType,
								"DBSession Constructor, invalid service handle!!!");
	}
	else
	{
		string	errMsg("Constructor, SQLAllocHandle, failed [ ");
		string	details;

		GetErrorMessage(details);
		errMsg	+= details;
		errMsg	+= " ]";

		throw AVISDBException(exceptType, errMsg);
	}
}

DBSession::~DBSession()
{
	if (!badSession)
	{
		SQLDisconnect(sqlSession);
		SQLFreeHandle(SQL_HANDLE_DBC, sqlSession);
		badSession = true;
	}
	sqlSession = NULL;
}


bool DBSession::GetErrorMessage(string& errorMessage)
{
static CMclCritSec	working;
	CMclAutoLock	autoLock(working);

	SQLCHAR		sqlState[6];
	SQLINTEGER	nativeErrorPtr;
static	SQLCHAR		messageText[1024];
	SQLSMALLINT	textLengthPtr;
	RETCODE		rc;

	errorMessage = "";

	for (int i = 1;
		SQL_SUCCESS == (rc = SQLGetDiagRec( SQL_HANDLE_DBC, sqlSession, i,
										sqlState, &nativeErrorPtr,
										messageText, 1024, &textLengthPtr))	||
		SQL_SUCCESS_WITH_INFO == rc;
		i++)
	{
		if (0 < errorMessage.size())
			errorMessage += "\n";

		errorMessage += (char *) messageText;
	}

	return 0 < errorMessage.size();
}
