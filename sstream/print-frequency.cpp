#include<bits/stdc++.h>
using namespace std;

void countFrequency(string str){
    map<string,int> mp;

    stringstream ss(str);

    string tmp;
    while(ss >> tmp){
        mp[tmp]++;
    }
    for(auto it : mp){
            cout << it.first << " -> " << it.second << endl;
        }
}

int main(){
    string str = "For Geeks Quiz Geeks Quiz Practice Practice";
    countFrequency(str);

return 0;
}