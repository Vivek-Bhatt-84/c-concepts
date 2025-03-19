#include<bits/stdc++.h>
#include <thread>
using namespace std;

void detachThreadFunc(){
    cout << "detach thread executing ..." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "detach thread completed " << endl;
}

int main(){
    thread t1(detachThreadFunc);
    t1.detach();
    cout << "main thread continuing " << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

return 0;
}