#include<bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){

    fstream file;

    file.open("test.txt" ,ios::in | ios :: out | ios :: trunc ); // ios::in | ios :: out

    if(!file.is_open()){
        cout << "error in opening file " << endl;
    }
    else{
        cout << "file opened " << endl;
        file.close();
    }

return 0;
}