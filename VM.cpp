#include "VM.h"  
#include "Instruction.h"

VM::VM() {};

VM::VM(Parser parser){
	this->parser = Parser();
};

//accepts line of VM readable code
/**
void VM::execute(std::vector<token> tokens) {
	std::vector<std::string> args;
	std::string instr = tokens.front().value;
	tokens.erase(tokens.begin());

	//when calling the Intruction static methods i can check for right number of args and their format

	for(auto& t: tokens){
		args.push_back(t.value);
	}

	if (instr == "add") {
		Instruction::add(*this, args);
	}
	else if (instr == "move") {
		Instruction::move(*this, args);
	}else if (instr == "print"){
		Instruction::print(*this, args);
	}
	else if (instr == "store") {
		Instruction::store(*this, args);
	}
	else if (instr == "load") {
		Instruction::load(*this, args);
	}
	else {
		std::cerr << "Unknown instruction: " << instr << "\n";
	}


};
**/