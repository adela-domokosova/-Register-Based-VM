#pragma once
#include <iostream>
#include <cstdint>
#include <limits>
#include <vector>


class VM;

class Instruction
{

public:
	Instruction();
	// Operations
	static void move(VM& vm, const std::vector<std::string>& args); // from registre to other register
	static void load(VM& vm, const std::vector<int>& args); // from RAM addres to register
	static void store(VM& vm, const std::vector<int>& args); // from register to RAM
	static void add(VM& vm, const std::vector<std::string>& args);
	static void print(VM& vm, const std::vector<std::string>& args);
};

