/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: SWITCHsim
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     1.0: 2020-01-13/badger - null - 
 *************************************************************************/

#include "SWITCHsim.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "SWITCHsim_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_SWITCHsim, g_nStringIdSWITCHsim)

const CStringDictionary::TStringId FORTE_SWITCHsim::scm_anDataInputNames[] = {g_nStringIdaddress, g_nStringIdport, g_nStringIdparams, g_nStringIdTI};

const CStringDictionary::TStringId FORTE_SWITCHsim::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdLINT, g_nStringIdINT, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_SWITCHsim::scm_anDataOutputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_SWITCHsim::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_SWITCHsim::scm_anEIWithIndexes[] = {0, -1};
const TDataIOID FORTE_SWITCHsim::scm_anEIWith[] = {0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_SWITCHsim::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREAD};

const TDataIOID FORTE_SWITCHsim::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_SWITCHsim::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_SWITCHsim::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_SWITCHsim::scm_stFBInterfaceSpec = {
	  	2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  		2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  		1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  		0, 0
};

using std::cout;
using std::string;
using std::to_string;

//
// executeEvent()
// ==============
void FORTE_SWITCHsim::executeEvent(int pa_nEIID){
	zone = params().substr(0, 1);
	switchType = params.substr(1, 1);
	cout << "zone = " << zone << "\n";
	cout << "switchType = " << switchType << "\n";
	
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
			cout << "SWITCHESsim connected to the simulator\n";
		} else {
			cout << "SWITCHsim " << " cannot connect to the simulator at " << serverAddress << " via listenerPort " << listenerPort
			     << ". " << client.getLastErrorMessage() << "\n";
		}
	}

	switch(pa_nEIID){
	case scm_nEventSAMPLEID:
   	if (client.isConnected()) {
   		// Request the status of the switch.
   		string packet = (string) START_OF_PACKET + "S" + switchType + (string) FIELD_SEPARATOR 
					          + zone + (string) FIELD_SEPARATOR + + (string) FIELD_SEPARATOR + (string) END_OF_PACKET;
			//string packet = "*SW" + to_string(ZONE()) + "||&";
  			client.sendPacket(packet);
   		
   		// Extract the returned switch value from the reply packet.
   		packet = client.recvPacket();
	 		string temp = "";
 	 		if (packet.length() > 0) {
   			size_t ptrStart = -1;
   			size_t ptrEnd = -1;
   			ptrStart = packet.find("|");
	 			if (ptrStart > (size_t) 0) {
   				ptrEnd = packet.find("|", ptrStart + 1);
   				if (ptrEnd > (size_t) 0) {
						temp = packet.substr(ptrStart + 1, ptrEnd - ptrStart - 1);
						if (temp.length() == 2) {
							if (temp.substr(0, 1) == "T") {
								cout << "[SWITCHsim]" << params().getValue() + " pressed\n";
								IN() = true;
								sendOutputEvent(scm_nEventCNFID);
							} else {
								cout << "[SWITCHsim]" << params().getValue() + " not pressed\n";
								IN() = false;
								sendOutputEvent(scm_nEventCNFID);
							}
						}						
					}	
				}	   				
 			} 
	  	}  	
 		break;
	}		
}	




