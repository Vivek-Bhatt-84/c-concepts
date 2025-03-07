#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Item{
    int id;
    string name;
public :
    Item(int i, string nme) : id(i) , name(nme){}

    void display(){
        cout << "Item ID : " << id << " Name : " << name << endl;
    }
};

class Inventory{
    vector<unique_ptr<Item>> game_inv;
public:

    void addItems(int id , const string& nme){
        game_inv.push_back(make_unique<Item>(id,nme));
    }

    void displayItems(){
        for(auto& it : game_inv){
            it -> display();
        }
    }


};

int main()
{
    unique_ptr<Inventory> i1 = make_unique<Inventory>();
    i1 ->addItems(1,"Sword");
    i1 -> addItems(2,"gun");
    i1 -> addItems(3, "machinegun");
    i1 -> addItems(4, "potion");

    // i1 -> displayItems();

    unique_ptr<Inventory> i2 = move(i1);
    i1 -> displayItems();
    i2 -> displayItems();


return 0;
}