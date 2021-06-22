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

#include "Z_DISPLAY3.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Z_DISPLAY3_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Z_DISPLAY3, g_nStringIdZ_DISPLAY3)

const CStringDictionary::TStringId FORTE_Z_DISPLAY3::scm_anDataInputNames[] = {g_nStringIdtemp, g_nStringIdset_temp, g_nStringIdmsg, g_nStringIdaddress, g_nStringIdport, g_nStringIdzone, g_nStringIdTI};

const CStringDictionary::TStringId FORTE_Z_DISPLAY3::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdSTRING, g_nStringIdSTRING, g_nStringIdLINT, g_nStringIdINT, g_nStringIdSTRING};

const TForteInt16 FORTE_Z_DISPLAY3::scm_anEIWithIndexes[] = {0, 2, 4};
const TDataIOID FORTE_Z_DISPLAY3::scm_anEIWith[] = {0, 255, 1, 255, 2, 255};
const CStringDictionary::TStringId FORTE_Z_DISPLAY3::scm_anEventInputNames[] = {g_nStringIdSHOW_TEMP, g_nStringIdSHOW_SET_TEMP, g_nStringIdSHOW_MSG};

const TForteInt16 FORTE_Z_DISPLAY3::scm_anEOWithIndexes[] = {-1};
const SFBInterfaceSpec FORTE_Z_DISPLAY3::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  0,  0,   0, 0,  7,  scm_anDataInputNames, scm_anDataInputTypeIds,
  0,  0, 0,
  0, 0
};

using std::cout;
using std::string;
using std::to_string;

void FORTE_Z_DISPLAY3::executeEvent(int pa_nEIID){
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
		//	cout << "Z_DISPLAY3 connected to the simulator\n";
		} else {
			cout << "Z_DISPLAY3 cannot connect to the simulator at " << serverAddress << " via listenerPort " << listenerPort
			     << ". " << client.getLastErrorMessage() << "\n";
		}
   }

	string packet = "";
	switch(pa_nEIID){
	case scm_nEventSHOW_TEMPID:
		packet = (string) START_OF_PACKET + "DZ" + to_string(zone()) + (string) FIELD_SEPARATOR 
					+ to_string(temp()) + (string) FIELD_SEPARATOR + (string) END_OF_PACKET;
		//	cout << packet << "\n";
		client.sendPacket(packet);
 		break;
    
	case scm_nEventSHOW_SET_TEMPID:
		packet = (string) START_OF_PACKET + "DS" + to_string(zone()) + (string) FIELD_SEPARATOR 
					+ to_string(set_temp()) + (string) FIELD_SEPARATOR + (string) END_OF_PACKET;
		//	cout << packet << "\n";
		client.sendPacket(packet);		
		break;
	
	case scm_nEventSHOW_MSGID:
		packet = (string) START_OF_PACKET + "DM" + to_string(zone()) + (string) FIELD_SEPARATOR 
					+ msg().getValue() + (string) FIELD_SEPARATOR + (string) END_OF_PACKET;
		//	cout << packet << "\n";
		client.sendPacket(packet);		
		break;	
	}
}



