
#include "Parser.h"
#include <iostream>
#include <fstream>
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
   InstructionMemory *currentInstruction;
	
  
    
    string ms(""); //main string 
    ofstream outputFile;
    
    
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
	
	
	
	//Starts Address for Program Counter
	programCounter = new ProgramCounter();
	currentAddress = programCounter->getAddress();
	cout << "This is the address: " << currentAddress;
	
	//Set up the instruction memory
	currentInstruction = new InstructionMemory(program_input);
	

	
    if(write_to_file){
	    outputFile.open(output_file.c_str());
    }
	//if(debug_mode)    
        cout << "ADDRESS: " << currentAddress << endl;
   
    cout<< currentInstruction->getInstructionPC(currentAddress)  << endl;
    while(currentInstruction->getInstructionPC(currentAddress) != ""){
	    
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
	    
	    //Set up the BinaryOpeations
	BinaryOp = new BinaryOperation();
     
        if(write_to_file){
            cout<< "*****CURRENT REGISTERS*****" <<endl;
            //cout << registerFile->getAllRegisters();
            cout << endl;
            cout<< "*****CURRENT DATA MEMORY*****" <<endl;
            //out << memoryUnit->getAllPairs();
        }
        
	    //Get the current address in the PC
	    currentAddress = programCounter->getAddress();
	  // if(debug_mode)
	    cout << "ADDRESS: " << currentAddress << endl;
       
	    
	 //Sets the inputs to increase the program counter   
        alu3->setOperand1(BinaryOp->hexToBin(currentAddress,32));
        alu3->setOperand2("00000000000000000000000000000100");//write 4 
	 alu3->setOperation(1);
	    
	 //increases the program counter
        alu3->execute();
	    
	    cout << "Address after alu3 call: " << alu3->getOutput() << endl;
	 
	 //GET THE INSTRUCTION
	     string instruction = currentInstruction->getInstructionPC(currentAddress);
	    programCounter->setAddress(alu3->getOutput());
	    
	    cout << "INSTRUCTION: " << instruction <<endl;
	    
	  
        cout << "Program counter get Address: " << programCounter->getAddress() << endl;
        alu2->setOperand1(BinaryOp->hexToBin(programCounter->getAddress(),32));
    
	    

         
//Runs the control unit and sets control lines
	   cout << "calling set the controls" << endl;
	    control->setControls(instruction.substr(0,6));
	    //if(debug_mode)
		    control->printValues();
				 
				 
				 
//Look to see if it is jump because will avoid all bottom stuff. Do after calculate options
	
	if(control->getJump().compare("1")==0){
    //maybe not right 
   	 string jumpAmount = instruction.substr(6,26);
	cout << "Jump partial: " << jumpAmount;


//**********TODO: Write the jump where it takes increased PC 4 bits and appends the addedss instruction shifted
        jumpAmount = shiftJump->shift(jumpAmount);
		cout << "Jump after shift: " << jumpAmount;
	string hexAdd = BinaryOp->hexToBin(programCounter->getAddress(),32);
	cout << "Hex Address of next PC: " << programCounter->getAddress() << endl;
        jumpAmount = hexAdd.substr(0,4) + jumpAmount;
	cout << "Where we jump to: " << jumpAmount << endl;
    	jumpOrIncrementMultiplexer5->useMultiplexer(currentAddress,BinaryOp->binToHex(jumpAmount,8),control->getJump());
	cout << "Address we will go to: " << jumpOrIncrementMultiplexer5->getOutput() << endl;
	programCounter->setAddress(jumpOrIncrementMultiplexer5->getOutput());
				 
}
	    
else{
    	
	
//****START DECODE****
	cout<< "Starting Decode" << endl;
	//Sets up the multiplexor that decides the write register
	registerMultiplexer1->useMultiplexer(instruction.substr(11,5),instruction.substr(16,5),control->getRegDST());      
    
    //Prepare the ALU inputs
	alu1 = new ALU();
	int num = BinaryOp->binToInt(instruction.substr(6,5));
	registerFile->setRead(1);
    	alu1->setOperand1(BinaryOp->hexToBin(registerFile->read(num),32));
	registerFile->setRead(0);
	
	//Does sign extend in case it is needed in the ALU
	signExtend = new SignExtend(instruction.substr(16,16));
	cout << "Just did sign Extend: " << signExtend->getExtended()<< endl;
		
	//Multiplexer to choose if register2 data or immediate
	registerOrImmediateMultiplexer2->useMultiplexer(instruction.substr(11,5),signExtend->getExtended(),control->getALUSrc());
	cout << "Did MuX" << endl;
	int num2 = BinaryOp->binToInt(registerOrImmediateMultiplexer2->getOutput());
	registerFile->setRead(1);
	alu1->setOperand2(BinaryOp->hexToBin(registerFile->read(num2),32));
	registerFile->setRead(0);
	cout << "Set operand" << endl;
	
		
	 aluControl = new ALUControl();
	aluControl->setALU(alu1);
	cout << "Set ALU control" << endl;
	aluControl->sendSignals(control->getALUOp());
	cout << "Sent Signals" << endl;
	alu1->execute();
	cout << "Register data" << endl; 
	registerFile->setRead(1);
		cout << registerFile->read(1) << "   " << registerFile->read(2) << endl;
		registerFile->setRead(0);
	cout << "Executed ALU. Result: " << alu1->getOutput() << endl;
	string ALUresult = BinaryOp->binToHex(alu1->getOutput(),8);
	cout <<"ALU Result: " << alu1->getOutput() << endl;
	
//If Branch
	if(control->getBranch().compare("1")==0){
   
        string choiceOP;
	    cout << "In branch part of decode" << endl;
		registerFile->setRead(1);
		cout << registerFile->read(1) << "   " << registerFile->read(2) << endl;
		registerFile->setRead(0);
  	 if(control->getBranch().compare("1")==0 && alu1->getComparisonResult()){
       		//if(debug_mode)	
         	 cout<<"Setting Branch Zero op to 1" << endl;
      		 choiceOP="1";
 	 }
 	 else{
    	       //if(debug_mode)
         	 cout<<"Setting Branch Zero op to 0" << endl;
     		 choiceOP="0";
  	}
  
 	 alu2->setOperand1(alu3->getOutput());
 	 //Execute the ALU with the signextended shift of Imm and PC+4 address   
 	 signExtend= new SignExtend(instruction.substr(16,16));
  	alu2->setOperand2(shiftBranch->shift(signExtend->getExtended()));
  	 alu2->setOperation(1);
  	 alu2->execute();
    	cout << "Output from ALU2: " << alu2->getOutput() << endl;
 	 branchOrIncrementMultiplexer4->useMultiplexer(alu3->getOutput(),alu2->getOutput(),choiceOP);
  
	   
   	programCounter->setAddress(BinaryOp->binToHex(branchOrIncrementMultiplexer4->getOutput(),8));
   	 //if(debug_mode)
		    cout << "New Address: " << programCounter->getAddress() << endl;
   
 }	

else{
//****MEMORY AND WRITEBACK PHASE	
	string memoryResult;	    
	memoryOrALUMultiplexer3->useMultiplexer(ALUresult,memoryResult,control->getMemtoReg());
	
	//If not dealing with memory
    if(memoryOrALUMultiplexer3->getOutput().compare(ALUresult)==0){
	    //Need to write ALUresult to the writedata register
	    int registerNum = BinaryOp->binToInt(registerMultiplexer1->getOutput());
	   // if(debug_mode)
		    cout << "Writing to register: " << registerNum << " Data: " << ALUresult<< endl;
	    registerFile->writeToRegister(registerNum, ALUresult);
	    
	    //ALL DONE WITH THE INSTRUCTION AT THIS POINT
	    
   	 }
				    
	//If I need to read to memory				    
	if(control->getMemRead().compare("1")==0){
		string memoryResult = memoryUnit->read(ALUresult);
		int registerNum = BinaryOp->binToInt(registerMultiplexer1->getOutput());
		//if(debug_mode)
		cout << "Writing to register: " << registerNum << " Data: " << memoryResult << endl;
	    registerFile->writeToRegister(registerNum,memoryResult);
	}
		
	//If writting to memory
	if(control->getMemWrite().compare("1")==0){
			string addressToWrite = ALUresult;
			int regNum = BinaryOp->binToInt(instruction.substr(11,5));
			//if(debug_mode)
		cout << "Reading from register: " << regNum << " Data: " << addressToWrite << endl;
			memoryUnit->writeToMemory(addressToWrite, registerFile->read(regNum));
	} 
}			
    }		//end else
	
	    currentAddress = programCounter->getAddress();
	    //if(debug_mode)
	    cout << "Next Address: " << endl;
				    
	 if(output_mode.compare("single_step")==0){
            string wait;
		cin >> wait;
        }
	 
	    if(print_memory_contents){
		//Print everything after every instruction
		    ms.append("MEMORY CONTENT: \n");
		   ms.append(memoryUnit->print()); 
		    ms.append(" \n ************************************** \n");
		    ms.append("REGISTER CONTENT: \n");
		    ms.append(registerFile->print());
		    ms.append("\n **************************************\n");
		    ms.append("CONTROL UNIT SIGNALS: \n");
		    ms.append(control->printStringValues());
	             ms.append("\n");
	    }
	 
	  if(write_to_file){
		  outputFile << ms;
	  }    
				    
//****RESET**********
	    delete alu1;//ToMemory
    delete alu2;//AddBranchAndAddress
    delete alu3;//AddPCand4
    delete shiftJump;
    delete shiftBranch;
    delete control;
    delete registerMultiplexer1;
   delete registerOrImmediateMultiplexer2;
   delete memoryOrALUMultiplexer3;
    delete branchOrIncrementMultiplexer4;
   delete jumpOrIncrementMultiplexer5;
    delete signExtend; 
    delete aluControl;	
    delete BinaryOp;
				    
  }	//end while
	
					    
    if(write_to_file){
	    outputFile.close();
    }
	 

 
        
        
       
 } // end file

