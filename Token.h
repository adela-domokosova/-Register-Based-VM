#include <string>
#pragma once

enum TokenType {
	VARIABLE, METHOD, NUMBER, STRING, CHARACTER, BOOLEAN, OPERATOR, KEYWORD
};
// variable starts with alph, can contain '_' and numbers
// character is in '' quotes
// string is in "" quotes
// keyword, method idk yet


struct token {
	TokenType type;
	int number = 0;
	std::string string;
	char character = '\0';
};
