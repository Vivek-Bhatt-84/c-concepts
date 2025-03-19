#include<bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){
    ifstream file;
    file.open("test.txt");

    if(!file){
        cout << "failed" << endl;
    }
    else{
        string line ;
        getline(file , line);
        cout << line << endl;
        file.close();
    }

return 0;
}