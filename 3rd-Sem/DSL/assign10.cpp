#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <class T>
class Stack
{
    int top;
    int capacity;
    T *data;

public:
    Stack(int size)
    {
        capacity = size;
        top = -1;
        data = new T[size];
    }
    void push(char value)
    {
        if(top<capacity - 1)
            data[++top] = value
    }
    char pop()
    {
        if(top>=0)
            return data[top--]
    }
    void Display()
    {
        for (int i = top; i > -1; i--)
            cout << data[i] << " ";
        cout << endl;
    }
    bool isempty()
    {
        return top == -1
    }
    bool isfull()
    {
        return top == capacity-1
    }
    T peek()
    {
        return data[top];
    }
};

bool isOperand(char a)
{
    if (a == '+' || a == '-' || a == '/' || a == '*' || a == '(' || a == ')')
        return false;
    else
        return true;
}

int pre(char a)
{
    if (a == '+' || a == '-')
        return 1;
    else if (a == '/' || a == '*')
        return 2;
    else if (a == '(')
        return 3;
}

string inTopost(string s)
{
    string post = "";
    Stack<char> st(100);
    int n = s.size();
    
    for (int i = 0; i < n; i++)
    {
        if (isOperand(s[i]))
        {
            post = post + s[i];
        }
        else if (s[i] == ')')
        {
            while (st.peek() != '(')
            {
                post = post + st.pop();
            }
            st.pop();
        }
        else
        {
            if (st.isempty())
                st.push(s[i]);
            else
            {
                while (!st.isempty() && st.peek() != '(' && pre(s[i]) <= pre(st.peek()))
                    post = post + st.pop();
                st.push(s[i]);
            }
        }
    }
    while (!st.isempty())
    {
        post = post + st.peek();
        st.pop();
    }
    return post;
}

int Evaluatepost(string s)
{
    Stack<float> st(100);
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            cout << "Enter the value of " << s[i] << endl;
            float t;
            cin >> t;
            st.push(t);
        }
        else
        {
            float x1, x2, r;
            x2 = st.pop();
            x1 = st.pop();
            switch (s[i])
            {
            case '+':
                r = x1 + x2;
                st.push(r);
                break;
            case '-':
                r = x1 - x2;
                st.push(r);
                break;
            case '*':
                r = x1 * x2;
                st.push(r);
                break;
            case '/':
                r = x1 / x2;
                st.push(r);
                break;
            default:
                break;
            }
        }
    }
    return st.pop();
}

int main()
{
    string s;
    cout << "Enter the Expression" << endl;
    cin >> s;

    cout << "------------------ Menu -----------------------" << endl;
    cout << "1.Display the Postfix Expresion for the input." << endl;
    cout << "2.Evaluate the expresion by taking some integer values ofthe variables." << endl;
    cout << "0.Exit the Program." << endl;
    cout << "-----------------------------------------------" << endl;
    int choice;
    while (true)
    {
        cout << "Enter the Choice." << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "The postfix Expresion of the Entered infix Exp. is :-- ' " << inTopost(s) << " " << endl;
        }
        else if (choice == 2)
        {
            string a = inTopost(s);
            int k = Evaluatepost(a);
            cout << "The Final ans of the Expresion according to the entered variables is :-- " << k << endl;
        }
        else if (choice == 0)
        {
            cout << "__ __ __ __ __ __-!!ThankYou!!-__ __ __ __ __" << endl;
            break;
        }
        else
        {
            cout << "Choice Out Of Range!!!!" << endl;
        }
    }
    return 0;
}