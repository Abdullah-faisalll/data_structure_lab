#include <iostream>
#include <string>
using namespace std;

class ArrayStack {
  int top, capacity;
  string* arr;

public:
  ArrayStack(int cap) {
    capacity = cap;
    arr = new string[capacity];
    top = -1;
  }
  ~ArrayStack() { delete[] arr; }

  void push(string act) {
    if (top < capacity - 1) arr[++top] = act;
  }

  string pop() {
    return (top == -1) ? "" : arr[top--];
  }

  string peek() {
    return (top == -1) ? "Empty" : arr[top];
  }

  void display() {
    for (int i = top; i >= 0; i--) cout << arr[i] << endl;
  }
};

int main() {
  ArrayStack editor(10);
  editor.push("Type \"Hello\"");
  editor.push("Type \"World\"");
  editor.push("Add \"!\"");
  editor.push("Delete \"!\"");

  cout << "All actions:" << endl;
  editor.display();

  cout << "\nUndone: " << editor.pop() << endl;
  cout << "Undone: " << editor.pop() << endl;

  cout << "\nCurrent Top: " << editor.peek() << endl;
  cout << "\nRemaining actions:" << endl;
  editor.display();
  return 0;
}
