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

  void push(string v) {
    if (top < capacity - 1) arr[++top] = v;
  }

  string pop() {
    if (top == -1) return "";
    return arr[top--];
  }

  string peek() {
    return (top == -1) ? "Empty" : arr[top];
  }

  void display() {
    for (int i = top; i >= 0; i--)
      cout << arr[i] << endl;
  }
};

int main() {
  ArrayStack history(10);
  history.push("Google");
  history.push("YouTube");
  history.push("Facebook");
  history.push("GitHub");

  cout << "All pages:" << endl;
  history.display();

  cout << "\nBack button pressed, removed: " << history.pop() << endl;
  cout << "Current Top: " << history.peek() << endl;

  cout << "\nRemaining history:" << endl;
  history.display();
  return 0;
}
