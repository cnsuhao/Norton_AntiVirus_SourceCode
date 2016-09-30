/* crypto/pkcs7/pkcs7err.c */
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
 *    openssl-core@OpenSSL.org.
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

/* NOTE: this file was auto generated by the mkerr.pl script: any changes
 * made to it will be overwritten when the script next updates this file.
 */

#include <stdio.h>
#include <openssl/err.h>
#include <openssl/pkcs7.h>

/* BEGIN ERROR CODES */
#ifndef NO_ERR
static ERR_STRING_DATA PKCS7_str_functs[]=
	{
{ERR_PACK(0,PKCS7_F_PKCS7_ADD_CERTIFICATE,0),	"PKCS7_add_certificate"},
{ERR_PACK(0,PKCS7_F_PKCS7_ADD_CRL,0),	"PKCS7_add_crl"},
{ERR_PACK(0,PKCS7_F_PKCS7_ADD_RECIPIENT_INFO,0),	"PKCS7_add_recipient_info"},
{ERR_PACK(0,PKCS7_F_PKCS7_ADD_SIGNER,0),	"PKCS7_add_signer"},
{ERR_PACK(0,PKCS7_F_PKCS7_CTRL,0),	"PKCS7_ctrl"},
{ERR_PACK(0,PKCS7_F_PKCS7_DATADECODE,0),	"PKCS7_dataDecode"},
{ERR_PACK(0,PKCS7_F_PKCS7_DATAINIT,0),	"PKCS7_dataInit"},
{ERR_PACK(0,PKCS7_F_PKCS7_DATASIGN,0),	"PKCS7_DATASIGN"},
{ERR_PACK(0,PKCS7_F_PKCS7_DATAVERIFY,0),	"PKCS7_dataVerify"},
{ERR_PACK(0,PKCS7_F_PKCS7_SET_CIPHER,0),	"PKCS7_set_cipher"},
{ERR_PACK(0,PKCS7_F_PKCS7_SET_CONTENT,0),	"PKCS7_set_content"},
{ERR_PACK(0,PKCS7_F_PKCS7_SET_TYPE,0),	"PKCS7_set_type"},
{ERR_PACK(0,PKCS7_F_PKCS7_SIGNATUREVERIFY,0),	"PKCS7_signatureVerify"},
{0,NULL}
	};

static ERR_STRING_DATA PKCS7_str_reasons[]=
	{
{PKCS7_R_CIPHER_NOT_INITIALIZED          ,"cipher not initialized"},
{PKCS7_R_DECRYPTED_KEY_IS_WRONG_LENGTH   ,"decrypted key is wrong length"},
{PKCS7_R_DIGEST_FAILURE                  ,"digest failure"},
{PKCS7_R_INTERNAL_ERROR                  ,"internal error"},
{PKCS7_R_MISSING_CERIPEND_INFO           ,"missing ceripend info"},
{PKCS7_R_NO_RECIPIENT_MATCHES_CERTIFICATE,"no recipient matches certificate"},
{PKCS7_R_OPERATION_NOT_SUPPORTED_ON_THIS_TYPE,"operation not supported on this type"},
{PKCS7_R_SIGNATURE_FAILURE               ,"signature failure"},
{PKCS7_R_UNABLE_TO_FIND_CERTIFICATE      ,"unable to find certificate"},
{PKCS7_R_UNABLE_TO_FIND_MEM_BIO          ,"unable to find mem bio"},
{PKCS7_R_UNABLE_TO_FIND_MESSAGE_DIGEST   ,"unable to find message digest"},
{PKCS7_R_UNKNOWN_DIGEST_TYPE             ,"unknown digest type"},
{PKCS7_R_UNKNOWN_OPERATION               ,"unknown operation"},
{PKCS7_R_UNSUPPORTED_CIPHER_TYPE         ,"unsupported cipher type"},
{PKCS7_R_UNSUPPORTED_CONTENT_TYPE        ,"unsupported content type"},
{PKCS7_R_WRONG_CONTENT_TYPE              ,"wrong content type"},
{PKCS7_R_WRONG_PKCS7_TYPE                ,"wrong pkcs7 type"},
{0,NULL}
	};

#endif

void ERR_load_PKCS7_strings(void)
	{
	static int init=1;

	if (init)
		{
		init=0;
#ifndef NO_ERR
		ERR_load_strings(ERR_LIB_PKCS7,PKCS7_str_functs);
		ERR_load_strings(ERR_LIB_PKCS7,PKCS7_str_reasons);
#endif

		}
	}
