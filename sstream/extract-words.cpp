#include<bits/stdc++.h>
using namespace std;

void extractWords(string str){
    stringstream ss(str);

    string tmp ;
    while(ss >> tmp){
        cout << tmp << endl;
    }
}

int main(){
    string str = "this is stringstream example";
    extractWords(str);
return 0;
}