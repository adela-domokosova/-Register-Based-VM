#include "Parser.h"

// have to define the nodes of the AST
// one node type or multiple

Parser::Parser() {};

// receives vector of tokens from Lexer with TokenType and value
void Parser::build_AST(std::vector<token> tokens) {

	// itterate over tokens
	//start building AST
	// use stack for help

	for (token& t : tokens) {
		if (t.type == TokenType::NUMBER) {
			stack.push(t);
		}
		if (t.type == TokenType::OPERATOR) {
			//stack by neměl být prázdný pro binární operátory
			Node left_node = stack.pop();
			node.left = std::make_unique(left_node);
		}


	}

};

