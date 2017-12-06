/**
This class represents the control unit in the processor.
Input: a string of bits that represents the funct of the instruction
Output: sets the control signals based on the binary input
**/

#ifndef __CONTROLUNIT_H__
#define __CONTROLUNIT_H__

using namespace std;
#include <fstream>
#include <iostream>

class ControlUnit{
public:
	ControlUnit();
	void setControls (string bitString);

	string regDst;
	string jump;
	string branch;
	string memRead;
	string memtoReg;
	string ALUOp1;
	string ALUOp0;
	string memWrite;
	string ALUSrc;
	string regWrite;
	bool debug;
	
	void setDebug(bool debugChange){debug = debugChange;};

	string getRegDST(){return regDst;};
	string getJump(){return jump;};
	string getBranch(){return branch;};
	string getMemRead(){return memRead;};
	string getMemtoReg(){return memtoReg;};
	string getALUOp1(){return ALUOp1;};
	string getALUOp0(){return ALUOp0;};
	string getALUOp(){return ALUOp0+ALUOp1;};
	string getMemWrite(){return memWrite;};
	string getALUSrc(){return ALUSrc;};
	string getRegWrite(){return regWrite;};

	string setRegDST(string reg){regDst = reg;};
	string setJump(string j){ jump = j;};
	string setBranch(string b){ branch = b;};
	string setMemRead(string mem){ memRead = mem;};
	string setMemtoReg(string mem){ memtoReg = mem;};
	string setAluOp1(string alu){ ALUOp1 = alu;};
	string setAluOp0(string alu){ ALUOp0 = alu;};
	string setMemWrite(string mem){ memWrite = mem;};
	string setALUSrc(string alu){ ALUSrc = alu;};
	string setRegWrite(string reg){ regWrite = reg;};
	void printValues(){cout << "RegDST: " << regDst << "\n" << "Branch: " << branch << "\n" << "Jump: " << jump << "\n" << "MemRead: " << memRead << "\n" << "MemtoReg: " << memtoReg << "\n" << "ALUOP0: " << ALUOp0 << "\n" << "ALUOp1: " << ALUOp1 << "\n" << "ALUSrc: " << ALUSrc << "\n" << "MemWrite: " << memWrite << "\n" << "RegWrite: " << regWrite << "\n";};
	string printStringValues();


};
#endif
