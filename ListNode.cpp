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
private:

    ListNode* head;

public:

    LinkedList() {
        head = nullptr;
    }

    void insertBeginning(int value) {

        ListNode* newNode = new ListNode(value);

        newNode->next = head;
        head = newNode;

        cout << "Node inserted at beginning.\n";
    }

    void insertEnd(int value) {

        ListNode* newNode = new ListNode(value);

        if (head == nullptr) {
            head = newNode;
            cout << "Node inserted at end.\n";
            return;
        }

        ListNode* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;

        cout << "Node inserted at end.\n";
    }
    void insertPosition(int value, int position) {

        if (position <= 0) {
            cout << "Invalid position.\n";
            return;
        }

        if (position == 1) {
            insertBeginning(value);
            return;
        }

        ListNode* temp = head;

        for (int i = 1; i < position - 1; i++) {

            if (temp == nullptr) {
                cout << "Invalid position.\n";
                return;
            }

            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position.\n";
            return;
        }

        ListNode* newNode = new ListNode(value);

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Node inserted at position "
             << position << ".\n";
    }


    // ================= DELETION =================

    // Delete from beginning
    void deleteBeginning() {

        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        ListNode* temp = head;

        head = head->next;

        delete temp;

        cout << "First node deleted.\n";
    }


    // Delete from end
    void deleteEnd() {

        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        // Only one node
        if (head->next == nullptr) {

            delete head;
            head = nullptr;

            cout << "Last node deleted.\n";
            return;
        }

        ListNode* temp = head;

        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;

        cout << "Last node deleted.\n";
    }


    // Delete from specific position
    void deletePosition(int position) {

        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (position <= 0) {
            cout << "Invalid position.\n";
            return;
        }

        if (position == 1) {
            deleteBeginning();
            return;
        }

        ListNode* temp = head;

        for (int i = 1; i < position - 1; i++) {

            if (temp == nullptr) {
                cout << "Invalid position.\n";
                return;
            }

            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Invalid position.\n";
            return;
        }

        ListNode* nodeToDelete = temp->next;

        temp->next = nodeToDelete->next;

        delete nodeToDelete;

        cout << "Node at position "
             << position << " deleted.\n";
    }


    // Delete a node by value
    void deleteByValue(int value) {

        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        // If first node contains the value
        if (head->data == value) {

            ListNode* temp = head;

            head = head->next;

            delete temp;

            cout << "Node deleted.\n";
            return;
        }

        ListNode* temp = head;

        while (temp->next != nullptr &&
               temp->next->data != value) {

            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value not found.\n";
            return;
        }

        ListNode* nodeToDelete = temp->next;

        temp->next = nodeToDelete->next;

        delete nodeToDelete;

        cout << "Node deleted.\n";
    }


    // ================= SEARCH =================

    void search(int value) {

        ListNode* temp = head;

        int position = 1;

        while (temp != nullptr) {

            if (temp->data == value) {

                cout << "Value found at position "
                     << position << ".\n";

                return;
            }

            temp = temp->next;
            position++;
        }

        cout << "Value not found.\n";
    }


    // ================= DISPLAY =================

    void display() {

        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        ListNode* temp = head;

        cout << "\nHEAD -> ";

        while (temp != nullptr) {

            cout << temp->data << " -> ";

            temp = temp->next;
        }

        cout << "NULL\n";
    }


    // ================= COUNT =================

    void countNodes() {

        int count = 0;

        ListNode* temp = head;

        while (temp != nullptr) {

            count++;

            temp = temp->next;
        }

        cout << "Total nodes = " << count << endl;
    }


    // ================= REVERSE =================

    void reverse() {

        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        ListNode* previous = nullptr;
        ListNode* current = head;

        while (current != nullptr) {

            ListNode* nextNode = current->next;

            current->next = previous;

            previous = current;
            current = nextNode;
        }

        head = previous;

        cout << "List reversed successfully.\n";
    }


    // ================= UPDATE =================

    void update(int position, int value) {

        if (position <= 0) {
            cout << "Invalid position.\n";
            return;
        }

        ListNode* temp = head;

        for (int i = 1; i < position; i++) {

            if (temp == nullptr) {
                cout << "Invalid position.\n";
                return;
            }

            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position.\n";
            return;
        }

        temp->data = value;

        cout << "Node updated successfully.\n";
    }


    // ================= FIND LENGTH =================

    int length() {

        int count = 0;

        ListNode* temp = head;

        while (temp != nullptr) {

            count++;
            temp = temp->next;
        }

        return count;
    }


    // ================= FIRST ELEMENT =================

    void firstElement() {

        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        cout << "First element = "
             << head->data << endl;
    }


    // ================= LAST ELEMENT =================

    void lastElement() {

        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        ListNode* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        cout << "Last element = "
             << temp->data << endl;
    }


    // ================= CLEAR LIST =================

    void clearList() {

        while (head != nullptr) {

            ListNode* temp = head;

            head = head->next;

            delete temp;
        }

        cout << "List cleared successfully.\n";
    }


    // ================= CHECK EMPTY =================

    void isEmpty() {

        if (head == nullptr)
            cout << "List is empty.\n";
        else
            cout << "List is not empty.\n";
    }
};


