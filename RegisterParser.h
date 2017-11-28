#ifndef __REGISTERPARSER_H__
#define __REGISTERPARSER_H__


#include <fstream>
#include <iostream>
using namespace std;

class RegisterParser{

public:
	RegisterParser(string filename);
	void completeParse(string file);
	int getRegisterData(int index){return registerArray[index];};
	void setRegisterData(int registerNum, string data){registerArray[registerNum]=convert(data);};
	void setRegisterData(int registerNum, int data){registerArray[registerNum]=data;};
	int registerArray [32];
	void PrintInfo();



private:
    int convert(string intput);   
};
#endif
