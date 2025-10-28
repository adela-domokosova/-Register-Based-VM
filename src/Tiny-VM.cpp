#include <iostream>
#include "VM.h"
#include "Instruction.h"
#include "Lexer.h"

int main()
{
    Lexer lex = Lexer();
    VM vm = VM();

    while (true) {
        std::string x;
        std::cout << "user@VM : ";
        std::getline(std::cin, x);

        std::vector<token> vec = lex.tokenizer(x);
        for (auto& t : vec) {
            std::cout << "token" << "\n";
            std::cout << t.type << "\n";
            std::cout << t.number << "\n";
            std::cout << t.string << "\n";
            std::cout << t.character << "\n";
        }

    
    }
}


