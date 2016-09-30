// DecDefs.h : Decomposer definitions
// PROPRIETARY/CONFIDENTIAL. Use of this product is subject to license terms.
// Copyright 2001, 2005 by Symantec Corporation.  All rights reserved.

#ifndef _DECDEFS_H_
#define _DECDEFS_H_

/////////////////////////////////////////////////////////////////////////////
// Global Decomposer options (DEC_OPTION_xxx option IDs)

#define DEC_OPTION_FIRST						1000
#define DEC_OPTION_TRUNCATE_TEMP_FILES			1000
#define DEC_OPTION_ENFORCE_CRC					1001
#define DEC_OPTION_EXTRACT_RTFHTML				1002
#define DEC_OPTION_EXTRACT_OLE10NATIVE_ONLY		1003
#define DEC_OPTION_NONMIMETHRESHOLD				1006
#define DEC_OPTION_ENABLE_MIME_ENGINE			1011
#define DEC_OPTION_ENABLE_UUE_ENGINE			1012
#define DEC_OPTION_ENABLE_BINHEX_ENGINE			1013
#define DEC_OPTION_LOG_WARNINGS					1014
#define DEC_OPTION_MAX_TEXT_SCAN_BYTES			1015
#define DEC_OPTION_EVENTSINK_VERSION			1016
#define DEC_OPTION_MIME_FUZZY_MAIN_HEADER		1017
#define DEC_OPTION_ENHANCED_TEXT_ID				1018
#define DEC_OPTION_TRANSLATE_NULL				1019
#define DEC_OPTION_NONHQXTHRESHOLD				1020
#define DEC_OPTION_NONUUETHRESHOLD_BYTES		1021
#define DEC_OPTION_MIN_MIME_SCAN_BYTES			1022
//#define DEC_OPTION_TYPE_IDENTIFICATION		####
#define DEC_OPTION_ENABLE_MBOX_ENGINE			1023
#define DEC_OPTION_MIME_IDENTIFICATION_STRENGTH	1024
#define DEC_OPTION_USE_OLE10NATIVE_CHILD_NAME	1025
#define DEC_OPTION_EVENTSINK_TRACE				1026
#define DEC_OPTION_LAST							1026
#define DEC_OPTION_COUNT  (DEC_OPTION_LAST - DEC_OPTION_FIRST + 1)

// The RTF and HTTP engines will be added to the Dec2Text engine later...
//#define DEC_OPTION_ENABLE_RTF_ENGINE        10xx
//#define DEC_OPTION_ENABLE_HTTP_ENGINE       10xx


// Bit-flags for text engine options (set via DEC_OPTION_ENHANCED_TEXT_ID).
#define TEXT_OPTION_NONE							0x00000000
#define TEXT_OPTION_PROCESS_MULTIPLE_ID				0x00000001
#define TEXT_OPTION_NO_TEXT_FORMAT_FILTER			0x00000002
#define TEXT_OPTION_LOOSE_MIME_HEADER_ID			0x00000004
#define TEXT_OPTION_ABORT_ON_BINARY					0x00000008
#define TEXT_OPTION_IGNORE_MIME_PLAIN_TEXT_BODIES	0x00000010
#define TEXT_OPTION_ALL								0xFFFFFFFF


