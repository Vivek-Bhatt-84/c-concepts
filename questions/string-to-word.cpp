#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<string,int>>> func(string str){
    stringstream ss(str);
    vector<vector<pair<string,int>>> res;
    string tmp;
    while(ss >> tmp){
        int len = tmp.length();
        pair<string,int> p = {tmp,len};
        vector<pair<string,int>> v ;
        v.push_back(p);
        res.push_back(v);
    }
    return res;
}

int main(){

    string str = "example string for storing length";
    vector<vector<pair<string,int>>> res = func(str);

    for(auto it : res){
        for(auto jt : it){
            cout << jt.first << ": " << jt.second << endl;
        }
    }

return 0;
}