#include <iostream>
using namespace std;

// Class for an Arraylist with basic operations like insertion, deletion, update, find, etc.
class Arraylist {
private:
    int length; // Current number of elements in the array
    int size;   // Maximum size of the array
    int *arr;   // Pointer to the array
    int *temp;  // Temporary pointer for traversing the array

public:
    // Constructor to initialize the array with a given size
    Arraylist(int size) {
        length = 0;
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = -1; // Initialize all elements to -1
        }
        temp = nullptr;
    }

    // Destructor to free the allocated memory
    ~Arraylist() {
        delete[] arr;
    }

    // Set the temporary pointer to the start of the array
    void start() {
        temp = arr;
    }

    // Move the temporary pointer to the next element
    void next() {
        temp++;
    }

    // Move the temporary pointer to the previous element
    void back() {
        temp--;
    }

    // Move the temporary pointer to the end of the array
    void tail() {
        start();
        for (int i = 0; i < length; i++) {
            next();
        }
    }

    // Insert a value at a specified position in the array
    void Insert(int value, int position) {
        start();
        if (length == size) {
            cout << "Array is already full" << endl;
        } else if (position >= 1) {
            for (int i = 1; i < position; i++) {
                next();
            }
            if (*temp == -1) {
                *temp = value;
                length += 1;
                cout << "Value has inserted successfully " << endl;
            } else {
                cout << "Value already present " << endl;
            }
        } else {
            cout << "Invalid Position " << endl;
        }
    }

    // Insert a value at the end of the array, resizing if necessary
    void insert_array_to_Last(int value) {
        start();
        if (size == length) {
            size++;
            tail();
            *temp = value;
            length += 1;
            cout << "Value has inserted successfully " << endl;
        }
    }

    // Update the first occurrence of a value in the array
    void Update(int value, int updatevalue) {
        start();
        for (int i = 0; i < size; i++) {
            if (*temp == value) {
                *temp = updatevalue;
                temp = arr;
            } else {
                next();
            }
        }
    }

    // Remove an element at a specified position and shift remaining elements
    void removeByPosition(int position) {
        if (position < 1 || position > length) {
            cout << "No such number Exists " << endl;
        }

        start();
        for (int i = 0; i < position - 1; i++) {
            next();
        }

        for (int i = position; i < length; i++) {
            *temp = *(temp + 1);
            next();
        }
        length--;
        size--;
    }

    // Find and display the index of a value in the array
    void find(int value) {
        start();
        for (int i = 0; i < size; i++) {
            if (temp == nullptr) {
                cout << "No Such Number Exists!! " << endl;
                return;
            }
            if (value == *temp) {
                cout << "found the number you entered: " << *temp << endl;
                return;
            } else {
                next();
            }
        }
        cout << "No Such Number Exists!!" << endl;
    }

    // Get the value at a specified position
    int get_Value(int position) {
        start();
        for (int i = 0; i < position; i++) {
            next();
        }
        return *temp;
    }

    // Find and display the current length of the array (number of non -1 elements)
    void find_lenght() {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (*temp != -1) {
                count++;
            }
        }
        cout << "Total length of the array is: " << count << endl;
    }

    // Copy the contents of another Arraylist into this one
    void copyArray(Arraylist *obj) {
        delete[] arr;

        size = obj->size;
        arr = new int[size];
        length = obj->length;

        for (int i = 0; i < size; i++) {
            arr[i] = obj->arr[i];
        }
    }

    // Reverse the elements of the array
    void reverseArray() {
        int *start = arr;
        int *end = arr + length - 1;
        int temp;

        while (start < end) {
            temp = *end;
            *end = *start;
            *start = temp;
            start++;
            end--;
        }
    }

    // Sort the array in ascending order using bubble sort
    void ArraySorting() {
        int temp = 0;
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // Set the temporary pointer to the start of the array (sorted list)
    void sortedlist() {
        temp = arr;
    }

    // Rearrange the array such that even indexed positions have even values and odd indexed positions have odd values
    void rearranged() {
        temp = arr;
        int currvalue = 0;
        for (int i = 0; i < length - 1; i += 2) {
            if (*temp % 2 != i % 2) {
                temp++;
                i--;
            } else {
                currvalue = *temp;
                *temp = *(temp + 1);
                *(temp + 1) = currvalue;
                temp += 2;
            }
        }
    }

    // Display the elements of the array, skipping -1 values
    void display() {
        start();
        for (int i = 0; i < size; i++) {
            if (*temp != -1) {
                cout << *temp << " ";
            }
            temp++;
        }
    }

    // Display all elements of the array including -1 values
    void display2() {
        start();
        for (int i = 0; i < size; i++) {
            cout << *temp << " ";
            next();
        }
    }
};

int main() {
    int size;

    cout << "Enter array size: ";
    cin >> size;
    Arraylist myarr(size);

    // Insertion of elements into the array
    cout << " ----- Insertion -----  " << endl << endl;
    myarr.Insert(1, 1);
    myarr.Insert(2, 2);
    myarr.Insert(3, 3);
    myarr.Insert(4, 4);
    myarr.Insert(5, 5);
    myarr.Insert(6, 6);
    myarr.Insert(1, 7); // This will display "Value already present" as 1 is already inserted
    myarr.Insert(3, 8); // This will display "Value already present" as 3 is already inserted
    cout << "----- Array 1 -----  " << endl << endl;
    myarr.display();
    cout << endl;

    // Rearrange array such that even index has even value and odd index has odd value
    myarr.rearranged();
    myarr.display();
    cout << endl;

    // Insert element at the end of the array
    cout << "----- insert value at the end of the array  -----  " << endl;
    myarr.insert_array_to_Last(2);
    myarr.display2();
    cout << endl;

    // Update specific elements in the array
    cout << "----- Updation -----  " << endl << endl;
    myarr.Update(15, 20); // This will not change anything as 15 is not in the array
    myarr.Update(12, 25); // This will not change anything as 12 is not in the array
    myarr.display();
    cout << endl;

    // Remove elements at specific positions
    cout << "----- Remove -----  " << endl << endl;
    // myarr.removeByPosition(2); // Uncomment to test remove function
    // myarr.removeByPosition(4); // Uncomment to test remove function
    // myarr.display2();
    cout << endl;

    // Find elements in the array
    cout << "----- Find value -----  " << endl << endl;
    myarr.find(10); // This will display "No Such Number Exists!!" as 10 is not in the array
    myarr.find(12); // This will display "No Such Number Exists!!" as 12 is not in the array
    myarr.find(14); // This will display "No Such Number Exists!!" as 14 is not in the array

    // Get element at specific position
    cout << "----- Get element at the given position -----  " << endl;
    cout << "Element at position 2: " << myarr.get_Value(2) << endl << endl;

    // Find current length of the array (number of non -1 elements)
    cout << "----- Find Length -----  " << endl;
    myarr.find_lenght();
    cout << endl;

    // Reverse the array elements
    cout << "----- Reverse An Array -----  " << endl;
    myarr.reverseArray();
    myarr.display();
    cout << endl;

    // Sort the array elements
    cout << "----- Sort An Array -----  " << endl;
    myarr.ArraySorting();
    myarr.display();
    cout << endl;

    // Copy the array to another object
    cout << "----- Copy Array -----  " << endl;
    Arraylist newarr(size);
    newarr.copyArray(&myarr);
    newarr.display();
    cout << endl;

    return 0;
}
