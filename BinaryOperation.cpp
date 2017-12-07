#include "BinaryOperation.h"

using namespace std;

BinaryOperation::BinaryOperation()
{
	//empty
}

string BinaryOperation::intToHex(unsigned int num, int len)
{
	stringstream stream;
	stream << hex << num;
	string result = stream.str();
	if(result.size() < len)
	{
		int remain = len - result.size();
		for(int j = 0; j < remain; j++)
		{
			result.insert(0, "0");
		}
	}
	result.insert(0, "0x");
	return result;
}

string BinaryOperation::intToBin(unsigned int num, int len)
{
	string s("");
	int negative = 0;
	if(num < 0)
	{
		negative = 1;
		num = num * -1;
	}
	while(num > 0)
	{
		int remain = num % 2;
		num = num / 2;
		s.insert(0, to_string(remain));
	}
	if(negative == 1)
	{
		s = twosComplement(s, len);
	}
	if(s.size() < len)
	{
		int remainingBits = len - s.size();
		for(int i = 0; i < remainingBits; i++)
		{
			s.insert(0, "0");
		}
	}
	return s;
}

unsigned int BinaryOperation::hexToInt(string hex)
{
	if((hex[1] == 'x' || hex[1] == 'X') && hex[0] == '0')
	{
		unsigned int result = strtol(hex.c_str(), nullptr, 0);
		return result;
	}
	unsigned int result = strtol(hex.c_str(), nullptr, 16);
	return result;
}

string BinaryOperation::hexToBin(string hex, int len)
{
	unsigned int result = hexToInt(hex);
	return intToBin(result, len);
}

unsigned int BinaryOperation::binToInt(string bin)
{
	unsigned int result = strtol(bin.c_str(), nullptr, 2);
	return result;
}

string BinaryOperation::binToHex(string bin, int len)
{
	unsigned int intValue = binToInt(bin);
	cout<<"print out intValue"<< intValue << endl;
	string result = intToHex(intValue, len);
	return result;
}

string BinaryOperation::addBin(string bin1, string bin2, int len)
{
	unsigned int op1 = binToInt(bin1);
	unsigned int op2 = binToInt(bin2);
	unsigned int sum = op1 + op2;
	return intToBin(sum, len);
}

string BinaryOperation::addHex(string hex1, string hex2, int len)
{
	unsigned int op1 = hexToInt(hex1);
	unsigned int op2 = hexToInt(hex2);
	unsigned int sum = op1 + op2;
	return intToHex(sum, len);
}

string BinaryOperation::twosComplement(string bin, int len)
{
	if(bin.size() < len)
	{
		int remain = len - bin.size();
		for(int i = 0; i < remain; i++)
		{
			bin.insert(0, "0");
		}
	}
	string revString("");
	for(int i = 0; i < bin.size(); i++)
	{
		if(bin[i] == '1')
		{
			revString.append("0");
		}
		else
		{
			revString.append("1");
		}
	}
	unsigned int reversed = binToInt(revString);
	reversed = reversed + 1;
	string afterAdd = intToBin(reversed, bin.size());
	if(afterAdd.size() > revString.size())
	{
		int extra = afterAdd.size() - revString.size();
		afterAdd.erase(0, extra);
	}
	return afterAdd;
}