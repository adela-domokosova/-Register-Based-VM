#pragma once
#include <iostream>
#include <cstdint>
#include <limits>
#include <vector>
#include "VM.h"

class Instruction
{

public:
	Instruction();
	// Operations
	void move(VM& vm, const std::vector<int>& args);
	void load(VM& vm, const std::vector<int>& args); // from RAM addres to register
	void store(VM& vm, const std::vector<int>& args); // from register to RAM
	void add(VM& vm, const std::vector<int>& args);
};

