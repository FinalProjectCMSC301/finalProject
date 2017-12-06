//Register.cpp

#include "Register.h"
#include <fstream>

//file from parser
Register::Register(string file, bool debug_mode)
{
	setDebug(debug_mode);
	
	if(debug){
		cout<< "****ENTERING THE DATA INTO THE REGISTERS*****";
	}
	//array was initialized in .h file
	//string registerArray[32];
	fstream in;
	in.open(file.c_str());
	
	if(in.bad())
	{
		cout << "Invalid Register File" << endl;
	}
	
	else
	{
		int arrayCounter = 0;
		string line;
		while(getline(in, line))
		{
			//read line then put space in place of :
			std::replace(line.begin(), line.end(), ':', ' ');
			
			//1 for address, another for value
			
			int check = 0;
			for(int i = 0; i < line.length(), i++)
			{
				if(line[i] == ' ')
				{
					check++;
				}
				if(check == 1)
				{
					//meaning you have passed the register number
					//time to get value
					registerArray[arrayCounter] = registerArray[arrayCounter] + line[i];
				}
			}
			
			//registerArray[num], where num is number of register, and the value is the what was read
			//next step would be to normalize: check and add 0x
			if(registerArray[arrayCounter].substr(0, 2) != "0x")
			{
				registerArray[arrayCounter] = "0x" + registerArray[arrayCounter];
			}
			//line has been completely processed. increment counter
			arrayCounter++;
		
			if(debug){
				cout<< "****JUST ENTERED INTO REGISTER ARRAY***** << "\n" << "Register Number: " << arrayCounter << " Data: " << registerArray[arrayCounter] << "\n"";
			}
		}
	}
}

void Register::writeToRegister(int register, string value)
{
	if(writeBoolean && register >= 0 && register <= 31)
	{
		registerArray[address] = value;
	}
}

string Register::read(int register)
{
	if(readBoolean)
	{
		return registerArray[register];
	}
	return o;//IDK!!!!
}

void Register::setWrite(bool writeBool)
{
	writeBoolean = writeBool;
}

void Register::setRead(bool readBool)
{
	readBoolean = readBool;
}

void Register::setDebug(bool debugBool)
{
	debug = debugBool;
}

void Register::print()
{
	if(debug)
	{
		//not the hard part
	}
}

void Registers::setReadRegister1(string registerNumber){
    
    //if (debug) cout << "setReadRegister1 INPUT: " << "register: " << hexToInt(getHexFromBin(registerNumber)) << endl;
    readRegister1 = registerNumber;
}


void Registers::setReadRegister2(string registerNumber){
    
    //if (debug) cout << "setReadRegister2 INPUT: " << "index: " << hexToInt(getHexFromBin(registerNumber)) << endl;
    readRegister2 = registerNumber;
}


string Registers::getReadRegister1(){
    int temp;
    if(readRegister1 != ""){
        temp = hexToInt(getHexFromBin(readRegister1));
    }else{
        temp = 0;
    }
    
    if (debug) cout << "getReadRegister1 INPUT: " << "index: " << hexToInt(getHexFromBin(readRegister1)) << endl;

    
    string result = registerMap[searchInt];
    
    if (debug) cout << "getReadRegister1 OUTPUT: " <<  getHexFromBin(result) << endl;

    
    return result;
}

string Registers::getReadRegister2(){
    int searchInt;
    if(readRegister2 != ""){
        searchInt = hexToInt(getHexFromBin(readRegister2));
    }else{
        searchInt = 0;
    }
    
    if (debug) cout << "getReadRegister2 INPUT: " << "register: " << hexToInt(getHexFromBin(readRegister2)) << endl;

    

    string result = registerMap[searchInt];
    
    if (debug) cout << "getReadRegister2 OUTPUT: " <<  getHexFromBin(result) << endl;

    
    return result;
}


string Registers::getHexFromBin(string sBinary)
{
    if(sBinary != ""){
        std::stringstream ss;
        ss << std::hex << std::stoll(sBinary, NULL, 2);
        //std::cout <<"hex test " << ss.str() << std::endl;
        
        string s =  ss.str();
        while (s.length() != 8){
            s = "0" + s;
        }
        s = "0x" + s;
        return s;
        
    }
    return "0x";
}

//This method intakes a hexadecimal string and returns an integer
int Registers::hexToInt(string hexString) {
    unsigned int x;
    stringstream ss;
    ss << std::hex << hexString;
    ss >> x;
    return x;
}

//This method intakes an integer and returns a hexadecimal string
string Registers::intToHex(int integer)
{
    char output[100];
    sprintf(output, "%08x", integer);
    string result = output;
    result = "0x" + result;
    return result;
}


