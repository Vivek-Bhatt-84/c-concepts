/*C++ program for unary minus (-) operator overloading.*/

#include <iostream>
#include <string>
using namespace std;

class Num{
private:
    int x;
    
public:
    void setX(int n){
        x = n;
    } 
    
    void displayNum(){
        cout << "The value of Num " << x;
    }
    
    void operator-(){
        x = -x;
    }
};

int main()
{
    Num obj;
    obj.setX(10);
    -obj;
    obj.displayNum();
    
    
    
return 0;
}