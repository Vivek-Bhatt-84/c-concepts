/**
 *  Create a std::vector Wrapper with Move Semantics

👉 Problem: Implement a class VectorWrapper that wraps std::vector<int> and supports efficient move semantics.

    Implement move constructor and move assignment operator.
 */

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class vectorWrapper{
    vector<int> v;
public:
    vectorWrapper(vector<int>& t) : v(t){}

    vectorWrapper(vectorWrapper&& obj){
        v = move(obj.v);
    }

    vectorWrapper& operator=(vectorWrapper&& obj){
        if(this != &obj){
           v = move(obj.v); 
        }
        return *this;
    }
    void print()  {
        for (int i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    std::vector<int> vec = {1, 2, 3};
    vectorWrapper vw1(vec);  // Initialize with a vector
    vectorWrapper vw2 = std::move(vw1);  // Move constructor
    
    std::cout << "vw2 after move: ";
    vw2.print();  // Should print 1 2 3

    vector<int>tmp = {4, 5, 6};
    vectorWrapper vw3(tmp);
    vw3 = std::move(vw2);  // Move assignment operator
    
    std::cout << "vw3 after move assignment: ";
    vw3.print();  // Should print 1 2 3

    std::cout << "vw2 after move assignment: ";
    vw2.print();  // Should print nothing (empty vector)


return 0;
}