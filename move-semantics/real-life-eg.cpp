// Move semantics
#include <iostream>
using namespace std;

 class A{
     int *id;
     string *name;
     public:
     A(int i, string n){
         this->id = new int(i);
         this->name = new string(n);
     }
     A(A&obj){
         this->name = new string(*obj.name);
         this->id = new int(*obj.id);
     }
     
     A(A&& obj){
         this->name = new string(*obj.name);
         this->id = new int(*obj.id);
         obj.name = nullptr;
         obj.id = nullptr;
     }
     void show(){
        if(name && id){
            cout<<*this->id<<" "<<*this->name<<" \n";
        }
        else{
            cout<<"nullptr\n";
        }
     }
     
     A& operator = (A&& obj){
         delete this->name;
         delete this->id;
         this->name = new string(*obj.name);
         this->id = new int(*obj.id);
         obj.name = nullptr;
         obj.id = nullptr;
         return * this;
     }
 };
int main()
{
    A a(1,"John");
    A b = move(a);
    a.show();
    b.show();


    return 0;
}
