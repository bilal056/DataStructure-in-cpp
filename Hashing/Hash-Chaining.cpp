#include <iostream>
using namespace std;

// Define a class for a student node
class Student_node
{
private:
    int Key; // Batch number
    string Student_rollNumber; // Student roll number
    string name; // Student name
    string father_name; // Father's name
    string department; // Department
    string degree; // Degree
    Student_node *next; // Pointer to next student node
public:
    // Constructor to initialize a student node
    Student_node(int key, string Student_rollnumber, string Name, string fatherName, string Department, string Degree)
    {
        Key = key;
        Student_rollNumber = Student_rollnumber;
        name = Name;
        father_name = fatherName;
        department = Department;
        degree = Degree;
        this->next = nullptr;
    }
    friend class linkedList;
};

// Define a class for a linked list of students
class linkedList
{
private:
    Student_node *head; // Head of the linked list
    int length; // Length of the linked list

public:
    // Constructor to initialize the linked list
    linkedList()
    {
        head = NULL;
        length = 0;
    }

    // Method to insert a new student into the linked list
    void insert(int key, string Student_Rollnumber, string Name, string fatherName, string Department, string Degree)
    {
        // Create a new student node
        Student_node *newnode = new Student_node(key, Student_Rollnumber, Name, fatherName, Department, Degree);
        if (head == NULL)
        {
            head = newnode; // If the list is empty, make the new node the head
        }
        else
        {
            Student_node *curr = head;
            bool found = false;

            // Check if a node exists for the batch
            while (curr != NULL)
            {
                if (curr->Key == key)
                {
                    found = true; // If a node for the batch is found, set found to true
                    break;
                }
                curr = curr->next;
            }

            // If a node for the batch exists, add the new node at the end
            if (found)
            {
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }
                curr->next = newnode;
            }
            else
            {
                // If no node for the batch exists, add the new node as the head
                newnode->next = head;
                head = newnode;
            }
            length++;
        }
    }

    // Method to remove a student from the linked list
    void remove_student(int key, string student_rollnumber)
    {
        if (head == NULL)
        {
            cout << "list does not exists" << endl;
            return;
        }
        Student_node *curr = head;
        Student_node *slow = NULL;

        // Find the student node to remove
        while (curr->next != NULL && curr->Student_rollNumber != student_rollnumber)
        {
            slow = curr;
            curr = curr->next;
        }

        if (curr == NULL)
        {
            cout << "ID not found!!" << endl;
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
        cout << "Student with ID :" << student_rollnumber << "has been removed successfully" << endl;
    }

    // Method to search for a student by ID
    void search_byRollnumber(int key, string student_rollnumber)
    {
        if (head == nullptr)
        {
            cout << "list does not exists" << endl;
            return;
        }

        Student_node *curr = head;

        // Search for the student by ID
        while (curr != NULL && curr->Student_rollNumber != student_rollnumber)
        {
            curr = curr->next;
        }
        if (curr == NULL)
        {
            cout << "ID not found" << endl;
        }
        else
        {
            // Print the student details if found
            cout << " -------------------------- " << endl;
            cout << "|          ID found         |" << endl;
            cout << " -------------------------- " << endl;
            cout << " __________________________ " << endl;
            cout << "|ID: " << curr->Student_rollNumber << endl;
            cout << "|Name: " << curr->name << endl;
            cout << "|Father Name: " << curr->father_name << endl;
            cout << "|Department: " << curr->department << endl;
            cout << "|Degree: " << curr->degree << endl;
            cout << " __________________________ " << endl;

            cout << endl;
        }
    }

    // Method to search for students in a batch
    void search_batch_Wise(int key)
    {
        Student_node *curr = head;

        if (head == nullptr)
        {
            cout << "No students found for the given batch." << endl;
            return;
        }

        bool find = false;
        while (curr != nullptr)
        {
            if (key == curr->Key)
            {
                if (!find)
                {
                    cout << "Students for batch " << key << ":" << endl;
                    find = true;
                }

                cout << " ______________________________ " << endl;
                cout << "|ID: " << curr->Student_rollNumber << endl;
                cout << "|Name: " << curr->name << endl;
                cout << "|Father Name: " << curr->father_name << endl;
                cout << "|Department: " << curr->department << endl;
                cout << "|Degree: " << curr->degree << endl;
                cout << " ______________________________ " << endl;
            }
            curr = curr->next;
        }
        if (!find)
        {
            cout << "Students for batch  " << key << " Not found!!" << endl;
        }
    }

    // Method to display all students in the linked list
    void display()
    {
        Student_node *curr = head;
        while (curr != nullptr)
        {
            cout << " ______________________________ " << endl;
            cout << "|ID: " << curr->Student_rollNumber << endl;
            cout << "|Name: " << curr->name << endl;
            cout << "|Father Name: " << curr->father_name << endl;
            cout << "|Department: " << curr->department << endl;
            cout << "|Degree: " << curr->degree << endl;
            cout << " ______________________________ " << endl;
            curr = curr->next;
        }
    }
};

