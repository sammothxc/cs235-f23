/*
#pragma once

template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
    };

    SLList() {}

    ~SLList() {}

    const Node* get_head() const {
        // implement get_head here
    }

    void push_back(T item) {
        // implement push_back here
    }

    void pop_back() {
        // implement pop_back here
    }

    const T& front() const {
        // implement front here
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

template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
    };

    SLList() : head(nullptr), listSize(0) {}

    ~SLList() {
        clear();
    }

    const Node* get_head() const {
        return head;
    }

    void push_back(T item) {
        Node* newNode = new Node(item);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        listSize++;
    }

    void pop_back() {
        if (listSize == 1) {
            delete head;
            head = nullptr;
        } else {
            Node* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
        listSize--;
    }

    const T& front() const {
        return head->value;
    }

    int size() const {
        return listSize;
    }

    void clear() {
        while (head != nullptr) {
            Node* current = head;
            head = head->next;
            delete current;
        }
        listSize = 0;
    }

private:
    Node* head;
    int listSize;
};
