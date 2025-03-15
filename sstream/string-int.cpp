#include<bits/stdc++.h>
using namespace std;

int stringtoInt(string str){
    stringstream ss(str);
    int tmp;
    ss >> tmp;
    return tmp;
}

int main(){
    string str = "1234";
    cout << stringtoInt(str) + 1 << endl;
return 0;
}