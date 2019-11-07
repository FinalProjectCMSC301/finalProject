//Alu2.cpp
#include "Alu2.h"
using namespace std;

Alu2::Alu2()
{
	alu2Bin32 = "";
	shiftBin32 = "";
}

void Alu2::setAlu2Input(string bin32)
{
	alu2Bin32 = bin32;
}

void Alu2::setShiftInput(string bin32)
{
	shiftBin32 = bin32;
}

string Alu2::getBinaryOutput()
{
	//simple add
	string result = bo.addBin(alu2Bin32, shiftBin32, 32);
	return result;
}