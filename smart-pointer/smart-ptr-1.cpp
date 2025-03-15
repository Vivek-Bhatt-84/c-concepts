#include <iostream>
#include <memory>

using namespace std;

class B;

class A{
public:
    shared_ptr<B> ptrB ;
    ~A(){
        cout << "Destructor of A called"  << endl;
    }
    
};

class B{
public:
    shared_ptr<A> ptrA;
    ~B() { cout << "Destructor of B called\n"; }
};

int main(){
    shared_ptr<A> a =  make_shared<A>();
    shared_ptr<B> b =  make_shared<B>();
    
    a -> ptrB  = b;
    // b -> ptrA = a;
    
    cout << "use count A " << a.use_count() << endl;
    cout << "use count B " << b.use_count() << endl;
    
    
    return 0;
}