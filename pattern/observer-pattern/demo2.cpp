#include<iostream>
#include <string>
#include <forward_list>
using namespace std;


// base class 
class IObserver{
    public:        
        virtual void onNotify() = 0;
        virtual ~IObserver(){}
};

// concrete observer 
class Watcher : public IObserver{
    public:
        Watcher(const string& name ) : mName(name) {}
        void onNotify() override {
            cout << "Watcher - " << mName << endl;
        }
    private:
        string mName; 
};


class ISubject{
    public:
        virtual ~ISubject() {}
        virtual void addObserver(IObserver* observer){
            mObserver.push_front(observer);
        }
        
        virtual void removeObserver(IObserver* observer){
            mObserver.remove(observer);
        }

        virtual void notifyAll(){
            for(auto& o : mObserver){
                o->onNotify();
            }
        }
    private :
        forward_list<IObserver*> mObserver;
};

class SomeSubject : public ISubject{
    public:
};  

int main(){
    
    SomeSubject subject;
    Watcher watcher1("observer-1");
    Watcher watcher2("observer-2");
    Watcher watcher3("observer-3");
    
    subject.addObserver(&watcher1);
    subject.addObserver(&watcher2);
    subject.addObserver(&watcher3);

    subject.notifyAll();


return 0;
}

/*
is this 
flexible - > need more power 
mainatnable -> yes , need to keep interfaces abstract 
extensible -> can use inheritance 
*/