#pragma once
#include <array>
#include "Instruction.h"
// Definition of the Virtual MAchine
class VM
{
public:
	std::array<uint16_t, 16> regs; // R0-R15
	std::uint16_t pc; // program counter
	std::uint16_t sp; // stack pointer
	std::uint8_t flags; // Z, C, O, N

	static constexpr size_t RAM_SIZE = 256;
	std::array<uint16_t, RAM_SIZE> ram{};

public:
	// Constructor
	VM();
	void execute(const Instruction& instr);
};

