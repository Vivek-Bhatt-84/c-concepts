# include <iostream>
using namespace std;

void swap(int& x, int& y){

    int temp = x;
    x = y;
    y = temp;
}

int main(){

    int x = 4, y = 5;

    swap(x, y);

    cout << "Value of x: " << x << endl;
    cout << "Value of y: " << y;

    return 0;
}