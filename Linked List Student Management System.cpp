#include <iostream>
using namespace std;

/*
 - This program can be used as a simple student management system for a small school or educational institution. 

 - It allows users to add new student records, remove existing records, search for specific students, and display all student records along with their GPAs.
Additionally, it can calculate the average GPA of all students in the system.

 - This system could be used by teachers or administrators to keep track of student information such as IDs, names, and GPAs.
It provides a straightforward interface for managing student records without the need for complex database systems.
*/



// Node structure for each student
class Student_node
{
public:
    int info1; // Student ID
    string info2; // Student Name
    double info3; // Student GPA
    Student_node *next; // Pointer to next student node

    // Constructor to initialize student node
    Student_node(int StudentID, string StudentName, double StudentGPA)
    {
        info1 = StudentID;
        info2 = StudentName;
        info3 = StudentGPA;
        next = NULL; // Initialize next pointer to NULL
    }
};

// Linked list class to manage student nodes
class linkedList
{
private:
    Student_node *head; // Pointer to the first student node in the list
    int length; // Number of students in the list

public:
    // Constructor to initialize the linked list
    linkedList()
    {
        head = NULL; // Initialize head pointer to NULL (empty list)
        length = 0; // Initialize length to 0
    }

    // Method to insert a new student node into the list
    void insert(int StudentID, string StudentName, double StudentGPA)
    {
        // Create a new student node
        Student_node *newnode = new Student_node(StudentID, StudentName, StudentGPA);

        // If the list is empty, set the new node as the head
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            // Traverse the list to find the last node
            Student_node *slow = NULL;
            Student_node *curr = head;
            for (int i = 0; i < length; i++)
            {
                slow = curr;
                curr = curr->next;
            }

            // Insert the new node at the end of the list
            slow->next = newnode;
            newnode->next = curr;
        }
        length++; // Increment the length of the list
    }

    // Method to remove a student node from the list based on Student ID
    void deletion_using_ID(int ID)
    {
        // Check if the list is empty
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        // Traverse the list to find the node with the given Student ID
        Student_node *curr = head;
        Student_node *slow = NULL;
        while (curr != NULL && curr->info1 != ID)
        {
            slow = curr;
            curr = curr->next;
        }

        // If the node is not found, display a message and return
        if (curr == NULL)
        {
            cout << "Student with ID " << ID << " not found." << endl;
            return;
        }

        // Remove the node from the list
        if (slow != NULL)
        {
            slow->next = curr->next;
        }
        else
        {
            head = curr->next;
        }
        delete curr; // Delete the removed node
        length--; // Decrement the length of the list
    }

    // Method to search for a student node in the list based on Student ID
    void search(int ID)
    {
        // Check if the list is empty
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        // Traverse the list to find the node with the given Student ID
        Student_node *curr = head;
        while (curr != NULL && curr->info1 != ID)
        {
            curr = curr->next;
        }

        // If the node is not found, display a message
        if (curr == NULL)
        {
            cout << "Student with ID " << ID << " not found." << endl;
            cout << "-----------------------" << endl;
        }
        else
        {
            cout << "-----------------------" << endl;
            // If the node is found, display the student information
            cout << "Student found:" << endl;
            cout << "ID: " << curr->info1 << ", Name: " << curr->info2 << ", GPA: " << curr->info3 << endl;
            cout << "-----------------------" << endl;
        }
    }

    // Method to calculate and display the average GPA of all students in the list
    void Calculate_averageGPA()
    {
        // Check if the list is empty
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        // Traverse the list to calculate the total GPA
        Student_node *curr = head;
        double total = 0;
        while (curr != NULL)
        {
            total += curr->info3;
            curr = curr->next;
        }

        // Calculate the average GPA
        double avg = total / length;

        // Display the average GPA and the total number of students
        cout << "-----------------------" << endl;
        cout << "Average GPA: " << avg << endl;
        cout << "Total Students: " << length << endl;
        cout << "-----------------------" << endl;
    
    }

    // Method to display all students in the list
    void Display()
    {
        // Check if the list is empty
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        // Traverse the list and display each student's information
        Student_node *curr = head;
        cout << "-----------------------" << endl;
        while (curr != NULL)
        {
            cout << "ID: " << curr->info1 << ", Name: " << curr->info2 << ", GPA: " << curr->info3 << endl;
            curr = curr->next;
            cout << "-----------------------" << endl;
        }
    }
};

// Main function to test the linked list implementation
int main()
{
    linkedList l1; // Create a linked list object

    int choice = 0;
    while (choice != 6)
    {
        // Display menu options
        cout << " __________________________" << endl;
        cout << "|1. Add a Student          |" << endl;
        cout << "|2. Remove a student       |" << endl;
        cout << "|3. Search for Student     |" << endl;
        cout << "|4. Display All Students   |" << endl;
        cout << "|5. Calculate Average      |" << endl;
        cout << "|6. Exit                   |" << endl;
        cout << "|Enter your choice:        |" << endl;
        cout << " __________________________" << endl;


        // Perform action based on user choice
        switch (choice)
        {
        case 1:
            int id;
            string name;
            double GPA;

            cout << "Enter Student ID: ";
            cin >> id;

            cout << "Enter Student Name: ";
            cin >> name;

            cout << "Enter Student GPA: ";
            cin >> GPA;

            l1.insert(id, name, GPA); // Insert a new student into the list
            break;
        case 2:
            int removeID;
            cout << "Enter Student ID to remove: ";
            cin >> removeID;
            l1.deletion_using_ID(removeID); // Remove a student from the list
            break;
        case 3:
            int searchID;
            cout << "Enter Student ID to search for: ";
            cin >> searchID;
            l1.search(searchID); // Search for a student in the list
            break;
        case 4:
            l1.Display(); // Display all students in the list
            break;
        case 5:
            l1.Calculate_averageGPA(); // Calculate and display the average GPA
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}
