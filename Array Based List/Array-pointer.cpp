#include<iostream>
using namespace std;

void printingSentence(char *name, int size) {
    for (int i = 0; i < size; i++) {
        cout << " " << name[i];
    }
    cout << endl;
}

void printSubstrings(char *name, int size, int start, int stop) {
    for (int i = start - 1; i <= stop; i++) {
        cout << name[i];
    }
    cout << endl;
}

int main() {
    int start;
    int stop;
    int i = 0;
    int size = 50;
    char *name = new char[size];

    cout << "Enter any sentence:" << endl;

    // Manually read characters until newline or array size limitm
    char character;
    while (i < size && (character = cin.get()) != '\n') {
        name[i] = character;
        i++;
    }
    name[i] = '\0';

    void (*printArray)(char*, int);
    printArray = &printingSentence;

    printArray(name, size);

    cout << "Enter starting point:" << endl;
    cin >> start;

    cout << "Enter ending point:" << endl;
    cin >> stop;

    void (*ArrayOfSubstring)(char*, int, int, int);
    ArrayOfSubstring = &printSubstrings;

    ArrayOfSubstring(name, size, start, stop);
    printArray(name, size);

    delete[] name;

    return 0;
}
