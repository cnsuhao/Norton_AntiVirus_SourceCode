/* apps/gendh.c */
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

#ifndef NO_DH
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "apps.h"
#include <openssl/bio.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include <openssl/bn.h>
#include <openssl/dh.h>
#include <openssl/x509.h>
#include <openssl/pem.h>

#define DEFBITS	512
#undef PROG
#define PROG gendh_main

static void MS_CALLBACK dh_cb(int p, int n, void *arg);
static long dh_load_rand(char *names);
int MAIN(int argc, char **argv)
	{
	char buffer[200];
	DH *dh=NULL;
	int ret=1,num=DEFBITS;
	int g=2;
	char *outfile=NULL;
	char *inrand=NULL,*randfile;
	BIO *out=NULL;

	apps_startup();

	if (bio_err == NULL)
		if ((bio_err=BIO_new(BIO_s_file())) != NULL)
			BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);

	argv++;
	argc--;
	for (;;)
		{
		if (argc <= 0) break;
		if (strcmp(*argv,"-out") == 0)
			{
			if (--argc < 1) goto bad;
			outfile= *(++argv);
			}
		else if (strcmp(*argv,"-2") == 0)
			g=2;
	/*	else if (strcmp(*argv,"-3") == 0)
			g=3; */
		else if (strcmp(*argv,"-5") == 0)
			g=5;
		else if (strcmp(*argv,"-rand") == 0)
			{
			if (--argc < 1) goto bad;
			inrand= *(++argv);
			}
		else
			break;
		argv++;
		argc--;
		}
	if ((argc >= 1) && ((sscanf(*argv,"%d",&num) == 0) || (num < 0)))
		{
bad:
		BIO_printf(bio_err,"usage: gendh [args] [numbits]\n");
		BIO_printf(bio_err," -out file - output the key to 'file\n");
		BIO_printf(bio_err," -2    use 2 as the generator value\n");
	/*	BIO_printf(bio_err," -3    use 3 as the generator value\n"); */
		BIO_printf(bio_err," -5    use 5 as the generator value\n");
		BIO_printf(bio_err," -rand file:file:...\n");
		BIO_printf(bio_err,"           - load the file (or the files in the directory) into\n");
		BIO_printf(bio_err,"             the random number generator\n");
		goto end;
		}
		
	out=BIO_new(BIO_s_file());
	if (out == NULL)
		{
		ERR_print_errors(bio_err);
		goto end;
		}

	if (outfile == NULL)
		BIO_set_fp(out,stdout,BIO_NOCLOSE);
	else
		{
		if (BIO_write_filename(out,outfile) <= 0)
			{
			perror(outfile);
			goto end;
			}
		}

	randfile=RAND_file_name(buffer,200);
	if ((randfile == NULL)|| !RAND_load_file(randfile,1024L*1024L))
		BIO_printf(bio_err,"unable to load 'random state'\n");

	if (inrand == NULL)
		BIO_printf(bio_err,"warning, not much extra random data, consider using the -rand option\n");
	else
		{
		BIO_printf(bio_err,"%ld semi-random bytes loaded\n",
			dh_load_rand(inrand));
		}

	BIO_printf(bio_err,"Generating DH parameters, %d bit long strong prime, generator of %d\n",num,g);
	BIO_printf(bio_err,"This is going to take a long time\n");
	dh=DH_generate_parameters(num,g,dh_cb,bio_err);
		
	if (dh == NULL) goto end;

	if (randfile == NULL)
		BIO_printf(bio_err,"unable to write 'random state'\n");
	else
		RAND_write_file(randfile);

	if (!PEM_write_bio_DHparams(out,dh))
		goto end;
	ret=0;
end:
	if (ret != 0)
		ERR_print_errors(bio_err);
	if (out != NULL) BIO_free(out);
	if (dh != NULL) DH_free(dh);
	EXIT(ret);
	}

static void MS_CALLBACK dh_cb(int p, int n, void *arg)
	{
	char c='*';

	if (p == 0) c='.';
	if (p == 1) c='+';
	if (p == 2) c='*';
	if (p == 3) c='\n';
	BIO_write((BIO *)arg,&c,1);
	(void)BIO_flush((BIO *)arg);
#ifdef LINT
	p=n;
#endif
	}

static long dh_load_rand(char *name)
	{
	char *p,*n;
	int last;
	long tot=0;

	for (;;)
		{
		last=0;
		for (p=name; ((*p != '\0') && (*p != LIST_SEPARATOR_CHAR)); p++);
		if (*p == '\0') last=1;
		*p='\0';
		n=name;
		name=p+1;
		if (*n == '\0') break;

		tot+=RAND_load_file(n,1);
		if (last) break;
		}
	return(tot);
	}
#endif
