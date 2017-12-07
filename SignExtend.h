//Sign Extend
#ifndef _SignExtend_h_
#define _SignExtend_h_

#include "InstructionMemory.h" //perhaps?
#include <iostream>

/** This class is used as the sign extended unit.
*/
class SignExtend
{
	public:
		/** Takes in a address of 16 bits.
		*/
		SignExtend(string address);//this is in binary
			//instruction would pass bits to this in string
			//which should technically be 16 bits in length
			//but I don't think it's necessary to check
		/** Returns a string that is extended and is not 32 bits.
		*/
		string getExtended();
		
		private:
			string actual;
			string modified;
};
#endif