// Bit-flags for options associated with DEC_OPTION_EVENTSINK_TRACE
#define TRACE_OPTION_NO_OBJECT_OUTPUT					0x00000000
#define TRACE_OPTION_LEVEL1_OBJECT_OUTPUT				0x00000001
#define TRACE_OPTION_LEVEL2_OBJECT_OUTPUT				0x00000002
#define TRACE_OPTION_LEVEL3_OBJECT_OUTPUT				0x00000003
#define TRACE_OPTION_LINE_SEPARATOR_CRLF				0x00000004
#define TRACE_OPTION_DISABLE_ENTERING_CALLBACK			0x00000008
#define TRACE_OPTION_DISABLE_LEAVING_CALLBACK			0x00000010
#define TRACE_OPTION_DISABLE_DUMP_OPTIONS				0x00000020
#define TRACE_OPTION_DISABLE_ONOBJECTBEGIN				0x00000040
#define TRACE_OPTION_DISABLE_ONOBJECTEND				0x00000080
#define TRACE_OPTION_DISABLE_ONDISKFILENEEDED			0x00000100
#define TRACE_OPTION_DISABLE_ONOBJECTNOTIDENTIFIED		0x00000200
#define TRACE_OPTION_DISABLE_ONCONTAINERIDENTIFIED		0x00000400
#define TRACE_OPTION_DISABLE_ONCONTAINEREND				0x00000800
#define TRACE_OPTION_DISABLE_ONBUSY						0x00001000
#define TRACE_OPTION_DISABLE_ONENGINEERROR				0x00002000
#define TRACE_OPTION_DISABLE_ONCHILDFOUND				0x00004000
#define TRACE_OPTION_DISABLE_ONCHILDBAD					0x00008000
#define TRACE_OPTION_DISABLE_ONKEYNEEDED				0x00010000

// Define the maximum supported file size
#define MAX_FILE_SIZE 2000000000

/////////////////////////////////////////////////////////////////////////////
// Event sink interface versioning information - to be used with 
// DEC_OPTION_EVENTSINK_VERSION.

#define EVENT_SINK_VERSION_1				1
#define EVENT_SINK_VERSION_2				2


/////////////////////////////////////////////////////////////////////////////
// Standard Property Names - Available to clients

#define DEC_PROPERTY_EXE_TYPE		"_EXETYPE"		// Type of EXE compressor used
#define DEC_PROPERTY_EXE_VERSION	"_EXEVERSION"   // Version of EXE compressor used
#define DEC_PROPERTY_EXE_STRING		"_EXESTRING"	// String of version of EXE compressor used

//
// Possible values for the GetNameType() API
//
enum DecNameType
{
   DEC_NAMETYPE_UNKNOWN	=	 0,
   DEC_NAMETYPE_INTERNAL =	 1,		// Native character set
   DEC_NAMETYPE_EXTERNAL =	 2			// Not native (typically ASCII)
};



/////////////////////////////////////////////////////////////////////////////
// DEC_ATTRTYPE_xxx Codes

enum DEC_ATTRTYPE_VALUES
{
	DEC_ATTRTYPE_DOS,					// DOS-style attributes (e.g. system, hidden, read-only)
	DEC_ATTRTYPE_UNIX					// Unix-style chmod attributes
};

/////////////////////////////////////////////////////////////////////////////
// DEC_ITEMTYPE_xxx Codes

enum DEC_ITEMTYPE_VALUES
{
	DEC_ITEMTYPE_NORMAL,				// Normal item object
	DEC_ITEMTYPE_MIME_BODY,				// MIME message body part
	DEC_ITEMTYPE_MIME_DATE,				// Special MIME Date: field (This Item Type is no longer used as of release 12g (July 2004))
	DEC_ITEMTYPE_MIME_HEADERS			// MIME Headers
};

/////////////////////////////////////////////////////////////////////////////
// DEC_TYPE_xxx Codes

enum DecTypes
{
	// This enumeration corresponds to the config file engine ids. We leave old ids
	// in place so that we do not have to change the engine ids in the config file
	// over time.

