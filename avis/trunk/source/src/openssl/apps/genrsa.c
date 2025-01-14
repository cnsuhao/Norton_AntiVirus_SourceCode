/* apps/genrsa.c */
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

#ifndef NO_RSA
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "apps.h"
#include <openssl/bio.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include <openssl/pem.h>

#define DEFBITS	512
#undef PROG
#define PROG genrsa_main

static void MS_CALLBACK genrsa_cb(int p, int n, void *arg);
static long gr_load_rand(char *names);
int MAIN(int argc, char **argv)
	{
	int ret=1;
	char buffer[200];
	RSA *rsa=NULL;
	int i,num=DEFBITS;
	long rnum=0,l;
	EVP_CIPHER *enc=NULL;
	unsigned long f4=RSA_F4;
	char *outfile=NULL;
	char *inrand=NULL,*randfile;
	BIO *out=NULL;

	apps_startup();

	if (bio_err == NULL)
		if ((bio_err=BIO_new(BIO_s_file())) != NULL)
			BIO_set_fp(bio_err,stderr,BIO_NOCLOSE|BIO_FP_TEXT);
	if ((out=BIO_new(BIO_s_file())) == NULL)
		{
		BIO_printf(bio_err,"unable to creat BIO for output\n");
		goto err;
		}

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
		else if (strcmp(*argv,"-3") == 0)
			f4=3;
		else if (strcmp(*argv,"-F4") == 0)
			f4=RSA_F4;
		else if (strcmp(*argv,"-rand") == 0)
			{
			if (--argc < 1) goto bad;
			inrand= *(++argv);
			}
#ifndef NO_DES
		else if (strcmp(*argv,"-des") == 0)
			enc=EVP_des_cbc();
		else if (strcmp(*argv,"-des3") == 0)
			enc=EVP_des_ede3_cbc();
#endif
#ifndef NO_IDEA
		else if (strcmp(*argv,"-idea") == 0)
			enc=EVP_idea_cbc();
#endif
		else
			break;
		argv++;
		argc--;
		}
	if ((argc >= 1) && ((sscanf(*argv,"%d",&num) == 0) || (num < 0)))
		{
bad:
		BIO_printf(bio_err,"usage: genrsa [args] [numbits]\n");
		BIO_printf(bio_err," -des      - encrypt the generated key with DES in cbc mode\n");
		BIO_printf(bio_err," -des3     - encrypt the generated key with DES in ede cbc mode (168 bit key)\n");
#ifndef NO_IDEA
		BIO_printf(bio_err," -idea     - encrypt the generated key with IDEA in cbc mode\n");
#endif
		BIO_printf(bio_err," -out file - output the key to 'file\n");
		BIO_printf(bio_err," -f4       - use F4 (0x10001) for the E value\n");
		BIO_printf(bio_err," -3        - use 3 for the E value\n");
		BIO_printf(bio_err," -rand file:file:...\n");
		BIO_printf(bio_err,"           - load the file (or the files in the directory) into\n");
		BIO_printf(bio_err,"             the random number generator\n");
		goto err;
		}
		
	ERR_load_crypto_strings();
	if (outfile == NULL)
		BIO_set_fp(out,stdout,BIO_NOCLOSE);
	else
		{
		if (BIO_write_filename(out,outfile) <= 0)
			{
			perror(outfile);
			goto err;
			}
		}

#ifdef WINDOWS
	BIO_printf(bio_err,"Loading 'screen' into random state -");
	BIO_flush(bio_err);
	RAND_screen();
	BIO_printf(bio_err," done\n");
#endif
	randfile=RAND_file_name(buffer,200);
	if ((randfile == NULL) ||
		 !(rnum=(long)RAND_load_file(randfile,1024L*1024L)))
		{
		BIO_printf(bio_err,"unable to load 'random state'\n");
		}

	if (inrand == NULL)
		{
		if (rnum == 0)
			{
			BIO_printf(bio_err,"warning, not much extra random data, consider using the -rand option\n");
			}
		}
	else
		{
		rnum+=gr_load_rand(inrand);
		}
	if (rnum != 0)
		BIO_printf(bio_err,"%ld semi-random bytes loaded\n",rnum);

	BIO_printf(bio_err,"Generating RSA private key, %d bit long modulus\n",
		num);
	rsa=RSA_generate_key(num,f4,genrsa_cb,bio_err);
		
	if (randfile == NULL)
		BIO_printf(bio_err,"unable to write 'random state'\n");
	else
		RAND_write_file(randfile);

	if (rsa == NULL) goto err;
	
	/* We need to do the folloing for when the base number size is <
	 * long, esp windows 3.1 :-(. */
	l=0L;
	for (i=0; i<rsa->e->top; i++)
		{
#ifndef SIXTY_FOUR_BIT
		l<<=BN_BITS4;
		l<<=BN_BITS4;
#endif
		l+=rsa->e->d[i];
		}
	BIO_printf(bio_err,"e is %ld (0x%lX)\n",l,l);
	if (!PEM_write_bio_RSAPrivateKey(out,rsa,enc,NULL,0,NULL,NULL))
		goto err;

	ret=0;
err:
	if (rsa != NULL) RSA_free(rsa);
	if (out != NULL) BIO_free(out);
	if (ret != 0)
		ERR_print_errors(bio_err);
	EXIT(ret);
	}

static void MS_CALLBACK genrsa_cb(int p, int n, void *arg)
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

static long gr_load_rand(char *name)
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

		tot+=RAND_load_file(n,1024L*1024L);
		if (last) break;
		}
	return(tot);
	}
#endif
