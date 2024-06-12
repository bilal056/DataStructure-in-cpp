#include <iostream>
using namespace std;

#define size 3
class arrQueue
{
private:
    int *arr;
    int capacity;
    int elements;
    int rear;
    int front;

public:
    arrQueue()
    {
        arr = new int[size];
        elements = front = 0;
        capacity = size;
        rear = -1;
    }
    bool isEmpty()
    {
        return elements == 0;
    }
    bool isFull()
    {
        return capacity == elements;
    }
    void inQueue(int val)
    {
        if (isFull())
        {
            cout << "overFlow" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        elements++;
    }
    int deQueue()
    {
        if (isEmpty())
        {
            cout << "underFlow" << endl;
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % capacity;
        elements--;
        return val;
    }
    int checkFront()
    {
        return front;
    }
void arranged()
{
    int *arr2 = new int[size]; // array to store negative integers
    int *arr3 = new int[size]; // array to store positive integers
    int temp = 0;
    int index2 = 0; // index for arr2
    int index3 = 0; // index for arr3

    // Separate positive and negative integers into arr2 and arr3
    for (int i = 0; i < size; i++)
    {
        temp = deQueue();
        if (temp < 0)
        {
            arr2[index2++] = temp;
        }
        else
        {
            arr3[index3++] = temp;
        }
    }

    // Reset the queue
    // clear();

    // Rearrange the queue according to the specified pattern
    for (int i = 0; i < index3; i++)
    {
        // Add positive integer
        inQueue(arr3[i]);

        // Add two negative integers if available
        if (i * 2 < index2)
        {
            inQueue(arr2[i * 2]);
        }
        if (i * 2 + 1 < index2)
        {
            inQueue(arr2[i * 2 + 1]);
        }
    }

    // Add remaining negative integers
    for (int i = index3 * 2; i < index2; i++)
    {
        inQueue(arr2[i]);
    }

    // Free memory allocated for arrays
    delete[] arr2;
    delete[] arr3;
}

    void Display()
    {

        int temp = front;
        int count = 0;
        while (count < elements)
        {
            cout << " " << arr[temp] << endl;
            temp = (temp + 1) % capacity;
            count++;
        }
    }
};
int main()
{
    arrQueue al;

    al.inQueue(-3);
    al.inQueue(2);
    al.inQueue(-4);

    al.arranged();
    al.Display();

    return 0;
}