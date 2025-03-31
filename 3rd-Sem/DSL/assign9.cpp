#include <iostream>
#include <string>
using namespace std;

class MyStack {
private:
    char* data;
    int capacity;
    int top;

public:
    MyStack(int size) 
    {
        data = new char[size];
        capacity = size;
        top = -1;
    }
    
    //ADDING ELEMENT
    void push(char value) {
        if (top < capacity - 1) {
            data[++top] = value;
        }
    }
    //deleting element from top
    char pop() {
        if (top >= 0) {
            return data[top--];
        }
        return NULL;
    }
    //returning element on the top
    char peek() {
        if (top >= 0) {
            return data[top];
        }
        return NULL;
    }
    //check for empty
    bool isEmpty() {
        return top == -1;
    }
};

bool isWellParenthesized(const string& expression) {
    MyStack stack(expression.length());

    for (char c : expression) 
    {
        if (c == '(' || c == '{' || c == '[') 
            stack.push(c); 
        else if (c == ')' || c == '}' || c == ']') 
        {
            if (stack.isEmpty()) 
                return false;

            char top = stack.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return stack.isEmpty();
}

int main() {
    while(true){
        string expression;
        cout << "Enter an expression: ";
        cin >> expression;
        if (isWellParenthesized(expression)) {
            cout << "The expression is well parenthesized."<<endl;
            } 
        else {
            cout << "The expression is not well parenthesized."<<endl;
            }
    }
    
    return 0;
}