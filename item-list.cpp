#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item{
public :
  int value;
  string name;
  int quantity;
  
  Item(int value ,string name ,int quan){
      this -> value = value ;
      this -> name = name;
      this -> quantity = quan;
  }
  
   void addQuan(int quan){
        quantity = quantity + quan;
    }
    
    void displayItems(){
        cout << "value : " << value << " name : " << name << " quantity : " << quantity << endl;
    }
  
};

class Inventory{
public :
    vector<Item*> inv;
    
   
    
    void addItem(int value , string name ,int quan){
        // if item already present 
        for(Item* it : inv){
            if(it -> name == name){
                // item present 
                it->addQuan(quan);
                return;
            }
        }
        Item* tmp  = new Item(value,name,quan);
        inv.push_back(tmp);
    }
    
    void display(){
        for(Item* it : inv){
             it -> displayItems();
        }
    }
    
};

int main(){
    
    Inventory i1 ;
    i1.addItem(10, "test_item", 20);
    i1.addItem(10,"test_item",30);
    i1.display();
    
    return 0;
}