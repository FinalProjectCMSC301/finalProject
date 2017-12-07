
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
	cout<< "Input: File " << argv[1] << "Output:" << endl;
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
	cout << "Input: " << register_file_input << endl;
	
   	
	//Create the Memory Unit
        memoryUnit = new DataMemory(memory_contents_input, 1);
	cout << "Input: " << memory_contents_input << endl;
	
	
	
	//Starts Address for Program Counter
	programCounter = new ProgramCounter();
	currentAddress = programCounter->getAddress();
	
	if(debug_mode)
	cout << "This is the address: " << currentAddress;
	
	//Set up the instruction memory
	currentInstruction = new InstructionMemory(program_input);
	cout << "Input: " << program_input << endl;
	

	
    if(write_to_file){
	    outputFile.open(output_file.c_str());
    }
	//if(debug_mode)    
        cout << "ADDRESS: " << currentAddress << endl;
   
    cout<< currentInstruction->getInstructionPC(currentAddress)  << endl;
while(currentInstruction->getInstructionPC(currentAddress) != ""){
	  //if(debug_mode)
		cout << "NEW INSTRUCTION" << endl;
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
     
	    //Get the current address in the PC
	    currentAddress = programCounter->getAddress();
	
	   if(debug_mode)
	    cout << "ADDRESS: " << currentAddress << endl;
       
	    
	 //Sets the inputs to increase the program counter 
	cout << "ALU3 Input: " <<currentAddress << " and " << BinaryOp->binToHex("00000000000000000000000000000100",8) << "Operation: 0x1" << endl; 
        alu3->setOperand1(BinaryOp->hexToBin(currentAddress,32));
        alu3->setOperand2("00000000000000000000000000000100");//write 4 
	 alu3->setOperation(1);
	    
	 //increases the program counter
        alu3->execute();
	    
		   cout << "Ouput: " << alu3->getOutput() << endl;
	 
	 //GET THE INSTRUCTION
	     string instruction = currentInstruction->getInstructionPC(currentAddress);
	    programCounter->setAddress(alu3->getOutput());
		cout << "Input to ProgramCounter Address: " << BinaryOp->binToHex(alu3->getOutput(),32) << endl;
	    
	    if(debug_mode)
		    cout << "INSTRUCTION: " << instruction <<endl;
	    
	
        cout << "Program counter Output: " << programCounter->getAddress() << endl;
       
	alu2->setOperand1(BinaryOp->hexToBin(programCounter->getAddress(),32));
    
         
	//Runs the control unit and sets control lines
	if(debug_mode)
	   cout << "calling set the controls" << endl;
	
	    control->setControls(instruction.substr(0,6));
	cout << "Output of Control Signals "<<endl;
		    control->printValues();
	cout << endl;
				 
				 
//Look to see if it is jump because will avoid all bottom stuff. Do after calculate options
	
    if(control->getJump().compare("1")==0){
    
   	 string jumpAmount = instruction.substr(6,26);
        jumpAmount = shiftJump->shift(jumpAmount);
	string hexAdd = BinaryOp->hexToBin(programCounter->getAddress(),32);
        jumpAmount = hexAdd.substr(0,4) + jumpAmount;
	 cout << "Input Multiplexer for Jump or PC Increment: " << currentAddress << " " <<BinaryOp->binToHex(jumpAmount,8) << " " << BinaryOp->binToHex(control->getJump(),8) << endl;
    	jumpOrIncrementMultiplexer5->useMultiplexer(currentAddress,BinaryOp->binToHex(jumpAmount,8),control->getJump());
	
	    cout << "Output Multiplexer for Jump or PC Increment: " << jumpOrIncrementMultiplexer5->getOutput() << endl;
	    
	programCounter->setAddress(jumpOrIncrementMultiplexer5->getOutput());				 
     }
	    
else{
    	
	
          //****START DECODE****
	if(debug_mode)
	cout<< "Starting Decode" << endl;
	
	//Sets up the multiplexor that decides the write register
	cout << "Input Register Multiplexer: " << instruction.substr(11,5) << " " <<instruction.substr(16,5)<< " " <<control->getRegDST() << endl;;      
    
	registerMultiplexer1->useMultiplexer(instruction.substr(11,5),instruction.substr(16,5),control->getRegDST()); 
	
	cout << "Output Register Multiplexer: " << registerMultiplexer1->getOutput() << endl;
    
        //Prepare the ALU inputs
	alu1 = new ALU();
	int num = BinaryOp->binToInt(instruction.substr(6,5));
	registerFile->setRead(1);
	cout << "ALU1 Input: " << registerFile->read(num);
    	alu1->setOperand1(BinaryOp->hexToBin(registerFile->read(num),32));
	registerFile->setRead(0);
	
	//Does sign extend in case it is needed in the ALU
	signExtend = new SignExtend(instruction.substr(16,16));
	
	if(debug_mode)
	cout << "Just did sign Extend: " << BinaryOp->binToHex(signExtend->getExtended(),8)<< endl;
		
	//Multiplexer to choose if register2 data or immediate
	registerOrImmediateMultiplexer2->useMultiplexer(instruction.substr(11,5),signExtend->getExtended(),control->getALUSrc());
	
	if(registerOrImmediateMultiplexer2->getOutput().compare(signExtend->getExtended())==0){
		cout << signExtend->getExtended() << endl;
		alu1->setOperand2(signExtend->getExtended());
	}
	
	else{
		int num2 = BinaryOp->binToInt(registerOrImmediateMultiplexer2->getOutput());
		registerFile->setRead(1);
		alu1->setOperand2(BinaryOp->hexToBin(registerFile->read(num2),32));
		cout <<registerFile->read(num2)<<endl;
		registerFile->setRead(0);
	}
	
		
	aluControl = new ALUControl();
	aluControl->setALU(alu1);
	aluControl->sendSignals(control->getALUOp(),instruction.substr(26,6));
	
	if(debug_mode)
	cout << "Sent ALU Signals" << endl;
	
	alu1->execute();
	cout << "ALU1 Output: " << alu1->getOutput() << endl;
	 
	registerFile->setRead(1);
	
	if(debug_mode)
	cout << BinaryOp->hexToInt(registerFile->read(num))<< "   " << registerFile->read(num)<< endl;
	
	registerFile->setRead(0);
	string ALUresult = BinaryOp->binToHex(alu1->getOutput(),8);
	
	if(debug_mode)
	cout <<"ALU Result: " << alu1->getOutput() << endl;
	
        //If Branch
	if(control->getBranch().compare("1")==0){
   
        		string choiceOP;
			registerFile->setRead(1);
			cout << registerFile->read(1) << "   " << registerFile->read(2) << endl;
			registerFile->setRead(0);
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
  	cout << "ALU2 Input: " << alu3->getOutput() << " " << shiftBranch->shift(signExtend->getExtended()) << "  0x1"<< endl;
 	 alu2->setOperand1(alu3->getOutput());   
 	 signExtend= new SignExtend(instruction.substr(16,16));
  	alu2->setOperand2(shiftBranch->shift(signExtend->getExtended()));
  	 alu2->setOperation(1);
  	 alu2->execute();
    	cout << "Output from ALU2: " << alu2->getOutput() << endl;
		
 	cout<< "Branch or Increment Multiplexer Input: " << alu3->getOutput()<< " " <<alu2->getOutput()<< " " <<choiceOP<<endl;
	branchOrIncrementMultiplexer4->useMultiplexer(alu3->getOutput(),alu2->getOutput(),choiceOP);
	cout<< "Branch or Increment Multiplexer Output: " << branchOrIncrementMultiplexer4->getOutput() << endl;
   	programCounter->setAddress(BinaryOp->binToHex(branchOrIncrementMultiplexer4->getOutput(),8));
	cout<< "New PC address: " << branchOrIncrementMultiplexer4->getOutput() << endl;
		
   	 if(debug_mode)
		    cout << "New Address: " << programCounter->getAddress() << endl;
   
 }	

else{
	//****MEMORY AND WRITEBACK PHASE	
	string memoryResult=" ";
	cout << "Input for Memory or ALU Multiplexer: " << ALUresult << " " << memoryResult << " " <<  control->getMemtoReg() << endl;
	memoryOrALUMultiplexer3->useMultiplexer(ALUresult,memoryResult,control->getMemtoReg());
	cout << "Output for Memory or ALU Multiplexer: " << memoryOrALUMultiplexer3->getOutput() << endl;
	
	//If not dealing with memory
    if(memoryOrALUMultiplexer3->getOutput().compare(ALUresult)==0){
	    //Need to write ALUresult to the writedata register
	    int registerNum = BinaryOp->binToInt(registerMultiplexer1->getOutput());
	    
	    cout << "Writing to register: " << registerNum << " with Data: " << ALUresult<< endl;
	    
	    registerFile->setWrite(1);
	    registerFile->writeToRegister(registerNum, ALUresult);
	    registerFile->setWrite(0);
	    
	    //ALL DONE WITH THE INSTRUCTION AT THIS POINT
	    
   	 }
				    
	//If I need to read to memory				    
    if(control->getMemRead().compare("1")==0){
		memoryUnit->setRead(1);
		
		memoryResult = memoryUnit->read(ALUresult);
	    
	    if(debug_mode)
		cout << "Memory Result: " << memoryResult << endl;
	    
		int registerNum = BinaryOp->binToInt(registerMultiplexer1->getOutput());
	    
		
		cout << "Writing to register: " << registerNum << "  The Data is: " << memoryResult << endl;
	    
		registerFile->setWrite(1);
	        registerFile->writeToRegister(registerNum,memoryResult);
		memoryUnit->setRead(0);
		registerFile->setWrite(0);
	}
		
	//If writting to memory
	if(control->getMemWrite().compare("1")==0){
			
		int regNum = BinaryOp->binToInt(instruction.substr(11,5));
		
		cout << "Reading from register: " << regNum << " Address in memory to write to: " << ALUresult << endl;
		
		memoryUnit->setRead(1);
		registerFile->setRead(1);
		memoryUnit->writeToMemory(ALUresult, registerFile->read(regNum));
		memoryUnit->setRead(0);
		registerFile->setRead(0);
	} 
	
   }			
}		//end else
	
	    currentAddress = programCounter->getAddress();
	    
	    cout << "Next Address: " << currentAddress << endl;
	    cout << "ALU 3 Output: " << alu3->getOutput() << endl;
				    
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
		    cout << ms << endl;
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
	    
	if(debug_mode)   
	cout << "Current Address before break: " << currentAddress << endl;
	
	    if(currentAddress.empty()){
		    break;
	    }
				    
  }	//end while
	
					    
    if(write_to_file){
	    outputFile.close();
    }  
       
 } // end file

