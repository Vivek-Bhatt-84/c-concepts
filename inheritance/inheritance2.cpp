#include <iostream>
using namespace std;

class Base{
protected :
    int x;
public :
    int y;
private:
    int z;

};

class Derived : public Base{
    // x remains protected 
    // y remains public 
    // z is not inherited   
};

class Derived : protected Base{
     // x -> protected 
     // y -> protected 
     // z -> not inherited 
};

class Derived : private Base{
    // x -> private
    // y -> private 
    // z -> not inherited 
};

int main()
{

return 0;
}