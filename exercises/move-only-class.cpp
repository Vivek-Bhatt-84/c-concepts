#include <iostream>
using namespace std;

class MoveOnly{
    int* data;

public:
    MoveOnly(int val) : data(new int(val)) {}

    MoveOnly(const MoveOnly&) = delete;
    MoveOnly& operator=(const MoveOnly&) = delete;

    MoveOnly( MoveOnly&& obj){
        data = obj.data;
        obj.data = nullptr;
        cout << "Move Constructor called " << endl;
    }

    MoveOnly& operator=(MoveOnly&& obj){
        if(this != &obj){
            delete data;
            data = obj.data;
            obj.data = nullptr;
            cout << "move assignment operator called " << endl;
        }
        return *this;
    }

    int getData(){
        return *data;
    }
};

int main()
{
    MoveOnly obj(10);
    cout << obj.getData() << endl;

    MoveOnly obj2 = move(obj);
    cout << obj2.getData() << endl;
    cout << obj.getData() << endl;

    // MoveOnly obj3 = obj2;


return 0;
}