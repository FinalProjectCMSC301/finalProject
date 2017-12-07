#ifndef _BinaryOperation_h_
#define _BinaryOperation_h_

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

/** General file that facilitates changes among int-hex-binary.
*/
class BinaryOperation
{
	public:
		/** Default constructor.
		*/
		BinaryOperation();
		/** Converts from unsigned int to Hex. len is length of hex string desired after 0x.
		*/
		string intToHex(unsigned int num, int len);
		/** Convers from unsigned int to Bin. len is length of bin string desired.
		*/
		string intToBin(unsigned int num, int len);
		
		/** Converts from hex to unsigned int.
		*/
		unsigned int hexToInt(string hex);	//can give 0x or just start
		
		/** Converts from hex to bin. Len is the length of bit string desired.
		*/
		string hexToBin(string hex, int len);	//where len is length of binary you want back
		
		/** Converts from bin to unsigned int.
		*/
		unsigned int binToInt(string bin);
		
		/** Converts from bin to hex. len is the length of hex string desired after 0x.
		*/
		string binToHex(string bin, int len);	//where len is length of hex you want AFTER the 0x
		/** Given two binary strings, adds them.
		*/
		string addBin(string bin1, string bin2, int len);
		/** Given two hex strings, adds them.
		*/
		string addHex(string hex1, string hex2, int len);
		/** Retrns two's complement of given binary string.
		*/
		string twosComplement(string bin, int len);
};
#endif
