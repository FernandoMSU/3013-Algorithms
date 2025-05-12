#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Node structure for BST
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

// Helper function to find the node with the minimum key in a subtree
Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

// Delete function for BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return nullptr;

    // Step 1: Traverse the tree to locate the node
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with matching key found

        // Case 1: Node with no children (leaf)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: Node with only one child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node with two children
        else {
            // Find the inorder successor (smallest in right subtree)
            Node* successor = findMin(root->right);
            // Copy the successor's key to this node
            root->key = successor->key;
            // Delete the successor node from right subtree
            root->right = deleteNode(root->right, successor->key);
        }
    }

    return root;
}

// Simple function to insert nodes into BST (for testing)
Node* insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

// Inorder traversal for testing
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Main function for demonstration
int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 50);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
