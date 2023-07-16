#include "readline.h"

void setNoncanonicalMode()
{
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

int main()
{
    setNoncanonicalMode();
    while (true)
    {
        std::string str = readline("please enter command: ");
        if (str.substr(0, 6) == "/color")
        {
            if (str.size() <= 7)
            {
                print_color_list();
            }
            else
            {
                std::string color = str.substr(7);
                auto idx = color2idx.find(color);
                if (color == "reset")
                {
                    std::cout << "\033[0m";
                }
                else if (idx == color2idx.end())
                {
                    std::cout << "unavailable color!" << std::endl;
                }
                else
                {
                    std::cout << "\033[1;" << idx->second << "m";
                }
            }
        }
        else if (str == "/exit")
        {
            break;
        }
        else
        {
            std::cout << "you entered: " << str << std::endl;
        }
    }
    return 0;
}