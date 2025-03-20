#include<bits/stdc++.h>
using namespace std;

bool compareStrings(string s1 , string s2){
    if(s1.compare(s2) == 0){
        return true;
    }
    return false;
}

int main(){

    string s1,s2;
    getline(cin , s1);
    getline(cin , s2);

    if(compareStrings(s1,s2)){
        cout << "equal " << endl;
     }
     else{
        cout << "not equal " << endl;
     }
return 0;
}