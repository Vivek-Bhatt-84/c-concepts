#include <iostream>
using namespace std;

class Singleton{
    static Singleton* inst;

    Singleton(){}

public:
    static Singleton* getInstance(){
        if(inst == NULL){
            inst = new Singleton();
        }
        return inst;
    }

    void display(){
        cout << "one instance with address " << this << endl;
    }

};

Singleton* Singleton :: inst = NULL; 

int main()
{

    Singleton* s1 = Singleton::getInstance();
    s1 -> display();

    Singleton* s2 = Singleton::getInstance();
    s2 -> display();

return 0;
}

// issues -> memory leak 
// non - thread safe