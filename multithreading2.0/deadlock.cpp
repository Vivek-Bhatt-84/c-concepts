#include<bits/stdc++.h>
using namespace std;

mutex mtx1 , mtx2;

void thread1(){
    mtx1.lock();
    this_thread::sleep_for(chrono::milliseconds(2));
    mtx2.lock();
    cout << "thread1 acquired mutex 1 : " << endl;
    mtx2.unlock();
    mtx1.unlock();
}

void thread2(){
    mtx2.lock();
    this_thread::sleep_for(chrono::milliseconds(2));
    mtx1.lock();
    cout << "thread1 acquired mutex 1 : " << endl;
    mtx1.unlock();
    mtx2.unlock();
}

int main(){

    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();

return 0;
}