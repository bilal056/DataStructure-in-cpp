#include <iostream>
using namespace std;
/*

 -  This C++ program demonstrates the implementation of a queue using a linked list.
 It defines a Node class to represent elements in the queue, and a QueueinLinkedlist class to implement the queue operations.

 - The main functionality includes adding elements to the queue, checking if the queue is full or empty, duplicating a node in the queue,
 duplicating all nodes from one queue to another, and displaying the elements in the queue.

*/


// Define a Node class to represent elements in the queue
class Node
{
public:
    int info;
    Node *next;

    Node(int data)
    {
        info = data;
        next = nullptr;
    }
};

// Define a QueueinLinkedlist class to implement the queue using a linked list
class QueueinLinkedlist
{
private:
    Node *front, *rear; // Front and rear pointers for the queue
    int length;         // Variable to store the length of the queue

public:
    // Constructor to initialize the queue
    QueueinLinkedlist()
    {
        front = nullptr;
        rear = nullptr;
        length = 0;
    }

    // Method to check if the queue is full (always returns false for a linked list implementation)
    bool isFull()
    {
        return false; // Since the queue is implemented using a linked list, it can't be full
    }

    // Method to check if the queue is empty
    bool isEmpty()
    {
        return length == 0;
    }

    // Method to add an element to the queue
    void inQueue(int data)
    {
        Node *newnode = new Node(data);
        if (rear == nullptr)
        {
            front = newnode;
            rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
        length++; // Increment the length of the queue
    }

    // Method to duplicate a node in the queue
    void duplicateNode(Node *obj)
    {
        if (obj == nullptr)
            return;

        Node *newnode = new Node(obj->info);
        if (rear == nullptr)
        {
            front = newnode;
            rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
        length++; // Increment the length of the queue
    }

    // Method to duplicate all nodes from one queue to another
    void duplicateAllNodes(QueueinLinkedlist& original, QueueinLinkedlist& duplicate)
    {
        Node* current = original.front;
        while (current != nullptr)
        {
            for (int  i = 0; i < current->info; i++)
            {
                duplicate.duplicateNode(current); // Duplicate each node from original and add it to duplicate
            }
            
            current = current->next;
        }
    }

    // Method to display the elements in the queue
    void display()
    {
        Node *temp = front;

        while (temp != nullptr)
        {
            cout << " " << temp->info << ", ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    QueueinLinkedlist l1;
    cout << " ---- ORIGINAL QUEUE LIST ----- " << endl;
    l1.inQueue(3);
    l1.inQueue(2);

    l1.display();

    QueueinLinkedlist l2;
    l2.duplicateAllNodes(l1, l2);
    cout << " ---- DUPLICATED QUEUE LIST ----- " << endl;

    l2.display();

    return 0;
}
