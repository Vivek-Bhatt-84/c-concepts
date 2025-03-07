#include <iostream>
using namespace std;

// class MyClass{
// public :
//     MyClass(int x) {
//         cout << "constructor called with value " << x << endl;
//     }
// };

class MyClass{
public :
    explicit MyClass(int x){
        cout << "constructor called with value : " << x << endl;
    }
};

int main()
{

    // MyClass obj = 10; // implicit conversion from int  to myclass

return 0;
}