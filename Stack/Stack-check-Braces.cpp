#include <iostream>
using namespace std;

// Node class for creating nodes of the stack
class node
{
public:
    char info1;
    node *next;
    node(char num)
    {
        info1 = num;
        next = NULL;
    }
};

// Stack class for implementing stack operations
class Stack
{
private:
    node *top;   // Pointer to the top of the stack
    int length;  // Current length of the stack
    int limit;   // Maximum limit of the stack

public:
    // Constructor to initialize an empty stack
    Stack()
    {
        top = nullptr;
        length = 0;
    }

    // Constructor to initialize a stack with a given limit
    Stack(int limit)
    {
        this->limit = limit;
        top = NULL;
        length = 0;
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return top == NULL;
    }

    // Check if the stack is full
    bool isFull()
    {
        return length == limit;
    }

    // Push an element onto the stack
    void push(char val)
    {
        if (!isFull())
        {
            node *temp = new node(val);
            temp->next = top;
            top = temp;
            length++;
            cout << "Element :" << val << " is pushed " << endl;
        }
    }

    // Pop an element from the stack
    char pop()
    {
        char val = '\0';
        if (!isEmpty())
        {
            node *temp = top;
            top = top->next;
            val = temp->info1;
            delete temp;
            length--;
            cout << "Element : " << val << " is popped" << endl;
        }
        return val;
    }

    // Return the top element of the stack without removing it
    char peek()
    {
        if (!isEmpty())
        {
            return top->info1;
        }
        return '\0';
    }

    // Check if the braces in a string are balanced
    bool checkbraces(string val)
    {
        Stack S(val.length());

        for (int i = 0; i < val.length(); i++)
        {
            if (val[i] == '{' || val[i] == '[' || val[i] == '(')
            {
                S.push(val[i]);
            }
            else if (val[i] == '}' || val[i] == ']' || val[i] == ')')
            {
                if (S.isEmpty())
                {
                    return false;
                }

                char top = S.pop();
                if ((top == '{' && val[i] != '}') ||
                    (top == '[' && val[i] != ']') ||
                    (top == '(' && val[i] != ')'))
                {
                    return false;
                }
            }
        }

        return S.isEmpty();
    }

    // Get the current length of the stack
    int getlength()
    {
        return length;
    }

    // Display the result of brace balancing
    void Display(bool result)
    {
        if (result)
        {
            cout << "True" << endl;
        }
        else
        {
            cout << "False" << endl;
        }
    }
};

int main()
{
    Stack stack(6); // Create a stack with a limit of 6 elements
    string name;    // Input string for braces

    int choose = 0;
    while (choose != 1)
    {
        cout<<"----------------------------"<<endl;
        cout << "Press [ 1 ] to exit" << endl;
        cout << "Enter braces: ";
        cin >> name;

        bool result = stack.checkbraces(name); // Check if the braces are balanced
        stack.Display(result);                 // Display the result

        cout << "Press [ 1 ] to exit|| Press [ 2 ] to continue!!" << endl;
        cin >> choose;
    }

    return 0;
}
