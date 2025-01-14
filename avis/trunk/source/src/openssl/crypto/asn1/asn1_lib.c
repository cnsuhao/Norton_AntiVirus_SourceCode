/* crypto/asn1/asn1_lib.c */
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
#include "cryptlib.h"
#include <openssl/asn1.h>
#include <openssl/asn1_mac.h>

static int asn1_get_length(unsigned char **pp,int *inf,long *rl,int max);
static void asn1_put_length(unsigned char **pp, int length);
const char *ASN1_version="ASN.1" OPENSSL_VERSION_PTEXT;

int ASN1_check_infinite_end(unsigned char **p, long len)
	{
	/* If there is 0 or 1 byte left, the length check should pick
	 * things up */
	if (len <= 0)
		return(1);
	else if ((len >= 2) && ((*p)[0] == 0) && ((*p)[1] == 0))
		{
		(*p)+=2;
		return(1);
		}
	return(0);
	}


int ASN1_get_object(unsigned char **pp, long *plength, int *ptag, int *pclass,
	     long omax)
	{
	int i,ret;
	long l;
	unsigned char *p= *pp;
	int tag,xclass,inf;
	long max=omax;

	if (!max) goto err;
	ret=(*p&V_ASN1_CONSTRUCTED);
	xclass=(*p&V_ASN1_PRIVATE);
	i= *p&V_ASN1_PRIMITIVE_TAG;
	if (i == V_ASN1_PRIMITIVE_TAG)
		{		/* high-tag */
		p++;
		if (--max == 0) goto err;
		l=0;
		while (*p&0x80)
			{
			l<<=7L;
			l|= *(p++)&0x7f;
			if (--max == 0) goto err;
			}
		l<<=7L;
		l|= *(p++)&0x7f;
		tag=(int)l;
		}
	else
		{ 
		tag=i;
		p++;
		if (--max == 0) goto err;
		}
	*ptag=tag;
	*pclass=xclass;
	if (!asn1_get_length(&p,&inf,plength,(int)max)) goto err;

#if 0
	fprintf(stderr,"p=%d + *plength=%ld > omax=%ld + *pp=%d  (%d > %d)\n", 
		(int)p,*plength,omax,(int)*pp,(int)(p+ *plength),
		(int)(omax+ *pp));

#endif
#if 0
	if ((p+ *plength) > (omax+ *pp))
		{
		ASN1err(ASN1_F_ASN1_GET_OBJECT,ASN1_R_TOO_LONG);
		/* Set this so that even if things are not long enough
		 * the values are set correctly */
		ret|=0x80;
		}
#endif
	*pp=p;
	return(ret|inf);
err:
	ASN1err(ASN1_F_ASN1_GET_OBJECT,ASN1_R_HEADER_TOO_LONG);
	return(0x80);
	}

static int asn1_get_length(unsigned char **pp, int *inf, long *rl, int max)
	{
	unsigned char *p= *pp;
	long ret=0;
	int i;

	if (max-- < 1) return(0);
	if (*p == 0x80)
		{
		*inf=1;
		ret=0;
		p++;
		}
	else
		{
		*inf=0;
		i= *p&0x7f;
		if (*(p++) & 0x80)
			{
			if (max-- == 0) return(0);
			while (i-- > 0)
				{
				ret<<=8L;
				ret|= *(p++);
				if (max-- == 0) return(0);
				}
			}
		else
			ret=i;
		}
	*pp=p;
	*rl=ret;
	return(1);
	}

/* class 0 is constructed
 * constructed == 2 for indefinitle length constructed */
void ASN1_put_object(unsigned char **pp, int constructed, int length, int tag,
	     int xclass)
	{
	unsigned char *p= *pp;
	int i;

	i=(constructed)?V_ASN1_CONSTRUCTED:0;
	i|=(xclass&V_ASN1_PRIVATE);
	if (tag < 31)
		*(p++)=i|(tag&V_ASN1_PRIMITIVE_TAG);
	else
		{
		*(p++)=i|V_ASN1_PRIMITIVE_TAG;
		while (tag > 0x7f)
			{
			*(p++)=(tag&0x7f)|0x80;
			tag>>=7;
			}
		*(p++)=(tag&0x7f);
		}
	if ((constructed == 2) && (length == 0))
		*(p++)=0x80; /* der_put_length would output 0 instead */
	else
		asn1_put_length(&p,length);
	*pp=p;
	}

static void asn1_put_length(unsigned char **pp, int length)
	{
	unsigned char *p= *pp;
	int i,l;
	if (length <= 127)
		*(p++)=(unsigned char)length;
	else
		{
		l=length;
		for (i=0; l > 0; i++)
			l>>=8;
		*(p++)=i|0x80;
		l=i;
		while (i-- > 0)
			{
			p[i]=length&0xff;
			length>>=8;
			}
		p+=l;
		}
	*pp=p;
	}

