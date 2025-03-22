#include<bits/stdc++.h>
using namespace std;

class Singleton{
    private:
        static Singleton* instance ;
        Singleton(){}
    public:
        static Singleton* getInstnce(){
            if(instance == nullptr){
                instance = new Singleton();
            }
            return instance;
        }

        void show(){
            cout << this << endl;
        }
};

Singleton* Singleton :: instance = nullptr;

int main(){

    Singleton* obj = Singleton :: getInstnce();
    Singleton* obj2 = Singleton :: getInstnce();
    obj->show();
    obj2->show();

return 0;
}