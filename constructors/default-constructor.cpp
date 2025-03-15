#include <iostream>
using namespace std;

class Box{
public :
    int length;
    int width ;
    int height;

    Box(){
        length = 1;
        width = 1;
        height = 1;

    }

    void display(){
        cout << "Length: " << length << ", Width: " << width << ", Height: " << height << endl;
    
    }

};

// default parameters 

class Rectangle{
public:
    int width ;
    int height;

    Rectangle(int w = 5 , int h = 10){
        width = w;
        height = h;
    }

    void displayDimensions() {
        cout << "Width: " << width << ", Height: " << height << endl;
    }
};

class Circle{
public : 
    int radius ;

    void displayRadius(){
        cout << "Radius : " << radius << endl;
    }
};

class NoDefault{
public : 
    NoDefault() = delete;

    void displayMessage(){
        cout << "This class has no default constructor!" << endl;
    }

};

int main()
{

    // Box b1 ;
    // b1.display();

    // Rectangle r1;
    // r1.displayDimensions();

    // Rectangle r2(8,12);
    // r2.displayDimensions();

    // Circle c1;
    // c1.displayRadius();

    // NoDefault obj ;



return 0;
}