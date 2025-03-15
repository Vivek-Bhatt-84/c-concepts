#include <iostream>
using namespace std;

class Employee{
public:
    int id;
    string name;
    string department;

    Employee(int id, string name, string dep) : id(id), name(name), department(dep){}

    Employee(const Employee& obj){
        id = obj.id;
        name = obj.name;
        department = obj.department;
    }

    void display(){
        cout << "Id : " << id << " Name : " << name << " Department : " << department << endl;
    }

};

int main()
{
    Employee e1(101, "aditya", "mern-stack");
    Employee e2 = e1;

    e1.display();
    e2.display();

return 0;
}