//Sign Extend

#include "InstructionMemory.h" //perhaps?

class SignExtend
{
	public:
		SignExtend(string address);//this is in binary
			//instruction would pass bits to this in string
			//which should technically be 16 bits in length
			//but I don't think it's necessary to check
		string getExtended();
		
		private:
			string actual;
			string modified;
}
