// Name: ABDULLAH FAISAL
// Roll Number: 2502053
// Task: Task 4 - Music Playlist

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string song;
    Node* next;

    Node(string title) : song(title), next(NULL) {}
};

class Playlist {
    Node* head;
    Node* tail;
    int count;
public:
    Playlist() : head(NULL), tail(NULL), count(0) {}

    void addSong(string title) {
        Node* newNode = new Node(title);
        if (!head) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        count++;
    }

    void displayPlaylist() {
        if (!head) return;
        cout << "Playlist Songs:" << endl;
        Node* temp = head;
        do {
            cout << " - " << temp->song << endl;
            temp = temp->next;
        } while (temp != head);
    }

    void playRounds(int rounds) {
        if (!head) return;
        cout << "\nSimulating Playlist for " << rounds << " Complete Rounds:" << endl;
        Node* temp = head;
        int totalTracks = count * rounds;
        
        for (int i = 1; i <= totalTracks; i++) {
            cout << "Track " << i << ": Playing " << temp->song << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Playlist myPlaylist;
    myPlaylist.addSong("Shape of You");
    myPlaylist.addSong("Blinding Lights");
    myPlaylist.addSong("Stay");
    myPlaylist.addSong("Levitating");
    myPlaylist.addSong("Perfect");

    myPlaylist.displayPlaylist();
    myPlaylist.playRounds(2);

    return 0;
}
