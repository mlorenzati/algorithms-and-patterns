#include "array.h"

#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include "sorter.h"

Array::Array(int n) {
    if (n <= 0) n = 100;
    v.resize(n);
    sorter = std::make_unique<QuickSort>(v);
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Array::generate() {
    int arraySize = v.size();
    // Add sequential unique numbers
    for (int i = 0; i < arraySize; i++) {
        v[i] = i;
    }
    // And shufle it
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::shuffle(v.begin(), v.end(), gen);
}

bool Array::verify() const {
    for (size_t i = 0; i < v.size() - 1; i++) {
        if (v[i] > v[i + 1]) return false;
    }
    return true;
}

void Array::setSorter(Method method) {
    switch (method) {
        case BUBBLE:    sorter = std::make_unique<BubbleSort>(v); break;
        case SELECTION: sorter = std::make_unique<SelectionSort>(v); break;
        case INSERTION: sorter = std::make_unique<InsertionSort>(v); break;
        case QUICK:     sorter = std::make_unique<QuickSort>(v); break;
        case HEAP:      sorter = std::make_unique<HeapSort>(v); break;
        case SHELL:     sorter = std::make_unique<ShellSort>(v); break;
    }
}

void Array::sort() {
    if (sorter) sorter->sort();
}

std::string Array::toString() {
    std::string res = "[ ";
    bool isFirst = true;
    for (auto& x : v) {
        if (!isFirst) {
            res += ", ";
        }
        res += std::to_string(x);
        isFirst = false;
    }

    res += " ]";
    return res;
}