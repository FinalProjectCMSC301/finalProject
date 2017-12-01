#include "Multiplexor.h"
#include <string>
#include <sstream>

string Multiplexor::Multiplexor(string input1, string input2, int choice){
	if(choice==0){
		return input1;
	}
	else{
		return input2;
	}

}

int Multiplexor::Multiplexor(int input1, int input2, int choice){
	if(choice==0){
		return input1;
	}
	else{
		return input2;
	}
}

string Multiplexor::Multiplexor(string input1, int input2, int choice){

	stringstream  ss;
	ss<< input2;
	string input2string = ss.str();
	
	if(choice==0){
		return input1;
	}
	else {
		return input2string;
	}
}