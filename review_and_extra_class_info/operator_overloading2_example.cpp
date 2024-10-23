#include <iostream>
using namespace std;

class IntArray {
private:
    int* arr;
    int size;

public:
    // Constructor to initialize the array with a given size
    IntArray(int s) : size(s) {
        arr = new int[size]; // Dynamically allocate memory for the array
        for (int i = 0; i < size; i++) {
            arr[i] = 0; // Initialize all elements to 0
        }
    }

    // Destructor to free dynamically allocated memory
    ~IntArray() {
        delete[] arr;
    }

    /*
    * These overload the [] operator, which is used for classes thta handle
    * collections or are expected to have subscripts. 
    * 
    * We have two version one fro writing and one for reading.
    */
    
    
    // Overload the [] operator to access elements (non-const version)
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds!" << endl;
            exit(1); // Terminate program for invalid index
        }
        return arr[index]; // Return reference to the element at the given index
    }

    // Overload the [] operator to access elements (const version)
    int operator[](int index) const {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds!" << endl;
            exit(1);
        }
        return arr[index]; // Return the value of the element at the given index (read-only)
    }

    // Function to get the size of the array
    int getSize() const {
        return size;
    }
};

int main() {
    // Create an IntArray object of size 5
    IntArray myArray(5);

    // Access elements using the overloaded [] operator
    for (int i = 0; i < myArray.getSize(); i++) {
        myArray[i] = i * 10; // Assign values to the array
    }

    // Display the array elements
    cout << "Array elements: ";
    for (int i = 0; i < myArray.getSize(); i++) {
        cout << myArray[i] << " "; // Use the [] operator to access elements
    }
    cout << endl;

    // Try accessing an out-of-bounds element
    // Uncommenting the line below will terminate the program with an error message
    // cout << myArray[10] << endl;

    return 0;
}