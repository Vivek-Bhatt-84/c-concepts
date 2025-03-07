// C++ program to add two objects using binary
// plus (+) operator overloading

#include <iostream>
using namespace std;

class Num{
    int x;
    
public:

    void getX(int val){
        x = val;
    }
    
    void displayNum(){
        cout << "The value of x : " << x << endl;
    }
    
    // adding two objects 

    Num operator+(Num& obj){
        Num tmp ;
        tmp.x =  x + obj.x;
        return tmp;
    }
};

int main()
{
    Num num1 ,num2 , sum;

    num1.getX(10);
    num2.getX(20);

    sum =  num1.operator+(num2);
    sum.displayNum();
    
    
    
return 0;
}