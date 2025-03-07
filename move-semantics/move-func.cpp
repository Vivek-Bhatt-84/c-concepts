#include <iostream>
#include <vector>
using namespace std;

class A{
    int *p;
public :
    A(){
        p = new int[100];
        cout << "Default Const" << endl;
     }
    A(const A& aObj){
        p = new int[100];
        for(auto i = 0 ; i < 100 ; i++){
            p[i] = aObj.p[i];
        }
        cout << "Copy const" << endl;
    }
    A(const A&& obj) : p(obj.p) {
        // obj.p = nullptr;
        cout << "move constr" << endl;
    }

    A& operator=(const A& obj){
        cout << "Copy assignment " << endl;
        p = new int[100];
        for(auto i = 0 ; i < 100 ; i++){
            p[i] = obj.p[i];
        }

        return *this;

    }
    A& operator=( A&& obj){
        cout << "Move assignment " << endl;
        // free resources of this object 
        delete[] p;
        p = obj.p;
        obj.p = nullptr;

        return *this;

    }
};

void printVector(vector<int>& v){
    cout << "print vector " << v.size() << endl;
    for(auto i = v.begin() ; i != v.end() ; i++){
        cout << *i << " " ;
    }
    cout << endl;
}

template <typename T>
void swap(T& a ,T& b){
    T tmp = move(a);
    a = move(b);
    b = move(tmp);
}

int main()
{
    vector<int> v1;
    vector<int> v2;

    for(int i = 0 ; i < 5 ; i++){
        v1.push_back(i);
    }
    for(int i = 10 ; i < 15 ; i++){
        v2.push_back(i);
    }

    printVector(v1);
    printVector(v2);
    
    
    // cout << "printing after copying v1 to v2" << endl;
    // v2 = move(v1);

    swap(v1,v2);
    
    printVector(v1);
    printVector(v2);
    
    A a;
    // A b = move(a);
    // A c(move(b));
    A b;
    b = move(a);

return 0;
}