int ASN1_object_size(int constructed, int length, int tag)
	{
	int ret;

	ret=length;
	ret++;
	if (tag >= 31)
		{
		while (tag > 0)
			{
			tag>>=7;
			ret++;
			}
		}
	if ((length == 0) && (constructed == 2))
		ret+=2;
	ret++;
	if (length > 127)
		{
		while (length > 0)
			{
			length>>=8;
			ret++;
			}
		}
	return(ret);
	}

int asn1_Finish(ASN1_CTX *c)
	{
	if ((c->inf == (1|V_ASN1_CONSTRUCTED)) && (!c->eos))
		{
		if (!ASN1_check_infinite_end(&c->p,c->slen))
			{
			c->error=ERR_R_MISSING_ASN1_EOS;
			return(0);
			}
		}
	if (	((c->slen != 0) && !(c->inf & 1)) ||
		((c->slen < 0) && (c->inf & 1)))
		{
		c->error=ERR_R_ASN1_LENGTH_MISMATCH;
		return(0);
		}
	return(1);
	}

int asn1_GetSequence(ASN1_CTX *c, long *length)
	{
	unsigned char *q;

	q=c->p;
	c->inf=ASN1_get_object(&(c->p),&(c->slen),&(c->tag),&(c->xclass),
		*length);
	if (c->inf & 0x80)
		{
		c->error=ERR_R_BAD_GET_ASN1_OBJECT_CALL;
		return(0);
		}
	if (c->tag != V_ASN1_SEQUENCE)
		{
		c->error=ERR_R_EXPECTING_AN_ASN1_SEQUENCE;
		return(0);
		}
	(*length)-=(c->p-q);
	if (c->max && (*length < 0))
		{
		c->error=ERR_R_ASN1_LENGTH_MISMATCH;
		return(0);
		}
	if (c->inf == (1|V_ASN1_CONSTRUCTED))
		c->slen= *length+ *(c->pp)-c->p;
	c->eos=0;
	return(1);
	}

ASN1_STRING *ASN1_STRING_dup(ASN1_STRING *str)
	{
	ASN1_STRING *ret;

	if (str == NULL) return(NULL);
	if ((ret=ASN1_STRING_type_new(str->type)) == NULL)
		return(NULL);
	if (!ASN1_STRING_set(ret,str->data,str->length))
		{
		ASN1_STRING_free(ret);
		return(NULL);
		}
	ret->flags = str->flags;
	return(ret);
	}

int ASN1_STRING_set(ASN1_STRING *str, const void *_data, int len)
	{
	unsigned char *c;
	const char *data=_data;

	if (len < 0)
		{
		if (data == NULL)
			return(0);
		else
			len=strlen(data);
		}
	if ((str->length < len) || (str->data == NULL))
		{
		c=str->data;
		if (c == NULL)
			str->data=Malloc(len+1);
		else
			str->data=Realloc(c,len+1);

		if (str->data == NULL)
			{
			str->data=c;
			return(0);
			}
		}
	str->length=len;
	if (data != NULL)
		{
		memcpy(str->data,data,len);
		/* an alowance for strings :-) */
		str->data[len]='\0';
		}
	return(1);
	}

ASN1_STRING *ASN1_STRING_new(void)
	{
	return(ASN1_STRING_type_new(V_ASN1_OCTET_STRING));
	}


ASN1_STRING *ASN1_STRING_type_new(int type)
	{
	ASN1_STRING *ret;

	ret=(ASN1_STRING *)Malloc(sizeof(ASN1_STRING));
	if (ret == NULL)
		{
		ASN1err(ASN1_F_ASN1_STRING_TYPE_NEW,ERR_R_MALLOC_FAILURE);
		return(NULL);
		}
	ret->length=0;
	ret->type=type;
	ret->data=NULL;
	ret->flags=0;
	return(ret);
	}

void ASN1_STRING_free(ASN1_STRING *a)
	{
	if (a == NULL) return;
	if (a->data != NULL) Free((char *)a->data);
	Free((char *)a);
	}

int ASN1_STRING_cmp(ASN1_STRING *a, ASN1_STRING *b)
	{
	int i;

	i=(a->length-b->length);
	if (i == 0)
		{
		i=memcmp(a->data,b->data,a->length);
		if (i == 0)
			return(a->type-b->type);
		else
			return(i);
		}
	else
		return(i);
	}

void asn1_add_error(unsigned char *address, int offset)
	{
	char buf1[16],buf2[16];

	sprintf(buf1,"%lu",(unsigned long)address);
	sprintf(buf2,"%d",offset);
	ERR_add_error_data(4,"address=",buf1," offset=",buf2);
	}

