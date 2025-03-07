#include <iostream>
using namespace std;

class Animal{
public :
    virtual void sound(){
        cout << "Animal make sound " << endl;
    }
};

class Dog : public Animal{
public : 
    void sound() override { 
        cout << "Dog Barks " << endl;
    }
};

class Cat : public Animal{
public :
    void sound() override {
        cout << "cat meows " << endl;
    }
};

int main()
{

    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1 -> sound();
    a2 -> sound();
    

return 0;
}