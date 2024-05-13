#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1

//Memoization------------------------------------------------------------
int solve(int n, vector<int> &dp){
    
    if(n < 0){
        return INT_MAX;
    }
    
    if(n == 0){
        return 0;
    }
    
    if(dp[n] != -1){
        return dp[n];
    }
    
    int mini = n;
    
    for(int i=1 ; i<=sqrt(n) ; i++){
        int ans = solve(n - i*i, dp);
        mini = min(1+ans, mini);
    }
    
    return dp[n] = mini;
}

int MinSquares(int n){
    
    vector<int> dp(n+1, -1);
    
    return solve(n, dp);
}

// Tabulation--------------------------------------------------------------
int MinSquares(int n){
	    
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    
    for(int ind=0 ; ind<=n ; ind++){
        int mini = ind;
        for(int i=1 ; i<=sqrt(ind) ; i++){
	        int ans = dp[ind - i*i];
	        mini = min(1+ans, mini);
	    }
	    dp[ind] = mini;
    }
    
    return dp[n];
}