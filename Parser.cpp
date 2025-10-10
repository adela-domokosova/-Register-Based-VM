#include "Parser.h"

Parser::Parser() {};

// receives vector of tokens from Lexer with TokenType and value
std::vector<token> Parser::parse(std::string x) {
	// separate lines and only call tokenize per line?

	//execute methods based on tokens
	std::vector<token> tokens;
	return tokens;
	// in case of creating a abstraction layer, add AST and then parse it to the VM methods
};

