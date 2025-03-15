#include <iostream>
using namespace std;

class SingletonClass{
private:
    static  SingletonClass* var ;
    
    SingletonClass(){cout << "Constructor called" << endl; }
public :
    static SingletonClass*  getInstance(){
        if(var == NULL){
            var = new SingletonClass();
        }
        return var;
    }
};

SingletonClass* SingletonClass :: var = NULL;

int main()
{
    SingletonClass* obj1 = SingletonClass::getInstance();
    SingletonClass* obj2 = SingletonClass::getInstance();
    
    return 0;
}