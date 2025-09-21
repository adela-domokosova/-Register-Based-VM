#pragma once
#include <iostream>
#include <cstdint>
#include <limits>

enum class OpCode { ADD, LOAD, MOVE, STORE };

class Instruction
{
	OpCode op;

	Instruction();
	// Operations
	void move();
	void load(); // from RAM addres to register
	void store(); // from register to RAM
	void add(VM& vm, int regs1, int regs2);
};

