#include <iostream>
#include<string>
using namespace std;
class  Node{
    public:
        int data;
        Node* next;
        Node* prv;
        Node(int i){
            data=i;
            next=NULL;
            prv=NULL;
        }
};
class DLL
{

    Node* head=NULL;
    Node* tail=NULL;
    public:
        void insertFront(int i){
            
            Node* newNode=new Node(i);
            
            if(!head && !tail){
                head=newNode;
                tail=newNode;
                newNode->next=tail;
                newNode->prv=NULL;
            }
            else{

                newNode->next=head;
                head->prv=newNode;
                head=newNode;
                
            }

            cout<<"List after insertion at front : "<<endl;
            printForward();
        }

        
        void insertEnd(int i){
            
            Node* newNode=new Node(i);
            if(tail==NULL){
                insertFront(i);
            }
            else{
                tail->next=newNode;
                newNode->prv=tail;
                tail=newNode;
            }

            cout<<"List after insertion at end : "<<endl;
            printForward();
        }

        void delFront(){
            if(head==NULL){
                cout<<"List Is Empty !"<<endl;
            }else{

                Node* temp=head;
                head=head->next;
                head->prv=NULL;
                delete temp;

            }
            cout<<"List after deletion at front : "<<endl;
            printForward();
        }
        
        void delEnd(){
            Node* temp=tail;
            if(tail==NULL){
                cout<<"List is Empty !"<<endl;
            }else{

                tail=tail->prv;
                tail->next=NULL;
                delete temp;
            
            }
            cout<<"List after deletion at end : "<<endl;
            printForward();
        }

        void buublesort(){
            if(head==NULL) return;

            Node* temp;
            bool swapped;
            do{
                swapped=false;
                temp=head;
                while(temp->next !=NULL){
                    if(temp->data>(temp->next)->data){
                        swap(temp->data,(temp->next)->data);
                        swapped=true;
                    }
                    temp=temp->next;
                }
            }while(swapped);
            cout<<"List after bubble sort : "<<endl;
            printForward();
        }

        static DLL merge(const DLL& l1,const DLL& l2){

            DLL res;
            Node* temp1=l1.head;
            Node* temp2=l2.head;

            while(temp1!=NULL && temp2!=NULL){
                if(temp1->data<temp2->data){
                    res.insertEnd(temp1->data);
                    temp1=temp1->next;
                }else{
                    res.insertEnd(temp2->data);
                    temp2=temp2->next;
                }
            }

            while(temp1!=NULL){
                res.insertEnd(temp1->data);
                temp1=temp1->next;
            }
            
            while(temp2!=NULL){
                res.insertEnd(temp2->data);
                temp2=temp2->next;
            }

            return res;

        }

        void printForward(){
            Node* temp=head;
            if(!temp){
                cout<<"List is empty !"<<endl;
                return;
            }

            while(temp!=tail){
                cout<<temp->data<<"=>";
                temp=temp->next;
            }
            cout<<temp->data<<endl;
        }

        void printBackward(){
            Node* temp=tail;
            if(!temp){
                cout<<"List is empty !"<<endl;
                return;
            }

            while(temp!=head){
                cout<<temp->data<<"=>";
                temp=temp->prv;
            }
            cout<<temp->data<<endl;
        }


};
int main(){
    int ch,ch1,val;
    DLL l1,l2,merged;
    do{
        cout<<"==============Main Menu=============="<<endl;
        cout<<"1. Insert At Front"<<endl;
        cout<<"2. Insert At End"<<endl;
        cout<<"3. Delete At Front"<<endl;
        cout<<"4. Delete At End"<<endl;
        cout<<"5. Print Forward"<<endl;
        cout<<"6. Print Backward"<<endl;
        cout<<"7. Bubble Sort"<<endl;
        cout<<"8. Merge Two Lists"<<endl;
        cout<<"9. Exit"<<endl;
        cout<<"====================================="<<endl;
        cout<<"Enter Your Choice : ";
        cin>>ch;

        switch(ch){
            case 1:
                cout<<"1. For List 1\n2. For List 2\n3. Go to Main menu"<<endl;
                cin>>ch1;

                if (ch1>=3) break;

                cout<<"Enter Val to Insert : ";
                cin>>val;

                if(ch1==1){
                    l1.insertFront(val);
                }else if(ch1==2){
                    l2.insertFront(val);
                }
                break;

            case 2:
                cout<<"1. For List 1\n2. For List 2\n3. Go to Main menu"<<endl;
                cin>>ch1;
                if (ch1>=3) break;

                cout<<"Enter Val to Insert : ";
                cin>>val;
                
                if(ch1==1){
                    l1.insertEnd(val);
                }else if(ch1==2){
                    l2.insertEnd(val);
                }
                break;
            case 3:
                cout<<"1. For List 1\n2. For List 2\n3. Go to Main menu"<<endl;
                cin>>ch1;
                if(ch1==1){
                    l1.delFront();
                }else if(ch1==2){
                    l2.delFront();
                }
                break;
            case 4:
                cout<<"1. For List 1\n2. For List 2\n3. Go to Main menu"<<endl;
                cin>>ch1;
                if(ch1==1){
                    l1.delEnd();
                }else if(ch1==2){
                    l2.delEnd();
                }
                break;
            case 5:
                cout<<"1. For List 1\n2. For List 2\n3. Go to Main menu"<<endl;
                cin>>ch1;
                if(ch1==1){
                    l1.printForward();
                }else if(ch1==2){
                    l2.printForward();
                }
                break;
            case 6:
                cout<<"1. For List 1\n2. For List 2\n3. Go to Main menu"<<endl;
                cin>>ch1;
                if(ch1==1){
                    l1.printBackward();
                }else if(ch1==2){
                    l2.printBackward();
                }
                break;
            case 7:
                cout<<"1. For List 1\n2. For List 2\n3. Go to Main menu"<<endl;
                cin>>ch1;
                if(ch1==1){
                    l1.buublesort();
                }else if(ch1==2){
                    l2.buublesort();
                }
                break;
            case 8:
                l1.buublesort();
                l2.buublesort();
                merged= DLL::merge(l1,l2);
                cout<<"Merged List : "<<endl;
                merged.printForward();
                break;
            default:
                cout<<"Invalid Choice !!"<<endl;
        }

    }while(ch!=9);
    
}