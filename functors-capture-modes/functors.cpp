#include <iostream>
using namespace std;

struct Value{
    int val{0};  // using {} -> list initialization (uniform initialization)  -> can be used to provide default values in struct 
    float val2{0};

    int operator()(int newRes){
        val = newRes;
        return newRes;
    }
    float operator()(float newRes2){
        val2 = newRes2;
        return newRes2;
    }

};

int main()
{
    Value v;
    v(42);
    v(42.7f);    
    cout << v.val << " " << v.val2 << endl;

return 0;
}