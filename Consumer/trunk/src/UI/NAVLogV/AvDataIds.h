// //////////////////////
//
// PROPRIETARY / CONFIDENTIAL.
// Use of this product is subject to license terms.
// Copyright � 2006 Symantec Corporation.
// All rights reserved.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace AV
{
    namespace RecommendedAction
    {
        enum { eInvalid = 0, 
               eRunQuickScan, 
               eRunFullSystemScan, 
               eRemoveNow,
               eDoNothing, 
               eSubmit, 
               eExcludeThreat, 
               eRestore, 
               eDelete, 
               eManualRemovalRequired, 
               eRebootRequired, 
               eLast };
    }


    //****************************************************************************
    //   Elements
    //****************************************************************************

    // {300C45C0-ACA0-45de-BEDA-83A7900F1617}
    SYM_DEFINE_GUID(AVELEMENT_TEMP_MCUI_DETAILS, 
        0x300c45c0, 0xaca0, 0x45de, 0xbe, 0xda, 0x83, 0xa7, 0x90, 0xf, 0x16, 0x17);

    // {5AA6440C-BE86-4382-AF4B-78B8DCBC2E0B}
    SYM_DEFINE_GUID(AVELEMENT_TEMP_MCUI_ADVANCED_DETAILS, 
        0x5aa6440c, 0xbe86, 0x4382, 0xaf, 0x4b, 0x78, 0xb8, 0xdc, 0xbc, 0x2e, 0xb);

    //****************************************************************************
    //   Data
    //****************************************************************************

    // {BD659896-8CB5-43e5-9376-D7B8CB628D5A}
    SYM_DEFINE_GUID(AVDATA_THREATTRACK_ID,
        0xbd659896, 0x8cb5, 0x43e5, 0x93, 0x76, 0xd7, 0xb8, 0xcb, 0x62, 0x8d, 0x5a);

    // {5A002166-E96D-4817-BA3C-379555140F57}
    SYM_DEFINE_GUID(AVDATA_RISK_VID,
        0x5a002166, 0xe96d, 0x4817, 0xba, 0x3c, 0x37, 0x95, 0x55, 0x14, 0xf, 0x57);

    // {002F1D4B-400A-4bc3-82D4-2BAB1B0E8870}
    SYM_DEFINE_GUID(AVDATA_MESSAGE_TYPE,
        0x2f1d4b, 0x400a, 0x4bc3, 0x82, 0xd4, 0x2b, 0xab, 0x1b, 0xe, 0x88, 0x70);

    // {063FF6AF-B1AF-4286-B8D5-D75C510BFFE9}
    SYM_DEFINE_GUID(AVDATA_RISK_NAME,
        0x63ff6af, 0xb1af, 0x4286, 0xb8, 0xd5, 0xd7, 0x5c, 0x51, 0xb, 0xff, 0xe9);

    // {E023E69D-B9AD-46fe-A25C-C1FCA0872CA2}
    SYM_DEFINE_GUID(AVDATA_RISK_CATEGORIES,
        0xe023e69d, 0xb9ad, 0x46fe, 0xa2, 0x5c, 0xc1, 0xfc, 0xa0, 0x87, 0x2c, 0xa2);

    // {188121F2-AEFF-4101-9FE4-D39C547F5B6C}
    SYM_DEFINE_GUID(AVDATA_RISK_CATEGORIES_STRING,
        0x188121f2, 0xaeff, 0x4101, 0x9f, 0xe4, 0xd3, 0x9c, 0x54, 0x7f, 0x5b, 0x6c);

    // {7EFAB549-A487-4b21-AE58-34611F905F04}
    SYM_DEFINE_GUID(AVDATA_PRODUCT_NAME,
        0x7efab549, 0xa487, 0x4b21, 0xae, 0x58, 0x34, 0x61, 0x1f, 0x90, 0x5f, 0x4);

    // {70361771-9EF1-4733-9012-A40A702E13EA}
    SYM_DEFINE_GUID(AVDATA_PRODUCT_VERSION,
        0x70361771, 0x9ef1, 0x4733, 0x90, 0x12, 0xa4, 0xa, 0x70, 0x2e, 0x13, 0xea);

    // {1BD73605-F077-47df-84AD-FCC4F2519865}
    SYM_DEFINE_GUID(AVDATA_COMPONENT_ID,
        0x1bd73605, 0xf077, 0x47df, 0x84, 0xad, 0xfc, 0xc4, 0xf2, 0x51, 0x98, 0x65);

    // {6BD32AD8-07EC-45d1-A536-50453B8F5359}
    SYM_DEFINE_GUID(AVDATA_COMPONENT_NAME,
        0x6bd32ad8, 0x7ec, 0x45d1, 0xa5, 0x36, 0x50, 0x45, 0x3b, 0x8f, 0x53, 0x59);

    // {43080BDB-1F9F-4d36-BBFA-0195F3FC7B73}
    SYM_DEFINE_GUID(AVDATA_COMPONENT_VERSION,
        0x43080bdb, 0x1f9f, 0x4d36, 0xbb, 0xfa, 0x1, 0x95, 0xf3, 0xfc, 0x7b, 0x73);

    // {1E95F8CC-1A87-490d-8278-C1683A343E4C}
    SYM_DEFINE_GUID(AVDATA_ACTION_TAKEN,
        0x1e95f8cc, 0x1a87, 0x490d, 0x82, 0x78, 0xc1, 0x68, 0x3a, 0x34, 0x3e, 0x4c);

    // {C3966AC5-B8EE-4555-906A-BD3492A7F32D}
    SYM_DEFINE_GUID(AVDATA_ACTION_TAKEN_RESULT,
        0xc3966ac5, 0xb8ee, 0x4555, 0x90, 0x6a, 0xbd, 0x34, 0x92, 0xa7, 0xf3, 0x2d);

    // {A4D66170-1311-4927-BB42-A8D10CCF45FF}
    SYM_DEFINE_GUID(AVDATA_THREAT_STATE_NAME,
        0xa4d66170, 0x1311, 0x4927, 0xbb, 0x42, 0xa8, 0xd1, 0xc, 0xcf, 0x45, 0xff);

    // {02A11F7C-5793-4fc6-9238-781648E8384A}
    SYM_DEFINE_GUID(AVDATA_DEFINITIONS_VERSION,
        0x2a11f7c, 0x5793, 0x4fc6, 0x92, 0x38, 0x78, 0x16, 0x48, 0xe8, 0x38, 0x4a);

    // {8EEA36D2-06A3-4188-A24C-020EA07CEA68}
    SYM_DEFINE_GUID(AVDATA_ERASER_VERSION,
        0x8eea36d2, 0x6a3, 0x4188, 0xa2, 0x4c, 0x2, 0xe, 0xa0, 0x7c, 0xea, 0x68);

    // {DED61BE1-A1AD-4478-8B8E-9587112D21AC}
    SYM_DEFINE_GUID(AVDATA_OBJECT_TYPE_ID,
        0xded61be1, 0xa1ad, 0x4478, 0x8b, 0x8e, 0x95, 0x87, 0x11, 0x2d, 0x21, 0xac);

    // {299A7031-6C5B-4ab7-BDB8-6223B0D44ACA}
    SYM_DEFINE_GUID(AVDATA_OBJECT_TYPE_NAME,
        0x299a7031, 0x6c5b, 0x4ab7, 0xbd, 0xb8, 0x62, 0x23, 0xb0, 0xd4, 0x4a, 0xca);

    // {4722FCFE-D170-4b0b-92EF-E8B83448B9A7}
    SYM_DEFINE_GUID(AVDATA_THREAT_DEPENDENCIES,
        0x4722fcfe, 0xd170, 0x4b0b, 0x92, 0xef, 0xe8, 0xb8, 0x34, 0x48, 0xb9, 0xa7);

    // {2185CD37-4467-4a24-BA1C-57612EE3E27E}
    SYM_DEFINE_GUID(AVDATA_REMEDIATION_RECOMMENDATION,
        0x2185cd37, 0x4467, 0x4a24, 0xba, 0x1c, 0x57, 0x61, 0x2e, 0xe3, 0xe2, 0x7e);

    // {3B5543A1-960E-43d9-A9CA-629D991327E2}
    SYM_DEFINE_GUID(AVDATA_USER_NAME,
        0x3b5543a1, 0x960e, 0x43d9, 0xa9, 0xca, 0x62, 0x9d, 0x99, 0x13, 0x27, 0xe2);

    // {D728E055-8282-4386-8299-BE61A8051A02}
    SYM_DEFINE_GUID(AVDATA_FILE_NAME,
        0xd728e055, 0x8282, 0x4386, 0x82, 0x99, 0xbe, 0x61, 0xa8, 0x5, 0x1a, 0x2);

    // {5AA25614-61FD-440a-B498-B2ABE5C774FF}
    SYM_DEFINE_GUID(AVDATA_FILE_DESC,
        0x5aa25614, 0x61fd, 0x440a, 0xb4, 0x98, 0xb2, 0xab, 0xe5, 0xc7, 0x74, 0xff);

    // {AB4BCC15-60BD-4768-9517-4A19A7F351C7}
    SYM_DEFINE_GUID(AVDATA_RESPONSE_THREATINFO_URL,
        0xab4bcc15, 0x60bd, 0x4768, 0x95, 0x17, 0x4a, 0x19, 0xa7, 0xf3, 0x51, 0xc7);

    // {24FA20E5-E7CE-4f33-A47E-95F0E36F5871}
    SYM_DEFINE_GUID(AVDATA_THREAT_MATRIX_OVERALL,
        0x24fa20e5, 0xe7ce, 0x4f33, 0xa4, 0x7e, 0x95, 0xf0, 0xe3, 0x6f, 0x58, 0x71);

    // {7B4FF7B4-41A7-4dc2-8D2C-6D0876D989CE}
    SYM_DEFINE_GUID(AVDATA_THREAT_MATRIX_OVERALL_STRING,
        0x7b4ff7b4, 0x41a7, 0x4dc2, 0x8d, 0x2c, 0x6d, 0x8, 0x76, 0xd9, 0x89, 0xce);

    // {FD174FDB-0114-40d7-95B9-CCF8F9042575}
    SYM_DEFINE_GUID(AVDATA_THREAT_MATRIX_PERFORMANCE,
        0xfd174fdb, 0x114, 0x40d7, 0x95, 0xb9, 0xcc, 0xf8, 0xf9, 0x4, 0x25, 0x75);

    // {B0D96B87-D80D-4e5d-8A41-18B7016EE4C0}
    SYM_DEFINE_GUID(AVDATA_THREAT_MATRIX_PRIVACY,
        0xb0d96b87, 0xd80d, 0x4e5d, 0x8a, 0x41, 0x18, 0xb7, 0x1, 0x6e, 0xe4, 0xc0);

    // {F3C44C3C-85DD-4e9e-B3AC-64895031AF83}
    SYM_DEFINE_GUID(AVDATA_THREAT_MATRIX_REMOVAL,
        0xf3c44c3c, 0x85dd, 0x4e9e, 0xb3, 0xac, 0x64, 0x89, 0x50, 0x31, 0xaf, 0x83);

    // {83124380-0BC8-403b-8201-CC8765A36FE2}
    SYM_DEFINE_GUID(AVDATA_THREAT_MATRIX_STEALTH,
        0x83124380, 0xbc8, 0x403b, 0x82, 0x1, 0xcc, 0x87, 0x65, 0xa3, 0x6f, 0xe2);

    // {66F2F613-684C-4f77-839B-63DB6C1144DF}
    SYM_DEFINE_GUID(AVDATA_SCANRESULTS_MBRs_REPAIRED,
        0x66f2f613, 0x684c, 0x4f77, 0x83, 0x9b, 0x63, 0xdb, 0x6c, 0x11, 0x44, 0xdf);

    // {5D5656F5-9DCE-4bd3-8811-8CEF8D4408CC}
    SYM_DEFINE_GUID(AVDATA_SCANRESULTS_TASK_NAME,
        0x5d5656f5, 0x9dce, 0x4bd3, 0x88, 0x11, 0x8c, 0xef, 0x8d, 0x44, 0x8, 0xcc);

    // {2995D2B9-6D07-46ba-B112-4152DC58F7E2}
    SYM_DEFINE_GUID(AVDATA_SCANRESULTS_MBRs_TOTAL_INFECTED,
        0x2995d2b9, 0x6d07, 0x46ba, 0xb1, 0x12, 0x41, 0x52, 0xdc, 0x58, 0xf7, 0xe2);

    // {4A5B9ADD-2804-4b2f-B46E-B0C171AEEFC5}
    SYM_DEFINE_GUID(AVDATA_SCANRESULTS_MBRs_TOTAL_SCANNED,
        0x4a5b9add, 0x2804, 0x4b2f, 0xb4, 0x6e, 0xb0, 0xc1, 0x71, 0xae, 0xef, 0xc5);

    // {462DB509-91A4-4c32-9BFB-062F91377630}
    SYM_DEFINE_GUID(AVDATA_SCANRESULTS_BOOT_RECS_REPAIRED,
        0x462db509, 0x91a4, 0x4c32, 0x9b, 0xfb, 0x6, 0x2f, 0x91, 0x37, 0x76, 0x30);

    // {8C258EB2-9556-4093-ACBA-9A40F0D5C194}
    SYM_DEFINE_GUID(AVDATA_SCANRESULTS_BOOT_RECS_TOTAL_INFECTED,
        0x8c258eb2, 0x9556, 0x4093, 0xac, 0xba, 0x9a, 0x40, 0xf0, 0xd5, 0xc1, 0x94);

    // {CD3E2D64-7864-46ce-BA58-76FFDC05B087}
    SYM_DEFINE_GUID(AVDATA_SCANRESULTS_BOOT_RECS_TOTAL_SCANNED,
        0xcd3e2d64, 0x7864, 0x46ce, 0xba, 0x58, 0x76, 0xff, 0xdc, 0x5, 0xb0, 0x87);

    // {7FAB920B-CDA1-40d9-B6C5-9A7D4578BC99}
    SYM_DEFINE_GUID(AVDATA_SCANRESULTS_FILES_REPAIRED,
        0x7fab920b, 0xcda1, 0x40d9, 0xb6, 0xc5, 0x9a, 0x7d, 0x45, 0x78, 0xbc, 0x99);

    // {E50EE968-4F00-4843-8604-518C63D068AC}
    SYM_DEFINE_GUID(AVDATA_SCANRESULTS_FILES_QUARANTINED,
        0xe50ee968, 0x4f00, 0x4843, 0x86, 0x4, 0x51, 0x8c, 0x63, 0xd0, 0x68, 0xac);

    // {978AA2ED-E874-47e8-B959-AC52BF018C09}
    SYM_DEFINE_GUID(AVDATA_SCANRESULTS_FILES_DELETED,
        0x978aa2ed, 0xe874, 0x47e8, 0xb9, 0x59, 0xac, 0x52, 0xbf, 0x1, 0x8c, 0x9);

    // {9A8244FE-8CC7-44e1-A209-592A3B1E5AE4}
    SYM_DEFINE_GUID(AVDATA_SCANRESULTS_FILES_TOTAL_INFECTED,
        0x9a8244fe, 0x8cc7, 0x44e1, 0xa2, 0x9, 0x59, 0x2a, 0x3b, 0x1e, 0x5a, 0xe4);

    // {CEEC4698-4D63-4511-9E57-74542A003527}
    SYM_DEFINE_GUID(AVDATA_SCANRESULTS_FILES_TOTAL_SCANNED,
        0xceec4698, 0x4d63, 0x4511, 0x9e, 0x57, 0x74, 0x54, 0x2a, 0x0, 0x35, 0x27);

    // {B986907E-C6F8-4ebe-A614-73C8CAE250E8}
    SYM_DEFINE_GUID(AVDATA_SCANRESULTS_FILES_EXCLUDED,
        0xb986907e, 0xc6f8, 0x4ebe, 0xa6, 0x14, 0x73, 0xc8, 0xca, 0xe2, 0x50, 0xe8);

	// {9E9FD4A0-2F50-4fc9-A045-8DC3748A24B5}
	SYM_DEFINE_GUID(AVDATA_SCANRESULTS_VIRUSES_DETECTED,
		0x9e9fd4a0, 0x2f50, 0x4fc9, 0xa0, 0x45, 0x8d, 0xc3, 0x74, 0x8a, 0x24, 0xb5);

	// {877D0DB3-518A-4988-B250-6D6B7A064929}
	SYM_DEFINE_GUID(AVDATA_SCANRESULTS_VIRUSES_REMOVED,
		0x877d0db3, 0x518a, 0x4988, 0xb2, 0x50, 0x6d, 0x6b, 0x7a, 0x6, 0x49, 0x29);

	// {CFD11F69-A3B8-4ac5-B4C6-A729F5FE6A87}
	SYM_DEFINE_GUID(AVDATA_SCANRESULTS_NONVIRUSES_DETECTED,
		0xcfd11f69, 0xa3b8, 0x4ac5, 0xb4, 0xc6, 0xa7, 0x29, 0xf5, 0xfe, 0x6a, 0x87);

	// {0F1BECE0-F274-41cd-AB6D-A9E053C39D66}
	SYM_DEFINE_GUID(AVDATA_SCANRESULTS_NONVIRUSES_REMOVED,
		0xf1bece0, 0xf274, 0x41cd, 0xab, 0x6d, 0xa9, 0xe0, 0x53, 0xc3, 0x9d, 0x66);

	// {B5994838-3FF7-430c-BF42-75A9D325DC7C}
	SYM_DEFINE_GUID(AVDATA_SCANRESULTS_ITEMS_TOTAL_SCANNED,
		0xb5994838, 0x3ff7, 0x430c, 0xbf, 0x42, 0x75, 0xa9, 0xd3, 0x25, 0xdc, 0x7c);

    // {AB9AEE91-BF72-44d3-9F28-8DE7E45D2BB1}
    SYM_DEFINE_GUID(AVDATA_SCANRESULTS_SCAN_TIME,
        0xab9aee91, 0xbf72, 0x44d3, 0x9f, 0x28, 0x8d, 0xe7, 0xe4, 0x5d, 0x2b, 0xb1);

    // {4D3E5A39-855E-4f62-A071-5EAA8C33C05E}
    SYM_DEFINE_GUID(AVDATA_EMAIL_SUBJECT,
        0x4d3e5a39, 0x855e, 0x4f62, 0xa0, 0x71, 0x5e, 0xaa, 0x8c, 0x33, 0xc0, 0x5e);

    // {E9497E61-17D8-4f2a-8E2A-21BA6CF5C679}
    SYM_DEFINE_GUID(AVDATA_EMAIL_SENDER,
        0xe9497e61, 0x17d8, 0x4f2a, 0x8e, 0x2a, 0x21, 0xba, 0x6c, 0xf5, 0xc6, 0x79);

    // {AAB2E245-9DF8-47cf-B013-67A529982ED7}
    SYM_DEFINE_GUID(AVDATA_EMAIL_RECIPIENT,
        0xaab2e245, 0x9df8, 0x47cf, 0xb0, 0x13, 0x67, 0xa5, 0x29, 0x98, 0x2e, 0xd7);

    // {084BCC75-92D0-451f-8DEB-0A5514A7ADA9}
    SYM_DEFINE_GUID(AVDATA_SUPPORTS_DELETE_ITEM,
        0x84bcc75, 0x92d0, 0x451f, 0x8d, 0xeb, 0xa, 0x55, 0x14, 0xa7, 0xad, 0xa9);

    // {09680F86-EF1B-49c3-88BD-0560B0FCEE34}
    SYM_DEFINE_GUID(AVDATA_SUPPORTS_DELETE_DATA,
        0x9680f86, 0xef1b, 0x49c3, 0x88, 0xbd, 0x5, 0x60, 0xb0, 0xfc, 0xee, 0x34);

    // {57DDB321-C092-4a40-8AFB-8E8EA395BCA2}
    SYM_DEFINE_GUID(AVDATA_SUPPORTS_RESTORE,
        0x57ddb321, 0xc092, 0x4a40, 0x8a, 0xfb, 0x8e, 0x8e, 0xa3, 0x95, 0xbc, 0xa2);

    // {763E6556-2556-4de0-B4BA-9F3BAE075BFC}
    SYM_DEFINE_GUID(AVDATA_SUPPORTS_SUBMISSION,
        0x763e6556, 0x2556, 0x4de0, 0xb4, 0xba, 0x9f, 0x3b, 0xae, 0x7, 0x5b, 0xfc);

    // {ED17A2EB-C7EA-44ec-8716-8624C938E5B2}
    SYM_DEFINE_GUID(AVDATA_SUPPORTS_REMOVENOW,
        0xed17a2eb, 0xc7ea, 0x44ec, 0x87, 0x16, 0x86, 0x24, 0xc9, 0x38, 0xe5, 0xb2);

    // {2E501EFC-242C-49da-95E5-3B58E9867FFD}
    SYM_DEFINE_GUID(AVDATA_SUPPORTS_QUICKSCAN,
        0x2e501efc, 0x242c, 0x49da, 0x95, 0xe5, 0x3b, 0x58, 0xe9, 0x86, 0x7f, 0xfd);

    // {2D9BA95D-6C09-4e39-AD16-9B87C701EECC}
    SYM_DEFINE_GUID(AVDATA_SUPPORTS_EXCLUDE,
        0x2d9ba95d, 0x6c09, 0x4e39, 0xad, 0x16, 0x9b, 0x87, 0xc7, 0x1, 0xee, 0xcc);

	// {AE598C1A-F4A7-4560-A401-2837FA50386D}
    SYM_DEFINE_GUID(AVDATA_SUPPORTS_VIEW_DETAILS,
		0xae598c1a, 0xf4a7, 0x4560, 0xa4, 0x1, 0x28, 0x37, 0xfa, 0x50, 0x38, 0x6d);

    // {473181EC-3B62-4ef8-9E04-AF5C4D858EEF}
    SYM_DEFINE_GUID(AVDATA_SHOW_AUTOPROTECT_OPTIONS,
        0x473181ec, 0x3b62, 0x4ef8, 0x9e, 0x4, 0xaf, 0x5c, 0x4d, 0x85, 0x8e, 0xef);

    // {1E81F6B0-8796-4f7c-97A2-B781780AD9EB}
    SYM_DEFINE_GUID(AVDATA_SHOW_MANUAL_SCAN_OPTIONS,
        0x1e81f6b0, 0x8796, 0x4f7c, 0x97, 0xa2, 0xb7, 0x81, 0x78, 0xa, 0xd9, 0xeb);

    // {586868E6-6487-431e-9C09-3F42DE35A6EC}
    SYM_DEFINE_GUID(AVDATA_SHOW_EMAIL_SCAN_OPTIONS,
        0x586868e6, 0x6487, 0x431e, 0x9c, 0x9, 0x3f, 0x42, 0xde, 0x35, 0xa6, 0xec);

    // {BA9F4B3E-AEFF-4f06-A08C-FFEB64BEF65C}
    SYM_DEFINE_GUID(AVDATA_SHOW_EXCLUSION_OPTIONS,
        0xba9f4b3e, 0xaeff, 0x4f06, 0xa0, 0x8c, 0xff, 0xeb, 0x64, 0xbe, 0xf6, 0x5c);

	// {752626EA-E604-43df-BDB8-4FB3019485B3}
    SYM_DEFINE_GUID(AVDATA_SUPPORTS_REVIEW_RISK_DETAILS,
		0x752626ea, 0xe604, 0x43df, 0xbd, 0xb8, 0x4f, 0xb3, 0x1, 0x94, 0x85, 0xb3);

    // {AA51F992-5F21-4a65-896E-93CD40776D1C}
    SYM_DEFINE_GUID(AVDATA_SUPPORTS_HELP_AND_SUPPORT,
        0xaa51f992, 0x5f21, 0x4a65, 0x89, 0x6e, 0x93, 0xcd, 0x40, 0x77, 0x6d, 0x1c);

    // {A6D7396B-2B31-4d7c-8D4C-70161D53E50E}
    SYM_DEFINE_GUID(AVDATA_SUPPORTS_OPTIONS,
        0xa6d7396b, 0x2b31, 0x4d7c, 0x8d, 0x4c, 0x70, 0x16, 0x1d, 0x53, 0xe5, 0xe);

    // {FFDDC3CE-493B-4505-BDE8-0A76047E4F09}
    SYM_DEFINE_GUID(AVDATA_HAS_NO_ACTIONS,
        0xffddc3ce, 0x493b, 0x4505, 0xbd, 0xe8, 0xa, 0x76, 0x4, 0x7e, 0x4f, 0x9);

    // {A936D9F4-7E44-421b-8FBD-0BAA123564B3}
    SYM_DEFINE_GUID(AVDATA_RECOMMENDED_ACTION,
        0xa936d9f4, 0x7e44, 0x421b, 0x8f, 0xbd, 0xb, 0xaa, 0x12, 0x35, 0x64, 0xb3);

	// {46EA4ACD-D729-4a02-85F0-8AB28DF47FF7}
	SYM_DEFINE_GUID(AVDATA_FILE_LIST,
		0x46ea4acd, 0xd729, 0x4a02, 0x85, 0xf0, 0x8a, 0xb2, 0x8d, 0xf4, 0x7f, 0xf7);

    // {9E658130-314A-41b0-B45B-9AE36007E45A}
    SYM_DEFINE_GUID(AVDATA_HEURISTIC_RANK_STRING,
        0x9e658130, 0x314a, 0x41b0, 0xb4, 0x5b, 0x9a, 0xe3, 0x60, 0x7, 0xe4, 0x5a);

    // {37914999-08FF-4d5d-877E-7D68ECE65701}
    SYM_DEFINE_GUID(AVDATA_ERASERSTAT_REGISTRY_DETECTION_ACTION,
        0x37914999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x01);

    // {37914999-08FF-4d5d-877E-7D68ECE65702}
    SYM_DEFINE_GUID(AVDATA_ERASERSTAT_FILE_DETECTION_ACTION,
        0x37914999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x02);

    // {37914999-08FF-4d5d-877E-7D68ECE65703}
    SYM_DEFINE_GUID(AVDATA_ERASERSTAT_PROCESS_DETECTION_ACTION,
        0x37914999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x03);

    // {37914999-08FF-4d5d-877E-7D68ECE65704}
    SYM_DEFINE_GUID(AVDATA_ERASERSTAT_BATCH_DETECTION_ACTION,
        0x37914999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x04);

    // {37914999-08FF-4d5d-877E-7D68ECE65705}
    SYM_DEFINE_GUID(AVDATA_ERASERSTAT_INI_DETECTION_ACTION,
        0x37914999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x05);

    // {37914999-08FF-4d5d-877E-7D68ECE65706}
    SYM_DEFINE_GUID(AVDATA_ERASERSTAT_SERVICE_DETECTION_ACTION,
        0x37914999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x06);

    // {37914999-08FF-4d5d-877E-7D68ECE65707}
    SYM_DEFINE_GUID(AVDATA_ERASERSTAT_STARTUP_DETECTION_ACTION,
        0x37914999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x07);

    // {37914999-08FF-4d5d-877E-7D68ECE65708}
    SYM_DEFINE_GUID(AVDATA_ERASERSTAT_COM_DETECTION_ACTION,
        0x37914999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x08);

    // {37914999-08FF-4d5d-877E-7D68ECE65709}
    SYM_DEFINE_GUID(AVDATA_ERASERSTAT_HOSTS_DETECTION_ACTION,
        0x37914999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x09);

    // {37914999-08FF-4d5d-877E-7D68ECE65710}
    SYM_DEFINE_GUID(AVDATA_ERASERSTAT_DIRECTORY_DETECTION_ACTION,
        0x37914999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x10);

    // {37914999-08FF-4d5d-877E-7D68ECE65711}
    SYM_DEFINE_GUID(AVDATA_ERASERSTAT_LSP_DETECTION_ACTION,
        0x37914999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x11);

    // {37914999-08FF-4d5d-877E-7D68ECE65712}
    SYM_DEFINE_GUID(AVDATA_ERASERSTAT_BROWSER_CACHE_DETECTION_ACTION,
        0x37914999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x12);

    // {37914999-08FF-4d5d-877E-7D68ECE65713}
    SYM_DEFINE_GUID(AVDATA_ERASERSTAT_COOKIE_DETECTION_ACTION,
        0x37914999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x13);

    // {37914999-08FF-4d5d-877E-7D68ECE657014}
    SYM_DEFINE_GUID(AVDATA_ERASERSTAT_APPHEURISTIC_DETECTION_ACTION,
        0x37914999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x14);

    // {44444999-08FF-4d5d-877E-7D68ECE657001}
    SYM_DEFINE_GUID(AVDATA_RESOLVEDSTATS_VIRAL,
        0x44444999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x01);

    // {44444999-08FF-4d5d-877E-7D68ECE657002}
    SYM_DEFINE_GUID(AVDATA_RESOLVEDSTATS_MALICIOUS,
        0x44444999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x02);

    // {44444999-08FF-4d5d-877E-7D68ECE657003}
    SYM_DEFINE_GUID(AVDATA_RESOLVEDSTATS_RESERVED_MALICIOUS,
        0x44444999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x03);

    // {44444999-08FF-4d5d-877E-7D68ECE657004}
    SYM_DEFINE_GUID(AVDATA_RESOLVEDSTATS_HEURISTIC,
        0x44444999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x04);

    // {44444999-08FF-4d5d-877E-7D68ECE657005}
    SYM_DEFINE_GUID(AVDATA_RESOLVEDSTATS_SECURITY_RISK,
        0x44444999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x05);

    // {44444999-08FF-4d5d-877E-7D68ECE657006}
    SYM_DEFINE_GUID(AVDATA_RESOLVEDSTATS_HACKTOOL,
        0x44444999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x06);

    // {44444999-08FF-4d5d-877E-7D68ECE657007}
    SYM_DEFINE_GUID(AVDATA_RESOLVEDSTATS_SPYWARE,
        0x44444999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x07);

    // {44444999-08FF-4d5d-877E-7D68ECE657008}
    SYM_DEFINE_GUID(AVDATA_RESOLVEDSTATS_TRACKWARE,
        0x44444999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x08);

    // {44444999-08FF-4d5d-877E-7D68ECE657009}
    SYM_DEFINE_GUID(AVDATA_RESOLVEDSTATS_DIALER,
        0x44444999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x09);

    // {44444999-08FF-4d5d-877E-7D68ECE657010}
    SYM_DEFINE_GUID(AVDATA_RESOLVEDSTATS_REMOTE_ACCESS,
        0x44444999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x10);

    // {44444999-08FF-4d5d-877E-7D68ECE657011}
    SYM_DEFINE_GUID(AVDATA_RESOLVEDSTATS_ADWARE,
        0x44444999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x11);

    // {44444999-08FF-4d5d-877E-7D68ECE657012}
    SYM_DEFINE_GUID(AVDATA_RESOLVEDSTATS_JOKE,
        0x44444999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x12);

    // {44444999-08FF-4d5d-877E-7D68ECE657013}
    SYM_DEFINE_GUID(AVDATA_RESOLVEDSTATS_CLIENT_COMPLIANCY,
        0x44444999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x13);

    // {44444999-08FF-4d5d-877E-7D68ECE657014}
    SYM_DEFINE_GUID(AVDATA_RESOLVEDSTATS_GLP,
        0x44444999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x14);

    // {44444999-08FF-4d5d-877E-7D68ECE657015}
    SYM_DEFINE_GUID(AVDATA_RESOLVEDSTATS_APPHEURISTIC,
        0x44444999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x15);

    // {44444999-08FF-4d5d-877E-7D68ECE657016}
    SYM_DEFINE_GUID(AVDATA_RESOLVEDSTATS_COOKIE,
        0x44444999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x16);

    // {55554999-08FF-4d5d-877E-7D68ECE657001}
    SYM_DEFINE_GUID(AVDATA_UNRESOLVEDSTATS_VIRAL,
        0x55554999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x01);

    // {55554999-08FF-4d5d-877E-7D68ECE657002}
    SYM_DEFINE_GUID(AVDATA_UNRESOLVEDSTATS_MALICIOUS,
        0x55554999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x02);

    // {55554999-08FF-4d5d-877E-7D68ECE657003}
    SYM_DEFINE_GUID(AVDATA_UNRESOLVEDSTATS_RESERVED_MALICIOUS,
        0x55554999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x03);

    // {55554999-08FF-4d5d-877E-7D68ECE657004}
    SYM_DEFINE_GUID(AVDATA_UNRESOLVEDSTATS_HEURISTIC,
        0x55554999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x04);

    // {55554999-08FF-4d5d-877E-7D68ECE657005}
    SYM_DEFINE_GUID(AVDATA_UNRESOLVEDSTATS_SECURITY_RISK,
        0x55554999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x05);

    // {55554999-08FF-4d5d-877E-7D68ECE657006}
    SYM_DEFINE_GUID(AVDATA_UNRESOLVEDSTATS_HACKTOOL,
        0x55554999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x06);

    // {55554999-08FF-4d5d-877E-7D68ECE657007}
    SYM_DEFINE_GUID(AVDATA_UNRESOLVEDSTATS_SPYWARE,
        0x55554999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x07);

    // {55554999-08FF-4d5d-877E-7D68ECE657008}
    SYM_DEFINE_GUID(AVDATA_UNRESOLVEDSTATS_TRACKWARE,
        0x55554999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x08);

    // {55554999-08FF-4d5d-877E-7D68ECE657009}
    SYM_DEFINE_GUID(AVDATA_UNRESOLVEDSTATS_DIALER,
        0x55554999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x09);

    // {55554999-08FF-4d5d-877E-7D68ECE657010}
    SYM_DEFINE_GUID(AVDATA_UNRESOLVEDSTATS_REMOTE_ACCESS,
        0x55554999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x10);

    // {55554999-08FF-4d5d-877E-7D68ECE657011}
    SYM_DEFINE_GUID(AVDATA_UNRESOLVEDSTATS_ADWARE,
        0x55554999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x11);

    // {55554999-08FF-4d5d-877E-7D68ECE657012}
    SYM_DEFINE_GUID(AVDATA_UNRESOLVEDSTATS_JOKE,
        0x55554999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x12);

    // {55554999-08FF-4d5d-877E-7D68ECE657013}
    SYM_DEFINE_GUID(AVDATA_UNRESOLVEDSTATS_CLIENT_COMPLIANCY,
        0x55554999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x13);

    // {55554999-08FF-4d5d-877E-7D68ECE657014}
    SYM_DEFINE_GUID(AVDATA_UNRESOLVEDSTATS_GLP,
        0x55554999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x14);

    // {55554999-08FF-4d5d-877E-7D68ECE657015}
    SYM_DEFINE_GUID(AVDATA_UNRESOLVEDSTATS_APPHEURISTIC,
        0x55554999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x15);

    // {55554999-08FF-4d5d-877E-7D68ECE657016}
    SYM_DEFINE_GUID(AVDATA_UNRESOLVEDSTATS_COOKIE,
        0x55554999, 0x8ff, 0x4d5d, 0x87, 0x7e, 0x7d, 0x68, 0xec, 0xe6, 0x57, 0x16);

	// {8D253225-D38D-44af-8E32-474E3806A214}
	SYM_DEFINE_GUID(AVDATA_USER_SID_STRING,
		0x8d253225, 0xd38d, 0x44af, 0x8e, 0x32, 0x47, 0x4e, 0x38, 0x6, 0xa2, 0x14);

};