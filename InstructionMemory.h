//InstructionMemory.h

//what is this file going to do?
//read a statement, break it up, convert it to binary.

#include <iostream>
//#include "Parser.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

enum Opcode
	{
		ADD, SUB, ADDI, SLT, LW, SW, BEQ, J, UNDEFINED
	};
	
enum InstType
	{
		ITYPE,RTYPE,JTYPE
	};
class InstructionMemory
{	
	private:
		struct TypicalInstruction
		{
			int index; //start at 0x400000
			string name; //add, sub or what?
			int numOps;	//how many things it has, rs,rt,rd,imm
			int rdPos;
			int rsPos;
			int rtPos;
			int immPos;
			InstType instType;	//could come in handy
			string op_field;	//definitely handy
			string funct_field;	//only for R types....right?
		};
		bool debug = 0;
		//array will hold all information
		TypicalInstruction myArray[UNDEFINED]; //holds definition of all instruction types
		vector<string> myInstructions; //contains all instructions
		//string getRegisterBinary(string register); //gets binary conversion of register number
		string getImmBinary(string imm);//gets binary of immediate/offset field
		void readInstructions(string fileName); //reads all instructions and puts them in the myInstructions vector
		string processInstArray(string array[]); //finds the binary equavalent of an entire instruction in .asm
		Opcode getOpcode(string s); //returns the Opcode, an enum
		string registerNumToBinary(string s); //gets binary conversion of register number
		//string getFunctField(string s); //gets 
		string getImm(string s, Opcode opcode); //gets immediate/offset depending on opcode. and of the proper length
		string immToBinarySixteen(string s);//used in case when immediate is integer and 16 bits are needed
		string jumpImmToBinaryTwentySix(string s); //used in case when J(ump) is done. Returns a 26 bit string
		//string twosComplement(string bitString);//gets two's complement			NOT WORKING FOR NOW
	public:
		//gets the file name from parser
		InstructionMemory(string fileName);
		void setDebug(int num);
		string getInstruction(int index);
		// string get25To0();	//returns a string of binary from 0 to 25th, used for shift left
		// string getBinaryOpcode(); //goes in control, OPCODE
		// string getRS();	//read register 1
		// string getRT();	//read register 2, and MUX
		// string getRD();	//MUX, which goes to write register
		// string getImm(); //get immediate field. Goes to sign extend
		// string get5To0(); //used for ALU control
};