#include <iostream>
#include <memory>
using namespace std;

class AbstractCar{
public:
    virtual void createCar() = 0;
    virtual ~AbstractCar() {}
};

class SportsCar : public AbstractCar{
public:
    void createCar() override{
        cout << "This is sports car " << endl;
    }
};

class SmallCar : public AbstractCar{
public :
    void createCar() override{
        cout << "This is small car " << endl;
    }
};

class AbstractFactory{
public :    
    virtual  unique_ptr<AbstractCar> Car(const string& type) = 0;
    virtual ~AbstractFactory(){}

};

class ConcreteFactory : public AbstractFactory{
public:
     unique_ptr<AbstractCar>  Car(const string& type) override {
        if(type == "SmallCar") return make_unique<SmallCar>();
        if(type == "SportsCar") return make_unique<SportsCar>();
        return nullptr;
    }
};

int main()
{
    ConcreteFactory obj ;
    auto car = obj.Car("SmallCar");
    if(car){
        car -> createCar();
    }

return 0;
}