// Copyright 1998 Symantec, SABU
//************************************************************************
//
// $Header:   S:/NAVEX/VCS/W7H2SIGS.CPv   1.3   09 Dec 1998 17:45:12   DCHI  $
//
// Description:
//  Contains Word 6.0/95 Heuristics Level II signatures.
//
//************************************************************************
// $Log:   S:/NAVEX/VCS/W7H2SIGS.CPv  $
// 
//    Rev 1.3   09 Dec 1998 17:45:12   DCHI
// Added #include "gdefines.h"
// 
//    Rev 1.2   04 Dec 1998 15:41:50   DCHI
// Moved #pragma data_seg() to before gstW7H2SigSet.
// 
//    Rev 1.1   09 Nov 1998 13:58:10   DCHI
// Added #pragma data_seg()'s for global FAR data for SYM_WIN16.
// 
//    Rev 1.0   10 Jun 1998 13:05:58   DCHI
// Initial revision.
// 
//************************************************************************

#include "gdefines.h"

#ifdef MACROHEU

#ifndef MACRODAT

#include "platform.h"
#include "w7h2sght.h"

#ifdef SYM_WIN16
#pragma data_seg("FAR_DATA_0")
#endif

WORD FAR gawW7H2Cmds[] =
{
    0x004F, // 0x0000: FileNew
    0x0050, // 0x0001: FileOpen
    0x0054, // 0x0002: FileSaveAs
    0x0075, // 0x0003: EditReplace
    0x007B, // 0x0004: EditAutoText
    0x00D7, // 0x0005: ToolsMacro
    0x00DE, // 0x0006: Organizer
    0x00ED, // 0x0007: EditSelectAll
    0x012C, // 0x0008: CopyFile
    0x8004, // 0x0009: Asc
    0x8005, // 0x000A: Chr$
    0x800A, // 0x000B: Mid$
    0x800E, // 0x000C: Rnd
    0x8012, // 0x000D: Insert
    0x8045, // 0x000E: GetProfileString$
    0x8046, // 0x000F: SetProfileString
    0x80B7, // 0x0010: CountMacros
    0x80B8, // 0x0011: MacroName$
    0x80C2, // 0x0012: MacroCopy
    0x813D, // 0x0013: MenuItemText$
    0x8140, // 0x0014: MenuText$
    0x814C, // 0x0015: SetDocumentVar
    0x814D, // 0x0016: GetDocumentVar$
    0x8178, // 0x0017: AddAddIn
    0x8183, // 0x0018: AddInState
    0x818C, // 0x0019: DefaultDir$
};

WORD FAR gawW7H2Dlgs[] =
{
    0x0001, // 0x0000: Name
    0x000B, // 0x0001: Delete
    0x0052, // 0x0002: Template
    0x0085, // 0x0003: Insert
    0x009B, // 0x0004: NewTemplate
    0x00CB, // 0x0005: Format
    0x00CD, // 0x0006: Replace
    0x0194, // 0x0007: Find
    0x01E0, // 0x0008: ReplaceAll
    0x01F5, // 0x0009: Run
    0x01F6, // 0x000A: Edit
    0x0287, // 0x000B: Copy
};

