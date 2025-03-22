#include<bits/stdc++.h>
using namespace std;

class Contact{
    public:
        string name;
        string phNo;
        string address;
        int id;

        Contact(string cName ,string cphno , string cAddr , int id){
            name = cName;
            phNo = cphno;
            address = cAddr;
            this -> id = id;
        } 

        void displayInfo(){
            cout << name << " " << phNo << " " << address << " " << id << endl;
        }
};

class AddressBook{
    vector<unique_ptr<Contact>> contactList;
    public :

    AddressBook(AddressBook&) = delete;
    AddressBook& operator=(AddressBook&) = delete;

    AddressBook(){}

    void addContact(unique_ptr<Contact> obj){
        contactList.push_back(move(obj));
    }


    void removeContact(int id){
        for(auto it = contactList.begin() ; it != contactList.end() ; it++ ){
            if((*it)->id == id){
                unique_ptr<Contact> tmp = move(*it);
                contactList.erase(it);
                cout << "removed contact " << tmp->name << endl;  
                return;              
            }
        }
    }

    void showBook(){
        for(auto& it : contactList){
            it -> displayInfo();
        }
    }

};

int main(){

    unique_ptr<Contact> c1 = make_unique<Contact>("John" , "0987654321","powder gali" , 1);
    unique_ptr<Contact> c2 = make_unique<Contact>("Jethalal" , "0987654321","gokuldham" , 2);

    AddressBook obj;
    obj.addContact(move(c1));
    obj.addContact(move(c2));
    obj.showBook();

    cout << "after deletion " << endl;
    obj.removeContact(2);
    obj.showBook();


    

return 0;
}