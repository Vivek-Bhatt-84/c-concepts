#include <iostream>
using namespace std;

class A{
public :
    int x;

    A(int val){ // conversion constructor from int to A.
        x = val;
    }
};

class B{
public :
    int y ;

    B(A a){
        y = a.x ; // constructor that accepts object of class A.
    }
};

int main()
{
    A a(10);
    B b = a;  // implicit conversion from A to B.
    cout << "B's value: " << b.y << endl;  // Output: B's value: 10

return 0;
}