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
	std::tuple<token, int> build_number(int x, const std::string& str);
	std::tuple<token, int> build_char(int x, const std::string& str);
	std::tuple<token, int> build_operator(int x, const std::string& str);
	std::tuple<token, int> build_alphanum_string(int x, const std::string& str);
	// const std::string&  from cpp 17 could be used std::string_view
	// fix the " warning: comparison of integers of different signs: 'int' and 'std::size_t' "
};

