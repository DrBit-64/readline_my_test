#include <iostream>
#include "readline.h"

int main()
{
    while (true)
    {
        std::string str = readline();
        std::cout << "you entered: " << str << std::endl;
    }
    return 0;
}