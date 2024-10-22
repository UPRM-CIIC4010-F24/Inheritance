#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Parallelogram {

    private:
    double side;
    double base;
    double angle;// In degrees.

    public:
    Parallelogram(double side, double base, double angle) {
        this->side = side;
        this->base = base;
        this->angle = angle;
        cout << "Parallelogram constructor" << endl;
    }
    Parallelogram() : Parallelogram(10, 10, 90){}

    double getSide() const {
        return side;
    }

    void setSide(double value) {
        side = value;
    }

    double getBase() const {
        return base;
    }

    void setBase(double value) {
        base = value;
    }

    double getAngle() const {
        return angle;
    }

    void setAngle(double value) {
        angle = value;
    }

    double getArea() {
        double height = getSide() * sin(angle * M_PI/180);
        return getBase() * height;
    }
    double getPerimeter() {
        return 2 * (getBase() + getSide());
    }
    string getShapeName() {
        return "Parallelogram";
    }
};

/*
    Overloading for the Paralellogram to get printed
*/
ostream& operator<<(ostream& out, Parallelogram& shape) {
    // Since parallelogram is a constant the methods it can access must be constant as well
    return out << shape.getShapeName() + "(" << shape.getSide() <<
                ", " << shape.getBase() << ", " << shape.getAngle() <<
                ")" <<endl;
}


class Rectangle : public Parallelogram {
 
    
    public:
    Rectangle(double width, double height) : Parallelogram(height, width, 90) {
        cout << "Rectangle constructor" << endl;
    }
    Rectangle() {}

    string getShapeName() {
        return "Rectangle";
    }

};



int main() {
    Parallelogram shape1 = Parallelogram(10, 25, 30);
    cout << shape1;
    cout << "Has area: " << shape1.getArea() << endl;
    cout << "Has Perimeter: " << shape1.getPerimeter() << endl;
    cout << "Shape: " << shape1.getShapeName() << endl;

    Rectangle shape2 = Rectangle(15, 20);
    cout << "==============\n";
    cout << shape2;
    cout << "Has area: " << shape2.getArea() << endl;
    cout << "Has Perimeter: " << shape2.getPerimeter() << endl;
    cout << "Shape: " << shape2.getShapeName() << endl;


    // Parallelogram *shape3 = new Rectangle(10, 15);
    // cout << "==============\n";
    // cout << "Has area: " << shape3->getArea() << endl;
    // cout << "Has Perimeter: " << shape3->getPerimeter() << endl;
    // cout << "Shape: " << shape3->getShapeName() << endl; 

    // Parallelogram *shape4;
    // shape4 = static_cast<Parallelogram *>(&shape2);
    // cout << "==============\n";
    // cout << "Has area: " << shape4->getArea() << endl;
    // cout << "Has Perimeter: " << shape4->getPerimeter() << endl;
    // cout << "Shape: " << shape4->getShapeName() << endl;

 

}