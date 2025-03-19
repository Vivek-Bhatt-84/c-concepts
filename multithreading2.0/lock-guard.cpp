#include<bits/stdc++.h>
using namespace std;

mutex mtx;

void printMessage(const string& mes){
    lock_guard<mutex> lock(mtx);
    cout << mes << endl;
    
}

int main(){
    thread t1(printMessage , "Thread 1 : Hello");
    thread t2(printMessage , "Thread 2 : World");

    t1.join();
    t2.join();


return 0;
}