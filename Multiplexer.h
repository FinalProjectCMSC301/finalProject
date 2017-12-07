//Multiplexer.h
#ifndef _Multiplexer_h_
#define _Multiplexer_h_

#include <string>
#include "BinaryOperation.h"
using namespace std;

/** General purpose Multiplexer class.
*/
class Multiplexer
{
	private:
		BinaryOperation bo;
		string one;
		string two;
		string control;
		
	public:
		/** Default constructor.
		*/
		Multiplexer();
		/** Used to set first choice.
		*/
		void setOne(string something);
		/** Used to set second choice.
		*/
		void setTwo(string something);
		/** Used to set the optimal choice from Control Unit.
		*/
		void setControl(string something);
		/** Gets one of the choices based on the control.
		*/
		string getOutput();
};
#endif