// Define a class for a hash table of linked lists
class hashTable
{
private:
    int size; // Size of the hash table
    linkedList *table; // Array of linked lists

public:
    // Constructor to initialize the hash table
    hashTable(int size)
    {
        this->size = size;
        table = new linkedList[size]; // Create an array of linked lists
    }
    // Destructor to free memory allocated for the hash table
    ~hashTable()
    {
        delete[] table;
    }

    // Hash function to determine the index in the array for a given key
    int function(int k)
    {
        return k % size;
    }

    // Method to insert a student into the hash table
    void insert(int key, string Student_rollnumber, string Name,
                string fatherName, string Department, string Degree)
    {
        int Key = function(key);
        table[Key].insert(key, Student_rollnumber, Name, fatherName, Department, Degree);
    }

    // Method to remove a student from the hash table
    void remove_student(int key, string student_rollnumber)
    {
        int Key = function(key);
        table[Key].remove_student(key, student_rollnumber);
    }

    // Method to search for a student by ID in the hash table
    void search_id(int key, string student_rollnumber)
    {
        int Key = function(key);
        table[Key].search_byRollnumber(key, student_rollnumber);
    }

    // Method to search for students in a batch in the hash table
    void search_batch_Wise(int key)
    {
        int Key = function(key);
        table[Key].search_batch_Wise(key);
    }

    // Method to display all students in the hash table
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "   Batch:  " << i << endl;
            table[i].display();
        }
    }
};

// Main function to test the hash table implementation
int main()
{
    int data[10];
    int size = sizeof(data) / sizeof(data[0]);

    hashTable H(size); // Create a hash table with the specified size

    // Insert some students into the hash table ( for pre check conditions )
    H.insert(0, "01p-0001", "bilal", "farooq", "CS", "Artificial intelligence");
    H.insert(0, "01p-0002", "ubaid_ur_rehman", "bilal", "CS", "Artificial intelligence");
    H.insert(1, "02p-0001", "asher", "naveed", "SE", "software engineering");

    int choose = 0;
    while (choose != 6)
    {
        // Display the menu
        cout << " ______________________________ " << endl;
        cout << "|1. Add a Student              |" << endl;
        cout << "|2. Search for Student         |" << endl;
        cout << "|3. Search Student (Batch wise)|" << endl;
        cout << "|4. Remove a student           |" << endl;
        cout << "|5. Display All Students       |" << endl;
        cout << "|6. Exit                       |" << endl;
        cout << " ______________________________ " << endl;
        cout << "Enter your choice: ";
        cin >> choose;

        // Perform the selected operation
        if (choose == 1)
        {
            // Add a student
            int key;
            string rollnumber;
            string name;
            string Father_name;
            string department;
            string degree;

            cout << "Enter Batch: ";
            cin >> key;

            cout << "Enter Student roll number (00p-0000): ";
            cin >> rollnumber;

            cout << "Enter Student Name: ";
            cin >> name;

            cout << "Enter Father Name: ";
            cin >> Father_name;

            cout << "Enter Department: ";
            cin >> department;

            cout << "Enter Degree: ";
            cin >> degree;

            H.insert(key, rollnumber, name, Father_name, department, degree);
        }
        else if (choose == 2)
        {
            // Search for a student by roll Number
            int batch;
            string rollnumber;
            cout << "Enter  ( Batch [0] & roll number [12p-1234] ) to search for: ";
            cin >> batch >> rollnumber;

            H.search_id(batch, rollnumber);
        }
        else if (choose == 3)
        {
            // Search for students in a specific Batch
            int year;
            cout << "Enter year for batch wise searching [0]";
            cin >> year;

            H.search_batch_Wise(year);
        }
        else if (choose == 4)
        {
            // Remove a student
            int batch;
            string rollnumber;
            cout << "Enter  ( Batch [0] & roll number [12p-1234] ) number to remove: ";
            cin >> batch >> rollnumber;

            H.remove_student(batch, rollnumber);
        }
        else if (choose == 5)
        {
            // Display all students
            cout << "Display All students" << endl;

            H.display();
        }
    }
    return 0;
}

int key = function(key);
table[key].insert(key,);