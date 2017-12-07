#ifndef _BinaryOperation_h_
#define _BinaryOperation_h_

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

class BinaryOperation
{
	public:
		BinaryOperation();
		string intToHex(int num, int len);
		string intToBin(int num, int len);
		
		int hexToInt(string hex);	//can give 0x or just start
		
		string hexToBin(string hex, int len);	//where len is length of binary you want back
		
		int binToInt(string bin);
		
		string binToHex(string bin, int len);	//where len is length of hex you want AFTER the 0x
		string addBin(string bin1, string bin2, int len);
		string addHex(string hex1, string hex2, int len);
};
#endif