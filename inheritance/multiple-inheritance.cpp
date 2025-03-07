#include <iostream>
using namespace std;

class A{
public :
    void methodA(){
        cout << "Method from class A" << endl;
    }
};

class B{
public :
    void methodB(){
        cout << "Method from class B " << endl ;
    }
};

class Derived : public A , public B{
public :
    void methodDerived(){
        cout << "Method from derived class " << endl;
    }
};

int main()
{

    Derived obj;
    obj.methodA(); // From ClassA
    obj.methodB(); // From ClassB
    obj.methodDerived(); // From Derived class

return 0;
}