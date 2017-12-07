#include "ProgramCounter.h"
#include "BinaryOperation.h"


//Constructor that sets the currentAddress equal to a string of 0's
ProgramCounter::ProgramCounter(){
    currentAddress = binaryOperation.hexToBin("0x00400000",32);
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
