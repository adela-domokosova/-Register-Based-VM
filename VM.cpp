#include "VM.h"  

VM::VM() {};

VM::VM(Instruction instruction, Parser parser){
	this->instruction = Instruction();
	this->parser = Parser();
	actions["add"] = [&](VM& vm, const std::vector<int>& args) { instruction.add(vm, args); } ;
	actions["load"], [&](VM& vm, const std::vector<int>& args) { instruction.load(vm, args); };
};

void VM::execute(VM vm, std::vector<token> tokens) {
	// tokens vector includes one line of tokenized machine code
	// first token in expected to be type instruction

	//for future reference, it will be usefull to use the TokenType
	std::vector<int> args;
	std::string instr = tokens.front().value;
	tokens.erase(tokens.begin());
	for (auto& t : tokens) {
		args.push_back(std::stoi(t.value));
	}
	if (actions.count(instr)) {
		actions[instr](*this, args);
	}
	else {
		std::cerr << "Unknown instruction: " << instr << "\n";
	}


};