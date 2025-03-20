#include <bits/stdc++.h>
using namespace std;


bool areAnagrams(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return false; 
    }

    int freq[256] = {0}; 

   
    for (char ch : str1) {
        freq[ch]++;
    }


    for (char ch : str2) {
        freq[ch]--;
    }

   
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string str1, str2;

    cin >> str1 >> str2;

    if (areAnagrams(str1, str2)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}
