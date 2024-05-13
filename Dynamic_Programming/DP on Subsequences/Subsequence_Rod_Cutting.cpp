// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h> 
using namespace std;

// Memoization----------------------------------------------------------------

int solve(int ind, int N, int *price, vector<vector<int>> dp){
        
    if(N == 0){
        return 0;
    }
    
    if(ind == 0){
        return (N/1)*price[0];
        // bec rod length will be 1 here.
    }
    
    if(dp[ind][N] != -1){
        return dp[ind][N];
    }
    
    int rodlength = ind + 1;
    
    int take = (N >= rodlength) ? solve(ind, N-rodlength, price, dp) + price[ind] : 0;
    int nottake = solve(ind-1, N, price, dp) + 0;
    
    return dp[ind][N] = max(take, nottake); 
    
}

int cutRod(int price[], int n) {
    
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    return solve(n-1, n, price, dp);
}

// Tabulation ----------------------------------------------------------------

int cutRod(int price[], int n) {
    
    vector<vector<int>> dp(n, vector<int> (n+1, 0));
    
    for(int j=0 ; j<=n ; j++){
        dp[0][j] = j*price[0];
    }
    
    for(int ind=1 ; ind<n ; ind++){
        for(int N=0 ; N<=n ; N++){
            
            int rodlength = ind + 1;
    
            int take = (N >= rodlength) ? dp[ind][N-rodlength] + price[ind] : 0;
            int nottake = dp[ind-1][N] + 0;
            
            dp[ind][N] = max(take, nottake); 
        }
    }
    
    return dp[n-1][n];
}

// Space Optimised ---------------------------------------------------------

int cutRod(int price[], int n) {
        
    vector<int> prev(n+1), curr(n+1, 0);
    
    for(int j=0 ; j<=n ; j++){
        prev[j] = j*price[0];
    }
    
    for(int ind=1 ; ind<n ; ind++){
        for(int N=0 ; N<=n ; N++){
            
            int rodlength = ind + 1;
    
            int take = (N >= rodlength) ? curr[N-rodlength] + price[ind] : 0;
            int nottake = prev[N] + 0;
            
            curr[N] = max(take, nottake); 
        }
        
        prev = curr;
    }
    
    return prev[n];
}

// Space Optimised using only 1 array ----------------------------------------

int cutRod(int price[], int n) {
        
    vector<int> curr(n+1, 0);
    
    for(int j=0 ; j<=n ; j++){
        curr[j] = j*price[0];
    }
    
    for(int ind=1 ; ind<n ; ind++){
        for(int N=0 ; N<=n ; N++){
            
            int rodlength = ind + 1;
    
            int take = (N >= rodlength) ? curr[N-rodlength] + price[ind] : 0;
            int nottake = curr[N] + 0;
            
            curr[N] = max(take, nottake); 
        }
    }
    
    return curr[n];
}