/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_TO_C_CONV2
 *** Description: Template for a Simple Function Block Type
 *** Version: 
 ***     1.0: 2018-12-03/badger - null - 
 *************************************************************************/

#include "F_TO_C_CONV2.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_TO_C_CONV2_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_TO_C_CONV2, g_nStringIdF_TO_C_CONV2)

const CStringDictionary::TStringId FORTE_F_TO_C_CONV2::scm_anDataInputNames[] = {g_nStringIdtemp_F, g_nStringIdTI};

const CStringDictionary::TStringId FORTE_F_TO_C_CONV2::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_F_TO_C_CONV2::scm_anDataOutputNames[] = {g_nStringIdtemp_C};

const CStringDictionary::TStringId FORTE_F_TO_C_CONV2::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_F_TO_C_CONV2::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_TO_C_CONV2::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_TO_C_CONV2::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_TO_C_CONV2::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_TO_C_CONV2::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_F_TO_C_CONV2::scm_anEventOutputNames[] = {g_nStringIdERROR, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_TO_C_CONV2::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

using std::cout;
using std::string;

void FORTE_F_TO_C_CONV2::alg_REQ(void){
	temp_C() = ((temp_F() - 32)) * 5 / 9;
	//cout << "F_TO_CONV temp_C = " << temp_C() << "\n";
	if (temp_C() < -273.15) {
		sendOutputEvent(scm_nEventERRORID);
	} else {
		sendOutputEvent(scm_nEventCNFID);
	}
}



