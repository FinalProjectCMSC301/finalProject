//Alu1.h
#ifndef _ALU_ALU_RESULT_h_
#define _ALU_ALU_RESULT_h_
#include "BinaryOperation.h"

class ALU_ALU_Result
{
	private:
		/** checks are used to see that all three required inputs have been received and after execute()
		is done, they are reset so that the same numbers do not execute.
		*/
		int check1;
		int check2;
		int check3;
		/** Used when conversion or addion between int-bin-hex is needed.
		*/
		BinaryOperation bo;
		string branchBit;
		unsigned int regData;
		unsigned int muxData;
		string oper;
		unsigned int result;
		
	public:
		/** Default constructor.
		*/
		ALU_ALU_Result();
		/** Used to set a 3 bit input from ALU Control unit.
		*/
		void setAluControlInput(string operation);
		/** Used to set data from register file.
		*/
		void setDataFromReg(string hex);
		/** Used to set data from the multiplexer
		*/
		void setDataFromMux(string data); //can be hex from reg, or binary from imm
		/** Used to do the required operation on the given operands.
		*/
		void execute();
		/** Used to get the result of execute() in binary.
		*/
		string getBinaryOutput();
		/** Used to get the result of execute() in hex.
		*/
		string getHexOutput();
		/** Used to see the control signal to AND unit which selectes if branch should be done.
		*/
		string getBranchBit();
		/** Used to set the branch bit to AND unit.
		*/
		void setBranchBit(string bit1);
};
#endif
