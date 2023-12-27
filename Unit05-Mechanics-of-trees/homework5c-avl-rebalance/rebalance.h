/*
#pragma once

struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
};

// Hint: you might find it helpful to write an update_height function that takes
// a Node* and updates its height field based on the heights of its children

void promote_left(Node*& root) {
    // implement promote_left here
}

void promote_right(Node*& root) {
    // implement promote_right here
}

void rebalance(Node*& root) {
    // implement rebalance here
}
*/

#pragma once
#include <algorithm>

struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
};

void update_height(Node* node) {
    if (node != nullptr) {
        int left_height = (node->left != nullptr) ? node->left->height : 0;
        int right_height = (node->right != nullptr) ? node->right->height : 0;
        node->height = 1 + std::max(left_height, right_height);
    }
}

void promote_left(Node*& root) {
    if (root == nullptr || root->right == nullptr) {
        return;
    }

    Node* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;

    update_height(root);
    update_height(newRoot);

    root = newRoot;
}

void promote_right(Node*& root) {
    if (root == nullptr || root->left == nullptr) {
        return; // Cannot promote right if there's no left child
    }

    Node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;

    // Update heights
    update_height(root);
    update_height(newRoot);

    root = newRoot;
}

void rebalance(Node*& root) {
    auto height = [](Node* node) { return (node != nullptr) ? node->height : 0; };

    update_height(root);

    int balance = height(root->left) - height(root->right);

    if (balance > 1) {
        if (height(root->left->right) > height(root->left->left)) {
            promote_left(root->left);
        }
        promote_right(root);
    }
    else if (balance < -1) {
        if (height(root->right->left) > height(root->right->right)) {
            promote_right(root->right);
        }
        promote_left(root);
    }

    update_height(root);
}
