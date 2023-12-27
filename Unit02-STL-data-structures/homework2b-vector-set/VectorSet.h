#pragma once
#include <vector>

template<class T>
class VectorSet {

private:
    std::vector<T> elements;

public:
    bool contains(T item) const {
        // implement contains here
        for (const T& element : elements) {
            if (element == item) {
                return true;
            }
        }
        return false;
        // return true if item is in the set and false if not
    }

    bool insert(T item) {
        // implement insert here
        if (!contains(item)) {
            elements.push_back(item);
            return true;
        }
        return false;
        // return true if item is inserted and false if item is already in the
        // set
    }

    bool remove(T item) {
        // implement remove here
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (*it == item) {
                elements.erase(it);
                return true;
            }
        }
        return false;
        // return true if item is removed and false if item wasn't in the set
    }

    int size() const {
        // implement size here
        return elements.size();
        // return the number of items in the set
    }

    bool empty() const {
        // implement empty here
        return elements.empty();
        // return true if the set is empty and return false otherwise
    }

    void clear() {
        // implement clear here
        return elements.clear();
        // remove all items from the set
    }
};
