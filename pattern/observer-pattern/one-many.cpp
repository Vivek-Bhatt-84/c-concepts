#include <bits/stdc++.h>
using namespace std;

class ObserverParent{
public :
    virtual void onUpdate() = 0;
    virtual ~ObserverParent(){} 
};

class Observer : public ObserverParent{
public :
    void onUpdate() override {
        cout << "message from onUpdate method" << endl;
    }

};

class Subject{
public :
    vector<ObserverParent*> store;
    void registerObserver(ObserverParent* obj){
        store.push_back(obj);
    }
    void unregister(ObserverParent* obj){
       store.erase(remove(store.begin(),store.end(),obj),store.end());
    }
    void update(const string& s){
       
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