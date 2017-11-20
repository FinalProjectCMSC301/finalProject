#include "controlUnit.h"

controlUnit::controlUnit(string bitString){
	
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
		setALUOp("10");
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
	setALUOp("00");

	}

	//SW
	else if (bitString.compare("101011")==0){
		setRegDST("TBD");
		setALUSrc("1");
		setMemtoReg("TBD");
		setRegWrite("0");
		setMemRead("0");
		setMemWrite("1");
		setBranch("0");
		setJump("0");
		setALUOp("00");


}

	//BEQ
	else if (bitString.compare("000100")==0){
	setRegDST("TBD");
	setALUSrc("0");
	setMemtoReg("TBD");
	setRegWrite("0");
	setMemRead("0");
	setMemWrite("0");
	setBranch("1");
	setJump("0");
	setALUOp("01");

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
	setALUOp("");
}
	//ADDI
	else if (bitString.compare("001000")==0){
		setRegDST("");
		setALUSrc("");
		setMemtoReg("");
		setRegWrite("");
		setMemRead("");
		setRegWrite("");
		setMemRead("");
		setMemWrite("");
		setBranch("0");
		setJump("0");
		setALUOp("10");	






}

}
