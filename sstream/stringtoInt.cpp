#include<bits/stdc++.h>
#include <sstream>
#include <typeinfo>
using namespace std;

int main(){
    string str = "1234";
    stringstream ss(str);
    int num;
    ss >> num;
    cout << "Integer : " << num << endl;
    cout << typeid(num).name() << endl;

return 0;
}