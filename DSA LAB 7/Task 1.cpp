//NAME: ABDULLAH FAISAL
// REG NO : 2502053

#include <iostream>
using namespace std;

class BankQueue {
private:
    int queue[5];
    int front, rear;

public:
    BankQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int token) {
        if (rear == 4) {
            cout << "Queue Overflow! No more customers can be added.\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = token;

        cout << "Customer " << token << " added.\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! No customers waiting.\n";
            return;
        }

        cout << "Customer " << queue[front] << " is served.\n";
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    void display() {
        if (front == -1) {
            cout << "No customers are waiting.\n";
            return;
        }

        cout << "Waiting customers: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }

    void countCustomers() {
        if (front == -1)
            cout << "Number of waiting customers: 0\n";
        else
            cout << "Number of waiting customers: " << rear - front + 1 << endl;
    }
};

int main() {
    BankQueue bank;

    bank.enqueue(101);
    bank.enqueue(102);
    bank.enqueue(103);

    bank.display();
    bank.countCustomers();

    bank.dequeue();

    bank.display();
    bank.countCustomers();

    return 0;
}


