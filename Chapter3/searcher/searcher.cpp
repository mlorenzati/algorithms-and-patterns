#include "searcher.h"
#include <random>
#include <cstdlib>
#include <ctime>
#include <iostream>

Searcher::Searcher() {
    array.resize(100);
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    srand(time(0));
    generate();
}

void Searcher::setArraySize(int n) {
    array.resize(100);
    generate();
}

void Searcher::generate() {
    int counter = 0;
    // Generates unique numbers, sorted
    for (auto &item: array) {
        item = counter;
        int rangedNumber = (rand() % 10) + 1; 
        counter += rangedNumber;
    }
}

void Searcher::shuffle() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::vector<int> tmp(array.begin(), array.end());
    std::shuffle(array.begin(), array.end(), gen);
}

bool Searcher::isSorted() {
    int previous = -1;
    for (auto &item: array) {
        if (item < previous) {
            return false;
        }
        previous = item;
    }
    return true;
}

int Searcher::find(int value, int &iterations) {
    if (isSorted()) {
        std::cout << "Sorted array, using binary search" << std::endl;
        int low = 0;
        int high = static_cast<int>(array.size()) - 1;
        iterations = 0;

        while (low <= high) {
            iterations++;
            int mid = low + (high - low) / 2;

            if (array[mid] == value)
                return mid;  // Found!
            else if (array[mid] < value)
                low = mid + 1;
            else
                high = mid - 1;
        }
    } else {
        std::cout << "Unsorted array, using sequential search" << std::endl;
        iterations = 0;
        for (auto &item: array) {
            iterations++;
            if (item == value) {
                return iterations - 1; // Found!
            }
        }
    }
    return -1;
}

std::string Searcher::arrayToString() {
    std::string res = "[ ";
    bool isFirst = true;
    for (auto& x : array) {
        if (!isFirst) {
            res += ", ";
        }
        res += std::to_string(x);
        isFirst = false;
    }

    res += " ]";
    return res;
}