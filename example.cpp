#include <iostream>
#include "readline.h"

// 设置终端属性为非规范模式
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
        std::cout << "you entered: " << str << std::endl;
    }
    return 0;
}