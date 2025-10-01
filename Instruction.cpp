#include "Instruction.h"
#include "VM.h"
#include <iostream>
#include <limits>

Instruction::Instruction() {};

void Instruction::add(VM& vm, const std::vector<std::string>& args) {
	// better use static_cast (replace C-style cast)
	//on what level do i check for the type of the args
	  // when vm gets the args?, when i save them to the args vector or in the function 

	//need to get the number of the register
	std::string one = args.at(0).substr(1);
	int r_one = std::stoi(one);
	std::string two = args.at(1).substr(1);
	int r_two = std::stoi(two);


	if (args.size() == 2) {
		uint32_t maxVal = std::numeric_limits<uint16_t>::max(); // 65535
		uint32_t sum = static_cast<uint32_t>(vm.regs[r_one]) + static_cast<uint32_t>(vm.regs[r_two]);

		if (sum > maxVal) {
			std::cout << "overflow \n";
		}
		// check overflow
		else {
			vm.regs[r_one] = (uint16_t)sum;
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
			vm.regs[des] = vm.regs[src];
		}
		else {
			uint16_t source = std::stoul(args.at(1));
			vm.regs[des] = source; //num 0-16 -> R0-R16

		}
	}
}

void Instruction::print(VM& vm, const std::vector<std::string>& args) {
	// print value from register
	int num;
	//check that i only have one argument
	if (!(args.size() == 1)) {
		std::cout << "Wrong number of arguments.\n";
		return;
	}

	if (args.at(0)[0] == 'R') {
		//static_cast vs stoi?

		std::string a = args.at(0).substr(1);
		//check that a is a number and can be converted
		num = std::stoi(a);
		std::cout << vm.regs[num] << "\n";
		return;
	}
	else if (args.at(0).rfind("ram", 0) == 0) {
		std::string a = args.at(0).substr(3);
		//check that a is a number and can be converted
		num = std::stoi(a);
		std::cout << vm.ram[num] << "\n";
	}
	else {
		std::cout << "Parameter not recongised";
	}
}

//from RAM to register
//check ram size before loading
void Instruction::load(VM& vm, const std::vector<std::string>& args) {
	//eg: load R ram; -> patern destination -> source
	int des;
	int src;
	if (args.size() == 2) {
		if (args.at(1).rfind("ram", 0) == 0 && args.at(0)[0] == 'R') {
		std::string a = args.at(0).substr(1);
		des = std::stoi(a); //check it is a number
		std::string b = args.at(1).substr(3);
		src = std::stoi(b); //check it is a number
		uint16_t num = vm.ram[src];
		vm.regs[des] = num;
		}
	}

}

//from register to RAM
// need to check ram size before storing
void Instruction::store(VM& vm, const std::vector<std::string>& args) {
	//eg: store ram R;
	int des;
	int src;
	if (args.size() == 2) {
		if (args.at(0).rfind("ram", 0) == 0 && args.at(1)[0] == 'R') {
			std::string a = args.at(0).substr(3);
			des = std::stoi(a);
			std::string b = args.at(1).substr(1);
			src = std::stoi(b);
			uint16_t num = vm.regs[src];
			vm.ram[des] = num;
		}
	}
}