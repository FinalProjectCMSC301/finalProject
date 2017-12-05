#include "Multiplexer.h"
#include <string>
#include <sstream>

Multiplexer::Mutiplexer(){
}

string Multiplexer::useMultiplexer(string input1, string input2, int choice){
	if (debug){
		cout << "*** MULTIPLEXER STRING/STRING***" << "\n" << "String1: " << input1 << " String2: " << input2 << "Choice: " << choice << "\n";
	}
	
	cout << "Input: " << input1 << " " << input2 << "\n"; 
	
	
	if(choice==0){
		cout << "Output: " << input1;
		return input1;
	}
	else{
		cout << "Output: " << input2;
		return input2;
	}

}

int Multiplexer::useMultiplexer(int input1, int input2, int choice){
	
	if (debug){
		cout << "*** MULTIPLEXER INT/INT***" << "\n" << "Int1: " << input1 << " Int2: " << input2 << "Choice: " << choice << "\n";
	}
	cout << "Input: " << input1 << " " << input2 << "\n"; 
	
	if(choice==0){
		cout << "Output: " << input1;
		return input1;
	}
	else{
		cout << "Output: " << input2;
		return input2;
	}
}

string Multiplexer::useMultiplexer(string input1, int input2, int choice){

	stringstream  ss;
	ss<< input2;
	string input2string = ss.str();
	cout << "Input: " << input1 << " " << input2 << "\n"; 
	if (debug){
		cout << "*** MULTIPLEXER STRING/INT***" << "\n" << "String1: " << input1 << " INT1: " << input2 << "Choice: " << choice << "\n";
	}
	if(choice==0){
		cout << "Output: " << input1;
		return input1;
	}
	else {
		cout << "Output: " << input2;
		return input2string;
	}
}
