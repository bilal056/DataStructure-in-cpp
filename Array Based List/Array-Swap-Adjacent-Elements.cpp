#include <iostream>
using namespace std;

/*
This program demonstrates the use of function pointers in C++ to perform various operations on an array, such as assigning values, printing elements, checking the sum of elements, and swapping adjacent elements.
It defines four functions: Assign_Values, printElements, sum_OfArray_check, and swapElements, each performing a specific task on the array.
The main function uses function pointers to call these functions based on user input.

*/


// Function to assign values to an array
void Assign_Values(int *arr, int size)
{
    int arr2[size]; // Create a temporary array to store input values

    cout << "\n -- Enter numbers of Array -- ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr2[i]; // Input values into the temporary array

        arr[i] = arr2[i]; // Copy values from temporary array to the main array
    }
}

// Function to print elements of an array
void printElements(int *arr, int size)
{
    int *temp = arr; // Create a temporary pointer to the array
    cout << "#point 1" << endl;
    cout << "Array  Element" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << *temp << " "; // Print the element pointed to by temp
        temp++; // Move temp to the next element
    }
}

// Function to check if the sum of array elements is equal to a given number
void sum_OfArray_check(int *arr, int addition, int size)
{
    cout << "\n#point 2" << endl;
    int sum = 0;
    int *temp = arr; // Create a temporary pointer to the array
    for (int i = 0; i < size; i++)
    {
        sum += *temp; // Add the element pointed to by temp to the sum
        temp++; // Move temp to the next element
    }
    cout << " sum of array  " << sum << endl;

    if (sum == addition)
    {
        cout << "The Number You Entered Is Equal To Array " << endl;
    }
    else
    {
        cout << "\n The Number You Entered Is Not Equal To Array " << endl;
    }
}

// Function to swap adjacent elements of an array
void swapElements(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i += 2)
    {
        temp = arr[i]; // Store the current element in temp
        arr[i] = arr[i + 1]; // Swap the current element with the next element
        arr[i + 1] = temp; // Set the next element to the value stored in temp
    }
}

int main()
{
    int size = 6; // Default size of the array
    int employee[size]; // Array to store employee numbers
    int *arr = &employee[0]; // Pointer to the array
    int input_number; // Number to compare with the sum of array elements

    // Part 1: Assign values to the array
    cout << "\n -- Enter Size of Array -- ";
    cin >> size;

    void (*numberAssign)(int *, int); // Function pointer for Assign_Values function
    numberAssign = &Assign_Values;
    numberAssign(arr, size);

    void (*display)(int *, int); // Function pointer for printElements function
    display = &printElements;
    display(arr, size);

    // Part 2: Check if the sum of array elements is equal to a given number
    cout << "\n -- Enter a number to compare with Array -- ";
    cin >> input_number;

    void (*sum_check)(int *, int, int); // Function pointer for sum_OfArray_check function
    sum_check = &sum_OfArray_check;
    sum_check(arr, input_number, size);

    // Part 3: Swap adjacent elements of the array
    void (*e_swap)(int *, int); // Function pointer for swapElements function
    e_swap = &swapElements;
    e_swap(arr, size);
    display(arr, size); // Display the modified array

    return 0;
}
