#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
    ListNode* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertBeginning(int value) {
        ListNode* n = new ListNode(value);
        n->next = head;
        head = n;
    }

    void insertEnd(int value) {
        ListNode* n = new ListNode(value);

        if (head == nullptr) {
            head = n;
            return;
        }

        ListNode* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = n;
    }

    void insertPosition(int value, int pos) {
        if (pos == 1) {
            insertBeginning(value);
            return;
        }

        ListNode* temp = head;

        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Invalid position\n";
            return;
        }

        ListNode* n = new ListNode(value);
        n->next = temp->next;
        temp->next = n;
    }

    void deleteBeginning() {
        if (head == nullptr) {
            cout << "List empty\n";
            return;
        }

        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        if (head == nullptr) {
            cout << "List empty\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        ListNode* temp = head;

        while (temp->next->next != nullptr)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
    }

    void deletePosition(int pos) {
        if (head == nullptr) {
            cout << "List empty\n";
            return;
        }

        if (pos == 1) {
            deleteBeginning();
            return;
        }

        ListNode* temp = head;

        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Invalid position\n";
            return;
        }

        ListNode* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    // Search
    void search(int value) {
        ListNode* temp = head;
        int pos = 1;

        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }

        cout << "Not found\n";
    }

    // Display
    void display() {
        ListNode* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // Count
    void count() {
        int c = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            c++;
            temp = temp->next;
        }

        cout << "Nodes = " << c << endl;
    }

    // Reverse
    void reverse() {
        ListNode *prev = nullptr, *curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }
};

int main() {
    LinkedList list;
    int choice, value, pos;

    do {
        cout << "\n--- LINKED LIST ---\n";
        cout << "1. Insert Beginning\n";
        cout << "2. Insert End\n";
        cout << "3. Insert Position\n";
        cout << "4. Delete Beginning\n";
        cout << "5. Delete End\n";
        cout << "6. Delete Position\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Count\n";
        cout << "10. Reverse\n";
        cout << "0. Exit\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Value: ";
            cin >> value;
            list.insertBeginning(value);
            break;

        case 2:
            cout << "Value: ";
            cin >> value;
            list.insertEnd(value);
            break;

        case 3:
            cout << "Value and position: ";
            cin >> value >> pos;
            list.insertPosition(value, pos);
            break;

        case 4:
            list.deleteBeginning();
            break;

        case 5:
            list.deleteEnd();
            break;

        case 6:
            cout << "Position: ";
            cin >> pos;
            list.deletePosition(pos);
            break;

        case 7:
            cout << "Value: ";
            cin >> value;
            list.search(value);
            break;

        case 8:
            list.display();
            break;

        case 9:
            list.count();
            break;

        case 10:
            list.reverse();
            break;

        case 0:
            cout << "Exit\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}