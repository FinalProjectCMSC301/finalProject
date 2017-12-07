//AluControl.h
#ifndef _AluControl_h_
#define _AluControl_h_
#include "BinaryOperation.h"

using namespace std;
/** This class takes the Funct field from instruction and also from Control Unit for ALUOp.
*/
class AluControl
{
	private:
		string operation;
		string funct_field;
		string ALUOp;
		
	public:
		/** Default constructor.
		*/
		AluControl();
		/** Used to set Funct field. Requires 5 bits.
		*/
		void setFunct(string bits5);
		/** Used to set ALUOp. Requires 2 bits.
		*/
		void setALUOp(string bits2);
		/** Outputs a 3 bit field which is used to in ALU to see what operation do.
		*/
		string getOutput();
};
#endif
