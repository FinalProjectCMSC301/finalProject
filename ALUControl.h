#ifndef ALUControl_h
#define ALUControl_h

#include <stdio.h>

#include "ALU.h"

using namespace std;

class ALUControl{
private:
    

    ALU *aluToMemory;

    
    string aluOP;
    
public:
    
    ALUControl();
    
    //void set
    void setALU(ALU *alu);
    
    //This method takes in an opcode in string form and sets the aluToMemory equal to setOperation(0, 1, 2, 
    void sendSignals(string opcode);
    
};
#endif 