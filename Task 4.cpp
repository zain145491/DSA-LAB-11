#include <iostream>
using namespace std;

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

BSTNode* insert(BSTNode* root, int val) {
    if (root == NULL) return new BSTNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Task 4: Reach leftmost node recursively for Minimum
BSTNode* findMin(BSTNode* root) {
    if (root == NULL) return NULL;
    if (root->left == NULL) return root; // Leftmost leaf reached
    return findMin(root->left);
}

// Task 4: Reach rightmost node recursively for Maximum
BSTNode* findMax(BSTNode* root) {
    if (root == NULL) return NULL;
    if (root->right == NULL) return root; // Rightmost leaf reached
    return findMax(root->right);
}

int main() {
    BSTNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 45);
    insert(root, 70);
    insert(root, 90);

    cout << "--- Task 4: Find Min & Max recursively ---" << endl;

    BSTNode* minNode = findMin(root);
    BSTNode* maxNode = findMax(root);

    if (minNode != NULL) cout << "Minimum value in BST: " << minNode->data << endl;
    if (maxNode != NULL) cout << "Maximum value in BST: " << maxNode->data << endl;

    return 0;
}