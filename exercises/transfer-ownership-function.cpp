#include <iostream>
#include <utility>
#include <memory>
using namespace std;

unique_ptr<int> createInt(int val){
    unique_ptr<int> res = make_unique<int>(val);
    return res; 
}

int main()
{
    unique_ptr<int> p = createInt(10);
    cout << *p << endl;
    unique_ptr<int> p2 = move(p);
    cout << *p2 << endl;
    if(p){
        cout << "p after its resources are transfered : " << *p << endl;
    }
    else{
        cout << "p is null " << endl;
    }

return 0;
}