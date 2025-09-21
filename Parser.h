#include <iostream>
#include <vector>
#include "Instruction.h"
#pragma once

class Parser
{
//parse line vs parse program
public:	
	Parser();
	void parse(std::string x);
	std::vector<std::string> tokenize(std::string x, std::string del);
private:
	void parseProgram(std::string str);
	void parseLine();

};

