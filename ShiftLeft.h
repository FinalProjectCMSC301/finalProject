#include <iostream>
#include <string>
using namespace std;

class ShiftLeft
{
	public:
		ShiftLeft(){};
		
		/*
			The method shifts the 26 bit binary number string left by 2 and adds 2 additional
			bits. The method returns the modifed 28-bit binary string.
		*/
		string shift(string input);
};
