//AluControl.cpp

#include "AluControl.h"
using namespace std;

AluControl::AluControl()
{
	funct_field = "";
	ALUOp = "";
	operation = "";
}

void AluControl::setFunct(string bits5)
{
	funct_field = bits5;
}

void AluControl::setALUOp(string bits2)
{
	ALUOp = bits2;
}
string AluControl::getOutput()
{
	if(ALUOp == "01")
	{
		if(funct_field == "100000")
		{
			//add
			operation = "010";
		}
		if(funct_field == "101010")
		{
			//slt
			operation = "111";
		}
		if(funct_field == "100010")
		{
			//sub
			operation = "110";
		}
	}
	if(ALUOp == "10")
	{
		//beq
		operation = "110";
	}
	if(ALUOp == "11")
	{
		//addi
		operation = "010";
	}
	if(ALUOp == "00")
	{
		//lw and sw
		operation = "010";
	}
	if(ALUOp == "xx")
	{
		//j
		operation = "000";
	}
	return operation;
}