#include <iostream>
#include <memory>
using namespace std;

void print(int& x){
    cout << "Lvalue" << endl;
}
void print(int&& x){
    cout << "Rvalue" << endl;
}

template <typename T>
void forwarder(const T& x){
    print(forward<T>(x));
}

// void forwarder(int&& a){
//     print(a);
// }


int main()
{
    int a = 10;
    forwarder(a);
    forwarder(20);

return 0;
}