//NAME: ABDULLAH FAISAL
// REG NO : 2502053

#include <iostream>
using namespace std;

class HospitalQueue {
private:
    struct Patient {
        string id;
        int priority;
    };

    Patient queue[5];
    int count;

public:
    HospitalQueue() {
        count = 0;
    }

    void enqueue(string id, int priority) {
        if (count == 5) {
            cout << "Queue is Full!\n";
            return;
        }

        queue[count].id = id;
        queue[count].priority = priority;
        count++;

        cout << "Patient " << id << " added.\n";
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue is Empty! No patient to treat.\n";
            return;
        }

        int highest = 0;

        for (int i = 1; i < count; i++) {
            if (queue[i].priority < queue[highest].priority) {
                highest = i;
            }
        }

        cout << "Treating Patient " << queue[highest].id
             << " (Priority " << queue[highest].priority << ")\n";

        for (int i = highest; i < count - 1; i++) {
            queue[i] = queue[i + 1];
        }

        count--;
    }

    void display() {
        if (count == 0) {
            cout << "No patients are waiting.\n";
            return;
        }

        cout << "\nWaiting Patients:\n";

        for (int i = 0; i < count; i++) {
            cout << "Patient ID: " << queue[i].id
                 << "  Priority: " << queue[i].priority << endl;
        }
    }
};

int main() {
    HospitalQueue hospital;

    hospital.enqueue("P101", 3);
    hospital.enqueue("P102", 1);
    hospital.enqueue("P103", 2);

    hospital.display();

    hospital.dequeue();

    hospital.display();

    return 0;
}
