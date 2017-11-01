#ifndef __PARSER_H__
#define __PARSER_H__

using namespace std;
#include <fstream>
#include <iostream>

//This Class will parse the configuration file to set up the program. The correct file format must be given.

class Parser{

  public:
   Parser(string filename);
   void PrintInfo();

  private:
	string program_input;
	string memory_contents_input;
	string register_file_input;
	string output_mode;
	bool debug_mode;
	bool print_memory_contents;
	bool write_to_file;
	string output_file;



	void setProgramInput(string input){program_input=input;};
   	void setMemoryInput(string memory){memory_contents_input=memory;};
   	void setRegisterInput(string registerInput){register_file_input=registerInput;};
  	void setOutputMode(string outputMode){output_mode=outputMode;};
   	void setDebugMode(bool debugMode){debug_mode=debugMode;};
   	void setPrintContents(bool print){print_memory_contents=print;};
   	void setWriteToFile(bool writeToFile){write_to_file=writeToFile;};
   	void setOutputFile(string outputFile){output_file=outputFile;};

   	string getProgramInput(){return program_input;};
   	string getMemoryInput(){return memory_contents_input;};
   	string getRegisterInput(){return register_file_input;};
   	string getOutputMode(){return output_mode;};
   	bool getDebugMode(){return debug_mode;};
   	bool getPrintContents(){return print_memory_contents;};
   	bool getWriteToFile(){return write_to_file;};
   	string getOutputFile(){return output_file;};
 };
 #endif
