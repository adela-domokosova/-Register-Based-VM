#include <string>
#include <unordered_set>
#include <tuple>
#include <iostream>
#include "Token.h"
#pragma once

class Lexer
{
public:
	Lexer();
	std::unordered_set<std::string> keywords;
	std::unordered_set<char> operators = { '+', '-', '*', '/', '=' };
	std::unordered_set<std::string> bools = { "true", "false" };
	std::vector<token> tokenizer(std::string str);
private:
	std::tuple<token, int> build_string(int x, const std::string& str);
	std::tuple<token, int> build_number(int x, std::string str);
	std::tuple<token, int> build_char(int x, std::string str);
	std::tuple<token, int> build_operator(int x, std::string str);
};

