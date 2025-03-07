#include <iostream>
using namespace std;

class Complex{
private :
    int a ,b;
public :
    void setData(int x ,int y){
        a = x;
        b = y;
    }

    void showData(){
        cout << " a = " << a << " b = " << b << endl;
    }

   
};

int main()
{

return 0;
}