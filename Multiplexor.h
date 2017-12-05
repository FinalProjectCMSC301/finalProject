/*
This class represents a multiplexor. 
Input: two values to choose from, and the choice int
Output: The value that was chosen
*/

#ifndef __MULTIPLEXOR_H__
#define __MULTIPLEXOR_H__

class Multiplexor{


public:
string Multiplexor(string input1, string input2, int choice);
int Multiplexor(int input1, int input2, int choice);
string Multiplexor(string input1, int input2, int choice);
  bool debug = false;
  void setDebug(bool debugChange){debug=debugChange;};

};
#endif
