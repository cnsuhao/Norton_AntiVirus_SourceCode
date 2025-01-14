/* asn_pack.c */
/* Written by Dr Stephen N Henson (shenson@bigfoot.com) for the OpenSSL
 * project 1999.
 */
/* ====================================================================
 * Copyright (c) 1999 The OpenSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"
 *
 * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    licensing@OpenSSL.org.
 *
 * 5. Products derived from this software may not be called "OpenSSL"
 *    nor may "OpenSSL" appear in their names without prior written
 *    permission of the OpenSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 * This product includes cryptographic software written by Eric Young
 * (eay@cryptsoft.com).  This product includes software written by Tim
 * Hudson (tjh@cryptsoft.com).
 *
 */

#include <stdio.h>
#include "cryptlib.h"
#include <openssl/asn1.h>

/* ASN1 packing and unpacking functions */

/* Turn an ASN1 encoded SEQUENCE OF into a STACK of structures */

STACK *ASN1_seq_unpack(unsigned char *buf, int len, char *(*d2i)(),
	     void (*free_func)())
{
    STACK *sk;
    unsigned char *pbuf;
    pbuf =  buf;
    if (!(sk = d2i_ASN1_SET(NULL, &pbuf, len, d2i, free_func,
					V_ASN1_SEQUENCE, V_ASN1_UNIVERSAL)))
		 ASN1err(ASN1_F_ASN1_SEQ_UNPACK,ASN1_R_DECODE_ERROR);
    return sk;
}

/* Turn a STACK structures into an ASN1 encoded SEQUENCE OF structure in a
 * Malloc'ed buffer
 */

unsigned char *ASN1_seq_pack(STACK *safes, int (*i2d)(), unsigned char **buf,
	     int *len)
{
	int safelen;
	unsigned char *safe, *p;
	if (!(safelen = i2d_ASN1_SET(safes, NULL, i2d, V_ASN1_SEQUENCE,
					      V_ASN1_UNIVERSAL, IS_SEQUENCE))) {
		ASN1err(ASN1_F_ASN1_SEQ_PACK,ASN1_R_ENCODE_ERROR);
		return NULL;
	}
	if (!(safe = Malloc (safelen))) {
		ASN1err(ASN1_F_ASN1_SEQ_PACK,ERR_R_MALLOC_FAILURE);
		return NULL;
	}
	p = safe;
	i2d_ASN1_SET(safes, &p, i2d, V_ASN1_SEQUENCE, V_ASN1_UNIVERSAL,
								 IS_SEQUENCE);
	if (len) *len = safelen;
	if (buf) *buf = safe;
	return safe;
}

/* Extract an ASN1 object from an ASN1_STRING */

void *ASN1_unpack_string (ASN1_STRING *oct, char *(*d2i)())
{
	unsigned char *p;
	char *ret;

	p = oct->data;
	if(!(ret = d2i(NULL, &p, oct->length)))
		ASN1err(ASN1_F_ASN1_UNPACK_STRING,ASN1_R_DECODE_ERROR);
	return ret;
}

/* Pack an ASN1 object into an ASN1_STRING */

ASN1_STRING *ASN1_pack_string (void *obj, int (*i2d)(), ASN1_STRING **oct)
{
	unsigned char *p;
	ASN1_STRING *octmp;

	if (!oct || !*oct) {
		if (!(octmp = ASN1_STRING_new ())) {
			ASN1err(ASN1_F_ASN1_PACK_STRING,ERR_R_MALLOC_FAILURE);
			return NULL;
		}
		if (oct) *oct = octmp;
	} else octmp = *oct;
		
	if (!(octmp->length = i2d(obj, NULL))) {
		ASN1err(ASN1_F_ASN1_PACK_STRING,ASN1_R_ENCODE_ERROR);
		return NULL;
	}
	if (!(p = Malloc (octmp->length))) {
		ASN1err(ASN1_F_ASN1_PACK_STRING,ERR_R_MALLOC_FAILURE);
		return NULL;
	}
	octmp->data = p;
	i2d (obj, &p);
	return octmp;
}

