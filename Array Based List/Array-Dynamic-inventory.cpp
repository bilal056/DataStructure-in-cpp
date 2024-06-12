#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
This program takes user input for the size of the inventory and random quantities of products.
It then calculates and displays the average stock level, counts and displays the total products that are critically low (below average stock), 
finds and displays the top selling product, and sorts the products array by popularity.
*/

// Function prototypes
int AvgStockLevel(int *products, int size); // Calculate and return the average stock level
int CriticalProducts(int *products, int size, int AverageStocks); // Count and return the number of products with stock levels below average
int TopSellingProducts(int *products, int size); // Find and return the top selling product
void sortByPopularity(int *products, int size); // Sort products array in descending order of popularity

int main()
{
    // Variable declarations
    int size;
    int AverageStocks;
    int TotalCriticalProducts;
    int TopProducts;

    // User input for inventory size
    cout << "Enter the desired size of the inventory you want: ";
    cin >> size;

    // Dynamic memory allocation for products array
    int *products = new (nothrow) int[size];

    // User input for random quantities of products
    cout << "Enter " << size << " random quantities of products: ";

    // Randomize seed
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        cin >> products[i];
    }

    // Display entered numbers
    cout << "The numbers: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << products[i] << endl;
    }
    cout << endl;

    // First point: Calculate and display average stock level
    AverageStocks = AvgStockLevel(products, size);
    cout << endl;

    // Second point: Calculate and display total critical products
    TotalCriticalProducts = CriticalProducts(products, size, AverageStocks);
    cout << endl;

    // Third point: Find and display the top selling product
    TopProducts = TopSellingProducts(products, size);
    cout << endl;

    // Sorting: Sort products array by popularity (quantity sold)
    sortByPopularity(products, size);
    cout << "Sorted products by popularity: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << products[i] << endl;
    }
    cout << endl;

    // Free allocated memory
    delete[] products;

    return 0;
}

// Function to calculate average stock level
int AvgStockLevel(int *products, int size)
{
    int temp = 0;
    int AverageStock;
    for (int i = 0; i < size; i++)
    {
        temp += products[i];
    }
    AverageStock = temp / size;
    cout << "Average Stock Level Is: " << AverageStock << endl;

    return AverageStock;
}

// Function to count products with stock levels below average
int CriticalProducts(int *products, int size, int AverageStocks)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (products[i] < AverageStocks)
        {
            count++;
        }
    }

    cout << "Total products that are critically low: " << count << endl;
    return count;
}

// Function to find the top selling product
int TopSellingProducts(int *products, int size)
{
    int secondmax;
    int Max = 0;
    for (int i = 0; i < size; i++)
    {
        if (products[i] > Max)
        {
            Max = products[i];
        }
    }

    secondmax = Max;

    cout << "Top Selling Product: " << Max << endl;
    return secondmax;
}

// Function to sort products array by popularity
void sortByPopularity(int *products, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (products[j] < products[j + 1])
            {
                // Swap elements
                int temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}
