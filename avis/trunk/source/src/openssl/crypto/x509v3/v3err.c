/* crypto/x509v3/v3err.c */
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
#include <openssl/x509v3.h>

/* BEGIN ERROR CODES */
#ifndef NO_ERR
static ERR_STRING_DATA X509V3_str_functs[]=
	{
{ERR_PACK(0,X509V3_F_COPY_EMAIL,0),	"COPY_EMAIL"},
{ERR_PACK(0,X509V3_F_COPY_ISSUER,0),	"COPY_ISSUER"},
{ERR_PACK(0,X509V3_F_DO_EXT_CONF,0),	"DO_EXT_CONF"},
{ERR_PACK(0,X509V3_F_DO_EXT_I2D,0),	"DO_EXT_I2D"},
{ERR_PACK(0,X509V3_F_HEX_TO_STRING,0),	"hex_to_string"},
{ERR_PACK(0,X509V3_F_I2S_ASN1_ENUMERATED,0),	"i2s_ASN1_ENUMERATED"},
{ERR_PACK(0,X509V3_F_I2S_ASN1_INTEGER,0),	"i2s_ASN1_INTEGER"},
{ERR_PACK(0,X509V3_F_NOTICE_SECTION,0),	"NOTICE_SECTION"},
{ERR_PACK(0,X509V3_F_NREF_NOS,0),	"NREF_NOS"},
{ERR_PACK(0,X509V3_F_POLICY_SECTION,0),	"POLICY_SECTION"},
{ERR_PACK(0,X509V3_F_R2I_CERTPOL,0),	"R2I_CERTPOL"},
{ERR_PACK(0,X509V3_F_S2I_ASN1_IA5STRING,0),	"S2I_ASN1_IA5STRING"},
{ERR_PACK(0,X509V3_F_S2I_ASN1_INTEGER,0),	"s2i_ASN1_INTEGER"},
{ERR_PACK(0,X509V3_F_S2I_ASN1_OCTET_STRING,0),	"s2i_ASN1_OCTET_STRING"},
{ERR_PACK(0,X509V3_F_S2I_ASN1_SKEY_ID,0),	"S2I_ASN1_SKEY_ID"},
{ERR_PACK(0,X509V3_F_S2I_S2I_SKEY_ID,0),	"S2I_S2I_SKEY_ID"},
{ERR_PACK(0,X509V3_F_STRING_TO_HEX,0),	"string_to_hex"},
{ERR_PACK(0,X509V3_F_SXNET_ADD_ASC,0),	"SXNET_ADD_ASC"},
{ERR_PACK(0,X509V3_F_SXNET_ADD_ID_INTEGER,0),	"SXNET_add_id_INTEGER"},
{ERR_PACK(0,X509V3_F_SXNET_ADD_ID_ULONG,0),	"SXNET_add_id_ulong"},
{ERR_PACK(0,X509V3_F_SXNET_GET_ID_ASC,0),	"SXNET_get_id_asc"},
{ERR_PACK(0,X509V3_F_SXNET_GET_ID_ULONG,0),	"SXNET_get_id_ulong"},
{ERR_PACK(0,X509V3_F_V2I_ASN1_BIT_STRING,0),	"V2I_ASN1_BIT_STRING"},
{ERR_PACK(0,X509V3_F_V2I_AUTHORITY_KEYID,0),	"V2I_AUTHORITY_KEYID"},
{ERR_PACK(0,X509V3_F_V2I_BASIC_CONSTRAINTS,0),	"V2I_BASIC_CONSTRAINTS"},
{ERR_PACK(0,X509V3_F_V2I_CRLD,0),	"V2I_CRLD"},
{ERR_PACK(0,X509V3_F_V2I_EXT_KU,0),	"V2I_EXT_KU"},
{ERR_PACK(0,X509V3_F_V2I_GENERAL_NAME,0),	"v2i_GENERAL_NAME"},
{ERR_PACK(0,X509V3_F_V2I_GENERAL_NAMES,0),	"v2i_GENERAL_NAMES"},
{ERR_PACK(0,X509V3_F_V3_GENERIC_EXTENSION,0),	"V3_GENERIC_EXTENSION"},
{ERR_PACK(0,X509V3_F_X509V3_ADD_VALUE,0),	"X509V3_add_value"},
{ERR_PACK(0,X509V3_F_X509V3_EXT_ADD,0),	"X509V3_EXT_add"},
{ERR_PACK(0,X509V3_F_X509V3_EXT_ADD_ALIAS,0),	"X509V3_EXT_add_alias"},
{ERR_PACK(0,X509V3_F_X509V3_EXT_CONF,0),	"X509V3_EXT_conf"},
{ERR_PACK(0,X509V3_F_X509V3_EXT_I2D,0),	"X509V3_EXT_i2d"},
{ERR_PACK(0,X509V3_F_X509V3_GET_VALUE_BOOL,0),	"X509V3_get_value_bool"},
{ERR_PACK(0,X509V3_F_X509V3_PARSE_LIST,0),	"X509V3_parse_list"},
{0,NULL}
	};

