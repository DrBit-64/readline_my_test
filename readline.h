#ifndef READLINE_H
#define READLINE_H

#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <unordered_map>
#include <map>

#endif

const std::unordered_map<std::string, int> color2idx = {
    {"red", 31},
    {"green", 32},
    {"yellow", 33},
    {"blue", 34},
    {"magenta", 35},
    {"cyan", 36},
    {"white", 37},
    {"dark gray", 30},
    {"light red", 31},
    {"light green", 32},
    {"light yellow", 33},
    {"light blue", 34},
    {"light magenta", 35},
    {"light cyan", 36},
    {"light gray", 37},
};

std::string readline(const std::string &prompt);
void print_color_list();