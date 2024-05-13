// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h> 
using namespace std;

// Tabulation ---------------------------------------------------------------

int longestCommonSubstr (string S1, string S2, int n, int m){

    // Here Base case is defined for indexes < 0, but we cant have that in dp.
    // So we've done Shifting of index --> row 0 & col 0 represents indexes < 0
    // and ind1, ind2 represents ind1-1 and ind2-1.
        
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    
    int ans = 0;
    
    for(int ind1=1 ; ind1<=n ; ind1++){
        for(int ind2=1 ; ind2<=m ; ind2++){
            
            if(S1[ind1-1] == S2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                
            else{
                dp[ind1][ind2] = 0;
            }
            
            ans = max(ans, dp[ind1][ind2]);
        }
    }
    
    return ans;
}

// Space Optimised ---------------------------------------------------------

int longestCommonSubstr (string S1, string S2, int n, int m){

    // Here Base case is defined for indexes < 0, but we cant have that in dp.
    // So we've done Shifting of index --> row 0 & col 0 represents indexes < 0
    // and ind1, ind2 represents ind1-1 and ind2-1.
        
    vector<int> prev(m+1, 0), curr(m+1, 0);
    
    int ans = 0;
    
    for(int ind1=1 ; ind1<=n ; ind1++){
        for(int ind2=1 ; ind2<=m ; ind2++){
            
            if(S1[ind1-1] == S2[ind2-1])
                curr[ind2] = 1 + prev[ind2-1];
                
            else{
                curr[ind2] = 0;
            }
            
            ans = max(ans, curr[ind2]);
        }
        
        prev = curr;
    }
    
    return ans;
}