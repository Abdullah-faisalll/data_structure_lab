
 // Name: Abdullah Faisal
 // Registration ID: 2502053

#include <iostream>
using namespace std;

class Node {
public:
    int id;
    Node* left;
    Node* right;

    Node(int value) {
        id = value;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* root, int value) {
        if (root == NULL)
            return new Node(value);

        if (value < root->id)
            root->left = insert(root->left, value);
        else if (value > root->id)
            root->right = insert(root->right, value);

        return root;
    }

    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->id << " ";
            inorder(root->right);
        }
    }

    void preorder(Node* root) {
        if (root != NULL) {
            cout << root->id << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node* root) {
        if (root != NULL) {
            postorder(root->left);
            postorder(root->right);
            cout << root->id << " ";
        }
    }

    void add(int value) {
        root = insert(root, value);
    }
};

int main() {
    BST tree;

    tree.add(40);
    tree.add(20);
    tree.add(60);
    tree.add(10);
    tree.add(30);
    tree.add(50);
    tree.add(70);

    cout << "In-order: ";
    tree.inorder(tree.root);

    cout << "\nPre-order: ";
    tree.preorder(tree.root);

    cout << "\nPost-order: ";
    tree.postorder(tree.root);

    cout << "\n\nIn-order traversal displays IDs in ascending order." << endl;

    return 0;
}
