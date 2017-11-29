//Data Memory
//The possible things that can be done from memory:
//Read an address,or write an address.

#include "Parser.h"
#include <map>

class DataMemory
{
	private:
		map<string, string> memoryContent;
		bool writeBoolean = 0;
		bool readBoolean = 0;
		bool debug = 0;
		
	public:
		//This takes the file name which contains the memory input and loads every address:value
		DataMemory(string file);
		
		//sw $t1, 0($t2)
		//writes to a particular address
		//address in HEX WITH a 0x
		void writeToMemory(string address, string value);
		
		//control signal that tells if memory CAN be overwritten
		void setWrite(bool writeBool);
		
		//control signal that tells if memory should be read for a particular instruction
		void setRead(bool readBool);
		
		//given a particular hex address, what does that address contain?
		string read(string address);
		
		//prints all memory
		void print();
		
		//this is to print debug info
		void setDebug(bool debugBool);
}