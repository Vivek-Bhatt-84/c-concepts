#include <iostream>
using namespace std;

class Base{
public :
    int a;
    void display(){
        cout << "Base class " << endl;
    }
};

class Derived : public Base{
public : 
void show(){
    cout << "Derived class " << endl;
}
};

int main()
{

    Derived obj;
    obj.display();
    obj.show();

return 0;
}