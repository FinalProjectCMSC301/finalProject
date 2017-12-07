#include "ALUControl.h"

ALUControl::ALUControl(){
    
}

//This method sets the alu to aluToMemory
void ALUControl::setALU(ALU *alu){
    aluToMemory = alu;
}



//This method takes in an opcode in string form and sets the aluToMemory equal to setOperation(0, 1, 2, or 3) depending on the opcode
//setOperation is from ALU class 
void ALUControl::sendSignals(string opcode,string funct){

    cout<<"this is opcode:" << opcode <<endl;
        cout<<funct<<endl;

    if(opcode.compare("01")==0){

        if(funct.compare("100000")==0){
            aluToMemory->setOperation(1);//add

        }

        if(funct.compare("100010")==0){
            aluToMemory->setOperation(2);//substract 
        }

        if (funct.compare ("101010")==0) 
        {
            aluToMemory->setOperation(3);//set less than
            } 
    }

    else if (opcode.compare("10")== 0){//brech equal 

        aluToMemory->setOperation(0);
    }



    else if(opcode.compare("00")== 0){//sw for add ? check?

        cout << "setting ALU to 0"<< endl; 

        aluToMemory->setOperation(1);


    }
    else{

        aluToMemory->setOperation(1);
    }
}

//add  - destination is rd
//addi - rt
//lw   - rt
//sw   - rt
//slt  - rd
