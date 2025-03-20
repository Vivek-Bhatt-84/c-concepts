#include<bits/stdc++.h>
using namespace std;

void touppercase(string& str){
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        }
    }
}
void tolowercase(string& str){
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32;
        }
    }
}

int main(){
    string str = "HELLO";
    tolowercase(str);
    cout << str << endl;

return 0;
}