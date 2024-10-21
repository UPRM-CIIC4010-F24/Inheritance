#include <iostream>
using namespace std;

// Define a class Box
class Box {
private:
    double width;

public:
    // Constructor to initialize width
    Box(double w) : width(w) {}

    // Friend function declaration
    // This function is not a member of the class but can access private members
    friend void displayWidth(Box& b);

    void setWidth(double w) { this->width = w;}
};

// Friend function definition
void displayWidth(Box& b) {
    // Accessing private member of Box directly
    cout << "Width of the box: " << b.width << endl;
}

int main() {
    // Create a Box object
    Box myBox(10.5);
    myBox.setWidth(12.5);
    // Call the friend function to display the width of the box
    displayWidth(myBox);

    return 0;
}