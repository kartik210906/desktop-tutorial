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
    DLL l1,l2;
    l1.insertEnd(1);
    l1.insertEnd(78);
    l1.insertEnd(99);
    l2.insertEnd(2);
    l2.insertEnd(4);
    l2.insertEnd(9);
    DLL l3= DLL::merge(l1,l2);
    l3.printForward();
}