//ADD_ALU_Result.cpp
#include "ADD_ALU_Result.h"
using namespace std;

ADD_ALU_Result::ADD_ALU_Result()
{
	alu2Bin32 = "";
	shiftBin32 = "";
}

void ADD_ALU_Result::setAlu2Input(string bin32)
{
	alu2Bin32 = bin32;
}

void ADD_ALU_Result::setShiftInput(string bin32)
{
	shiftBin32 = bin32;
}

string ADD_ALU_Result::getBinaryOutput()
{
	//simple add
	string result = bo.addBin(alu2Bin32, shiftBin32, 32);
	return result;
}