// ================= MAIN =================

int main() {

    LinkedList list;

    int choice;
    int value;
    int position;

    do {

        cout << "\n\n";
        cout << "=====================================\n";
        cout << "       SINGLY LINKED LIST MENU\n";
        cout << "=====================================\n";

        cout << "1.  Insert at Beginning\n";
        cout << "2.  Insert at End\n";
        cout << "3.  Insert at Position\n";

        cout << "4.  Delete from Beginning\n";
        cout << "5.  Delete from End\n";
        cout << "6.  Delete from Position\n";
        cout << "7.  Delete by Value\n";

        cout << "8.  Search\n";
        cout << "9.  Display\n";
        cout << "10. Count Nodes\n";
        cout << "11. Reverse\n";
        cout << "12. Update Node\n";
        cout << "13. Find Length\n";
        cout << "14. First Element\n";
        cout << "15. Last Element\n";
        cout << "16. Check Empty\n";
        cout << "17. Clear List\n";

        cout << "0.  Exit\n";

        cout << "=====================================\n";

        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice) {

        // INSERT BEGINNING
        case 1:

            cout << "Enter value: ";
            cin >> value;

            list.insertBeginning(value);

            break;


        // INSERT END
        case 2:

            cout << "Enter value: ";
            cin >> value;

            list.insertEnd(value);

            break;


        // INSERT POSITION
        case 3:

            cout << "Enter value: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            list.insertPosition(value, position);

            break;


        // DELETE BEGINNING
        case 4:

            list.deleteBeginning();

            break;


        // DELETE END
        case 5:

            list.deleteEnd();

            break;


        // DELETE POSITION
        case 6:

            cout << "Enter position: ";
            cin >> position;

            list.deletePosition(position);

            break;


        // DELETE VALUE
        case 7:

            cout << "Enter value: ";
            cin >> value;

            list.deleteByValue(value);

            break;


        // SEARCH
        case 8:

            cout << "Enter value to search: ";
            cin >> value;

            list.search(value);

            break;


        // DISPLAY
        case 9:

            list.display();

            break;


        // COUNT
        case 10:

            list.countNodes();

            break;


        // REVERSE
        case 11:

            list.reverse();

            break;


        // UPDATE
        case 12:

            cout << "Enter position: ";
            cin >> position;

            cout << "Enter new value: ";
            cin >> value;

            list.update(position, value);

            break;


        // LENGTH
        case 13:

            cout << "Length = "
                 << list.length()
                 << endl;

            break;


        // FIRST ELEMENT
        case 14:

            list.firstElement();

            break;


        // LAST ELEMENT
        case 15:

            list.lastElement();

            break;


        // CHECK EMPTY
        case 16:

            list.isEmpty();

            break;


        // CLEAR LIST
        case 17:

            list.clearList();

            break;


        // EXIT
        case 0:

            cout << "Program terminated.\n";

            break;


        default:

            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);


    return 0;
}