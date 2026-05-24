#include <iostream>
using namespace std;

// Node structure for a simple binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to easily create a node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// 1. Pre-order Traversal
void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// 2. In-order Traversal
void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// 3. Post-order Traversal
void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    // Manually creating a tree with 5 nodes as required
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    // Displaying the traversal results
    cout << "--- Task 1: Binary Tree Traversals ---" << endl;

    cout << "Pre-order Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "In-order Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postOrder(root);
    cout << endl;

    return 0;
}