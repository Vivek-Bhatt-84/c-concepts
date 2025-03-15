// C++ program for unary logical NOT (!)
// operator overloading

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
        x = ++x;
    }
    
    void operator!(){
        x = !x;
    }
};

int main()
{
    Num obj;
    obj.setX(10);
    obj.displayNum();
    !obj;
    obj.displayNum();
    
    
    
return 0;
}