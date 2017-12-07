//Alu.cpp
#include "ALU_ALU_Result.h"
using namespace std;

ALU_ALU_Result::ALU_ALU_Result()
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

void ALU_ALU_Result::setAluControlInput(string operation)
{
	oper = operation;
	check1 = 1;
}

void ALU_ALU_Result::setDataFromReg(string hex)
{
	regData = bo.hexToInt(hex);
	check2 = 1;
}

void ALU_ALU_Result::setDataFromMux(string data)
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
void ALU_ALU_Result::execute()
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
		cout << "In ALU_ALU_Result.cpp, not everything was set." << endl;
	}
}

string ALU_ALU_Result::getBinaryOutput()
{
	return bo.intToBin(result, 32);
}

string ALU_ALU_Result::getHexOutput()
{
	return bo.intToHex(result, 8);
}

void ALU_ALU_Result::setBranchBit(string bit1)
{
	branchBit = bit1;
}

string ALU_ALU_Result::getBranchBit()
{
	return branchBit;
}