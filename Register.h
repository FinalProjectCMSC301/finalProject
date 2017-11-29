//This is for Registers

#include "Parser.h"

class Register
{
	private:
		string registerArray[32];
		bool writeBoolean = 0;
		bool readBoolean = 0;
		bool debug = 0;
		
	public:
		//This takes the file name which contains the memory input and loads every address:value
		Register(string file);
		
		//add $t1, $t1, $t2
		//writes to a particular register
		//register is int, value is HEX with 0x
		void writeToRegister(int register, string value);
		
		//control signal that tells if register CAN be overwritten
		void setWrite(bool writeBool);
		
		//control signal that tells if register should be read for a particular instruction
		void setRead(bool readBool);
		
		//given a particular register (int value), what does that register contain?
		string read(int register);
		
		//prints all registers
		void print();
		
		//this is to print debug info
		void setDebug(bool debugBool);
}