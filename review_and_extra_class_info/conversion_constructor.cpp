#include <iostream>
using namespace std;

class Distance {
private:
    double meters;

public:
    // Default constructor
    Distance() : meters(0.0) {}

    // Conversion constructor: Convert int to Distance (meters)
    Distance(int m) : meters(m) {
        cout << "Conversion constructor (int to Distance) called." << endl;
    }

    // Conversion constructor: Convert double to Distance (meters)
    Distance(double m) : meters(m) {
        cout << "Conversion constructor (double to Distance) called." << endl;
    }

    // Function to display the distance
    void display() const {
        cout << meters << " meters" << endl;
    }
};

int main() {
    // Implicit conversion from int to Distance
    Distance d1 = 10;  
    d1.display();      

    // Implicit conversion from double to Distance
    Distance d2 = 15.75;  
    d2.display();         

    // Explicit conversion using the constructor
    Distance d3 = Distance(25);  
    d3.display();                

    // Explicit conversion using the constructor for double
    Distance d4 = Distance(50.5);  
    d4.display();                  

    return 0;
}