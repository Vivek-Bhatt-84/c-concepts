#include<bits/stdc++.h>
using namespace std;

//observer interface 
class Observer{
    public:
        virtual void update(const string& name, float price) = 0;
        virtual ~Observer(){}
};

class User : public Observer{
    public:
        User(const string& name ) : uName(name){}
        void update(const string& name, float price) override {
            cout << "update for " << name <<  " price : " << price << endl;
        }

    private:
        string uName;
};


// subject interface 
class Subject{
    public : 
        virtual void addUser(Observer* observer) = 0;
        virtual void removeUser(Observer* observer) = 0;
        virtual void notifyAll() = 0;
        virtual ~Subject(){}
};

class StockMarket : public Subject{
    public:
        StockMarket(const string& name , float price) : sName(name) , sPrice(price) {}
        void addUser(Observer* observer) override {
            subscriberList.push_back(observer);
        }

        void removeUser(Observer* observer) override {
            subscriberList.erase(remove(subscriberList.begin() , subscriberList.end() , observer));
        }

        void notifyAll() override {
            for(auto& obs : subscriberList){
                obs -> update(sName , sPrice);
            }
        }

        void setPrice(float price){
            sPrice = price;
            notifyAll();
        }
    private:
    string sName;
    float sPrice;
    vector<Observer*> subscriberList;
};

int main(){

    StockMarket tesla("tesla" , 35.6);
    StockMarket bank("Bandhan-Bank" , 143.22);

    User u1("Raju") ;
    User u2("Bheem") ;

    tesla.addUser(&u1);
    bank.addUser(&u1);

    bank.addUser(&u2);
    bank.removeUser(&u2);

    tesla.setPrice(40.01);
    bank.setPrice(140.23);

return 0;
}