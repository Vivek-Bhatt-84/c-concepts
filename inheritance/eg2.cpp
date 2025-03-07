// C++ program to read and print students information
// using two classes and simple inheritance

#include <iostream>
#include <string>
using namespace std;

class BasicInfo{
    string name;
    int age;
    char gender;
public:
    void getBasicinfo(){
        cout << "Enter basic info " << endl;
        cout << "Name ?" << endl;
        getline(cin,name);
        cout << "Age ? " << endl;
        cin >> age;
        cout << "Gender ? " << endl;
        cin >> gender;
    }
    
    void setBasicInfo(){
        cout << "---------------------------------------" << endl;
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Gender : " << gender << endl;
        cout << "---------------------------------------" << endl;
    }
};

class ResultInfo : public BasicInfo{
    int totalMarks;
    float perc;
    char grade;
 public :
 void getresultInfo(){
        cout << "Enter Result info " << endl;
        cout << "totalMarks ?" << endl;
        cin >> totalMarks;
        perc = ((float)totalMarks * 100) / 500;
        cout << "grade ? " << endl;
        cin >> grade;
    }
    void setresultInfo(){
        cout << "---------------------------------------" << endl;
        cout << "totalMarks : " << totalMarks << endl;
        cout << "percentage  : " << perc << endl;
        cout << "grade : " << grade << endl;
        cout << "---------------------------------------" << endl;
    }
};
int main()
{
    ResultInfo obj;
    
    obj.getBasicinfo();
    obj.setBasicInfo();
    
    obj.getresultInfo();
    obj.setresultInfo();

return 0;
}