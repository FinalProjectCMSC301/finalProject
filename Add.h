//ALU3.h
#ifndef _ADD_h_
#define _ADD_h_
#include "BinaryOperation.h"

using namespace std;
/** Class name was ADD before but it gave errors for some reason which went away after name changed to Add.
*/
class Add
{
	private:
		BinaryOperation bo;
		string hexPC;
	public:
		/** Default constructor.
		*/
		Add();
		/** Requires a hex value of PC.
		*/
		void setPCInput(string hex);
		/** When called, 4 is added to the PC given earlier.
		*/
		void update();
		/** Can be used to get the binary rep. of PC.
		*/
		string getBinaryOutput();
		/** Can be used to get the hex rep. of PC
		*/
		string getHexOutput();
};
#endif
