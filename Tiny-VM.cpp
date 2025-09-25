#include <iostream>
#include "VM.h"

int main()
{
    VM vm = VM();

    while (true) {
        std::string x;
        std::cout << "user@VM : ";
        std::cin >> x;


        vm.execute(vm , vm.parser.parse(x)); // returns whats needed to execute in vm


    
    }
}


