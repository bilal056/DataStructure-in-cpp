#include <iostream>
using namespace std;

// Node class to represent each student
class Student_node
{
public:
    int info1;       // Student ID
    string info2;    // Student Name
    double info3;    // Student GPA
    Student_node *next; // Pointer to the next student node

    // Constructor to initialize the student node with given values
    Student_node(int StudentID, string StudentName, double StudentGPA)
    {
        info1 = StudentID;
        info2 = StudentName;
        info3 = StudentGPA;
        next = NULL; // Initially, the next pointer is set to NULL
    }
};

// Linked List class to manage the student nodes
class linkedList
{
private:
    Student_node *head; // Pointer to the first student node in the linked list
    int length;         // Length of the linked list (number of students)

public:
    // Constructor to initialize the linked list
    linkedList()
    {
        head = NULL; // Initially, the linked list is empty
        length = 0;  // The length is set to zero
    }

    // Function to insert a new student node into the linked list
    void insert(int StudentID, string StudentName, double StudentGPA)
    {
        // Create a new student node with the given values
        Student_node *newnode = new Student_node(StudentID, StudentName, StudentGPA);

        // If the linked list is empty, set the new node as the head
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            // Traverse the linked list to find the last node
            Student_node *slow = NULL;
            Student_node *curr = head;
            for (int i = 0; i < length; i++)
            {
                slow = curr;
                curr = curr->next;
            }
            // Insert the new node at the end of the linked list
            slow->next = newnode;
            newnode->next = curr;
        }
        length++; // Increment the length of the linked list
    }

    // Function to delete a student node with a specific ID from the linked list
    void deletion_using_ID(int ID)
    {
        if (head == NULL)
        {
            cout << "list does not exists" << endl;
            return;
        }

        Student_node *curr = head;
        Student_node *slow = NULL;
        while (curr != NULL && curr->info1 != ID)
        {
            slow = curr;
            curr = curr->next;
        }
        if (curr == NULL)
        {
            cout << "ID not found" << endl;
            return;
        }
        if (slow != NULL)
        {
            slow->next = curr->next;
        }
        else
        {
            head = curr->next;
        }
        delete curr;
        length--;
    }

    // Function to search for a student node with a specific ID and display its information
    void search(int ID)
    {
        if (head == NULL)
        {
            cout << "list does not exists" << endl;
            return;
        }

        Student_node *curr = head;
        while (curr != NULL && curr->info1 != ID)
        {
            curr = curr->next;
        }
        if (curr == NULL)
        {
            cout << "ID not found" << endl;
        }
        else
        {
            cout << "ID found: " << endl;
            cout << "ID: " << curr->info1;
            cout << ", Name: " << curr->info2;
            cout << ", GPA: " << curr->info3;
            cout << endl;
        }
    }

    // Function to calculate and display the average GPA of all students in the linked list
    void Calculate_averageGPA()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Student_node *curr = head;
        double total = 0;
        while (curr != NULL)
        {
            total += curr->info3;
            curr = curr->next;
        }
        double avg = total / length;
        cout << "Average GPA: " << avg << endl;
        cout << "Total Students: " << length << endl;
    }

    // Function to display all students in the linked list
    void Display()
    {
        if (head == NULL)
        {
            cout << "List Not Found!! " << endl;
            return;
        }

        Student_node *curr = head;
        for (int i = 0; i < length; i++)
        {
            cout << " ID: " << curr->info1;
            cout << ", Name: " << curr->info2;
            cout << ", GPA: " << curr->info3;
            curr = curr->next;
            cout << endl;
        }
        cout << endl;
    }
};

// Main function to test the linked list operations
int main()
{
    linkedList l1; // Create an instance of the linked list

    int choose = 0;
    int search = 0;
    int remove = 0;
    while (choose != 6)
    {
        // Display menu options
        cout << "1. Add a Student" << endl;
        cout << "2. Remove a student " << endl;
        cout << "3. Search for Student" << endl;
        cout << "4. Display All Students" << endl;
        cout << "5. Calculate Average" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choose;

        // Perform operations based on user choice
        if (choose == 1)
        {
            int id;
            string name;
            double GPA;

            cout << "Enter Student ID: ";
            cin >> id;

            cout << "Enter Student Name: ";
            cin >> name;

            cout << "Enter Student GPA: ";
            cin >> GPA;

            l1.insert(id, name, GPA); // Insert a new student into the linked list
        }
        else if (choose == 2)
        {
            cout << "Enter Student id You want to remove: ";
            cin >> remove;

            l1.deletion_using_ID(remove); // Remove a student from the linked list
        }
        else if (choose == 3)
        {
            cout << "Enter id You want to search for: ";
            cin >> search;

            l1.search(search); // Search for a student in the linked list
        }
        else if (choose == 4)
        {
            l1.Display(); // Display all students in the linked list
        }
        else if (choose == 5)
        {
            l1.Calculate_averageGPA(); // Calculate and display the average GPA of all students
        }
    }

    return 0;
}
