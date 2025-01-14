/* apps/version.c */
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
#include <string.h>
#include "apps.h"
#include <openssl/evp.h>
#include <openssl/crypto.h>

#undef PROG
#define PROG	version_main

int MAIN(int argc, char **argv)
	{
	int i,ret=0;
	int cflags=0,version=0,date=0,options=0,platform=0;

	apps_startup();

	if (bio_err == NULL)
		if ((bio_err=BIO_new(BIO_s_file())) != NULL)
			BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);

	if (argc == 1) version=1;
	for (i=1; i<argc; i++)
		{
		if (strcmp(argv[i],"-v") == 0)
			version=1;	
		else if (strcmp(argv[i],"-b") == 0)
			date=1;
		else if (strcmp(argv[i],"-f") == 0)
			cflags=1;
		else if (strcmp(argv[i],"-o") == 0)
			options=1;
		else if (strcmp(argv[i],"-p") == 0)
			platform=1;
		else if (strcmp(argv[i],"-a") == 0)
			date=version=cflags=options=platform=1;
		else
			{
			BIO_printf(bio_err,"usage:version -[avbofp]\n");
			ret=1;
			goto end;
			}
		}

	if (version) printf("%s\n",SSLeay_version(SSLEAY_VERSION));
	if (date)    printf("%s\n",SSLeay_version(SSLEAY_BUILT_ON));
	if (platform) printf("%s\n",SSLeay_version(SSLEAY_PLATFORM));
	if (options) 
		{
		printf("options:  ");
		printf("%s ",BN_options());
#ifndef NO_MD2
		printf("%s ",MD2_options());
#endif
#ifndef NO_RC4
		printf("%s ",RC4_options());
#endif
#ifndef NO_DES
		printf("%s ",des_options());
#endif
#ifndef NO_IDEA
		printf("%s ",idea_options());
#endif
#ifndef NO_BF
		printf("%s ",BF_options());
#endif
		printf("\n");
		}
	if (cflags)  printf("%s\n",SSLeay_version(SSLEAY_CFLAGS));
end:
	EXIT(ret);
	}
