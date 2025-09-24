#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <memory>
#include "sortable.h"

class Array {
public:
    enum Method { BUBBLE, SELECTION, INSERTION, QUICK, HEAP, SHELL };

    explicit Array(int n = 100);

    void generate();
    bool verify() const;
    void setSorter(Method method);
    void sort();
    std::string toString();

private:
    std::vector<int> v;
    std::unique_ptr<Sortable> sorter;

    class BubbleSort;
    class SelectionSort;
    class InsertionSort;
    class QuickSort;
    class HeapSort;
    class ShellSort;
};

#endif