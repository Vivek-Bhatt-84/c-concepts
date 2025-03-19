#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
        string name;
        int age ;
        Student(int a , const string& n) : name(n) , age(a) {}

};
    ostream& operator<<(ostream& obj1, const Student& obj){
        obj1 << "Name : " << obj.name << "Age : " << obj.age << endl;
        return obj1;
    }

int main(){

    Student  s(21 , "john");
    cout << s << endl;

return 0;
}