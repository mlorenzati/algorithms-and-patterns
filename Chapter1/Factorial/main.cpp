#include "algorithm.h"
#include "console.h"
#include <iostream>

using namespace Algorithm;

int main(void)
{
    int n;
    do
    {
        std::cout << "Type n (non negative): " << std::endl;
        n = Console::readInt();
        if( n < 0 ) {
            std::cout << "Non negative, please try again" << std::endl;
        }
    }
    while(n < 0);
    
    int f1 = recursiveFactorial(n);
    std::cout << "The  factorial of " << n << " (recursive) is: " << f1 << std::endl;

    int f2 = iterativeFactorial(n);
    std::cout << "The  factorial of " << n << " (recursive) is: " << f1 << std::endl;

    int fb1 = recursiveFibonacci(n);
    std::cout << "The Fibonacci of " << n << " (recursive) is: " << fb1 << std::endl;
    
    int fb2 = iterativeFibonacci(n);
    std::cout << "The Fibonacci of " << n << " (iterative) is: " << fb2 << std::endl;
    return 0;
}
