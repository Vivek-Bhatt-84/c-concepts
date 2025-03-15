#include <iostream>
using namespace std;

class Reactangle{
private :
    int width , height ;
public :
    Reactangle() : Reactangle(0,0) {}

    Reactangle(int w ,int h) : width (w) , height(h) {}


    void display(){
        cout << "width : " << width << "height : " << height << endl;
    }
};

int main()
{

return 0;
}