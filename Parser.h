#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "Token.h"
#pragma once

class Parser
{
//parse line vs parse program
public:	
	Parser();
	std::vector<token> parse(std::string x);
	//void parseProgram(std::string str);
	//void parseLine();
};

