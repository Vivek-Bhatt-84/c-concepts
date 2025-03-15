#include <iostream>
using namespace std;

template <typename T>
T add(T a ,T b){
    return a + b;
}

template <typename T1 ,typename T2>
void display(T1 a , T2 b){
    cout << a << " and " << b << endl;
 }

    

int main()
{

    cout << add(2,2) << endl;
    cout << add(2.2 , 4.3) << endl;

    display(1,"hello") ;
    display(2.3 , 2);

return 0;
}