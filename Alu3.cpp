//Alu3.cpp

#include "Alu3.h"

using namespace std;

Alu3::Alu3()
{
	hexPC = "";
}

void Alu3::setPCInput(string hex)
{
	hexPC = hex;
}

void Alu3::update()
{
	string hex1 = hexPC;
	string hex2 = bo.intToHex(4, 8);
	hexPC = bo.addHex(hex1, hex2, 8);
}

string Alu3::getBinaryOutput()
{
	return bo.hexToBin(hexPC, 32);
}

string Alu3::getHexOutput()
{
	return hexPC;
}