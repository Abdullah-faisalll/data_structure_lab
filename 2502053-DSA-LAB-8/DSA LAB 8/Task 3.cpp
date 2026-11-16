#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = right = NULL;
    }
};

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->name << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->name << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->name << " ";
}

int main() {
    Node* root = new Node("Computer");

    root->left = new Node("Documents");
    root->right = new Node("Downloads");

    root->left->left = new Node("Assignments");
    root->left->right = new Node("Projects");

    root->right->left = new Node("Images");
    root->right->right = new Node("Videos");

    cout << "In-order: ";
    inorder(root);

    cout << "\nPre-order: ";
    preorder(root);

    cout << "\nPost-order: ";
    postorder(root);

    return 0;
}
