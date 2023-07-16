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
    int pos = 0;
    while (true)
    {
        char c = readChar();
        if (c == '\n')
        {
            std::cout << std::endl;
            std::cout.flush();
            break;
        }
        else if (c == '\b' || c == 127)
        {
            if (!line.empty() && pos > 0)
            {
                line.erase(pos - 1, 1);
                std::cout << "\033[D" << line.substr(pos - 1) << " ";
                if (line.size() - pos + 3 > 0)
                    std::cout << "\033[" << line.size() - pos + 2 << "D";
                std::cout.flush();
                pos--;
            }
        }
        else if (c == '\033')
        {
            char next1 = readChar();
            if (next1 == '[')
            {
                char next2 = readChar();
                if (next2 == 'D')
                {
                    if (!line.empty() && pos > 0)
                    {
                        pos--;
                        std::cout << "\033[D";
                        std::cout.flush();
                    }
                }
                else if (next2 == 'C')
                {
                    if (!line.empty() && pos < line.size())
                    {
                        pos++;
                        std::cout << "\033[C";
                        std::cout.flush();
                    }
                }
            }
        }
        else
        {
            line.insert(pos, 1, c);
            pos++;
            std::cout << c << line.substr(pos);
            if (pos < line.size())
                std::cout << "\033[" << line.size() - pos << "D";
            std::cout.flush();
        }
    }
    return line;
}