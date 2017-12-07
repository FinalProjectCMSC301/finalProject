//Alu2.h
#ifndef _ADD_ALU_RESULT_h_
#define _ADD_ALU_RESULT_h_

#include "BinaryOperation.h"

using namespace std;

class ADD_ALU_Result
{
	private:
		BinaryOperation bo;
		string alu2Bin32;
		string shiftBin32;
	public:
		ADD_ALU_Result();
		void setAlu2Input(string bin32);
		void setShiftInput(string bin32);
		string getBinaryOutput();
};
#endif