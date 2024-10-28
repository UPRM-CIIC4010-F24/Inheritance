#include <iostream>
using namespace std;

// Abstract base class (Shape) with a pure virtual function
class Shape {
public:
    virtual double area() const = 0;  // Pure virtual function making Shape an abstract class
};

// Another abstract class with a pure virtual function
class Printable {
public:
    virtual void print() const = 0;  // Pure virtual function for printing
};

// Another abstract class for drawable objects
class Drawable {
public:
    virtual void draw() const = 0;  // Pure virtual function for drawing
};

// Rectangle class inherits from Shape, Printable, and Drawable
class Rectangle : public Shape, public Printable, public Drawable {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Implement area() from Shape
    double area() const override {
        return width * height;
    }

    // Implement print() from Printable
    void print() const override {
        cout << "Rectangle: width = " << width << ", height = " << height << ", area = " << area() << endl;
    }

    // Implement draw() from Drawable
    void draw() const override {
        for(int i = 0; i < width; i++) 
            cout << "*";
        cout << endl;
        for(int i = 0; i < height; i++) {
            cout << "*";
            for(int j = 0; j < width - 2; j++) 
                cout << " ";
            cout << "*\n";
        }
        for(int i = 0; i < width; i++) 
            cout << "*";
        cout << endl;

    }
};


int main() {
    // Create a Rectangle object
    Rectangle rect(40.0, 2.0);

    // Call functions from different base classes
    rect.print();      // Printable functionality
    rect.draw();       // Drawable functionality
    cout << "Area: " << rect.area() << endl;  // Shape functionality

    return 0;
}