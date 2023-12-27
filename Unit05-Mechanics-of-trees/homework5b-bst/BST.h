/* #pragma once

template<class T>
class BST {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {}
    };

    BST() {
        // implement the contructor here
    }

    ~BST() {
        // implement the destructor here
    }

    const Node* getRootNode() const {
        // implement getRootNode here
        // return a pointer to the tree's root node
    }

    bool insert(T item) {
        // implement insert here
        // return true if item was inserted, false if item was already in the tree
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the tree
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the tree, false otherwise
    }

    void clear() {
        // implement clear here
        // remove all nodes from the tree
    }

    int size() const {
        // implement size here
        // return the number of nodes in the tree
    }
};
*/

#pragma once

template<class T>
class BST {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {}
    };

    BST() : root(nullptr) {}

    ~BST() {
        clear();
    }

    const Node* getRootNode() const {
        return root;
    }

    bool insert(T item) {
        return insert(root, item);
    }

    bool remove(T item) {
        return remove(root, item);
    }

    bool contains(T item) const {
        return contains(root, item);
    }

    void clear() {
        clear(root);
        treeSize = 0;
    }

    int size() const {
        return treeSize;
    }

private:
    Node* root;
    int treeSize;

    bool insert(Node*& current, T item) {
        if (!current) {
            current = new Node(item);
            treeSize++;
            return true;
        }

        if (item < current->value) {
            return insert(current->left, item);
        } else if (item > current->value) {
            return insert(current->right, item);
        } else {
            return false;
        }
    }

/*  error when removal of a node that has two children and where the left child has a right subtree
    bool remove(Node*& current, T item) {
        if (!current) {
            return false;
        }

        if (item < current->value) {
            return remove(current->left, item);
        } else if (item > current->value) {
            return remove(current->right, item);
        } else {
            if (!current->left) {
                Node* temp = current->right;
                delete current;
                current = temp;
            } else if (!current->right) {
                Node* temp = current->left;
                delete current;
                current = temp;
            } else {
                Node* temp = current->right;
                while (temp->left) {
                    temp = temp->left;
                }
                current->value = temp->value;
                remove(current->right, temp->value);
            }

            treeSize--;
            return true;
        }
    }
*/

bool remove(Node*& current, T item) {
    if (!current) {
        return false; // Item not found
    }

    if (item < current->value) {
        return remove(current->left, item);
    } else if (item > current->value) {
        return remove(current->right, item);
    } else {
        // Item found, remove the node
        if (!current->left) {
            Node* temp = current->right;
            delete current;
            current = temp;
        } else if (!current->right) {
            Node* temp = current->left;
            delete current;
            current = temp;
        } else {
            // Node has two children
            Node* temp = findMax(current->left); // Find the max node in the left subtree
            current->value = temp->value;
            remove(current->left, temp->value);
        }

        treeSize--;
        return true;
    }
}

Node* findMax(Node* current) {
    while (current->right) {
        current = current->right;
    }
    return current;
}

    bool contains(Node* current, T item) const {
        if (!current) {
            return false;
        }

        if (item < current->value) {
            return contains(current->left, item);
        } else if (item > current->value) {
            return contains(current->right, item);
        } else {
            return true;
        }
    }

    void clear(Node*& current) {
        if (current) {
            clear(current->left);
            clear(current->right);
            delete current;
            current = nullptr;
        }
}};
