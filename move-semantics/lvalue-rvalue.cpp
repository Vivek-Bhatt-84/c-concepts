#include <iostream>
#include <string>
using namespace std;

void f(int&& x){
    cout << x << endl;
}

void f(int& x){
    cout << x << endl;
}

int main()
{
    int i = 10;
    f(i);
    f(10);

    return 0;
}