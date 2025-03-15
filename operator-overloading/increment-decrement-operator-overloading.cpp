
// C++ program for unary increment (++) and
// decrement (--) operator overloading

#include <iostream>
using namespace std;

class Num{
    int x;
    
public:

    void setX(int val){
        x = val;
    }
    
    void displayNum(){
        cout << "The value of x : " << x << endl;
    }
    
    void operator++(){
        ++x;
    }
    
    void operator--(){
        --x;
    }
};

int main()
{
    Num obj;
    obj.setX(10);
    cout << "after increment " << endl;
    ++obj;
    obj.displayNum();
    
    cout << "after decrement " << endl;
    --obj;
    obj.displayNum();
    
return 0;
}