	DEC_TYPE_UNKNOWN = 0,		// 0
	DEC_TYPE_AMG,				// 1
	DEC_TYPE_ARC,				// 2
	DEC_TYPE_ARJ,				// 3
	DEC_TYPE_CAB,				// 4
	DEC_TYPE_EXE,				// 5  (This engine is no longer supported as of Release 12 (April 2004)) 
	DEC_TYPE_GHO,				// 6  (This engine is no longer supported as of Release 12 (April 2004))
	DEC_TYPE_GZIP,				// 7
	DEC_TYPE_HQX,				// 8  (This engine is no longer supported as of Release 12 (April 2004)) - definition also used in text engine
	DEC_TYPE_HTTP,				// 9  (This engine is no longer supported as of Release 12 (April 2004))
	DEC_TYPE_ID,				// 10
	DEC_TYPE_JAR,				// 11
	DEC_TYPE_LHA,				// 12
	DEC_TYPE_LN,				// 13
	DEC_TYPE_LZ,				// 14
	DEC_TYPE_MIME,				// 15 (This engine is no longer supported as of Release 12 (April 2004)) - definition also used in text engine
	DEC_TYPE_MSG,				// 16 (This engine is no longer supported as of Release 11 (July 2003))
	DEC_TYPE_OLE1,				// 17
	DEC_TYPE_OLESS,				// 18
	DEC_TYPE_RAR,				// 19
	DEC_TYPE_RTF,				// 20
	DEC_TYPE_TAR,				// 21
	DEC_TYPE_TNEF,				// 22
	DEC_TYPE_UUE,				// 23 (This engine is no longer supported as of Release 12 (April 2004)) - definition also used in text engine
	DEC_TYPE_ZIP,				// 24
	DEC_TYPE_ZOO,				// 25
	DEC_TYPE_BAG,				// 26
	DEC_TYPE_HA,				// 27
	DEC_TYPE_HYP,				// 28
	DEC_TYPE_SQZ,				// 29
	DEC_TYPE_ACE,				// 30
	DEC_TYPE_PDF,				// 31
	DEC_TYPE_DAS,				// 32
	DEC_TYPE_TEXT,				// 33
	DEC_TYPE_ISO9660,			// 34
	DEC_TYPE_MB3,				// 35
	DEC_TYPE_AS,				// 36
	DEC_TYPE_AD,				// 37
	DEC_TYPE_SIT,				// 38
	DEC_TYPE_DBX,				// 39
	DEC_TYPE_MBOX,				// 40
	DEC_TYPE_OLESS_PNG				// 41 (Structured Storage PNG Stream)

};

/////////////////////////////////////////////////////////////////////////////
// DECRESULT Codes

enum DecResult
{
	DECRESULT_UNCHANGED,
	DECRESULT_CHANGED,
	DECRESULT_TO_BE_REPLACED,
	DECRESULT_TO_BE_DELETED
};


/////////////////////////////////////////////////////////////////////////////
// Decomposer namespace definitions
//
// All namespaces MUST have a corresponding NAMESPACE_U
// definition that contains the uppercase representation
// of the namespace.  This is for EBCDIC compliance.
//

#define NAMESPACE_MEMORY			"mem://"
#define NAMESPACE_MEMORY_U			"MEM://"
#define NAMESPACE_MEMORY_LEN		6
#define NAMESPACE_FTP				"ftp://"
#define NAMESPACE_FTP_U				"FTP://"
#define NAMESPACE_FTP_LEN			6
#define NAMESPACE_HTTP				"http://"
#define NAMESPACE_HTTP_U			"HTTP://"
#define NAMESPACE_HTTP_LEN			7
#define NAMESPACE_RAPI				"rapi://"
#define NAMESPACE_RAPI_U			"RAPI://"
#define NAMESPACE_RAPI_LEN			7
#define NAMESPACE_CDFS				"cdfs://"
#define NAMESPACE_CDFS_U			"CDFS://"
#define NAMESPACE_CDFS_LEN			7

#define NAMESPACE_MAX_LEN			16

/////////////////////////////////////////////////////////////////////////////
// DECRESULT Codes
//
// All Decomposer DECRESULT error values use the facility FACILITY_ITF
// and error codes in the range 0x0200 - 0xFFFF.  This is in accordance
// with Microsoft's recommendations in the Platform SDK.
//
// Once created, an error code's value must not change.
// Engine authors should resist adding new error codes whenever possible.
// Applications should properly handle unlisted error codes.

typedef long DECRESULT;

#define MAKE_DECRESULT(sev,fac,code) ((DECRESULT)(((unsigned long)(sev)<<31)|((unsigned long)(fac)<<16)|((unsigned long)(code))))
#define FACILITY_ITF 4 


#define DECERR(code)  MAKE_DECRESULT(1, FACILITY_ITF, 0x0200 + code)

enum DecErr
{
	DEC_OK							= 0,

	DECERR_ENGINE_NOT_SUPPORTED		= DECERR(10),
	DECERR_ENGINE_FILE_MISSING		= DECERR(11),
	DECERR_INTERFACE_NOT_SUPPORTED	= DECERR(12),

