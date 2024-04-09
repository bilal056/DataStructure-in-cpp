#include <iostream>
using namespace std;

//       --- ----  Queue Using Linked List  ---- ---

/*

 * This program implements a queue using a linked list and provides a menu-driven interface for adding orders, 
   processing orders, and displaying the current orders with their total price.

*/


// Node class to represent each element in the queue
class Node
{
public:
    string info;    // Information about the order
    double prices;  // Price of the order
    Node *next;     // Pointer to the next node

    // Constructor to initialize the node
    Node(string data, double price)
    {
        info = data;
        prices = price;
        next = NULL;
    }
};

// Queue class implemented using linked list
class QueueinLinkedlist
{
private:
    Node *front, *rear; // Pointers to the front and rear of the queue
    int length;         // Length of the queue

public:
    // Constructor to initialize an empty queue
    QueueinLinkedlist()
    {
        front = NULL;
        rear = NULL;
        length = 0;
    }

    // Method to check if the queue is full (always false for linked list implementation)
    bool isFull()
    {
        return false;
    }

    // Method to check if the queue is empty
    bool isEmpty()
    {
        return length == 0;
    }

    // Method to add an element to the rear of the queue
    void inQueue(string data, double price)
    {
        Node *newnode = new Node(data, price);

        if (rear == NULL)
        {
            front = newnode;
            rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
        length++;
        cout << "OREDER PLACED!! " << endl;
    }

    // Method to remove an element from the front of the queue
    void dQueue()
    {
        Node *temp = front;
        if (!isEmpty())
        {
            cout << " PROCESSED ORDER : " << front->info << endl;
            cout << "PROCESSED ORDER PRICE: " << front->prices << endl;
            front = front->next;
            delete temp;
            length--;
        }
        else
        {
            cout << "ERROR!! List is Empty.." << endl;
        }
    }

    // Method to display all orders in the queue
    void DISPLAY()
    {
        Node *temp = front;
        double totalPrice = 0; // Initialize totalPrice to 0

        if (length != 0)
        {
            cout << " ---- CURRENT ORDERS ----- " << endl;
            while (temp != nullptr) // Use nullptr instead of NULL
            {
                cout << "ORDER NAME: " << temp->info << endl;
                cout << "ORDER PRICE: " << temp->prices << endl;

                totalPrice += temp->prices; // Add the current order price to totalPrice
                temp = temp->next;
            }
        }
        else
        {
            cout << "NO ORDER RECEIVED YET!!" << endl;
        }

        cout << "TOTAL PRICE: $" << totalPrice << endl;
    }
};

// Main function to create a menu-driven program for managing orders
int main()
{
    QueueinLinkedlist orders;

    int choose = -1;

    // Display the menu and process user input until the user chooses to exit (0)
    while (choose != 0)
    {
        cout << " ________________________________ " << endl;
        cout << "|---------- FOOD ITEMS ----------|" << endl;
        cout << "| 1. CLASSIC BURGER ------ $4.00 |" << endl;
        cout << "| 2. CHEESE BURGER  ------ $5.00 |" << endl;
        cout << "| 3. BEEF BURGER    ------ $7.00 |" << endl;
        cout << "| 4. WINGS          ------ $8.00 |" << endl;
        cout << "|---------- beverages -----------|" << endl;
        cout << "| 5. COCKTAIL       ------ $8.00 |" << endl;
        cout << "| 6. ICE TEA        ------ $5.00 |" << endl;
        cout << "| 7. BANANA SHAKE   ------ $6.00 |" << endl;
        cout << "| SELECT ITEM TO ADD IN THE LIST:|" << endl;
        cout << "|--- REMOVE PROCESSED ORDERS --- |" << endl;
        cout << "| 8. PROCCEED THE ORDER          |" << endl;
        cout << "| 9. FOR DISPLAYING THE ORDERS   |" << endl;
        cout << "| 0. EXIT.                       |" << endl;
        cout << " ________________________________ " << endl;
        cin >> choose;

        // Process user's choice based on the menu
        switch (choose)
        {
        case 1:
            orders.inQueue("CLASSIC BURGER", 4.00);
            break;
        case 2:
            orders.inQueue("CHEESE BURGER", 5.00);
            break;
        case 3:
            orders.inQueue("BEEF BURGER", 7.00);
            break;
        case 4:
            orders.inQueue("WINGS", 8.00);
            break;
        case 5:
            orders.inQueue("COCKTAIL", 8.00);
            break;
        case 6:
            orders.inQueue("ICE TEA", 5.00);
            break;
        case 7:
            orders.inQueue("BANANA SHAKE", 6.00);
            break;
        case 8:
            orders.dQueue();
            cout << endl;
            break;
        case 9:
            orders.DISPLAY();
            cout << endl;
            break;
        default:
            cout << "THANK YOU FOR USING THIS PLATEFORM..." << endl;
            break;
        }
    }
    return 0;
}
