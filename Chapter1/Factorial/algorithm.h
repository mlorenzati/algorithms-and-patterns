#ifndef ALGORITHM_H
#define ALGORITHM_H

namespace Algorithm {
    int recursiveFactorial(int n, int &stackCount, int &spatialComplexity, int &temporalComplexity) {
        stackCount++;
        temporalComplexity++;
        spatialComplexity = stackCount > spatialComplexity ? stackCount : spatialComplexity;

        if( n == 0 ) return 1;
        return n * recursiveFactorial(n - 1, stackCount, spatialComplexity, temporalComplexity);
    }
    
    int iterativeFactorial(int n) {
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }
    
    int recursiveFibonacci(int n, int &stackCount, int &spatialComplexity, int &temporalComplexity) {
        stackCount++;
        temporalComplexity++;
        spatialComplexity = stackCount > spatialComplexity ? stackCount : spatialComplexity;

        if (n <= 1) {
            stackCount--;
            return 1;
        }
        int val = recursiveFibonacci(n - 1, stackCount, spatialComplexity, temporalComplexity) + recursiveFibonacci(n - 2, stackCount, spatialComplexity, temporalComplexity);
        stackCount--;
        return val;
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