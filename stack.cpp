#include <iostream>
using namespace std;
class stack{
    int top;
    char arr[50];
    public:
        stack(){
            top=-1;
        }
        void push(int ch){
            arr[++top]=ch;
        }
        char pop(){
            return arr[top--];
        }
        bool isEmpty(){
            return (top==-1);
        }
        int priority(char ch){
            if (ch=='^') return 3;
            if (ch=='*' || ch=='/') return 2;
            if (ch=='+' || ch=='-') return 1;
            return 0;
        }
};
int main() {
    
    return 0;
}