#include<bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){

    ifstream file("position" , ios :: in);

    if(!file){
        cerr << "failed" << endl;
    }
    else{
        cout << file.tellg() << endl;   
        string line;
        file.seekg(5);
        getline(file,line);
        cout << line << endl;
    }

    file.close();

return 0;
}