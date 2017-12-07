#include <stdio.h>
#include <iostream>

#include "BinaryOperation.h"

using namespace std;
class ProgramCounter{
private:
    string currentAddress;
    BinaryOperation binaryOperation;
    bool debug;
    ofstream ofile;
    
public:
    
    /* Constructor for pc */
    ProgramCounter();
    
    /* Sets the programCounters address to the input address 
	address parameter should be a 0x00000000. So a hex, with 8 digits or letters after.*/
    void setAddress(string address);
    
    /* Retruns the currents address */
    string getAddress();
    
    /* Converts hex to binary string*/
    string getBinFromHex(string sHex);
    
    /* Sets debug to true or false controlling print statements */
    void setDebug(bool debug);
};
