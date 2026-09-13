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
        
		cout<<"\nOrder Placed :- "<<temp->quantity<<" "<<temp->type<<endl;
	}

    void serveOrder()
    {
        CNode *temp;
        temp=head;
        if(head==nullptr)
        {
            cout<<"\nNo Orders to Serve";
            return;
        }
        else if(head==tail)
        {
            cout<<"\nOrder Served :- "<<temp->quantity<<" "<<temp->type<<endl;
            head=nullptr;
            tail=nullptr;
            delete temp;
        }
        else
        {
            cout<<"\nOrder Served :- "<<temp->quantity<<" "<<temp->type<<endl;
            head=head->next;
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
    int choice,count=0,choice1;
    int order;
    string type;
    CLL c;
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
/*
    OUTPUT FOR PROGRAM:
    
    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 1

    Enter Pizza Type :- 
    1. Veg
    2. Non-Veg
    1

    Enter Quantity :- 21

    Order Placed :- 21 Veg

    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 1

    Enter Pizza Type :- 
    1. Veg
    2. Non-Veg
    2

    Enter Quantity :- 32

    Order Placed :- 32 Non-Veg

    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 1

    Enter Pizza Type :- 
    1. Veg
    2. Non-Veg
    1

    Enter Quantity :- 23

    Order Placed :- 23 Veg

    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 1

    Enter Pizza Type :- 
    1. Veg
    2. Non-Veg
    1

    Enter Quantity :- 11

    Order Placed :- 11 Veg

    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 1

    Enter Pizza Type :- 
    1. Veg
    2. Non-Veg
    2

    Enter Quantity :- 22

    Order Placed :- 22 Non-Veg

    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 1

    Orders Full
    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 2

    Order Served :- 21 Veg

    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 1

    Enter Pizza Type :- 
    1. Veg
    2. Non-Veg
    1 

    Enter Quantity :- 23

    Order Placed :- 23 Veg

    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 1

    Orders Full
    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 3

    32 Non-Veg
    23 Veg
    11 Veg
    22 Non-Veg
    23 Veg

    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 2

    Order Served :- 32 Non-Veg

    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 3

    23 Veg
    11 Veg
    22 Non-Veg
    23 Veg

    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 2

    Order Served :- 23 Veg

    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 2

    Order Served :- 11 Veg

    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 2

    Order Served :- 22 Non-Veg

    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 2

    Order Served :- 23 Veg

    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 2

    No Orders to Serve
    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 3

    No Orders to Display
    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 1

    Enter Pizza Type :- 
    1. Veg
    2. Non-Veg
    1

    Enter Quantity :- 43

    Order Placed :- 43 Veg

    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 3

    43 Veg

    --------------------
    1. Place Order
    2. Serve Order
    3. Display Orders
    4. Exit
    --------------------
    Enter Your Choice :- 4

    Invalid Choice

*/