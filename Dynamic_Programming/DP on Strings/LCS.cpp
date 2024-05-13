// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h> 
using namespace std;

// Memoization--------------------------------------------------------------

// solve(ind1, ind2) represents longest common sunsequence
// till ind1 in string 1 and till ind2 in string 2.

int solve(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp){
        
    if(ind1 < 0 || ind2 < 0){
        return 0;
    }
    
    if(dp[ind1][ind2] != -1){
        return dp[ind1][ind2];
    }
    
    if(s1[ind1] == s2[ind2]){
        return 1 + solve(ind1-1, ind2-1, s1, s2, dp);
        // bec if matched we dont need to check that in again.
    }
    
    return dp[ind1][ind2] = 0 + max(solve(ind1-1, ind2, s1, s2, dp), solve(ind1, ind2-1, s1, s2, dp));
    // bec we will check which index to move and return the one that gives max ans. 
}

int lcs(int n, int m, string s1, string s2){
    
    vector<vector<int>> dp(n, vector<int> (m, -1));
    return solve(n-1, m-1, s1, s2, dp);
}

// Tabulation -----------------------------------------------------------------

int lcs(int n, int m, string s1, string s2){

    // Here Base case is defined for indexes < 0, but we cant have that in dp.
    // So we've done Shifting of index --> row 0 & col 0 represents indexes < 0
    // and ind1, ind2 represents ind1-1 and ind2-1.
        
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    
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
    
    return dp[n][m];
    // bec we needed to return dp[n-1][m-1];
}

// Space Optimised ----------------------------------------------------------

int lcs(int n, int m, string s1, string s2){
        
    vector<int> prev(m+1, 0), curr(m+1, 0);
    
    for(int ind1=1 ; ind1<=n ; ind1++){
        for(int ind2=1 ; ind2<=m ; ind2++){
            
            if(s1[ind1-1] == s2[ind2-1]){
                curr[ind2] = 1 + prev[ind2-1];
                // bec if matched we dont need to check that in again.
            }
            else{
                curr[ind2] = 0 + max(prev[ind2], curr[ind2-1]);
            }
        }
        
        prev = curr;
    }
    
    return curr[m];
}
