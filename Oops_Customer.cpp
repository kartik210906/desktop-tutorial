#include <iostream>
#include <string>
using namespace std;
class Customer {
    private:
        string name;
        int age;
        string email;
        string bought_items;
        int price;
    public:
        Customer()
            : name(""), age(0), email(""), bought_items(""), price(0) {}

        void displayInfo() const {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Email: " << email << endl;
            cout << "Bought Items: " << bought_items << endl;
            cout << "Price: " << price << endl;
            cout<< "------------------------" << endl;
        }

        void updateInfo(const string& n, int a, const string& e, const string& b, int p) {
            name = n;
            age = a;
            email = e;
            bought_items = b;
            price = p;
        }

        void deleteInfo() {
            name.clear();
            age = 0;
            email.clear();
            bought_items.clear();
            price = 0;
        }

        void insertInfo(const string& n, int a, const string& e, const string& b, int p) {
            name = n;
            age = a;
            email = e;
            bought_items = b;
            price = p;
        }
};

int main() {
    Customer c[50];
    int choice;
    int size=0,a,p,noOfCustomers, index;
    string n,e,b;
    do{
        cout << endl;
        cout << "Customer Management System" << endl;
        cout << "------------------------" << endl;
        cout << "1. Insert Customer Info" << endl;
        cout << "2. Update Customer Info" << endl;
        cout << "3. Delete Customer Info" << endl;
        cout << "4. Display Customer Info" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice){
        case 1:{
            cout << "Enter the number of customers to insert: ";
            cin >> noOfCustomers;
            for (int i = 0; i < noOfCustomers; i++) {
                cout << "Enter Customer Name: ";
                cin.ignore();
                getline(cin, n);
                cout << "Enter Customer Age: ";
                cin >> a;
                cout << "Enter Customer Email: ";
                cin.ignore();
                getline(cin, e);
                cout << "Enter Bought Items: ";
                cin.ignore();
                getline(cin, b);
                cout << "Enter Price: ";
                cin >> p;
                cout << endl;
                c[size].insertInfo(n, a, e, b, p);
                size++;
            }
            break;
        }
        case 2:{
            cout << "Enter the index of the customer to update: ";
            cin >> index;
            if (index >= 0 && index < size) {
                cout << "Enter Updated Customer Name: ";
                cin.ignore();
                getline(cin, n);
                cout << "Enter Updated Customer Age: ";
                cin >> a;
                cout << "Enter Updated Customer Email: ";
                cin.ignore();
                getline(cin, e);
                cout << "Enter Updated Bought Items: ";
                cin.ignore();
                getline(cin, b);
                cout << "Enter Updated Price: ";
                cin >> p;
                c[index].updateInfo(n, a, e, b, p);
                cout << "Customer info updated." << endl;
            } else {
                cout << "Invalid index!" << endl;

            }
            break;
        }
        case 3:{
            cout << "Enter the index of the customer to delete: ";
            cin >> index;
            if (index >= 0 && index < size) {
                c[index].deleteInfo();
                cout << "Customer info deleted." << endl;
                c[index] = c[size - 1]; 
                size--; 
            } else {
                cout << "Invalid index!" << endl;
            }
            break;
        }
        case 4:{
            cout << "Customer Information:" << endl;
            cout << "------------------------" << endl;
            for (int i = 0; i < size; i++) {
                cout << "Customer " << i + 1 << ":" << endl;
                c[i].displayInfo();
                cout << endl;
            }
            break;
        }
        default:
            cout << "exiting the program." << endl;
            break;
        }
    }while(choice != 5);
    return 0;
}

/*

SAMPLE OUTPUT

Customer Management System
------------------------
1. Insert Customer Info
2. Update Customer Info
3. Delete Customer Info
4. Display Customer Info
5. Exit

Enter your choice: 1

Enter the number of customers to insert: 2
Enter Customer Name: kartik ambhore
Enter Customer Age: 19
Enter Customer Email: kartik@gmail.com
Enter Bought Items: bread
Enter Price: 54

Enter Customer Name: soham more
Enter Customer Age: 17
Enter Customer Email: soham@gmai;.com
Enter Bought Items: toast
Enter Price: 12


Customer Management System
------------------------
1. Insert Customer Info
2. Update Customer Info
3. Delete Customer Info
4. Display Customer Info
5. Exit

Enter your choice: 1

Enter the number of customers to insert: 1
Enter Customer Name: sahil more
Enter Customer Age: 17 
Enter Customer Email: sahil@gmail.com
Enter Bought Items: jam
Enter Price: 12


Customer Management System
------------------------
1. Insert Customer Info
2. Update Customer Info
3. Delete Customer Info
4. Display Customer Info
5. Exit

Enter your choice: 2

Enter the index of the customer to update: 1
Enter Updated Customer Name: soham nirne
Enter Updated Customer Age: 19
Enter Updated Customer Email: sohamnirne@86
Enter Updated Bought Items: ketcup
Enter Updated Price: 43
Customer info updated.

Customer Management System
------------------------
1. Insert Customer Info
2. Update Customer Info
3. Delete Customer Info
4. Display Customer Info
5. Exit

Enter your choice: 4

Customer Information:
------------------------
Customer 1:
Name: kartik ambhore
Age: 19
Email: kartik@gmail.com
Bought Items: read
Price: 54
------------------------

Customer 2:
Name: soham nirne
Age: 19
Email: sohamnirne@86
Bought Items: etcup
Price: 43
------------------------

Customer 3:
Name: sahil more
Age: 17
Email: sahil@gmail.com
Bought Items: am
Price: 12
------------------------


Customer Management System
------------------------
1. Insert Customer Info
2. Update Customer Info
3. Delete Customer Info
4. Display Customer Info
5. Exit

Enter your choice: 6

exiting the program.

Customer Management System
------------------------
1. Insert Customer Info
2. Update Customer Info
3. Delete Customer Info
4. Display Customer Info
5. Exit

Enter your choice: 3 

Enter the index of the customer to delete: 2
Customer info deleted.

Customer Management System
------------------------
1. Insert Customer Info
2. Update Customer Info
3. Delete Customer Info
4. Display Customer Info
5. Exit

Enter your choice: 4

Customer Information:
------------------------
Customer 1:
Name: kartik ambhore
Age: 19
Email: kartik@gmail.com
Bought Items: read
Price: 54
------------------------

Customer 2:
Name: soham nirne
Age: 19
Email: sohamnirne@86
Bought Items: etcup
Price: 43
------------------------


Customer Management System
------------------------
1. Insert Customer Info
2. Update Customer Info
3. Delete Customer Info
4. Display Customer Info
5. Exit

Enter your choice: 5

exiting the program.
*/