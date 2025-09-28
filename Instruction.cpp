#include "Instruction.h"
#include "VM.h"
#include <iostream>
#include <limits>

Instruction::Instruction() {};

void Instruction::add(VM& vm, const std::vector<std::string>& args) {
	// better use static_cast (replace C-style cast)
	//on what level do i check for the type of the args
	  // when vm gets the args?, when i save them to the args vector or in the function 
	if (args.size() == 2) {
		uint32_t maxVal = std::numeric_limits<uint16_t>::max(); // 65535
		uint32_t sum = static_cast<uint32_t>(vm.regs[args.at(0)]) + static_cast<uint32_t>(vm.regs[args.at(1)]);

		if (sum > maxVal) {
			std::cout << "overflow \n";
		}
		// check overflow
		else {
			vm.regs[args.at(1)] = (uint16_t)sum;
			std::cout << sum;
		}
	}
	// throw exceptio for wrong number of args

};

void Instruction::move(VM& vm, const std::vector<std::string>& args) {
	// accepted args are Rx, Ry or Rx, variable
	// first args is destination, second args is source
	if (args.size() == 2) { // maybe check this in the VM when calling the static method 
		//get destination 
		// between registers
		int src;
		std::string desStr = args.at(0).substr(1);
		int des = std::stoi(desStr);

		if (args.at(1)[0] == 'R') {
		std::string srcStr = args.at(1).substr(1);
		src = std::stoi(srcStr);
		}
		else{
			int des = (args.at(0))[2];
			uint16_t source = std::stoul(args.at(1));
		}
		
		vm.regs[des] = vm.regs[src]; //num 0-16 -> R0-R16

		
		// RAM -> register 
		//int des = (args.at(0))[2];
		//uint16_t source = std::stoul(args.at(3));
		//vm.regs[des] = vm.regs[source];

		// register -> RAM
	}
}

void Instruction::load(VM& vm, const std::vector<int>& args) {
}