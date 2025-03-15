#include <iostream>
#include <string>
#include <vector>
using namespace std;



// int f(string& s1 , string& s2 , int i1 , int i2 , vector<vector<int>>& dp){

//     if(i1 < 0 || i2 < 0){
//         return 0;
//     }

//     if(dp[i1][i2] != -1) return dp[i1][i2];

//     if(s1[i1] == s2[i2]){
//         return dp[i1][i2] =  1 + f(s1 , s2 , i1 - 1 , i2 - 1 ,dp);
//     }

//     return dp[i1][i2] = max(f(s1,s2,i1-1,i2, dp),f(s1,s2,i1,i2-1 ,dp));
// }

// int longestCommonSubsequence(string s1 , string s2){
//     int n1 = s1.size();
//     int n2 = s2.size();
//     vector<vector<int>> dp(n1,vector<int>(n2, -1));
//     return f(s1,s2,n1 - 1,n2 - 1 ,dp);
// }

int longestCommonSubsequence(string s1 , string s2){
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1,vector<int>(m + 1, 0));
    for(int i = 0 ; i < n ; i++ )dp[i][0] = 0;
    for(int j = 0 ; j < n ; j++ )dp[0][j] = 0;

    for(int i = 1 ; i <=n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s1[i-1] == s2[j-1] ) dp[i][j] = 1 + dp[i-1][j-1];
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            } 
        }
    }
    return dp[n][m];
}

int main()
{
    string s1 = "pmjghexybyrgzczy";
    string s2 = "hafcdqbgncrcbihkd";
    cout << longestCommonSubsequence(s1,s2) << endl;

return 0;
}