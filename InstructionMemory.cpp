//InstructionMemory.cpp

#include "InstructionMemory.h"

InstructionMemory::InstructionMemory(string fileName)
{
	//initialize the array
	myArray[ADD].name = "add";
	myArray[ADD].numOps = 3;
	myArray[ADD].rdPos = 0;
	myArray[ADD].rsPos = 1;  
	myArray[ADD].rtPos = 2;   
	myArray[ADD].immPos = -1;  
	myArray[ADD].instType = RTYPE; 
	myArray[ADD].op_field = "000000"; 
	myArray[ADD].funct_field = "100000";

	myArray[ADDI].name = "addi"; 
	myArray[ADDI].numOps = 3; 
	myArray[ADDI].rdPos = -1; 
	myArray[ADDI].rsPos = 1;  
	myArray[ADDI].rtPos = 0;   
	myArray[ADDI].immPos = 2; 
	myArray[ADDI].instType = ITYPE; 
	myArray[ADDI].op_field = "001000"; 
	myArray[ADDI].funct_field = "";
	
	myArray[SLT].name = "slt";
	myArray[SLT].numOps = 3; 
	myArray[SLT].rdPos = 0; 
	myArray[SLT].rsPos = 1;  
	myArray[SLT].rtPos = 2;   
	myArray[SLT].immPos = -1; 
	myArray[SLT].instType = RTYPE; 
	myArray[SLT].op_field = "000000"; 
	myArray[SLT].funct_field = "101010";
	
	myArray[J].name = "j";
	myArray[J].numOps = 1; 
	myArray[J].rdPos = -1; 
	myArray[J].rsPos = -1;  
	myArray[J].rtPos = -1;   
	myArray[J].immPos = 0; 
	myArray[J].instType = JTYPE; 
	myArray[J].op_field = "000010";
	myArray[J].funct_field = "";

	myArray[SUB].name = "sub";
	myArray[SUB].numOps = 3; 
	myArray[SUB].rdPos = 0; 
	myArray[SUB].rsPos = 1;  
	myArray[SUB].rtPos = 2;   
	myArray[SUB].immPos = -1; 
	myArray[SUB].instType = RTYPE; 
	myArray[SUB].op_field = "000000";
	myArray[SUB].funct_field = "100010";

	myArray[LW].name = "lw";
	myArray[LW].numOps = 3; 
	myArray[LW].rdPos = -1; 
	myArray[LW].rsPos = 2;  
	myArray[LW].rtPos = 0;   
	myArray[LW].immPos = 1;
	myArray[LW].instType = ITYPE; 
	myArray[LW].op_field = "100011";
	myArray[LW].funct_field = "";

	myArray[SW].name = "sw";
	myArray[SW].numOps = 3; 
	myArray[SW].rdPos = -1; 
	myArray[SW].rsPos = 2;  
	myArray[SW].rtPos = 0;   
	myArray[SW].immPos = 1;
	myArray[SW].instType = ITYPE; 
	myArray[SW].op_field = "101011";
	myArray[SW].funct_field = "";

	myArray[BEQ].name = "beq";
	myArray[BEQ].numOps = 3; 
	myArray[BEQ].rdPos = -1; 
	myArray[BEQ].rsPos = 0;  
	myArray[BEQ].rtPos = 1;   
	myArray[BEQ].immPos = 2; 
	myArray[BEQ].instType = JTYPE; 
	myArray[BEQ].op_field = "000100";
	myArray[BEQ].funct_field = "";
	
	readInstructions(fileName);
	//assume that vector<string> myInstructions has all instructions now
}

void InstructionMemory::readInstructions(string fileName)
{
	fstream in;
	in.open(fileName.c_str());
	
	if(in.bad())
	{
		cout << "Invalid Register File" << endl;
	}
	
	else
	{
		string line;
		string instArray[5];
		int instArrayCounter = 0;
		while(getline(in, line))
		{
			//remember to check for comments	
			char str[100];
			strcpy(str, line.c_str());
			char * pch;
			pch = strtok (str," $,()\t");
			while (pch != NULL)
			{
			std::string strg(pch);
			//strg has a token. Process it.
			instArray[instArrayCounter] = strg;
			instArrayCounter++;
			pch = strtok (NULL, " $,()\t");
			}
			//convert the stuff in instArray and get a binary string.
			string binary = processInstArray(instArray);
			//push this string to vector now.
			myInstructions.push_back(binary);
		}
	}
}

