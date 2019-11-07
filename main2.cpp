//main2.cpp
#include "ProgramCounter.h"
#include "InstructionMemory.h"
#include "Register.h"
#include "SignExtend.h"
#include "AluControl.h"
#include "ALU_ALU_Result.h"
#include "ADD_ALU_Result.h"
#include "ADD.h"
#include "DataMemory.h"
#include "ShiftLeft.h"
#include "ControlUnit.h"
#include "BinaryOperation.h"
#include "Multiplexer.h"
#include "Parser.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	Parser parser(argv[1]);
	InstructionMemory im(parser.getProgramInput());
	Register rm(parser.getRegisterInput(), 0);
	DataMemory dm(parser.getMemoryInput(), 0);
	ShiftLeft shiftJump;
	ShiftLeft shiftImm;
	ProgramCounter pc;
	AluControl aluC;
	ALU_ALU_Result alu1;
	ADD_ALU_Result alu2;
	ADD alu3;
	ControlUnit cu;
	BinaryOperation bo;
	Multiplexer instMux;
	Multiplexer regMux;
	Multiplexer dataMux;
	Multiplexer alu2Mux;
	Multiplexer pcMux;
	string complete("");
	ofstream outputFile;
	//STARTING HERE
	string currentInst(im.getInstructionPC(pc.getAddress()));
	while(currentInst != "")
	{
	cout << "*****INSTRUCTION*****" << endl;
	cout << currentInst << endl;
		//Instruction Parts
		string rs =  currentInst.substr(6, 5);
		string rt = currentInst.substr(11, 5);
		string rd = currentInst.substr(16, 5);
		string opcode = currentInst.substr(0, 6);
		string funct_field = currentInst.substr(26, 6);
		string immediate = currentInst.substr(16, 16);
		string jump = currentInst.substr(6, 26);
		
		if(parser.getWriteToFile()){
		 outputFile.open(parser.getOutputFile());
		}
		
		//Setting Controls
		cu.setControls(opcode);
		cout<< "Controls for the Instruction: \n" << cu.printStringValues()<< endl;
		instMux.setControl(cu.getRegDST());
		pcMux.setControl(cu.getJump());
		alu1.setBranchBit(cu.getBranch());
		if(cu.getMemRead() == "1")
		{
			dm.setRead(1);
		}
		else
		{
			dm.setRead(0);
		}
		dataMux.setControl(cu.getMemtoReg());
		aluC.setALUOp(cu.getALUOp());
		if(cu.getMemWrite() == "1")
		{
			dm.setWrite(1);
		}
		else
		{
			dm.setWrite(0);
		}
		regMux.setControl(cu.getALUSrc());
		if(cu.getRegWrite() == "1")
		{
			rm.setWrite(1);
		}
		else
		{
			rm.setWrite(0);
		}
		
		/**	Setting multiplexers
		*/
		
		//instMux
		instMux.setOne(rd);
		instMux.setTwo(rt);
		complete += "Input for Multiplexer 1: Register" + bo.binToInt(rt) + "Register " + bo.binToInt(rd) + " Control Signal: " + cu.getRegDST() + endl; 
		int writeRegNum = bo.binToInt(instMux.getOutput());
		complete+="Output for Multiplexer 1: " + bo.binToInt(instMux.getOutput()) + endl;
		string regReadData1 = rm.read(bo.binToInt(rs));	//input to ALU_ALU_Result
		string regReadData2 = rm.read(bo.binToInt(rt)); //input to regMux
		
		//regMux
		regMux.setTwo(regReadData2);
		SignExtend se(immediate);
		regMux.setOne(se.getExtended());
		complete+= "Input for Multiplexer 2: " + regReadData2 +" " + se.getExtended()+ " Control Signal: " + cu.getALUSrc() + endl;
		complete+= "Output for Multiplexer 2: " + regMux.getOutput() + endl;
		//the output will go to ALU_ALU_Result
		
		/**	Setting AluControl
		*/
		
		aluC.setFunct(funct_field);
		
		/**	Working ALU_ALU_Result
		*/
		
		alu1.setAluControlInput(aluC.getOutput());
		alu1.setDataFromReg(regReadData1);
		alu1.setDataFromMux(regMux.getOutput());
		alu1.execute();
		complete+= "alu1 Input: " + regReadData1 + " " + regMux.getOutput() + " Control Signal: " + aluC.getInput() + endl;
		complete+= "alu1 Output: " + alu1.getHexOutput() + endl;
		if(alu1.getBranchBit() == "1" && bo.binToInt(alu1.getBinaryOutput()) == 0)
		{
			alu2Mux.setControl("1");	//meaning, you branch
		}
		complete+= "Writing to address " + alu1.getHexOutput() + " the data " + regReadData2 + endl;
		dm.writeToMemory(alu1.getHexOutput(), regReadData2);	//writing to memory
		
		/**	Setting multiplexers and writing back
		*/
		dataMux.setOne(dm.read(alu1.getHexOutput()));
		dataMux.setTwo(alu1.getHexOutput());
		complete += "Multiplexer 3 Input: " + alu1.getHexOutput() + " " + dm.read(alu1.getHexOutput()) + " Control Signal: " + cu.getMemtoReg() + endl;  
		complete += "Multiplexer 3 Output: " + dataMux.getOutput();
		complete += "Writing to register " + writeRegNum + " with data " + dataMux.getOutput() + endl;
		rm.writeToRegister(writeRegNum, dataMux.getOutput());
		/**	Preparing jump address in binary
		*/
		string jumpShiftPart = shiftJump.shift(jump);	//jump part ready
		alu3.setPCInput(pc.getAddress());
		alu3.update();
		complete += "alu3 Input: " + pc.getAddress() + " " + "0x00000004" + endl;
		complete += "alu3 Output: " + alu3.getHexOutput()+endl;
		string pcPlusFour = pc.getAddress();	//PC + 4 address, IN HEX
		pcPlusFour = bo.hexToBin(pcPlusFour, 32);	//in binary
		pcPlusFour = pcPlusFour.substr(0, 4);	//top 4 bits
		string totalJump = pcPlusFour + jumpShiftPart;
		
		/**	Preparing two inputs to alu2
		*/
		SignExtend forImm(immediate);	//put this through shift left
		string extended = forImm.getExtended();	//32 bits
		extended = shiftImm.shift(extended);	//34 bits now
		extended = extended.erase(0, 2);
		string pcPlusFour2 = pc.getAddress();
		pcPlusFour2 = bo.hexToBin(pcPlusFour2, 32);	//using this as alu2Mux
		
		alu2.setAlu2Input(pcPlusFour2);
		alu2.setShiftInput(extended);
		
		//preparing alu2Mux
		alu2Mux.setOne(alu2.getBinaryOutput());
		alu2Mux.setTwo(pcPlusFour2);
		complete += "Multiplexer 5 Input : " + pcPlusFour2 + " " + alu2.getHexOutput()+ " Control Signal: " + (alu1.getBranchBit() && !bo.binToInt(alu1.getBinaryOutput())) + endl;
		complete += "Multiplexer 5 Output : " + alu2Mux.getHexOutput() + endl;
		//preparing pcMux
		pcMux.setOne(totalJump);
		pcMux.setTwo(alu2Mux.getOutput());
		
		complete += "Multiplexer 4 Input : " + alu2Mux.getHexOutput()+ " " + totalJump +" Control Signal: " + cu.getJump() + endl;
		complete += "Multiplexer 4 Output : " + pcMux.getHexOutput() + endl;
		
		string hexAddress = bo.binToHex(pcMux.getOutput(), 8);
		pc.setAddress(hexAddress);
		
		//if instruction is a jump or a branch, change PC
		//AT THE END
		complete.append("Instruction: ");
		complete.append(currentInst);
		complete.append("\n\n");
		complete.append("Control Signals:\n");
		complete.append(cu.printStringValues());
		complete.append("\n\n");
		complete.append("Register:\n");
		complete.append(rm.print());
		complete.append("\n\n");
		complete.append("Data Memory:\n");
		complete.append(dm.print());
		complete.append("\n\n");
		currentInst = im.getInstructionPC(pc.getAddress());
		
		
		if(parser.getWriteToFile()){
			outputFile<< complete;
		}
		
		if(parser.getOutputMode().compare("single_step")==0){
			string wait;
			cin >> wait;
		}
		
		ProgramCounter p2;
		p2.setAddress(pc.getAddress());
		p2.updatePC(p2.getAddress());
		string nextInst = im.getInstructionPC(p2.getAddress());
		if(nextInst.size() == 0)
		{
			break;
		}
		
	}
	cout << complete << endl;
	outputFile.close();
	return 0;
}
