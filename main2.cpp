//main2.cpp
#include "ProgramCounter.h"
#include "InstructionMemory.h"
#include "Register.h"
#include "SignExtend.h"
#include "AluControl.h"
#include "ALU_ALU_Result.h"
#include "ADD_ALU_Result.h"
#include "Add.h"
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
	ShiftLeft shiftJump2628;
	ShiftLeft shiftImm32;
	ProgramCounter pc;
	AluControl aluC;
	ALU_ALU_Result alu1;
	ADD_ALU_Result alu2;
	Add aluADD;
	ControlUnit cu;
	BinaryOperation bo;
	Multiplexer Multiplexer1;
	Multiplexer Multiplexer2;
	Multiplexer Multiplexer3;
	Multiplexer Multiplexer5;
	Multiplexer Multiplexer4;
	string complete("");
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
		cout << cu.getStringValues();
		Multiplexer1.setControl(cu.getRegDST());
		Multiplexer4.setControl(cu.getJump());
		alu1.setBranchBit(cu.getBranch());
		if(cu.getMemRead() == "1")
		{
			dm.setRead(1);
		}
		else
		{
			dm.setRead(0);
		}
		Multiplexer3.setControl(cu.getMemtoReg());
		aluC.setALUOp(cu.getALUOp());
		if(cu.getMemWrite() == "1")
		{
			dm.setWrite(1);
		}
		else
		{
			dm.setWrite(0);
		}
		Multiplexer2.setControl(cu.getALUSrc());
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
		
		//Multiplexer1
		Multiplexer1.setOne(rd);
		Multiplexer1.setTwo(rt);
		complete += "Input for Multiplexer 1: Register" + bo.binToInt(rt) + "Register " + bo.binToInt(rd) + " Control Signal: " + cu.getRegDST() + endl; 
		cout << "Input for Multiplexer 1: Register" << bo.binToInt(rt) << "Register " << bo.binToInt(rd) << " Control Signal: " << cu.getRegDST() << endl; 
		complete+="Output for Multiplexer 1: " + bo.binToInt(Multiplexer1.getOutput()) + endl;
		cout <<"Output for Multiplexer 1: " << bo.binToInt(Multiplexer1.getOutput()) << endl;
		int writeRegNum = bo.binToInt(Multiplexer1.getOutput());
		string regReadData1 = rm.read(bo.binToInt(rs));	//input to ALU_ALU_Result
		string regReadData2 = rm.read(bo.binToInt(rt)); //input to Multiplexer2
		
		//Multiplexer2
		Multiplexer2.setTwo(regReadData2);
		SignExtend se(immediate);
		complete += "Sign Extend Input: "+ immediate +"\n" + "Sign Extend Output: " + se.getExtended() + endl;
		cout << "Sign Extend Input: "<< immediate +"\n" << "Sign Extend Output: " << se.getExtended() << endl;
		Multiplexer2.setOne(se.getExtended());
		//the output will go to ALU_ALU_Result
		complete+= "Input for Multiplexer 2: " + regReadData2 +" " + se.getExtended()+ " Control Signal: " + cu.getALUSrc() + endl;
		complete+= "Output for Multiplexer 2: " + Multiplexer2.getOutput() + endl;
		cout<<"Input for Multiplexer 2: " << regReadData2 <<" " << se.getExtended()<< " Control Signal: " << cu.getALUSrc() << endl;
		cout<< "Output for Multiplexer 2: " << Multiplexer2.getOutput() << endl;
		
		/**	Setting AluControl
		*/
		complete += "ALU Control Input: "+ funct_field +"\n" + "ALU Control Output: " + aluC.getOutput() + endl;
		cout << "ALU Control Input: "<< funct_field +"\n" << "ALU Control Output: " << aluC.getOutput() << endl;
		aluC.setFunct(funct_field);
		
		/**	Working ALU_ALU_Result
		*/
		
		alu1.setAluControlInput(aluC.getOutput());
		alu1.setDataFromReg(regReadData1);
		alu1.setDataFromMux(Multiplexer2.getOutput());
		alu1.execute();
		complete+= "alu1 Input: " + regReadData1 + " " + Multiplexer1.getOutput() + " Control Signal: " + aluC.getInput() + endl;
		complete+= "alu1 Output: " + alu1.getHexOutput() + endl;
		cout<< "alu1 Input: " << regReadData1 << " " << Multiplexer1.getOutput() << " Control Signal: " << aluC.getInput() << endl;
		cout<< "alu1 Output: " << alu1.getHexOutput() << endl;
		if(alu1.getBranchBit() == "1" && bo.binToInt(alu1.getBinaryOutput()) == 0)
		{
			Multiplexer5.setControl("1");	//meaning, you branch
		}
		if(cu.getMemWrite() == "1"){
		complete+= "Writing to address " << alu1.getHexOutput() << " the data " << regReadData2 << endl;
		cout<< "Writing to address " << alu1.getHexOutput() << " the data " << regReadData2 << endl;
		}
		dm.writeToMemory(alu1.getHexOutput(), regReadData2);	//writing to memory
		
		/**	Setting multiplexers and writing back
		*/
		Multiplexer3.setOne(dm.read(alu1.getHexOutput()));
		Multiplexer3.setTwo(alu1.getHexOutput());
		complete += "Multiplexer 3 Input: " + alu1.getHexOutput() + " " + dm.read(alu1.getHexOutput()) + " Control Signal: " + cu.getMemtoReg() + endl;  
		complete += "Multiplexer 3 Output: " + Multiplexer3.getOutput();
		cout << "Multiplexer 3 Input: " << alu1.getHexOutput() << " " << dm.read(alu1.getHexOutput()) << " Control Signal: " << cu.getMemtoReg() << endl;  
		cout << "Multiplexer 3 Output: " << Multiplexer3.getOutput();
		if(cu.getMemWrite() == "1"){
		complete += "Writing to register " + writeRegNum + " with data " + Multiplexer3.getOutput() + endl;
		cout<< "Writing to register " << writeRegNum << " with data " << Multiplexer3.getOutput() << endl;
		}
		rm.writeToRegister(writeRegNum, Multiplexer3.getOutput());
		/**	Preparing jump address in binary
		*/
		
		string jumpShiftPart = shiftJump2628.shift(jump);
		complete += "Shift Input: "+ jump +"\n" + "Shift Output: " + jumpShiftPart + endl;
		cout << "Shift Input: "<< jump +"\n" << "Shift Output: " << jumpShiftPart << endl;
		//jump part ready
		aluADD.setPCInput(pc.getAddress());
		aluADD.update();
		complete += "aluADD Input: " + pc.getAddress() + " " + "0x00000004" + endl;
		complete += "aluDD Output: " + aluADD.getHexOutput()+endl;
		cout<< "aluADD Input: " << pc.getAddress() << " " << "0x00000004" << endl;
		cout<< "aluDD Output: " << aluADD.getHexOutput()<<endl;
		string pcPlusFour = aluADD.getHexOutput();	//PC + 4 address, IN HEX
		pcPlusFour = bo.hexToBin(pcPlusFour, 32);	//in binary
		pcPlusFour = pcPlusFour.substr(0, 4);	//top 4 bits
		string totalJump = pcPlusFour + jumpShiftPart;
		
		/**	Preparing two inputs to alu2
		*/
		SignExtend forImm(immediate);	//put this through shift left
		string extended = forImm.getExtended();	//32 bits
		complete += "Sign Extend Input: "+ immediate +"\n" + "Sign Extend Output: " + extended + endl;
		cout << "Sign Extend Input: "<< immediate +"\n" << "Sign Extend Output: " << extended << endl;
		extended = shiftImm32.shift(extended);	//34 bits now
		complete += "Shift Imm Input: "+ extended +endl; 
		cout << "Shift Imm Input: "<< extended << endl; 
		extended = extended.erase(0, 2);
		"Shift Imm Output: " << extended << endl;
		"Shift Imm Output: " + extended + endl;
		string pcPlusFour2 = aluADD.getHexOutput();
		pcPlusFour2 = bo.hexToBin(pcPlusFour2, 32);	//using this as Multiplexer5
		
		alu2.setAlu2Input(pcPlusFour2);
		alu2.setShiftInput(extended);
		
		//preparing Multiplexer5
		Multiplexer5.setOne(alu2.getBinaryOutput());
		Multiplexer5.setTwo(pcPlusFour2);
		complete += "Multiplexer 5 Input : " + pcPlusFour2 + " " + alu2.getHexOutput()+ " Control Signal: " + (alu1.getBranchBit() && !bo.binToInt(alu1.getBinaryOutput())) + endl;
		complete += "Multiplexer 5 Output : " + Multiplexer5.getHexOutput() + endl;
		cout<< "Multiplexer 5 Input : " << pcPlusFour2 << " " + alu2.getHexOutput()<< " Control Signal: " << (alu1.getBranchBit() && !bo.binToInt(alu1.getBinaryOutput())) << endl;
		cout<< "Multiplexer 5 Output : " << Multiplexer5.getHexOutput() << endl;
		
		//preparing Multiplexer4
		Multiplexer4.setOne(totalJump);
		Multiplexer4.setTwo(Multiplexer5.getOutput());
		complete += "Multiplexer 4 Input : " + Multiplexer5.getHexOutput()+ " " + totalJump +" Control Signal: " + cu.getJump() + endl;
		complete += "Multiplexer 4 Output : " + Multiplexer4.getHexOutput() + endl;
		cout<<"Multiplexer 4 Input : " << Multiplexer5.getHexOutput()<< " " << totalJump <<" Control Signal: " << cu.getJump() << endl;
		cout<< "Multiplexer 4 Output : " << Multiplexer4.getHexOutput() << endl;
		
		string hexAddress = bo.binToHex(Multiplexer4.getOutput(), 8);
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
