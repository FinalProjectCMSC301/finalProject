#include "ALUControl.h"

ALUControl::ALUControl(){
    
}

//This method sets the alu to aluToMemory
void ALUControl::setALU(ALU *alu){
    aluToMemory = alu;
}

void ALUControl::setInstruction(string input){

    instruction = input;
}


//This method takes in an opcode in string form and sets the aluToMemory equal to setOperation(0, 1, 2, or 3) depending on the opcode
//setOperation is from ALU class 
void ALUControl::sendSignals(string opcode){
    if(opcode == "10"){

        if(instruction.substr(26,6) == "100000"){
            aluToMemory->setOperation(1);//add

        }

        if(instruction.substr(26,6) == "100010"){
            aluToMemory->setOperation(2);//substract 
        }

        if (instruction.substr(26,6) == "101010") 
        {
            aluToMemory->setOperation(3);//set less than 
    }

    else if(opcode == "01"){//addi

        aluToMemory->setOperation(1);
    }else if(opcode == "00"){//sw for add ? check?

        aluToMemory->setOperation(0);

        cout << "setting ALU to 0"<< endl;

    }else{//jp 
        aluToMemory->setOperation(1);
    }
}
}
//add  - destination is rd
//addi - rt
//lw   - rt
//sw   - rt
//slt  - rd
