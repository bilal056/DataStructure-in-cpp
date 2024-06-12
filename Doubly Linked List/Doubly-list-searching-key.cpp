#include <iostream>
using namespace std;

class node
{
public:
    int info1;
    node *next;
    node *previous;

    // Constructor to initialize a node with a given value
    node(int num)
    {
        info1 = num;
        next = previous = NULL;
    }
};

class doubleLinkList
{
    friend int main(); // Allowing main() to access private members

private:
    node *head;
    int length;

public:
    // Constructor to initialize an empty doubly linked list
    doubleLinkList()
    {
        this->head = NULL;
        this->length = 0;
    }

    // Method to insert a new node with a given value at the end of the list
    void insert(int val)
    {
        node *newnode = new node(val);

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->previous = temp;
        }
        length++;
    }

    // Method to recursively search for a key in the list starting from a given node
    int searchKey(int key, node *temp)
    {
        if (temp == NULL)
        {
            cout << "List is empty " << endl;
            return -1;
        }
        if (temp->info1 == key)
        {
            cout << "Key is found  " << key << endl;
            return key;
        }
        else
        {
            return searchKey(key, temp->next);
        }
    }

    // Method to get the head node of the list
    node *getHead()
    {
        return head;
    }
};

int main()
{
    doubleLinkList l1;

    // Inserting nodes with values 2, 5, and 9 into the list
    l1.insert(2);
    l1.insert(5);
    l1.insert(9);

    int keyToSearch = 2;
    // Searching for the key 2 in the list
    l1.searchKey(keyToSearch, l1.getHead());

    return 0;
}
