#include <iostream>
using namespace std;

/*
 - This code defines a circular linked list data structure to manage songs.

 - Users can add new songs, remove songs, and display all songs using a simple menu-driven interface.
*/


// Node class to store information about a song
class node
{
public:
    string info1; // Song title
    string info2; // Artist name
    string info3; // Release year
    node *next;   // Pointer to the next node in the circular linked list

    // Constructor to initialize the node with song information
    node(string Song_Title, string artist, string release_year)
    {
        info1 = Song_Title;
        info2 = artist;
        info3 = release_year;
        next = NULL;
    }
};

// Circular linked list class to manage songs
class circularLinkList
{
private:
    node *head;  // Pointer to the head of the circular linked list
    int length;  // Length of the circular linked list

public:
    // Constructor to initialize an empty circular linked list
    circularLinkList()
    {
        head = NULL;
        length = 0;
    }

    // Method to insert a new song at the beginning of the circular linked list
    void insertsong(string Song_Title, string artist, string release_year)
    {
        node *temp = head;
        node *newnode = new node(Song_Title, artist, release_year);

        if (head == NULL) // If the list is empty
        {
            head = newnode;
            head->next = head;
        }
        else
        {
            while (temp->next != head) // Find the last node in the list
            {
                temp = temp->next;
            }

            temp->next = newnode; // Insert the new node at the end of the list
            newnode->next = head;
            head = newnode; // Update the head to point to the new first node
        }
    }

    // Method to remove the first song from the circular linked list
    void remove()
    {
        if (head == NULL)
        {
            cout << "List is empty !!" << endl;
            return;
        }

        node *temp = head;
        node *slow = NULL;

        while (temp->next != head) // Find the node before the head
        {
            slow = temp;
            temp = temp->next;
        }

        if (slow == NULL) // If only one node in the list
        {
            delete head;
            head = NULL;
        }
        else
        {
            slow->next = head;
            delete temp;
        }
        cout << "Song Successfully Deleted..." << endl;
    }

    // Method to display all songs in the circular linked list
    void Display()
    {
        node *temp = head;

        if (head == NULL)
        {
            cout << "List is empty!! " << endl;
            return;
        }

        cout << "------------------------" << endl;

        do
        {
            cout << "Song TItle: " << temp->info1 << endl;
            cout << "Song Artist Name: " << temp->info2 << endl;
            cout << "Song release Year: " << temp->info3 << endl;
            temp = temp->next;
            cout << "------------------------" << endl;
        } while (temp != head);
        cout << endl;
    }
};

// Main function to demonstrate the circular linked list operations
int main()
{
    circularLinkList ls;
    int choose = 0;

    // Menu-driven program
    while (choose != 4)
    {
        cout << "  ___________________ " << endl;
        cout << "| 1. Add Song         |" << endl;
        cout << "| 2. Remove song      |" << endl;
        cout << "| 3. Display ALL Songs|" << endl;
        cout << "| 4. Exit             |" << endl;
        cout << "| Enter your choice:  |" << endl;
        cout << "  ___________________  " << endl;
        cin >> choose;

        if (choose == 1)
        {
            string Song_title;
            string ArtistName;
            string RealseYear;
            cout << "Enter Song Title: ";
            cin >> Song_title;
            cout << "Enter Artist Name: ";
            cin >> ArtistName;
            cout << "Enter Release year: ";
            cin >> RealseYear;

            ls.insertsong(Song_title, ArtistName, RealseYear);
        }
        else if (choose == 2)
        {
            ls.remove();
        }
        else if (choose == 3)
        {
            ls.Display();
        }
        else
        {
            cout << " -------------------------------  " << endl;
            cout << "Thank you for using this platform!!" << endl
                 << endl;
        }
    }

    return 0;
}