BYTE FAR gabyW7H2StrSigs[] =
{
    // 0x0000: SS_PLUS
    0x01, 0x02,
    0xF0, 
    0x02, 0x2C, 
    // 0x0001: SS_COLON
    0x01, 0x02,
    0xF0, 
    0x02, 0x3B, 
    // 0x0002: SS_AUTOEXEC
    0x01, 0x09,
    0xF0, 
    0x09, 0x62, 0x76, 0x75, 0x70, 0x66, 0x79, 0x66, 0x64, 
    // 0x0003: SS_AUTOOPEN
    0x01, 0x09,
    0xF0, 
    0x09, 0x62, 0x76, 0x75, 0x70, 0x70, 0x71, 0x66, 0x6F, 
    // 0x0004: SS_AUTONEW
    0x01, 0x08,
    0xF0, 
    0x08, 0x62, 0x76, 0x75, 0x70, 0x6F, 0x66, 0x78, 
    // 0x0005: SS_AUTOEXIT
    0x01, 0x09,
    0xF0, 
    0x09, 0x62, 0x76, 0x75, 0x70, 0x66, 0x79, 0x6A, 0x75, 
    // 0x0006: SS_AUTOCLOSE
    0x01, 0x0A,
    0xF0, 
    0x0A, 0x62, 0x76, 0x75, 0x70, 0x64, 0x6D, 0x70, 0x74, 0x66, 
    // 0x0007: SS_FILENEW
    0x01, 0x08,
    0xF0, 
    0x08, 0x67, 0x6A, 0x6D, 0x66, 0x6F, 0x66, 0x78, 
    // 0x0008: SS_FILECLOSE
    0x01, 0x0A,
    0xF0, 
    0x0A, 0x67, 0x6A, 0x6D, 0x66, 0x64, 0x6D, 0x70, 0x74, 0x66, 
    // 0x0009: SS_FILESAVE
    0x01, 0x09,
    0xF0, 
    0x09, 0x67, 0x6A, 0x6D, 0x66, 0x74, 0x62, 0x77, 0x66, 
    // 0x000A: SS_FILEEXIT
    0x01, 0x09,
    0xF0, 
    0x09, 0x67, 0x6A, 0x6D, 0x66, 0x66, 0x79, 0x6A, 0x75, 
    // 0x000B: SS_FILESAVEAS
    0x01, 0x0B,
    0xF0, 
    0x0B, 0x67, 0x6A, 0x6D, 0x66, 0x74, 0x62, 0x77, 0x66, 0x62, 0x74, 
    // 0x000C: SS_FILEOPEN
    0x01, 0x09,
    0xF0, 
    0x09, 0x67, 0x6A, 0x6D, 0x66, 0x70, 0x71, 0x66, 0x6F, 
    // 0x000D: SS_MAKROKOPIEREN
    0x01, 0x0E,
    0xF0, 
    0x0E, 0x6E, 0x62, 0x6C, 0x73, 0x70, 0x6C, 0x70, 0x71, 0x6A, 0x66, 0x73, 0x66, 0x6F, 
    // 0x000E: SS_MACROCOPY
    0x01, 0x0A,
    0xF0, 
    0x0A, 0x6E, 0x62, 0x64, 0x73, 0x70, 0x64, 0x70, 0x71, 0x7A, 
};

LPBYTE FAR galpabyW7H2StrSigs[] =
{
    gabyW7H2StrSigs + 0,
    gabyW7H2StrSigs + 5,
    gabyW7H2StrSigs + 10,
    gabyW7H2StrSigs + 22,
    gabyW7H2StrSigs + 34,
    gabyW7H2StrSigs + 45,
    gabyW7H2StrSigs + 57,
    gabyW7H2StrSigs + 70,
    gabyW7H2StrSigs + 81,
    gabyW7H2StrSigs + 94,
    gabyW7H2StrSigs + 106,
    gabyW7H2StrSigs + 118,
    gabyW7H2StrSigs + 132,
    gabyW7H2StrSigs + 144,
    gabyW7H2StrSigs + 161,
};

WORD FAR gawW7H2StrSigIdx[] =
{
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0x00
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0x08
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0x10
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0x18
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0x20
    0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0x28
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0x30
    0xFFFF, 0xFFFF, 0x0001, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0x38
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0x40
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0x48
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0x50
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0x58
    0xFFFF, 0x0002, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0007, 0xFFFF,  // 0x60
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x000D, 0xFFFF, 0xFFFF,  // 0x68
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0x70
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0x78
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0x80
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0x88
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0x90
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0x98
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0xA0
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0xA8
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0xB0
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0xB8
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0xC0
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0xC8
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0xD0
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0xD8
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0xE0
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0xE8
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0xF0
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,  // 0xF8
};

BYTE FAR gabyW7H2StrSigCatScores[] =
{
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x01,
    0x00, 0x01,
    0x00, 0x01,
    0x00, 0x01,
    0x00, 0x01,
    0x00, 0x01,
    0x00, 0x01,
    0x00, 0x01,
    0x00, 0x01,
    0x00, 0x01,
    0x00, 0x01,
    0x00, 0x00,
    0x00, 0x00,
};

