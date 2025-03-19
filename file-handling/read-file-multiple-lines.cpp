#include<bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){
    ifstream file;
    file.open("read-mutltiple");

    if(!file){
        cout << "failed" << endl;
    }
    else{
        string line ;
        while(file.good()){
            getline(file , line);
            cout << line << endl;
        }
        file.close();
    }

return 0;
}