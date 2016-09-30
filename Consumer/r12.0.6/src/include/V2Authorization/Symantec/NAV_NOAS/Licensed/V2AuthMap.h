// V2AuthMap.h
// 
//////////////////////////////////////////////////////////////////////
#ifndef _V2AUTHMAP_H__42FBCCE5_38D1_43af_917A_3DAA144965C5__INCLUDED_
#define _V2AUTHMAP_H__42FBCCE5_38D1_43af_917A_3DAA144965C5__INCLUDED_


#include "V2LicensingAuthGuids.h"
namespace V2AuthMap
{

// V2 AUTHORIZATION// V2 AUTHORIZATION// V2 AUTHORIZATION// V2 AUTHORIZATION// V2 AUTHORIZATION
AUTHORIZATION_MAP_BEGIN(ThisObjectAuthorizationMap)
	AUTHORIZATION_MAP_ENTRY(V2LicensingAuthGuids::GUID_Licensed)
	AUTHORIZATION_MAP_ENTRY(V2LicensingAuthGuids::GUID_SuiteOwner)
	AUTHORIZATION_MAP_ENTRY(V2LicensingAuthGuids::GUID_NAVNOAS_ProductLine_Current)
AUTHORIZATION_MAP_END()

AUTHORIZATION_MAP_BEGIN(ThatObjectAuthorizationMap)
	AUTHORIZATION_MAP_ENTRY(V2LicensingAuthGuids::GUID_Licensed)
	AUTHORIZATION_MAP_ENTRY(V2LicensingAuthGuids::GUID_NAVNOAS_ProductLine_Current)
AUTHORIZATION_MAP_END()

AUTHORIZATION_MAP_BEGIN(PartnerObjectAuthorizationMap)
	AUTHORIZATION_MAP_ENTRY(V2LicensingAuthGuids::GUID_Licensed)
AUTHORIZATION_MAP_END()
CONST TCHAR szPartner[] = _T("AVRES.dll");


// V2 AUTHORIZATION// V2 AUTHORIZATION// V2 AUTHORIZATION// V2 AUTHORIZATION// V2 AUTHORIZATION
}//V2AuthMap


#endif //_V2AUTHMAP_H__42FBCCE5_38D1_43af_917A_3DAA144965C5__INCLUDED_