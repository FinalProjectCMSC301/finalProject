//Register.cpp

#include "Register.h"
#include <fstream>

//file from parser
Register::Register(string file)
{
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
				cout<< "****JUST ENTERED INTO REGISTER ARRAY***** << "\n" << "Register Number: " << arrayCounter << " Data: " << registerArray[arrayCounter] << "\n";
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
	return //IDK!!!!
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
