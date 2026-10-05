// Abdullah Faisal 2502053 , Task number 1

#include <iostream>
#include <string>

using namespace std;

struct Node {
    int id;
    string name;
    int age;
    Node* next;
};

class HospitalSystem {
private:
    Node* head;

public:
    HospitalSystem() {
        head = NULL;
    }

    // 1. Add patient at end
    void addPatientEnd(int id, string name, int age) {
        Node* newNode = new Node();
        newNode->id = id;
        newNode->name = name;
        newNode->age = age;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Patient added at the end successfully.\n";
    }

    // 2. Add emergency patient at beginning
    void addEmergencyPatient(int id, string name, int age) {
        Node* newNode = new Node();
        newNode->id = id;
        newNode->name = name;
        newNode->age = age;
        newNode->next = head;
        head = newNode;
        cout << "Emergency patient added at the beginning successfully.\n";
    }

    // 3. Search for a patient using Patient ID
    void searchPatient(int id) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->id == id) {
                cout << "Patient Found! ID: " << temp->id 
                     << ", Name: " << temp->name 
                     << ", Age: " << temp->age << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Patient with ID " << id << " does not exist.\n";
    }

    // 4. Remove a patient after treatment using Patient ID
    void removePatient(int id) {
        if (head == NULL) {
            cout << "Waiting list is empty.\n";
            return;
        }

        // If head node itself holds the key
        if (head->id == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Patient " << id << " treated and removed.\n";
            return;
        }

        Node* current = head;
        Node* prev = NULL;

        while (current != NULL && current->id != id) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Patient with ID " << id << " does not exist.\n";
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Patient " << id << " treated and removed.\n";
    }

    // 5. Display all waiting patients
    void displayPatients() {
        if (head == NULL) {
            cout << "No patients in the waiting list.\n";
            return;
        }

        cout << "\n--- Waiting Patients List ---\n";
        Node* temp = head;
        while (temp != NULL) {
            cout << "ID: " << temp->id << " | Name: " << temp->name << " | Age: " << temp->age << "\n";
            temp = temp->next;
        }
    }
};

int main() {
    HospitalSystem hospital;
    int choice, id, age;
    string name;

    do {
        cout << "\n--- Hospital Emergency System ---\n";
        cout << "1. Add Normal Patient (End)\n";
        cout << "2. Add Emergency Patient (Beginning)\n";
        cout << "3. Search Patient by ID\n";
        cout << "4. Remove Treated Patient\n";
        cout << "5. Display Waiting Patients\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID, Name, Age: ";
                cin >> id >> name >> age;
                hospital.addPatientEnd(id, name, age);
                break;
            case 2:
                cout << "Enter Emergency Patient ID, Name, Age: ";
                cin >> id >> name >> age;
                hospital.addEmergencyPatient(id, name, age);
                break;
            case 3:
                cout << "Enter Patient ID to search: ";
                cin >> id;
                hospital.searchPatient(id);
                break;
            case 4:
                cout << "Enter Patient ID to remove: ";
                cin >> id;
                hospital.removePatient(id);
                break;
            case 5:
                hospital.displayPatients();
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
