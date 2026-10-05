// Abdullah Faisal 2502053 , Task number 4

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string code;
    string name;
    int credits;
    Node* next;
};

class CourseList {
private:
    Node* head;

public:
    CourseList() {
        head = NULL;
    }

    void addBeginning(string code, string name, int credits) {
        Node* newNode = new Node();
        newNode->code = code;
        newNode->name = name;
        newNode->credits = credits;
        newNode->next = head;
        head = newNode;
    }
    void addEnd(string code, string name, int credits) {
        Node* newNode = new Node();
        newNode->code = code;
        newNode->name = name;
        newNode->credits = credits;
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
    }

    // 3. Search Course by Course Code
    void searchCourse(string code) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->code == code) {
                cout << "Course Found! Code: " << temp->code 
                     << ", Name: " << temp->name 
                     << ", Credit Hours: " << temp->credits << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Course with code " << code << " not found.\n";
    }

    // 4. Delete Course by Course Code
    void deleteCourse(string code) {
        if (head == NULL) {
            cout << "Course list is empty.\n";
            return;
        }

        if (head->code == code) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Course " << code << " deleted successfully.\n";
            return;
        }

        Node* current = head;
        Node* prev = NULL;

        while (current != NULL && current->code != code) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Course with code " << code << " not found.\n";
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Course " << code << " deleted successfully.\n";
    }

    // 5. Display All Courses
    void displayCourses() {
        if (head == NULL) {
            cout << "No courses available.\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->code << " (" << temp->name << ", " << temp->credits << " CH)  ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // 6. Count Total Courses
    int countCourses() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // 7. Concatenate Another Course List (Evening into Morning)
    void concatenate(CourseList& secondList) {
        if (head == NULL) {
            head = secondList.head;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = secondList.head;
        }
        secondList.head = NULL; // Clear second list head to avoid double references
        cout << "Lists concatenated successfully!\n";
    }
};

int main() {
    CourseList morningList, eveningList;
    int choice, targetList, credits;
    string code, name;

    do {
        cout << "\n=== Course Management System ===\n";
        cout << "1. Add Course at Beginning\n";
        cout << "2. Add Course at End\n";
        cout << "3. Search Course\n";
        cout << "4. Delete Course\n";
        cout << "5. Display All Courses\n";
        cout << "6. Count Total Courses\n";
        cout << "7. Concatenate Evening List to Morning List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            case 2:
                cout << "Select List (1 for Morning, 2 for Evening): ";
                cin >> targetList;
                cout << "Enter Course Code, Name, Credit Hours: ";
                cin >> code >> name >> credits;

                if (targetList == 1) {
                    if (choice == 1) morningList.addBeginning(code, name, credits);
                    else morningList.addEnd(code, name, credits);
                } else {
                    if (choice == 1) eveningList.addBeginning(code, name, credits);
                    else eveningList.addEnd(code, name, credits);
                }
                break;

            case 3:
                cout << "Enter Course Code to search: ";
                cin >> code;
                cout << "-- Searching Morning List --\n";
                morningList.searchCourse(code);
                break;

            case 4:
                cout << "Enter Course Code to delete: ";
                cin >> code;
                morningList.deleteCourse(code);
                break;

            case 5:
                cout << "\nMorning Courses: ";
                morningList.displayCourses();
                cout << "Evening Courses: ";
                eveningList.displayCourses();
                break;

            case 6:
                cout << "Total Morning Courses: " << morningList.countCourses() << "\n";
                cout << "Total Evening Courses: " << eveningList.countCourses() << "\n";
                break;

            case 7:
                morningList.concatenate(eveningList);
                break;

            case 8:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 8);

    return 0;
}
