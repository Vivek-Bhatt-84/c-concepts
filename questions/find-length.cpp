#include<bits/stdc++.h>
using namespace std;

int findLength(string str){
    int len = 0;
    for(char c : str){
        len++;
    }
    return len;
}

int main(){
    string str = "hello world";
    cout << findLength(str) << endl;

return 0;
}