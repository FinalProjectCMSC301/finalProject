//Alu1.h
#ifndef _Alu1_h_
#define _Alu1_h_
#include "BinaryOperation.h"

class Alu1
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
		Alu1();
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