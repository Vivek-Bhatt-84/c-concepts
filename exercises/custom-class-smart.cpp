#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Employee{
    string name;
    int id;
    float salary;
public :
    Employee (string name , int id , float salary) : name(name) , id(id) , salary(salary) {}

    int getId()
    {
        return id;
    }

    void display(){
        cout << "-------------------------------" << endl;
        cout << "Name : " << name << endl;
        cout << "ID : " << id << endl;
        cout << "Salary : " << salary << endl;
    }
};


class Company{
    vector<shared_ptr<Employee>> comp;
public:
    void hire(const Employee& obj){
        comp.push_back(make_shared<Employee>(obj));
    }

    void fire(int id){
       auto it = find_if(comp.begin() , comp.end() ,[id](shared_ptr<Employee>& emp){
            return emp -> getId() == id;
       });
       if(it != comp.end()){
        comp.erase(it);
       }

    }

    void displayEmployees(){
        for(auto it : comp){
            it -> display();
        }
    }

};

int main()
{

    Company c;
    Employee e1 = {"Vivek" , 001 , 5000000.0};
    Employee e2 = {"Aditya" , 002 , 5000000.0};
    Employee e3 = {"Akshita" , 001 , 4000000.0};

    c.hire(e1);
    c.hire(e2);
    c.hire(e3);

    cout << "display" << endl;
    c.displayEmployees();

    c.fire(003);
    c.displayEmployees();

return 0;
}