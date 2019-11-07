//Multiplexer.h
#ifndef _Multiplexer_h_
#define _Multiplexer_h_

#include <string>
#include "BinaryOperation.h"
using namespace std;

class Multiplexer
{
	private:
		BinaryOperation bo;
		string one;
		string two;
		string control;
		
	public:
		Multiplexer();
		void setOne(string something);
		void setTwo(string something);
		void setControl(string something);
		string getOutput();
};
#endif