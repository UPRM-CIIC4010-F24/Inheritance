#include<iostream>
#include<string>

using namespace std;

class Person {
    private:
    int age;
    string name;

    public:
    Person(int age, string name) {
        this->age = age;
        this->name = name;
    }
    int getAge() {return this->age;}
    void setAge(int age) { 
        this->age = age;
    }

    string getName() {
        return name;
    }
    void setName(string name) {
        this->name = name;
    }

    bool isOlder(Person& p2) {
        return this->getAge() > p2.getAge();
    }

    Person operator+(Person person2) {
        Person newPerson = Person(this->getAge() + person2.getAge(), this->getName() + " " + person2.getName());
        return newPerson;
    }

};

/*
 * Another kind of overloading, where we indicate how this class should
 * be printed by cout
*/
std::ostream& operator<<(std::ostream& out, Person& person) {
    // Since triangle is a constant the methods it can access must be constant as well
    return out << person.getName() + " (" << person.getAge() << ")" <<std::endl;
}

void printAge(Person& p1) {
    p1.setAge(12);
    cout<< p1.getAge() << endl;
}
int main() {
    Person p1 = Person(10, "Bob");
    Person p2 = Person(45, "Jen");

    cout << "Person 1: " << p1; // Using the overloaded ostream
    cout << "Person 2: " << p2;

    Person p3 = p1 + p2;
    cout << "person3 = person1 + person2: " << endl;
    cout << "Person 3: " << p3;
}