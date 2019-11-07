//Multiplexer.cpp
#include "Multiplexer.h"

using namespace std;

Multiplexer::Multiplexer()
{
	one = "";
	two = "";
	control = "";
}

void Multiplexer::setOne(string something)
{
	one = something;
}

void Multiplexer::setTwo(string something)
{
	two = something;
}

void Multiplexer::setControl(string something)
{
	control = something;
}

string Multiplexer::getOutput()
{
	if(control == "1")
	{
		return one;		
	}
	else
	{
		return two;
	}
}