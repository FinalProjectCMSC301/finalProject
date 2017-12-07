//ALU3.h
#ifndef _ADD_h_
#define _ADD_h_
#include "BinaryOperation.h"

using namespace std;

class Add
{
	private:
		BinaryOperation bo;
		string hexPC;
	public:
		Add();
		void setPCInput(string hex);
		void update();
		string getBinaryOutput();
		string getHexOutput();
};
#endif