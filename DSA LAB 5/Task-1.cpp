// Name: ABDULLAH FAISAL
// Roll Number: 2502053
// Task: Task 1 - Browser History

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string url;
    Node* prev;
    Node* next;
    
    Node(string val) : url(val), prev(NULL), next(NULL) {}
};

class BrowserHistory {
    Node* head;
    Node* tail;
public:
    BrowserHistory() : head(NULL), tail(NULL) {}

    void addPage(string url) {
        Node* newNode = new Node(url);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayForward() {
        cout << "First -> Last Visited:" << endl;
        Node* temp = head;
        while (temp) {
            cout << " - " << temp->url << endl;
            temp = temp->next;
        }
    }

    void displayBackward() {
        cout << "\nLast -> First Visited:" << endl;
        Node* temp = tail;
        while (temp) {
            cout << " - " << temp->url << endl;
            temp = temp->prev;
        }
    }
};

int main() {
    BrowserHistory history;
    history.addPage("google.com");
    history.addPage("github.com");
    history.addPage("stackoverflow.com");
    history.addPage("youtube.com");
    history.addPage("wikipedia.org");

    history.displayForward();
    history.displayBackward();

    return 0;
}
