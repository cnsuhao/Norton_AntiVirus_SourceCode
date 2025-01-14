/* crypto/tmdiff.c */
/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)
 * All rights reserved.
 *
 * This package is an SSL implementation written
 * by Eric Young (eay@cryptsoft.com).
 * The implementation was written so as to conform with Netscapes SSL.
 * 
 * This library is free for commercial and non-commercial use as long as
 * the following conditions are aheared to.  The following conditions
 * apply to all code found in this distribution, be it the RC4, RSA,
 * lhash, DES, etc., code; not just the SSL code.  The SSL documentation
 * included with this distribution is covered by the same copyright terms
 * except that the holder is Tim Hudson (tjh@cryptsoft.com).
 * 
 * Copyright remains Eric Young's, and as such any Copyright notices in
 * the code are not to be removed.
 * If this package is used in a product, Eric Young should be given attribution
 * as the author of the parts of the library used.
 * This can be in the form of a textual message at program startup or
 * in documentation (online or textual) provided with the package.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    "This product includes cryptographic software written by
 *     Eric Young (eay@cryptsoft.com)"
 *    The word 'cryptographic' can be left out if the rouines from the library
 *    being used are not cryptographic related :-).
 * 4. If you include any Windows specific code (or a derivative thereof) from 
 *    the apps directory (application code) you must include an acknowledgement:
 *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"
 * 
 * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * 
 * The licence and distribution terms for any publically available version or
 * derivative of this code cannot be changed.  i.e. this code cannot simply be
 * copied and put under another distribution licence
 * [including the GNU Public Licence.]
 */
#include <stdio.h>
#include <stdlib.h>
#include "cryptlib.h"
#include <openssl/tmdiff.h>

#ifdef TIMEB
#undef WIN32
#undef TIMES
#endif

#ifndef MSDOS
#  ifndef WIN32
#    if !defined(VMS) || defined(__DECC)
#      define TIMES
#    endif
#  endif
#endif

#ifndef _IRIX
#  include <time.h>
#endif
#ifdef TIMES
#  include <sys/types.h>
#  include <sys/times.h>
#endif

/* Depending on the VMS version, the tms structure is perhaps defined.
   The __TMS macro will show if it was.  If it wasn't defined, we should
   undefine TIMES, since that tells the rest of the program how things
   should be handled.				-- Richard Levitte */
#if defined(VMS) && defined(__DECC) && !defined(__TMS)
#undef TIMES
#endif

#if defined(sun) || defined(__ultrix)
#define _POSIX_SOURCE
#include <limits.h>
#include <sys/param.h>
#endif

#ifndef TIMES
#include <sys/timeb.h>
#endif

#ifdef WIN32
#include <windows.h>
#endif

/* The following if from times(3) man page.  It may need to be changed */
#ifndef HZ
# ifndef CLK_TCK
#  ifndef _BSD_CLK_TCK_ /* FreeBSD hack */
#   define HZ  100.0
#  else /* _BSD_CLK_TCK_ */
#   define HZ ((double)_BSD_CLK_TCK_)
#  endif
# else /* CLK_TCK */
#  define HZ ((double)CLK_TCK)
# endif
#endif

typedef struct ms_tm
	{
#ifdef TIMES
	struct tms ms_tms;
#else
#  ifdef WIN32
	HANDLE thread_id;
	FILETIME ms_win32;
#  else
	struct timeb ms_timeb;
#  endif
#endif
	} MS_TM;

char *ms_time_new(void)
	{
	MS_TM *ret;

	ret=(MS_TM *)Malloc(sizeof(MS_TM));
	if (ret == NULL)
		return(NULL);
	memset(ret,0,sizeof(MS_TM));
#ifdef WIN32
	ret->thread_id=GetCurrentThread();
#endif
	return((char *)ret);
	}

void ms_time_free(char *a)
	{
	if (a != NULL)
		Free(a);
	}

void ms_time_get(char *a)
	{
	MS_TM *tm=(MS_TM *)a;
#ifdef WIN32
	FILETIME tmpa,tmpb,tmpc;
#endif

#ifdef TIMES
	times(&tm->ms_tms);
#else
#  ifdef WIN32
	GetThreadTimes(tm->thread_id,&tmpa,&tmpb,&tmpc,&(tm->ms_win32));
#  else
	ftime(&tm->ms_timeb);
#  endif
#endif
	}

double ms_time_diff(char *ap, char *bp)
	{
	MS_TM *a=(MS_TM *)ap;
	MS_TM *b=(MS_TM *)bp;
	double ret;

#ifdef TIMES
	ret=(b->ms_tms.tms_utime-a->ms_tms.tms_utime)/HZ;
#else
# ifdef WIN32
	{
#ifdef __GNUC__
	signed long long la,lb;
#else
	signed _int64 la,lb;
#endif
	la=a->ms_win32.dwHighDateTime;
	lb=b->ms_win32.dwHighDateTime;
	la<<=32;
	lb<<=32;
	la+=a->ms_win32.dwLowDateTime;
	lb+=b->ms_win32.dwLowDateTime;
	ret=((double)(lb-la))/1e7;
	}
# else
	ret=	 (double)(b->ms_timeb.time-a->ms_timeb.time)+
		(((double)b->ms_timeb.millitm)-
		((double)a->ms_timeb.millitm))/1000.0;
#  endif
#endif
	return((ret < 0.0000001)?0.0000001:ret);
	}

int ms_time_cmp(char *ap, char *bp)
	{
	MS_TM *a=(MS_TM *)ap,*b=(MS_TM *)bp;
	double d;
	int ret;

#ifdef TIMES
	d=(b->ms_tms.tms_utime-a->ms_tms.tms_utime)/HZ;
#else
# ifdef WIN32
	d =(b->ms_win32.dwHighDateTime&0x000fffff)*10+b->ms_win32.dwLowDateTime/1e7;
	d-=(a->ms_win32.dwHighDateTime&0x000fffff)*10+a->ms_win32.dwLowDateTime/1e7;
# else
	d=	 (double)(b->ms_timeb.time-a->ms_timeb.time)+
		(((double)b->ms_timeb.millitm)-(double)a->ms_timeb.millitm)/1000.0;
#  endif
#endif
	if (d == 0.0)
		ret=0;
	else if (d < 0)
		ret= -1;
	else
		ret=1;
	return(ret);
	}

