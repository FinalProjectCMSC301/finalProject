#ifndef _ShiftLeft_h_
#define _ShiftLeft_h_
#include <iostream>
#include <string>
using namespace std;

/** General class to Shift left. 
*/
class ShiftLeft
{
	public:
		/** Default constructor.
		*/
		ShiftLeft();
		/** Adds "00" at the end of input and returns it.
		*/
		string shift(string input);
};
#endif
