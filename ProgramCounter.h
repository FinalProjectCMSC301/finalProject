
#include <stdio.h>
#include <iostream>

#include "BinaryOperation.h"

using namespace std;
class ProgramCounter{
private:
    string Address;
    BinaryOperation binaryOperation;
    bool debug;
    ofstream ofile;
    
public:
    
    /* Constructor for pC */
    ProgramCounter();
    
    /* Sets the programCounters address to the input address */
    void setAddress(string address);
    
    /* Retruns the currents address */
    string getAddress();
    
    /* Converts hex to binary string*/
    string getBinFromHex(string sHex);
    
    /* Sets debug to true or false controlling print statements */
    void setDebug(bool debug);
    
    /* Sets toFile to true or false determining if a file is written to */
    void setToFile(bool val);
    
    /* Sets the location of the ostream that will be written to */

};



