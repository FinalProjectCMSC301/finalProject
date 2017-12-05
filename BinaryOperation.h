
#ifndef _BinaryOperation_h_
#define _BinaryOperation_h_

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

class BinaryOperation
{
    
private:
    bool debug = false;
public:
    BinaryOperation();
    
    /*
     * Returns a hexadecimal string representation of the binary input string.
     */
    string getHexFromBin(string sBinary);
    
    /*
     * Takes a hex string as a parameter and returns its integer representation
     */
    int hexToInt(string hexString);
    
    /*
     * Converts the int integer to hex and returns a string representation of 
     * the hexadecimal value
     */
    string intToHex(int integer);
    void setDebug(bool debugChange){debug = debugChange;};
};

#endif
