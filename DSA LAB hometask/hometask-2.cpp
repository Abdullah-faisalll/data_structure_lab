// Abdullah Faisal 2502053 , Task number 2

#include <iostream>
#include <string>

using namespace std;

struct Node {
    int rollNo;
    string name;
    string status; // Present / Absent
    Node* next;
};

class AttendanceList {
private:
    Node* head;

public:
    AttendanceList() {
        head = NULL;
    }

    // 1. Add student to attendance list
    void addStudent(int rollNo, string name, string status) {
        Node* newNode = new Node();
        newNode->rollNo = rollNo;
        newNode->name = name;
        newNode->status = status;
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
        cout << "Student added successfully.\n";
    }

    // 2. Search student using Roll Number
    void searchStudent(int rollNo) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->rollNo == rollNo) {
                cout << "Found -> Roll No: " << temp->rollNo 
                     << ", Name: " << temp->name 
                     << ", Status: " << temp->status << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found.\n";
    }

    // 3. Delete student from list
    void deleteStudent(int rollNo) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if (head->rollNo == rollNo) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Student removed from list.\n";
            return;
        }

        Node* current = head;
        Node* prev = NULL;

        while (current != NULL && current->rollNo != rollNo) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Student not found.\n";
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Student removed from list.\n";
    }

    // 4 & 6. Display all / final attendance list
    void displayStudents() {
        if (head == NULL) {
            cout << "No attendance record found.\n";
            return;
        }

        cout << "\n--- Class Attendance List ---\n";
        Node* temp = head;
        while (temp != NULL) {
            cout << "Roll No: " << temp->rollNo 
                 << " | Name: " << temp->name 
                 << " | Status: " << temp->status << "\n";
            temp = temp->next;
        }
    }

    // 5. Count total students present
    void countPresent() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->status == "Present" || temp->status == "present" || temp->status == "P" || temp->status == "p") {
                count++;
            }
            temp = temp->next;
        }
        cout << "Total Present Students: " << count << "\n";
    }
};

int main() {
    AttendanceList attendance;
    int choice, rollNo;
    string name, status;

    do {
        cout << "\n--- Student Attendance System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Count Total Present\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Roll No, Name, Status (Present/Absent): ";
                cin >> rollNo >> name >> status;
                attendance.addStudent(rollNo, name, status);
                break;
            case 2:
                cout << "Enter Roll No to search: ";
                cin >> rollNo;
                attendance.searchStudent(rollNo);
                break;
            case 3:
                cout << "Enter Roll No to delete: ";
                cin >> rollNo;
                attendance.deleteStudent(rollNo);
                break;
            case 4:
                attendance.displayStudents();
                break;
            case 5:
                attendance.countPresent();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
