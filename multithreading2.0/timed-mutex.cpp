#include<bits/stdc++.h>
using namespace std;

timed_mutex mtx;

void tryLockFunc(){
    if(mtx.try_lock_for(chrono::milliseconds(50))){
        cout << "lock acquired by thread " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        mtx.unlock();
    }   
    else{
        std::cout << "Thread " << std::this_thread::get_id() << " couldn't acquire lock" << std::endl;
    }
}

int main(){
    std::thread t1(tryLockFunc);
    std::thread t2(tryLockFunc);

    t1.join();
    t2.join();

return 0;
}