#include "BinaryOperation.h"

using namespace std;

BinaryOperation::BinaryOperation()
{
	//empty
}

string BinaryOperation::intToHex(int num, int len)
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

string BinaryOperation::intToBin(int num, int len)
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
	if(s.size() < len)
	{
		int remainingBits = len - s.size();
		for(int i = 0; i < remainingBits; i++)
		{
			s.insert(0, "0");
		}
	}
	if(negative == 1)
	{
		//TWO'S COMPLEMENT
	}
	return s;
}

int BinaryOperation::hexToInt(string hex)
{
	if((hex[1] == 'x' || hex[1] == 'X') && hex[0] == '0')
	{
		int result = stoi(hex, nullptr, 0);
		return result;
	}
	int result = stoi(hex, nullptr, 16);
	cout << "The result is " << result << endl;
	return result;
}

string BinaryOperation::hexToBin(string hex, int len)
{
	if(hex.substr(0,2).compare("0x")==0){
		hex = hex.substr(2);
	}
	cout << "In hexToBin: hex - " << hex << " int - ";
	int result = hexToInt(hex);
	cout << "In hexToBin: hex - " << hex << " int - " << result << endl;
	cout << "test intToBin" << intToBin(result, len) << endl;
	return intToBin(result, len);
}

int BinaryOperation::binToInt(string bin)
{
	int result = stoi(bin, nullptr, 2);
	return result;
}

string BinaryOperation::binToHex(string bin, int len)
{
	int intValue = binToInt(bin);
	string result = intToHex(intValue, len);
	return result;
}

string BinaryOperation::addBin(string bin1, string bin2, int len)
{
	int op1 = binToInt(bin1);
	int op2 = binToInt(bin2);
	int sum = op1 + op2;
	return intToBin(sum, len);
}

string BinaryOperation::addHex(string hex1, string hex2, int len)
{
	int op1 = hexToInt(hex1);
	int op2 = hexToInt(hex2);
	int sum = op1 + op2;
	return intToHex(sum, len);
}
