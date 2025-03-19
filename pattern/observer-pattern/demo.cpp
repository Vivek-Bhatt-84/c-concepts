#include<iostream>
#include <string>
#include <forward_list>
using namespace std;

class Observer{
    public:
        Observer(string name) : mName(name){}
        
        void onNotify(){
            cout << mName << "says Hello " << endl;
        }

    private:
        string mName;
};

class Subject{
    public:
        void addObserver(Observer* observer){
            mObserver.push_front(observer);
        }
        
        void removeObserver(Observer* observer){
            mObserver.remove(observer);
        }

        void notifyAll(){
            for(auto& o : mObserver){
                o->onNotify();
            }
        }
    private :
        forward_list<Observer*> mObserver;
};

int main(){
    Subject subject;
    Observer observer1("observer-1");
    Observer observer2("observer-2");
    Observer observer3("observer-3");

    subject.addObserver(&observer1);
    subject.addObserver(&observer2);
    subject.addObserver(&observer3);

    subject.notifyAll();



return 0;
}