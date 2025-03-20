#include<bits/stdc++.h>
#include <sstream>
using namespace std;

vector<char> extractChar(string str){
    vector<char> res;

    for(int i = 0 ; i < str.length() ; i++){
        res.push_back(str[i]);
    }
    return res;
}

int main(){
    string str;
    getline(cin , str);

    vector<char> res =  extractChar(str);

    for(auto& it : res){
        cout << it << " " ;
    }


return 0;
}