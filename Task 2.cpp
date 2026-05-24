#include <iostream>
using namespace std;

// Node structure for BST
struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Recursive function to insert elements according to BST rules
BSTNode* insert(BSTNode* root, int val) {
    if (root == NULL) {
        return new BSTNode(val);
    }
    // If value is small, go to left subtree
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    // If value is larger, go to right subtree
    else {
        root->right = insert(root->right, val);
    }
    return root;
}

// In-order traversal to show values in sorted/ascending order
void inOrderBST(BSTNode* root) {
    if (root == NULL) return;
    inOrderBST(root->left);
    cout << root->data << " ";
    inOrderBST(root->right);
}

int main() {
    BSTNode* root = NULL;

    // Inserting values into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "--- Task 2: BST Insertion and In-order ---" << endl;
    cout << "BST In-order Traversal: ";
    inOrderBST(root);
    cout << endl;

    return 0;
}