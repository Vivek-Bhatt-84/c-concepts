#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;
mutex mtx;
condition_variable cv;


void printData(int id){

    cout << "Thread " << id << " is executing " << endl;
}

int main()
{
    thread t1(printData , 1);
    thread t2(printData , 2);
    thread t3(printData , 3);


    t1.join();
    t2.join();
    t3.join();

return 0;
}