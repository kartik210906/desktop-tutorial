#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class LinkedList{
    public:
    Node* head=NULL;
    void insert(int val){
        Node* newNode = new Node(val); //new used here to allocate memory for new node
        if(head == NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void deleteNode(int val){
        if(head == NULL) return;
        if(head->data == val){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL && temp->next->data != val){
            temp = temp->next;
        }
        if(temp->next == NULL) return;
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;

        delete nodeToDelete; //delete used here to free memory
    }
};
int main() {
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    cout << "Linked List after insertion: ";
    ll.display();
    ll.deleteNode(2);
    cout << "Linked List after deletion of 2: ";
    ll.display();
    return 0;
}
/*
    OUTPUT :
    Linked List after insertion: 1 2 3 
    Linked List after deletion of 2: 1 3 
*/