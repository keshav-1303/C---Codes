// https://practice.geeksforgeeks.org/problems/distinct-occurrences/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h> 
using namespace std;
int MOD = (int)(1e9 + 7);

// Tell the number of times str2 occurs as subsequence in str1.

// Memoization ---------------------------------------------------------------

int f(int i, int j, string s1, string s2, vector<vector<int>> &dp){
    
    // if all chars of s2 are matched, then 1 must be returned
    if(j < 0)    return 1;
    
    // if s1 is exhausted and s2 not, means we are not able to find s2 anymore;
    if(i < 0)    return 0;
    
    if(dp[i][j] != - 1){
        return dp[i][j];
    }
    
    if(s1[i] == s2[j]){
        return f(i-1, j-1, s1, s2, dp)    +    f(i-1, j, s1, s2, dp);
        // bec we've checked curr index        // bec it may be possible that another
                                               // occurence of s1[j] can be found
    }
    
    return dp[i][j] = f(i-1, j, s1, s2, dp);
    // if not matched, search continues for s2[j].
}

int subsequenceCount(string s1, string s2){
    
    int n = s1.size(), m = s2.size();
    
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    return f(n-1, m-1, s1, s2, dp);
}

// Tabulation ----------------------------------------------------------------
    
int subsequenceCount(string s1, string s2){
    
    int n = s1.size(), m = s2.size();
    
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    
    for(int i=0 ; i<n ; i++){
        dp[i][0] = 1;
    }
    
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] % MOD    +    dp[i-1][j] % MOD;
            // bec we've checked curr index        // bec it may be possible that another
                                                   // occurence of s1[j] can be found
            }
            
            else
                dp[i][j] = dp[i-1][j] % MOD;
        }
    }
    
    return dp[n][m] % MOD;
}

// Space Optimised ---------------------------------------------------------

int subsequenceCount(string s1, string s2){
        
    int n = s1.size(), m = s2.size();
    
    vector<int> prev(m+1, 0), curr(m+1, 0);
    
    prev[0] = curr[0] = 1;
    
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            
            if(s1[i-1] == s2[j-1]){
                curr[j] = prev[j-1] % MOD    +    prev[j] % MOD;
            // bec we've checked curr index        // bec it may be possible that another
                                                   // occurence of s1[j] can be found
            }
            
            else
                curr[j] = prev[j] % MOD;
        }
        
        prev = curr;
    }
    
    return prev[m] % MOD;
}

// Space Optimised using 1 array -------------------------------------------

int subsequenceCount(string s1, string s2){
        
    int n = s1.size(), m = s2.size();
    
    vector<int> curr(m+1, 0);
    
    curr[0] = 1;
    
    for(int i=1 ; i<=n ; i++){
        for(int j=m ; j>=1 ; j--){
            // traversing reverse bec we need those elements.
            
            if(s1[i-1] == s2[j-1]){
                curr[j] = curr[j-1] % MOD    +    curr[j] % MOD;
            // bec we've checked curr index        // bec it may be possible that another
                                                   // occurence of s1[j] can be found
            }
            
            else
                curr[j] = curr[j] % MOD;
        }
    }
    
    return curr[m] % MOD;
}
