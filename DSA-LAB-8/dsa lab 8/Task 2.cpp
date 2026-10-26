 // Name: Abdullah Faisal
 // Registration ID: 2502053

#include <iostream>
using namespace std;

class Node {
public:
    int roll;
    Node* left;
    Node* right;

    Node(int r) {
        roll = r;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* root, int r) {
        if (root == NULL)
            return new Node(r);

        if (r < root->roll)
            root->left = insert(root->left, r);
        else if (r > root->roll)
            root->right = insert(root->right, r);

        return root;
    }

    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->roll << " ";
            inorder(root->right);
        }
    }

    void add(int r) {
        root = insert(root, r);
    }
};

int main() {
    BST tree;

    tree.add(45);
    tree.add(25);
    tree.add(65);
    tree.add(15);
    tree.add(35);
    tree.add(55);
    tree.add(75);

    int a, b;

    cout << "Enter two additional roll numbers: ";
    cin >> a >> b;

    tree.add(a);
    tree.add(b);

    cout << "Roll numbers in ascending order: ";
    tree.inorder(tree.root);

    cout << endl;

    return 0;
}
