#include <iostream>
using namespace std;

// Forward declaration of class B
class B;

// Class A definition
class A {
private:
    int dataA;

public:
    // Constructor to initialize dataA
    A(int value) : dataA(value) {}

    // Declare class B as a friend of class A
    // This allows class B to access the private members of class A
    friend class B;
};

// Class B definition
class B {
public:
    // Function that accesses the private member of class A
    void displayAData(A& objA) {
        cout << "Data from class A: " << objA.dataA << endl;
    }

    // A member of class B
    void modifyAData(A& objA, int newValue) {
        objA.dataA = newValue;
        cout << "Modified data in class A to: " << objA.dataA << endl;
    }
};

int main() {
    // Create an object of class A
    A objA(100);

    // Create an object of class B
    B objB;

    // Class B can access and modify private members of class A
    objB.displayAData(objA);   // Access private data of class A
    objB.modifyAData(objA, 200);  // Modify private data of class A
    objB.displayAData(objA);
    return 0;
}