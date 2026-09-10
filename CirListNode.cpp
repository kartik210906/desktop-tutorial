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
	CNode *tail=nullptr;
    public:
	void placeOrder(int i, string s)
	{
		CNode *temp = new CNode(i, s);
		if(head==nullptr)
		{
			head=temp;
			head->next = head;
			tail=head;
		}
		else
		{
			temp->next = tail->next;
			tail->next = temp;
			tail = temp;
		}
        //cout<<temp<<" ==> "<<temp->quantity<<" ==> "<<tail->next;
		cout<<"\nOrder Placed :- "<<temp->quantity<<" "<<temp->type<<endl;
	}

    void serveOrder()
    {
        CNode *temp;
        temp=head;
        cout<<"Order Served for :- "<<temp->quantity<<" "<<temp->type<<endl;
        head=head->next;
        tail->next=head;
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
    int choice,count=0,choice1;
    int order;
    string type;
    CLL c;
    do
    {
        cout<<"\n1. Place Order";
        cout<<"\n2. Serve Order";
        cout<<"\n3. Display Orders";
        cout<<"\n4. Exit";
        cout<<"\nEnter Your Choice :- ";
        cin>>choice;
        switch (choice)
        {
            case 1:
            if (count==5)
            {
                cout<<"\nOrders Full";
                break;
            }

            cout<<"\nEnter Pizza Type :- ";
            cout<<"\n1. Veg";
            cout<<"\n2. Non-Veg"<<endl;
            cin>>choice1;

            if (choice1 == 1)
                type = "Veg";
            else
                type = "Non-Veg";

            cout<<"\nEnter Quantity :- ";
            cin>>order;

            c.placeOrder(order, type);
            count++;
            break;
        case 2:
            if (count == 0)
            {
                cout<<"\nNo Orders to Serve";
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
