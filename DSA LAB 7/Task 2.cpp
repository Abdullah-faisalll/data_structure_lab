//NAME: ABDULLAH FAISAL
// REG NO : 2502053

#include <iostream>
using namespace std;

class PacketQueue {
private:
    int queue[5];
    int front, rear;
    int count;

public:
    PacketQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int packetID) {
        if (count == 5) {
            cout << "Queue is Full!\n";
            return;
        }

        rear = (rear + 1) % 5;
        queue[rear] = packetID;
        count++;

        cout << "Packet " << packetID << " added.\n";
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Packet " << queue[front] << " transmitted.\n";

        front = (front + 1) % 5;
        count--;
    }

    void display() {
        if (count == 0) {
            cout << "No packets waiting.\n";
            return;
        }

        cout << "Packets waiting: ";

        for (int i = 0; i < count; i++) {
            cout << queue[(front + i) % 5] << " ";
        }

        cout << endl;
    }
};

int main() {
    PacketQueue packets;

    packets.enqueue(201);
    packets.enqueue(202);
    packets.enqueue(203);

    packets.display();

    packets.dequeue();

    packets.display();

    packets.enqueue(204);

    packets.display();

    return 0;
}


