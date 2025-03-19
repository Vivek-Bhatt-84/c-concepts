#include<bits/stdc++.h>
using namespace std;

mutex mtx;
int counter = 0;
// void printMessage(const string& mes){
//     mtx.lock();
//     cout << mes << endl;
//     mtx.unlock();
    
// }

void increment(){
    mtx.lock();
    ++counter;
    std::cout << "Counter: " << counter << std::endl;
    mtx.unlock();

}

int main(){
    // thread t1(printMessage , "Thread 1 : Hello");
    // thread t2(printMessage , "Thread 2 : World");

    // t1.join();
    // t2.join();

    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();


return 0;
}