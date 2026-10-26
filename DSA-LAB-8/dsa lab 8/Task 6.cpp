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
    Node* root;

    Node* insert(Node* node, int id) {
        if (node == NULL)
            return new Node(id);

        if (id < node->id)
            node->left = insert(node->left, id);
        else if (id > node->id)
            node->right = insert(node->right, id);
        else
            cout << "Duplicate product ID!" << endl;

        return node;
    }

    bool search(Node* node, int id) {
        if (node == NULL)
            return false;

        if (node->id == id)
            return true;

        if (id < node->id)
            return search(node->left, id);

        return search(node->right, id);
    }

    Node* findMin(Node* node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int id) {
        if (node == NULL)
            return NULL;

        if (id < node->id)
            node->left = deleteNode(node->left, id);
        else if (id > node->id)
            node->right = deleteNode(node->right, id);
        else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->id = temp->id;
            node->right = deleteNode(node->right, temp->id);
        }

        return node;
    }

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->id << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node != NULL) {
            cout << node->id << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node != NULL) {
            postorder(node->left);
            postorder(node->right);
            cout << node->id << " ";
        }
    }

    void clear(Node* node) {
        if (node != NULL) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        clear(root);
    }

    void insertProduct(int id) {
        if (search(root, id))
            cout << "Product ID already exists!" << endl;
        else {
            root = insert(root, id);
            cout << "Product inserted successfully." << endl;
        }
    }

    void searchProduct(int id) {
        if (search(root, id))
            cout << "Product Found." << endl;
        else
            cout << "Product Not Found." << endl;
    }

    void deleteProduct(int id) {
        if (!search(root, id))
            cout << "Product Not Found." << endl;
        else {
            root = deleteNode(root, id);
            cout << "Product deleted successfully." << endl;
        }
    }

    void displayInorder() {
        cout << "In-order: ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        cout << "Pre-order: ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        cout << "Post-order: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int choice, id;

    do {
        cout << "\n1. Insert Product ID";
        cout << "\n2. Search Product ID";
        cout << "\n3. Delete Product ID";
        cout << "\n4. Display In-order";
        cout << "\n5. Display Pre-order";
        cout << "\n6. Display Post-order";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter product ID: ";
            cin >> id;
            tree.insertProduct(id);
            break;

        case 2:
            cout << "Enter product ID to search: ";
            cin >> id;
            tree.searchProduct(id);
            break;

        case 3:
            cout << "Enter product ID to delete: ";
            cin >> id;
            tree.deleteProduct(id);
            break;

        case 4:
            tree.displayInorder();
            break;

        case 5:
            tree.displayPreorder();
            break;

        case 6:
            tree.displayPostorder();
            break;

        case 7:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
