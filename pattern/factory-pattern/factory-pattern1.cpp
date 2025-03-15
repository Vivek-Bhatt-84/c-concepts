/**
 * encapsulates object creation logic inside dedicated  function 
 * abstract class -> defines common contract for all products 
 *  concrete class -> actual implementation of interface 
 * factory -> contains a method and return objects dynamically 
 */

#include <bits/stdc++.h>
using namespace std;

class Shape{
public:
    virtual void draw() = 0;
};

class Circle : public Shape{
public:
    void draw() override{
        cout << "drawing circle " << endl;
    }
};

class Rectangle : public Shape{
public :
    void draw() override{
        cout << "drawing rectangle" << endl;
    }
};

class Square : public Shape{
public :
    void draw() override{
        cout << "drawing Square" << endl;
    }
};

class ShapeFactory{
public :
    static unique_ptr<Shape> createShape(const string& type){
        if (type == "Circle") return make_unique<Circle>();
        if (type == "Square") return make_unique<Square>();
        if (type == "Rectangle") return make_unique<Rectangle>();
        return nullptr; 
    }
};



int main()
{

    auto shape1 = ShapeFactory :: createShape("Circle");
    if(shape1) {
        shape1 -> draw();
    }

return 0;
}

/**
 * client interacts with factory 
 * Advantage  - > 
 * encapsulation of object - client do not need to know which class to instantiate 
 * code reusability 
 * 
 * limitation 
 * violates open closed principle -> adding new shape we have to modify shape factory 
 */