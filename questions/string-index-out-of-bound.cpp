#include<bits/stdc++.h>
using namespace std;

void traverseString(string str){
    for(int i = 0 ; i <= str.length() ; i++){
        if(i > str.length() - 1){
            throw runtime_error("string index out of bound" );
        }
        else{
            cout << str[i] << " ";
        }
    }
}

int main(){
    string str = "hello";

    try{
        traverseString(str);
    }
    catch(exception& e){
        cout << "exception caught : " << e.what() << endl;
    }

return 0;
}