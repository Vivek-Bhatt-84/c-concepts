#include <iostream>
using namespace std;

class Circle{
public :
    const double pi;
    const double radius ;

    // constructor with member initialization list 
    Circle(double r) : pi(3.14159) , radius(r){}
    
    double area(){
        return pi * radius * radius;
    }
};

int main()
{

    Circle c1(5.0);
    cout << "Area : " << c1.area() << endl;

return 0;
}