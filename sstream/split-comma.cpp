#include<bits/stdc++.h>
using namespace std;

void splitByComma(string str){
    stringstream ss(str);
    string tmp;
    while(getline(ss , tmp, ',')){
        cout << tmp << endl;
    }



}

int main(){
    string str = "10,20,30,40,50";
    splitByComma(str);

return 0;
}