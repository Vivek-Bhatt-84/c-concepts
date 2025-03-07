#include <iostream>
using namespace std;

class ShallowCopyExample
{
public:
    int *data;

    ShallowCopyExample(int value)
    {
        data = new int(value); // dynamically allocated memory
    }

    // copy constructor (shallow copy)
    ShallowCopyExample(const ShallowCopyExample &obj)
    {
        data = obj.data;
    }

    // Destructor to free memory
    ~ShallowCopyExample()
    {
        delete data;
    }

    void display()
    {
        cout << "Data: " << *data << endl;
    }
};

int main()
{
    ShallowCopyExample obj1(10);
    ShallowCopyExample obj2 = obj1; // shallow copy 

    obj1.display();
    obj2.display();

    *obj1.data = 20;

    obj1.display();  // Data: 20
    obj2.display(); // data changed 


    return 0;
}