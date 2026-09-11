#include <iostream>
using namespace std;
class Node{
    public:
        string name;
        string company_name;
        int salary;

        Node* next;

        Node(string n,string cn,int s){
            name=n;
            company_name=cn;
            salary=s;
            next=NULL;
        }
};
class List{
    Node* head=NULL;
    public:
    void push_front(string n,string cn,int s){
        Node* newNode=new Node(n,cn,s);
        if (head==NULL){
            head=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }
    void push_end(string n,string cn,int s){
        Node* temp=head;
        Node* newNode=new Node(n,cn,s);
        if (head==NULL){
            head=newNode;
        }else{
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    void push_pos(string n,string cn,int s,int pos){
        if (pos==1) push_front(n,cn,s);
        else if (pos==length()+1) push_end(n,cn,s);
        else{
            Node* newNode=new Node(n,cn,s);
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
            cout<<"\nName : "<<temp->name<<endl;
            cout<<"Company's Name : "<<temp->company_name<<endl;
            cout<<"Salary Offered : "<<temp->salary<<endl;
            cout<<"\n";
            temp=temp->next;
        }
    }
    void search(string n){
        Node* temp=head;
        if (head==NULL) 
            cout << "Empty List"<<endl;
        else{
            while(temp!=NULL){
                if (temp->name==n){
                    cout<<"Data of "<<n<<" Found !"<<endl;
                    break;
                }
                temp=temp->next;
            }
            if(temp==NULL){
                cout<<"Data of "<<n<<" Not Found !"<<endl;
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
        else if (pos==length()) del_end();
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
    void sort_list(){
        Node* temp=head;
        Node* t=head;
        if (head==NULL) cout<<"List Empty !!"<<endl;
        else{
            while(temp!=NULL){
                t=temp->next;
                while(t!=NULL){
                    if (temp->salary>t->salary){
                        swap(temp->name,t->name);
                        swap(temp->company_name,t->company_name);
                        swap(temp->salary,t->salary);
                    }
                    t=t->next;
                }
                temp=temp->next;
            }
        }
    }

};
int main (){
    int choice,s,pos;
    string n,cn;
    List l;
    do{
        cout<<"----------------------OPERATIONS----------------------"<<endl;
        cout<<"1.Insert at Front\t\t2.Insert at Last"<<endl;
        cout<<"3.Insert at Postion\t\t4.Delete at Front"<<endl;
        cout<<"5.Delete at last\t\t6.Delete at Position "<<endl;
        cout<<"7.Display List\t\t\t8.Search Element"<<endl;
        cout<<"9.Length Of list\t\t10.Sort List"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<"Enter Your Choice :\n";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter DATA To insert at front : \n";
                cout<<"Name : ";cin>>n;
                cout<<"Company Name : ";cin>>cn;
                cout<<"Salary Offered : ";cin>>s;
                l.push_front(n,cn,s);
                cout<<"\nList After Insertion :";
                l.displayList();
                cout<<endl;
                break;
            case 2:
                cout<<"Enter DATA To insert at Last : \n";
                cout<<"Name : ";cin>>n;
                cout<<"Company Name : ";cin>>cn;
                cout<<"Salary Offered : ";cin>>s;
                l.push_end(n,cn,s);
                cout<<"\nList After Insertion :";
                l.displayList();
                cout<<endl;
                break;
            case 3:
                cout<<"Enter Postion : ";
                cin>>pos;
                cout<<"Enter DATA To insert at Last : \n";
                cout<<"Name : ";cin>>n;
                cout<<"Company Name : ";cin>>cn;
                cout<<"Salary Offered : ";cin>>s;
                l.push_pos(n,cn,s,pos);
                cout<<"\nList After Insertion :";
                l.displayList();
                cout<<endl;
                break;
            case 4:
                l.del_front();
                cout<<"\nList After Deletion :";
                l.displayList();
                cout<<endl;
                break;
            case 5:
                l.del_end();
                cout<<"\nList After Deletion :";
                l.displayList();
                cout<<endl;
                break;
            case 6:
                cout<<"Enter position or index u want to delete : ";
                cin>>pos;
                l.del_pos(pos);
                cout<<"\nList After Deletion :";
                l.displayList();
                cout<<endl;
                break;
            case 7:
                cout<<"\nCurrent list is : ";
                l.displayList();
                cout<<endl;
                break;
            case 8:
                cout<<"\nEnter Name of std u want to search : ";
                cin>>n;
                l.search(n);
                cout<<endl;
                break;
            case 9:
                cout<<"Length of list is  : "<<l.length()<<endl;
                cout<<endl;
                break;
            case 10:
                l.sort_list();
                cout<<"\nList After Sorting :";
                l.displayList();
                cout<<endl;
                break;
            case 0:
                cout<<"Exiting Program !!"<<endl;
                break;
            default:
                cout<<"Invalid Choice !!"<<endl;
        }
        cin.ignore();
    }while(choice!=0);
}
/*
OUTPUT FOR PROGRAMM (NOT SHOWN EVERY CASE TO MAINTAIN SPACE) :
----------------------OPERATIONS----------------------
1.Insert at Front               2.Insert at Last
3.Insert at Postion             4.Delete at Front
5.Delete at last                6.Delete at Position 
7.Display List                  8.Search Element
9.Length Of list                10.Sort List
0.Exit
------------------------------------------------------
Enter Your Choice :
1
Enter DATA To insert at front : 
Name : kartik
Company Name : cisco
Salary Offered : 123

List After Insertion :
Name : kartik
Company's Name : cisco
Salary Offered : 123


----------------------OPERATIONS----------------------
1.Insert at Front               2.Insert at Last
3.Insert at Postion             4.Delete at Front
5.Delete at last                6.Delete at Position 
7.Display List                  8.Search Element
9.Length Of list                10.Sort List
0.Exit
------------------------------------------------------
Enter Your Choice :
2
Enter DATA To insert at Last : 
Name : harsh
Company Name : ibm
Salary Offered : 98

List After Insertion :
Name : kartik
Company's Name : cisco
Salary Offered : 123


Name : harsh
Company's Name : ibm
Salary Offered : 98


----------------------OPERATIONS----------------------
1.Insert at Front               2.Insert at Last
3.Insert at Postion             4.Delete at Front
5.Delete at last                6.Delete at Position 
7.Display List                  8.Search Element
9.Length Of list                10.Sort List
0.Exit
------------------------------------------------------
Enter Your Choice :
10

List After Sorting :
Name : harsh
Company's Name : ibm
Salary Offered : 98


Name : kartik
Company's Name : cisco
Salary Offered : 123


----------------------OPERATIONS----------------------
1.Insert at Front               2.Insert at Last
3.Insert at Postion             4.Delete at Front
5.Delete at last                6.Delete at Position 
7.Display List                  8.Search Element
9.Length Of list                10.Sort List
0.Exit
------------------------------------------------------
Enter Your Choice :
8

Enter Name of std u want to search : kartik
Data of kartik Found !

----------------------OPERATIONS----------------------
1.Insert at Front               2.Insert at Last
3.Insert at Postion             4.Delete at Front
5.Delete at last                6.Delete at Position 
7.Display List                  8.Search Element
9.Length Of list                10.Sort List
0.Exit
------------------------------------------------------
Enter Your Choice :
5

List After Deletion :
Name : harsh
Company's Name : ibm
Salary Offered : 98


----------------------OPERATIONS----------------------
1.Insert at Front               2.Insert at Last
3.Insert at Postion             4.Delete at Front
5.Delete at last                6.Delete at Position 
7.Display List                  8.Search Element
9.Length Of list                10.Sort List
0.Exit
------------------------------------------------------
Enter Your Choice :
4

List After Deletion :List Is Empty

----------------------OPERATIONS----------------------
1.Insert at Front               2.Insert at Last
3.Insert at Postion             4.Delete at Front
5.Delete at last                6.Delete at Position 
7.Display List                  8.Search Element
9.Length Of list                10.Sort List
0.Exit
------------------------------------------------------
Enter Your Choice :
0
Exiting Program !! 

*/