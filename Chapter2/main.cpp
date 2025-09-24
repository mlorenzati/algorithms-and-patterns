#include "array.h"
#include "console.h"
#include <iostream>

int main()
{
    std::cout << "Define Vector Size: ";
    int n = Console::readInt();
    Array v(n);

    int op;
    do
    {
        std::cout << std::endl << std::endl
            << "Sort Options" << std::endl
            << "0. Generate Array" << std::endl
            << "1. Bubble Sort" << std::endl
            << "2. Selection Sort" << std::endl
            << "3. Insertion Sort" << std::endl
            << "4. Quick Sort" << std::endl
            << "5. Heap Sort" << std::endl
            << "6. Shell Sort" << std::endl
            << "7. Verify if sorted" << std::endl
            << "8. Print Array" << std::endl
            << "9. Exit" << std::endl
            << "Type choice: ";

        op = Console::readInt();
        switch (op)
        {
        case 0:
            std::cout << "Regenarating vector...";
            v.generate();
            std::cout << std::endl
                      << "Vector generated...";
            break;
        case 1:
            std::cout << "Buble Sorting...";
            v.setSorter(Array::BUBBLE);
            v.sort();
            std::cout << std::endl
                      << "Vector sorted...";
            break;
        case 2:
            std::cout << "Selection Sorting...";
            v.setSorter(Array::SELECTION);
            v.sort();
            std::cout << std::endl << "Vector sorted...";
            break;
        case 3:
            std::cout << "Insertion Sorting...";
            v.setSorter(Array::INSERTION);
            v.sort();
            std::cout << std::endl << "Vector sorted...";
            break;
        case 4:
            std::cout << "Quick Sorting...";
            v.setSorter(Array::QUICK);
            v.sort();
            std::cout << std::endl << "Vector sorted...";
            break;
        case 5:
            std::cout << "Heap Sorting...";
            v.setSorter(Array::HEAP);
            v.sort();
            std::cout << std::endl << "Vector sorted...";
            break;
        case 6:
            std::cout << "Shell Sorting...";
            v.setSorter(Array::SHELL);
            v.sort();
            std::cout << std::endl << "Vector sorted...";
            break;
        case 7:
            std::cout << "Verifying if sorted..." << std::endl;
            if (v.verify())
                std::cout << "Is Sorted!..." << std::endl;
            else
                std::cout << "Not Sorted..." << std::endl;
            break;
        case 8:
            std::cout << "Array is " << v.toString() << std::endl;
            break;
        default:
            break;
        }
    } while (op != 9);

    return 0;
}