#include "Parser.h"

Parser::Parser(string filename){

fstream fs;
fs.open(filename);
  if(!file.find(".txt")){
    cerr<<"CONFIGURATION FILE NEEDS TO BE A .txt FILE";
    system.exit();
  }
  string line;
 while(getline(fs,line)){
   if(line.empty()){
   }
   else if (line.substr(0,1).compare("#")==0){
   }
   else{
     while(line.substr(0,1)==" "){
       line = line.substr(1,line.length);
     }       
     switch(line.sub(0,8){
       case "program_": setProgramInput(line.substr(line.find("=")+1,string::npos));
             break;
       case "memory_c": setMemoryInput(line.substr(line.find("=")+1,string::npos));
            break;
       case "register": setRegisterInput(line.substr(line.find("=")+1,string::npos));
            break;
       case "output_m": setOutputMode(line.substr(line.find("=")+1,string::npos));
            break;
       case "debug_mo": if(line.find("true")){
                              setDebugMode(true);
                        }
                        else {setDebugMode(false);}
            break;
       case "print_me":  if(line.find("true")){
                              setPrintContents(true);
                        }
                        else {setPrintContents(false);}
            break;
       case "output_f": setOutputFile(line.substr(line.find("=")+1,string::npos));
            break;
       case "write_to":  if(line.find("true")){
                              setWritetoFile(true);
                        }
                        else {setWriteToFile(false);}
     }   
 }

fs.close()
}
