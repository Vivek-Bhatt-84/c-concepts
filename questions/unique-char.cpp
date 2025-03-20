#include<bits/stdc++.h>
using namespace std;

vector<char> findUnique(string str){
    int frequency[256] = {0};

    for(int i = 0 ; i < str.length() ; i++){
        frequency[str[i]]++;  
    }
        vector<char> res;
    for(int i = 0 ; i < 256 ; i++){
        if(frequency[i] == 1){
            res.push_back((char)i);
        }
    }
    return res;
}

int main(){
    string str = "unique character string ";
    vector<char> res = findUnique(str);

    for(auto it : res){
        cout << it << " " ;
    }

return 0;
}