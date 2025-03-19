#include<bits/stdc++.h>
using namespace std;

void extractNumbers(string str){
    stringstream ss(str);
    string tmp ;

    while(ss >> tmp){
        bool isNumber = true;
        for(char ch : tmp){
            if(!isdigit(ch)){
                isNumber = false;
                break;
            }
        }
        if(isNumber){
            cout << tmp << " " ;
        }
    }
}

int main(){
    string str = "My age is 21 and my roll number is 105";
    extractNumbers(str);
return 0;
}