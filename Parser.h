#ifndef __PARSER_H__
#define __PARSER_H__

using namespace std;
#include <fstream>
#include <iostream>

//This Class will parse the configuration file to set up the program. The correct file format must be given.

class Parser{

  public:
   Parser(string filename);
   PrintInfo();

  private:
	string program_input;
	string memory_contents_input;
	string register_file_input;
	string output_mode;
	bool debug_mode;
	bool print_memory_contents;
	bool write_to_file;
	string output_file;



   setProgramInput(string input);
   setMemoryInput(string memory);
   setRegisterInput(string registerInput);
   setOutputMode(string outputMode);
   setDebugMode(bool debugMode);
   setPrintContents(bool print);
   setWriteToFile(bool writeToFile);
   setOutputFile(string outputFile);

   string getProgramInput();
   string getMemoryInput();
   string getRegisterInput();
   string getOutputMode();
   bool getDebugMode();
   bool getPrintContents();
   bool getWriteToFile();
   string getOutputFile();
 };
 #endif
