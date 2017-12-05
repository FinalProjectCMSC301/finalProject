
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
	ProgramCounter *programCounter
    Register *registerFile;
    DataMemory *memoryUnit;
    ALU *alu1;//ToMemory;
    ALU *alu2//AddBranchAndAddress;
    ALU *alu3//AddPCand4;
    ShiftLeft *shiftJump;
    ShiftLeft *shiftBranch;
    ControlUnit *control;
    Multiplexer *registerMultiplexer1;
    Multiplexer *registerOrImmediateMultiplexer2;
    Multiplexer *memoryOrALUMultiplexer3;
    Multiplexer *branchOrIncrementMultiplexer4;
    Multiplexer *jumpOrIncrementMultiplexer5;
    SignExtend *signExtend;
    
    
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
	parser->printInfo();
	
	bool debug_mode = parser->getDebugMode();
	string register_file_input = parser->getRegisterInput();
	string program_input = parser->getProgramInput();
	string output_mode = parser->getOutputMode();
	bool print_memory_contents = parser->getPrintContents();
	bool write_to_file = parser->getWriteToFile();
	string output_file = parser->getOutputFile();
	string memory_contents_input = parser->getMemoryInput();

	// set debug
	registerFile.init();
    registerFile.setFile(register_file_input);

    parse.setFile(programInput);
	memoryUnit.setFile(memory_Contents_Input);
    
    aluAddPCand4.setOperation(1);
    aluAddBranchAndAddress.setOperation(1);
    
    
    //control.setComponents

 
    cout<< "*****CURRENT REGISTERS*****" <<endl;
    registerFile.print();
    cout << endl;
        
    cout<< "*****CURRENT INSTRUCTIONS*****" <<endl;
    //parser.printAllInstructions();
    cout << endl;
        
    cout<< "*****CURRENT DATA MEMORY*****" <<endl;
    memoryUnit.print();
        
    std::ofstream out(outputFile);
    
    while(true){
        
        out << "Current Instruction: " << parse.getInstruction(programCounter.getAddress()).getStringVersion() << endl;
        out<< "*****CURRENT INSTRUCTIONS*****" <<endl;
        out << parse.getAllInstructions();
        
        if(writeToFile){
            out<< "*****CURRENT REGISTERS*****" <<endl;
            out << registerFile.getAllRegisters();
            out << endl;
            out<< "*****CURRENT DATA MEMORY*****" <<endl;
            out << memoryUnit.getAllPairs();
        }
        
        //TODO
        /*
        fetch
        decode
        execute
        memory
        writeback*/
        
        cout<< "*****CURRENT REGISTERS*****" <<endl;
        registerFile.print();
        cout << endl;
            
        cout<< "*****CURRENT INSTRUCTIONS*****" <<endl;
        parse.printAllInstructions();
        cout << endl;
            
        cout<< "*****CURRENT DATA MEMORY*****" <<endl;
         memoryUnit.print();
        
        
        
        if(!batch){
            system("read");
        }
    }
    cout << endl << endl;
    cout << "End of file" << endl;
    out.close();
