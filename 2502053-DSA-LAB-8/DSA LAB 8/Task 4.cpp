#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int token;
    int height;
    Node* left;
    Node* right;

    Node(int n) {
        token = n;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node* root) {
    if (root == NULL)
        return 0;
    return root->height;
}

int getBalance(Node* root) {
    if (root == NULL)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

Node* insert(Node* root, int key) {
    if (root == NULL)
        return new Node(key);

    if (key < root->token)
        root->left = insert(root->left, key);
    else if (key > root->token)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->token)
        return rightRotate(root);

    if (balance < -1 && key > root->right->token)
        return leftRotate(root);

    if (balance > 1 && key > root->left->token) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->token) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->token << " ";
    inorder(root->right);
}

void display(Node* root, int space = 0) {
    if (root == NULL)
        return;

    space += 5;

    display(root->right, space);

    cout << endl;
    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->token << endl;

    display(root->left, space);
}

void showBalance(Node* root) {
    if (root == NULL)
        return;

    showBalance(root->left);
    cout << "Token: " << root->token
         << "  Height: " << root->height
         << "  Balance Factor: " << getBalance(root) << endl;
    showBalance(root->right);
}

int main() {
    Node* root = NULL;

    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    for (int i = 0; i < 7; i++) {
        root = insert(root, tokens[i]);
    }

    cout << "In-order Traversal: ";
    inorder(root);

    cout << "\n\nNode Heights and Balance Factors:\n";
    showBalance(root);

    cout << "\nFinal Balanced AVL Tree:\n";
    display(root);

    return 0;
}