BYTE FAR gabyW7H2LineSigs[] =
{
    // 0x0000: LS_STR_ARRAY_ASSIGN_ENC
    0x0A, 0x08,
    0xAA, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xCA, 0xBD, 0x4E, 0xFB, 
    0x69, 0x05, 0x6C, 0x06, 0x0C, 0x6A, 0x67, 0x1D, 
    // 0x0001: LS_TOOLSMACRO_RUN
    0x02, 0x02,
    0x20, 0xFB, 
    0x05, 0x09, 
    // 0x0002: LS_EDITAUTOTEXT_INSERT
    0x02, 0x02,
    0x20, 0xFB, 
    0x04, 0x03, 
    // 0x0003: LS_CHRS
    0x01, 0x01,
    0xF0, 
    0x0A, 
    // 0x0004: LS_TOOLSMACRO_EDIT
    0x02, 0x02,
    0x20, 0xFB, 
    0x05, 0x0A, 
    // 0x0005: LS_NEWTEMPLATE
    0x03, 0x01,
    0xE2, 0xB0, 0xFF, 
    0x04, 
    // 0x0006: LS_FILESAVEAS_FORMAT
    0x02, 0x02,
    0x20, 0xFB, 
    0x02, 0x05, 
    // 0x0007: LS_ORGANIZER_COPY
    0x02, 0x02,
    0x20, 0xFB, 
    0x06, 0x0B, 
    // 0x0008: LS_INSERT_STR_EXPR
    0x09, 0x09,
    0xA0, 0xAB, 0xAB, 0xAB, 0xAB, 0x0B, 0x8B, 0x8B, 0xFB, 
    0x0D, 0x69, 0x05, 0x6C, 0x06, 0x07, 0x0A, 0x00, 0x01, 
    // 0x0009: LS_INSERT_MACROCOPY
    0x03, 0x03,
    0x80, 0xC8, 0xFB, 
    0x0D, 0x0E, 0x0D, 
    // 0x000A: LS_EDITREPLACE
    0x04, 0x04,
    0x20, 0x2B, 0x2B, 0xFB, 
    0x03, 0x07, 0x06, 0x08, 
    // 0x000B: LS_TEMPLATE
    0x03, 0x01,
    0xE2, 0xB0, 0xFF, 
    0x02, 
    // 0x000C: LS_TOOLSMACRO_DELETE
    0x02, 0x02,
    0x20, 0xFB, 
    0x05, 0x01, 
    // 0x000D: LS_MIDS
    0x01, 0x01,
    0xF0, 
    0x0B, 
    // 0x000E: LS_OPEN_OUTPUT
    0x02, 0x02,
    0xAA, 0xFB, 
    0x3D, 0x3B, 
    // 0x000F: LS_FILESAVEAS_FORMAT_NAME
    0x05, 0x03,
    0x20, 0xEB, 0xB0, 0xB2, 0xFF, 
    0x02, 0x05, 0x00, 
    // 0x0010: LS_FILENEW_TEMPLATE
    0x05, 0x03,
    0x20, 0x2B, 0xEB, 0xB0, 0xFF, 
    0x00, 0x02, 0x04, 
    // 0x0011: LS_ASC
    0x01, 0x01,
    0xF0, 
    0x09, 
    // 0x0012: LS_ASSIGN_VAR_DEFAULTDIR_CAT_STR
    0x06, 0x06,
    0xAA, 0x0B, 0xAB, 0xAB, 0xCA, 0xFB, 
    0x69, 0x0C, 0x19, 0x07, 0x6A, 0x79, 
};

LPBYTE FAR galpabyW7H2LineSigs[] =
{
    gabyW7H2LineSigs + 0,
    gabyW7H2LineSigs + 20,
    gabyW7H2LineSigs + 26,
    gabyW7H2LineSigs + 32,
    gabyW7H2LineSigs + 36,
    gabyW7H2LineSigs + 42,
    gabyW7H2LineSigs + 48,
    gabyW7H2LineSigs + 54,
    gabyW7H2LineSigs + 60,
    gabyW7H2LineSigs + 80,
    gabyW7H2LineSigs + 88,
    gabyW7H2LineSigs + 98,
    gabyW7H2LineSigs + 104,
    gabyW7H2LineSigs + 110,
    gabyW7H2LineSigs + 114,
    gabyW7H2LineSigs + 120,
    gabyW7H2LineSigs + 130,
    gabyW7H2LineSigs + 140,
    gabyW7H2LineSigs + 144,
};

BYTE FAR gabyW7H2LineSigCatScores[] =
{
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x01, 0x01,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x01, 0x01,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x01, 0x01,
    0x00, 0x00,
};

