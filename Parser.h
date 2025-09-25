#include <iostream>
#include <vector>
#include "Instruction.h"
#pragma once

enum TokenType { VARIABLE, INSTRUCTION, METHOD , OPERATORS };

struct token
{
	std::string value;
	enum TokenType;
};

class Parser
{
//parse line vs parse program
public:	
	Parser();
	std::vector<token> parse(std::string x);
	std::vector<token> tokenize(std::string x, std::string del);
private:
	void parseProgram(std::string str);
	void parseLine();

};

