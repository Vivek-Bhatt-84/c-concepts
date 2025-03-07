#include <iostream>
using namespace std;

class Rectangle{
private :
    int length ;
    int width;

public :
    Rectangle(int l ,int w){
        length = l;
        width = w;
    }

    void display() {
        cout << "Length: " << length << ", Width: " << width << endl;
    }

};

int main()
{
    Rectangle r1(10,5);
    r1.display();

return 0;
}