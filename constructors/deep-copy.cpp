#include <iostream>
using namespace std;

class DeepCopyExample
{
public:
    int *data;

    DeepCopyExample(int value)
    {
        data = new int(value);
    }

    // copy constructor (deep copy )
    DeepCopyExample(const DeepCopyExample &obj)
    {
        data = new int(*obj.data); // Deep copy: new memory is allocated and data is copied
    }

    // Destructor to free memory
    ~DeepCopyExample()
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
    DeepCopyExample obj1(10);
    DeepCopyExample obj2 = obj1;

    obj1.display();  // Data: 10
    obj2.display();  // Data: 10

    *obj1.data = 20;

    obj1.display();  
    obj2.display();  

    return 0;
}