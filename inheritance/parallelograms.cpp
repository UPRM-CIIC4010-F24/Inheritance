#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Parallelogram {

    private:
    double side;
    double base;
    double angle;// In degrees.

    protected:
    void saySomething() { cout << "Im protected";}

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
    virtual string getShapeName() {
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

    virtual string getShapeName() override{
        saySomething();
        return "Rectangle";
    }
    void sayHello() {
        cout << "HELLO!\n";
    }

};

class Square : public Rectangle {
    public:
    Square(double side): Rectangle(side, side) {}
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


    Parallelogram *shape3 = new Rectangle(10, 15);
    cout << "==============\n";
    cout << "Has area: " << shape3->getArea() << endl;
    cout << "Has Perimeter: " << shape3->getPerimeter() << endl;
    cout << "Shape: " << shape3->getShapeName() << endl; 


    // Parallelogram *shape4 = new Rectangle(15, 20);
    // Rectangle *shapeFour = static_cast<Rectangle *>(shape4);
    // shapeFour->sayHello();
    // cout << "==============\n";
    // cout << "Has area: " << shapeFour->getArea() << endl;
    // cout << "Has Perimeter: " << shapeFour->getPerimeter() << endl;
    // cout << "Shape: " << shapeFour->getShapeName() << endl;

    // Square shape5 = Square(15);
    // cout << "==============\n";
    // cout << shape5;
    // cout << "Has area: " << shape5.getArea() << endl;
    // cout << "Has Perimeter: " << shape5.getPerimeter() << endl;
    // cout << "Shape: " << shape5.getShapeName() << endl;
    // shape5.sayHello();

    // Rectangle *shape6 = new Square(10);
    // cout << "==============\n";
    // cout << "Has area: " << shape6->getArea() << endl;
    // cout << "Has Perimeter: " << shape6->getPerimeter() << endl;
    // cout << "Shape: " << shape6->getShapeName() << endl;

 

}