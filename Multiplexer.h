/*
This class represents a multiplexor. 
Input: two values to choose from, and the choice int
Output: The value that was chosen
*/

#ifndef __MULTIPLEXER_H__
#define __MULTIPLEXER_H__


#include <string>
#include <iostream>
using namespace std;

class Multiplexer{


public:
  Multiplexer(){};
  string choice1;
  string choice2;
  string choice;
  string output;
void useMultiplexer(string input1, string input2, string muxChoice);
  string getOutput(){return output;};

};
#endif
