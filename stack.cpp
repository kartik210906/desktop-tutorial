#include <iostream>
#include <cmath>
using namespace std;

class stack {
    int top;
    string arr[50];

    public:
        stack() {
            top = -1;
        }

        void push(string ch) {
            arr[++top] = ch;
        }

        string pop() {
            return arr[top--];
        }

        bool isEmpty() {
            return top == -1;
        }

        int priority(char ch) {
            if (ch == '^') return 3;
            if (ch == '*' || ch == '/') return 2;
            if (ch == '+' || ch == '-') return 1;
            return 0;
        }

        string peek() {
            return arr[top];
        }

        // Infix to Postfix
        string infixToPost(string s) {
            string post;

            for (int i = 0; i < s.size(); i++) {
                char ch = s[i];

                if (isalnum(ch)) {
                    post += ch;
                }

                else if (ch == '(') {
                    string temp = "";
                    temp += ch;
                    push(temp);
                }

                else if (ch == ')') {
                    while (!isEmpty() && peek() != "(") {
                        post += pop();
                    }

                    if (!isEmpty())
                        pop();
                }

                else {
                    while (!isEmpty() &&
                        peek() != "(" &&
                        priority(peek()[0]) >= priority(ch)) {
                        post += pop();
                    }

                    string temp = "";
                    temp += ch;
                    push(temp);
                }
            }

            while (!isEmpty()) {
                post += pop();
            }

            return post;
        }

        // Prefix to Infix
        string prefixToInfix(string s) {
            for (int i = s.size() - 1; i >= 0; i--) {

                if (isalnum(s[i])) {
                    string temp = "";
                    temp += s[i];
                    push(temp);
                }

                else {
                    string a = pop();
                    string b = pop();

                    string temp = "(";
                    temp += a;
                    temp += s[i];
                    temp += b;
                    temp += ")";

                    push(temp);
                }
            }

            return pop();
        }

        int postfixEvaluation(string postfix)
        {
            int numStack[50];
            int top = -1;

            for (int i = 0; i < postfix.length(); i++)
            {
                char ch = postfix[i];

                if (ch >= '0' && ch <= '9')
                {
                    numStack[++top] = ch - '0';
                }
                else if (!isalnum(ch))
                {
                    int b = numStack[top--];
                    int a = numStack[top--];

                    int result;

                    switch (ch)
                    {
                        case '+':
                            result = a + b;
                            break;

                        case '-':
                            result = a - b;
                            break;

                        case '*':
                            result = a * b;
                            break;

                        case '/':
                            result = a / b;
                            break;

                        case '^':
                            result = pow(a, b);
                            break;
                    }

                    numStack[++top] = result;
                }
            }

            return numStack[top];
        }
};

int main() {
    int choice;
    stack s1,s2,s3;
    do{

        cout<<"-------------------------- "<<endl;
        cout<<"1.Infix to Postfix"<<endl;
        cout<<"2.Prefix to Infix"<<endl;
        cout<<"3.PostFix Evaluation"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"-------------------------- "<<endl;
        cout<<"Enter ur Choice :"<<endl;
        cin>>choice;
        switch(choice){
            case 1:{
                string infix;
                cout<<"Enter Infix Expression"<<endl;
                cin>>infix;
                cout<<"Ur PostFix Expression is:"<<endl;
                cout<<s1.infixToPost(infix)<<endl;
                break;
            }
            case 2 : {
                string prefix;
                cout<<"Enter Prefix Expression"<<endl;
                cin>>prefix;
                cout<<"Ur Infix Expression is:"<<endl;
                cout<<s1.prefixToInfix(prefix)<<endl;
                break;
            }
            case 3 : {
                string postfix;
                cout<<"Enter Postfix Expression"<<endl;
                cin>>postfix;
                cout<<"Ur PostFix Evalution is:"<<endl;
                cout<<s1.postfixEvaluation(postfix)<<endl;
                break;
            }
            default : {
                cout<<"Invalid Choice !"<<endl;
                break;
            }
        }

    }while(choice!=0);

    return 0;
}

/*
        OUTPUT :
        -------------------------- 
        1.Infix to Postfix
        2.Prefix to Infix
        3.PostFix Evaluation
        0.Exit
        -------------------------- 
        Enter ur Choice :
        1
        Enter Infix Expression
        A+B*C-(X/Y^Z)+P
        Ur PostFix Expression is:
        ABC*+XYZ^/-P+
        -------------------------- 
        1.Infix to Postfix
        2.Prefix to Infix
        3.PostFix Evaluation
        0.Exit
        -------------------------- 
        Enter ur Choice :
        2
        Enter Prefix Expression
        +*ABC
        Ur Infix Expression is:
        ((A*B)+C)
        -------------------------- 
        1.Infix to Postfix
        2.Prefix to Infix
        3.PostFix Evaluation
        0.Exit
        -------------------------- 
        Enter ur Choice :
        3
        Enter Postfix Expression
        23*6+7*5-
        Ur PostFix Evalution is:
        79
        -------------------------- 
        1.Infix to Postfix
        2.Prefix to Infix
        3.PostFix Evaluation
        0.Exit
        -------------------------- 
        Enter ur Choice :
        3
        Enter Postfix Expression
        39*7+
        Ur PostFix Evalution is:
        34
        -------------------------- 
        1.Infix to Postfix
        2.Prefix to Infix
        3.PostFix Evaluation
        0.Exit
        -------------------------- 
        Enter ur Choice :
        0
        Invalid Choice !
*/