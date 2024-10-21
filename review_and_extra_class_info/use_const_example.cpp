#include <iostream>
#include <string>
using namespace std;

// Define a class for Person
class Person {
private:
    string name;
    int age;

    // Static variable: shared by all instances of the class
    static int personCount;

public:
    // Constructor
    Person(string n, int a) : name(n), age(a) {
        // Increment the static variable for each new instance
        personCount++;
    }

    // Destructor
    ~Person() {
        // Decrement the static variable when an instance is destroyed
        personCount--;
    }

    /*
    In this example we will see the difference between receiving an const parameter
    and a function being constant. The former restricts how we interact with the
    paramter. The latter restricts how we interact with the class attributes.
    */
    // Member function that accepts a const parameter
    void changeName(const string& newName) {
        this->name = newName;  // You can still modify the member variable
        // newName is constant, so it can't be modified within this function
        // newName = "Invalid";  // This would be illegal
    }

    // Const function (it guarantees that it will not modify any class member variables)
    void printInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
        // Cannot modify name or age here
        // name = "Invalid";  // This would cause a compilation error because it's a const function
    }

    // Non-const function (can modify class members)
    void birthday() {
        age++;  // Modifies the age
    }

    int getAge() {
        return age;
    }

    /*
    Static variables: all the instance have access to the variable.
    Static functions: Have access to them through the class and can only work with 
    static variables

    */
    // Static function: can only access static members
    static int getPersonCount() {
        return personCount;  // Can only return static members
    }

    static bool isOlder(Person& p1, Person& p2) {
        return p1.getAge() > p2.getAge();
    }
};

// Definition of the static variable outside the class
int Person::personCount = 0;

int main() {
    // Create two Person objects
    Person p1("Alice", 30);
    Person p2("Bob", 25);

    // Call the static function to get the count of Person objects
    cout << "Current number of persons: " << Person::getPersonCount() << endl;


    // Call non-static member functions
    cout << "Person 1 Info:" << endl;
    p1.printInfo();

    cout << "Person 2 Info:" << endl;
    p2.printInfo();

    // Modify person details
    p1.changeName("Charlie");
    p2.birthday();

    // Print updated information
    cout << "After Modifications:" << endl;
    p1.printInfo();
    p2.printInfo();

    // Call static function to show that the person count has not changed
    cout << "Current number of persons: " << Person::getPersonCount() << endl;

    cout << boolalpha;
    cout << "Is Charlie older than Bob? " << Person::isOlder(p1, p2) << endl;

    // Once p1 and p2 go out of scope, the destructor will be called, and personCount will be decremented
    return 0;
}