#pragma once
#include <array>
#include <unordered_map>
#include <functional>
#include <string>
#include "Instruction.h"
#include "Parser.h"

// Definition of the Virtual Machine
// VM creates its own Instruction object for set of basic instructions 
// VM creates its own Parser to tokenize input and parse it to its instructions
class VM
{
public:
	Instruction instruction;
	Parser parser;
	std::unordered_map<std::string, std::function<void(VM&, const std::vector<int>&)>> actions;

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
	VM(Instruction instruction, Parser parser);
	void execute(VM vm, std::vector<token> tokens);
};

