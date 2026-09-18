#include <iostream>
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
        
        void insertEnd(int i){
            
            Node* newNode=new Node(i);
            if(tail==NULL){
                head=newNode;
                tail=newNode;
            }
            else{
                tail->next=newNode;
                newNode->prv=tail;
                tail=newNode;
            }

        }

        void delEnd(){
            Node* temp=tail;
            if(tail==NULL){
                cout<<"List is Empty !"<<endl;
                return;
            }else if(head==tail){
                head=NULL;
                tail=NULL;
            }else{
                tail=tail->prv;
                tail->next=NULL;
            }
            delete temp;
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
    DLL l1,l2,merged;
    int choice,n,val,choice2;
    do{
        cout<<"--------------------------------"<<endl;
        cout<<"1.Enter n number of marks :"<<endl;
        cout<<"2.Enter marks at end of list :"<<endl;
        cout<<"3.Delete marks at end of list :"<<endl;
        cout<<"4.Print List Of marks Forward :"<<endl;
        cout<<"5.Print List Of marks Backward :"<<endl;
        cout<<"6.Sort List Of Marks :"<<endl;
        cout<<"7.Merge Sort Lists Of Marks :"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"--------------------------------"<<endl;

        cin>>choice;
        
        switch(choice){
            case 1:
                cout<<"\nList u want to do operation on :"<<endl;
                cout<<"1. List 1"<<endl;
                cout<<"2. List 2"<<endl;
                cout<<"3. Goto main menu"<<endl;
                cin>>choice2;
                if (choice2>=3){
                    break;
                }

                cout<<"\nEnter No.Of Marks u want to enter: "<<endl;
                cin>>n;
                cout<<"Enter "<<n<<" Values :"<<endl;

                for(int i=0;i<n;i++){
                    cin>>val;
                    if (choice2==1){
                        l1.insertEnd(val);
                    }else if(choice2==2){
                        l2.insertEnd(val);
                    }
                }
                if (choice2==1){
                        cout<<"After Inseration :"<<endl;
                        l1.printForward();

                    }else if(choice2==2){
                        cout<<"After Inseration :"<<endl;
                        l2.printForward();
                    }
                break;
            
            case 2:
                cout<<"\nList u want to do operation on :"<<endl;
                cout<<"1. List 1"<<endl;
                cout<<"2. List 2"<<endl;
                cout<<"3. Goto main menu"<<endl;
                cin>>choice2;
                
                if (choice2==1){
                    cout<<"Enter marks to Enter at end :"<<endl;
                    cin>>val;
                    l1.insertEnd(val);
                    cout<<"After Inseration :"<<endl;
                    l1.printForward();
                }
                else if (choice2==2){
                    cout<<"Enter marks to Enter at end :"<<endl;
                    cin>>val;
                    l2.insertEnd(val);
                    cout<<"After Inseration :"<<endl;
                    l2.printForward();
                }
                
                break;
            
            case 3:
                cout<<"\nList u want to do operation on :"<<endl;
                cout<<"1. List 1"<<endl;
                cout<<"2. List 2"<<endl;
                cout<<"3. Goto main menu"<<endl;
                cin>>choice2;
                if (choice2==1){
                    l1.delEnd();
                }else if(choice2==2){
                    l2.delEnd();
                }else{
                    cout<<"Invalid Choice "<<endl;
                }
                break;
            case 4:
                cout<<"\nList u want to do operation on :"<<endl;
                cout<<"1. List 1"<<endl;
                cout<<"2. List 2"<<endl;
                cout<<"3. Goto main menu"<<endl;
                cin>>choice2;
                
                if (choice2==1){
                    l1.printForward();
                }
                else if (choice2==2){
                    l2.printForward();
                }
                
                break;
                
            case 5:
                cout<<"\nList u want to do operation on :"<<endl;
                cout<<"1. List 1"<<endl;
                cout<<"2. List 2"<<endl;
                cout<<"3. Goto main menu"<<endl;
                cin>>choice2;
                
                if (choice2==1){
                    l1.printBackward();
                }
                else if (choice2==2){
                    l2.printBackward();
                }
                break;
            
            case 6:
                cout<<"List u want to do operation on :"<<endl;
                cout<<"1. List 1"<<endl;
                cout<<"2. List 2"<<endl;
                cout<<"3. Goto main menu"<<endl;
                cin>>choice2;
                
                if (choice2==1){
                    l1.buublesort();
                }
                else if (choice2==2){
                    l2.buublesort();
                }
                break;
            case 7:
                l1.buublesort();
                l2.buublesort();
                merged=DLL::merge(l1,l2);
                cout<<"List after Merging :"<<endl;
                merged.printForward();
                break;
            default:
                cout<<"Invalid Choice !!"<<endl;

        }


    }while(choice!=0);
    
}