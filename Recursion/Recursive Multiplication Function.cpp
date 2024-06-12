#include <iostream>
using namespace std;

/*

 * The program defines a function Multiply_using_recursion that recursively calculates the product of two numbers a and b.
 It takes two integers Number1 and Number2 as input from the user.
 It calculates the product of Number1 and Number2 using the Multiply_using_recursion function.
 It then displays the result of the multiplication.

*/


// Function to multiply two numbers using recursion
int Multiply_using_recursion(int a, int b)
{
    // Base case: if b is 0, return 0
    if (b == 0)
    {
        return 0;
    }
    // If b is positive, recursively add a to the result (b-1) times
    else if (b > 0)
    {
        return a + Multiply_using_recursion(a, b - 1);
    }
    // If b is negative, recursively add the negative of a to the result (-b) times
    else
    {
        return -Multiply_using_recursion(a, -b);
    }
}

int main()
{
    int Number1, Number2, result;

    // Input two numbers from the user
    cout << "Enter any 2 numbers to multiply: ";
    cin >> Number1 >> Number2;

    // Calculate the result using the Multiply_using_recursion function
    result = Multiply_using_recursion(Number1, Number2);

    // Display the result
    cout << "The Multiplication of " << Number1 << " and " << Number2 << " is " << result << endl;

    return 0;
}
