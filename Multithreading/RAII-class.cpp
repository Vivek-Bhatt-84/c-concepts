#include <iostream>
using namespace std;

class RAIIeg
{
    int *ptr;

public:
    RAIIeg(int *p = NULL) : ptr(p) {}

    ~RAIIeg()
    {
        delete ptr;
        cout << "Memory released " << endl;
    }

    int &operator*() { return *ptr; }
};

int main()
{
    {
        RAIIeg sp(new int(42));
        cout << "Value : " << *sp << endl;
    }
    return 0;
}