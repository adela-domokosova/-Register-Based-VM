#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_set>
#include "Token.h"
#pragma once

struct Node {
	token token;
	std::unique_ptr<Node> left; 
	std::unique_ptr<Node> right;
};

class Parser
{
//parse line vs parse program
public:	
	Parser();
	//void parseProgram(std::string str);
	//void parseLine();
private:
	void build_AST(std::vector<token> tokens);
	std::stack<token> stack;
};

