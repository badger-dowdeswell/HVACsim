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

#ifndef _Z_CONTROLLER3_H_
#define _Z_CONTROLLER3_H_

#include <iostream>
#include <stdio.h>
using std::cout;
using std::string;

#include <basicfb.h>
#include <forte_real.h>
#include <forte_string.h>
#include <forte_int.h>

class FORTE_Z_CONTROLLER3: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Z_CONTROLLER3)

private:
	static const CStringDictionary::TStringId scm_anDataInputNames[];
  	static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  	CIEC_REAL &temp_C() {
   	return *static_cast<CIEC_REAL*>(getDI(0));
  	};

  	CIEC_INT &error_code() {
   	return *static_cast<CIEC_INT*>(getDI(1));
  	};

  	CIEC_STRING &TI() {
   	return *static_cast<CIEC_STRING*>(getDI(2));
  	};

  	static const CStringDictionary::TStringId scm_anDataOutputNames[];
  	static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  	
  	CIEC_REAL &zone_temp() {
   	return *static_cast<CIEC_REAL*>(getDO(0));
  	};

  	CIEC_REAL &set_zone_temp() {
   	return *static_cast<CIEC_REAL*>(getDO(1));
  	};

  	CIEC_STRING &zone_msg() {
   	return *static_cast<CIEC_STRING*>(getDO(2));
  	};

  	static const TEventID scm_nEventINITID = 0;
  	static const TEventID scm_nEventCYCLEID = 1;
  	static const TEventID scm_nEventTEMPID = 2;
  	static const TEventID scm_nEventCMD_UPID = 3;
  	static const TEventID scm_nEventCMD_DOWNID = 4;
  	static const TEventID scm_nEventERRORID = 5;
  	static const TForteInt16 scm_anEIWithIndexes[];
  	static const TDataIOID scm_anEIWith[];
  	static const CStringDictionary::TStringId scm_anEventInputNames[];

  	static const TEventID scm_nEventGET_TEMPID = 0;
  	static const TEventID scm_nEventCNF_TEMPID = 1;
  	static const TEventID scm_nEventCNF_SET_TEMPID = 2;
  	static const TEventID scm_nEventCNF_MSGID = 3;
  	static const TForteInt16 scm_anEOWithIndexes[];
  	static const TDataIOID scm_anEOWith[];
  	static const CStringDictionary::TStringId scm_anEventOutputNames[];

  	static const CStringDictionary::TStringId scm_anInternalsNames[];
  	static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  
  	CIEC_REAL &ZONE_TEMPERATURE() {
   	return *static_cast<CIEC_REAL*>(getVarInternal(0));
  	};

  	CIEC_REAL &ZONE_SET_TEMPERATURE() {
   	return *static_cast<CIEC_REAL*>(getVarInternal(1));
  	};

  	static const SFBInterfaceSpec scm_stFBInterfaceSpec;

	static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(4, 3, 3, 2, 0);
 	void alg_initialize(void);
  	void alg_normalOperation(void);
  	void alg_temperatureChanged(void);
  	void alg_increaseSetTemperature(void);
  	void alg_decreaseSetTemperature(void);
  	void alg_CYCLE(void);
  	void alg_displayError(void);
  	static const TForteInt16 scm_nStateSTART = 0;
  	static const TForteInt16 scm_nStateINIT = 1;
  	static const TForteInt16 scm_nStateNORMAL = 2;
  	static const TForteInt16 scm_nStateTEMP = 3;
  	static const TForteInt16 scm_nStateCMD_UP = 4;
  	static const TForteInt16 scm_nStateCMD_DOWN = 5;
  	static const TForteInt16 scm_nStateCYCLE = 6;
  	static const TForteInt16 scm_nStateERROR = 7;

  	void enterStateSTART(void);
 	void enterStateINIT(void);
  	void enterStateNORMAL(void);
  	void enterStateTEMP(void);
  	void enterStateCMD_UP(void);
  	void enterStateCMD_DOWN(void);
  	void enterStateCYCLE(void);
  	void enterStateERROR(void);

  	virtual void executeEvent(int pa_nEIID);

public:
	FORTE_Z_CONTROLLER3(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  	};

  	virtual ~FORTE_Z_CONTROLLER3(){};
};
#endif //close the ifdef sequence from the beginning of the file

