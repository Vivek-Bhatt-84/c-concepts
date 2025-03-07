#include <iostream>
#include <vector>
#include <memory>

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
        for(auto it = comp.begin() ; it != comp.end() ; it++){
            if(it -> getId() == id ){
                comp.erase(it);
                return;
            }
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

return 0;
}