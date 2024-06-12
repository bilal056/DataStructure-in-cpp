#include <iostream>
using namespace std;
// used All list Operations Including start back tail and next

class list
{
private:
    int lenght;
    int size;
    int *temp;
    int *arr;

public:
    list(int size)
    {

        this->size = size;
        lenght = 0;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = -1;
        }
        temp = nullptr;
    }
    ~list()
    {

        delete[] arr;
    }
    void back()
    {
        temp--;
    }
    void next()
    {
        temp++;
    }
    void start()
    {
        temp = arr;
        insert(6,2);
    }
    void tail()
    {
        start();
        for (int i = 0; i < size; i++)
        {
            next();
        }
    }
    void insert(int value ,int position){
            if (lenght == size)
            {
                cout<<"Array is already full! "<<endl;
            }
            if (position< 1|| position> lenght+1)
            {
                cout<<"Array possition is already full! "<<endl;
            }
            tail();

            for (int i = lenght; i < position; i++)
            {
                if (lenght == position)
                {
                    *(temp+1) = *temp;
                    *temp = value;
                }
                else if (lenght != position)
                {
                    lenght++;
                }
                
                                
            }
            
    }
};

int main()
{

    return 0;
}