#include<bits/stdc++.h>
using namespace std;

void reverseWords(string str){
    stringstream ss(str);

    vector<string> v;
    string tmp;
    while(ss >> tmp){
        v.push_back(tmp);
    }
    for(int i = v.size()-1 ; i >=0 ; i--){
        cout << v[i] << " " ;
    }
}

int main(){
    string str = "word reversed a is this" ;
    reverseWords(str);

return 0;
}