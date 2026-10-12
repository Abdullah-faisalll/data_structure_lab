#include <iostream>
#include <string>
using namespace std;

struct Node {
  string id;
  Node* next;
  Node(string val) {
    id = val;
    next = NULL;
  }
};

class LinkedListStack {
  Node* top;

public:
  LinkedListStack() {
    top = NULL;
  }

  ~LinkedListStack() {
    while (top != NULL) {
      Node* temp = top;
      top = top->next;
      delete temp;
    }
  }

  void push(string id) {
    Node* n = new Node(id);
    n->next = top;
    top = n;
  }

  string pop() {
    if (top == NULL) return "";
    Node* temp = top;
    string val = temp->id;
    top = top->next;
    delete temp;
    return val;
  }

  string peek() {
    if (top == NULL) return "Empty";
    return top->id;
  }

  void display() {
    Node* curr = top;
    while (curr != NULL) {
      cout << curr->id << endl;
      curr = curr->next;
    }
  }
};

int main() {
  LinkedListStack hospital;
  hospital.push("P101");
  hospital.push("P102");
  hospital.push("P103");
  hospital.push("P104");

  cout << "All requests:" << endl;
  hospital.display();

  cout << "\nHandled: " << hospital.pop() << endl;
  cout << "New Top: " << hospital.peek() << endl;

  cout << "\nRemaining requests:" << endl;
  hospital.display();

  return 0;
}
