// Name: ABDULLAH FAISAL
// Roll Number: 2502053
// Task: Task 2 - Image Gallery

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string image;
    Node* prev;
    Node* next;

    Node(string name) : image(name), prev(NULL), next(NULL) {}
};

class ImageGallery {
    Node* head;
    Node* tail;
public:
    ImageGallery() : head(NULL), tail(NULL) {}

    void addImage(string name) {
        Node* newNode = new Node(name);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void showForward() {
        cout << "Gallery (Forward):" << endl;
        Node* temp = head;
        while (temp) {
            cout << "[ " << temp->image << " ] -> ";
            temp = temp->next;
        }
        cout << "END" << endl;
    }

    void showBackward() {
        cout << "\nGallery (Backward):" << endl;
        Node* temp = tail;
        while (temp) {
            cout << "[ " << temp->image << " ] -> ";
            temp = temp->prev;
        }
        cout << "START" << endl;
    }
};

int main() {
    ImageGallery gallery;
    gallery.addImage("sunset.jpg");
    gallery.addImage("mountains.png");
    gallery.addImage("beach.jpg");
    gallery.addImage("forest.png");
    gallery.addImage("skyline.jpg");

    gallery.showForward();
    gallery.showBackward();

    return 0;
}
