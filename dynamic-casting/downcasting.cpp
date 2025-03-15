#include <iostream>
using namespace std;

class Animal {
    public:
        virtual void sound() {
            cout << "Animal makes a sound" << endl;
        }
    };
    
    class Dog : public Animal {
    public:
        void sound() override {
            cout << "Dog barks" << endl;
        }
    };

int main()
{
    Animal* a = new Dog();
    
    Dog* dog = dynamic_cast<Dog*>(a);
    if (dog) {
        dog->sound();  // Output: Dog barks
    } else {
        cout << "Downcast failed!" << endl;
    }

    delete a;

return 0;
}