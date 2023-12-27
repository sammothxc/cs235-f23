/*
#pragma once

#include <iostream>
#include <string>

template<class T>
class Vector {
public:
    Vector() {}

    ~Vector() {}

    void push_back(T item) {
        // implement push_back here
    }

    void insert(T item, int position) {
        // implement insert here
    }

    void remove(int position) {
        // implement remove here
    }

    T& operator[](int index) {
        // implement operator[] here
    }

    int size() const {
        // implement size here
    }

    void clear() {
        // implement clear here
    }
};
*/

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

template<class T>
class Vector {
public:
    Vector() {
        capacity_ = 10;
        size_ = 0;
        data = new T[capacity_];
    }

    ~Vector() {
        delete[] data;
    }

    void push_back(T item) {
        if (size_ == capacity_) {
            resize();
        }
        data[size_++] = item;
    }

    void insert(T item, int position) {
        if (position < 0 || position > size_) {
            throw std::out_of_range("Index out of range");
        }

        if (size_ == capacity_) {
            resize();
        }

        for (int i = size_; i > position; --i) {
            data[i] = data[i - 1];
        }

        data[position] = item;
        size_++;
    }

    void remove(int position) {
        if (position < 0 || position >= size_) {
            throw std::out_of_range("Index out of range");
        }

        for (int i = position; i < size_ - 1; ++i) {
            data[i] = data[i + 1];
        }

        size_--;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    int size() const {
        return size_;
    }

    void clear() {
        size_ = 0;
    }

private:
    T* data;
    int capacity_;
    int size_;

    void resize() {
        capacity_ *= 2;
        T* new_data = new T[capacity_];
        for (int i = 0; i < size_; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
};
