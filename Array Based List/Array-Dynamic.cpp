
#include <iostream>

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

public:
    DynamicArray(int initialCapacity) {
        arr = new int[initialCapacity];
        size = 0;
        capacity = initialCapacity;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isIndexEmpty(int index) const {
        return index >= size;
    }

    // Other functions to manage the array (e.g., insert, remove) would go here

    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray dynArray(10);

    // Assuming you have added elements to the array
    int indexToCheck = 5;

    if (dynArray.isIndexEmpty(indexToCheck)) {
        std::cout << "Index " << indexToCheck << " is empty." << std::endl;
    } else {
        std::cout << "Index " << indexToCheck << " is not empty." << std::endl;
    }

    return 0;
}

