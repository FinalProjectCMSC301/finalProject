#ifndef _ADD_ALU_RESULT_h_
#define _ADD_ALU_RESULT_h_
#include "BinaryOperation.h"

using namespace std;

/** This class represents the ADD_ALU_Result unit. This is used for calculation for branch addresses.
*/
class ADD_ALU_Result
{
	private:
		BinaryOperation bo;
		string alu2Bin32;
		string shiftBin32;
	public:
		/** Default Constructor
		*/
		ADD_ALU_Result();
		/** Used to set first input from ADD ALU unit. Requires a 32 bit binary string.
		*/
		void setAlu2Input(string bin32);
		/** Used to set input from Shift Left unit. Requires a 32 bit binary string.
		*/
		void setShiftInput(string bin32);
		/** returns a binary representation (32 bits) that shows addition between two inputs.
		*/
		string getBinaryOutput();
};
#endif
