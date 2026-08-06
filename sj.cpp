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
    Customer c[10];
    int choice;
    cout << "Enter your choice: ";
    cout << "1. Insert Customer Info" << endl;
    cout << "2. Update Customer Info" << endl;
    cout << "3. Delete Customer Info" << endl;
    cout << "4. Display Customer Info" << endl;
    cout << "5. Exit" << endl;
    cin >> choice;
    int size=0;
    do{
        switch (choice){
        case 1:{
            int noOfCustomers;
            cout << "Enter the number of customers to insert: ";
            cin >> noOfCustomers;
            for (int i = 0; i < noOfCustomers; i++) {
                string n;
                int a;
                string e;
                string b;
                int p;
                cout << "Enter Customer Name: ";
                cin >> n;
                cout << "Enter Customer Age: ";
                cin >> a;
                cout << "Enter Customer Email: ";
                cin >> e;
                cout << "Enter Bought Items: ";
                cin >> b;
                cout << "Enter Price: ";
                cin >> p;
                c[size].insertInfo(n, a, e, b, p);
                size++;
            }
            break;
        }
        case 2:{
            int index;
            cout << "Enter the index of the customer to update: ";
            cin >> index;
            if (index >= 0 && index < size) {
                string n;
                int a;
                string e;
                string b;
                int p;
                cout << "Enter Updated Customer Name: ";
                cin >> n;
                cout << "Enter Updated Customer Age: ";
                cin >> a;
                cout << "Enter Updated Customer Email: ";
                cin >> e;
                cout << "Enter Updated Bought Items: ";
                cin >> b;
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
            int index;
            cin >> index;
            if (index >= 0 && index < size) {
                c[index].deleteInfo();
                cout << "Customer info deleted." << endl;
            } else {
                cout << "Invalid index!" << endl;
            }
            break;
        }
        case 4:{
            for (int i = 0; i < size; i++) {
                cout << "Customer " << i + 1 << ":" << endl;
                c[i].displayInfo();
                cout << endl;
            }
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }while(choice != 5);
    return 0;
}