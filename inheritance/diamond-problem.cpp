#include <iostream>
using namespace std;

class A{
public :
    A(){
        cout << "Constructor of A" << endl;
    }
    virtual ~A(){cout << "Destructor of A" << endl;}
};

class B : virtual public A {
    public:
        B() { std::cout << "Constructor of B" << std::endl; }
        virtual ~B() { std::cout << "Destructor of B" << std::endl; }
    };

    class C : virtual public A {
        public:
            C() { std::cout << "Constructor of C" << std::endl; }
            virtual ~C() { std::cout << "Destructor of C" << std::endl; }
        };
        class D : public B, public C {
            public:
                D() { std::cout << "Constructor of D" << std::endl; }
                virtual ~D() { std::cout << "Destructor of D" << std::endl; }
            };


int main()
{
    D obj;


return 0;
}