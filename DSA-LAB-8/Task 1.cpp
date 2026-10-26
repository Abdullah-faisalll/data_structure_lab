 // Name: Abdullah Faisal
 // Registration ID: 2502053

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = NULL;
        right = NULL;
    }
};

void display(Node* root) {
    if (root == NULL)
        return;

    cout << root->name
      << "  Left: "
      << (root->left != NULL ? root->left->name : "None")
      << "  Right: "
      << (root->right != NULL ? root->right->name : "None")
      << endl;

    display(root->left);
    display(root->right);
}

int main() {
    Node* grandfather = new Node("Grandfather");
    grandfather->left = new Node("Grandmother");
    grandfather->right = new Node("Father");

    grandfather->left->left = new Node("Uncle");
    grandfather->left->right = new Node("Aunt");
    grandfather->right->left = new Node("Brother");
    grandfather->right->right = new Node("Sister");

    cout << "Family Tree" << endl;
    display(grandfather);

    return 0;
}
