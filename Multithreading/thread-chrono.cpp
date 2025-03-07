#include <iostream>
#include <thread>
using namespace std;

void printMessage(){
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Hello from thread" << endl;
}

int main()
{
    thread t1(printMessage);
    t1.detach();

    cout << "main thread continues execution " << endl;
    this_thread::sleep_for(chrono::seconds(3));

return 0;
}