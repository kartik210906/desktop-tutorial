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
//have done some modification in code after previous completion.