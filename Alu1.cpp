//Alu.cpp
#include "Alu1.h"
using namespace std;

Alu1::Alu1()
{
	check1 = 0;
	check2 = 0;
	check3 = 0;
	branchBit = "0";
	regData = 0;
	muxData = 0;
	oper = "";
	result = 0;
}

void Alu1::setAluControlInput(string operation)
{
	oper = operation;
	check1 = 1;
}

void Alu1::setDataFromReg(string hex)
{
	regData = bo.hexToInt(hex);
	check2 = 1;
}

void Alu1::setDataFromMux(string data)
{
	if(data[0] == '0' && (data[1] == 'x' || data[1] == 'X'))
	{
		muxData = bo.hexToInt(data);
	}
	else
	{
		muxData = bo.binToInt(data);
	}
	check3 = 1;
}
void Alu1::execute()
{
	if(check1 == 1 && check2 == 1 && check3 == 1)
	{
		//execute
		if(oper == "010")
		{
			result = regData + muxData;
		}
		else if(oper == "110")
		{
			//beq and sub
			result = regData - muxData;
		}
		else if(oper == "111") //slt only
		{
			if(regData < muxData)
			{
				result = 1;
			}
			else
			{
				result = 0;
			}
		}
		else
		{
			//has to be a jump. Do nothing.
		}
		check1 = 0;
		check2 = 0;
		check3 = 0;
	}
	else
	{
		cout << "In Alu1.cpp, not everything was set." << endl;
	}
}

string Alu1::getBinaryOutput()
{
	return bo.intToBin(result, 32);
}

string Alu1::getHexOutput()
{
	return bo.intToHex(result, 8);
}

void Alu1::setBranchBit(string bit1)
{
	branchBit = bit1;
}

string Alu1::getBranchBit()
{
	return branchBit;
}