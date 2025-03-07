#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class ObserverParent{
public :
string type;
    virtual void onUpdate(const string& str) = 0;
    ObserverParent(string st = "") : type(st) {}
};

class Observer1 : public ObserverParent{
    public:
    Observer1(string t) :  ObserverParent(t){}

        void onUpdate(const string& s) override {
            cout << "Observer [" << type << "] received message: " << s << endl;    
        }
    
};

class Subject{
public:
    vector<ObserverParent*> lst;

    void lstSize(){
        cout << lst.size() << endl;
    }


    void registerObs(ObserverParent* obj){
        lst.push_back(obj);
    }
    void unregister(ObserverParent* obj){
        // lst.erase(remove(lst.begin(), lst.end(), obj), lst.end());
        auto it = remove(lst.begin(), lst.end(), obj);
        if (it != lst.end()) {
            cout << "Unregistering observer: " << obj->type << endl;
            lst.erase(it, lst.end());
        } else {
            cout << "Observer not found: " << obj->type << endl;
        }
    }
    void update(const string& str){
        // for(auto obs : lst){
        //    if(obs -> type == str){
        //     obs -> onUpdate("Update for " + str);
        //    }
        // }

        if (lst.empty()) {
            cout << "No observers to update." << endl;
            return;
        }
        for (auto obs : lst) {
            if (obs->type == str) {
                obs->onUpdate("Update for " + str);
            }
        }
    }
};



int main()
{
    Subject s;
    
    Observer1* obj1 = new Observer1("obj1");
    Observer1* obj2 = new Observer1("obj2");

    s.registerObs(obj1);
    s.registerObs(obj2);

    s.update("obj1");

    s.unregister(obj1);
    s.unregister(obj2);

    delete obj1;  // Free memory safely
    delete obj2;

return 0;
}