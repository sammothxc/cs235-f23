/*
#pragma once

#include <iostream>
#include <string>

template<class T>
class DLList {
public:
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };

    DLList() {}

    ~DLList() {}

    const Node* get_head() const {
        // implement get_head here
    }

    void push_front(T item) {
        // implement push_front here
    }
    void push_back(T item) {
        // implement push_back here
    }
    void insert(T item, int position) {
        // implement insert here
    }

    void pop_front() {
        // implement pop_front here
    }
    void pop_back() {
        // implement pop_back here
    }
    void remove(int position) {
        // implement remove here
    }

    const T& front() const {
        // implement front here
    }
    const T& back() const {
        // implement back here
    }
    const T& at(int index) const {
        // implement at here
    }

    bool contains(const T& item) const {
        // implement contains here
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
class DLList {
public:
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };

    Node* head;
    Node* tail;
    int listSize;

    DLList() : head(nullptr), tail(nullptr), listSize(0) {}

    ~DLList() {
        clear();
    }

    const Node* get_head() const {
        return head;
    }

    void push_front(T item) {
        Node* newNode = new Node(item);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        listSize++;
    }

    void push_back(T item) {
        Node* newNode = new Node(item);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        listSize++;
    }

    void insert(T item, int position) {
        if (position < 0 || position > listSize) {
            throw std::out_of_range("Index out of range");
        }
        if (position == 0) {
            push_front(item);
        }
        else if (position == listSize) {
            push_back(item);
        }
        else {
            Node* current = head;
            for (int i = 0; i < position; i++) {
                current = current->next;
            }
            Node* newNode = new Node(item);
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;
            listSize++;
        }
    }

    void pop_front() {
        if (head == nullptr) {
            throw std::length_error("List is empty");
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
        listSize--;
    }

    void pop_back() {
        if (tail == nullptr) {
            throw std::length_error("List is empty");
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        delete temp;
        listSize--;
    }

    void remove(int position) {
        if (position < 0 || position >= listSize) {
            throw std::out_of_range("Index out of range");
        }
        if (position == 0) {
            pop_front();
        }
        else if (position == listSize - 1) {
            pop_back();
        }
        else {
            Node* current = head;
            for (int i = 0; i < position; i++) {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            listSize--;
        }
    }

    const T& front() const {
        if (head == nullptr) {
            throw std::length_error("List is empty");
        }
        return head->value;
    }

    const T& back() const {
        if (tail == nullptr) {
            throw std::length_error("List is empty");
        }
        return tail->value;
    }

    const T& at(int index) const {
        if (index < 0 || index >= listSize) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }

    bool contains(const T& item) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->value == item) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int size() const {
        return listSize;
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        listSize = 0;
    }
};
