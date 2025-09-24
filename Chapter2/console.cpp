#include "console.h"

std::string Console::readLine() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

int Console::readInt() {
    int value;
    while (true) {
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Not an integer. Please, trye again!\n";
    }
}