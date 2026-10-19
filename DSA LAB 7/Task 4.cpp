//NAME: ABDULLAH FAISAL
// REG NO : 2502053

#include <iostream>
using namespace std;

class PassengerDeque {
private:
    int deque[5];
    int front, rear;

public:
    PassengerDeque() {
        front = -1;
        rear = -1;
    }

    void insertFront(int requestID) {
        if (front == 0 && rear == 4) {
            cout << "Deque is Full!\n";
            return;
        }

        if (front == -1) {
            front = rear = 0;
        }
        else if (front > 0) {
            front--;
        }
        else {
            cout << "Cannot insert at front.\n";
            return;
        }

        deque[front] = requestID;
        cout << "Request " << requestID << " added at front.\n";
    }
   void insertRear(int requestID) {
        if (rear == 4) {
            cout << "Deque is Full!\n";
            return;
        }

        if (front == -1) {
            front = rear = 0;
        }
        else {
            rear++;
        }

        deque[rear] = requestID;
        cout << "Request " << requestID << " added at rear.\n";
    }

    void removeFront() {
        if (front == -1) {
            cout << "Deque is Empty!\n";
            return;
        }

        cout << "Request " << deque[front] << " removed from front.\n";

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }
    }

    void removeRear() {
        if (rear == -1) {
            cout << "Deque is Empty!\n";
            return;
        }

        cout << "Request " << deque[rear] << " removed from rear.\n";

        if (front == rear) {
            front = rear = -1;
        }
        else {
            rear--;
        }
    }

    void display() {
        if (front == -1) {
            cout << "No requests in the deque.\n";
            return;
        }

        cout << "Requests: ";

        for (int i = front; i <= rear; i++) {
            cout << deque[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    PassengerDeque station;

    station.insertRear(301);
    station.insertRear(302);
    station.insertFront(300);

    station.display();

    station.removeFront();
    station.removeRear();

    station.display();

    return 0;
}
