#ifndef SEARCHER_H
#define SEARCHER_H

#include <list>
#include <vector>
#include <string>
#include <algorithm>

class Searcher {
public:
    Searcher();
    void setArraySize(int n = 100);
    void shuffle();
    void generate();
    bool isSorted();
    int  find(int value, int &iterations);
    std::string arrayToString();

private:
    std::vector<int> array;
};

#endif