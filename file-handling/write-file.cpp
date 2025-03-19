#include<bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){
    fstream file("test.txt");

    if(!file){
        cout << "failed" << endl;
    }
    else{
        cout << "success" << endl;
    }
    file <<  "writing into file " << endl;
    file << "writing with fstream " << endl;
    file.close();

return 0;
}