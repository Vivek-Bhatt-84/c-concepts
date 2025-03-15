#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mutexA, mutexB; // Two mutexes

void thread1() {
    lock_guard<mutex> lock1(mutexA); // Lock Mutex A
    this_thread::sleep_for(chrono::milliseconds(100)); // Simulate some work

    cout << "Thread 1 trying to lock Mutex B..." << endl;
    lock_guard<mutex> lock2(mutexB); // Lock Mutex B (Deadlock occurs here)
    cout << "Thread 1 acquired both locks!" << endl;
}

void thread2() {
    lock_guard<mutex> lock2(mutexB); // Lock Mutex B
    this_thread::sleep_for(chrono::milliseconds(100)); // Simulate some work

    cout << "Thread 2 trying to lock Mutex A..." << endl;
    lock_guard<mutex> lock1(mutexA); // Lock Mutex A (Deadlock occurs here)
    cout << "Thread 2 acquired both locks!" << endl;
}

int main() {
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}
