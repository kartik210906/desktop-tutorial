#include<iostream>
using namespace std;
class CNode
{
    public:
	int data;
	CNode *next;
    CNode(int i)
	{
		data=i;
		next=nullptr;	
    }
};

class CLL
{
	CNode *head=nullptr;
	CNode *tail=nullptr;
    public:
	void placeOrder(int i)
	{
		CNode *temp = new CNode(i);
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
        //cout<<temp<<" ==> "<<temp->data<<" ==> "<<tail->next;
		cout<<"\nOrder Placed :- "<<temp->data<<" Pizza"<<endl;
	}

    void serveOrder()
    {
        CNode *temp;
        temp=head;
        cout<<"Order Served for :- "<<temp->data<<" Pizza";
        head=head->next;
        tail->next=head;
    }
    
	void display()
	{
		CNode *temp;
		cout<<"\nCurrent Orders Are :-"<<endl;
		temp=head;
		while(temp->next != head)
		{
			cout<<"Pizza = "<<temp->data<<" ==> ";
			temp=temp->next;
		}
      cout<<"Pizza = "<<temp->data<<" ==> Null ";
	}
};

int main()
{
    int choice,count=0;
    int order;
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
            cout<<"\nEnter Order Number :- ";
            cin>>order;
            c.placeOrder(order);
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
