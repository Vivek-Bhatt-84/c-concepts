#include<bits/stdc++.h>
using namespace std;

class Car{
    public:
        string name;
        string model;
        int seats;
        string colour;

        void show(){
            cout << "Name : " << name << endl;
            cout << "Model : " << model << endl;
            cout << "Color : " << colour << endl;
            cout << "Seats : " << seats << endl;
        }
};

class Builder{
    public:
        Car c;

        Builder& setName(string n){
            c.name = n;
            return *this;
        }

        Builder& setModel(string m){
            c.model = m;
            return *this;
        }

        Builder& setSeats(int seat){
            c.seats = seat;
            return *this;
        }

        Builder& setColor(string co){
            c.colour = co;
            return *this;
        }

        Car build(){
            return c;
        }
};

int main(){

    Builder obj;

    Car c1 = obj.setName("BMW")
                .setModel("1992")
                .setColor("Blue")
                .setSeats(2)
                .build();

    c1.show();
return 0;   
}