#include <iostream>
#include "VM.h"
#include "Instruction.h"

int main()
{
    VM vm = VM();

    while (true) {
        std::string x;
        std::cout << "user@VM : ";
        std::cin >> x;


        vm.execute(vm.parser.parse(x)); // returns whats needed to execute in vm


    
    }
}


