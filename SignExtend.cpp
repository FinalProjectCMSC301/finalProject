//SignExtend.cpp

#include "SignExtend.h"

SignExtend::SignExtend(string address)
{
	actual = string 
}

string SignExtend::getExtended()
{
	if(actual[0] == '0')
	{
		modified = "0000000000000000" + actual;
	}
	else
	{
		modified = "1111111111111111" + actual;
	}
	return modified;
}