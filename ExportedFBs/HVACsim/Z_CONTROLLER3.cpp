/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Z_CONTROLLER3
 *** Description: HVAC Zone temperature panel controller
 *** Version: 
 ***     1.0: 2020-01-14/badger - null - 
 *************************************************************************/

#include "Z_CONTROLLER3.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Z_CONTROLLER3_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Z_CONTROLLER3, g_nStringIdZ_CONTROLLER3)

const CStringDictionary::TStringId FORTE_Z_CONTROLLER3::scm_anDataInputNames[] = {g_nStringIdtemp_C, g_nStringIderror_code, g_nStringIdTI};

const CStringDictionary::TStringId FORTE_Z_CONTROLLER3::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdINT, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_Z_CONTROLLER3::scm_anDataOutputNames[] = {g_nStringIdzone_temp, g_nStringIdset_zone_temp, g_nStringIdzone_msg};

const CStringDictionary::TStringId FORTE_Z_CONTROLLER3::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdSTRING};

const TForteInt16 FORTE_Z_CONTROLLER3::scm_anEIWithIndexes[] = {-1, -1, 0, -1, -1, 2};
const TDataIOID FORTE_Z_CONTROLLER3::scm_anEIWith[] = {0, 255, 1, 255};
const CStringDictionary::TStringId FORTE_Z_CONTROLLER3::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdCYCLE, g_nStringIdTEMP, g_nStringIdCMD_UP, g_nStringIdCMD_DOWN, g_nStringIdERROR};

const TDataIOID FORTE_Z_CONTROLLER3::scm_anEOWith[] = {0, 255, 1, 255, 2, 255};
const TForteInt16 FORTE_Z_CONTROLLER3::scm_anEOWithIndexes[] = {-1, 0, 2, 4, -1};
const CStringDictionary::TStringId FORTE_Z_CONTROLLER3::scm_anEventOutputNames[] = {g_nStringIdGET_TEMP, g_nStringIdCNF_TEMP, g_nStringIdCNF_SET_TEMP, g_nStringIdCNF_MSG};

const CStringDictionary::TStringId FORTE_Z_CONTROLLER3::scm_anInternalsNames[] = {g_nStringIdZONE_TEMPERATURE, g_nStringIdZONE_SET_TEMPERATURE};

const CStringDictionary::TStringId FORTE_Z_CONTROLLER3::scm_anInternalsTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_Z_CONTROLLER3::scm_stFBInterfaceSpec = {
  6,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  4,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

const SInternalVarsInformation FORTE_Z_CONTROLLER3::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_Z_CONTROLLER3::alg_initialize(void){
	cout << "[Z_CONTROLLER3] alg_initialize()\n";
	// Set default room temperature and zone temperature
	zone_temp() = 18.0;
	set_zone_temp() = 15.0;
	zone_msg() = "Room controller operating";
}

void FORTE_Z_CONTROLLER3::alg_normalOperation(void){
//	cout <<  "[Z_CONTROLLER3] alg_normalOperation\n";
}

void FORTE_Z_CONTROLLER3::alg_temperatureChanged(void){
//	cout << "[Z_CONTROLLER3] alg_temperatureChanged\n";
	zone_temp() = temp_C();
}

void FORTE_Z_CONTROLLER3::alg_increaseSetTemperature(void){
//	cout << "[Z_CONTROLLER3] alg_increaseSetTemperature\n";
	set_zone_temp() = set_zone_temp() + (float) 1.0;
}

void FORTE_Z_CONTROLLER3::alg_decreaseSetTemperature(void){
//	cout << "[Z_CONTROLLER3] alg_decreaseSetTemperature\n";
	set_zone_temp() = set_zone_temp() - (float) 1.0;
}

void FORTE_Z_CONTROLLER3::alg_CYCLE(void){
}

void FORTE_Z_CONTROLLER3::alg_displayError(void){
//	cout << zone_msg().getValue() << "\n";
}

void FORTE_Z_CONTROLLER3::enterStateSTART(void){
	m_nECCState = scm_nStateSTART;
}

void FORTE_Z_CONTROLLER3::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_initialize();
  sendOutputEvent( scm_nEventCNF_TEMPID);
  sendOutputEvent( scm_nEventCNF_SET_TEMPID);
  sendOutputEvent( scm_nEventCNF_MSGID);
}

void FORTE_Z_CONTROLLER3::enterStateNORMAL(void){
  m_nECCState = scm_nStateNORMAL;
}

void FORTE_Z_CONTROLLER3::enterStateTEMP(void){
	m_nECCState = scm_nStateTEMP;
  	alg_temperatureChanged();
  	sendOutputEvent( scm_nEventCNF_TEMPID);
}

void FORTE_Z_CONTROLLER3::enterStateCMD_UP(void){
  m_nECCState = scm_nStateCMD_UP;
  alg_increaseSetTemperature();
  sendOutputEvent( scm_nEventCNF_SET_TEMPID);
}

void FORTE_Z_CONTROLLER3::enterStateCMD_DOWN(void){
	m_nECCState = scm_nStateCMD_DOWN;
  	alg_decreaseSetTemperature();
  	sendOutputEvent( scm_nEventCNF_SET_TEMPID);
}

void FORTE_Z_CONTROLLER3::enterStateCYCLE(void){
  	m_nECCState = scm_nStateCYCLE;
  	alg_CYCLE();
  	sendOutputEvent( scm_nEventGET_TEMPID);
}

void FORTE_Z_CONTROLLER3::enterStateERROR(void){
  m_nECCState = scm_nStateERROR;
  alg_displayError();
  sendOutputEvent( scm_nEventCNF_MSGID);
}
//
// executeEvent()
// ==============
// 
void FORTE_Z_CONTROLLER3::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateINIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINIT:
        if((1))
          enterStateNORMAL();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateNORMAL:
        if(scm_nEventTEMPID == pa_nEIID)
          enterStateTEMP();
        else
        if(scm_nEventCMD_UPID == pa_nEIID)
          enterStateCMD_UP();
        else
        if(scm_nEventCMD_DOWNID == pa_nEIID)
          enterStateCMD_DOWN();
        else
        if(scm_nEventCYCLEID == pa_nEIID)
          enterStateCYCLE();
        else
        if(scm_nEventERRORID == pa_nEIID)
          enterStateERROR();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateTEMP:
        if((1))
          enterStateNORMAL();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCMD_UP:
        if((1))
          enterStateNORMAL();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCMD_DOWN:
        if((1))
          enterStateNORMAL();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCYCLE:
        if((1))
          enterStateNORMAL();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateERROR:
        if((1))
          enterStateNORMAL();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 7.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


