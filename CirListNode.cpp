#include<iostream>
using namespace std;
class CNode
{
    public:
	int quantity;
	string type;
	CNode *next;
    CNode(int i,string s)
	{
		quantity=i;
		type=s;
		next=nullptr;
    }
};

class CLL
{
	CNode *head=nullptr;

    public:
    
    CNode* getTail()
    {
        if(head==nullptr){
            return nullptr;
        }
        CNode* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        return temp;
    }

	void placeOrder(int i, string s)
	{
		CNode *temp = new CNode(i, s);
		if(head==nullptr)
		{
			head=temp;
			head->next = head;
		}
		else
		{
            CNode* tail = getTail();
			tail->next = temp;
			temp->next = head;
			tail = temp;
		}
        
		cout<<"\nOrder Placed :- "<<temp->quantity<<" "<<temp->type<<endl;
	}

    void serveOrder()
    {
        if(head==nullptr)
        {
            cout<<"\nNo Orders to Serve";
            return;
        }
        else if(head->next==head)
        {
            CNode *temp = head;
            cout<<"\nOrder Served :- "<<temp->quantity<<" "<<temp->type<<endl;
            head=nullptr;
            delete temp;
        }
        else
        {
            CNode *temp = head;
            cout<<"\nOrder Served :- "<<temp->quantity<<" "<<temp->type<<endl;
            head=head->next;
            CNode* tail = getTail();
            tail->next=head;
            delete temp;
        }
    }
    
	void display()
	{
		CNode* temp=head;
        if(head==nullptr)
        {
            cout<<"\nNo Orders to Display";
            return;
        }

        while(temp->next!=head)
        {
            cout<<"\n"<<temp->quantity<<" "<<temp->type;
            temp=temp->next;
        }
        cout<<"\n"<<temp->quantity<<" "<<temp->type<<endl;
	}
};

int main()
{
    int choice,count=0,choice1,maxOrders;
    int order;
    string type;
    CLL c;
    cout<<"\nEnter Maximum Orders :- ";
    cin>>maxOrders;
    do
    {
        cout<<"\n--------------------";
        cout<<"\n1. Place Order";
        cout<<"\n2. Serve Order";
        cout<<"\n3. Display Orders";
        cout<<"\n4. Exit";
        cout<<"\n--------------------";
        cout<<"\nEnter Your Choice :- ";
        cin>>choice;
        switch (choice)
        {
            case 1:
            if (count==maxOrders)
            {
                cout<<"\nOrders Full";
                break;
            }

            cout<<"\nEnter Pizza Type :- ";
            cout<<"\n1. Veg";
            cout<<"\n2. Non-Veg"<<endl;
            cin>>choice1;

            if (choice1 == 1){
                type = "Veg";
            }else if (choice1==2){
                type = "Non-Veg";
            }else{
                cout<<"Invalid Choice"<<endl;
                break;
            }
            cout<<"\nEnter Quantity :- ";
            cin>>order;

            c.placeOrder(order, type);
            count++;
            break;
        case 2:
            if (count==0){
                cout<<"No orders to serve"<<endl;
                break;
            }
            c.serveOrder();
            count--;
            break;
        case 3:
            c.display();
            break;
        default:
            cout<<"\nInvalid Choice";
    }
}while(choice!=4);
    
}