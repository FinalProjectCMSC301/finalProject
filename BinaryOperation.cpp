
#include "BinaryOperation.h"

BinaryOperation::BinaryOperation()
{
    
}

/*
 * Takes a binary string and returns its hex string representation
 */
string BinaryOperation::getHexFromBin(string sBinary)
{
    if(sBinary != ""){
        std::stringstream ss;
        ss << std::hex << std::stoll(sBinary, NULL, 2);
        //std::cout <<"hex test " << ss.str() << std::endl;
        
        string s =  ss.str();
        while (s.length() != 8){
            s = "0" + s;
        }
        s = "0x" + s;
        return s;
        
    }
    return "0x";
}

//This method intakes a hexadecimal string and returns an integer
int BinaryOperation::hexToInt(string hexString) {
    unsigned int x;
    stringstream ss;
    ss << std::hex << hexString;
    ss >> x;
    return x;
}

//This method intakes an integer and returns a hexadecimal string
string BinaryOperation::intToHex(int integer)
{
    char output[100];
    sprintf(output, "%08x", integer);
    string result = output;
    result = "0x" + result;
    return result;
}
