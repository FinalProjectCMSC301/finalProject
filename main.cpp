
#include "Parser.h"
#include <iostream>
#include "ShiftLeft.h"
#include "Register.h"
#include "DataMemory.h"
#include "ProgramCounter.h"
#include "ControlUnit.h"
#include "ALU.h"
#include "Multiplexer.h"
#include "SignExtend.h"
using namespace std;

int main (int argc, char *argv[]){
	Parser *parser;
	ProgramCounter *programCounter;
    Register *registerFile;
    DataMemory *memoryUnit;
    ALU *alu1;//ToMemory
    ALU *alu2;//AddBranchAndAddress
    ALU *alu3;//AddPCand4
    ShiftLeft *shiftJump;
    ShiftLeft *shiftBranch;
    ControlUnit *control;
    Multiplexer *registerMultiplexer1;
    Multiplexer *registerOrImmediateMultiplexer2;
    Multiplexer *memoryOrALUMultiplexer3;
    Multiplexer *branchOrIncrementMultiplexer4;
    Multiplexer *jumpOrIncrementMultiplexer5;
    SignExtend *signExtend;
    BinaryOperation *BinaryOp;
    
    
    string currentAddress;
    Instruction *currentInstruction;
    
    string opcode;
    string rs;
    string rt;
    string rd;
    string immediate;
    string jumpAmount;
	// began to run 
	
	//Start the Parser
	parser = new Parser(argv[1]);
	parser->PrintInfo();
	
	//Get all the values from the parser
	bool debug_mode = parser->getDebugMode();
	string register_file_input = parser->getRegisterInput();
	string program_input = parser->getProgramInput();
	string output_mode = parser->getOutputMode();
	bool print_memory_contents = parser->getPrintContents();
	bool write_to_file = parser->getWriteToFile();
	string output_file = parser->getOutputFile();
	string memory_contents_input = parser->getMemoryInput();

	//Run Register File
	registerFile = new Register(register_file_input, debug_mode);
	
   	
	//Create the Memory Unit
        memoryUnit = new DataMemory(memory_contents_input, debug_mode);
	
    
    alu3->setOperation(1);
    alu2->setOperation(1);
    
    
    //control.setComponents

 
    cout<< "*****CURRENT REGISTERS*****" <<endl;
    registerFile->print();
    cout << endl;
        
    cout<< "*****CURRENT INSTRUCTIONS*****" <<endl;
    //parser.printAllInstructions();
    cout << endl;
        
    cout<< "*****CURRENT DATA MEMORY*****" <<endl;
    memoryUnit->print();
        
    std::ofstream out(output_file);
    
    while(true){
        
        out << "Current Instruction: " << parse->getInstruction(programCounter->getAddress())->getStringVersion() << endl;
        out<< "*****CURRENT INSTRUCTIONS*****" <<endl;
        out << parse->getAllInstructions();
        
        if(write_to_file){
            out<< "*****CURRENT REGISTERS*****" <<endl;
            out << registerFile->getAllRegisters();
            out << endl;
            out<< "*****CURRENT DATA MEMORY*****" <<endl;
            //out << memoryUnit->getAllPairs();
        }
        
        //TODO
        /*
        fetch
        decode
        execute
        memory
        writeback*/

        //fetch 
        //currentInstruction TODO
        alu3.setOperand1(programCounter.getAddress());
        alu3.setOperand2("00000000000000000000000000000100");
        alu3.execute();
        currentAddress = alu3.getOutput();

        if (debug)
            cout << "address for instruction: " << BinaryOp.getHexFromBin(currentAddress) << endl << endl;
    
        if (debug)
            cout << "SETTING THE OPERAND1 IN BRANCH AND CURRENT ADDRESS ALU" << endl << endl;
    
        alu2.setOperand1(currentAddress);
    
    
        if (debug)
            cout << "SETTING THE MULTIPLEXER FOR BRANCH VS CURRENT ADDRESS" << endl << endl;
            
            // write multplexer to store 
            branchOrIncrementMultiplexer44.setInput0(currentAddress);
    
       /*
       re
        opcode = currentInstruction.getOpcode();
        rs = currentInstruction.getRs();
        rt = currentInstruction.getRt();
        rd = currentInstruction.getRd();
        immediate = currentInstruction.getImmediate();
        jumpAmount = currentInstruction.getJumpAmount();
        */


        //decode  change
         control.sendSignals(opcode);

    
        if (debug)
            cout << "ADJUSTING READ REGISTERS" << endl << endl;
        
        //where to put rs and rt rewrite the code 
        registerFile.setReadRegister1(rs);
        registerFile.setReadRegister2(rt);
    
    
    
    if (debug)
        cout <<"ADJUSTING REGISTER MULTIPLEXER INPUTS" << endl << endl;
    //rewrite multiplexerto store 
        registerMultiplexer1.setInput0(rt);
        registerMultiplexer1.setInput1(rd);
    
    
    if (debug)
        cout <<"SETTING WRITE REGISTER" << endl << endl;
    
    //how do we write the register setup for write depend on the Mux of multiplexer 

    //registerFile.setWriteIndex(registerMultiplexer1.getOutput());
    
    //?
    control.sendSignals(opcode);
    
   
    
    jumpAmount = shiftJump.shift(jumpAmount);
    
    
    
    if (debug)
        cout << "get the first four bits of current address: " <<currentAddress.substr(0,4) << "  with shifted jump 28 bits: " <<jumpAmount<< " new current address: " << currentAddress.substr(0,4) + jumpAmount <<  endl << endl;
    
    jumpAmount = currentAddress.substr(0,4) + jumpAmount;

    //rewrite the multpliexer 
    jumpOrIncrementMultiplexer5.setInput1(jumpAmount);
    
    
    if (debug)
        cout <<"SIGN EXTENDING IMMEDIATE" << endl << endl;
    
    immediate = signExtend.extend(immediate);
    
    
    if (debug)
        cout <<"ADJUSTING ALU SOURCE MULTIPLEXER INPUT0" << endl << endl;
    
    string temp = registerFile.getReadRegister2();

    //need to change to store 
    registerOrImmediateMultiplexer2.setInput0(temp);
    
    
    if (debug)
        cout <<"ADJUSTING ALU SOURCE MULTIPLEXER INPUT1" << endl << endl;

    //need to change to store 
        registerOrImmediateMultiplexer2.setInput1(immediate);
    
    
    if (debug)
        cout <<"SETTING THE MEMORY ALU OPERANDS" << endl;
    
        alu1.setOperand1(registerFile.getReadRegister1());
        alu1.setOperand2(registerOrImmediateMultiplexer2.getOutput());
    
    
    if (debug)
        cout << "SETTING THE OPERAND2 IN BRANCH AND CURRENT ADDRESS ALU" << endl << endl;
    
        immediate = shiftBranch.shift(immediate);
     aluAddBranchAndAddress.setOperand2(immediate);
    
    
    aluAddBranchAndAddress.execute();
    branchOrIncrementMultiplexer4.setInput1(aluAddBranchAndAddress.getOutput());



    //excute
     if (debug)
        cout <<"EXECUTING MEMORY ALU" << endl;
    
    aluToMemory.execute();
    
    if (debug)
        cout <<"SETTING BRANCH OR INCREMENTED ADDRESS MULTIPLEXER CONTROL " << endl;
    
    branchOrIncrementMultiplexer4.setControl(control.isBranch() && alu1.getComparisonResult());
    
    if(debug)
        cout <<"SETTING JUMP OR INCREMENTED ADDRESS INPUT0" << endl;
    jumpOrIncrementMultiplexer5.setInput0(branchOrIncrementMultiplexer4.getOutput());
    


    //memory
    
    
    if (debug)
        cout <<"SETTING DATA MEMORY ADDRESS AND WRITE DATA" << endl;

    string temp = aluToMemory.getOutput();
    memoryUnit.setCurrentAddress(temp);
    temp = registerFile.getReadRegister2();
    memoryUnit.storeWord(temp);
    memoryUnit.saveMemory();
    
    
    
    if (debug)
        cout <<"SETTING MEMORY OR ALU MULTIPLEXER AS WELL AS WRITE DATA" << endl;

    memoryOrALUMultiplexer3.setInput1(memoryUnit.readMemory());
    memoryOrALUMultiplexer3.setInput0(aluToMemory.getOutput());
    registerFile.setWriteValue(memoryOrALUMultiplexer3.getOutput());
    


        //writeback
    registerFile.write();
    programCounter.setAddress(jumpOrIncrementMultiplexer5.getOutput());
    
    //
    if(!parse.`( programCounter.getAddress())){
        cout <<"Next Instruction to run: ";parse.getInstruction(programCounter.getAddress()).print();
    }

    
    

        cout<< "*****CURRENT REGISTERS*****" <<endl;
        registerFile.print();
        cout << endl;
            
        cout<< "*****CURRENT INSTRUCTIONS*****" <<endl;
        parse.printAllInstructions();
        cout << endl;
            
        cout<< "*****CURRENT DATA MEMORY*****" <<endl;
         memoryUnit.print();
        
        
        
        if(output_mode.compare("single_step")==0){
            system("read");
        }
    }
    cout << endl << endl;
    cout << "End of file" << endl;
    out.close();
}