static ERR_STRING_DATA X509V3_str_reasons[]=
	{
{X509V3_R_BAD_IP_ADDRESS                 ,"bad ip address"},
{X509V3_R_BAD_OBJECT                     ,"bad object"},
{X509V3_R_BN_DEC2BN_ERROR                ,"bn dec2bn error"},
{X509V3_R_BN_TO_ASN1_INTEGER_ERROR       ,"bn to asn1 integer error"},
{X509V3_R_DUPLICATE_ZONE_ID              ,"duplicate zone id"},
{X509V3_R_ERROR_CONVERTING_ZONE          ,"error converting zone"},
{X509V3_R_ERROR_IN_EXTENSION             ,"error in extension"},
{X509V3_R_EXPECTED_A_SECTION_NAME        ,"expected a section name"},
{X509V3_R_EXTENSION_NAME_ERROR           ,"extension name error"},
{X509V3_R_EXTENSION_NOT_FOUND            ,"extension not found"},
{X509V3_R_EXTENSION_SETTING_NOT_SUPPORTED,"extension setting not supported"},
{X509V3_R_EXTENSION_VALUE_ERROR          ,"extension value error"},
{X509V3_R_ILLEGAL_HEX_DIGIT              ,"illegal hex digit"},
{X509V3_R_INVALID_BOOLEAN_STRING         ,"invalid boolean string"},
{X509V3_R_INVALID_EXTENSION_STRING       ,"invalid extension string"},
{X509V3_R_INVALID_NAME                   ,"invalid name"},
{X509V3_R_INVALID_NULL_ARGUMENT          ,"invalid null argument"},
{X509V3_R_INVALID_NULL_NAME              ,"invalid null name"},
{X509V3_R_INVALID_NULL_VALUE             ,"invalid null value"},
{X509V3_R_INVALID_NUMBER                 ,"invalid number"},
{X509V3_R_INVALID_NUMBERS                ,"invalid numbers"},
{X509V3_R_INVALID_OBJECT_IDENTIFIER      ,"invalid object identifier"},
{X509V3_R_INVALID_OPTION                 ,"invalid option"},
{X509V3_R_INVALID_POLICY_IDENTIFIER      ,"invalid policy identifier"},
{X509V3_R_INVALID_SECTION                ,"invalid section"},
{X509V3_R_ISSUER_DECODE_ERROR            ,"issuer decode error"},
{X509V3_R_MISSING_VALUE                  ,"missing value"},
{X509V3_R_NEED_ORGANIZATION_AND_NUMBERS  ,"need organization and numbers"},
{X509V3_R_NO_CONFIG_DATABASE             ,"no config database"},
{X509V3_R_NO_ISSUER_CERTIFICATE          ,"no issuer certificate"},
{X509V3_R_NO_ISSUER_DETAILS              ,"no issuer details"},
{X509V3_R_NO_POLICY_IDENTIFIER           ,"no policy identifier"},
{X509V3_R_NO_PUBLIC_KEY                  ,"no public key"},
{X509V3_R_NO_SUBJECT_DETAILS             ,"no subject details"},
{X509V3_R_ODD_NUMBER_OF_DIGITS           ,"odd number of digits"},
{X509V3_R_UNABLE_TO_GET_ISSUER_DETAILS   ,"unable to get issuer details"},
{X509V3_R_UNABLE_TO_GET_ISSUER_KEYID     ,"unable to get issuer keyid"},
{X509V3_R_UNKNOWN_BIT_STRING_ARGUMENT    ,"unknown bit string argument"},
{X509V3_R_UNKNOWN_EXTENSION              ,"unknown extension"},
{X509V3_R_UNKNOWN_EXTENSION_NAME         ,"unknown extension name"},
{X509V3_R_UNKNOWN_OPTION                 ,"unknown option"},
{X509V3_R_UNSUPPORTED_OPTION             ,"unsupported option"},
{X509V3_R_USER_TOO_LONG                  ,"user too long"},
{0,NULL}
	};

#endif

void ERR_load_X509V3_strings(void)
	{
	static int init=1;

	if (init)
		{
		init=0;
#ifndef NO_ERR
		ERR_load_strings(ERR_LIB_X509V3,X509V3_str_functs);
		ERR_load_strings(ERR_LIB_X509V3,X509V3_str_reasons);
#endif

		}
	}
