#include "Multiplexer.h"
#include <string>
#include <sstream>

Multiplexer::Mutiplexer(){
	choice1="";
	choice2="";
}

string Multiplexer::useMultiplexer(string input1, string input2, int muxChoice){
	if (debug){
		cout << "*** MULTIPLEXER STRING/STRING***" << "\n" << "String1: " << input1 << " String2: " << input2 << "Choice: " << choice << "\n";
	}
	
	cout << "Input: " << input1 << " " << input2 << "\n"; 
	
	choice1=input1;
	choice2 = input2;
	choice=muxChoice;
	if(choice==0){
		cout << "Output: " << choice1;
		return choice1;
	}
	else{
		cout << "Output: " << choice2;
		return choice2;
	}

}


