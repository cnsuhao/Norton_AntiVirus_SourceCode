//************************************************************************
//
// $Header:   S:/MACROHEU/VCS/O97DOOP.CPv   1.0   15 Aug 1997 13:28:56   DCHI  $
//
// Description:
//  Table of opcode handler functions.
//
//************************************************************************
// $Log:   S:/MACROHEU/VCS/O97DOOP.CPv  $
// 
//    Rev 1.0   15 Aug 1997 13:28:56   DCHI
// Initial revision.
// 
//************************************************************************

#include "o97api.h"
#include "o97env.h"

BOOL O97_OP_00_IMP(LPO97_ENV lpstEnv);
BOOL O97_OP_01_EQV(LPO97_ENV lpstEnv);
BOOL O97_OP_02_XOR(LPO97_ENV lpstEnv);
BOOL O97_OP_03_OR(LPO97_ENV lpstEnv);
BOOL O97_OP_04_AND(LPO97_ENV lpstEnv);
BOOL O97_OP_05_EQ(LPO97_ENV lpstEnv);
BOOL O97_OP_06_NE(LPO97_ENV lpstEnv);
BOOL O97_OP_07_LE(LPO97_ENV lpstEnv);
BOOL O97_OP_08_GE(LPO97_ENV lpstEnv);
BOOL O97_OP_09_LT(LPO97_ENV lpstEnv);
BOOL O97_OP_0A_GT(LPO97_ENV lpstEnv);
BOOL O97_OP_0B_PLUS(LPO97_ENV lpstEnv);
BOOL O97_OP_0C_MINUS(LPO97_ENV lpstEnv);
BOOL O97_OP_0D_MOD(LPO97_ENV lpstEnv);
BOOL O97_OP_0E_INT_DIV(LPO97_ENV lpstEnv);
BOOL O97_OP_0F_ASTERISK(LPO97_ENV lpstEnv);
BOOL O97_OP_10_SLASH(LPO97_ENV lpstEnv);
BOOL O97_OP_11_AMPERSAND(LPO97_ENV lpstEnv);
BOOL O97_OP_12_LIKE(LPO97_ENV lpstEnv);
BOOL O97_OP_13_CARAT(LPO97_ENV lpstEnv);
BOOL O97_OP_14_IS(LPO97_ENV lpstEnv);
BOOL O97_OP_15_NOT(LPO97_ENV lpstEnv);
BOOL O97_OP_16_NEGATE(LPO97_ENV lpstEnv);
BOOL O97_OP_17_ABS(LPO97_ENV lpstEnv);
BOOL O97_OP_18_FIX(LPO97_ENV lpstEnv);
BOOL O97_OP_19_INT(LPO97_ENV lpstEnv);
BOOL O97_OP_1A_SGN(LPO97_ENV lpstEnv);
BOOL O97_OP_1B_LEN(LPO97_ENV lpstEnv);
BOOL O97_OP_1C_LENB(LPO97_ENV lpstEnv);
BOOL O97_OP_1D_PARENTHESIZE(LPO97_ENV lpstEnv);
BOOL O97_OP_1E(LPO97_ENV lpstEnv);
BOOL O97_OP_1F(LPO97_ENV lpstEnv);
BOOL O97_OP_20_EVAL(LPO97_ENV lpstEnv);
BOOL O97_OP_21_DOT_EVAL(LPO97_ENV lpstEnv);
BOOL O97_OP_22(LPO97_ENV lpstEnv);
BOOL O97_OP_23(LPO97_ENV lpstEnv);
BOOL O97_OP_24_FUNCTION_EVAL(LPO97_ENV lpstEnv);
BOOL O97_OP_25_DOT_FUNCTION_EVAL(LPO97_ENV lpstEnv);
BOOL O97_OP_26(LPO97_ENV lpstEnv);
BOOL O97_OP_27_ASSIGN(LPO97_ENV lpstEnv);
BOOL O97_OP_28_DOT_ASSIGN(LPO97_ENV lpstEnv);
BOOL O97_OP_29(LPO97_ENV lpstEnv);
BOOL O97_OP_2A(LPO97_ENV lpstEnv);
BOOL O97_OP_2B_ASSIGN_FUNCTION(LPO97_ENV lpstEnv);
BOOL O97_OP_2C_ASSIGN_DOT_FUNCTION(LPO97_ENV lpstEnv);
BOOL O97_OP_2D(LPO97_ENV lpstEnv);
BOOL O97_OP_2E_ASSIGN_USING_SET(LPO97_ENV lpstEnv);
BOOL O97_OP_2F_ASSIGN_DOTTED_SET(LPO97_ENV lpstEnv);
BOOL O97_OP_30(LPO97_ENV lpstEnv);
BOOL O97_OP_31(LPO97_ENV lpstEnv);
BOOL O97_OP_32(LPO97_ENV lpstEnv);
BOOL O97_OP_33(LPO97_ENV lpstEnv);
BOOL O97_OP_34(LPO97_ENV lpstEnv);
BOOL O97_OP_35_ROOT_DOT_EVAL(LPO97_ENV lpstEnv);
BOOL O97_OP_36(LPO97_ENV lpstEnv);
BOOL O97_OP_37_ROOT_DOT_FUNCTION_EVAL(LPO97_ENV lpstEnv);
BOOL O97_OP_38(LPO97_ENV lpstEnv);
BOOL O97_OP_39_ASSIGN_ROOT_DOT(LPO97_ENV lpstEnv);
BOOL O97_OP_3A(LPO97_ENV lpstEnv);
BOOL O97_OP_3B_ASSIGN_ROOT_DOT_FUNCTION(LPO97_ENV lpstEnv);
BOOL O97_OP_3C(LPO97_ENV lpstEnv);
BOOL O97_OP_3D(LPO97_ENV lpstEnv);
BOOL O97_OP_3E(LPO97_ENV lpstEnv);
BOOL O97_OP_3F(LPO97_ENV lpstEnv);
BOOL O97_OP_40(LPO97_ENV lpstEnv);
BOOL O97_OP_41_CALL(LPO97_ENV lpstEnv);
BOOL O97_OP_42_DOT_CALL(LPO97_ENV lpstEnv);
BOOL O97_OP_43_ROOT_DOT_CALL(LPO97_ENV lpstEnv);
BOOL O97_OP_44(LPO97_ENV lpstEnv);
BOOL O97_OP_45_COLON(LPO97_ENV lpstEnv);
BOOL O97_OP_46_THEN_ELSE_SINGLE(LPO97_ENV lpstEnv);
BOOL O97_OP_47(LPO97_ENV lpstEnv);
BOOL O97_OP_48_CASE(LPO97_ENV lpstEnv);
BOOL O97_OP_49_CASE_TO(LPO97_ENV lpstEnv);
BOOL O97_OP_4A_CASE_GT(LPO97_ENV lpstEnv);
BOOL O97_OP_4B_CASE_LT(LPO97_ENV lpstEnv);
BOOL O97_OP_4C_CASE_GE(LPO97_ENV lpstEnv);
BOOL O97_OP_4D_CASE_LE(LPO97_ENV lpstEnv);
BOOL O97_OP_4E_CASE_NE(LPO97_ENV lpstEnv);
BOOL O97_OP_4F_CASE_EQ(LPO97_ENV lpstEnv);
BOOL O97_OP_50_CASE_ELSE(LPO97_ENV lpstEnv);
BOOL O97_OP_51_CASE_EOL(LPO97_ENV lpstEnv);
BOOL O97_OP_52(LPO97_ENV lpstEnv);
BOOL O97_OP_53_CLOSE(LPO97_ENV lpstEnv);
BOOL O97_OP_54_CLOSE_ALL(LPO97_ENV lpstEnv);
BOOL O97_OP_55_TYPE_CONVERSION(LPO97_ENV lpstEnv);
BOOL O97_OP_56(LPO97_ENV lpstEnv);
BOOL O97_OP_57(LPO97_ENV lpstEnv);
BOOL O97_OP_58(LPO97_ENV lpstEnv);
BOOL O97_OP_59_DEFTYPE(LPO97_ENV lpstEnv);
BOOL O97_OP_5A_DECLARATION(LPO97_ENV lpstEnv);
BOOL O97_OP_5B_TYPE_ELEMENT(LPO97_ENV lpstEnv);
BOOL O97_OP_5C_DO(LPO97_ENV lpstEnv);
BOOL O97_OP_5D(LPO97_ENV lpstEnv);
BOOL O97_OP_5E_DO_UNTIL(LPO97_ENV lpstEnv);
BOOL O97_OP_5F_DO_WHILE(LPO97_ENV lpstEnv);
BOOL O97_OP_60_ELSE_SINGLE(LPO97_ENV lpstEnv);
BOOL O97_OP_61_ELSE_MULTIPLE(LPO97_ENV lpstEnv);
BOOL O97_OP_62_ELSEIF(LPO97_ENV lpstEnv);
BOOL O97_OP_63(LPO97_ENV lpstEnv);
BOOL O97_OP_64_END(LPO97_ENV lpstEnv);
BOOL O97_OP_65(LPO97_ENV lpstEnv);
BOOL O97_OP_66_END_FUNCTION(LPO97_ENV lpstEnv);
BOOL O97_OP_67_END_SINGLE_IF(LPO97_ENV lpstEnv);
BOOL O97_OP_68_END_IF(LPO97_ENV lpstEnv);
BOOL O97_OP_69(LPO97_ENV lpstEnv);
BOOL O97_OP_6A_END_PROPERTY(LPO97_ENV lpstEnv);
BOOL O97_OP_6B_END_SELECT(LPO97_ENV lpstEnv);
BOOL O97_OP_6C_END_SUB(LPO97_ENV lpstEnv);
BOOL O97_OP_6D_END_TYPE(LPO97_ENV lpstEnv);
BOOL O97_OP_6E_END_WITH(LPO97_ENV lpstEnv);
BOOL O97_OP_6F(LPO97_ENV lpstEnv);
BOOL O97_OP_70(LPO97_ENV lpstEnv);
BOOL O97_OP_71_EXIT_DO(LPO97_ENV lpstEnv);
BOOL O97_OP_72_EXIT_FOR(LPO97_ENV lpstEnv);
BOOL O97_OP_73_EXIT_FUNCTION(LPO97_ENV lpstEnv);
BOOL O97_OP_74_EXIT_PROPERTY(LPO97_ENV lpstEnv);
BOOL O97_OP_75_EXIT_SUB(LPO97_ENV lpstEnv);
BOOL O97_OP_76(LPO97_ENV lpstEnv);
BOOL O97_OP_77(LPO97_ENV lpstEnv);
BOOL O97_OP_78(LPO97_ENV lpstEnv);
BOOL O97_OP_79(LPO97_ENV lpstEnv);
BOOL O97_OP_7A(LPO97_ENV lpstEnv);
BOOL O97_OP_7B(LPO97_ENV lpstEnv);
BOOL O97_OP_7C(LPO97_ENV lpstEnv);
BOOL O97_OP_7D_INSTR_TWO_PARAMS(LPO97_ENV lpstEnv);
BOOL O97_OP_7E_INSTR_THREE_PARAMS(LPO97_ENV lpstEnv);
BOOL O97_OP_7F_INSTR_FOUR_PARAMS(LPO97_ENV lpstEnv);
BOOL O97_OP_80(LPO97_ENV lpstEnv);
BOOL O97_OP_81(LPO97_ENV lpstEnv);
BOOL O97_OP_82(LPO97_ENV lpstEnv);
BOOL O97_OP_83(LPO97_ENV lpstEnv);
BOOL O97_OP_84(LPO97_ENV lpstEnv);
BOOL O97_OP_85(LPO97_ENV lpstEnv);
BOOL O97_OP_86_STRCOMP_A_B(LPO97_ENV lpstEnv);
BOOL O97_OP_87_STRCOMP_A_B_C(LPO97_ENV lpstEnv);
BOOL O97_OP_88(LPO97_ENV lpstEnv);
BOOL O97_OP_89(LPO97_ENV lpstEnv);
BOOL O97_OP_8A(LPO97_ENV lpstEnv);
BOOL O97_OP_8B_B_TO_C(LPO97_ENV lpstEnv);
BOOL O97_OP_8C_EACH_B(LPO97_ENV lpstEnv);
BOOL O97_OP_8D(LPO97_ENV lpstEnv);
BOOL O97_OP_8E_B_TO_C_STEP_D(LPO97_ENV lpstEnv);
BOOL O97_OP_8F_SUB_FUNCTION(LPO97_ENV lpstEnv);
BOOL O97_OP_90(LPO97_ENV lpstEnv);
BOOL O97_OP_91(LPO97_ENV lpstEnv);
BOOL O97_OP_92(LPO97_ENV lpstEnv);
BOOL O97_OP_93_GOTO(LPO97_ENV lpstEnv);
BOOL O97_OP_94_IF_THEN_SINGLE(LPO97_ENV lpstEnv);
BOOL O97_OP_95_IF_THEN_MULTIPLE(LPO97_ENV lpstEnv);
BOOL O97_OP_96(LPO97_ENV lpstEnv);
BOOL O97_OP_97(LPO97_ENV lpstEnv);
BOOL O97_OP_98(LPO97_ENV lpstEnv);
BOOL O97_OP_99(LPO97_ENV lpstEnv);
BOOL O97_OP_9A(LPO97_ENV lpstEnv);
BOOL O97_OP_9B_LABEL(LPO97_ENV lpstEnv);
BOOL O97_OP_9C(LPO97_ENV lpstEnv);
BOOL O97_OP_9D(LPO97_ENV lpstEnv);
BOOL O97_OP_9E_BROKEN_LINE(LPO97_ENV lpstEnv);
BOOL O97_OP_9F(LPO97_ENV lpstEnv);
BOOL O97_OP_A0(LPO97_ENV lpstEnv);
BOOL O97_OP_A1(LPO97_ENV lpstEnv);
BOOL O97_OP_A2(LPO97_ENV lpstEnv);
BOOL O97_OP_A3_NO_LEN(LPO97_ENV lpstEnv);
BOOL O97_OP_A4_WORD(LPO97_ENV lpstEnv);
BOOL O97_OP_A5_DWORD(LPO97_ENV lpstEnv);
BOOL O97_OP_A6_HEX_WORD(LPO97_ENV lpstEnv);
BOOL O97_OP_A7_HEX_DWORD(LPO97_ENV lpstEnv);
BOOL O97_OP_A8_NOTHING(LPO97_ENV lpstEnv);
BOOL O97_OP_A9(LPO97_ENV lpstEnv);
BOOL O97_OP_AA(LPO97_ENV lpstEnv);
BOOL O97_OP_AB(LPO97_ENV lpstEnv);
BOOL O97_OP_AC_DOUBLE(LPO97_ENV lpstEnv);
BOOL O97_OP_AD(LPO97_ENV lpstEnv);
BOOL O97_OP_AE_STRING(LPO97_ENV lpstEnv);
BOOL O97_OP_AF_TRUE_OR_FALSE(LPO97_ENV lpstEnv);
BOOL O97_OP_B0(LPO97_ENV lpstEnv);
BOOL O97_OP_B1_LOOP(LPO97_ENV lpstEnv);
BOOL O97_OP_B2_LOOP_UNTIL(LPO97_ENV lpstEnv);
BOOL O97_OP_B3_LOOP_WHILE(LPO97_ENV lpstEnv);
BOOL O97_OP_B4(LPO97_ENV lpstEnv);
BOOL O97_OP_B5(LPO97_ENV lpstEnv);
BOOL O97_OP_B6_PRINT_BEGIN(LPO97_ENV lpstEnv);
BOOL O97_OP_B7(LPO97_ENV lpstEnv);
BOOL O97_OP_B8(LPO97_ENV lpstEnv);
BOOL O97_OP_B9(LPO97_ENV lpstEnv);
BOOL O97_OP_BA(LPO97_ENV lpstEnv);
BOOL O97_OP_BB(LPO97_ENV lpstEnv);
BOOL O97_OP_BC(LPO97_ENV lpstEnv);
BOOL O97_OP_BD(LPO97_ENV lpstEnv);
BOOL O97_OP_BE_NEW(LPO97_ENV lpstEnv);
BOOL O97_OP_BF_NEXT(LPO97_ENV lpstEnv);
BOOL O97_OP_C0_NEXT_A(LPO97_ENV lpstEnv);
BOOL O97_OP_C1_ON_ERROR_GOTO(LPO97_ENV lpstEnv);
BOOL O97_OP_C2(LPO97_ENV lpstEnv);
BOOL O97_OP_C3(LPO97_ENV lpstEnv);
BOOL O97_OP_C4_OPEN(LPO97_ENV lpstEnv);
BOOL O97_OP_C5_OPTION(LPO97_ENV lpstEnv);
BOOL O97_OP_C6_ARRAY_SIZE(LPO97_ENV lpstEnv);
BOOL O97_OP_C7(LPO97_ENV lpstEnv);
BOOL O97_OP_C8(LPO97_ENV lpstEnv);
BOOL O97_OP_C9_PARAM_ASSIGN(LPO97_ENV lpstEnv);
BOOL O97_OP_CA_PRINTN_BEGIN(LPO97_ENV lpstEnv);
BOOL O97_OP_CB_PRINT_COMMA(LPO97_ENV lpstEnv);
BOOL O97_OP_CC_PRINT_END(LPO97_ENV lpstEnv);
BOOL O97_OP_CD_PRINT_ARG_COMMA(LPO97_ENV lpstEnv);
BOOL O97_OP_CE_PRINT_ARG_END(LPO97_ENV lpstEnv);
BOOL O97_OP_CF_PRINT_ARG_SEMICOLON(LPO97_ENV lpstEnv);
BOOL O97_OP_D0_PRINT_END_NONE(LPO97_ENV lpstEnv);
BOOL O97_OP_D1_PRINT_MID_END_NONE(LPO97_ENV lpstEnv);
BOOL O97_OP_D2_PRINT_SEMICOLON(LPO97_ENV lpstEnv);
BOOL O97_OP_D3_PRINT_SPC_ARG(LPO97_ENV lpstEnv);
BOOL O97_OP_D4_PRINT_TAB_ARG(LPO97_ENV lpstEnv);
BOOL O97_OP_D5_PRINT_TAB(LPO97_ENV lpstEnv);
BOOL O97_OP_D6(LPO97_ENV lpstEnv);
BOOL O97_OP_D7(LPO97_ENV lpstEnv);
BOOL O97_OP_D8_COMMENT(LPO97_ENV lpstEnv);
BOOL O97_OP_D9_REDIM(LPO97_ENV lpstEnv);
BOOL O97_OP_DA_REDIM_PRESERVE(LPO97_ENV lpstEnv);
BOOL O97_OP_DB_LITERAL(LPO97_ENV lpstEnv);
BOOL O97_OP_DC_REM(LPO97_ENV lpstEnv);
BOOL O97_OP_DD_RESUME(LPO97_ENV lpstEnv);
BOOL O97_OP_DE(LPO97_ENV lpstEnv);
BOOL O97_OP_DF(LPO97_ENV lpstEnv);
BOOL O97_OP_E0(LPO97_ENV lpstEnv);
BOOL O97_OP_E1(LPO97_ENV lpstEnv);
BOOL O97_OP_E2_SELECT_CASE(LPO97_ENV lpstEnv);
BOOL O97_OP_E3(LPO97_ENV lpstEnv);
BOOL O97_OP_E4(LPO97_ENV lpstEnv);
BOOL O97_OP_E5_SET(LPO97_ENV lpstEnv);
BOOL O97_OP_E6(LPO97_ENV lpstEnv);
BOOL O97_OP_E7(LPO97_ENV lpstEnv);
BOOL O97_OP_E8_TYPE(LPO97_ENV lpstEnv);
BOOL O97_OP_E9(LPO97_ENV lpstEnv);
BOOL O97_OP_EA_SYMBOL_DECL(LPO97_ENV lpstEnv);
BOOL O97_OP_EB_WEND(LPO97_ENV lpstEnv);
BOOL O97_OP_EC_WHILE(LPO97_ENV lpstEnv);
BOOL O97_OP_ED_WITH_A(LPO97_ENV lpstEnv);
BOOL O97_OP_EE_WRITEN_BEGIN(LPO97_ENV lpstEnv);
BOOL O97_OP_EF(LPO97_ENV lpstEnv);
BOOL O97_OP_F0(LPO97_ENV lpstEnv);
BOOL O97_OP_F1(LPO97_ENV lpstEnv);
BOOL O97_OP_F2(LPO97_ENV lpstEnv);
BOOL O97_OP_F3(LPO97_ENV lpstEnv);
BOOL O97_OP_F4(LPO97_ENV lpstEnv);
BOOL O97_OP_F5(LPO97_ENV lpstEnv);
BOOL O97_OP_F6_FOR_NEXT_A(LPO97_ENV lpstEnv);
BOOL O97_OP_F7_FOR_NEXT(LPO97_ENV lpstEnv);
BOOL O97_OP_F8(LPO97_ENV lpstEnv);
BOOL O97_OP_F9_WITH(LPO97_ENV lpstEnv);
BOOL O97_OP_FA(LPO97_ENV lpstEnv);
BOOL O97_OP_FB(LPO97_ENV lpstEnv);
BOOL O97_OP_FC(LPO97_ENV lpstEnv);
BOOL O97_OP_FD(LPO97_ENV lpstEnv);
BOOL O97_OP_FE(LPO97_ENV lpstEnv);
BOOL O97_OP_FF(LPO97_ENV lpstEnv);

