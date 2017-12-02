#include "ShiftLeft.hpp"

// Default constructor
ShiftLeft::ShiftLeft()
{

}

/*
The method shifts the 26 bit binary number string left by 2 and adds 2 additional
bits. The method returns the modifed 28-bit binary string.
*/

string ShiftLeft::shift(string input)
{
        string printed = "00" + input;

        cout << "ShiftLeft INPUT: " << binaryOperation.getHexFromBin(printed) << endl;
    
    // Puts 00 at the end to shift the input left by 2 bits
    if(input.length() == 32){
        input.erase(0,2);
    }

    input += "00";
    
    cout << "ShiftLeft OUTPUT: " << binaryOperation.getHexFromBin(input) << endl << endl;
    
    
    return input;
}
