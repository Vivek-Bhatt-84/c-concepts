#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

class Contact{
    string name;
    string phno;
    string email;
public :

    Contact(string n ,string p  ,string e) : name(n) , phno(p) ,email(e){}

    string getName(){
        return name;
    }

    void display(){
        cout << "Name : " << name << "\nPhone no : " << phno << "\nEmail address : " << email << endl;
        cout << "----------------------------------------------------------------------------------" << endl;
    }

};

class AddressBook{
    vector<Contact*> book;
    set<string> contact_names;

public:

    void addContacts(string& nme , string& pno , string& mail){
        if(contact_names.find(nme) != contact_names.end() ){
            cout << "Contact with name " << nme << "exists." << endl;
        }
        Contact* c1 = new Contact(nme , pno ,mail);
        book.push_back(c1);
        contact_names.insert(nme);
        cout << "Contact added successfully ." << endl;
    }

    void displayContact(){
        if(book.empty()){
            cout << "address book is empty." << endl;
        }
        for(const auto& it : book ){
            it -> display();
        }
    }

    void searchContact(const string& nme){
        for(auto& it : book){
            if(it -> getName() == nme){
                cout << "Contact found" << endl;
                it -> display();
            }
        }
        cout << "Not found " << endl;
    }

    void deleteContact(string& name){
        
    }

};


void init(){
    AddressBook b1;
    int choice ;
    do{
        cout << "------------Address Book Menu -----------------------" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Display Contacts. " << endl;
        cout << "3. search contact " << endl;
        cout << " -1 to exit " << endl;
        cout << "enter your choice " << endl;
        cin >> choice;
        cin.ignore();
        string name , phno ,email;

        switch(choice){
            case 1: {
                cout << "Enter name " << endl;
                getline(cin,name);
                cout << "Enter Phone no :  " << endl;
                getline(cin,phno);
                cout << "Enter email :  " << endl;
                getline(cin,email);
                b1.addContacts(name, phno, email);
                break;
            }
            case 2: {
                b1.displayContact();
                break;
            }
            case 3 :{
                cout << "Enter name to search " << endl;
                getline(cin ,name);
                break;
            }
        }

    }
    while(choice != -1);
}

int main()
{
    init();

return 0;
}