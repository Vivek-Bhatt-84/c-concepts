#include<bits/stdc++.h>
using namespace std;


int main(){
    int n = 7;
    for (int i = 1; i <= n; i++) {
        int spaces = abs(n / 2 - i + 1);
        int xCount = n - 2 * spaces;
        
        for (int j = 0; j < spaces; j++)
            cout << " ";
        
        for (int j = 0; j < xCount; j++)
            cout << "x";
        
        cout << endl;
    }

return 0;
}






