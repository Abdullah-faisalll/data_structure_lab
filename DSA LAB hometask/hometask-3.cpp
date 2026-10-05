// Abdullah Faisal 2502053 , Task number 3

#include <iostream>
#include <string>

using namespace std;

struct Node {
    int orderId;
    string customerName;
    string foodItem;
    Node* next;
};

class FoodOrderSystem {
private:
    Node* head;

public:
    FoodOrderSystem() {
        head = NULL;
    }

    // 1. Add regular order at end
    void addOrderEnd(int id, string name, string item) {
        Node* newNode = new Node();
        newNode->orderId = id;
        newNode->customerName = name;
        newNode->foodItem = item;
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
        cout << "Order " << id << " added successfully.\n";
    }

    // 5. Add urgent order at beginning
    void addUrgentOrder(int id, string name, string item) {
        Node* newNode = new Node();
        newNode->orderId = id;
        newNode->customerName = name;
        newNode->foodItem = item;
        newNode->next = head;
        head = newNode;
        cout << "Urgent Order " << id << " received and added at top.\n";
    }

    // 2 & 6. Display pending orders
    void displayOrders() {
        if (head == NULL) {
            cout << "No pending orders.\n";
            return;
        }

        cout << "\nPending Orders: ";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->orderId;
            if (temp->next != NULL) cout << " -> ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // 3. Search order by ID
    void searchOrder(int id) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->orderId == id) {
                cout << "Order Found! ID: " << temp->orderId 
                     << ", Customer: " << temp->customerName 
                     << ", Item: " << temp->foodItem << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Order " << id << " not found.\n";
    }

    // 4. Remove order after delivery
    void removeOrder(int id) {
        if (head == NULL) {
            cout << "No orders to deliver.\n";
            return;
        }

        if (head->orderId == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Order " << id << " delivered.\n";
            return;
        }

        Node* current = head;
        Node* prev = NULL;

        while (current != NULL && current->orderId != id) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Order " << id << " not found.\n";
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Order " << id << " delivered.\n";
    }
};

int main() {
    FoodOrderSystem system;
    int choice, id;
    string name, item;

    do {
        cout << "\n--- Food Delivery Order System ---\n";
        cout << "1. Add Regular Order (End)\n";
        cout << "2. Add Urgent Order (Beginning)\n";
        cout << "3. Display Pending Orders\n";
        cout << "4. Search Order\n";
        cout << "5. Deliver (Remove) Order\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Order ID, Customer Name, Food Item: ";
                cin >> id >> name >> item;
                system.addOrderEnd(id, name, item);
                break;
            case 2:
                cout << "Enter Urgent Order ID, Customer Name, Food Item: ";
                cin >> id >> name >> item;
                system.addUrgentOrder(id, name, item);
                break;
            case 3:
                system.displayOrders();
                break;
            case 4:
                cout << "Enter Order ID to search: ";
                cin >> id;
                system.searchOrder(id);
                break;
            case 5:
                cout << "Enter Order ID to mark delivered: ";
                cin >> id;
                system.removeOrder(id);
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
