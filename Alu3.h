//ALU3.h
#ifndef _Alu3_h_
#define _Alu3_h_
#include "BinaryOperation.h"
using namespace std;

class Alu3
{
	private:
		BinaryOperation bo;
		string hexPC;
	public:
		Alu3();
		void setPCInput(string hex);
		void update();
		string getBinaryOutput();
		string getHexOutput();
};
#endif