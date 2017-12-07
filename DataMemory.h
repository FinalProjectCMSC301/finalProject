//Data Memory
//The possible things that can be done from memory:
//Read an address,or write an address.

//#include "Parser.h"
#ifndef _DataMemory_h_
#define _DataMemory_h_
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

/** Representation of data memory.
*/
class DataMemory
{
	private:
		map<string, string> memoryContent;
		bool writeBoolean = 0;
		bool readBoolean = 0;
		bool debug = 0;
		
	public:
		//This takes the file name which contains the memory input and loads every address:value
		/** Constructor takes in a filename, and a bool that decides if debug values will be displayed.
		*/
		DataMemory(string file, bool debug);
		
		//sw $t1, 0($t2)
		//writes to a particular address
		//address in HEX WITH a 0x
		/** Given a hex string address, writes the given values (which should be in hex as well).
		*/
		void writeToMemory(string address, string value);
		
		//control signal that tells if memory CAN be overwritten
		/** Decides whether memory can be written.
		*/
		void setWrite(bool writeBool);
		
		//control signal that tells if memory should be read for a particular instruction
		/** Decides whether memory can be read.
		*/
		void setRead(bool readBool);
		
		//given a particular hex address, what does that address contain?
		/** Given a hex address, returns the associated hex string.
		*/
		string read(string address);
		
		//prints all memory
		/** Returns a string that contains whole data memory.
		*/
		string print();
		
		//this is to print debug info
		void setDebug(bool debugBool);
};
#endif
