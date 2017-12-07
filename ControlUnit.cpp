#include "ControlUnit.h"
#include <iostream>
#include <sstream>

using namespace std;
ControlUnit::ControlUnit(){
	
}

void ControlUnit::setControls(string bitString){
	
	//R-type
 	if (bitString.compare("000000")==0){
		//cout << "Input: " << bitString << "\n";
      		  setRegDST("1");
	 	  setALUSrc("0");
		setMemtoReg("0");
		setRegWrite("1");
		setMemRead("0");
		setMemWrite("0");
		setBranch("0");
		setJump("0");
		setALUOp0("0");
		setALUOp1("1");
	}

	//LW
	else if (bitString.compare("100011")==0){
	//cout << "Input: " << bitString << "\n";
	setRegDST("0");
	setALUSrc("1");
	setRegWrite("1");
	setMemtoReg("1");
	setMemWrite("0");
	setMemRead("1");
	setBranch("0");
	setJump("0");
	setALUOp0("0");
	setALUOp1("0");

	}

	//SW
	else if (bitString.compare("101011")==0){
		//cout << "Input: " << bitString << "\n";
		setRegDST("x");
		setALUSrc("1");
		setMemtoReg("x");
		setRegWrite("0");
		setMemRead("0");
		setMemWrite("1");
		setBranch("0");
		setJump("0");
		setALUOp0("0");
		setALUOp1("0");


	}

	//BEQ
	else if (bitString.compare("000100")==0){
		//cout<< "In the branch" << endl;
	setRegDST("x");
		//cout<< "Here" << endl;
	setALUSrc("0");
	setMemtoReg("x");
	setRegWrite("0");
	setMemRead("0");
	setMemWrite("0");
	setBranch("1");
	setJump("0");
	setALUOp0("1");
	setALUOp1("0");

	}

	//jump
	else if (bitString.compare("000010")==0){
		//cout << "Input: " << bitString << "\n";
	setRegDST("1");
	setALUSrc("1");
	setMemtoReg("0");
	setRegWrite("0");
	setMemRead("0");
	setMemWrite("0");
	setBranch("0");
	setJump("1");
	setALUOp0("x");
	setALUOp1("x");
}
	//ADDI
	else if (bitString.compare("001000")==0){
	//cout << "Input: " << bitString << "\n";
		setRegDST("0");
		setALUSrc("1");
		setMemtoReg("0");
		setRegWrite("1");
		setMemRead("0");
		setMemWrite("0");
		setBranch("0");
		setJump("0");
		setALUOp0("1");
		setALUOp1("1");

	}
	
	
	else{
		cout << "failed to find match" << endl;
	}
	

}

string check(string s)
{
	if(s[0] == 'x' || s[0] == 'X')
	{
		return "";
	}
	else if(s[0] == '1')
	{
		string ret("0x00000001");
		return ret;
	}
	else
	{
		string ret("0x00000000");
		return ret;
	}
}

string ControlUnit::printStringValues(){
	stringstream s; 
	s << "RegDST: " << check(regDst) << "\n" << "Branch: " << check(branch) << "\n" << "Jump: " << check(jump) << "\n" << "MemRead: " << check(memRead) << "\n" << "MemtoReg: " << check(memtoReg) << "\n" << "ALUOP0: " << check(ALUOp0) << "\n" << "ALUOp1: " << check(ALUOp1) << "\n" << "ALUSrc: " << check(ALUSrc) << "\n" << "MemWrite: " << check(memWrite) << "\n" << "RegWrite: " << check(regWrite) << "\n"; 
	return s.str();
}