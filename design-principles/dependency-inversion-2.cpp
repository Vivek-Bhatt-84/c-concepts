#include <iostream>
using namespace std;

class abstractDB{
public :
    virtual void dbConnect() = 0;
    virtual void add() = 0;
    virtual void deleteDB() = 0;
};

class Sql : public abstractDB{
public :
    void dbConnect() override {
        cout << "Sql connected" << endl;
    }
    void add() override {
        cout << "data added in sql " << endl;
    }
    void deleteDB() override {
        cout << "data deleted from sql " << endl;
    }
};
class Mongo : public abstractDB{
public :
    void dbConnect() override {
        cout << "Mongo connected" << endl;
    }
    void add() override {
        cout << "data added in Mongo " << endl;
    }
    void deleteDB() override {
        cout << "data deleted from Mongo " << endl;
    }
};

class DashBoard {
public : 
    abstractDB* db ;
    DashBoard(abstractDB &obj){
        db = &obj;
    }
    void fun(){
        db -> dbConnect();
        db -> add();
        db -> deleteDB();
    }
};

int main()
{   
    // Mongo obj1;
    // DashBoard d(obj1) ;

    // d.fun();

    
    // DashBoard* d2 = new Mongo(); give error 

return 0;
}