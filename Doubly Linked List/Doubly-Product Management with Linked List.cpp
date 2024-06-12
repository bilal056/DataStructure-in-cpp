#include <iostream>
using namespace std;

/*

* This C++ code manages a list of products using a doubly linked list.
  It allows users to add, remove, update, find, and display products.

*/


// Node class to represent each item in the linked list
class node
{
public:
    int info1;      // ID of the product
    string info2;   // Name of the product
    double info3;   // Price of the product
    int info4;      // Quantity of the product
    node *next;     // Pointer to the next node in the linked list
    node *previous; // Pointer to the previous node in the linked list

    // Constructor to initialize a node with the given values
    node(int id, string name, double price, int quantity)
    {
        info1 = id;
        info2 = name;
        info3 = price;
        info4 = quantity;
        next = previous = NULL; // Initialize next and previous pointers to NULL
    }
};

// Class for the double linked list
class doubleLinkList
{
private:
    node *head; // Pointer to the head of the linked list
    node *temp; // Temporary pointer for traversal
    int length; // Length of the linked list

public:
    // Constructor to initialize the linked list
    doubleLinkList()
    {
        head = NULL; // Initialize head to NULL
        temp = NULL; // Initialize temp to NULL
        length = 0;  // Initialize length to 0
    }

    // Function to insert a new node into the linked list
    void Insertion(int id, string name, double price, int quantity)
    {
        node *newnode = new node(id, name, price, quantity); // Create a new node with the given values

        if (head == NULL)
        {
            // If the linked list is empty, set the new node as the head
            head = newnode;
        }
        else
        {
            // If the linked list is not empty, find the correct position to insert the new node
            temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            if (newnode->info1 > temp->info1)
            {
                // Insert at the end of the list if the new node's ID is greater than the last node's ID
                temp->next = newnode;
                newnode->next = NULL;
            }
            else if (newnode->info1 < temp->info1)
            {
                // Insert at the beginning of the list if the new node's ID is less than the first node's ID
                newnode->next = head;
                head = newnode;
            }
            else
            {
                // Insert in the middle of the list based on ID order
                temp = head;

                while (temp->next != NULL && temp->next->info1 < newnode->info1)
                {
                    temp = temp->next;
                }

                newnode->next = temp->next;
                temp->next = newnode;
            }
        }
        length++; // Increment the length of the linked list
    }

    // Function to remove a node from the linked list based on the ID
    void remove(int id)
    {
        temp = head;

        if (head == NULL)
        {
            cout << "list does not exists" << endl;
            return;
        }

        if (head->info1 == id)
        {
            // Remove the head node if it matches the given ID
            head = head->next;
            delete temp;
        }
        else
        {
            while (temp->next != NULL && temp->info1 != id)
            {
                temp = temp->next;
            }

            if (temp == NULL)
            {
                cout << "ID not found" << endl;
                return ;
            }

            if (temp->next != NULL)
            {
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;
            }
            else
            {
                temp->previous->next = NULL;
            }

            delete temp;
        }
        length--; // Decrement the length of the linked list
    }

    // Function to update the price of a product based on its ID
    void update(int id, double price)
    {
        temp = head;

        if (head == NULL)
        {
            cout << "list does not exists" << endl;
            return;
        }

        while (temp->info1 != id)
        {
            temp = temp->next;
        }

        temp->info3 = price;

        if (temp == NULL)
        {
            cout << "list does not exists" << endl;
        }
    }

    // Function to find and display a product based on its ID
    void FindProduct(int id)
    {
        if (head == NULL)
        {
            cout << "list does not exists" << endl;
            return;
        }

        node *curr = head;

        while (curr != NULL && curr->info1 != id)
        {
            curr = curr->next;
        }

        if (curr == NULL)
        {
            cout << "ID not found" << endl;
        }
        else
        {
            cout << "---------------" << endl;
            cout << "ID found: " << endl;
            cout << "ID: " << curr->info1 << endl;
            cout << "Name: " << curr->info2 << endl;
            cout << "price: " << curr->info3 << endl;
            cout << "Quantity: " << curr->info4 << endl;
            cout << "---------------" << endl;
            cout << endl;
        }
    }

    // Function to display all products in the linked list
    void Display()
    {
        temp = head;

        if (head == NULL)
        {
            cout << "List Not Found!! " << endl;
            return;
        }

        cout << "---------------" << endl;

        while (temp != NULL)
        {
            cout << "ID: " << temp->info1 << endl;
            cout << "Name: " << temp->info2 << endl;
            cout << "price: " << temp->info3 << endl;
            cout << "Quantity: " << temp->info4 << endl;
            cout << "---------------" << endl;
            cout << endl;
            temp = temp->next;
        }
    }
};

// Main function to test the linked list implementation
int main()
{
    doubleLinkList l1; // Create an instance of the double linked list
    int choose = 0;    // Variable to store the user's choice

    // Loop to display the menu and perform operations based on user input
    while (choose != 6)
    {
        cout << "  ___________________ " << endl;
        cout << "| 1. Add Product      |" << endl;
        cout << "| 2. Remove Product   |" << endl;
        cout << "| 3. Display Products |" << endl;
        cout << "| 4. Update Product   |" << endl;
        cout << "| 5. Find Product     |" << endl;
        cout << "| 6. Exit             |" << endl;
        cout << "| Enter your choice:  |" << endl;
        cout << "  ___________________  " << endl;
        cin >> choose;

        if (choose == 1)
        {
            // Add a new product
            int id;
            string name;
            double price;
            int Quantity;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Price: ";
            cin >> price;

            cout << "Enter Quantity: ";
            cin >> Quantity;

            l1.Insertion(id, name, price, Quantity);
        }
        else if (choose == 2)
        {
            // Remove a product
            int removeID = 0;
            cout << "Enter id You want to remove: ";
            cin >> removeID;

            l1.remove(removeID);
        }
        else if (choose == 3)
        {
            // Display all products
            l1.Display();
        }
        else if (choose == 4)
        {
            // Update the price of a product
            int id;
            double price;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter Price: ";
            cin >> price;

            l1.update(id, price);
        }
        else if (choose == 5)
        {
            // Find and display a product
            int id;

            cout << "Enter ID: ";
            cin >> id;

            l1.FindProduct(id);
        }
    }

    return 0; // Exit the program
}
