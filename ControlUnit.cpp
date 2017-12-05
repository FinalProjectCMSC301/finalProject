#include "ControlUnit.h"

ControlUnit::ControlUnit(){
	
}

void ControlUnit::setControls(string bitString){
	
	//R-TYPE 
 	if (bitString.compare("000000")==0){
        setRegDST("1");
	   setALUSrc("0");
		setMemtoReg("0");
		setRegWrite("1");
		setMemRead("0");
		setMemWrite("0");
		setBranch("0");
		setJump("0");
		setALUOp1("1");
		setALUOp2("0");
	}

	//LW
	else if (bitString.compare("100011")==0){
	setRegDST("0");
	setALUSrc("1");
	setRegWrite("1");
	setMemtoReg("1");
	setMemWrite("0");
	setMemRead("1");
	setBranch("0");
	setJump("0");
	setALUOp1("0");
	setAluOp2("0");

	}

	//SW
	else if (bitString.compare("101011")==0){
		setRegDST("x");
		setALUSrc("1");
		setMemtoReg("x");
		setRegWrite("0");
		setMemRead("0");
		setMemWrite("1");
		setBranch("0");
		setJump("0");
		setALUOp1("0");
		setAluOp2("0");


}

	//BEQ
	else if (bitString.compare("000100")==0){
	setRegDST("x");
	setALUSrc("0");
	setMemtoReg("x");
	setRegWrite("0");
	setMemRead("0");
	setMemWrite("0");
	setBranch("1");
	setJump("0");
	setALUOp1("0");
	setAluOp2("1");

}

	//jump
	else if (bitString.compare("000010")==0){
	setRegDST("1");
	setALUSrc("1");
	setMemtoReg("0");
	setRegWrite("0");
	setMemRead("0");
	setMemWrite("0");
	setBranch("0");
	setJump("1");
	setALUOp1("x");
	setAluOp2("x");
}
	//ADDI
	else if (bitString.compare("001000")==0){
		setRegDST("0");
		setALUSrc("1");
		setMemtoReg("0");
		setRegWrite("1");
		setMemRead("0");
		setMemWrite("0");
		setBranch("0");
		setJump("0");
		setALUOp1("1");
		setAluOp2("0");

}
	printValues();

}