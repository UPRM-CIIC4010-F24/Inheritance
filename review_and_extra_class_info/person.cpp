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

    bool isOlder(Person& p2) {
        return this->getAge() > p2.getAge();
    }
};

void printAge(Person& p1) {
    p1.setAge(12);
    cout<< p1.getAge() << endl;
}
int main() {
    Person p1 = Person(10, "Bob");
    Person p2 = Person(45, "Jen");

    cout << boolalpha;

    cout << p1.isOlder(p2) << endl;

    cout << p1.getAge()<<endl;
    printAge(p1);
    cout << p1.getAge()<<endl;
}