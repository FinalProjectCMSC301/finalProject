//This is for Registers

#include "Parser.h"

class Register
{
	private:
		string registerArray[32];
		bool writeBoolean = 0;
		bool readBoolean = 0;
		bool debug = 0;
		//read1 and read2 for temp string 
		string readRegister1;
		string readRegister2;
		
	public:
		//This takes the file name which contains the memory input and loads every address:value
		Register(string file, bool debug_mode);
		
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

    
		void setReadRegister1(string registerNumber);
    
		void setReadRegister2(string registerNumber);

		string getReadRegister1();
		
		string getReadRegister2();
};
