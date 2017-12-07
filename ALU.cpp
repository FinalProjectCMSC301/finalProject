 
#include "ALU.h"

/*
 * Default constructor
 */
ALU::ALU() {
    
}

/*
 * Calls either the compare(), add(), or subtract() function depending on the value
 * of the operation instance variable
 */
void ALU::execute() {


    
    
        //cout << "In exce ALU INPUT 1: " << BinOp.hexToBin(operand1, 32) << endl;
        //cout << "ALU INPUT 2: " << BinOp.hexToBin(operand2,32) << endl;

        cout << "we want to see the operation" << endl;
    //int operation1 = BinOp.binToInt(operation);
    cout << operation <<endl;
    if (operation == 0){
       cout << "ALU OPERATION: compare equal" << endl;
        compareEqual();
                cout << "The output rights now is " << output <<endl;

    }
    
    
    else if (operation == 1){
        // cout << "ALU OPERATION: add" << endl;
        
        add();
    }
    
    else if (operation == 2){
        // cout << "ALU OPERATION: subtract" << endl;
        
        subtract();
    }
    else if (operation == 3){
        //if (debug) cout << "ALU OPERATION: compare less than" << endl;
        
        compareLessThan();
        cout << "The output rights now is " << output <<endl;
    }
}

/*
 * Compares the two operands, returns true if the same and false if different
 */
void ALU::compareEqual() {
    
    if (operand1.compare(operand2) != 0) {
        //strings are different
        cout << "The strings are not the same" << endl;
        comparisonResult = false;
        output ="0";
    }
    
    else {
         cout << "The strings are the same" << endl;
        comparisonResult = true;
                output ="1";

    }
}

/*
 * Compares the two operands, returns true if the first is smaller than the other
 */
void ALU::compareLessThan() {
        cout<< "check the int of OP1 "<< BinOp.hexToInt(operand1)<<endl;
                cout<< "check the int of OP2 "<< BinOp.hexToInt(operand2)<<endl;

    if (BinOp.hexToInt(operand1) < BinOp.hexToInt(operand2)) {
        //strings are different
         cout << "Operand 1 is smaller" << endl;
         comparisonResult = true;
                 output ="1";

    }
    
    else {
         cout << "Operand 1 is not smaller" << endl;
            comparisonResult = false;
                    output ="0";


    }
}

/*
 * Adds two operands and returns the result
 */
void ALU::add() {
    
    output = BinOp.addBin(operand1,operand2,32);

    if (debug) cout << "The sum is: " << BinOp.binToHex(output,8)<< endl;
    
}

/*
 * Subtracts two operands and returns the result
 */
void ALU::subtract() {
    
    int temp1 = BinOp.binToInt(operand1);
    int temp2 = BinOp.binToInt(operand2);
    
    int result = temp1 - temp2;
    
    output = BinOp.intToBin(result,32);

    if (debug) cout << "The difference is: " << BinOp.binToHex(output,8) << endl;
}





/*
 * Sets the operand1 instance variable equal to the passed string
 */
void ALU::setOperand1(string operand){
    //if (debug) cout << "ALU: SETTING OPERAND1 TO " << BinOp.binToHex(output,8) << endl;
    operand1 = operand;
}

/*
 * Sets the operand2 instance variable equal to the passed string
 */
void ALU::setOperand2(string operand){
    //if (debug) cout << "ALU: SETTING OPERAND2 TO " << BinOp.binToHex(output,8) << endl;

    operand2 = operand;
    
}

/*
 * Sets the operation instance variable equal to the passed int
 */
void ALU::setOperation(int operationInput){
   // if (debug) cout << "ALU: SETTING OPERATION TO " << BinOp.binToHex(output,8) << endl;
    operation = operationInput;
}

/*
 * Returns the output instance variable. This will be a 32 bit hex string
 */
string ALU::getOutput(){
 //   if (debug) cout << "ALU OUTPUT: " << BinOp.binToHex(output,8) << endl;

    return output;
}

/*
 * Returns the result of the compare() method, which will be either true or false
 */
bool ALU::getComparisonResult(){
   // if (debug) cout << "The comparison result is " << comparisonResult << endl;
    return comparisonResult;
}

/*
* Sets the debug instance variable to true
*/
void ALU::setDebug(bool value) {
    debug = value;
}

