//InstructionMemory.h

//what is this file going to do?
//read a statement, break it up, convert it to binary.

#include <iostream>
//#include "Parser.h"
#include <string>
#include <vector>
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
		//array will hold all information
		TypicalInstruction myArray[UNDEFINED];
		vector<string> myInstructions;
		string getRegisterBinary(string register);
		string getImmBinary(string imm);
		void readInstructions(string fileName);
	public:
		//gets the file name from parser
		InstructionMemory(string fileName);
		
		string get25To0();	//returns a string of binary from 0 to 25th, used for shift left
		string getOpcode(); //goes in control, OPCODE
		string getRS();	//read register 1
		string getRT();	//read register 2, and MUX
		string getRD();	//MUX, which goes to write register
		string getImm(); //get immediate field. Goes to sign extend
		string get5To0(); //used for ALU control
};