/*
#pragma once

template<class T>
class HashSet {
public:
    HashSet() {}

    ~HashSet() {}

    bool insert(T item) {
        // implement insert here
        // return true if item was inserted, false if item was already in the set
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the set
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the set, false otherwise
    }

    void clear() {
        // implement clear here
        // remove all elements from the set
    }

    int size() const {
        // implement size here
        // return the number of elements in the set
    }
};
*/

#pragma once

#include <vector>
#include <list>
#include <algorithm>

template<class T>
class HashSet {
private:
    static const size_t INITIAL_BUCKET_COUNT = 10;
    static const double LOAD_FACTOR_THRESHOLD;

    std::vector<std::list<T>> buckets;

    size_t hashFunction(const T& item) const {
        return std::hash<T>{}(item) % buckets.size();
    }

public:
    HashSet() : buckets(INITIAL_BUCKET_COUNT) {}

    ~HashSet() {}

    bool insert(T item) {
        size_t index = hashFunction(item);
        auto& bucket = buckets[index];

        if (std::find(bucket.begin(), bucket.end(), item) == bucket.end()) {
            // Element not found, insert it
            bucket.push_back(item);
            return true;
        }

        // Element already exists
        return false;
    }

    bool remove(T item) {
        size_t index = hashFunction(item);
        auto& bucket = buckets[index];

        auto it = std::find(bucket.begin(), bucket.end(), item);

        if (it != bucket.end()) {
            // Element found, remove it
            bucket.erase(it);
            return true;
        }

        // Element not found
        return false;
    }

    bool contains(T item) const {
        size_t index = hashFunction(item);
        const auto& bucket = buckets[index];

        return std::find(bucket.begin(), bucket.end(), item) != bucket.end();
    }

    void clear() {
        buckets.clear();
        buckets.resize(INITIAL_BUCKET_COUNT);
    }

    int size() const {
        int count = 0;
        for (const auto& bucket : buckets) {
            count += static_cast<int>(bucket.size());
        }
        return count;
    }
};

template<class T>
const double HashSet<T>::LOAD_FACTOR_THRESHOLD = 0.75;
