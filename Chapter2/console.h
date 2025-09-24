#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include <string>
#include <limits>


class Console {
public:
    static std::string readLine();
    static int readInt();
};
#endif