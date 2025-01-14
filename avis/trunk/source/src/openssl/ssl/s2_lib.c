/* ssl/s2_lib.c */
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
#include <openssl/rsa.h>
#include <openssl/objects.h>
#include <openssl/md5.h>
#include "ssl_locl.h"

static long ssl2_default_timeout(void );
const char *ssl2_version_str="SSLv2" OPENSSL_VERSION_PTEXT;

#define SSL2_NUM_CIPHERS (sizeof(ssl2_ciphers)/sizeof(SSL_CIPHER))

OPENSSL_GLOBAL SSL_CIPHER ssl2_ciphers[]={
/* NULL_WITH_MD5 v3 */
#if 0
	{
	1,
	SSL2_TXT_NULL_WITH_MD5,
	SSL2_CK_NULL_WITH_MD5,
	SSL_kRSA|SSL_aRSA|SSL_eNULL|SSL_MD5|SSL_EXP40|SSL_SSLV2,
	0,
	SSL_ALL_CIPHERS,
	},
#endif
/* RC4_128_EXPORT40_WITH_MD5 */
	{
	1,
	SSL2_TXT_RC4_128_EXPORT40_WITH_MD5,
	SSL2_CK_RC4_128_EXPORT40_WITH_MD5,
	SSL_kRSA|SSL_aRSA|SSL_RC4|SSL_MD5|SSL_EXP40|SSL_SSLV2,
	SSL2_CF_5_BYTE_ENC,
	SSL_ALL_CIPHERS,
	},
/* RC4_128_WITH_MD5 */
	{
	1,
	SSL2_TXT_RC4_128_WITH_MD5,
	SSL2_CK_RC4_128_WITH_MD5,
	SSL_kRSA|SSL_aRSA|SSL_RC4|SSL_MD5|SSL_NOT_EXP|SSL_SSLV2|SSL_MEDIUM,
	0,
	SSL_ALL_CIPHERS,
	},
/* RC2_128_CBC_EXPORT40_WITH_MD5 */
	{
	1,
	SSL2_TXT_RC2_128_CBC_EXPORT40_WITH_MD5,
	SSL2_CK_RC2_128_CBC_EXPORT40_WITH_MD5,
	SSL_kRSA|SSL_aRSA|SSL_RC2|SSL_MD5|SSL_EXP40|SSL_SSLV2,
	SSL2_CF_5_BYTE_ENC,
	SSL_ALL_CIPHERS,
	},
/* RC2_128_CBC_WITH_MD5 */
	{
	1,
	SSL2_TXT_RC2_128_CBC_WITH_MD5,
	SSL2_CK_RC2_128_CBC_WITH_MD5,
	SSL_kRSA|SSL_aRSA|SSL_RC2|SSL_MD5|SSL_NOT_EXP|SSL_SSLV2|SSL_MEDIUM,
	0,
	SSL_ALL_CIPHERS,
	},
/* IDEA_128_CBC_WITH_MD5 */
	{
	1,
	SSL2_TXT_IDEA_128_CBC_WITH_MD5,
	SSL2_CK_IDEA_128_CBC_WITH_MD5,
	SSL_kRSA|SSL_aRSA|SSL_IDEA|SSL_MD5|SSL_NOT_EXP|SSL_SSLV2|SSL_MEDIUM,
	0,
	SSL_ALL_CIPHERS,
	},
/* DES_64_CBC_WITH_MD5 */
	{
	1,
	SSL2_TXT_DES_64_CBC_WITH_MD5,
	SSL2_CK_DES_64_CBC_WITH_MD5,
	SSL_kRSA|SSL_aRSA|SSL_DES|SSL_MD5|SSL_NOT_EXP|SSL_SSLV2|SSL_LOW,
	0,
	SSL_ALL_CIPHERS,
	},
/* DES_192_EDE3_CBC_WITH_MD5 */
	{
	1,
	SSL2_TXT_DES_192_EDE3_CBC_WITH_MD5,
	SSL2_CK_DES_192_EDE3_CBC_WITH_MD5,
	SSL_kRSA|SSL_aRSA|SSL_3DES|SSL_MD5|SSL_NOT_EXP|SSL_SSLV2|SSL_HIGH,
	0,
	SSL_ALL_CIPHERS,
	},
/* RC4_64_WITH_MD5 */
#if 1
	{
	1,
	SSL2_TXT_RC4_64_WITH_MD5,
	SSL2_CK_RC4_64_WITH_MD5,
	SSL_kRSA|SSL_aRSA|SSL_RC4|SSL_MD5|SSL_SSLV2|SSL_LOW,
	SSL2_CF_8_BYTE_ENC,
	SSL_ALL_CIPHERS,
	},
#endif
/* NULL SSLeay (testing) */
#if 0
	{	
	0,
	SSL2_TXT_NULL,
	SSL2_CK_NULL,
	0,
	SSL_ALL_CIPHERS,
	},
#endif

/* end of list :-) */
	};

