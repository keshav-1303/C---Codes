#include <bits/stdc++.h> 
#define MOD 1000000007

int solve(int ind, vector<int> &dp){

    if(ind == 0){
        return 1;
    }

    if(ind == -1){
        return 0;
    }

    if(dp[ind] != -1)   return dp[ind] % MOD;

    return dp[ind] = (solve(ind-1, dp) + solve(ind-2, dp)) % MOD;

}

int countDistinctWays(int nStairs) {
    
    // vector<int> dp(nStairs+1, 0);
    int prev1 = 1;
    int prev2 = 1;

    for(int i=2 ; i<=nStairs ; i++){
        int curr = (prev1 + prev2) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}