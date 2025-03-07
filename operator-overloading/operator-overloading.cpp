#include <iostream>
using namespace std;

// class Complex{
//     int a ,b;
// public :
//     void setData(int x ,int y){
//         a = x;
//         b = y;
//     }

//     void showData(){
//         cout << " a = " << a << " b = " << b << endl;
//     }

//     Complex operator +(Complex c){
//         Complex tmp;
//         tmp.a = a + c.a;
//         tmp.b = b + c.b;
//         return tmp;

//     }

// };

// overloading unary operator 
class Complex{
    int a ,b;
public :
    void setData(int x ,int y){
        a = x;
        b = y;
    }

    void showData(){
        cout << " a = " << a << " b = " << b << endl;
    }

    Complex operator-(){
        Complex tmp;
        tmp.a = -a;
        tmp.b = -b;
        return tmp;

    }

};

int main()
{

    Complex c1 ,c2 ,c3;
    c1.setData(3,4);
    c2.setData(5,6);
    // c3 = c1.operator+(c2);
    c3 = -c1;
    c3.showData();

return 0;
}