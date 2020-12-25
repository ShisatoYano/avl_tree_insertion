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

// left rotate subtree rooted with x
Node* left_rotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// get balance factor of node N
int get_balance(Node* N) {
    if (N == NULL) {
        return 0;
    }
    return height(N->left) - height(N->right);
}

// insert key recursively in subtree
// rooted with node and returns
// new root of subtree
Node* insert(Node* node, int key) {
    // normal binary search tree
    if (node == NULL) {
        return(new_node(key));
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        // equal keys are not allowed in binary search tree
        return node;
    }

    // update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // get the balance factor of this ancestor node
    // to check whether this node become unbalanced
    int balance = get_balance(node);

    // if this node becomes unbalanced,
    // then there are 4 cases

    // left left case
    if (balance > 1 && key < node->left->key) {
        return right_rotate(node);
    }

    // right right case
    if (balance < -1 &&  key > node->right->key) {
        return left_rotate(node);
    }

    // left right case
    if (balance > 1 && key > node->left->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // right left case
    if (balance < -1 && key < node->right->key) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

// print preorder traversal
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Preorder traversal of the constructed \n";
    preorder(root);

    return 0;
}
