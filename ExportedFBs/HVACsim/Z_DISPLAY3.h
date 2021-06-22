/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Z_DISPLAY3
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     1.0: 2020-01-09/badger - null - 
 *************************************************************************/

#ifndef _Z_DISPLAY3_H_
#define _Z_DISPLAY3_H_

#include <funcbloc.h>
#include <forte_lint.h>
#include <forte_real.h>
#include <forte_string.h>
#include <forte_int.h>

#include <iostream>
#include <stdio.h>	

#include "../DPs/NIOclient.h"

class FORTE_Z_DISPLAY3: public CFunctionBlock{
	DECLARE_FIRMWARE_FB(FORTE_Z_DISPLAY3)

private:
  	static const CStringDictionary::TStringId scm_anDataInputNames[];
  	static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  	
  	CIEC_REAL &temp() {
   	return *static_cast<CIEC_REAL*>(getDI(0));
  	};

  	CIEC_REAL &set_temp() {
   	return *static_cast<CIEC_REAL*>(getDI(1));
  	};

  	CIEC_STRING &msg() {
   	return *static_cast<CIEC_STRING*>(getDI(2));
  	};

  	CIEC_STRING &address() {
   	return *static_cast<CIEC_STRING*>(getDI(3));
  	};

  	CIEC_LINT &port() {
   	return *static_cast<CIEC_LINT*>(getDI(4));
  	};

  	CIEC_INT &zone() {
   	return *static_cast<CIEC_INT*>(getDI(5));
  	};

  	CIEC_STRING &TI() {
   	return *static_cast<CIEC_STRING*>(getDI(6));
  	};

  	static const TEventID scm_nEventSHOW_TEMPID = 0;
  	static const TEventID scm_nEventSHOW_SET_TEMPID = 1;
  	static const TEventID scm_nEventSHOW_MSGID = 2;
  	static const TForteInt16 scm_anEIWithIndexes[];
  	static const TDataIOID scm_anEIWith[];
  	static const CStringDictionary::TStringId scm_anEventInputNames[];

  	static const TForteInt16 scm_anEOWithIndexes[];
  	static const SFBInterfaceSpec scm_stFBInterfaceSpec;
  	
  	//
	// Packet structure definitions
	// ============================
	static constexpr const char* START_OF_PACKET = "*";
	static constexpr const char* FIELD_SEPARATOR = "|";
	static constexpr const char* END_OF_PACKET = "&";  

   FORTE_FB_DATA_ARRAY(0, 7, 0, 0);

  	void executeEvent(int pa_nEIID);

public:
  	NIOclient client;
  	
  	FUNCTION_BLOCK_CTOR(FORTE_Z_DISPLAY3){
 	};

  	virtual ~FORTE_Z_DISPLAY3(){};
};
#endif //close the ifdef sequence from the beginning of the file

