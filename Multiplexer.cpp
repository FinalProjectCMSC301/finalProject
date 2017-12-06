#include "Multiplexer.h"
#include <string>
#include <sstream>

Multiplexer::Mutiplexer(){
	
}

void Multiplexer::useMultiplexer(string input1, string input2, string muxChoice){
		
	choice1=input1;
	choice2 = input2;
	choice=muxChoice;
	
	if(choice.compare("0")==0){
		cout << "Output: " << choice1;
		output = choice1;
	}
	else{
		cout << "Output: " << choice2;
		output = choice2;
	}

}


