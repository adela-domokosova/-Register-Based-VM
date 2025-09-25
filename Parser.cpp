#include "Parser.h"

Parser::Parser() {};

void Parser::parse(std::string x) {
	// separate lines and only call tokenize per line?
	std::vector<std::string> tokens = tokenize(x, " ");

	//execute methods based on tokens

	// in case of creating a abstraction layer, add AST and then parse it to the VM methods

};

std::vector<token> tokenize(std::string x, std::string del) {
	std::string helper = "";
	std::vector<token> result;
	for (int i = 0; i < (int)x.size(); i++) {
		// need to check if its var or num or instruction
		if (isdigit(x[i])) {
			helper += x[i];
			//check if the next is also digit
		}
		else if ( isalpha(x[i])) {
			helper += x[i];
			//check if next is also alpha
		}
		else if (isblank(x[i])) {
			result.push_back(helper);
			helper = "";
		}
		else {
			std::cout << "cannot read the character \n";
			helper = "";
		}
	}
	return result;
};