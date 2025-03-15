#include <iostream>
#include <thread>
using namespace std;

void test(){
    cout << "Hello from test :  " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::seconds(2));
}

void funcA(){
    thread tc(test);
    cout << "Hello from function A : " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::seconds(2));
    tc.join();
    
}

void funcB(){
    cout << "hello from function B : " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::seconds(2));
    
}

int main(){
    thread t1(funcA);
    thread t2(funcB);
    
    t1.join();
    t2.join();
    
    cout << "Hello from main :  " << this_thread::get_id() << endl;
    
    return 0;
}

/**
create two threads on should call function A and another function B 
function A should call another thread tc which should call function test 
execute thread in order means thread which execute first should end first 
*/