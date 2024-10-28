#include<iostream>
#include<string>
#include<cmath>

using namespace std;

// Base class
class Shape {
public:
    // Virtual function to be overridden by derived classes
    virtual double area() const {
        return 0;  // Default implementation
    }

    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}

    // Override the area function for Circle
    double area() const override {
        return M_PI * radius * radius;  
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Override the area function for Rectangle
    double area() const override {
        return width * height;  // Area of a rectangle: width * height
    }
};

int main() {
    // Create a pointer to base class Shape
    Shape* shape;

    // Create a Circle object and assign it to the Shape pointer
    Circle circle(5.0);
    shape = &circle;
    cout << "Area of Circle: " << shape->area() << endl;  // Output: Area of Circle: 78.5398

    // Create a Rectangle object and assign it to the Shape pointer
    Rectangle rectangle(4.0, 6.0);
    shape = &rectangle;
    cout << "Area of Rectangle: " << shape->area() << endl;  // Output: Area of Rectangle: 24

    return 0;
}