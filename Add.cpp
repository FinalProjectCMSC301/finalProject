//Alu3.cpp

#include "Add.h"

using namespace std;

Add::Add()
{
	hexPC = "";
}

void Add::setPCInput(string hex)
{
	hexPC = hex;
}

void Add::update()
{
	string hex1 = hexPC;
	string hex2 = bo.intToHex(4, 8);
	hexPC = bo.addHex(hex1, hex2, 8);
}

string Add::getBinaryOutput()
{
	return bo.hexToBin(hexPC, 32);
}

string Add::getHexOutput()
{
	return hexPC;
}