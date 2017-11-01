
#include "Parser.h"
int main (int argc, char *argv[]){
	Parser *parser;
	parser = new Parser("input.config");
	parser->Parser::PrintInfo();
	delete parser;
}
