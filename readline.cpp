#include <iostream>
#include <ncurses.h>
int main()
{
    initscr();
    char ch;
    while (true)
    {
        ch = getch();
        std::cout << "You entered: " << ch << std::endl;
        if (ch == 'q')
        {
            break;
        }
    }
    return 0;
}