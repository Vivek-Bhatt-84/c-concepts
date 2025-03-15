// dry principle in custom objects 

#include <iostream>
using namespace std;

class Vehicle{
public :
    virtual void start(){
        cout << "Vehicle is starting " << endl;
    }
};

class Car : public Vehicle{
public :
    void start() override{
        cout << "car is staring " << endl;
    }
};

class Truck : public Vehicle{
public :
    void start() override {
        cout << "truck is starting " << endl;
    }
};



int main()
{

    Vehicle* v1 = new Truck();
    Vehicle* v2 = new Car();

    v1 -> start();
    v2 -> start();

    delete v1;
    delete v2;
    

return 0;
}



// #include <iostream>

// class Car {
// public:
//     void start() {
//         std::cout << "Car is starting" << std::endl;
//     }
// };

// class Truck {
// public:
//     void start() {
//         std::cout << "Truck is starting" << std::endl;
//     }
// };

// int main() {
//     Car car;
//     Truck truck;
//     car.start();
//     truck.start();
//     return 0;
// }