LPFNO97_OP gapfnO97_OP[] =
{
    O97_OP_00_IMP,
    O97_OP_01_EQV,
    O97_OP_02_XOR,
    O97_OP_03_OR,
    O97_OP_04_AND,
    O97_OP_05_EQ,
    O97_OP_06_NE,
    O97_OP_07_LE,
    O97_OP_08_GE,
    O97_OP_09_LT,
    O97_OP_0A_GT,
    O97_OP_0B_PLUS,
    O97_OP_0C_MINUS,
    O97_OP_0D_MOD,
    O97_OP_0E_INT_DIV,
    O97_OP_0F_ASTERISK,
    O97_OP_10_SLASH,
    O97_OP_11_AMPERSAND,
    O97_OP_12_LIKE,
    O97_OP_13_CARAT,
    O97_OP_14_IS,
    O97_OP_15_NOT,
    O97_OP_16_NEGATE,
    O97_OP_17_ABS,
    O97_OP_18_FIX,
    O97_OP_19_INT,
    O97_OP_1A_SGN,
    O97_OP_1B_LEN,
    O97_OP_1C_LENB,
    O97_OP_1D_PARENTHESIZE,
    O97_OP_1E,
    O97_OP_1F,
    O97_OP_20_EVAL,
    O97_OP_21_DOT_EVAL,
    O97_OP_22,
    O97_OP_23,
    O97_OP_24_FUNCTION_EVAL,
    O97_OP_25_DOT_FUNCTION_EVAL,
    O97_OP_26,
    O97_OP_27_ASSIGN,
    O97_OP_28_DOT_ASSIGN,
    O97_OP_29,
    O97_OP_2A,
    O97_OP_2B_ASSIGN_FUNCTION,
    O97_OP_2C_ASSIGN_DOT_FUNCTION,
    O97_OP_2D,
    O97_OP_2E_ASSIGN_USING_SET,
    O97_OP_2F_ASSIGN_DOTTED_SET,
    O97_OP_30,
    O97_OP_31,
    O97_OP_32,
    O97_OP_33,
    O97_OP_34,
    O97_OP_35_ROOT_DOT_EVAL,
    O97_OP_36,
    O97_OP_37_ROOT_DOT_FUNCTION_EVAL,
    O97_OP_38,
    O97_OP_39_ASSIGN_ROOT_DOT,
    O97_OP_3A,
    O97_OP_3B_ASSIGN_ROOT_DOT_FUNCTION,
    O97_OP_3C,
    O97_OP_3D,
    O97_OP_3E,
    O97_OP_3F,
    O97_OP_40,
    O97_OP_41_CALL,
    O97_OP_42_DOT_CALL,
    O97_OP_43_ROOT_DOT_CALL,
    O97_OP_44,
    O97_OP_45_COLON,
    O97_OP_46_THEN_ELSE_SINGLE,
    O97_OP_47,
    O97_OP_48_CASE,
    O97_OP_49_CASE_TO,
    O97_OP_4A_CASE_GT,
    O97_OP_4B_CASE_LT,
    O97_OP_4C_CASE_GE,
    O97_OP_4D_CASE_LE,
    O97_OP_4E_CASE_NE,
    O97_OP_4F_CASE_EQ,
    O97_OP_50_CASE_ELSE,
    O97_OP_51_CASE_EOL,
    O97_OP_52,
    O97_OP_53_CLOSE,
    O97_OP_54_CLOSE_ALL,
    O97_OP_55_TYPE_CONVERSION,
    O97_OP_56,
    O97_OP_57,
    O97_OP_58,
    O97_OP_59_DEFTYPE,
    O97_OP_5A_DECLARATION,
    O97_OP_5B_TYPE_ELEMENT,
    O97_OP_5C_DO,
    O97_OP_5D,
    O97_OP_5E_DO_UNTIL,
    O97_OP_5F_DO_WHILE,
    O97_OP_60_ELSE_SINGLE,
    O97_OP_61_ELSE_MULTIPLE,
    O97_OP_62_ELSEIF,
    O97_OP_63,
    O97_OP_64_END,
    O97_OP_65,
    O97_OP_66_END_FUNCTION,
    O97_OP_67_END_SINGLE_IF,
    O97_OP_68_END_IF,
    O97_OP_69,
    O97_OP_6A_END_PROPERTY,
    O97_OP_6B_END_SELECT,
    O97_OP_6C_END_SUB,
    O97_OP_6D_END_TYPE,
    O97_OP_6E_END_WITH,
    O97_OP_6F,
    O97_OP_70,
    O97_OP_71_EXIT_DO,
    O97_OP_72_EXIT_FOR,
    O97_OP_73_EXIT_FUNCTION,
    O97_OP_74_EXIT_PROPERTY,
    O97_OP_75_EXIT_SUB,
    O97_OP_76,
    O97_OP_77,
    O97_OP_78,
    O97_OP_79,
    O97_OP_7A,
    O97_OP_7B,
    O97_OP_7C,
    O97_OP_7D_INSTR_TWO_PARAMS,
    O97_OP_7E_INSTR_THREE_PARAMS,
    O97_OP_7F_INSTR_FOUR_PARAMS,
    O97_OP_80,
    O97_OP_81,
    O97_OP_82,
    O97_OP_83,
    O97_OP_84,
    O97_OP_85,
    O97_OP_86_STRCOMP_A_B,
    O97_OP_87_STRCOMP_A_B_C,
    O97_OP_88,
    O97_OP_89,
    O97_OP_8A,
    O97_OP_8B_B_TO_C,
    O97_OP_8C_EACH_B,
    O97_OP_8D,
    O97_OP_8E_B_TO_C_STEP_D,
    O97_OP_8F_SUB_FUNCTION,
    O97_OP_90,
    O97_OP_91,
    O97_OP_92,
    O97_OP_93_GOTO,
    O97_OP_94_IF_THEN_SINGLE,
    O97_OP_95_IF_THEN_MULTIPLE,
    O97_OP_96,
    O97_OP_97,
    O97_OP_98,
    O97_OP_99,
    O97_OP_9A,
    O97_OP_9B_LABEL,
    O97_OP_9C,
    O97_OP_9D,
    O97_OP_9E_BROKEN_LINE,
    O97_OP_9F,
    O97_OP_A0,
    O97_OP_A1,
    O97_OP_A2,
    O97_OP_A3_NO_LEN,
    O97_OP_A4_WORD,
    O97_OP_A5_DWORD,
    O97_OP_A6_HEX_WORD,
    O97_OP_A7_HEX_DWORD,
    O97_OP_A8_NOTHING,
    O97_OP_A9,
    O97_OP_AA,
    O97_OP_AB,
    O97_OP_AC_DOUBLE,
    O97_OP_AD,
    O97_OP_AE_STRING,
    O97_OP_AF_TRUE_OR_FALSE,
    O97_OP_B0,
    O97_OP_B1_LOOP,
    O97_OP_B2_LOOP_UNTIL,
    O97_OP_B3_LOOP_WHILE,
    O97_OP_B4,
    O97_OP_B5,
    O97_OP_B6_PRINT_BEGIN,
    O97_OP_B7,
    O97_OP_B8,
    O97_OP_B9,
    O97_OP_BA,
    O97_OP_BB,
    O97_OP_BC,
    O97_OP_BD,
    O97_OP_BE_NEW,
    O97_OP_BF_NEXT,
    O97_OP_C0_NEXT_A,
    O97_OP_C1_ON_ERROR_GOTO,
    O97_OP_C2,
    O97_OP_C3,
    O97_OP_C4_OPEN,
    O97_OP_C5_OPTION,
    O97_OP_C6_ARRAY_SIZE,
    O97_OP_C7,
    O97_OP_C8,
    O97_OP_C9_PARAM_ASSIGN,
    O97_OP_CA_PRINTN_BEGIN,
    O97_OP_CB_PRINT_COMMA,
    O97_OP_CC_PRINT_END,
    O97_OP_CD_PRINT_ARG_COMMA,
    O97_OP_CE_PRINT_ARG_END,
    O97_OP_CF_PRINT_ARG_SEMICOLON,
    O97_OP_D0_PRINT_END_NONE,
    O97_OP_D1_PRINT_MID_END_NONE,
    O97_OP_D2_PRINT_SEMICOLON,
    O97_OP_D3_PRINT_SPC_ARG,
    O97_OP_D4_PRINT_TAB_ARG,
    O97_OP_D5_PRINT_TAB,
    O97_OP_D6,
    O97_OP_D7,
    O97_OP_D8_COMMENT,
    O97_OP_D9_REDIM,
    O97_OP_DA_REDIM_PRESERVE,
    O97_OP_DB_LITERAL,
    O97_OP_DC_REM,
    O97_OP_DD_RESUME,
    O97_OP_DE,
    O97_OP_DF,
    O97_OP_E0,
    O97_OP_E1,
    O97_OP_E2_SELECT_CASE,
    O97_OP_E3,
    O97_OP_E4,
    O97_OP_E5_SET,
    O97_OP_E6,
    O97_OP_E7,
    O97_OP_E8_TYPE,
    O97_OP_E9,
    O97_OP_EA_SYMBOL_DECL,
    O97_OP_EB_WEND,
    O97_OP_EC_WHILE,
    O97_OP_ED_WITH_A,
    O97_OP_EE_WRITEN_BEGIN,
    O97_OP_EF,
    O97_OP_F0,
    O97_OP_F1,
    O97_OP_F2,
    O97_OP_F3,
    O97_OP_F4,
    O97_OP_F5,
    O97_OP_F6_FOR_NEXT_A,
    O97_OP_F7_FOR_NEXT,
    O97_OP_F8,
    O97_OP_F9_WITH,
    O97_OP_FA,
    O97_OP_FB,
    O97_OP_FC,
    O97_OP_FD,
    O97_OP_FE,
    O97_OP_FF
};
