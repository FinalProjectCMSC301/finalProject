#include "Multiplexer.h"
#include <string>
#include <sstream>

void Multiplexer::useMultiplexer(string input1, string input2, string muxChoice){
		
	choice1=input1;
	choice2 = input2;
	choice=muxChoice;
	
	if(choice.compare("0")==0){
		output = choice1;
	}
	else{
		output = choice2;
	}

}


