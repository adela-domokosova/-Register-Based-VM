#include "Lexer.h"

/**
Lexer creates vector of token. Lexer can categorize tokens in to enums.
**/


Lexer::Lexer() {};

std::vector<token> Lexer::tokenizer(std::string str) {
	// i expect usage of ; at the end of lines
	std::vector<token> result;

	for (int i = 0; i < str.size(); i++) {
		std::tuple<token, int> res; // for result of each builder
		// string
		if (str[i] == '"') {
			// build the string until next "
			res = build_string(i, str);
			i = std::get<1>(res);
		}
		else if (operators.find(str[i]) != operators.end()) {
			// get operator token
			res = build_operator(i, str);
			i = std::get<1>(res);
		}
		else if (str[i] == '\'') {
			// get char
			res = build_char(i, str);
			i = std::get<1>(res);
		}
		else if (std::isdigit(str[i])) {
			// build number
			// int only now
			res = build_number(i, str);
			i = std::get<1>(res);
		}
		else if (std::isalpha(str[i])) {
			// convert to lower case
			// carefull next characters might not be alpha
			// vnořená fce na rozpoznani key/varriable word -> končí mezerou?
				// metoda končí ( ?
			res = build_alphanum_string(i, str);

		}
		else if (std::isspace(str[i])) {
			// skip space
			continue;
		}
		else if (str[i] == ';') {
			std::cout << "push \n";
			// end of expression
			// push vector to parser
			return result;
		}
		else {
			// exception, unknown character, skip whole instruction up to ;
			std::cout << "unknown token in your input \n";
		}
		//push token to vector

		result.push_back(std::get<0>(res));

	}
	std::cout << "cannot push tokens, wrong line ending \n";
	//exeption, no ending to line
};

std::tuple<token, int> Lexer::build_string(int x, const std::string& str) { //
	std::string helper = "";
	x++; //skip the "
	int i = x;
	while (i < str.size()&& str[i] != '"') {
		helper = helper + str[i];
		i++;
	}
	token t = { TokenType::STRING, 0 , helper, NULL };
	std::tuple<token, int> result = { t, i };
	return result;
}

std::tuple<token, int> Lexer::build_number(int x, std::string str) { //
	std::string helper;
	while (x < str.size() && std::isdigit(str[x])) {
		helper = helper + str[x];
			x++;
	}
	x--;
	token t = { TokenType::NUMBER, std::stoi(helper) };
	return { t, x };
}


std::tuple<token, int> Lexer::build_char(int x, std::string str) { //
	x++; //skip the '
	char tchar = str[x];
	x++;
	token t = { TokenType::CHARACTER, 0, "", tchar};
	std::tuple<token, int> result = { t, x };
	return result;
}

std::tuple<token, int> Lexer::build_operator(int x, std::string str) { //
	char ochar = str[x];
	token t = { TokenType::OPERATOR, 0, "", ochar};
	std::tuple<token, int> result = { t, x };
	return result;
}