#include <iostream>
using namespace std;
class vec{
    int i,j,k;
    public:
        //Default constructor 
        vec(){
            i=0;
            j=0;
            k=0;
        }

        //Default Parametric constructor 
        vec(int val_i,int val_j,int val_k){
            i=val_i;
            j=val_j;
            k=val_k;
        }

        vec operator +(vec a){
            vec result;
            result.i=i+a.i;
            result.j=j+a.j;
            result.k=k+a.k;
            return result;
        }

        vec operator -(vec a){
            vec result;
            result.i=i-a.i;
            result.j=j-a.j;
            result.k=k-a.k;
            return result;
        }

        vec operator *(vec a){
            vec result;
            result.i=i*a.i;
            result.j=j*a.j;
            result.k=k*a.k;
            return result;
        }

        void dis(){
            cout<<i<<"i+"<<j<<"j+"<<k<<"k"<<endl;
        }
};

int main(){
    int i,j,k;

    cout<<"Enter 1st Vector :\n";
    cout<<"i : ";
    cin>>i;
    cout<<"j : ";
    cin>>j;
    cout<<"k : ";
    cin>>k;
    cout<<endl;

    vec a(i,j,k);

    cout<<"Enter 2nd Vector :\n";
    cout<<"i : ";
    cin>>i;
    cout<<"j : ";
    cin>>j;
    cout<<"k : ";
    cin>>k;
    cout<<endl;

    vec b(i,j,k);    //Parametric Constructor called 

    vec result;      //Default contructor called (0,0,0) value setted.
    
    cout<<"Vector 1 : ";
    a.dis();
    cout<<"Vector 2 : ";
    b.dis();
    cout<<endl;

    result=a+b;     //ADDITION OF VECTOR
    cout<<"Addition : ";
    result.dis();

    result=a-b;     //SUBTRACTION OF VECTOR 
    cout<<"Subtraction : ";
    result.dis();

    result=a*b;     //DOT PRODUCT OF VECTOR 
    cout<<"Dot Product : ";
    result.dis();
}
/*

Enter 1st Vector :
i : 2
j : 3
k : 5

Enter 2nd Vector :
i : 1
j : 8
k : 4

Vector 1 : 2i+3j+5k
Vector 2 : 1i+8j+4k

Addition : 3i+11j+9k
Subtraction : 1i+-5j+1k
Dot Product : 2i+24j+20k

*/