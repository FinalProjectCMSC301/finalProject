//Alu1.h
#ifndef _ALU_ALU_RESULT_h_
#define _ALU_ALU_RESULT_h_
#include "BinaryOperation.h"

class ALU_ALU_Result
{
	private:
		int check1;
		int check2;
		int check3;
		BinaryOperation bo;
		string branchBit;
		unsigned int regData;
		unsigned int muxData;
		string oper;
		unsigned int result;
		
	public:
		ALU_ALU_Result();
		void setAluControlInput(string operation);
		void setDataFromReg(string hex);
		void setDataFromMux(string data); //can be hex from reg, or binary from imm
		void execute();
		string getBinaryOutput();
		string getHexOutput();
		string getBranchBit();
		void setBranchBit(string bit1);
};
#endif