#include <bits/stdc++.h>
using namespace std;

// base class 
class Vehicle{
protected :
    string brand;
    int wheels;

public :
    Vehicle(string b ,int w) : brand(b) ,wheels(w) {}

    virtual void display(){
        cout << "Brand : " << brand << " Wheels : " << wheels << endl;
    }
};

// single inheritance (car -> vehicle)

class Car : virtual public Vehicle{
protected :
    int doors;
public :
    Car(string s ,int w ,int  d) : Vehicle(s ,w) ,doors(d) {} 


    void display() override {
        cout << "Car - Brand: " << brand << ", Wheels: " << wheels << ", Doors: " << doors << endl;
    }
};


// single inhritance (bike -> vehicle)
class Bike : virtual public Vehicle{
protected :
    bool hasGear;
public :
    Bike(string s ,bool g ,int w) : Vehicle(s,w) ,hasGear(g) {}

    void display() override {
        cout << "Bike - Brand: " << brand << ", Wheels: " << wheels << ", Has Gear: " << (hasGear ? "Yes" : "No") << endl;
    }
};

// Multilevel Inheritance (SportsCar -> Car -> Vehicle)

class SportsCar : public Car
{
private :
    int horsePower;
public :
    SportsCar(string b, int w, int d, int h) : Vehicle(b,w) , Car(b,w,d) , horsePower(h) {}

    void display() override
    {
        cout << "Sports Car - Brand: " << brand << ", Wheels: " << wheels << ", Doors: " << doors << ", Horsepower: " << horsePower << " HP" << endl;
    }
};

// multiple inheritance (HybridVehicle inherits from Car and Bike)

class HybridVehicle : public Car ,public Bike{
public :
    HybridVehicle(string b, int w, int d, bool g) : Car(b,w,d) , Bike(b,g,w) , Vehicle(b,w) {}

    void display() override{
        cout << "Hybrid Vehicle - Brand: " << brand 
             << ", Wheels: " << wheels 
             << ", Doors: " << doors 
             << ", Has Gear: " << (hasGear ? "Yes" : "No") << endl;
    }
};


int main()
{
    Vehicle* v1 = new Car("Toyota", 4, 4);
    Vehicle* v2 = new Bike("Honda", 2, true);
    Vehicle* v3 = new SportsCar("Ferrari", 4, 2, 600);

    cout << "\n**Polymorphism Example:**\n";
    v1->display();  // Calls Car's display()
    v2->display();  // Calls Bike's display()
    v3->display();  // Calls SportsCar's display()

    cout << "\n**Multiple Inheritance Example:**\n";
    HybridVehicle hv("Tesla", 4, 4, true);
    hv.display(); // Calls HybridVehicle's display()

    delete v1;
    delete v2;
    delete v3;

return 0;
}