#include <iostream>
using namespace std;

class Animal{
public:
    virtual void speak(){
        cout << "Animal speaks " << endl;
    }
};

class Dog : public Animal{
public :
    void speak() override{
        cout << "dog bark " << endl;
    }
};

int main()
{
    Dog d;
    Animal* a = &d; // derived class pointer assigned to base class pointer 
    a->speak();

return 0;
}