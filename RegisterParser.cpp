#include "RegisterParser.h"
#include <string>
#include <sstream>

RegisterParser::RegisterParser(string filename){
	completeParse(filename);

}

void RegisterParser::completeParse(string file){
	fstream fs;
	fs.open(file.c_str());

	string line;

	while(getline(fs,line)){

		if(line.empty()){

		}

		if(line.substr(0,1).compare("#")==0){

		}

		else{

			while(line.substr(0,1)==" "){
				line = line.substr(1,string::npos);
				}
		    istringstream buffer(line.substr(0,line.find_last_of(":")));
			int index;
			buffer >> index;
			int value = convert(line.substr(line.find_last_of(":")+1,string::npos));
			registerArray[index]=value;

		}

	}

	fs.close();
}

int RegisterParser::convert(string input){
	int returnValue;
	stringstream ss;
	ss << std::hex << input;
	ss >> returnValue;
	return returnValue;
}
void RegisterParser::PrintInfo(){
	for( int x=0; x<32; x++){
		cout << "Index: " << x << " Value: " << registerArray[x] << "\n";
	}
}