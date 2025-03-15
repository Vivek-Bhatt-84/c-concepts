#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 123;

    stringstream ss;
    ss << a;
    string x;
    ss >> x;

    cout << x + "1" << endl;

return 0;
}