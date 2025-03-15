// C++ program to demonstrate example of
// private simple inheritance

#include <iostream>
using namespace std;

class A{
private:
    int a;
protected :
    int x;
public :
    void setVal(int v){
        x = v;
    }

};

class B : private A{
public:
    void printV(){
        setVal(10);
        cout << "value of x which is priavate member of base class is : " << x << endl;
    }

};

int main()
{
    B obj;
    obj.printV();
    // obj.setVal(20);

return 0;
}