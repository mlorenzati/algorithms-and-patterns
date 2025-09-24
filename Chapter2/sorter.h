#ifndef SORTER_H
#define SORTER_H

#include "sortable.h"
#include "array.h"

// ---- Sorting Strategies ----
class Array::BubbleSort : public Sortable {
    std::vector<int>& v;
public:
    BubbleSort(std::vector<int>& vec) : v(vec) {}
    void sort() override {
        bool sorted = false;
        int n = v.size();
        for (int i = 0; i < n - 1 && !sorted; i++) {
            sorted = true;
            for (int j = 0; j < n - i - 1; j++) {
                if (v[j] > v[j + 1]) {
                    std::swap(v[j], v[j + 1]);
                    sorted = false;
                }
            }
        }
    }
};

class Array::SelectionSort : public Sortable {
    std::vector<int>& v;
public:
    SelectionSort(std::vector<int>& vec) : v(vec) {}
    void sort() override {
        int n = v.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (v[i] > v[j]) {
                    std::swap(v[i], v[j]);
                }
            }
        }
    }
};

class Array::InsertionSort : public Sortable {
    std::vector<int>& v;
public:
    InsertionSort(std::vector<int>& vec) : v(vec) {}
    void sort() override {
        int n = v.size();
        for (int j = 1; j < n; j++) {
            int key = v[j];
            int k = j - 1;
            while (k >= 0 && key < v[k]) {
                v[k + 1] = v[k];
                k--;
            }
            v[k + 1] = key;
        }
    }
};

class Array::QuickSort : public Sortable {
    std::vector<int>& v;
public:
    QuickSort(std::vector<int>& vec) : v(vec) {}

    void sort() override {
        quickSort(0, v.size() - 1);
    }

private:
    void quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    int partition(int low, int high) {
        int pivot = v[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (v[j] <= pivot) {
                i++;
                std::swap(v[i], v[j]);
            }
        }
        std::swap(v[i + 1], v[high]);
        return i + 1;
    }
};

class Array::HeapSort : public Sortable {
    std::vector<int>& v;
public:
    HeapSort(std::vector<int>& vec) : v(vec) {}

    void sort() override {
        std::make_heap(v.begin(), v.end());
        std::sort_heap(v.begin(), v.end());
    }
};

class Array::ShellSort : public Sortable {
    std::vector<int>& v;
public:
    ShellSort(std::vector<int>& vec) : v(vec) {}

    void sort() override {
        int n = v.size();
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = v[i];
                int j;
                for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                    v[j] = v[j - gap];
                }
                v[j] = temp;
            }
        }
    }
};

#endif