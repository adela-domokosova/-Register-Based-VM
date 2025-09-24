#include "Instruction.h"

Instruction::Instruction(VM& vm) : vm(vm) {};

void Instruction::add(const std::vector<int>& args) {
	if (args.size() == 2) {
		uint32_t maxVal = std::numeric_limits<uint16_t>::max(); // 65535
		uint32_t sum = (uint32_t)vm.regs[args.at(1)] + (uint32_t)vm.regs[args.at(2)];

		if (sum > maxVal) {
			std::cout << "overflow \n";
		}
		// check overflow
		else {
			vm.regs[args.at(1)] = (uint16_t)sum;
			std::cout << sum;
		}
	}

};

void Instruction::load(const std::vector<int>& args) {
}