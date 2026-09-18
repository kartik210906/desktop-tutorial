#include <iostream>
using namespace std;
class  Node{
    public:
        int mark;
        string name;
        string subject;
        string prn;
        Node* next;
        Node* prv;
        Node(int i,string n,string s,string p){
            mark=i;
            name=n;
            subject=s;
            prn=p;
            next=NULL;
            prv=NULL;
        }
};
class DLL
{

    Node* head=NULL;
    Node* tail=NULL;
    public:
        
        void insertEnd(int i,string n,string s,string p){
            
            Node* newNode=new Node(i,n,s,p);
            if(tail==NULL){
                head=newNode;
                tail=newNode;
            }else{
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
                    if(temp->mark>(temp->next)->mark){
                        swap(temp->mark,(temp->next)->mark);
                        swap(temp->name,(temp->next)->name);
                        swap(temp->subject,(temp->next)->subject);
                        swap(temp->prn,(temp->next)->prn);
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
                if(temp1->mark<temp2->mark){
                    res.insertEnd(temp1->mark,temp1->name,temp1->subject,temp1->prn);
                    temp1=temp1->next;
                }else{
                    res.insertEnd(temp2->mark,temp2->name,temp2->subject,temp2->prn);
                    temp2=temp2->next;
                }
            }

            while(temp1!=NULL){
                res.insertEnd(temp1->mark,temp1->name,temp1->subject,temp1->prn);
                temp1=temp1->next;
            }
            
            while(temp2!=NULL){
                res.insertEnd(temp2->mark,temp2->name,temp2->subject,temp2->prn);
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

            while(temp!=NULL){
                cout<<temp->name<<endl;
                cout<<temp->subject<<endl;
                cout<<temp->prn<<endl;
                cout<<temp->mark<<endl;
                cout<<endl;
                temp=temp->next;
            }
        }

        void printBackward(){
            Node* temp=tail;
            if(!temp){
                cout<<"List is empty !"<<endl;
                return;
            }

            while(temp!=NULL){
                cout<<temp->name<<endl;
                cout<<temp->subject<<endl;
                cout<<temp->prn<<endl;
                cout<<temp->mark<<endl;
                cout<<endl;
                temp=temp->prv;
            }
        }


};
int main(){
    DLL l1,l2,merged;
    int choice,n,choice2;
    int marks;
    string prn;
    string name,subject;
    do{
        cout<<"===============MENU==============="<<endl;
        cout<<"1.Enter N number of entries"<<endl;
        cout<<"2.Enter marks at end of list"<<endl;
        cout<<"3.Delete marks at end of list"<<endl;
        cout<<"4.Print List Of marks Forward"<<endl;
        cout<<"5.Print List Of marks Backward"<<endl;
        cout<<"6.Sort List Of Marks"<<endl;
        cout<<"7.Merge Sort Lists Of Marks"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"=================================="<<endl;

        cout<<"Enter Choice :"<<endl;
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
                    cout<<"\nEnter Student Name :";
                    cin>>name;
                    cout<<"Enter Subject :";
                    cin>>subject;
                    cout<<"Enter Student PRN :";
                    cin>>prn;
                    cout<<"Enter Student marks :";
                    cin>>marks;
                    if (choice2==1){
                        l1.insertEnd(marks,name,subject,prn);
                    }else if(choice2==2){
                        l2.insertEnd(marks,name,subject,prn);
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
                    cout<<"\nEnter Student Name :";
                    cin>>name;
                    cout<<"Enter Subject :";
                    cin>>subject;
                    cout<<"Enter Student PRN :";
                    cin>>prn;
                    cout<<"Enter Student marks :";
                    cin>>marks;
                    l1.insertEnd(marks,name,subject,prn);

                    cout<<"After Inseration :"<<endl;
                    l1.printForward();
                }
                else if (choice2==2){
                    cout<<"\nEnter Student Name :";
                    cin>>name;
                    cout<<"Enter Subject :";
                    cin>>subject;
                    cout<<"Enter Student PRN :";
                    cin>>prn;
                    cout<<"Enter Student marks :";
                    cin>>marks;
                    l2.insertEnd(marks,name,subject,prn);
                    
                    cout<<"\nAfter Inseration :"<<endl;
                    cout<<endl;
                    l2.printForward();
                }else{
                    cout<<"Invalid Choice "<<endl;
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
                }else{
                    cout<<"Invalid Choice "<<endl;
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
                }else{
                    cout<<"Invalid Choice "<<endl;
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
                }else{
                    cout<<"Invalid Choice "<<endl;
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
/*
OUTPUT:
===============MENU===============
1.Enter N number of entries
2.Enter marks at end of list
3.Delete marks at end of list
4.Print List Of marks Forward
5.Print List Of marks Backward
6.Sort List Of Marks
7.Merge Sort Lists Of Marks
0.Exit
==================================
Enter Choice :
1

List u want to do operation on :
1. List 1
2. List 2
3. Goto main menu
1

Enter No.Of Marks u want to enter: 
2
Enter 2 Values :

Enter Student Name :kartik
Enter Subject :math
Enter Student PRN :202501040012
Enter Student marks :95

Enter Student Name :Harsh
Enter Subject :Math
Enter Student PRN :202501040011
Enter Student marks :96
After Inseration :
kartik
math
202501040012
95

Harsh
Math
202501040011
96

===============MENU===============
1.Enter N number of entries
2.Enter marks at end of list
3.Delete marks at end of list
4.Print List Of marks Forward
5.Print List Of marks Backward
6.Sort List Of Marks
7.Merge Sort Lists Of Marks
0.Exit
==================================
Enter Choice :
1

List u want to do operation on :
1. List 1
2. List 2
3. Goto main menu
2

Enter No.Of Marks u want to enter: 
2
Enter 2 Values :

Enter Student Name :siddesh
Enter Subject :math
Enter Student PRN :202501040009
Enter Student marks :97

Enter Student Name :sujal
Enter Subject :science
Enter Student PRN :202501040028
Enter Student marks :98
After Inseration :
siddesh
math
202501040009
97

sujal
science
202501040028
98

===============MENU===============
1.Enter N number of entries
2.Enter marks at end of list
3.Delete marks at end of list
4.Print List Of marks Forward
5.Print List Of marks Backward
6.Sort List Of Marks
7.Merge Sort Lists Of Marks
0.Exit
==================================
Enter Choice :
2

List u want to do operation on :
1. List 1
2. List 2
3. Goto main menu
1

Enter Student Name :soham
Enter Subject :OOPS
Enter Student PRN :202501040028
Enter Student marks :96
After Inseration :
kartik
math
202501040012
95

Harsh
Math
202501040011
96

soham
OOPS
202501040028
96

===============MENU===============
1.Enter N number of entries
2.Enter marks at end of list
3.Delete marks at end of list
4.Print List Of marks Forward
5.Print List Of marks Backward
6.Sort List Of Marks
7.Merge Sort Lists Of Marks
0.Exit
==================================
Enter Choice :
2

List u want to do operation on :
1. List 1
2. List 2
3. Goto main menu
2

Enter Student Name :Aditya
Enter Subject :DSA
Enter Student PRN :202501040013
Enter Student marks :98

After Inseration :

siddesh
math
202501040009
97

sujal
science
202501040028
98

Aditya
DSA
202501040013
98

===============MENU===============
1.Enter N number of entries
2.Enter marks at end of list
3.Delete marks at end of list
4.Print List Of marks Forward
5.Print List Of marks Backward
6.Sort List Of Marks
7.Merge Sort Lists Of Marks
0.Exit
==================================
Enter Choice :
4

List u want to do operation on :
1. List 1
2. List 2
3. Goto main menu
1
kartik
math
202501040012
95

Harsh
Math
202501040011
96

soham
OOPS
202501040028
96

===============MENU===============
1.Enter N number of entries
2.Enter marks at end of list
3.Delete marks at end of list
4.Print List Of marks Forward
5.Print List Of marks Backward
6.Sort List Of Marks
7.Merge Sort Lists Of Marks
0.Exit
==================================
Enter Choice :
5

List u want to do operation on :
1. List 1
2. List 2
3. Goto main menu
2
Aditya
DSA
202501040013
98

sujal
science
202501040028
98

siddesh
math
202501040009
97

===============MENU===============
1.Enter N number of entries
2.Enter marks at end of list
3.Delete marks at end of list
4.Print List Of marks Forward
5.Print List Of marks Backward
6.Sort List Of Marks
7.Merge Sort Lists Of Marks
0.Exit
==================================
Enter Choice :
4

List u want to do operation on :
1. List 1
2. List 2
3. Goto main menu
2
siddesh
math
202501040009
97

sujal
science
202501040028
98

Aditya
DSA
202501040013
98

===============MENU===============
1.Enter N number of entries
2.Enter marks at end of list
3.Delete marks at end of list
4.Print List Of marks Forward
5.Print List Of marks Backward
6.Sort List Of Marks
7.Merge Sort Lists Of Marks
0.Exit
==================================
Enter Choice :
6
List u want to do operation on :
1. List 1
2. List 2
3. Goto main menu
1
List after bubble sort : 
kartik
math
202501040012
95

Harsh
Math
202501040011
96

soham
OOPS
202501040028
96

===============MENU===============
1.Enter N number of entries
2.Enter marks at end of list
3.Delete marks at end of list
4.Print List Of marks Forward
5.Print List Of marks Backward
6.Sort List Of Marks
7.Merge Sort Lists Of Marks
0.Exit
==================================
Enter Choice :
7
List after bubble sort : 
kartik
math
202501040012
95

Harsh
Math
202501040011
96

soham
OOPS
202501040028
96

List after bubble sort : 
siddesh
math
202501040009
97

sujal
science
202501040028
98

Aditya
DSA
202501040013
98

List after Merging :
kartik
math
202501040012
95

Harsh
Math
202501040011
96

soham
OOPS
202501040028
96

siddesh
math
202501040009
97

sujal
science
202501040028
98

Aditya
DSA
202501040013
98

===============MENU===============
1.Enter N number of entries
2.Enter marks at end of list
3.Delete marks at end of list
4.Print List Of marks Forward
5.Print List Of marks Backward
6.Sort List Of Marks
7.Merge Sort Lists Of Marks
0.Exit
==================================
Enter Choice :
0
Invalid Choice !!
*/