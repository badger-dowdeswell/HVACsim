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

#ifndef _F_TO_C_CONV2_H_
#define _F_TO_C_CONV2_H_

#include <simplefb.h>
#include <forte_real.h>
#include <forte_string.h>

#include <iostream>
#include <stdio.h>

class FORTE_F_TO_C_CONV2: public CSimpleFB{
  DECLARE_FIRMWARE_FB(FORTE_F_TO_C_CONV2)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  CIEC_REAL &temp_F() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_STRING &TI() {
    return *static_cast<CIEC_STRING*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  CIEC_REAL &temp_C() {
    return *static_cast<CIEC_REAL*>(getDO(0));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventERRORID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(2, 2, 1, 0);
  void alg_REQ(void);

public:
  FORTE_F_TO_C_CONV2(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CSimpleFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_F_TO_C_CONV2(){};
};
#endif //close the ifdef sequence from the beginning of the file

