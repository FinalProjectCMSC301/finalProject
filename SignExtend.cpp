//SignExtend.cpp

#include "SignExtend.h"

SignExtend::SignExtend(string address)
{
	actual = address 
}

string SignExtend::getExtended()
{
	if(debug){
		cout<< "***SIGN EXTENDING***" << endl;
	}
	cout << "Input: " << address << endl;
		
	if(actual[0] == '0')
	{
		modified = "0000000000000000" + actual;
	}
	else
	{
		modified = "1111111111111111" + actual;
	}
	
	cout << "Output: " << modified << endl;
	return modified;
}
