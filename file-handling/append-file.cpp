#include<bits/stdc++.h>
using namespace std;

int main(){
    fstream file("append.txt" , ios :: in | ios :: out | ios :: app);
    if(!file){
        cerr << "failed" << endl;

    }
    else{
        cout << "file opened " << endl;
        cout << "writing to file" << endl;
        file << "append successfully " << endl;

        cout << "reading from file " << endl;
        file.seekg(0);
        string tmp;
        while(file.good()){
            getline(file , tmp);
            cout << tmp << endl;
        }
    }

return 0;
}