BYTE FAR gabyW7H2FuncSigs[] =
{
    // 0x0000: FS_RND_GLOBAL_TO_LOCAL
    0x03, 0x03,
    0x00, 0x0B, 0xFB, 
    0x15, 0x12, 0x0C, 
    // 0x0001: FS_CREATE_DOCVAR_MACRO
    0x04, 0x04,
    0x40, 0x0B, 0x4B, 0xFB, 
    0x16, 0x04, 0x0D, 0x0C, 
    // 0x0002: FS_POLYNAME_GLOBAL_TO_LOCAL
    0x03, 0x03,
    0x00, 0x0B, 0xFB, 
    0x12, 0x0E, 0x15, 
    // 0x0003: FS_OVERWRITE_GLOBAL_TO_LOCAL_FO
    0x04, 0x04,
    0x00, 0x4B, 0x4B, 0xFB, 
    0x10, 0x11, 0x0F, 0x12, 
    // 0x0004: FS_CHK_INST_COPY
    0x04, 0x04,
    0x00, 0x4B, 0xC0, 0xFB, 
    0x10, 0x11, 0x07, 0x12, 
    // 0x0005: FS_ADDIN
    0x03, 0x03,
    0x00, 0x0B, 0xFB, 
    0x19, 0x08, 0x17, 
    // 0x0006: FS_EDIT_RUN_DEL_MACRO
    0x05, 0x05,
    0x04, 0x4B, 0x4B, 0x4B, 0xFB, 
    0x04, 0x0A, 0x09, 0x01, 0x0C, 
    // 0x0007: FS_CREATE_GLOBAL_MACRO
    0x05, 0x05,
    0x00, 0x0B, 0x4B, 0x0B, 0xFB, 
    0x12, 0x14, 0x13, 0x04, 0x0D, 
    // 0x0008: FS_AUTOTEXT_MACRO
    0x02, 0x02,
    0x44, 0xFB, 
    0x04, 0x02, 
    // 0x0009: FS_MANY_AUTO_MACROCOPIES
    0x04, 0x04,
    0xE0, 0xB1, 0xB0, 0xFF, 
    0x12, 0x05, 0x00, 0x0C, 
    // 0x000A: FS_POLY_MACRONAME
    0x03, 0x03,
    0x04, 0x4B, 0xFB, 
    0x04, 0x0C, 0x0A, 
    // 0x000B: FS_OVERWRITE_GLOBAL_TO_LOCAL_FN
    0x03, 0x03,
    0x44, 0x4B, 0xFB, 
    0x10, 0x0F, 0x12, 
    // 0x000C: FS_RND_LOCAL_TO_GLOBAL
    0x03, 0x03,
    0x00, 0x0B, 0xFB, 
    0x16, 0x12, 0x0C, 
    // 0x000D: FS_POLYNAME_LOCAL_TO_GLOBAL
    0x03, 0x03,
    0x00, 0x0B, 0xFB, 
    0x12, 0x16, 0x0F, 
    // 0x000E: FS_REPLACE_MACRO
    0x04, 0x04,
    0x04, 0x4B, 0x0B, 0xFB, 
    0x04, 0x07, 0x09, 0x0A, 
    // 0x000F: FS_FILENEW_TEMPLATE
    0x04, 0x04,
    0x00, 0x4B, 0x4B, 0xFB, 
    0x19, 0x00, 0x05, 0x0B, 
    // 0x0010: FS_CREATE_LOCAL_MACRO
    0x02, 0x02,
    0x40, 0xFB, 
    0x12, 0x06, 
    // 0x0011: FS_OPEN_VAR_DOC
    0x04, 0x04,
    0x40, 0x0B, 0x0B, 0xFB, 
    0x19, 0x0E, 0x16, 0x01, 
    // 0x0012: FS_STR_ARRAY_DEC_MACRO
    0x05, 0x05,
    0x44, 0x4B, 0xEB, 0xB1, 0xFF, 
    0x00, 0x04, 0x08, 0x02, 0x01, 
    // 0x0013: FS_TOOLSMACRO_HIDE_ADDIN
    0x02, 0x02,
    0x00, 0xFB, 
    0x18, 0x05, 
};

