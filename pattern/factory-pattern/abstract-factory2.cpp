#include<bits/stdc++.h>
using namespace std;

class Notification{
    public :
        virtual void notify() = 0;

};

class Email : public Notification{
    public :
        void notify() override{
            cout << "this is email Notification " << endl;
        }
};

class SMS : public Notification{
    public :
        void notify() override{
            cout << "this is sms Notification " << endl;
        }
};


class AbstractNotifyFactory{
    public :
        virtual Notification* createNotification(const string& type) = 0;
};  

class NotifyFactory : public AbstractNotifyFactory{
    public :
         Notification* createNotification(const string& type){
            if(type == "SMS"){
                return new SMS();
            }
            if(type == "Email"){
                return new Email();
            }
            return nullptr;
        }
};


int main(){
    AbstractNotifyFactory* obj = new NotifyFactory() ;
    Notification* message  = obj -> createNotification("Email");
    message -> notify();


return 0;
}