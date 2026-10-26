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

    Node* insert(Node* root, int value) {
        if (root == NULL)
            return new Node(value);

        if (value < root->id)
            root->left = insert(root->left, value);
        else if (value > root->id)
            root->right = insert(root->right, value);

        return root;
    }

    bool search(int value, int& comparisons) {
        Node* current = root;

        while (current != NULL) {
            comparisons++;

            if (current->id == value)
                return true;
            else if (value < current->id)
                current = current->left;
            else
                current = current->right;
        }

        return false;
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

    int bookID, comparisons = 0;

    cout << "Enter Book ID to search: ";
    cin >> bookID;

    if (tree.search(bookID, comparisons))
        cout << "Book Found" << endl;
    else
        cout << "Book Not Found" << endl;

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}

