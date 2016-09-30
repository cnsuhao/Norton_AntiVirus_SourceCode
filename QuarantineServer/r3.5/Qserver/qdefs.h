/*
 * PROPRIETARY/CONFIDENTIAL.  use of this product is subject to license terms.
 * Copyright (c) 2005 Symantec Corporation.  All Rights Reserved.
 *
*/
//////////////////////////////////////////////////////////////////////////
//
// $Header: $
//
//
//
//////////////////////////////////////////////////////////////////////////
// Created by: DBUCHES   12-1-98 11:52:48am
//////////////////////////////////////////////////////////////////////////
// $Log: $
//////////////////////////////////////////////////////////////////////////

#ifndef _QSTATUS_H_
#define _QSTATUS_H_

#pragma pack( push, 8 )

//////////////////////////////////////////////////////////////////////////
// QSERVERSTATUS
//////////////////////////////////////////////////////////////////////////

// 
// Do not change the order of members of this structure!  If you need to add
// elements, add them to the end of the structure.
// 
typedef struct _QSERVERSTATUS {
    DWORD   dwSize;
    DWORD   dwNumItems;
    }
QSERVERSTATUS, *PQSERVERSTATUS, *LPQSERVERSTATUS;

#define QSERVERSTATUS_SIZE sizeof( QSERVERSTATUS )


#pragma pack( pop )
#endif