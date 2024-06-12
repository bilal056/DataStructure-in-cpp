#include <iostream>
#include <string>
using namespace std;

// Node class for creating nodes of the stack
class node
{
public:
    string info1;   // Information stored in the node
    node *next;     // Pointer to the next node

    // Constructor to initialize a node with given information
    node(string num)
    {
        info1 = num;
        next = NULL;
    }
};

// Stack class for implementing stack data structure
class Stack
{
private:
    node *top;      // Pointer to the top of the stack
    int length;     // Current length of the stack
    int limit;      // Maximum limit of the stack

public:
    // Constructor to initialize the stack with a given limit
    Stack(int limit)
    {
        this->limit = limit;
        top = NULL;
        length = 0;
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        if (top == NULL)
        {
            cout << "stack is empty " << endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    // Check if the stack is full
    bool isFull()
    {
        if (length == limit)
        {
            cout << "Stack is full" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    // Push a new element onto the stack
    void push(string val)
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

    // Pop the top element from the stack
    string pop()
    {
        string val;
        if (!isEmpty())
        {
            node *temp = top;
            val = top->info1;
            top = top->next;
            delete temp;
            temp = NULL;
            length--;
            cout << "Element : " << val << " is popped" << endl;
        }
        return val;
    }

    // Peek at the top element of the stack
    string peek()
    {
        if (!isEmpty())
        {
            return top->info1;
        }
    }
};

// Browser class for implementing a simple web browser using stacks
class Browser
{
private:
    Stack backStack;            // Stack for storing back history
    Stack forwardStack;         // Stack for storing forward history
    string currentUrl;          // Current URL

public:
    // Constructor to initialize the browser with a capacity
    Browser(int capacity) : backStack(capacity), forwardStack(capacity)
    {
        currentUrl = "https://www.startpage.com";   // Start with a default URL
    }

    // Visit a new URL
    void visit(string url)
    {
        backStack.push(currentUrl);
        currentUrl = url;
        while (!forwardStack.isEmpty())
        {
            forwardStack.pop();
        }
        displayCurrentPage();
    }

    // Go back to the previous page
    void back()
    {
        if (!backStack.isEmpty())
        {
            forwardStack.push(currentUrl);
            currentUrl = backStack.pop();
            displayCurrentPage();
        }
        else
        {
            cout << "Error: Cannot go back. No more pages in the back history." << endl;
        }
    }

    // Go forward to the next page
    void forward()
    {
        if (!forwardStack.isEmpty())
        {
            backStack.push(currentUrl);
            currentUrl = forwardStack.pop();
            displayCurrentPage();
        }
        else
        {
            cout << "Error: Cannot go forward. No more pages in the forward history." << endl;
        }
    }

    // Display the current page URL
    void displayCurrentPage()
    {
        cout << "Current Page: " << currentUrl << endl;
    }
};

int main()
{
    int choose = 0;
    string URL;
    Stack History(6);    // Create a stack for history with a capacity of 6
    Browser history(6);  // Create a browser object with a history capacity of 6

    // Menu-driven loop for browsing options
    while (choose != 4)
    {
        cout << "  ___________________ " << endl;
        cout << "| 1. new tab         |" << endl;
        cout << "| 2. back button     |" << endl;
        cout << "| 3. forward button  |" << endl;
        cout << "| 4. Exit            |" << endl;
        cout << "| Enter your choice: |" << endl;
        cout << "  ___________________  " << endl;
        cin >> choose;

        if (choose == 1)
        {
            cout << "Enter website url: ";
            cin >> URL;
            history.visit(URL);
        }
        else if (choose == 2)
        {
            history.back();
        }
        else if (choose == 3)
        {
            history.forward();
        }
    }

    return 0;
}