LPBYTE FAR galpabyW7H2FuncSigs[] =
{
    gabyW7H2FuncSigs + 0,
    gabyW7H2FuncSigs + 8,
    gabyW7H2FuncSigs + 18,
    gabyW7H2FuncSigs + 26,
    gabyW7H2FuncSigs + 36,
    gabyW7H2FuncSigs + 46,
    gabyW7H2FuncSigs + 54,
    gabyW7H2FuncSigs + 66,
    gabyW7H2FuncSigs + 78,
    gabyW7H2FuncSigs + 84,
    gabyW7H2FuncSigs + 94,
    gabyW7H2FuncSigs + 102,
    gabyW7H2FuncSigs + 110,
    gabyW7H2FuncSigs + 118,
    gabyW7H2FuncSigs + 126,
    gabyW7H2FuncSigs + 136,
    gabyW7H2FuncSigs + 146,
    gabyW7H2FuncSigs + 152,
    gabyW7H2FuncSigs + 162,
    gabyW7H2FuncSigs + 174,
};

BYTE FAR gabyW7H2FuncSigCatScores[] =
{
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
};

BYTE FAR gabyW7H2SetSigs[] =
{
    // 0x0000: 0x0001
    0x02, 0x02,
    0x66, 0xFB, 
    0x0D, 0x02, 
    // 0x0001: 0x0002
    0x01, 0x01,
    0xF6, 
    0x01, 
    // 0x0002: 0x0003
    0x03, 0x03,
    0x66, 0xB6, 0xFC, 
    0x03, 0x0B, 0x04, 
    // 0x0003: 0x0004
    0x01, 0x01,
    0xF6, 
    0x0E, 
    // 0x0004: 0x0005
    0x01, 0x01,
    0xF6, 
    0x0A, 
    // 0x0005: 0x0006
    0x02, 0x02,
    0x66, 0xFB, 
    0x07, 0x10, 
    // 0x0006: 0x0007
    0x02, 0x02,
    0x66, 0xFB, 
    0x0F, 0x05, 
    // 0x0007: 0x0008
    0x01, 0x01,
    0xF6, 
    0x11, 
    // 0x0008: 0x0009
    0x01, 0x01,
    0xF6, 
    0x12, 
    // 0x0009: 0x000A
    0x01, 0x01,
    0xF6, 
    0x09, 
    // 0x000A: 0x000B
    0x02, 0x02,
    0x66, 0xFC, 
    0x0C, 0x00, 
    // 0x000B: 0x000C
    0x01, 0x01,
    0xF6, 
    0x06, 
    // 0x000C: 0x000D
    0x01, 0x01,
    0xF6, 
    0x08, 
    // 0x000D: 0x000E
    0x02, 0x02,
    0x66, 0xFB, 
    0x05, 0x13, 
};

LPBYTE FAR galpabyW7H2SetSigs[] =
{
    gabyW7H2SetSigs + 0,
    gabyW7H2SetSigs + 6,
    gabyW7H2SetSigs + 10,
    gabyW7H2SetSigs + 18,
    gabyW7H2SetSigs + 22,
    gabyW7H2SetSigs + 26,
    gabyW7H2SetSigs + 32,
    gabyW7H2SetSigs + 38,
    gabyW7H2SetSigs + 42,
    gabyW7H2SetSigs + 46,
    gabyW7H2SetSigs + 50,
    gabyW7H2SetSigs + 56,
    gabyW7H2SetSigs + 60,
    gabyW7H2SetSigs + 64,
};

WORD FAR gawW7H2SetSigVIDs[] =
{
    0x0001, // Demon
    0x0002, // Dishonor
    0x0003, // Eraser
    0x0004, // Four
    0x0005, // Futureno
    0x0006, // Goggles
    0x0007, // Hunter
    0x0008, // Inside
    0x0009, // KillOk
    0x000A, // RandomA
    0x000B, // RandomIC
    0x000C, // Target
    0x000D, // UglyKid
    0x000E, // Zero
};

#ifdef SYM_WIN16
#pragma data_seg()
#endif

W7H2_SIG_SET_T gstW7H2SigSet =
{
    26,
    gawW7H2Cmds,
    12,
    gawW7H2Dlgs,
    15,
    galpabyW7H2StrSigs,
    gawW7H2StrSigIdx,
    gabyW7H2StrSigCatScores,
    19,
    galpabyW7H2LineSigs,
    gabyW7H2LineSigCatScores,
    20,
    galpabyW7H2FuncSigs,
    gabyW7H2FuncSigCatScores,
    2,
    14,
    galpabyW7H2SetSigs,
    gawW7H2SetSigVIDs
};

#endif // #ifndef MACRODAT

#endif // #ifdef MACROHEU

