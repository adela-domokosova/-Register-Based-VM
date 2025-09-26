#include <iostream>
#include <vector>
#include <string>
#include "Instruction.h"
#pragma once

enum TokenType { VARIABLE, INSTRUCTION, METHOD , OPERATORS, NUMBER };

struct token
{
	std::string value;
	TokenType type;
};

class Parser
{
//parse line vs parse program
public:	
	Parser();
	std::vector<token> parse(std::string x);
private:
	std::vector<token> tokenize(std::string x, std::string del);
	bool is_number(const std::string& str);
	token create_token(std::string helper);
	//void parseProgram(std::string str);
	//void parseLine();
};

