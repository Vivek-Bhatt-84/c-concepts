#include <iostream>
#include <memory>
using namespace std;

class Test{
public:
    Test(){
        cout << "Test object created " << endl;
    }

    ~Test(){
        cout << "test object destroyed " << endl;
    }

    void display(){
        cout << "hello from test class " << endl;
    }
};

int main()
{

    unique_ptr<Test> ptr = make_unique<Test>();
    // unique_ptr<Test> ptr(new Test());
    ptr -> display();

    // copy not allowed 
    // unique_ptr<Test> ptr2 = ptr;

    // move to resolve error
    unique_ptr<Test> ptr2 = move(ptr);

    if(!ptr) cout << "ptr is now nullptr\n" << endl;


return 0;
}