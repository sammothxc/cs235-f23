/*
#pragma once

template<class T>
class AVL {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;
        int height;

        Node(T v) : left(nullptr), right(nullptr), value(v), height(1) {}
    };

    AVL() {
        // implement the contructor here
    }

    ~AVL() {
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
class AVL {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;
        int height;

        Node(T v) : left(nullptr), right(nullptr), value(v), height(1) {}
    };

    AVL() : root(nullptr) {}

    ~AVL() {
        clear();
    }

    const Node* getRootNode() const {
        return root;
    }

    bool insert(T item) {
        int initialSize = size();
        root = insertNode(root, item);
        return size() > initialSize;
    }

    bool remove(T item) {
        int initialSize = size();
        root = removeNode(root, item);
        return size() < initialSize;
    }

    bool contains(T item) const {
        return containsNode(root, item);
    }

    void clear() {
        clearNodes(root);
        root = nullptr;
    }

    int size() const {
        return getSize(root);
    }

private:
    Node* root;

    int getHeight(Node* node) const {
        return (node == nullptr) ? 0 : node->height;
    }

    int getBalanceFactor(Node* node) const {
        return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* insertNode(Node* node, T item) {
        if (node == nullptr) {
            return new Node(item);
        }

        if (item < node->value) {
            node->left = insertNode(node->left, item);
        } else if (item > node->value) {
            node->right = insertNode(node->right, item);
        } else {
            return node; // Duplicate items not allowed
        }

        // Update height of current node
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        // Perform rebalance
        return rebalance(node);
    }

    Node* rebalance(Node* node) {
        int balance = getBalanceFactor(node);

        // Left Heavy
        if (balance > 1) {
            if (getBalanceFactor(node->left) >= 0) {
                return rotateRight(node);
            } else {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        // Right Heavy
        if (balance < -1) {
            if (getBalanceFactor(node->right) <= 0) {
                return rotateLeft(node);
            } else {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    Node* findMin(Node* node) const {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

Node* removeNode(Node* node, T item) {
    if (node == nullptr)
        return nullptr;

    if (item < node->value) {
        node->left = removeNode(node->left, item);
    } else if (item > node->value) {
        node->right = removeNode(node->right, item);
    } else {
        // Node with only one child or no child
        if (node->left == nullptr || node->right == nullptr) {
            Node* temp = (node->left != nullptr) ? node->left : node->right;

            // Node with no child
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                // Node with one child
                *node = *temp; // Copy the contents of the only child
            }

            delete temp;
        } else {
            // Node with two children, get the inorder successor
            Node* temp = findMin(node->right);

            // Copy the inorder successor's data to this node
            node->value = temp->value;

            // Remove the inorder successor
            node->right = removeNode(node->right, temp->value);
        }
    }

    // If the tree had only one node, then return
    if (node == nullptr)
        return nullptr;

    // Update height of current node
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    // Perform rebalance
    return rebalance(node);
}


    bool containsNode(Node* node, T item) const {
        if (node == nullptr)
            return false;

        if (item < node->value)
            return containsNode(node->left, item);
        else if (item > node->value)
            return containsNode(node->right, item);
        else
            return true; // Found the item
    }

    void clearNodes(Node* node) {
        if (node != nullptr) {
            clearNodes(node->left);
            clearNodes(node->right);
            delete node;
        }
    }

    int getSize(Node* node) const {
        return (node == nullptr) ? 0 : 1 + getSize(node->left) + getSize(node->right);
    }
};
