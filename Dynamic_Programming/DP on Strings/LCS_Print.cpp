// https://www.codingninjas.com/studio/problems/print-longest-common-subsequence_8416383

#include <bits/stdc++.h> 
using namespace std;

string findLCS(int n, int m, string s1, string s2){

    // Here Base case is defined for indexes < 0, but we cant have that in dp.
    // So we've done Shifting of index --> row 0 & col 0 represents indexes < 0
    // and ind1, ind2 represents ind1-1 and ind2-1.
        
    vector<vector<int>> dp(n+2, vector<int> (m+2, 0));
    
    for(int ind1=1 ; ind1<=n ; ind1++){
        for(int ind2=1 ; ind2<=m ; ind2++){ 
            
            if(s1[ind1-1] == s2[ind2-1]){
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                // bec if matched we dont need to check that in again.
            }
            else{
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
            }
        }
    }
    
    string ans = "";
    int i = n, j = m;

    while(i > 0 && j > 0){
        // If current character in both the strings are same, then current character is part of LCS
        if(s1[i - 1] == s2[j - 1]){
            ans += s1[i-1];
            i--;
            j--;
        }
        // If current character in X and Y are different & we are moving upwards
        else if(dp[i - 1][j] > dp[i][j - 1]){
            i--;
        }
        // If current character in X and Y are different & we are moving leftwards
        else{
            j--;
        }
    }
    reverse(ans.begin(), ans.end());

    return ans;
}
