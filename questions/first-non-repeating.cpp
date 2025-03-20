#include<bits/stdc++.h>
using namespace std;

void findUnique(string str){
    int frequency[256] = {0};

    for(int i = 0 ; i < str.length() ; i++){
        frequency[str[i]]++;  
    }
    
    for(int i = 0 ; i < 256 ; i++){
        if(frequency[i] == 1){
            cout << (char) i << endl;
            break;
        }
    }
    
}

int main(){
    string str = "unique character string ";
    findUnique(str);


return 0;
}