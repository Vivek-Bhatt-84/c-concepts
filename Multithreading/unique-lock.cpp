#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
mutex mtx;

void printVal(int x){

    unique_lock<mutex> lock(mtx , defer_lock);

    cout << "Thread " << this_thread::get_id() << " attempting to lock... " << endl;
    lock.lock();
    cout << "Thread " << this_thread::get_id() << " acquired  the  lock... " << endl;

    this_thread::sleep_for(chrono::seconds(1));

    cout << "Thread " << this_thread::get_id() << " releasing the lock... " << endl;
}


int main()
{
    thread t1(printVal , 42);
    thread t2(printVal , 100);

    t1.join();
    t2.join();

return 0;
}