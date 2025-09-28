#include "Parser.h"

Parser::Parser() {};

std::vector<token> Parser::parse(std::string x) {
	// separate lines and only call tokenize per line?
	std::vector<token> tokens = tokenize(x, " ");

	//execute methods based on tokens

	// in case of creating a abstraction layer, add AST and then parse it to the VM methods
	return tokens;
};

std::vector<token> Parser::tokenize(std::string x, std::string del) {
	std::cout << x << "\n";

	// i expect usage of ; at the end of lines
	std::string helper = "";
	std::vector<token> result;

	//special characters
	std::unordered_set<char> operators = { '+', '-', '*', '/', '='};

	for (int i = 0; i < (int)x.size(); i++) {
		std::cout << x[i] << "\n";
		token token;
		// get string character
		if (isalnum(x[i])) {
			helper += x[i];
		}
		else if (std::isblank(x[i])) {
			//what about move whitespaces after each other
			if (!helper.empty()) {
				if (result.empty()) {
				//first token defines the operation
					token = create_method_token(helper);
				}else{
					token = create_token(helper);
				}
				result.push_back(token);
				helper.clear();
			}
			// helper string is empty -> continue for loop
		}
        else if (operators.find(x[i]) != operators.end()) { // i expect that 
			token.value = x[i];
			token.type = TokenType::OPERATORS;

		}
		else if ((x[i])==';') {
			token = create_token(helper);
			result.push_back(token);
			for (auto& i : result) {
				std::cout << i.value << "\n";
			}
			return result;
		}
		else {
			std::cout << "cannot read the character \n";
			helper.clear();
		}
	}
	std::cerr << "Tokenizer error: missing ';' at end of line\n";
	return {};
};

bool Parser::is_number(const std::string& str) {
	// registers only support unsigned numbers
	// i only expect unsigned numbers
	for (char c : str) {
		if (!isdigit(static_cast<unsigned char>(c))) {
			// unsigned char -> char up to 255 bits -> no unefined behaviour in case of ř,ž,ect chars
			return false;
		}
	}
	return true;
}


token Parser::create_token(std::string helper) {
	if (is_number(helper)) {
		return token{ helper, TokenType::NUMBER };
	}
	else {
		return token{ helper, TokenType::VARIABLE };
	}
}

token Parser::create_method_token(std::string helper) {
	// method token will be created -> the VM has more info about accessible methods and will check if the method is valid
	return token{ helper, TokenType::METHOD};
}