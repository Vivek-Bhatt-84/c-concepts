#include <iostream>
using namespace std;

class MyClass{
    int* data;

public:
    MyClass(int val) : data(new int(val)){
        cout << "Constructor called" << endl;
    }

    MyClass(const MyClass& obj) : data(new int(*obj.data)){
        cout << "Copy constructor called" << endl;
    }

    MyClass& operator=(MyClass&& obj) noexcept {
        if(this != &obj){
            delete data;

            data = obj.data;
            obj.data = nullptr;
            cout << "Move Assignment Operator called\n";
        }
        return *this;
    }

    ~MyClass(){
        delete data;
        cout << "Destructor called" << endl;
    }



    // void show(){
    //     cout << "Data : " << *data << endl;
    // }
    void show()  { 
        if (data) cout   << "Data: " << *data << std::endl;
        else std::cout << "Data: nullptr" << std::endl;
    }
};

int main()
{
    // MyClass a(10);
    // MyClass b = a;

    MyClass a(10);
    MyClass b(20);

    b = move(a);
    b.show();
    a.show();


return 0;
}