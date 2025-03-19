#include<bits/stdc++.h>
using namespace std;

// observer interface
class Observer{
    public :
    virtual void update(const string& name , float price) = 0;
    virtual ~Observer() {}

};

class Customer : public Observer{
    public :
        Customer(const string& name) : cName(name) {}
        void update(const string& name , float price) override {
            cout << "update for : " << cName << endl;
            cout << "New Item Available " << name << " price : " << price << endl;
        }

    private :
        string cName;
};
// subject interface 
class Subject{
    public:
        virtual void addUser(Observer* observer) = 0;
        virtual void removeUser(Observer* observer) = 0;
        virtual void notifyAll() = 0;
        virtual ~Subject(){} 
};

class ShopingMall : public Subject{
    public:
    ShopingMall(){}
        ShopingMall(const string& item , float price) : sItem(item) , iPrice(price) {}

        void addUser(Observer* observer) override {
            list_customers.push_back(observer);
        }

        void removeUser(Observer* observer) override{
            list_customers.erase(remove(list_customers.begin() , list_customers.end() ,observer) , list_customers.end());
        }

        void notifyAll() override{
            for(auto& customer : list_customers)  {
                customer -> update(sItem , iPrice);
            }
        }
        
        void setItem(const string& name , float price){
            sItem = name ;
            iPrice = price;
            notifyAll();
        }

    private :
        vector<Observer*> list_customers;
        string sItem;
        float iPrice;
};


int main(){
    ShopingMall mall;
    
    Customer c1("Arun");
    Customer c2("Priya");

    mall.addUser(&c1);
    mall.addUser(&c2);

    mall.setItem("Laptop" , 35000.0);
    mall.setItem("iPhone 16", 92000.0);

    

return 0;
}