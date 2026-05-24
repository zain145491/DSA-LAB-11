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

// Task 3: Recursive search function
bool search(BSTNode* root, int key) {
    // Base Case: If tree is empty or value not found
    if (root == NULL) return false;
    // If value is found at current node
    if (root->data == key) return true;

    // Search left or right depending on the key value
    if (key < root->data) {
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}

int main() {
    BSTNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);

    cout << "--- Task 3: Recursive Search ---" << endl;
    int searchVal;
    cout << "Enter a value to search in the BST: ";
    cin >> searchVal;

    // Output message based on whether it exists or not
    if (search(root, searchVal)) {
        cout << "Message: " << searchVal << " exists in the BST." << endl; [cite:50]
    }
    else {
        cout << "Message: " << searchVal << " does not exist in the BST." << endl; [cite:50]
    }

    return 0;
}