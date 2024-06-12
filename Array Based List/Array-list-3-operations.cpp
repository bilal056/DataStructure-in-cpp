#include <iostream>
using namespace std;

void printElements(int *ptr, int addition)
{
    cout << "#point 1" << endl;
    int sum_1 = 0;

    cout << "Array  Element" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << *ptr << " ";
        ptr++;
    }
    ptr = ptr - 5; // Reset the pointer to the beginning of the array


    cout << "#point 2" << endl;
    for (int i = 0; i < 5; i++)
    {
        sum_1 += *ptr;
        ptr++;
    }
    cout << "\n sum of array  " << sum_1;

    if (sum_1 == addition)
    {
        cout << "\nThe Number You Entered Is Equal To Array " << endl;
    }
    else
    {
        cout << "\n The Number You Entered Is Not Equal To Array " << endl;
    }
    ptr = ptr - 5;// Reset the pointer to the beginning of the array


    cout << "#point 3" << endl;
    int even = 0;
    int odd = 0;

    for (int i = 0; i < 5; i++)
    {
        if (*ptr % 2 == 0)
        {
            even = *ptr;
            *ptr = even+1;

        }
        else
        {
            odd = *ptr;
            *ptr = odd-1;
        }
        ptr++;
    }
    
    cout << "Array  Element" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << *ptr << " ";
        ptr++;
    }
}
int main()
{
    int employee[5] = {1, 2, 3, 4, 5};
    int *ptr1 = &employee[0];
    int addition;

    cout << "Enter a number ";
    cin >> addition;
    printElements(ptr1, addition);

    // void (*display)(int*); // this code also will work
    // display = &printElements;
    // display(ptr1);

    return 0;
}
