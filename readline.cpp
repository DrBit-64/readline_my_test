#include "readline.h"

std::string readline()
{
    char ch;
    std::string s{};
    std::cout << "please enter command:";
    while (true)
    {
        std::cin.get(ch);
        if (ch == '\n')
            break;
        s += ch;
    }
    return s;
}