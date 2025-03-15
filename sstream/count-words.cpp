#include<bits/stdc++.h>
using namespace std;

int countWords(string str){

    stringstream ss(str);

    string word;

    int cnt = 0;
    while(ss >> word){
        cout << word << endl;
        cnt++;
    }
    return cnt;
}

int main(){
    string s = "I have installed ubuntu on my laptop";
    cout << "No of words : " << countWords(s) << endl;

return 0;
}