//AluControl.h
#ifndef _AluControl_h_
#define _AluControl_h_
#include "BinaryOperation.h"

using namespace std;

class AluControl
{
	private:
		string operation;
		string funct_field;
		string ALUOp;
		
	public:
		AluControl();
		void setFunct(string bits5);
		void setALUOp(string bits2);
		string getOutput();
};
#endif