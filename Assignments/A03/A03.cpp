#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Bst {
    Node *root;

    void _print(Node *subroot) {
        if (!subroot) return;
        _print(subroot->left);
        cout << subroot->data << " ";
        _print(subroot->right);
    }

    void _insert(Node *&subroot, int x) {
        if (!subroot)
            subroot = new Node(x);
        else if (x < subroot->data)
            _insert(subroot->left, x);
        else
            _insert(subroot->right, x);
    }

    Node* _delete(Node *subroot, int key) {
        if (!subroot) return subroot;
        if (key < subroot->data)
            subroot->left = _delete(subroot->left, key);
        else if (key > subroot->data)
            subroot->right = _delete(subroot->right, key);
        else {
            if (!subroot->left) {
                Node *temp = subroot->right;
                delete subroot;
                return temp;
            } else if (!subroot->right) {
                Node *temp = subroot->left;
                delete subroot;
                return temp;
            }
            Node *temp = _minValueNode(subroot->right);
            subroot->data = temp->data;
            subroot->right = _delete(subroot->right, temp->data);
        }
        return subroot;
    }

    Node* _minValueNode(Node *node) {
        while (node->left)
            node = node->left;
        return node;
    }

public:
    Bst() : root(nullptr) {}

    void insert(int x) { _insert(root, x); }
    void remove(int x) { root = _delete(root, x); }
    void print() { _print(root); cout << endl; }
};

int main() {
    Bst tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);
    tree.insert(20);

    cout << "BST before deletion: ";
    tree.print();

    tree.remove(10);
    cout << "BST after deleting 10: ";
    tree.print();
    
    return 0;
}
