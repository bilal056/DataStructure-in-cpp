#include <iostream>
using namespace std;


/* 
 - This code defines a doubly linked list with the ability to separate even and odd nodes into two separate lists.
    It uses two classes, node for defining the nodes of the list and doubleLinkList for managing the list.

 - The insert method is used to insert a new node at the end of the list, while the Even_Odd_data method separates even and odd nodes into two separate lists.
 - The Display method is used to display the even and odd lists.


*/


// Node class for a doubly linked list
class node
{
public:
    int info1;         // Data of the node
    node *next;        // Pointer to the next node
    node *previous;    // Pointer to the previous node
    
    // Constructor to initialize node
    node(int num)
    {
        info1 = num;
        next = previous = NULL;
    }
};

// Doubly linked list class
class doubleLinkList
{
private:
    node *head;        // Pointer to the head of the list
    node *head2;       // Pointer to the head of the odd nodes list
    node *temp;        // Temporary pointer used for traversal
    node *temp2;       // Temporary pointer used for traversal
    int length;        // Length of the list

public:
    // Constructor to initialize doubleLinkList
    doubleLinkList()
    {
        head = NULL;
        head2 = NULL;
        temp = NULL;
        temp2 = NULL;
        length = 0;
    }

    // Method to insert a new node at the end of the list
    void insert(int val)
    {
        node *newnode = new node(val);

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->previous = temp;
        }
        length++;
    }

    // Method to separate even and odd nodes into two separate lists
    void Even_Odd_data()
    {
        temp = head;
        while (temp != NULL)
        {
            if (temp->info1 % 2 != 0)
            {
                // Creating a new node for odd numbers
                node *newnode2 = new node(temp->info1);
                if (head2 == NULL)
                {
                    head2 = newnode2;
                    temp2 = head2;
                }
                else
                {
                    temp2 = head2;
                    while (temp2->next != NULL)
                    {
                        temp2 = temp2->next;
                    }
                    temp2->next = newnode2;
                    newnode2->previous = temp2;
                    temp2 = newnode2;
                }
                length++;
            }
            temp = temp->next;
        }

        temp = head;
        // Removing odd nodes from the original list
        while (temp != NULL)
        {
            if (temp->info1 % 2 != 0)
            {
                if (temp->previous == NULL)
                {
                    head = temp->next;
                    if (head != NULL)
                    {
                        head->previous = NULL;
                    }
                    delete temp;
                    temp = head;
                }
                else
                {
                    temp->previous->next = temp->next;
                    if (temp->next != NULL)
                    {
                        temp->next->previous = temp->previous;
                    }
                    node *deletion = temp;
                    temp = temp->next;
                    delete deletion;
                }
                length--;
            }
            else
            {
                temp = temp->next;
            }
        }
    }

    // Method to display the even and odd lists
    void Display()
    {
        temp = head;
        if (head == NULL)
        {
            cout << "List Not Found!! " << endl;
            return;
        }
        cout << " Even List: " << endl;
        while (temp != NULL)
        {
            cout << " " << temp->info1 << endl;
            temp = temp->next;
        }
        cout << endl;

        temp2 = head2;
        cout << " Odd List: " << endl;
        while (temp2 != NULL)
        {
            cout << " " << temp2->info1 << endl;
            temp2 = temp2->next;
        }
        cout << endl;
    }
};

int main()
{
    // Creating an instance of the doubleLinkList class
    doubleLinkList l1;

    // Inserting elements into the list
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.insert(6);
    l1.insert(7);
    l1.insert(8);
    l1.insert(9);

    // Separating even and odd nodes
    l1.Even_Odd_data();

    // Displaying the even and odd lists
    l1.Display();

    return 0;
}