static SSL_METHOD SSLv2_data= {
	SSL2_VERSION,
	ssl2_new,	/* local */
	ssl2_clear,	/* local */
	ssl2_free,	/* local */
	ssl_undefined_function,
	ssl_undefined_function,
	ssl2_read,
	ssl2_peek,
	ssl2_write,
	ssl2_shutdown,
	ssl_ok,	/* NULL - renegotiate */
	ssl_ok,	/* NULL - check renegotiate */
	ssl2_ctrl,	/* local */
	ssl2_ctx_ctrl,	/* local */
	ssl2_get_cipher_by_char,
	ssl2_put_cipher_by_char,
	ssl2_pending,
	ssl2_num_ciphers,
	ssl2_get_cipher,
	ssl_bad_method,
	ssl2_default_timeout,
	&ssl3_undef_enc_method,
	};

static long ssl2_default_timeout(void)
	{
	return(300);
	}

SSL_METHOD *sslv2_base_method(void)
	{
	return(&SSLv2_data);
	}

int ssl2_num_ciphers(void)
	{
	return(SSL2_NUM_CIPHERS);
	}

SSL_CIPHER *ssl2_get_cipher(unsigned int u)
	{
	if (u < SSL2_NUM_CIPHERS)
		return(&(ssl2_ciphers[SSL2_NUM_CIPHERS-1-u]));
	else
		return(NULL);
	}

int ssl2_pending(SSL *s)
	{
	return(s->s2->ract_data_length);
	}

int ssl2_new(SSL *s)
	{
	SSL2_CTX *s2;

	if ((s2=(SSL2_CTX *)Malloc(sizeof(SSL2_CTX))) == NULL) goto err;
	memset(s2,0,sizeof(SSL2_CTX));

	if ((s2->rbuf=(unsigned char *)Malloc(
		SSL2_MAX_RECORD_LENGTH_2_BYTE_HEADER+2)) == NULL) goto err;
	if ((s2->wbuf=(unsigned char *)Malloc(
		SSL2_MAX_RECORD_LENGTH_2_BYTE_HEADER+2)) == NULL) goto err;
	s->s2=s2;

	ssl2_clear(s);
	return(1);
err:
	if (s2 != NULL)
		{
		if (s2->wbuf != NULL) Free(s2->wbuf);
		if (s2->rbuf != NULL) Free(s2->rbuf);
		Free(s2);
		}
	return(0);
	}

void ssl2_free(SSL *s)
	{
	SSL2_CTX *s2;

	if(s == NULL)
	    return;

	s2=s->s2;
	if (s2->rbuf != NULL) Free(s2->rbuf);
	if (s2->wbuf != NULL) Free(s2->wbuf);
	memset(s2,0,sizeof(SSL2_CTX));
	Free(s2);
	s->s2=NULL;
	}

void ssl2_clear(SSL *s)
	{
	SSL2_CTX *s2;
	unsigned char *rbuf,*wbuf;

	s2=s->s2;

	rbuf=s2->rbuf;
	wbuf=s2->wbuf;

	memset(s2,0,sizeof(SSL2_CTX));

	s2->rbuf=rbuf;
	s2->wbuf=wbuf;
	s2->clear_text=1;
	s->packet=s2->rbuf;
	s->version=SSL2_VERSION;
	s->packet_length=0;
	}

