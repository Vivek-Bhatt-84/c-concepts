#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
using namespace std;

class Singleton{
    static Singleton* inst;
    Singleton(){}
public :
    static Singleton* getInstance(){
        if(inst == nullptr){
            inst = new Singleton();
        }
        return inst;
    }

    void display(){
        cout << "Singleton instance with address " << this << endl;
    }
};

void createSingleInstance(){
    this_thread::sleep_for(chrono::milliseconds(200));
    Singleton* s = Singleton::getInstance();
    s -> display();
}

Singleton* Singleton :: inst = nullptr;

int main()
{
    vector<thread> thrd;
    
    for(int i = 0 ; i < 5 ; i++){
        thrd.push_back(thread(createSingleInstance));
    }

    for(auto& t : thrd){
        t.join();
    }

return 0;
}