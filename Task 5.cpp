#include <iostream>
using namespace std;

// BST Node structure
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

// Simple recursive insertion function
BSTNode* insert(BSTNode* root, int val) {
    if (root == NULL) return new BSTNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// In-order traversal to show the elements
void inOrderBST(BSTNode* root) {
    if (root == NULL) return;
    inOrderBST(root->left);
    cout << root->data << " ";
    inOrderBST(root->right);
}

// Fully recursive function to find min node
BSTNode* findMin(BSTNode* root) {
    if (root == NULL) return NULL;
    if (root->left == NULL) return root;
    return findMin(root->left);
}

// Task 5: Pure recursive deletion function
BSTNode* deleteNode(BSTNode* root, int val) {
    if (root == NULL) return root;

    // 1. Searching the node to delete recursively
    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    }
    // 2. Node found, now handle deletion cases
    else {
        // Case 1: Node has no children (Leaf node)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: Node has only Right child
        else if (root->left == NULL) {
            BSTNode* temp = root->right;
            delete root;
            return temp;
        }
        // Case 2: Node has only Left child
        else if (root->right == NULL) {
            BSTNode* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Node has two children
        else {
            BSTNode* temp = findMin(root->right);
            root->data = temp->data;

            // Recursively delete the successor node
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    BSTNode* root = NULL;

    // Constructing the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "--- Task 5: Recursive Deletion ---" << endl;
    cout << "Original In-order Traversal: ";
    inOrderBST(root);
    cout << "\n\n";

    // Prompting user for deletion
    int deleteVal;
    cout << "Enter a value to delete: ";
    cin >> deleteVal;

    // Performing deletion
    root = deleteNode(root, deleteVal);

    // Verifying structure using in-order traversal
    cout << "\nUpdated In-order Traversal: ";
    inOrderBST(root);
    cout << endl;

    return 0;
}