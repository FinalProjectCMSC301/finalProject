#ifndef __REGISTERPARSER_H__
#define __REGISTERPARSER_H__

using namespace std;
#include <fstream>
#include <iostream>


class RegisterParser{

public:
	RegisterParser(string filename);
	void completeParse(string file);
	string registerArray [32];
	void PrintInfo(){for(int x=0; x<32; x++){ cout<< "Index: " << x << " Value: " << registerArray[x]<< '\n';}};

};
#endif