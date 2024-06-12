#include <iostream>
using namespace std;

class Node
{
public:
    string info;
    double prices;
    Node *next;

    Node(string data, double price)
    {
        info = data;
        prices = price;
        next = NULL;
    }
};

class QueueinLinkedlist
{
private:
    Node *front, *rear;
    int length;

public:
    QueueinLinkedlist()
    {
        front = NULL;
        rear = NULL;
        length = 0;
    }

    bool isFull()
    {
        return false; // Since the queue is implemented using a linked list, it can't be full
    }

    bool isEmpty()
    {
        return length == 0;
    }

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
        cout << "ORDER PLACED!! " << endl;
    }

    void dQueue()
    {
        Node *temp = front;
        if (!isEmpty())
        {
            cout << "PROCESSED ORDER : " << front->info << endl;
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
            cout << "NO ORDERS RECEIVED YET!!" << endl;
        }

        cout << "TOTAL PRICE: $" << totalPrice << endl;
    }
};

int main()
{
    QueueinLinkedlist orders;

    int choose = -1;

    while (choose != 0)
    {
        cout << " ________________________________ " << endl;
        cout << "|---------- FOOD ITEMS ----------|" << endl;
        cout << "| 1. CLASSIC BURGER ------ $4.00 |" << endl;
        cout << "| 2. CHEESE BURGER  ------ $5.00 |" << endl;
        cout << "| 3. BEEF BURGER    ------ $7.00 |" << endl;
        cout << "| 4. WINGS          ------ $8.00 |" << endl;
        cout << "|---------- BEVERAGES -----------|" << endl;
        cout << "| 5. COCKTAIL       ------ $8.00 |" << endl;
        cout << "| 6. ICE TEA        ------ $5.00 |" << endl;
        cout << "| 7. BANANA SHAKE   ------ $6.00 |" << endl;
        cout << "| SELECT ITEM TO ADD IN THE LIST:|" << endl;
        cout << "|--- REMOVE PROCESSED ORDERS --- |" << endl;
        cout << "| 8. PROCEED THE ORDER           |" << endl;
        cout << "| 9. DISPLAY THE ORDERS          |" << endl;
        cout << "| 0. EXIT.                       |" << endl;
        cout << " ________________________________ " << endl;
        cin >> choose;

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
            cout << "THANK YOU FOR USING THIS PLATFORM..." << endl;
            break;
        }
    }
    return 0;
}
