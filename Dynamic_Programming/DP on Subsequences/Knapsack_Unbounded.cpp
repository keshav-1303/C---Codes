// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h>
using namespace std;

// Memoization --------------------------------------------------------------

int solve(int ind, int W, int *val, int *wt, vector<vector<int>> &dp){
    
    if(W == 0){
        return 0;
    }
    
    if(ind == 0){
        int div = W / wt[0];
        return div*val[0];
    }
    
    if(dp[ind][W] != -1){
        return dp[ind][W];
    }
    
    int take = (W >= wt[ind]) ? solve(ind, W - wt[ind], val, wt, dp) + val[ind] : 0;
    int nottake = solve(ind-1, W, val, wt, dp);
    
    return dp[ind][W] = max(take, nottake);
    
}

int knapSack(int N, int W, int val[], int wt[]){
    vector<vector<int>> dp(N+1, vector<int> (W+1, -1));
    return solve(N-1, W, val, wt, dp);
}

// Tabulation ----------------------------------------------------------------

int knapSack(int N, int W, int val[], int wt[]){
        
    vector<vector<int>> dp(N, vector<int> (W+1, 0));
    
    for(int j=0 ; j<=W ; j++){
        dp[0][j] = (j/wt[0]) * val[0];
    }
    
    for(int ind=1 ; ind<N ; ind++){
        for(int j=0 ; j<=W ; j++){
            
            int take = (j >= wt[ind]) ? dp[ind][j - wt[ind]] + val[ind] : 0;
            int nottake = dp[ind-1][j];
            
            dp[ind][j] = max(take, nottake);
        }
    }
    
    return dp[N-1][W];
}

// Space Optimised -----------------------------------------------------------

int knapSack(int N, int W, int val[], int wt[]){
    
    vector<int> prev(W+1, 0), curr(W+1, 0);
    
    for(int j=0 ; j<=W ; j++){
        prev[j] = (j/wt[0]) * val[0];
    }
    
    for(int ind=1 ; ind<N ; ind++){
        for(int j=0 ; j<=W ; j++){
            
            int take = (j >= wt[ind]) ? curr[j - wt[ind]] + val[ind] : 0;
            int nottake = prev[j];
            
            curr[j] = max(take, nottake);
        }
        
        prev = curr;
    }
    
    return prev[W];
}

// Space Optimised using only 1 array ---------------------------------------

int knapSack(int N, int W, int val[], int wt[]){
    
    vector<int> curr(W+1, 0);
    
    for(int j=0 ; j<=W ; j++){
        curr[j] = (j/wt[0]) * val[0];
    }
    
    for(int ind=1 ; ind<N ; ind++){
        for(int j=0 ; j<=W ; j++){
            
            int take = (j >= wt[ind]) ? curr[j - wt[ind]] + val[ind] : 0;
            int nottake = curr[j];
            
            curr[j] = max(take, nottake);
            // prev val is rewritten here, so 1 array is sufficient.
        }
    }
    
    return curr[W];
}