	DECERR_OBJECT_FILE_INVALID		= DECERR(20),
	DECERR_MIME_DATE_FIELD_INVALID	= DECERR(21),

	DECERR_CONTAINER_OPEN			= DECERR(30),
	DECERR_CONTAINER_ACCESS			= DECERR(31),
	DECERR_CONTAINER_UPDATE			= DECERR(32),
	DECERR_CONTAINER_CLOSE			= DECERR(33),
	DECERR_CONTAINER_UNKNOWN_ALG	= DECERR(34),

	DECERR_CHILD_EXTRACT			= DECERR(40),
	DECERR_CHILD_ACCESS				= DECERR(41),
	DECERR_CHILD_DECRYPT			= DECERR(42),
	DECERR_CHILD_SPLIT				= DECERR(43),
	DECERR_CHILD_SPLIT_PART			= DECERR(44),
	DECERR_CHILD_SIZE_UNKNOWN		= DECERR(45),
	DECERR_CHILD_MAX_SIZE			= DECERR(46),
	DECERR_CHILD_MIN_SIZE			= DECERR(47),

	DECERR_TEMPDIR_INVALID			= DECERR(50),

	DECERR_TEMPFILE_CREATE			= DECERR(61),
	DECERR_TEMPFILE_OPEN			= DECERR(62),
	DECERR_TEMPFILE_READ			= DECERR(63),
	DECERR_TEMPFILE_WRITE			= DECERR(64),
	DECERR_TEMPFILE_CLOSE			= DECERR(65),
	DECERR_TEMPFILE_DELETE			= DECERR(66),

	DECERR_OUT_OF_MEMORY			= DECERR(80),

	DECERR_INVALID_PARAMS			= DECERR(90),
	DECERR_INVALID_CHANGE			= DECERR(91),
	DECERR_INVALID_REPLACE			= DECERR(92),
	DECERR_INVALID_DELETE			= DECERR(93),

	DECERR_USER_CANCEL				= DECERR(100),

	DECERR_INCORRECT_USAGE			= DECERR(110),

	DECERR_ENGINE_EXCEPTION			= DECERR(150),

	DECERR_GENERIC					= DECERR(200)
};


/////////////////////////////////////////////////////////////////////////////
// DEC_CHARSET_xxx codes

