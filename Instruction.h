#pragma once
#include <iostream>
#include <cstdint>
#include <limits>
#include <vector>

class Instruction
{

public:
	Instruction(VM& vm);
	// Operations
	void move(const std::vector<int>& args);
	void load(const std::vector<int>& args); // from RAM addres to register
	void store(const std::vector<int>& args); // from register to RAM
	void add(const std::vector<int>& args);
};

