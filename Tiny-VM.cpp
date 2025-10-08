#include <iostream>
#include "VM.h"
#include "Instruction.h"

int main()
{
    char ai = 'a';
    uint16_t num = 'a';
    std::cout << std::to_string(num);

    VM vm = VM();

    while (true) {
        std::string x;
        std::cout << "user@VM : ";
        std::getline(std::cin, x);


        vm.execute(vm.parser.parse(x)); // returns whats needed to execute in vm


    
    }
}


