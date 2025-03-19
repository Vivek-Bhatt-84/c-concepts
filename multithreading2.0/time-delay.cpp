#include<bits/stdc++.h>
using namespace std;

int main(){

    cout << "starting countdown" << endl;
    for(int i = 5 ; i>0 ; i--){
        cout << "time remaining " << i << "..." << endl;
        this_thread::sleep_for(chrono::seconds(2));
    }

    cout << "time up " << endl;

return 0;
}