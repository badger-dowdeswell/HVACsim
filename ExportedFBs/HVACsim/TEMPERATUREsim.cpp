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

#include "TEMPERATUREsim.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "TEMPERATUREsim_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_TEMPERATUREsim, g_nStringIdTEMPERATUREsim)

const CStringDictionary::TStringId FORTE_TEMPERATUREsim::scm_anDataInputNames[] = {g_nStringIdaddress, g_nStringIdport, g_nStringIdzone, g_nStringIdTI};

const CStringDictionary::TStringId FORTE_TEMPERATUREsim::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdLINT, g_nStringIdINT, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_TEMPERATUREsim::scm_anDataOutputNames[] = {g_nStringIdtemp_F, g_nStringIderror_code};

const CStringDictionary::TStringId FORTE_TEMPERATUREsim::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdINT};

const TForteInt16 FORTE_TEMPERATUREsim::scm_anEIWithIndexes[] = {0, -1};
const TDataIOID FORTE_TEMPERATUREsim::scm_anEIWith[] = {0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_TEMPERATUREsim::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREAD};

const TDataIOID FORTE_TEMPERATUREsim::scm_anEOWith[] = {0, 255, 1, 255};
const TForteInt16 FORTE_TEMPERATUREsim::scm_anEOWithIndexes[] = {-1, 0, 2, -1};
const CStringDictionary::TStringId FORTE_TEMPERATUREsim::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF_TEMP, g_nStringIdERROR};

const SFBInterfaceSpec FORTE_TEMPERATUREsim::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

using std::cout;
using std::string;
using std::to_string;

using std::stoi;
using std::stod;
using std::stof;
using std::cout;
using std::endl;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

//
// setInitialValues()
// ==================
void FORTE_TEMPERATUREsim::setInitialValues(){
	address() = "127.0.0.1";
  	port() = 62500;
  	zone() = 1;
}

//
// executeEvent()
// ==============
void FORTE_TEMPERATUREsim::executeEvent(int pa_nEIID){
	switch(pa_nEIID){
   case scm_nEventINITID:
   	if (!client.isConnected()) {
 	 		// Connect to the simulator.
			long int listenerPort = 0;
   		listenerPort = port();
   		char serverAddress[32] = {0};
   		address().toString(serverAddress, 32);
   		// FORTE parameter strings have leading and terminating single-quote characters in them 
   		// so remove them from the server address just created.
   		for(int ptr = 1; ptr <= 32; ptr++) {
				serverAddress[ptr - 1] = serverAddress[ptr];
				if ((ptr > 1 ) && (serverAddress[ptr] == '\'')) {
					serverAddress[ptr - 1] = '\0';
					break;
				}
			}
			
			if (client.connectToServer(serverAddress, listenerPort)) {	
				//	cout << "TEMPERATUREsim connected to the simulator\n";
			} else {
				cout << "TEMPERATUREsim cannot connect to the simulator at " << serverAddress << " via listenerPort " << listenerPort
			    	  << ". " << client.getLastErrorMessage() << "\n";
			}
   	}
	  	break;
      
	case scm_nEventREADID:
		// auto currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

		string packet = (string) START_OF_PACKET + "GZ" + to_string(zone()) + (string) FIELD_SEPARATOR 
		                + (string) FIELD_SEPARATOR + (string) END_OF_PACKET;
  		client.sendPacket(packet);
   	packet = client.recvPacket();
   	
   	// Extract the returned value
   	string temp = "";
 	 	if (packet.length() > 0) {
   		size_t ptrStart = -1;
   		size_t ptrEnd = -1;
   		ptrStart = packet.find(FIELD_SEPARATOR);
	 		if (ptrStart > (size_t) 0) {
   			ptrEnd = packet.find(FIELD_SEPARATOR, ptrStart + 1);
   			if (ptrEnd > (size_t) 0) {
					temp = packet.substr(ptrStart + 1, ptrEnd - ptrStart - 1);
					if (temp.length() > 0) {
						currentTemperature = stof(temp);
						lastTemperature = currentTemperature;
						temp_F() = currentTemperature;
						cout << "TEMPERATUREsim: temp_F = " << to_string(temp_F()) << "\n";	
						sendOutputEvent(scm_nEventCNF_TEMPID);
					}	
				}	   				
 			} 
	  	}
		break;
  }
}



