/**
 * clients should not be forced to depend on interfaces they don't use 
 * client should not implement unnecessary function they do not need 
 */

#include <iostream>
using namespace std;


/**
 *client have to override all virtual functions 
 * but what if client need only scan functionality 
 */


class Printer{
public:
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void fax() = 0;
};

// // concrete class implementation 
// class MultifunctionPrinter : public Printer{
// public:
// void print() override {
//     cout << "Printing document." << endl;
// }

// void scan() override {
//     cout << "Scanning document." << endl;
// }

// void fax() override {
//     cout << "Faxing document." << endl;
// }
// };

// fix :- split different functionality of printer into different abstract classes
class Printable {
    public:
        virtual void print() = 0;
    };
    
    class Scannable {
    public:
        virtual void scan() = 0;
    };
    
    class Faxable {
    public:
        virtual void fax() = 0;
    };


int main()
{

return 0;
}