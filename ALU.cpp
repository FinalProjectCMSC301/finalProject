
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
    
    if (debug) {
        cout << "ALU INPUT 1: " << getHexFromBin(operand1) << endl;
        cout << "ALU INPUT 2: " << getHexFromBin(operand2) << endl;
    }
    
    if (operation == 0){
        if (debug) cout << "ALU OPERATION: compare equal" << endl;
        compareEqual();
    }
    
    
    else if (operation == 1){
        if (debug) cout << "ALU OPERATION: add" << endl;
        
        add();
    }
    
    else if (operation == 2){
        if (debug) cout << "ALU OPERATION: subtract" << endl;
        
        subtract();
    }
    else if (operation == 3){
        if (debug) cout << "ALU OPERATION: compare less than" << endl;
        
        compareLessThan();
    }
}

/*
 * Compares the two operands, returns true if the same and false if different
 */
void ALU::compareEqual() {
    
    if (operand1.compare(operand2) != 0) {
        //strings are different
        if (debug) cout << "The strings are not the same" << endl;
        comparisonResult = false;
    }
    
    else {
        if (debug) cout << "The strings are the same" << endl;
        comparisonResult = true;
    }
}

/*
 * Compares the two operands, returns true if the first is smaller than the other
 */
void ALU::compareLessThan() {
    
    if (hexToInt(getHexFromBin(operand1)) < hexToInt(getHexFromBin(operand2))) {
        //strings are different
        if (debug) cout << "Operand 1 is smaller" << endl;
        output = getBinFromHex(intToHex(1));
    }
    
    else {
        if (debug) cout << "Operand 1 is not smaller" << endl;
        output = getBinFromHex(intToHex(0));
    }
}

/*
 * Adds two operands and returns the result
 */
void ALU::add() {
    //convert hex string to int to add
    int temp1 = hexToInt(getHexFromBin(operand1));
    int temp2 = hexToInt(getHexFromBin(operand2));
    
    int result = temp1 + temp2;
    
    output = getBinFromHex(intToHex(result));

    if (debug) cout << "The sum is: " << getHexFromBin(output) << endl;
    
}

/*
 * Subtracts two operands and returns the result
 */
void ALU::subtract() {
    
    int temp1 = hexToInt(getHexFromBin(operand1));
    int temp2 = hexToInt(getHexFromBin(operand2));
    
    int result = temp1 - temp2;
    
    output = getBinFromHex(intToHex(result));

    if (debug) cout << "The difference is: " << output << endl;
}

/*
 * Takes a binary string and returns its hex string representation
 can be changed in binary operation
 */
string ALU::getHexFromBin(string sBinary)
{
    if(sBinary != ""){
    std::stringstream ss;
    ss << std::hex << std::stoll(sBinary, NULL, 2);

    string s =  ss.str();
    while (s.length() != 8){
        s = "0" + s;
    }
    s = "0x" + s;
    return s;
    }else{
        return "0x";
    }
}

/*
 * Takes a hex string as a parameter and returns its integer representation
 can be change in binry operation 
 */
int ALU::hexToInt(string hexString) {
    unsigned int x;
    stringstream ss;
    ss << std::hex << hexString;
    ss >> x;
    return x;
}

/*
 * Takes an int as a parameter and returns its hex representation as a string
 */
string ALU::intToHex(int integer) {
    char output[100];
    sprintf(output, "%08x", integer);
    string result = output;
    result = "0x" + result;
    return result;
}

/*
 * Takes a hex string and returns its binary string representation
 */
string ALU::getBinFromHex(string sHex)
{
    string s = sHex;
    stringstream ss;
    ss << std::hex << s;
    unsigned n;
    ss >> n;
    bitset<32> b(n);
    return b.to_string();
    
}

/*
 * Sets the operand1 instance variable equal to the passed string
 */
void ALU::setOperand1(string operand){
    if (debug) cout << "ALU: SETTING OPERAND1 TO " << getHexFromBin(operand) << endl;
    operand1 = operand;
}

/*
 * Sets the operand2 instance variable equal to the passed string
 */
void ALU::setOperand2(string operand){
    if (debug) cout << "ALU: SETTING OPERAND2 TO " << getHexFromBin(operand) << endl;

    operand2 = operand;
    
}

/*
 * Sets the operation instance variable equal to the passed int
 */
void ALU::setOperation(int operationInput){
    if (debug) cout << "ALU: SETTING OPERATION TO " << intToHex(operationInput) << endl;
    operation = operationInput;
}

/*
 * Returns the output instance variable. This will be a 32 bit hex string
 */
string ALU::getOutput(){
    if (debug) cout << "ALU OUTPUT: " << getHexFromBin(output) << endl;

    return output;
}

/*
 * Returns the result of the compare() method, which will be either true or false
 */
bool ALU::getComparisonResult(){
    if (debug) cout << "The comparison result is " << comparisonResult << endl;
    return comparisonResult;
}

/*
* Sets the debug instance variable to true
*/
void ALU::setDebug(bool value) {
    debug = value;
}

