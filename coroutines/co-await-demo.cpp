#include <iostream>
#include <coroutine>
#include <bits/stdc++.h>
using namespace std;

struct MyAwaitable{
    bool await_ready(){
        return false;
    }
    void await_suspend(coroutine_handle<> handle){
        cout << "suspend coroutine " << endl;
        savedHandle = handle;
    }   

    void await_resume(){
        cout << "Resumed coroutine " << endl;
    }

    coroutine_handle<> savedHandle;
};

struct MyCoroutine {
    struct promise_type {
        MyCoroutine get_return_object() { return {}; }
        suspend_never initial_suspend() { return {}; }
        suspend_always final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() { std::terminate(); }
    };
};


int main()
{

return 0;
}