// C++ program to demonstrate example of
// private simple inheritance

#include <iostream>
#include <string>
using namespace std;

class BasicInfo{
protected :
    string name;
    int emid;
    char gender;
    
public:
    void getBasicInfo(){
        cout << "Enter basic information for employee " << endl;
        cout << "Name ? " << endl;
        cin.ignore();
        getline(cin,name);
        cout << "Employee id ? " << endl;
        cin >> emid;
        cout << "Gender ? " << endl;
        cin >> gender;
    }
    
};

class DepartInfo{
protected:
    string depName;
    string assignedWork;
    int time2complete;
    
public :
    void setDepartInfo(){
        cout << "Enter Department info " << endl;
        cout << "Departname Name ?" << endl;
        cin.ignore();
        getline(cin ,depName);
        cout << "Assigned Work ? " << endl;
        getline(cin, assignedWork);
        cout << "time to complete ? " << endl;
        cin >> time2complete ;
        
    }
};
class Employee : private BasicInfo , private DepartInfo{
public :
void getEmployeeInfo(){
    cout << "Enter employee basic info " << endl;
    getBasicInfo();
    
    cout << "Enter employee department info " << endl;
    setDepartInfo();
}

void printEmployeeInfo(){
    
    cout << "--------------Basic information of employee-------------------" << endl;
    cout << "Name : " << name << endl;
    cout << "Employee ID : " << emid << endl;
    cout << "Gender : " << gender << endl;
    cout << "------------x----------------x--------------x------------x---" << endl;
    cout << "Department information of Employee " << endl;
    cout << "Department Name : " << depName << endl;
    cout << "Work assigned : " << assignedWork << endl;
    
}
};
int main()
{
    Employee emp;

    emp.getEmployeeInfo();
    emp.printEmployeeInfo();
    
return 0;
}