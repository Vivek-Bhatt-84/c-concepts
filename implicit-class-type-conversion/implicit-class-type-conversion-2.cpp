#include <iostream>
using namespace std;

class A{
public :
    int x;
    A(int val) : x(val) {}
};

class B{
public :
    int y ;

    B(int val) : y(val) {}

    // conversion operator from B to A
    operator A(){
        return A(y);
    }
};


int main()
{

    B b(5);
    A a = b;
    cout << "A's value: " << a.x << endl;

return 0;
}