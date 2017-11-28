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
	int registerArray [32];
	void PrintInfo();



private:
    int convert(string intput);   
};
#endif
