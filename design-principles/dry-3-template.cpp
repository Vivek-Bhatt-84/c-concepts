// #include <iostream>
// using namespace std;

// int add(int a , int b){
//     return a + b;
// }

// double add(double a , double b){
//     return a + b;
// }

// int main()
// {
//     cout << add(2,3) << endl;
//     cout << add(2.2 , 3.4) << endl;

// return 0;
// }

#include <iostream>
#include <string>
using namespace std;

template <typename T>
T add(T a ,T b){
    return a + b;
}


int main()
{
    cout << add<int>(2,4) << endl;
    cout << add<string>("Vivek" , " Bhatt") << endl;
    cout << add(2.3 , 4.5) << endl;


return 0;
}