// Name: ABDULLAH FAISAL
// Roll Number: 2502053
// Task: Task 3 - Game Player Turns

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string player;
    Node* next;

    Node(string name) : player(name), next(NULL) {}
};

class GameTurns {
    Node* head;
    Node* tail;
public:
    GameTurns() : head(NULL), tail(NULL) {}

    void addPlayer(string name) {
        Node* newNode = new Node(name);
        if (!head) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void displayTurns() {
        if (!head) return;
        cout << "Player Turns:" << endl;
        Node* temp = head;
        do {
            cout << "Turn: " << temp->player << endl;
            temp = temp->next;
        } while (temp != head);
        
        cout << "\nAfter " << tail->player << ", turn loops back to: " << temp->player << endl;
    }
};

int main() {
    GameTurns game;
    game.addPlayer("Alice");
    game.addPlayer("Bob");
    game.addPlayer("Charlie");
    game.addPlayer("David");
    game.addPlayer("Emma");

    game.displayTurns();

    return 0;
}
