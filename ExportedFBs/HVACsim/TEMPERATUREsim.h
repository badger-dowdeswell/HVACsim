/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: TEMPERATUREsim
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     1.0: 2020-01-04/badger - AUT - Original version
 *************************************************************************/

#ifndef _TEMPERATURESIM_H_
#define _TEMPERATURESIM_H_
#
#include <funcbloc.h>
#include <forte_lint.h>
#include <forte_real.h>
#include <forte_string.h>
#include <forte_int.h>

#include <chrono>
#include <sys/time.h>
#include <ctime>

#include <iostream>
#include <stdio.h>	

#include "../DPs/NIOclient.h"

class FORTE_TEMPERATUREsim: public CFunctionBlock{
	DECLARE_FIRMWARE_FB(FORTE_TEMPERATUREsim)

private:
	static const CStringDictionary::TStringId scm_anDataInputNames[];
  	static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  	CIEC_STRING &address() {
   	return *static_cast<CIEC_STRING*>(getDI(0));
  	};

  	CIEC_LINT &port() {
   	return *static_cast<CIEC_LINT*>(getDI(1));
  	};

  	CIEC_INT &zone() {
   	return *static_cast<CIEC_INT*>(getDI(2));
  	};

  	CIEC_STRING &TI() {
   	return *static_cast<CIEC_STRING*>(getDI(3));
  	};

  	static const CStringDictionary::TStringId scm_anDataOutputNames[];
  	static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  	CIEC_REAL &temp_F() {
   	return *static_cast<CIEC_REAL*>(getDO(0));
  	};

  	CIEC_INT &error_code() {
   	return *static_cast<CIEC_INT*>(getDO(1));
  	};

  	static const TEventID scm_nEventINITID = 0;
  	static const TEventID scm_nEventREADID = 1;
  	static const TForteInt16 scm_anEIWithIndexes[];
  	static const TDataIOID scm_anEIWith[];
  	static const CStringDictionary::TStringId scm_anEventInputNames[];

  	static const TEventID scm_nEventINITOID = 0;
  	static const TEventID scm_nEventCNF_TEMPID = 1;
  	static const TEventID scm_nEventERRORID = 2;
  	static const TForteInt16 scm_anEOWithIndexes[];
  	static const TDataIOID scm_anEOWith[];
  	static const CStringDictionary::TStringId scm_anEventOutputNames[];

  	static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(3, 4, 2, 0);
   
   float lastTemperature = 0;
 	float currentTemperature = 0;

	virtual void setInitialValues();

	void executeEvent(int pa_nEIID);
	
	//
	// Packet structure definitions
	// ============================
	static constexpr const char* START_OF_PACKET = "*";
	static constexpr const char* FIELD_SEPARATOR = "|";
	static constexpr const char* END_OF_PACKET = "&";  

public:
	NIOclient client;

	FUNCTION_BLOCK_CTOR(FORTE_TEMPERATUREsim){
  	};

  	virtual ~FORTE_TEMPERATUREsim(){};
};
#endif //close the ifdef sequence from the beginning of the file

