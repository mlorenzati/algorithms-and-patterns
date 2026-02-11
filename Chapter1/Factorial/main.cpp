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
    
    int stackCount = 0;
    int spatialComplexity = 0;
    int temporalComplexity = 0;

    int f1 = recursiveFactorial(n, stackCount, spatialComplexity, temporalComplexity);
    std::cout << "Stack in zero? " << stackCount << std::endl;
    std::cout << "The factorial spatial complexity is  " << spatialComplexity << std::endl;
    std::cout << "The factorial temporal complexity is  " << temporalComplexity << std::endl;
    std::cout << "The factorial of " << n << " (recursive) is: " << f1 << std::endl;

    int f2 = iterativeFactorial(n);
    std::cout << "The factorial of " << n << " (iterative) is: " << f1 << std::endl;

    stackCount = 0;
    spatialComplexity = 0;
    temporalComplexity = 0;

    int fb1 = recursiveFibonacci(n, stackCount, spatialComplexity, temporalComplexity);
    std::cout << "Stack in zero? " << stackCount << std::endl;
    std::cout << "The Fibonacci spatial complexity is  " << spatialComplexity << std::endl;
    std::cout << "The Fibonacci temporal complexity is  " << temporalComplexity << std::endl;
    std::cout << "The Fibonacci of " << n << " (recursive) is: " << fb1 << std::endl;
    
    int fb2 = iterativeFibonacci(n);
    std::cout << "The Fibonacci of " << n << " (iterative) is: " << fb2 << std::endl;
    return 0;
}
