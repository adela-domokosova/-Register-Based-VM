#include "Instruction.h"
void Instruction::add(VM& vm, int reg1, int reg2) {
	uint32_t maxVal = std::numeric_limits<uint16_t>::max(); // 65535
	uint32_t sum = (uint32_t)vm.regs[reg1] + (uint32_t)regs[reg2];

	if (sum > maxVal) {
		std::cout << "overflow \n";
	}
	else {
		regs[reg1] = (uint16_t)sum;
		std::cout << sum;
	}
};