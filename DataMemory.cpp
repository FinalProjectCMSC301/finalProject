//DataMemory.cpp

#include "DataMemory.h"
#include <fstream>

//should get file from parser
DataMemory::DataMemory(string file, bool debug)
{
	memoryContent = map<string, string>(); //initialize
	
	fstream in;
	in.open(file.c_str());
	
	if(in.bad())
	{
		cout << "Invalid Memory File" << endl;
	}
	
	else
	{
		if(debug){
			cout << "****ADDING THE MEMORY****" << "\n";
		string line;
		while(getline(in, line))
		{
			//read line then put space in place of :
			std::replace(line.begin(), line.end(), ':', ' ');
			
			//1 for address, another for value
			string array[2];
			
			int valueCheck = 0;
			for(int i = 0; i < line.length(), i++)
			{
				if(line[i] == ' ')
				{
					valueCheck++;
				}
				else
				{
					array[valueCheck] = array[valueCheck] + line[i];
				}
			}
			
			//now the array[0] has adresses, and array[1] has values
			//next step would be to normalize: check and add 0x
			if(array[0].substr(0, 2) != "0x")
			{
				array[0] = "0x" + array[0];
			}
			if(array[1].substr(0, 2) != "0x")
			{
				array[1] = "0x" + array[1];
			}
			
			//now add these values to the map
			memoryContent[array[0]] = array[1];
			if(debug){
				cout << "Added memory content: " << array[0] << " Data: " << memoryContent[array[0]] << "\n";
			}
		}
	}
}

void DataMemory::writeToMemory(string address, string value)
{
	if(writeBoolean)
	{
		memoryContent[address] = value;
	}
	if (debug){
		cout << "*** WROTE TO MEMORY***" << "\n" << "Address: " << address << " Data: " << value << "\n";
	}
}

string DataMemory::read(string address)
{
	if(readBoolean)
	{
		return memoryContent[address];
	}
	
	if (debug){
		cout << "*** READ MEMORY***" << "\n" << "Address: " << address << " Data: " << memoryContent[address] << "\n";
	}
	
	return 0;//IDK!!!!
}

void DataMemory::setWrite(bool writeBool)
{
	writeBoolean = writeBool;
}

void DataMemory::setRead(bool readBool)
{
	readBoolean = readBool;
}

void DataMemory::setDebug(bool debugBool)
{
	debug = debugBool;
}

void DataMemory::print()
{
	if(debug)
	{
		//not the hard part
	}
}
