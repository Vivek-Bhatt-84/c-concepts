#include<bits/stdc++.h>
using namespace std;

mutex mtx;

class Singleton{
    private:
        static Singleton* instance;
        Singleton(){}
    public:
        static Singleton* getInstance(){
            lock_guard<mutex> lock(mtx);
            if(instance == nullptr){
                instance = new Singleton();
            }
            return instance;
        }

        void show(){
            cout << "Single instance of address : " << this << endl;
        }
};

Singleton* Singleton :: instance = nullptr;

int main(){
    Singleton* obj = Singleton :: getInstance();
    obj->show();

return 0;
}