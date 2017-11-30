#ifndef __CONTROLUNIT_H__
#define __CONTROLUNIT_H__

using namespace std;
#include <fstream>
#include <iostream>

class controlUnit{
public:
	controlUnit(string bitString);
private:
	string regDst;
	string jump;
	string branch;
	string memRead;
	string memtoReg;
	string ALUOp;
	string memWrite;
	string ALUSrc;
	string regWrite;

	string getRegDST(){return regDst;};
	string getJump(){return jump;};
	string getBranch(){return branch;};
	string getMemRead(){return memRead;};
	string getMemtoReg(){return memtoReg;};
	string getALUOp(){return ALUOp;};
	string getMemWrite(){return memWrite;};
	string getALUSrc(){return ALUSrc;};
	string getRegWrite(){return regWrite;};

	string setRegDST(string reg){regDst = reg;};
	string setJump(string j){ jump = j;};
	string setBranch(string b){ branch = b;};
	string setMemRead(string mem){ memRead = mem;};
	string setMemtoReg(string mem){ memtoReg = mem;};
	string setALUOp(string alu){ ALUOp = alu;};
	string setMemWrite(string mem){ memWrite = mem;};
	string setALUSrc(string alu){ ALUSrc = alu;};
	string setRegWrite(string reg){ regWrite = reg;};
	void printValues(){cout << "RegDST: " << regDst << "\n" << "Branch: " << branch << "\n" << "Jump: " << jump << "\n" << "MemRead: " << memRead << "\n" << "MemtoReg: " << memtoReg << "\n" << "ALUOP: " << ALUOp << "\n" << "ALUSrc: " << ALUSrc << "\n" << "MemWrite: " << memWrite << "\n" << "RegWrite: " << regWrite << "\n";};
	


};
#endif
