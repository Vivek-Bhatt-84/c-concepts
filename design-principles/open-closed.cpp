/**
 * open for extension but closed for modification
 */

#include <iostream>
using namespace std;

/**
 * violating OCP 
 * everytime if we have to add functionality to add area we have to modify AreaCalculator class 
 */
// class AreaCalculator{
// public:
//     double calcArea(int shapetype , double length , double width = 0 ){
//         if(shapetype == 0){
//             cout << "area of square " << endl;
//             return length * length;
//         }
//         if(shapetype == 1){
//             cout << "area of rectangle " << endl;
//             return length * width;
//         }
//     }
// };

// corrected way 

/**
 * abstract class for extension and child class modification
 * now if a new class is to be created we can extend AreaCalc class 
 */
class AreaCalculator{
public:
   virtual double calculateArea() = 0;
};

class CircleArea : public AreaCalculator
{
    int r;
public :
    CircleArea(int val) :r (val) {}
     double calculateArea() override{
        return 3.14 * r * r;
     }
};

class Reactangle : public AreaCalculator{
    int l;
    int w;
public :
    Reactangle(int len , int width) : l(len) , w(width){}
    double calculateArea() override {
        return l * w;
    } 
};

void printArea( AreaCalculator& shape) {
    cout << "Area: " << shape.calculateArea() << endl;
}


int main()
{
    CircleArea c1(3.4);
    Reactangle r1(3.0 , 4.5);

    printArea(c1);
    printArea(r1);


return 0;
}