#include "ShiftLeft.h"

using namespace std;

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
	//whatever it gets, doesn't matter.
	input.append("00");
	return input;
}