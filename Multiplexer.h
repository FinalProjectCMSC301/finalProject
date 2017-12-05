/*
This class represents a multiplexor. 
Input: two values to choose from, and the choice int
Output: The value that was chosen
*/

#ifndef __MULTIPLEXER_H__
#define __MULTIPLEXER_H__

class Multiplexer{


public:
string useMultiplexer(string input1, string input2, int choice);
int useMultiplexer(int input1, int input2, int choice);
string useMultiplexer(string input1, int input2, int choice);
  bool debug = false;
  void setDebug(bool debugChange){debug=debugChange;};

};
#endif
