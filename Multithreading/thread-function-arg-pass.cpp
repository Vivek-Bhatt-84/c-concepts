#include <iostream>
#include <thread>
using namespace std;

void printValue(int x , string str){
    cout << "Value: " << x << ", String: " << str << endl;
}

int main()
{
    string msg = "Hello" ;
    thread t1(printValue ,42 , ref(msg));
    t1.join();

return 0;
}