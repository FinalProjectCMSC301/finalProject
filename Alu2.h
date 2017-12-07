//Alu2.h
#ifndef _Alu2_h_
#define _Alu2_h_

#include "BinaryOperation.h"

using namespace std;

class Alu2
{
	private:
		BinaryOperation bo;
		string alu2Bin32;
		string shiftBin32;
	public:
		Alu2();
		void setAlu2Input(string bin32);
		void setShiftInput(string bin32);
		string getBinaryOutput();
};
#endif