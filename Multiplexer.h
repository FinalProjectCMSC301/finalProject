/*
This class represents a multiplexor. 
Input: two values to choose from, and the choice int
Output: The value that was chosen
*/

#ifndef __MULTIPLEXER_H__
#define __MULTIPLEXER_H__


#include <string>
using namespace std;

class Multiplexer{


public:
  Multiplexer();
  string input1;
  string input2;
  string choice;
  string output;
void useMultiplexer(string input1, string input2, string choice);
  bool debug = false;
  void setDebug(bool debugChange){debug=debugChange;};
  string getOutput(){return output;};

};
#endif
