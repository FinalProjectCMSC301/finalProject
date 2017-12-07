#include "ProgramCounter.h"
#include "BinaryOperation.h"


//Constructor that sets the currentAddress equal to a string of 0's
ProgramCounter::ProgramCounter(){
    currentAddress = "0x00400000";
}

//Sets the programCounters address to the input address
void ProgramCounter::setAddress(string address){
    
    if(debug)
        cout << "SETTING PROGRAM COUNTER ADDRESS " << binaryOperation.binToHex(address,8) << endl;
    
    
    currentAddress = address;
}
//Retruns the current address


string ProgramCounter::getAddress(){
   
    if (debug)
    {
        cout << "Parser getAddress OUTPUT: " << binaryOperation.binToHex(currentAddress,8) << endl
            << endl;
    }
	return currentAddress;
}




void ProgramCounter::setDebug(bool value)
{
    debug = value;
}

void ProgramCounter::updatePC(string hex)
{
	int current = binaryOperation.hexToInt(hex);
	current = current + 4;
	currentAddress = binaryOperation.intToHex(current, 8);
}