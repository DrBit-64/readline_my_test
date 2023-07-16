#include "readline.h"

char readChar()
{
    char c;
    read(STDIN_FILENO, &c, 1);
    return c;
}

std::string readline(const std::string &prompt)
{
    std::cout << prompt;
    std::cout.flush();
    std::string line;
    while (true)
    {
        char c = readChar();
        switch (c)
        {
        case '\n':
            std::cout << std::endl;
            return line;
        case 127:
        case '\b':
            if (!line.empty())
            {
                line.pop_back();
                std::cout << "\b \b";
                std::cout.flush();
            }
            break;
        case '\033':
        { // 处理方向键
            char next1 = readChar();
            if (next1 == '[')
            {
                char next2 = readChar();
                if (next2 == 'C')
                { // 向右移动
                    if (!line.empty())
                    {
                        std::cout << "\033[C";
                        std::cout.flush();
                    }
                }
                else if (next2 == 'D')
                { // 向左移动
                    if (!line.empty())
                    {
                        std::cout << "\033[D";
                        std::cout.flush();
                    }
                }
            }
            break;
        }
        default:
            line += c;
            std::cout << c;
            std::cout.flush();
        }
    }
}