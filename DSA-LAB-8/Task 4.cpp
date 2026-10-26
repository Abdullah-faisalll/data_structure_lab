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

    Node* findMin(Node* root) {
        while (root->left != NULL)
            root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, int value) {
        if (root == NULL)
            return root;

        if (value < root->id)
            root->left = deleteNode(root->left, value);
        else if (value > root->id)
            root->right = deleteNode(root->right, value);
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = findMin(root->right);
            root->id = temp->id;
            root->right = deleteNode(root->right, temp->id);
        }

        return root;
    }

    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->id << " ";
            inorder(root->right);
        }
    }

    void add(int value) {
        root = insert(root, value);
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }
};

int main() {
    BST tree;

    tree.add(50);
    tree.add(30);
    tree.add(70);
    tree.add(20);
    tree.add(40);
    tree.add(60);
    tree.add(80);

    int id;

    cout << "Enter Employee ID to delete: ";
    cin >> id;

    tree.remove(id);

    cout << "Remaining Employee IDs: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}

