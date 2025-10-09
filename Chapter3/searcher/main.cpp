#include "console.h"
#include "searcher.h"
#include <iostream>

int main()
{
    Searcher searcher;
    int opt;

    std::cout << "Search patterns" << std::endl;
    
    do {
        std::cout << "\nSelect option"   << std::endl
        << "0. Set Array Size" << std::endl
        << "1. Is Sorted" << std::endl
        << "2. Shuffle" << std::endl
        << "3. Find" << std::endl
        << "4. Print array" << std::endl
        << "5. Exit" << std::endl
        << "Type choice: ";

        opt = Console::readInt();
        switch (opt) {
            case 0: {
                    std::cout << "New size?: ";
                    int size = Console::readInt();
                    searcher.setArraySize(size);
                }
                break;
            case 1:
                std::cout << "Array is " << (searcher.isSorted() ? "sorted" : "not sorted") << std::endl;
                break;
            case 2:
                searcher.shuffle();
                std::cout << "Array shuffled" << std::endl;
                break;
            case 3: {
                    std::cout << "Enter valuet to find:";
                    int value = Console::readInt();
                    int iterations;
                    int position = searcher.find(value, iterations);
                    if (position > 0) {
                        std::cout << "Value found at " << position << " in " << iterations << " iterations";
                    } else {
                        std::cout << "Value " << value << " not found" << std::endl;
                    }
                }
                break;
            case 4:
                std::cout << searcher.arrayToString() << std::endl;
                break;
            default: break;
        };
    } while (opt != 5);

    std::cout << "Exiting"  << std::endl;
    return 0;
}