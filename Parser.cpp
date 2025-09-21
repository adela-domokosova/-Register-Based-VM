#include "Parser.h"

Parser::Parser() {};
void Parser::parse(std::string x) {
	// separate lines and only call tokenize per line?
	std::vector<std::string> tokens = tokenize(x, " ");

	//execute methods based on tokens

	// in case of creating a abstraction layer, add AST and then parse it to the VM methods

};

std::vector<std::string> tokenize(std::string x, std::string del) {
	std::string helper = "";
	std::vector<std::string> result;
	for (int i = 0; i < (int)x.size(); i++) {
		if (isalnum(x[i])) {
			helper += x[i];
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