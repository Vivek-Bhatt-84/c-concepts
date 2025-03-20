#include<bits/stdc++.h>
using namespace std;

class Test{
    public :
        virtual void fun1(){
            cout << "hello test " << endl;
        }

};
class Test2{
    public :
        virtual void fun2(){
            cout << "hello test2 " << endl;
        }

};
class Test3 : public Test , public Test2{
    public :
        //  void fun1() override {
        //     cout << "hello test2 " << endl;
        // }

};

int main(){
    cout << sizeof(Test3) << endl;
    // Test2 obj;
    // obj.fun1();

return 0;
}