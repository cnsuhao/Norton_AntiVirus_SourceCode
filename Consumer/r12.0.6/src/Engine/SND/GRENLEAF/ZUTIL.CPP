//************************************************************************
//
// $Header:   S:/GRENLEAF/VCS/ZUTIL.CPv   1.0   12 Mar 1998 12:18:06   DCHI  $
//
// Description:
//  Greenleaf ArchiveLib 2.0
//
//************************************************************************
// $Log:   S:/GRENLEAF/VCS/ZUTIL.CPv  $
// 
//    Rev 1.0   12 Mar 1998 12:18:06   DCHI
// Initial revision.
// 
//************************************************************************

//
// ZUTIL.CPP
//
//  Source file for ArchiveLib 2.0
//
//  No Copyright claimed by Greenleaf Software!
//
// DESCRIPTION
//
//  This is one of the ZLIB source files, with as few changes as possible.
//
// REVISION HISTORY
//
//   February 14, 1996  2.0A : New release
#include "arclib.h"
#if !defined( AL_IBM )
#pragma hdrstop
#endif
#if defined( AL_BORLAND )
#pragma option -w-
#endif

/* zutil.c -- target dependent utility functions for the compression library
 * Copyright (C) 1995 Jean-loup Gailly.
 * For conditions of distribution and use, see copyright notice in zlib.h
 */

/* $Id: zutil.c,v 1.8 1995/05/03 17:27:12 jloup Exp $ */

#include <stdio.h>
#include <stdlib.h>

#include "zutil.h"

//
// Everyone supports exit()
//
//#ifndef __GO32__
//extern void exit __P((int));
//#endif

char *zlib_version = ZLIB_VERSION;

char *z_errmsg[8] = {
"stream end",          /* Z_STREAM_END    1 */
"",                    /* Z_OK            0 */
"file error",          /* Z_ERRNO        (-1) */
"stream error",        /* Z_STREAM_ERROR (-2) */
"data error",          /* Z_DATA_ERROR   (-3) */
"insufficient memory", /* Z_MEM_ERROR    (-4) */
"buffer error",        /* Z_BUF_ERROR    (-5) */
""};


void z_error (char *)
{
//    fprintf(stderr, "%s\n", m);
//    exit(1);
}

#ifndef HAVE_MEMCPY

void zmemcpy(dest, source, len)
    Byte* dest;
    Byte* source;
    uInt  len;
{
    if (len == 0) return;
    do {
        *dest++ = *source++; /* ??? to be unrolled */
    } while (--len != 0);
}

void zmemzero(dest, len)
    Byte* dest;
    uInt  len;
{
    if (len == 0) return;
    do {
        *dest++ = 0;  /* ??? to be unrolled */
    } while (--len != 0);
}
#endif

#if defined(__TURBOC__) && !defined( AL_FLAT_MODEL )

#  define MY_ZCALLOC

/* Turbo C malloc() does not allow dynamic allocation of 64K bytes
 * and farmalloc(64K) returns a pointer with an offset of 8, so we
 * must fix the pointer. Warning: the pointer must be put back to its
 * original form in order to free it, use zcfree().
 */

#define MAX_PTR 10
/* 10*64K = 640K */

local int next_ptr = 0;

typedef struct ptr_table_s {
    voidp org_ptr;
    voidp new_ptr;
} ptr_table;

local ptr_table table[MAX_PTR];
/* This table is used to remember the original form of pointers
 * to large buffers (64K). Such pointers are normalized with a zero offset.
 * Since MSDOS is not a preemptive multitasking OS, this table is not
 * protected from concurrent access. This hack doesn't work anyway on
 * a protected system like OS/2. Use Microsoft C instead.
 */

voidp zcalloc (voidp opaque, unsigned items, unsigned size)
{
    voidp buf = opaque; /* just to make some compilers happy */
    ulg bsize = (ulg)items*size;

    if (bsize < 65536L) {
        buf = farmalloc(bsize);
#if 0
    cout << "farmalloc( " << items << "," << size << " = " << (void _far *) buf  << endl;
#endif
        if (*(ush*)&buf != 0) return buf;
    } else {
        buf = farmalloc(bsize + 16L);
    }
    if (buf == NULL || next_ptr >= MAX_PTR) return NULL;
    table[next_ptr].org_ptr = buf;

    /* Normalize the pointer to seg:0 */
    *((ush*)&buf+1) += ((ush)((uch*)buf-0) + 15) >> 4;
    *(ush*)&buf = 0;
    table[next_ptr++].new_ptr = buf;
#if 0
    cout << "farmalloc( " << items << "," << size << " = " << (void _far *) buf  << endl;
#endif
    return buf;
}

void  zcfree (voidp opaque, voidp ptr)
{
    int n;
    if (*(ush*)&ptr != 0) { /* object < 64K */
        farfree(ptr);
        return;
    }
    /* Find the original pointer */
    for (n = 0; n < next_ptr; n++) {
        if (ptr != table[n].new_ptr) continue;

        farfree(table[n].org_ptr);
        while (++n < next_ptr) {
            table[n-1] = table[n];
        }
        next_ptr--;
        return;
    }
    ptr = opaque; /* just to make some compilers happy */
    z_error("zcfree: ptr not found");
}
#endif /* __TURBOC__ */

//#if defined(M_I86CM) || defined(M_I86LM) /* MSC compact or large model */
#if !defined( AL_FLAT_MODEL )
#if defined( AL_MICROSOFT ) || defined( AL_SYMANTEC ) || defined( AL_WATCOM )
#  define MY_ZCALLOC

//#if (!defined(_MSC_VER) || (_MSC_VER < 600))
//#  define _halloc  halloc
//#  define _hfree   hfree
//#endif

#if defined( AL_WATCOM )
#  define _halloc  halloc
#  define _hfree   hfree
#endif


voidp zcalloc (voidp opaque, unsigned items, unsigned size)
{
    if (opaque) opaque = 0; /* to make compiler happy */
    void _huge *h = _halloc((long)items, size);
#if 0
    cout << "halloc( " << items << "," << size << " = " << h << endl;
#endif
    return h;
}

void  zcfree (voidp opaque, voidp ptr)
{
    if (opaque) opaque = 0; /* to make compiler happy */
    _hfree(ptr);
}

#endif /* defined(M_I86CM) || defined(M_I86LM) */
#endif

#ifndef MY_ZCALLOC /* Any system without a special alloc function */

#if 0
#ifndef __GO32__
extern voidp calloc __P((uInt items, uInt size));
extern void  free   __P((voidp ptr));
#endif
#endif

voidp zcalloc (voidp, unsigned items, unsigned size)
{
    return calloc(items, size);
}

void  zcfree (voidp, voidp ptr)
{
    free(ptr);
}

#endif /* MY_ZCALLOC */
