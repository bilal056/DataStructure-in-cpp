#include <iostream>
using namespace std;

/*


* This C++ program implements a stack data structure to check the validity of a string containing different types of braces (parentheses, square brackets, and curly braces). 
  - It defines a node class to represent each element in the stack and a Stack class to implement stack operations like push, pop, and checking for empty/full conditions. 

* The checkbraces method in the Stack class iterates through the input string, pushing opening braces onto the stack and popping and comparing closing braces with the top of the stack.
  - If the stack is empty at the end of the iteration, it indicates that the string has balanced braces. 

* The program continuously prompts the user to input strings and displays whether the braces in the string are balanced or not, until the user chooses to exit

*/



// Node class to represent elements in the stack
class node
{
public:
    char info1; // Information stored in the node (brace character)
    node *next; // Pointer to the next node

    // Constructor to initialize a node with given information
    node(char num)
    {
        info1 = num;
        next = NULL;
    }
};

// Stack class to implement stack operations
class Stack
{
private:
    node *top;   // Pointer to the top of the stack
    int length;  // Current number of elements in the stack
    int limit;   // Maximum number of elements allowed in the stack

public:
    // Constructor to initialize an empty stack
    Stack()
    {
        top = nullptr;
        length = 0;
    }

    // Constructor to initialize a stack with a specified limit
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

    // Peek at the top element of the stack
    char peek()
    {
        if (!isEmpty())
        {
            return top->info1;
        }
        return '\0';
    }

    // Check the validity of braces in a string
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

    // Display the result of brace validity check
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

// Main function
int main()
{
    Stack stack(6); // Create a stack with a limit of 6 elements
    string name;    // String to store user input

    int choose = 0;
    // Loop until the user chooses to exit
    while (choose != 1)
    {
        cout << "----------------------------" << endl;
        cout << "Press [ 1 ] to exit" << endl;
        cout << "Enter braces: ";
        cin >> name;

        // Check the validity of braces in the input string
        bool result = stack.checkbraces(name);

        // Display the result
        stack.Display(result);

        cout << "Press [ 1 ] to exit|| Press [ 2 ] to continue!!" << endl;
        cin >> choose;
    }

    return 0;
}
