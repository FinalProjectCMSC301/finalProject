
//Author: Wallace He 
// This class functions as the Arithmetic Logic Unit of a processor. The values of
// the instance variables 'operation', 'operand1', and 'operand2' are set through
// their respective set methods. The execute method directs the program to the 
// correct arithmetic operation depending on the value of the 'operation' instance
// variable. The compare method returns true or false depending on the equivalency
// of the operands. The add and subtract methods return the sum or difference of
// the two operands in the form of a 32-bit hexadecimal string.
//

#ifndef ALU_h
#define ALU_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include "BinaryOperation.h"


using namespace std;
class ALU {

private:
	BinaryOperation BinOp;
	string operation; 			//0 = compare, 1 = add, 2 = subtract 3 comparelessthan 
	string operand1; 		//bineary string to be operated on instruction 
	string operand2; 		//bineary string to be operated on instruction
	string output;			//bineary string representing the output of the ALU
	bool comparisonResult;	//boolean result of the comparison between the two operands
	void compareEqual();			//Compares the two operands, returns true if the same and false if different
    void compareLessThan();			//Compares the two operands, returns true if operand1 is smaller than operand 2
	void add();				//Adds the two operands and returns the result
	void subtract();		//Subtracts the two operands and returns the result

    bool debug;
public:

	//Default constructor
	ALU();

	//Calls either the compare(), add(), or subtract() function depending on the
	//value of the operation instance variable
	void execute();

	//Sets the operand1 instance variable equal to the passed string
	void setOperand1(string operand);

	//Sets the operand2 instance variable equal to the passed string
	void setOperand2(string operand);

	//Sets the operation instance variable equal to the passed int
	void setOperation(int operationInput);

	//Returns the output instance variable. This will be a 32 bit hex string
	string getOutput();

	//returns boolean result of compare() method
	bool getComparisonResult();

    void setDebug(bool value);
};

#endif 
