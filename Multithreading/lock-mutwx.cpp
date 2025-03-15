#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex mtx;

// void printData(int id){
//     mtx.lock();
//     cout << "Thread " << id << " is executing " << endl;
//     mtx.unlock();
// }

void printData(int id){
    lock_guard<mutex> guard(mtx);
    cout << "Thread " << id << " is executing " << endl;
   
}

int main()
{

    thread t1(printData ,1);
    thread t2(printData ,2);

    t1.join();
    t2.join();


return 0;
}