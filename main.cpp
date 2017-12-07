
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
#include "ALUControl.h"
using namespace std;

int main (int argc, char *argv[]){
    Parser *parser;
    ProgramCounter *programCounter = new ProgramCounter();
    Register *registerFile;
    DataMemory *memoryUnit;
    ALU *alu1 = new ALU();//ToMemory
    ALU *alu2 = new ALU();//AddBranchAndAddress
    ALU *alu3 = new ALU();//AddPCand4
    ShiftLeft *shiftJump = new ShiftLeft();
    ShiftLeft *shiftBranch = new ShiftLeft();
    ControlUnit *control = new ControlUnit();
    Multiplexer *registerMultiplexer1 = new Multiplexer();
    Multiplexer *registerOrImmediateMultiplexer2 = new Multiplexer();
    Multiplexer *memoryOrALUMultiplexer3 = new Multiplexer();
    Multiplexer *branchOrIncrementMultiplexer4 = new Multiplexer();
    Multiplexer *jumpOrIncrementMultiplexer5 = new Multiplexer();
    SignExtend *signExtend; 
    ALUControl *aluControl;	
    BinaryOperation *BinaryOp = new BinaryOperation();
    InstructionMemory *currentInstruction;
    
    
    string currentAddress;
	
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
	
	//Set up the BinaryOpeations
	BinaryOp = new BinaryOperation();
	
	//Starts Address for Program Counter
	programCounter = new ProgramCounter();
	currentAddress = programCounter->getAddress();
	
	//Set up the instruction memory
	currentInstruction = new InstructionMemory(program_input);
	
    alu3->setOperation(1);
    alu2->setOperation(1);
    
        
    //std::ofstream out(output_file);
    
    while(true){
        
        //out << "Current Instruction: " << parse->getInstruction(programCounter->getAddress())->getStringVersion() << endl;
        out<< "*****CURRENT INSTRUCTIONS*****" <<endl;
        //out << parse->getAllInstructions();
        
        if(write_to_file){
            out<< "*****CURRENT REGISTERS*****" <<endl;
            out << registerFile->getAllRegisters();
            out << endl;
            out<< "*****CURRENT DATA MEMORY*****" <<endl;
            //out << memoryUnit->getAllPairs();
        }
        
       
	    
	 //Sets the inputs to increase the program counter   
        alu3->setOperand1(programCounter->getAddress());
        alu3->setOperand2("00000000000000000000000000000100");//write 4 
	    
	 //increases the program counter
        alu3->execute();
        
        alu2->setOperand1(currentAddress);
    
	    
//GET THE INSTRUCTION
	    
	    string instruction = currentInstruction->getInstruction();
         
//Runs the control unit and sets control lines
	   
	    control->setControls(instruction.substr(0,6));
				 
				 
				 
//Look to see if it is jump because will avoid all bottom stuff. Do after calculate options
	
	if(control->getJump().compare("1")==0){
    //maybe not right 
    string jumpAmount = instruction.substr(6,26);



//**********TODO: Write the jump where it takes increased PC 4 bits and appends the addedss instruction shifted
        jumpAmount = shiftJump->shift(jumpAmount);

        jumpAmount = currentAddress.substr(0,4) + jumpAmount;
    	jumpOrIncrementMultiplexer5->useMultiplexer(currentAddress,jumpAmount,control->getJump());
		
	programCounter->setAddress(jumpOrIncrementMultiplexer5->getOutput());
				 
}
	    
else{
    if(control->getBranch().compare("1")==0){
   
        string choiceOP;
  	 if(control->getBranch().compare("1")==0 && alu1->getComparisonResult()){
       		if(debug_mode)
         	 cout<<"Setting Branch Zero op to 1" << endl;
      		 choiceOP="1";
 	 }
 	 else{
    			  if(debug_mode)
         	 cout<<"Setting Branch Zero op to 0" << endl;
     		 choiceOP="0";
  	}
  
 	 alu2->setOperand1(alu3->getOutput());
 	 //Execute the ALU with the signextended shift of Imm and PC+4 address
	    string instructionCode = currentInstruction->getInstruction();
 	 signExtend= new SignExtend(instructionCode.substr(16,16));
 	 shiftBranch = new ShiftLeft();
  	alu2->setOperand2(shiftBranch->shift(signExtend->getExtended()));
  	 alu2->setOperation(1);
  	 alu2->execute();
    
 	 branchOrIncrementMultiplexer4->useMultiplexer(alu3->getOutput(),alu2->getOutput(),choiceOP);
  
   	programCounter->setAddress(branchOrIncrementMultiplexer4->getOutput());
   
   
 }		
	
//****START DECODE****
	
	//Sets up the multiplexor that decides the write register
	registerMultiplexer1->useMultiplexer(instruction.substr(11,5),instruction.substr(16,5),control->getRegDST());      
    
    //Prepare the ALU inputs
	alu1 = new ALU();
    	alu1->setOperand1(instruction.substr(6,5));
	
	//Does sign extend in case it is needed in the ALU
	signExtend = new SignExtend(instruction.substr(16,16));
		
	//Multiplexer to choose if register2 data or immediate
	registerOrImmediateMultiplexer2->useMultiplexer(instruction.substr(11,5),signExtend->getExtended(),control->getALUSrc());
	
	alu1->setOperand2(registerOrImmediateMultiplexer2->getOutput());
	
	
		
	 aluControl = new ALUControl();
	aluControl->setALU(alu1);
	aluControl->sendSignals(control->getALUOp());
	alu1->execute();
	string ALUresult = alu1->getOutput();

//****MEMORY AND WRITEBACK PHASE	
	string memoryResult;	    
	memoryOrALUMultiplexer3->useMultiplexer(ALUresult,memoryResult,control->getMemtoReg());
	
	//If not dealing with memory
    ifmemoryOrALUMultiplexer3->getOutput().compare(ALUresult)==0){
	    //Need to write ALUresult to the writedata register
	    int registerNum = registerFile->getRegFromBinary(registerMultiplexer1->getOutput());
	    registerFile->writeToRegister(registerNum, BinaryOp->getHexFromBin(ALUresult));
	    
	    //ALL DONE WITH THE INSTRUCTION AT THIS POINT
	    
   	 }
				    
	//If I need to read to memory				    
	if(control->getMemRead().compare("1")==0){
		string memoryResult = memoryUnit->read(ALUresult);
		int registerNum = registerFile->getRegFromBinary(registerMultiplexer1->getOutput());
	    registerFile->writeToRegister(registerNum,memoryResult);
	}
		
	//If writting to memory
	if(control->getMemWrite().compare("1")==0){
			string addressToWrite = alu1->getOutput();
			int regNum = registerFile->getRegFromBinary(instruction.substr(11,5));
			memoryUnit->writeToMemory(addressToWrite, registerFile->read(regNum));
	} 
			
    }		//end else
				    
				    
	 if(output_mode.compare("single_step")==0){
            string wait;
		cin >> wait;
        }
				    
//****NEED TO ADD IF WE WRITE TO FILE**********
				    
  }	//end while
	
					    
   

 
        
        
       
 } // end file

