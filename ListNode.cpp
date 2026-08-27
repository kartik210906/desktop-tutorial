#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int val){
            data=val;
            next=NULL;
        }
};
class List{
    Node* head=NULL;
    public:
    void push_front(int val){
        Node* newNode=new Node(val);
        if (head==NULL){
            head=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }
    void push_end(int val){
        Node* temp=head;
        Node* newNode=new Node(val);
        if (head==NULL){
            head=newNode;
        }else{
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    void push_pos(int val,int pos){
        if (pos==1) push_front(val);
        else if (pos==length()+1) push_end(val);
        else{
            Node* newNode=new Node(val);
            Node* temp=head;
            int count=1;
            while (count!=pos-1){
                temp=temp->next;
                count++;
            }
            Node* t=temp->next;
            temp->next=newNode;
            newNode->next=t;
        }
    }
    int length (){
        Node* temp=head;
        int l=0;
        while(temp!=NULL){
            temp=temp->next;
            l++;
        }
        return l;
    }
    void displayList(){
        Node* temp=head;
        if (head==NULL){
            cout<<"List Is Empty"<<endl;
            return;
            }
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void search(int val){
        Node* temp=head;
        if (head==NULL) 
            cout << "Empty List"<<endl;
        else{
            while(temp!=NULL){
                if (temp->data==val){
                    cout<<"Element "<<val<<" Found !"<<endl;
                    break;
                }
                temp=temp->next;
            }
            if(temp==NULL){
                cout<<"Element "<<val<<" Not Found !"<<endl;
            }
        }
    }
    void del_front(){
        if (head==NULL) cout<<"List Empty !!"<<endl;
        else{
            Node* temp=head;
            head=temp->next;
            delete temp;
        }
    }
    void del_end(){
        if (head==NULL) cout<<"List Empty !!"<<endl;
        else{
            Node* temp=head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            Node* t=temp->next;
            temp->next=NULL;
            delete t;
        }
    }
    void del_pos(int pos){
        if (pos==1) del_front();
        else if (pos==length()+1) del_end();
        else{
            Node* temp=head;
            int count=1;
            while(count!=pos-1){
                temp=temp->next;
                count++;
            }
            Node* t=temp->next;
            temp->next=t->next;
            delete t;
        }
    }

};
int main (){
    int choice,val,pos;
    List l;
    do{
        cout<<"----------------------OPERATIONS----------------------"<<endl;
        cout<<"1.Insert at Front\t\t2.Insert at Last"<<endl;
        cout<<"3.Insert at Postion\t\t4.Delete at Front"<<endl;
        cout<<"5.Delete at last\t\t6.Delete at Position "<<endl;
        cout<<"7.Display List\t\t\t8.Search Element"<<endl;
        cout<<"9.Length Of list\t\t0.Exit"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<"Enter Your Choice :\n";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter Value To insert at front : ";
                cin>>val;
                l.push_front(val);
                cout<<"List After Insertion :";
                l.displayList();
                cout<<endl;
                break;
            case 2:
                cout<<"Enter Value To insert at Last : ";
                cin>>val;
                l.push_end(val);
                cout<<"List After Insertion :";
                l.displayList();
                cout<<endl;
                break;
            case 3:
                cout<<"Enter Postion : ";
                cin>>pos;
                cout<<"Enter Value To insert at Postion : ";
                cin>>val;
                l.push_pos(pos,val);
                cout<<"List After Insertion :";
                l.displayList();
                cout<<endl;
                break;
            case 4:
                l.del_front();
                cout<<"List After Deletion :";
                l.displayList();
                cout<<endl;
                break;
            case 5:
                l.del_end();
                cout<<"List After Deletion :";
                l.displayList();
                cout<<endl;
                break;
            case 6:
                cout<<"Enter position or index u want to delete : ";
                cin>>pos;
                l.del_pos(pos);
                cout<<"List After Deletion :";
                l.displayList();
                cout<<endl;
                break;
            case 7:
                cout<<"Current list is : ";
                l.displayList();
                cout<<endl;
                break;
            case 8:
                cout<<"Enter Value u want to search : ";
                cin>>val;
                l.search(val);
                cout<<endl;
                break;
            case 9:
                cout<<"Length of list is  : "<<l.length()<<endl;
                cout<<endl;
                break;
            default:
                cout<<"Invalid Choice !!"<<endl;
        }
    }while(choice!=0);
}