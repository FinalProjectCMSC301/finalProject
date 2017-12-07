//This is for Registers
#ifndef _Register_h_
#define _Register_h_
//#include "Parser.h"
//#include "BinaryOperation.h"
#include <string>
#include <iostream>

using namespace std;

/** Class used to read the register file and store the values.
*/
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
		/** Constructor takes in a file name to be read, and the debug mode.
		*/
		Register(string file, bool debug_mode);
		
		//add $t1, $t1, $t2
		//writes to a particular register
		//register is int, value is HEX with 0x
		/** Given a register number in int, writes the value given which should be in hex.
		*/
		void writeToRegister(int regNum, string value);
		
		//control signal that tells if register CAN be overwritten
		/** Sets if writing to register is allowed.
		*/
		void setWrite(bool writeBool);
		
		//control signal that tells if register should be read for a particular instruction
		/** Sets if reading is allowed. It always is.
		*/
		void setRead(bool readBool);
		
		//given a particular register (int value), what does that register contain?
		/** Given a register number in int, returns the hex string at it.
		*/
		string read(int register);
		
		//prints all registers
		/** Returns a string that contains contents of entire Register file.
		*/
		string print();
		
		//this is to print debug info
		void setDebug(bool debugBool);
		
		//takes 5 bits in string form and converts to int (num) of register.
		/** Helper method to convert from 5 bits of binary to int value.
		*/
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
