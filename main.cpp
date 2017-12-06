
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
	
    
    aluAddPCand4->setOperation(1);
    aluAddBranchAndAddress->setOperation(1);
    
    
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
            branchOrIncrementMultiplexer4.setInput0(currentAddress);
    
       /*
        opcode = currentInstruction.getOpcode();
        rs = currentInstruction.getRs();
        rt = currentInstruction.getRt();
        rd = currentInstruction.getRd();
        immediate = currentInstruction.getImmediate();
        jumpAmount = currentInstruction.getJumpAmount();
        */

         control.sendSignals(opcode);

    
        if (debug)
            cout << "ADJUSTING READ REGISTERS" << endl << endl;
        
        //where to put rs and rt rewrite the code 
        registerFile.setReadRegister1(rs);
        registerFile.setReadRegister2(rt);
    
    
    
    if (debug)
        cout <<"ADJUSTING REGISTER MULTIPLEXER INPUTS" << endl << endl;
        registerMultiplexer1.setInput0(rt);
        registerMultiplexer1.setInput1(rd);
    
    
    if (debug)
        cout <<"SETTING WRITE REGISTER" << endl << endl;
    
    registerFile.setWriteIndex(registerMultiplexer.getOutput());
    
    
    control.sendSignals(opcode);
    
    if (debug)
        cout << endl;
    
    
    jumpAmount = shiftJump.shift(jumpAmount);
    
    if (debug)
        cout << endl;
    
    if (debug)
        cout << "merging: first four bits of current address: " <<currentAddress.substr(0,4) << "  with shifted jump 28 bits: " <<jumpAmount<< " new current address: " << currentAddress.substr(0,4) + jumpAmount <<  endl << endl;
    
    jumpAmount = currentAddress.substr(0,4) + jumpAmount;
    jumpOrIncrementMultiplexer.setInput1(jumpAmount);
    
    
    if (debug)
        cout <<"SIGN EXTENDING IMMEDIATE" << endl << endl;
    
    immediate = signExtend.extend(immediate);
    
    
    if (debug)
        cout <<"ADJUSTING ALU SOURCE MULTIPLEXER INPUT0" << endl << endl;
    
    string temp = registerFile.getReadRegister2();
    registerOrImmediateMultiplexer.setInput0(temp);
    
    
    if (debug)
        cout <<"ADJUSTING ALU SOURCE MULTIPLEXER INPUT1" << endl << endl;
    registerOrImmediateMultiplexer.setInput1(immediate);
    
    
    if (debug)
        cout <<"SETTING THE MEMORY ALU OPERANDS" << endl;
    
    aluToMemory.setOperand1(registerFile.getReadRegister1());
    aluToMemory.setOperand2(registerOrImmediateMultiplexer.getOutput());
    
    
    if (debug)
        cout << "SETTING THE OPERAND2 IN BRANCH AND CURRENT ADDRESS ALU" << endl << endl;
    
    immediate = shiftBranch.shift(immediate);
    aluAddBranchAndAddress.setOperand2(immediate);
    
    
    aluAddBranchAndAddress.execute();
    branchOrIncrementMultiplexer.setInput1(aluAddBranchAndAddress.getOutput());
    

        





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
