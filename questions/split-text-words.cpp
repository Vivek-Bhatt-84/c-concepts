#include<bits/stdc++.h>
using namespace std;

void func(string str){
    stringstream ss(str);
    string tmp ;
    while(ss >> tmp){
        cout << tmp << endl ; 
    }
}

int main(){
    string str = "this is a word" ;
    func(str);
return 0;
}