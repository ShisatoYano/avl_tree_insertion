#include <bits/stdc++.h>
using namespace std;

// tree node
class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;
};

// get maximum of two integers
int max(int a, int b) {
    return (a > b)? a : b;
}

// get the height of tree
int height(Node* N) {
    if (N == NULL) {
        return 0;
    }
    return N->height;
}

// allocate a new node with the given key
// and NULL left and right pointers
Node* new_node(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node is initially added at leaf

    return node;
}

// right rotate subtree rooted with y
Node* right_rotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // perform rotation
    x->right = y;
    y->left = T2;

    // update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // return new root
    return x;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
