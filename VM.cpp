#include "VM.h"  

VM::VM() {};

VM::VM(Instruction instruction){
	this->instruction = Instruction(*this);
		actions["add"], [&](const std::vector<int>& args) { instruction.add(args); });
		actions["load"], [&](const std::vector<int>& args) { instruction.load(args); };
};

void VM::execute() {
	instr.call();
};