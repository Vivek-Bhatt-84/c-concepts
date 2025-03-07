/*Implement a Department with std::weak_ptr (Avoid Cyclic References)

👉 Problem:

    Modify the Company and Employee problem to introduce departments.
    Each Employee has a std::shared_ptr<Department> department.
    Each Department maintains a list of employees using std::weak_ptr<Employee> to prevent cyclic references.

✅ Concepts: std::shared_ptr, std::weak_ptr, preventing memory leaks.*/

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Department;

class Employee{
    string name;
    int id;
    float salary;
    shared_ptr<Department> dept;
public :
    Employee (string name , int id , float salary) : name(name) , id(id) , salary(salary) {}

    int getId()
    {
        return id;
    }

    void setDepartment(shared_ptr<Department> d){
        dept = d;
    }


    void display(){
        cout << "-------------------------------" << endl;
        cout << "Name : " << name << endl;
        cout << "ID : " << id << endl;
        cout << "Salary : " << salary << endl;
        if(dept){
            cout << "Department : " << dept -> getName();
        }
        else{
            cout << "NO department " << endl;
        }
    }
};

class Department{
    string name;
    vector<weak_ptr<Employee>> dept_list; 
public:
    void 
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