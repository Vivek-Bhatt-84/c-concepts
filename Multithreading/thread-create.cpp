#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

mutex mtx;

void printMessage(){
    mtx.lock();
    cout << "Hello from thread" << endl;
    mtx.unlock();
}


int main()
{
    thread t1(printMessage);
    thread t2(printMessage);

    t1.join();
    t2.join();

return 0;
}