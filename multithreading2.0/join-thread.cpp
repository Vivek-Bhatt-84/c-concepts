#include<bits/stdc++.h>
using namespace std;

void thread_func(){
    this_thread::sleep_for(chrono::seconds(1));  
}

int main(){

    thread t1;
    
    cout << "thread 1 joinable if default created ? " << endl;
    if(t1.joinable()){
        cout << "YES" << endl;
    }
    else{
        cout << "No" << endl;
    }

    t1 = thread(thread_func);
    cout << "Is joinable ? " << endl;
    if(t1.joinable()){
        cout << "YES" << endl;
    }
    else{
        cout << "No" << endl;
    }

    t1.join();

    cout << "t1 joinable after join is called? \n"; 
    if (t1.joinable()) 
        cout << "YES\n"; 
    else
        cout << "NO\n"; 

return 0;
}