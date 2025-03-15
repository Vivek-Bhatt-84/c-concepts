#include <iostream>
using namespace std;

class MoveEg{
    int* data;

public :
    MoveEg(int val) : data(new int(val)){}

    // move assignment operator
    MoveEg& operator=(MoveEg&& other) { 
        if(&other != this){ // prevent self assignment 
            delete data; // delete existing resource
        

        // transfer ownership 
        data = other.data;
        other.data = nullptr;
        }
        return *this;

    }  

    void show(){
        if(data){
            cout << "Data : " << *data << endl;
        }
        else{
            cout << "Data: nullptr" << endl;
        }
    }

    ~MoveEg(){
        delete data;
    }
};

int main()
{
    MoveEg a(10) ,b(20);
    b = move(a);

    a.show();
    b.show();

return 0;
}