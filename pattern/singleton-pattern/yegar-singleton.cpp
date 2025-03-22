#include<bits/stdc++.h>
using namespace std;
mutex mtx;

class Singleton{
    private:
        static Singleton* instance ;
        Singleton(){}
    public:
        static Singleton* getInstnce(){
            // if(!instance){
            //     lock_guard<mutex> lock(mtx);
            //     if(instance == nullptr){
            //         instance = new Singleton();
            //     }
            // }
            
            return instance;
        }

        void show(){
            cout << this << endl;
        }
};

Singleton* Singleton :: instance = instance = new Singleton();;

int main(){

    Singleton* obj = Singleton :: getInstnce();
    Singleton* obj2 = Singleton :: getInstnce();
    obj->show();
    obj2->show();

return 0;
}