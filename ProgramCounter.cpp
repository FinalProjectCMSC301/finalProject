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
    
    if(currentAddress.length()<32){
        return currentAddress;
    }
    

 
    return binaryOperation.binToHex(currentAddress,8);
}




void ProgramCounter::setDebug(bool value)
{
    debug = value;
}