string InstructionMemory::processInstArray(string array[])
{
	Opcode opcode = getOpcode(array[0]);
	//now you know what type of thing this is
	//based on the positions, get the different stuff.
	//get binary of positions.
	string rs,rt,rd,imm;
	string toReturn = "";
	if(myArray[opcode].rsPos != -1)
	{
		rs = registerNumToBinary(array[myArray[opcode].rsPos]);
	}
	if(myArray[opcode].rtPos != -1)
	{
		rt = registerNumToBinary(array[myArray[opcode].rtPos]);
	}
	if(myArray[opcode].rdPos != -1)
	{
		rd = registerNumToBinary(array[myArray[opcode].rdPos]);
	}
	if(myArray[opcode].immPos != -1)
	{
		imm = getImm(array[myArray[opcode].immPos], opcode);
	}
	string functField = myArray[opcode].funct_field;
	//now the stuff is ready. All the register binaries have been computed, same for immediate.
	//put it all together
	toReturn.append(myArray[opcode].op_field);
	if(opcode == ADD || opcode == SUB || opcode == SLT)
	{
		toReturn.append(rs);
		toReturn.append(rt);
		toReturn.append(rd);
		toReturn.append("00000");
		toReturn.append(functField);
		return toReturn;
	}
	if(opcode == BEQ || opcode == LW || opcode == SW || opcode == ADDI)
	{
		toReturn.append(rs);
		toReturn.append(rt);
		toReturn.append(imm);
		return toReturn;
	}
	else
	{
		toReturn.append(imm);
		return toReturn;
	}
	
}

Opcode InstructionMemory::getOpcode(string s)
{
	for(int i = ADD; i < UNDEFINED; i++)
	{
		if(myArray[i].name == s)
		{
			return (Opcode)i;
		}
	}
	return UNDEFINED;
}

string InstructionMemory::registerNumToBinary(string s)
{
    string toReturn = "";
	int value = atoi(s.c_str());
	while(value > 0)
	{
      int digit = value % 2;
      value = value / 2;
      stringstream ss;
      ss << digit;
      toReturn.insert(0, ss.str());
    }
    if((int)toReturn.length() == 5)
	{
      return toReturn;
    }
    int remaining = 5 - (int)toReturn.length();
    for(int k = 0; k < remaining; k++)
	{
      toReturn.insert(0, "0");
    }
    return toReturn;
}

string InstructionMemory::getImm(string s, Opcode opcode) //s can be a number or a hex address
{
	//in what cases would it be a number? what cases would it be a hex?
	//handle both cases.
	//Cases with number: ADDI, LW, SW
	//addi: 16, LW: 16, SW: 16
	//cases with hex: BEQ, J
	//BEQ: 16, J: 26
	if(opcode == ADD || opcode == LW || opcode == SW)
	{
		return immToBinarySixteen(s);
	}
	//int i = stoi(s,nullptr,0);
	if(opcode == BEQ)
	{
		int i = stoi(s,nullptr,0);
		//i has the int value of hex address for BEQ
		stringstream ss;
		ss << i;
		return immToBinarySixteen(ss.str());
	}
	if(opcode == J)
	{
		int i = stoi(s,nullptr,0);
		//i has the int value of hex address for J
		stringstream ss;
		ss << i;
		return jumpImmToBinaryTwentySix(ss.str());
	}
	return 0;
}

string InstructionMemory::jumpImmToBinaryTwentySix(string s)
{
	string toReturn = "";
	int value = atoi(s.c_str());
	while(value > 0)
	{
      int digit = value % 2;
      value = value / 2;
      stringstream ss;
      ss << digit;
      toReturn.insert(0, ss.str());
    }
    if((int)toReturn.length() == 26)
	{
      return toReturn;
    }
    int remaining = 26 - (int)toReturn.length();
    for(int k = 0; k < remaining; k++)
	{
      toReturn.insert(0, "0");
    }
    return toReturn;
}

//takes a string s of integer
string InstructionMemory::immToBinarySixteen(string s)
{
	string toReturn = "";
	int value = atoi(s.c_str());
	int negative = 0;
	if(value < 0)
	{
		negative = 1;
		value = value * -1;
	}
	while(value > 0)
	{
      int digit = value % 2;
      value = value / 2;
      stringstream ss;
      ss << digit;
      toReturn.insert(0, ss.str());
    }
    if((int)toReturn.length() == 16)
	{
      return toReturn;
    }
    int remaining = 16 - (int)toReturn.length();
    for(int k = 0; k < remaining; k++)
	{
      toReturn.insert(0, "0");
    }
	if(negative = 1)
	{
		//compute two's complement>.........DOOOOOOO THISSSS!!!!
		return twosComplement(toReturn);
	}
    return toReturn;
}

string InstructionMemory::twosComplement(string bitString)
{
	
	int bitArray[16];

	for(int x = 0; x <= 15; x++)
	{
		bitArray[x] = bitString.substr(x, 1);
	} 

	for(int y = 0; y <= 15; y++)
	{

		if(bitArray[y] == 1)
		{
			bitArray[y] = 0;
		}

		else
		{
			bitArray[y] = 1;
		}

	}

	bitArray[15] = bitArray[15] + 1;

	for(int z = 14; z > 0; z--)
	{
		if(bitArray[z] == 2)
		{
			bitArray[z + 1] = 0;
			bitArray[z] = bitArray[z] + 1;
		}
	}

	if(bitArray[0] == 2)
	{
		return "OVERFLOW FOR TWO'S COMPLEMENT";
	}
	else
	{
		sstream ss;
		for(int w = 0; w <= 15; w++)
		{
			ss << bitArray[w];
		}
		return ss.str();
	}
}

string InstructionMemory::getInstruction(int index)
{
	return myInstructions.at(index);
}