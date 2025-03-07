#include <bits/stdc++.h>
using namespace std;

class Observer{
public :
    void onUpdate(){
        cout << "message from onUpdate method" << endl;
    }

};

class Subject{
public :
    Observer* oobj;
    void registerObserver(Observer &obj){
        oobj = &obj;
    }
    void unregister(){
        oobj = nullptr;
        cout << "Observer unregistered " << endl;
    }
    void update(){
        if(oobj){
            oobj -> onUpdate();
        }
        else{
            cout << "No observer registered " << endl;
        }
    }

};

int main()
{
    Subject s;
    Observer o;
    s.update();

    s.registerObserver(o);
    s.update();
    s.unregister();

return 0;
}