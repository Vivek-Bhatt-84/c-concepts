#include<bits/stdc++.h>
using namespace std;

//final product
class Car{
    private:
        int seats;
        string engine;
        bool tripComputer;
        bool GPS;

    public:
        void setSeats(int st){
            seats = st;
        }
        void setEngine(const string& type){
            engine = type;
        }
        void setTripComputer(bool hascomp){
            tripComputer = hascomp;
        }
        void setGps(bool hasGps){
            GPS = hasGps;
        }
        void display(){
            cout << "Car Specifications:\n";
            cout << "Seats: " << seats << endl;
            cout << "Engine: " << engine << endl;
            cout << "Trip Computer: " << (tripComputer ? "Yes" : "No") << endl;
            cout << "GPS: " << (GPS ? "Yes" : "No") << endl;
        }

};

// Builder interface
class Builder{
    public:
        virtual void reset() = 0;
        virtual void setSeats(int seats) = 0;
        virtual void setEngine(const string& type) = 0;
        virtual void setTripComputer(bool hascomp) = 0;
        virtual void setGps(bool hasGps) = 0;
        virtual Car build() = 0;
};

class CarBuilder : public Builder{
    private :
        Car car;
    public:
        CarBuilder(){this->reset();}
        void reset() override {
            car = Car();
        }
        void setSeats(int st) override {
            car.setSeats(st);
        }
        void setEngine(const string& type) override {
            car.setEngine(type);
        }
        
        void setTripComputer(bool hascomp) override {
            car.setTripComputer(hascomp);
        }
        void setGps(bool hasGps) override {
            car.setGps(hasGps);
        }

        Car build() override {
            return car;
        }

};


class Director {
    public:
    void constructSportsCar(Builder& builder){
        builder.reset();
        builder.setSeats(2);
        builder.setEngine("v8");
        builder.setTripComputer(true);
        builder.setGps(true);
    }
};

int main(){
    CarBuilder builder;
    Director director;

    director.constructSportsCar(builder);
    Car sportsCar = builder.build();
    sportsCar.display();

return 0;
}