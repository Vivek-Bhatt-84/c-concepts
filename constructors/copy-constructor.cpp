#include <iostream>
#include <cstring>
using namespace std;

class Person{
    char* name;
    int age;

public :
    Person(const char* nm , int ag){
        name = new char[strlen(nm) + 1];
        strcpy(name ,nm);
        age = ag;
    }


    // copy constructor (deep copy )
    Person(const Person &obj){
        name = new char[strlen(obj.name) + 1];
        strcpy(name ,obj.name);
        age = obj.age;
    }

    ~Person() {
        delete[] name; // Free the dynamically allocated memory
    }

    // Print Person details
    void printDetails() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

};

int main()
{

    Person p1("john" ,25);
    p1.printDetails();
    
    Person p2 = p1;
    p2.printDetails();

    p1.printDetails();
    p2.printDetails();


return 0;
}