enum DecCharset
{
	DEC_CHARSET_US_ASCII,
	DEC_CHARSET_ASCII,
	DEC_CHARSET_ISO646_US,
	DEC_CHARSET_ISO_646_IRV_1991,
	DEC_CHARSET_ISO_IR_6,
	DEC_CHARSET_ANSI_X3_4_1968,
	DEC_CHARSET_CP367,
	DEC_CHARSET_IBM367,
	DEC_CHARSET_US,
	DEC_CHARSET_csASCII,
	DEC_CHARSET_UTF_8,
	DEC_CHARSET_UCS_2,
	DEC_CHARSET_ISO_10646_UCS_2,
	DEC_CHARSET_csUnicode,
	DEC_CHARSET_UCS_4,
	DEC_CHARSET_ISO_10646_UCS_4,
	DEC_CHARSET_csUCS4,
	DEC_CHARSET_UTF_16,
	DEC_CHARSET_UTF_7,
	DEC_CHARSET_UNICODE_1_1_UTF_7,
	DEC_CHARSET_csUnicode11UTF7,
	DEC_CHARSET_UCS_2_INTERNAL,
	DEC_CHARSET_UCS_2_SWAPPED,
	DEC_CHARSET_UCS_2_BE,
	DEC_CHARSET_UNICODEBIG,
	DEC_CHARSET_UNICODE_1_1,
	DEC_CHARSET_csUnicode11,
	DEC_CHARSET_UCS_2_LE,
	DEC_CHARSET_UNICODELITTLE,
	DEC_CHARSET_UCS_4_INTERNAL,
	DEC_CHARSET_UCS_4_SWAPPED,
	DEC_CHARSET_UCS_4_BE,
	DEC_CHARSET_UCS_4_LE,
	DEC_CHARSET_JAVA,
	DEC_CHARSET_ISO_8859_1,
	DEC_CHARSET_ISO_8859_1_ALIAS,
	DEC_CHARSET_ISO_8859_1_1987,
	DEC_CHARSET_ISO_IR_100,
	DEC_CHARSET_CP819,
	DEC_CHARSET_IBM819,
	DEC_CHARSET_LATIN1,
	DEC_CHARSET_L1,
	DEC_CHARSET_csISOLatin1,
	DEC_CHARSET_ISO_8859_2,
	DEC_CHARSET_ISO_8859_2_ALIAS,
	DEC_CHARSET_ISO_8859_2_1987,
	DEC_CHARSET_ISO_IR_101,
	DEC_CHARSET_LATIN2,
	DEC_CHARSET_L2,
	DEC_CHARSET_csISOLatin2,
	DEC_CHARSET_ISO_8859_3,
	DEC_CHARSET_ISO_8859_3_ALIAS,
	DEC_CHARSET_ISO_8859_3_1988,
	DEC_CHARSET_ISO_IR_109,
	DEC_CHARSET_LATIN3,
	DEC_CHARSET_L3,
	DEC_CHARSET_csISOLatin3,
	DEC_CHARSET_ISO_8859_4,
	DEC_CHARSET_ISO_8859_4_ALIAS,
	DEC_CHARSET_ISO_8859_4_1988,
	DEC_CHARSET_ISO_IR_110,
	DEC_CHARSET_LATIN4,
	DEC_CHARSET_L4,
	DEC_CHARSET_csISOLatin4,
	DEC_CHARSET_ISO_8859_5,
	DEC_CHARSET_ISO_8859_5_ALIAS,
	DEC_CHARSET_ISO_8859_5_1988,
	DEC_CHARSET_ISO_IR_144,
	DEC_CHARSET_CYRILLIC,
	DEC_CHARSET_csISOLatinCyrillic,
	DEC_CHARSET_ISO_8859_6,
	DEC_CHARSET_ISO_8859_6_ALIAS,
	DEC_CHARSET_ISO_8859_6_1987,
	DEC_CHARSET_ISO_IR_127,
	DEC_CHARSET_ECMA_114,
	DEC_CHARSET_ASMO_708,
	DEC_CHARSET_ARABIC,
	DEC_CHARSET_csISOLatinArabic,
	DEC_CHARSET_ISO_8859_7,
	DEC_CHARSET_ISO_8859_7_ALIAS,
	DEC_CHARSET_ISO_8859_7_1987,
	DEC_CHARSET_ISO_IR_126,
	DEC_CHARSET_ECMA_118,
	DEC_CHARSET_ELOT_928,
	DEC_CHARSET_GREEK8,
	DEC_CHARSET_GREEK,
	DEC_CHARSET_csISOLatinGreek,
	DEC_CHARSET_ISO_8859_8,
	DEC_CHARSET_ISO_8859_8_ALIAS,
	DEC_CHARSET_ISO_8859_8_1988,
	DEC_CHARSET_ISO_IR_138,
	DEC_CHARSET_HEBREW,
	DEC_CHARSET_csISOLatinHebrew,
	DEC_CHARSET_ISO_8859_9,
	DEC_CHARSET_ISO_8859_9_ALIAS,
	DEC_CHARSET_ISO_8859_9_1989,
	DEC_CHARSET_ISO_IR_148,
	DEC_CHARSET_LATIN5,
	DEC_CHARSET_L5,
	DEC_CHARSET_csISOLatin5,
	DEC_CHARSET_ISO_8859_10,
	DEC_CHARSET_ISO_8859_10_ALIAS,
	DEC_CHARSET_ISO_8859_10_1992,
	DEC_CHARSET_ISO_IR_157,
	DEC_CHARSET_LATIN6,
	DEC_CHARSET_L6,
	DEC_CHARSET_csISOLatin6,
	DEC_CHARSET_ISO_8859_13,
	DEC_CHARSET_ISO_8859_13_ALIAS,
	DEC_CHARSET_ISO_IR_179,
	DEC_CHARSET_LATIN7,
	DEC_CHARSET_L7,
	DEC_CHARSET_ISO_8859_14,
	DEC_CHARSET_ISO_8859_14_ALIAS,
	DEC_CHARSET_ISO_8859_14_1998,
	DEC_CHARSET_LATIN8,
	DEC_CHARSET_L8,
	DEC_CHARSET_ISO_8859_15,
	DEC_CHARSET_ISO_8859_15_ALIAS,
	DEC_CHARSET_ISO_8859_15_1998,
	DEC_CHARSET_KOI8_R,
	DEC_CHARSET_csKOI8R,
	DEC_CHARSET_KOI8_U,
	DEC_CHARSET_KOI8_RU,
	DEC_CHARSET_CP1250,
	DEC_CHARSET_WINDOWS_1250,
	DEC_CHARSET_MS_EE,
	DEC_CHARSET_CP1251,
	DEC_CHARSET_WINDOWS_1251,
	DEC_CHARSET_MS_CYRL,
	DEC_CHARSET_CP1252,			  // Windows_1252 WinLatin1 (ANSI)
	DEC_CHARSET_WINDOWS_1252,
	DEC_CHARSET_MS_ANSI,
	DEC_CHARSET_CP1253,
	DEC_CHARSET_WINDOWS_1253,
	DEC_CHARSET_MS_GREEK,
	DEC_CHARSET_CP1254,
	DEC_CHARSET_WINDOWS_1254,
	DEC_CHARSET_MS_TURK,
	DEC_CHARSET_CP1255,
	DEC_CHARSET_WINDOWS_1255,
	DEC_CHARSET_MS_HEBR,
	DEC_CHARSET_CP1256,
	DEC_CHARSET_WINDOWS_1256,
	DEC_CHARSET_MS_ARAB,
	DEC_CHARSET_CP1257,
	DEC_CHARSET_WINDOWS_1257,
	DEC_CHARSET_WINBALTRIM,
	DEC_CHARSET_CP1258,
	DEC_CHARSET_WINDOWS_1258,
	DEC_CHARSET_CP850,				// MS_DOS Latin1 (OEM)
	DEC_CHARSET_IBM850,
	DEC_CHARSET_850,
	DEC_CHARSET_csPC850Multilingual,
	DEC_CHARSET_CP866,
	DEC_CHARSET_IBM866,
	DEC_CHARSET_866,
	DEC_CHARSET_csIBM866,
	DEC_CHARSET_MacRoman,
	DEC_CHARSET_MACINTOSH,
	DEC_CHARSET_MAC,
	DEC_CHARSET_csMacintosh,
	DEC_CHARSET_MacCentralEurope,
	DEC_CHARSET_MacIceland,
	DEC_CHARSET_MacCroatian,
	DEC_CHARSET_MacRomania,
	DEC_CHARSET_MacCyrillic,
	DEC_CHARSET_MacUkraine,
	DEC_CHARSET_MacGreek,
	DEC_CHARSET_MacTurkish,
	DEC_CHARSET_MacHebrew,
	DEC_CHARSET_MacArabic,
	DEC_CHARSET_MacThai,
	DEC_CHARSET_HP_ROMAN8,
	DEC_CHARSET_ROMAN8,
	DEC_CHARSET_R8,
	DEC_CHARSET_csHPRoman8,
	DEC_CHARSET_NEXTSTEP,
	DEC_CHARSET_ARMSCII_8,
	DEC_CHARSET_GEORGIAN_ACADEMY,
	DEC_CHARSET_GEORGIAN_PS,
	DEC_CHARSET_MULELAO_1,
	DEC_CHARSET_CP1133,
	DEC_CHARSET_IBM_CP1133,
	DEC_CHARSET_TIS_620,
	DEC_CHARSET_TIS620,
	DEC_CHARSET_TIS620_0,
	DEC_CHARSET_TIS620_2529_1,
	DEC_CHARSET_TIS620_2533_0,
	DEC_CHARSET_TIS620_2533_1,
	DEC_CHARSET_ISO_IR_166,
	DEC_CHARSET_CP874,
	DEC_CHARSET_WINDOWS_874,
	DEC_CHARSET_VISCII,
	DEC_CHARSET_VISCII1_1_1,
	DEC_CHARSET_csVISCII,
	DEC_CHARSET_TCVN,
	DEC_CHARSET_TCVN_5712,
	DEC_CHARSET_TCVN5712_1,
	DEC_CHARSET_TCVN5712_1_1993,
	DEC_CHARSET_JIS_X0201,
	DEC_CHARSET_JISX0201_1976,
	DEC_CHARSET_JISX0201_1976_0,
	DEC_CHARSET_X0201,
	DEC_CHARSET_csHalfWidthKatakana,
	DEC_CHARSET_JIS_X0208,
	DEC_CHARSET_JIS_X0208_1983_0,
	DEC_CHARSET_JIS_X0208_1983_1,
	DEC_CHARSET_JIS_X0208_1983,
	DEC_CHARSET_JIS_X0208_1990,
	DEC_CHARSET_JIS0208,
	DEC_CHARSET_X0208,
	DEC_CHARSET_ISO_IR_87,
	DEC_CHARSET_csISO87JISX0208,
	DEC_CHARSET_JIS_X0212,
	DEC_CHARSET_JIS_X0212_1990_0,
	DEC_CHARSET_JIS_X0212_1990,
	DEC_CHARSET_X0212,
	DEC_CHARSET_ISO_IR_159,
	DEC_CHARSET_csISO159JISX02121990,
	DEC_CHARSET_GB_2312_80,
	DEC_CHARSET_ISO_IR_58,
	DEC_CHARSET_csISO58GB231280,
	DEC_CHARSET_CHINESE,
	DEC_CHARSET_KSC_5601,
	DEC_CHARSET_KSC5601_1987_0,
	DEC_CHARSET_KS_C_5601_1987,
	DEC_CHARSET_KS_C_5601_1989,
	DEC_CHARSET_ISO_IR_149,
	DEC_CHARSET_csKSC56011987,
	DEC_CHARSET_KOREAN,
	DEC_CHARSET_CP949,
	DEC_CHARSET_EUC_JP,
	DEC_CHARSET_EUCJP,
	DEC_CHARSET_Extended_UNIX_Code_Packed_Format_for_Japanese,
	DEC_CHARSET_csEUCPkdFmtJapanese,
	DEC_CHARSET_SJIS,
	DEC_CHARSET_SHIFT_JIS,
	DEC_CHARSET_SHIFT_JIS_ALIAS,
	DEC_CHARSET_MS_KANJI,
	DEC_CHARSET_csShiftJIS,
	DEC_CHARSET_CP932,
	DEC_CHARSET_ISO_2022_JP,
	DEC_CHARSET_csISO2022JP,
	DEC_CHARSET_ISO_2022_JP_1,
	DEC_CHARSET_ISO_2022_JP_2,
	DEC_CHARSET_EUC_CN,
	DEC_CHARSET_EUCCN,
	DEC_CHARSET_GB2312,
	DEC_CHARSET_csGB2312,
	DEC_CHARSET_GBK,
	DEC_CHARSET_CP936,
	DEC_CHARSET_ISO_2022_CN,
	DEC_CHARSET_csISO2022CN,
	DEC_CHARSET_ISO_2022_CN_EXT,
	DEC_CHARSET_HZ,
	DEC_CHARSET_HZ_GB_2312,
	DEC_CHARSET_EUC_TW,
	DEC_CHARSET_EUCTW,
	DEC_CHARSET_csEUCTW,
	DEC_CHARSET_BIG5,
	DEC_CHARSET_BIG_5,
	DEC_CHARSET_BIG_FIVE,
	DEC_CHARSET_BIGFIVE,
	DEC_CHARSET_csBig5,
	DEC_CHARSET_CP950,
	DEC_CHARSET_EUC_KR,
	DEC_CHARSET_EUCKR,
	DEC_CHARSET_csEUCKR,
	DEC_CHARSET_JOHAB,
	DEC_CHARSET_CP1361,
	DEC_CHARSET_ISO_2022_KR,
	DEC_CHARSET_csISO2022KR
};

#define DEC_CHARSET_LAST	DEC_CHARSET_csISO2022KR

#endif //_DECDEFS_H_

