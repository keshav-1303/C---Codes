#include<vector>
#define MOD 1000000007

// Memoization---
long long int solve(int n, vector<int> &dp){

    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }

    if(dp[n] != -1)     return dp[n];

    int ans = (n-1)*(solve(n-1, dp) + solve(n-2, dp)) % MOD;
    return dp[n] = ans;
}

long long int countDerangements(int n) {
    vector<int> dp(n+1, -1);
    return solve(n, dp);
}

// Tabulation---
long long int countDerangements(int n) {

    vector<long long int> dp(n+1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for(int i=3 ; i<=n ; i++){
        dp[i] = (i-1)*(dp[i-1] + dp[i-2]) % MOD;
    }
    return dp[n];
    
}

// Space Optimised---
