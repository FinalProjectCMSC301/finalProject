#include "ProgramCounter.h"


//Constructor that sets the currentAddress equal to a string of 0's
ProgramCounter::ProgramCounter(){
    currentAddress = getBinFromHex("0x00040000");
}

//Sets the programCounters address to the input address
void ProgramCounter::setAddress(string address){
    
    if(debug)
        cout << "SETTING PROGRAM COUNTER ADDRESS " << binaryOperation.getHexFromBin(address) << endl;
    
    
    currentAddress = address;
}

//Retruns the current address


string ProgramCounter::getAddress(){
   
    if (debug)
    {
        cout << "Parser getAddress OUTPUT: " << binaryOperation.getHexFromBin(currentAddress) << endl
            << endl;
    }
    
    if (toFile)
    {
        //ofile << "Parser getAddress OUTPUT: " << binaryOperation.getHexFromBin(currentAddress) << endl << endl; write or not 
    }


    return currentAddress;
}


string ProgramCounter::getBinFromHex(string sHex)
{
    string s = sHex;
    stringstream ss;
    ss << std::hex << s;
    unsigned n;
    ss >> n;
    bitset<32> b(n);

    cout << "Test Return Hex " << b.to_string() << endl;
    
    return b.to_string();
}


void ProgramCounter::setDebug(bool value)
{
    debug = value;
}


void ProgramCounter::setToFile(bool val)
{
    toFile = val;
}
