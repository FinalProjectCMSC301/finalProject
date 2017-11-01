#include "Parser.h"
#include <stdlib.h>
Parser::Parser(string filename){

  fstream fs;
  fs.open(filename.c_str());
  if(!filename.find(".config")){
    cerr<<"CONFIGURATION FILE NEEDS TO BE A .txt FILE";
    exit(EXIT_FAILURE);
  }
  string line;
  
  while(getline(fs,line)){
  
    if(line.empty()){
    }
    else if (line.substr(0,1).compare("#")==0){
    }

    else {
          
      if(line.substr(0,line.rfind("=")).compare("program_input")==0){

        setProgramInput(line.substr(line.find("=")+1,line.size()-line.rfind("=")));
      
       }
      else if( line.substr(0,line.rfind("=")).compare("memory_contents_input")==0){
        setMemoryInput(line.substr(line.find("=")+1,string::npos));
     
      }
      else if(line.substr(0,line.rfind("=")).compare("register_file_input")==0){
         setRegisterInput(line.substr(line.find("=")+1,string::npos));
     
      }
      else if(line.substr(0,line.rfind("=")).compare("output_mode")==0){
         setOutputMode(line.substr(line.find("=")+1,string::npos));
     
       }

      else if(line.substr(0,line.rfind("=")).compare("debug_mode")==0){
        if(line.find("true")){
             setDebugMode(true);
        }
        else {setDebugMode(false);}
    
      }

      else if (line.substr(0,line.rfind("=")).compare("print_memory_contents")==0){
        if(line.find("true")){
          setPrintContents(true);
        }
        else {setPrintContents(false);}
    
      }

      else if (line.substr(0,line.rfind("=")).compare("output_file")==0){
        setOutputFile(line.substr(line.find("=")+1,string::npos));
   
      }

      else if (line.substr(0,line.rfind("=")) .compare("write_to_file")==0){
          if(line.find("true")){
            setWriteToFile(true);
            }
          else {setWriteToFile(false);}
      
      }
    }   
  }
fs.close();
}

void Parser::PrintInfo(){
  cout<< "Program input: " <<getProgramInput()<< '\n';
  cout<< "Memory File: " <<getMemoryInput() << '\n';
  cout << "Register File: " << getRegisterInput() << '\n';
  cout << "Output Mode: " << getOutputMode() << '\n';
  cout << "Debug Mode: " << getDebugMode() << '\n';
  cout << "Print Contents: " << getPrintContents() << '\n';
  cout << "Write to File: " << getWriteToFile() << '\n';
  cout << "Output File: " << getOutputFile() << '\n';
}

