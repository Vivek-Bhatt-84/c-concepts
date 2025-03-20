#include<bits/stdc++.h>
using namespace std;

string createsubstring(string str , int s , int e){
    string tmp;
    for(int i = s ; i < e; i++){
        tmp += str[i];
    }
    return tmp;
}

int main(){
    string str;
    cin >> str;

    string res = createsubstring(str,0,3);
    if(str.substr(0,2).compare(res)){
        cout << "equal " << endl;
    }
    else{
        cout << "false" << endl;
    }

return 0;
}