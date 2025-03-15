/**
 * if class B is subclass of A then we should be able to 
 * replace object of A with B without breaking behaviour of program 
 * subclass should extend capability of parent class does not narrow it down 
 */

// #include <iostream>
// using namespace std;

// class Bird{
// public:
//     virtual void fly(){
//         cout << "Birds fly " << endl;
//     }
// };

// class Penguin : public Bird{
// public:
//     void fly() override{
//         cout << "Penguins can't fly " << endl;
//     }

// };

// void makeBirdFly(Bird& obj){
//     obj.fly();
// }

// int main()
// {
//     Bird bird;
//     Penguin p1;

//     makeBirdFly(bird);
//     makeBirdFly(p1);

// return 0;
// }




// fix 
#include <iostream>
#include <string>
using namespace std;

class Bird{
public:
    virtual void sound() = 0;
};

class FlyingBird : public Bird{
public:
    virtual void fly() = 0;
};

class Sparrow : public FlyingBird{
public:
    void fly() override{
        cout << "sparrow fly " << endl;
    }

    void sound() override{
        cout << "sparrow chirps!" << endl;
    }
};

class Penguin : public Bird{
public :
    void sound() override {
        cout << " penguin honks" << endl;
    }
};

void makeBirdFly(FlyingBird& bird){
    bird.fly();
}

int main()
{
    Sparrow sp;
    Penguin pe;
    makeBirdFly(sp);
    // makeBirdFly(pe);

return 0;
}