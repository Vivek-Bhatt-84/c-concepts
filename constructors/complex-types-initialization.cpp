#include <iostream>
#include <string>
using namespace std;

// A simple class for storing the name and age of a person
class Person{
public :
    string name;
    int age;

    Person(string n , int a ) : name(n) ,age(a) {}
};

// A class with complex type (Person) as a member 
class Employee{
public :
    int id;
    Person p ;

    Employee(int id ,string name ,int age) : id(id) ,p(name ,age) {}

    void display() {
        cout << "Employee ID: " << id << ", Name: " << p.name << ", Age: " << p.age << endl;
    }
};



int main()
{
    Employee e1(101 ,"John Doe" ,30) ;
    e1.display();

return 0;
}