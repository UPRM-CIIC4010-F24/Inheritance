#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char* name;
    int age;

public:
    // Constructor to initialize Person with a name and age
    Person(const char* n, int a) {
        age = a;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        cout << "Constructor called for " << name << endl;
    }

    // Copy constructor (deep copy)
    Person(const Person& other) {
        age = other.age;
        name = new char[strlen(other.name) + 1]; // Allocate new memory for name
        strcpy(name, other.name);                // Copy the content of the name
        cout << "Copy constructor called for " << name << endl;
    }

    // Destructor to clean up dynamically allocated memory
    ~Person() {
        cout << "Destructor called for " << name << endl;
        delete[] name;
    }

    // Function to display the person's details
    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    int setAge(int a) {
        this->age = a;
    }

    Person operator+(Person p1) {
        Person p3("New Person", this->age + p1.age);
        return p3;

    }
};

int main() {
    // Creating an object of Person using the constructor
    Person person1("Alice", 25);
    person1.display();

    // Creating a new object of Person using the copy constructor
    Person person2 = person1; // Copy constructor is called here
    person2.display();

    person1.setAge(100);

    cout<< "Printing person 1 and 2" << endl;
    person1.display();
    person2.display();

    Person person3 = person2;

    cout<< "Printing person 3" << endl;
    person3.display();

    person2.setAge(99);

    cout<< "Printing person 2 and 3" << endl;
    person2.display();
    person3.display();

    Person p4 = person2 + person3;

    p4.display();
    

    return 0;
}