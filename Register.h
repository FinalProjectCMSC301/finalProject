//This is for Registers
#ifndef _Register_h_
#define _Register_h_
//#include "Parser.h"
//#include "BinaryOperation.h"
#include <string>
#include <iostream>

using namespace std;

class Register
{
	private:
		string registerArray[32];
		bool writeBoolean = 0;
		bool readBoolean = 1;
		bool debug = 0;
		//read1 and read2 for temp string 
		// string readRegister1;
		// string readRegister2;
		// string writeRegister;
		// BinaryOperation BinOP;
		
	public:
		//This takes the file name which contains the memory input and loads every address:value
		Register(string file, bool debug_mode);
		
		//add $t1, $t1, $t2
		//writes to a particular register
		//register is int, value is HEX with 0x
		void writeToRegister(int regNum, string value);
		
		//control signal that tells if register CAN be overwritten
		void setWrite(bool writeBool);
		
		//control signal that tells if register should be read for a particular instruction
		void setRead(bool readBool);
		
		//given a particular register (int value), what does that register contain?
		string read(int register);
		
		//prints all registers
		string print();
		
		//this is to print debug info
		void setDebug(bool debugBool);
		
		//takes 5 bits in string form and converts to int (num) of register.
		int getRegFromBinary(string fiveBits);
    
		// void setReadRegister1(string registerNumber);
    
		// void setReadRegister2(string registerNumber);
	
		// void setWriteRegister(string registerNumber){writeRegister=registerNumber;};
		
		// string getWriteRegister(){return writeRegister;};

		// string getReadRegister1();
		
		// string getReadRegister2();
		// string getHexFromBin(string sBinary);
		// int hexToInt(string hexString);
		// string intToHex(int integer);
};
#endif