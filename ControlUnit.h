#ifndef __CONTROLUNIT_H__
#define __CONTROLUNIT_H__

using namespace std;
#include <fstream>
#include <iostream>

class ControlUnit{
public:
	ControlUnit();
	void setControls (string bitString);
private:
	string regDst;
	string jump;
	string branch;
	string memRead;
	string memtoReg;
	string ALUOp1;
	string ALUOp2;
	string memWrite;
	string ALUSrc;
	string regWrite;

	string getRegDST(){return regDst;};
	string getJump(){return jump;};
	string getBranch(){return branch;};
	string getMemRead(){return memRead;};
	string getMemtoReg(){return memtoReg;};
	string getALUOp1(){return ALUOp1;};
	string getALUOp2(){return ALUOp2;};
	string getMemWrite(){return memWrite;};
	string getALUSrc(){return ALUSrc;};
	string getRegWrite(){return regWrite;};

	string setRegDST(string reg){regDst = reg;};
	string setJump(string j){ jump = j;};
	string setBranch(string b){ branch = b;};
	string setMemRead(string mem){ memRead = mem;};
	string setMemtoReg(string mem){ memtoReg = mem;};
	string setALUOp1(string alu){ ALUOp1 = alu;};
	string setALUOp2(string alu){ ALUOp2 = alu;};
	string setMemWrite(string mem){ memWrite = mem;};
	string setALUSrc(string alu){ ALUSrc = alu;};
	string setRegWrite(string reg){ regWrite = reg;};
	void printValues(){cout << "RegDST: " << regDst << "\n" << "Branch: " << branch << "\n" << "Jump: " << jump << "\n" << "MemRead: " << memRead << "\n" << "MemtoReg: " << memtoReg << "\n" << "ALUOP1: " << ALUOp1 << "\n" << "ALUOp2: " << ALUOp2 << "\n" << "ALUSrc: " << ALUSrc << "\n" << "MemWrite: " << memWrite << "\n" << "RegWrite: " << regWrite << "\n";};
	


};
#endif
