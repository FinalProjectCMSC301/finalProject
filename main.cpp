
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
    Multiplexer *registerMultiplexer1 = new Multiplexer();
    Multiplexer *registerOrImmediateMultiplexer2 = new Multiplexer();
    Multiplexer *memoryOrALUMultiplexer3 = new Multiplexer();
    Multiplexer *branchOrIncrementMultiplexer4 = new Multiplexer();
    Multiplexer *jumpOrIncrementMultiplexer5 = new Multiplexer();
    SignExtend *signExtend;
    BinaryOperation *BinaryOp;
    
    
    string currentAddress;
   
    
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
	
	//Set up the BinaryOpeations
	BinaryOP = new BinaryOperation();
	
	//Starts Address for Program Counter
	programCounter = new ProgramCounter();
	currentAddress = programCounter->getAddress();
	
	//Set up the instruction memory
	InstructionMemory currentInstruction = new InstructionMemory(program_input);
	
	
	
	
    
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
        
        //out << "Current Instruction: " << parse->getInstruction(programCounter->getAddress())->getStringVersion() << endl;
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
	
	 
	    
	 //Sets the inputs to increase the program counter   
        alu3.setOperand1(programCounter.getAddress());
        alu3.setOperand2("00000000000000000000000000000100");//write 4 
	    
	 //increases the program counter
        alu3.execute();
        
        alu2.setOperand1(currentAddress);
    
    

       
 //Now need to get first instruction
	    
//GET THE INSTRUCTION
	    
	    string instruction = currentInstruction->getInstruction();
         
//Runs the control unit and sets control lines
	    control = new controlUnit();
	    control->setControls(instruction.substr(0,6);
				 
//calculate the next address options 

            
            // write multplexer to store 
            branchOrIncrementMultiplexer4->choice1=currentAddress;
//***TO DO: Calculate the possible address that can come from immediate ********
				 

				 
//***TO DO: Send to ALU2****
				 

				 
				 
//Look to see if it is jump because will avoid all bottom stuff. Do after calculate options
	
	if(control->getJump().compare("1")==0{
    //maybe not right 
    string jumpAmount = instruction.substr(6,26)



//**********TODO: Write the jump where it takes increased PC 4 bits and appends the addedss instruction shifted
        jumpAmount = shiftJump.shift(jumpAmount);//

        jumpAmount = currentAddress.substr(0,4) + jumpAmount;
    	jumpOrIncrementMultiplexer5->choice1 = jumpAmount;
    
    
    //rewrite the multpliexer 
    
    //jumpOrIncrementMultiplexer5.setInput1(jumpAmount);
    //
    
				 
	}

    if(control->getBranch().compare("1")==0){
 -  
 -  string choiceOP;
 -  if(control->getBranch().compare("1")==0 &&ALU1->getComparisonResult()){
 -      if(debug_mode)
 -          cout<<"Setting Branch Zero op to 1" << endl
 -      choiceOP="1";
 -  }
 -  else{
 -      if(debug_mode)
 -          cout<<"Setting Branch Zero op to 0" << endl
 -      choiceOp="0";
 -  }
 -  
 -  alu2->setOperand1(alu3->getOutput());
 -  //Execute the ALU with the signextended shift of Imm and PC+4 address
 - 
 -  shiftBranch = new ShiftLeft();
 -  alu2->setOperand2(shiftBranch->shift(signExtend));
 -  alu2->setOperation(1);
 -  alu2->execute();
 -  
 -  
 -  branchOrIncrementMultiplexer4->useMultiplexer(alu3->getOutput(),alu2->getOutput(),choiceOp);
 -  
 
 -  programCounter->setAddress(branchOrIncrementMultiplexer4->getOutput());
 -  
 -  
 -}			 
	
				 
				 
//Get to this if it is not a jump				 
				 
else{				 
				 
	//Set the Read register from the Instruction
	registerFile->setReadRegister1(instruction.substr(6,5));
	registerFile->setReadRegister2(instruction.substr(11,5));
				 
				 
      
	
	//Sets up the multiplexor that decides the write register
	registerMultiplexor1->useMultiplexer(instruction.substr(11,5),instruction.substr(16,5),control->getRegDST());
       	//Sets the write register based on the multiplexor
	registerFile->setWriteRegister(registerMultiplexor1->getOutput());
	      
    
    //Prepare the ALU inputs
	
	ALU1 = new ALU();
    	ALU1->setOperand1(registerFile->getReadRegister1());
	
	//Does sign extend in case it is needed in the ALU
	
		signExtend = new signExtend(instruction.substr(16,16);
		ALU1->setOperand2(signExtend->getExtended());
	
	
	registerOrImmediateMultiplexor2->useMultiplexor(registerFile->getReadRegister2(),signExtend->getExtended(),control->getALUSrc());
	
	ALU1->setOperand2(registerOrImmediateMultiplexor2->getOutput());
	
	
		
	ALUControl ALUcontrol = new ALUControl();
	ALUcontrol->setALU(ALU1);
	ALUcontrol->sendSignals(control->getALUOp());
	ALU1->execute();
	string ALUresult = ALU1->getOutput();
	
	

// Start the Data Memory Area
//memory

	memoryOrALUMultiplexor3->useMultiplexor(ALUresult,MemoryResult,control->getMemtoReg());
					    
    if(memoryOrALUMultiplexor->getOutput().compare(ALUresult)==0){
	    //Need to write ALUresult to the writedata register
	    int registerNum = BinaryOp->binToInt(registerFile->getWriteRegister());
	    registerFile->writeToRegister(registerNum, BinaryOp->getHexFromBin(ALUresult));
	    
	    //ALL DONE WITH THE INSTRUCTION AT THIS POINT
	    //NEED TO CHANGE PC
	    
   	 }
					    
	else{
			string addressToWrite = ALU1->getOutput();
			int regNum = BinaryOp->getIntFromBin(registerFile->getReadRegister2());
			memoryunit->writeToMemory(addressToWrite, registerFile->read(regNum));
	} 
			
			
		 /*
    memoryUnit.setCurrentAddress(temp);
    temp = registerFile.getReadRegister2();
    memoryUnit.storeWord(temp);
    memoryUnit.saveMemory();
    */	
	}
					    
   } // put everything except Branch and jump 					    
    
    string temp = registerFile.getReadRegister2();

    //need to change to store 
    registerOrImmediateMultiplexer2.setInput0(temp);
    
    
//     if (debug)
//         cout <<"ADJUSTING ALU SOURCE MULTIPLEXER INPUT1" << endl << endl;

//     //need to change to store 
//         registerOrImmediateMultiplexer2.setInput1(immediate);
//     //
    
        immediate = shiftBranch.shift(immediate);
        alu2.setOperand2(immediate);
    
    
        alu2.execute();
        branchOrIncrementMultiplexer4.setInput1(aluAddBranchAndAddress.getOutput());



    //excute
    
        alu1.execute();
    
    //branchOrIncrementMultiplexer4.setControl(control.isBranch() && alu1.getComparisonResult());
    

        //writeback
    programCounter.setAddress(jumpOrIncrementMultiplexer5.getOutput());
    
    /*
    if(!parse.(weAreDone)( programCounter.getAddress())){
        cout <<"Next Instruction to run: ";parse.getInstruction(programCounter.getAddress()).print();
    } make a break part of the while. 
    */

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
