/*
#pragma once

#include <vector>

template<class T>
int medianOfThree(std::vector<T>& array, int left, int right) {
    // implement medianOfThree here
}

template<class T>
int partition(std::vector<T>& array, int left, int right) {
    // implement partition here
}

template<class T>
void sort(std::vector<T>& array) {
    // implement sort here
    // hint: you'll probably want to make a recursive sort_helper function
}
*/

#pragma once

#include <vector>

template<class T>
int medianOfThree(std::vector<T>& array, int left, int right) {
    int middle = (left + right) / 2;

    if (array[left] > array[middle]) {
        std::swap(array[left], array[middle]);
    }
    if (array[left] > array[right]) {
        std::swap(array[left], array[right]);
    }
    if (array[middle] > array[right]) {
        std::swap(array[middle], array[right]);
    }

    return middle;
}

template<class T>
int partition(std::vector<T>& array, int left, int right) {
    int middle = medianOfThree(array, left, right);
    std::swap(array[left], array[middle]);
    T pivot = array[left];
    int up = left + 1;
    int down = right;

    while (up < down) {
        while (up < right && array[up] <= pivot) {
            up++;
        }
        while (array[down] > pivot) {
            down--;
        }
        if (up < down) {
            std::swap(array[up], array[down]);
        }
    }

    std::swap(array[left], array[down]);
    return down;
}

template<class T>
void sort_helper(std::vector<T>& array, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(array, left, right);
        sort_helper(array, left, pivotIndex - 1);
        sort_helper(array, pivotIndex + 1, right);
    }
}

template<class T>
void sort(std::vector<T>& array) {
    if (!array.empty()) {
        sort_helper(array, 0, array.size() - 1);
    }
}
