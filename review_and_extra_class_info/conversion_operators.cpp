#include <iostream>
using namespace std;

class Distance {
private:
    double meters;

public:
    // Constructor to initialize the distance in meters
    Distance(double m = 0.0) : meters(m) {}

    // Conversion operator to convert Distance to double
    operator double() const {
        return meters;  // Returns the distance in meters
    }

    // Conversion operator to convert Distance to int (rounded)
    operator int() const {
        return static_cast<int>(meters + 0.5);  // Return the distance rounded to the nearest integer
    }

    // Function to display the distance in meters
    void display() const {
        cout << meters << " meters" << endl;
    }
};

int main() {
    // Create a Distance object
    Distance dist(15.75);

    // Implicit conversion to double
    double meters = dist;  // Conversion operator to double is called
    cout << "Distance in double: " << meters << endl;  

    // Implicit conversion to int
    int roundedMeters = dist;  // Conversion operator to int is called
    cout << "Distance rounded to nearest int: " << roundedMeters << endl;  

    // Explicit conversion using static_cast
    double metersExplicit = static_cast<double>(dist);  // Explicitly calling the conversion operator to double
    int roundedExplicit = static_cast<int>(dist);  // Explicitly calling the conversion operator to int

    // Output the explicitly casted values
    cout << "Explicitly casted to double: " << metersExplicit << endl;  
    cout << "Explicitly casted to int: " << roundedExplicit << endl;    

    return 0;
}