#ifndef ALGORITHM_H
#define ALGORITHM_H

namespace Algorithm {
    int recursiveFactorial(int n) {
        if( n == 0 ) return 1;
        return n * recursiveFactorial( n - 1 );
    }
    
    int iterativeFactorial(int n) {
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }
    
    int recursiveFibonacci(int n) {
        if (n <= 1) return 1;
        return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
    }
    
    int iterativeFibonacci(int n) {
        int ant2 = 1;
        int ant1 = 1;
        for (int i = 2; i <= n; i++) 
        {
            int aux = ant1 + ant2;
            ant2 = ant1;
            ant1 = aux;
        }
        return ant1;
    }
};

#endif