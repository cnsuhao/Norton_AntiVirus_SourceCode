/* crypto/x509/x509_txt.c */
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
#include <time.h>
#include <errno.h>
#include <sys/types.h>

#include "cryptlib.h"
#include <openssl/lhash.h>
#include <openssl/buffer.h>
#include <openssl/evp.h>
#include <openssl/asn1.h>
#include <openssl/x509.h>
#include <openssl/objects.h>

const char *X509_verify_cert_error_string(long n)
	{
	static char buf[100];

	switch ((int)n)
		{
	case X509_V_OK:
		return("ok");
	case X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT:
		return("unable to get issuer certificate");
	case X509_V_ERR_UNABLE_TO_GET_CRL:
		return("unable to get certificate CRL");
	case X509_V_ERR_UNABLE_TO_DECRYPT_CERT_SIGNATURE:
		return("unable to decrypt certificate's signature");
	case X509_V_ERR_UNABLE_TO_DECRYPT_CRL_SIGNATURE:
		return("unable to decrypt CRL's's signature");
	case X509_V_ERR_UNABLE_TO_DECODE_ISSUER_PUBLIC_KEY:
		return("unable to decode issuer public key");
	case X509_V_ERR_CERT_SIGNATURE_FAILURE:
		return("certificate signature failure");
	case X509_V_ERR_CRL_SIGNATURE_FAILURE:
		return("CRL signature failure");
	case X509_V_ERR_CERT_NOT_YET_VALID:
		return("certificate is not yet valid");
	case X509_V_ERR_CRL_NOT_YET_VALID:
		return("CRL is not yet valid");
	case X509_V_ERR_CERT_HAS_EXPIRED:
		return("Certificate has expired");
	case X509_V_ERR_CRL_HAS_EXPIRED:
		return("CRL has expired");
	case X509_V_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD:
		return("format error in certificate's notBefore field");
	case X509_V_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD:
		return("format error in certificate's notAfter field");
	case X509_V_ERR_ERROR_IN_CRL_LAST_UPDATE_FIELD:
		return("format error in CRL's lastUpdate field");
	case X509_V_ERR_ERROR_IN_CRL_NEXT_UPDATE_FIELD:
		return("format error in CRL's nextUpdate field");
	case X509_V_ERR_OUT_OF_MEM:
		return("out of memory");
	case X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT:
		return("self signed certificate");
	case X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN:
		return("self signed certificate in certificate chain");
	case X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY:
		return("unable to get local issuer certificate");
	case X509_V_ERR_UNABLE_TO_VERIFY_LEAF_SIGNATURE:
		return("unable to verify the first certificate");
	case X509_V_ERR_CERT_CHAIN_TOO_LONG:
		return("certificate chain too long");
	case X509_V_ERR_CERT_REVOKED:
		return("certificate revoked");
	case X509_V_ERR_APPLICATION_VERIFICATION:
		return("application verification failure");
	default:
		sprintf(buf,"error number %ld",n);
		return(buf);
		}
	}


