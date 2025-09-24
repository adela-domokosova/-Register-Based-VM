#pragma once
#include <array>
#include <unordered_map>
#include <functional>
#include "Instruction.h"
// Definition of the Virtual MAchine
class VM
{
public:
	Instruction instruction;
	std::unordered_map<std::string, std::function<void()>> actions;

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
	VM(Instruction instr);
	void execute(Instruction instr);
};