long ssl2_ctrl(SSL *s, int cmd, long larg, char *parg)
	{
	int ret=0;

	switch(cmd)
		{
	case SSL_CTRL_GET_SESSION_REUSED:
		ret=s->hit;
		break;
	default:
		break;
		}
	return(ret);
	}

long ssl2_ctx_ctrl(SSL_CTX *ctx, int cmd, long larg, char *parg)
	{
	return(0);
	}

/* This function needs to check if the ciphers required are actually
 * available */
SSL_CIPHER *ssl2_get_cipher_by_char(const unsigned char *p)
	{
	static int init=1;
	static SSL_CIPHER *sorted[SSL2_NUM_CIPHERS];
	SSL_CIPHER c,*cp= &c,**cpp;
	unsigned long id;
	int i;

	if (init)
		{
		CRYPTO_w_lock(CRYPTO_LOCK_SSL);

		for (i=0; i<SSL2_NUM_CIPHERS; i++)
			sorted[i]= &(ssl2_ciphers[i]);

		qsort(  (char *)sorted,
			SSL2_NUM_CIPHERS,sizeof(SSL_CIPHER *),
			FP_ICC ssl_cipher_ptr_id_cmp);

		CRYPTO_w_unlock(CRYPTO_LOCK_SSL);
		init=0;
		}

	id=0x02000000L|((unsigned long)p[0]<<16L)|
		((unsigned long)p[1]<<8L)|(unsigned long)p[2];
	c.id=id;
	cpp=(SSL_CIPHER **)OBJ_bsearch((char *)&cp,
		(char *)sorted,
		SSL2_NUM_CIPHERS,sizeof(SSL_CIPHER *),
		(int (*)())ssl_cipher_ptr_id_cmp);
	if ((cpp == NULL) || !(*cpp)->valid)
		return(NULL);
	else
		return(*cpp);
	}

int ssl2_put_cipher_by_char(const SSL_CIPHER *c, unsigned char *p)
	{
	long l;

	if (p != NULL)
		{
		l=c->id;
		if ((l & 0xff000000) != 0x02000000) return(0);
		p[0]=((unsigned char)(l>>16L))&0xFF;
		p[1]=((unsigned char)(l>> 8L))&0xFF;
		p[2]=((unsigned char)(l     ))&0xFF;
		}
	return(3);
	}

void ssl2_generate_key_material(SSL *s)
	{
	unsigned int i;
	MD5_CTX ctx;
	unsigned char *km;
	unsigned char c='0';

#ifdef CHARSET_EBCDIC
	c = os_toascii['0']; /* Must be an ASCII '0', not EBCDIC '0',
				see SSLv2 docu */
#endif

	km=s->s2->key_material;
	for (i=0; i<s->s2->key_material_length; i+=MD5_DIGEST_LENGTH)
		{
		MD5_Init(&ctx);

		MD5_Update(&ctx,s->session->master_key,s->session->master_key_length);
		MD5_Update(&ctx,(unsigned char *)&c,1);
		c++;
		MD5_Update(&ctx,s->s2->challenge,s->s2->challenge_length);
		MD5_Update(&ctx,s->s2->conn_id,s->s2->conn_id_length);
		MD5_Final(km,&ctx);
		km+=MD5_DIGEST_LENGTH;
		}
	}

void ssl2_return_error(SSL *s, int err)
	{
	if (!s->error)
		{
		s->error=3;
		s->error_code=err;

		ssl2_write_error(s);
		}
	}


void ssl2_write_error(SSL *s)
	{
	unsigned char buf[3];
	int i,error;

	buf[0]=SSL2_MT_ERROR;
	buf[1]=(s->error_code>>8)&0xff;
	buf[2]=(s->error_code)&0xff;

/*	state=s->rwstate;*/
	error=s->error;
	s->error=0;
	i=ssl2_write(s,&(buf[3-error]),error);
/*	if (i == error) s->rwstate=state; */

	if (i < 0)
		s->error=error;
	else if (i != s->error)
		s->error=error-i;
	/* else
		s->error=0; */
	}

int ssl2_shutdown(SSL *s)
	{
	s->shutdown=(SSL_SENT_SHUTDOWN|SSL_RECEIVED_SHUTDOWN);
	return(1);
	}
#endif
