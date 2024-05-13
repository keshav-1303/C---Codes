#include <bits/stdc++.h> 
using namespace std;

int solveMem(vector<int> &num, int sum, vector<int> &dp){

    if(sum == 0) return 0;
    
    if(sum < 0) return INT_MAX;

    if(dp[sum] != -1){
        return dp[sum];
    }
    else{

        int ans = INT_MAX;

        for(int i = 0; i < num.size(); i++) {
            int temp = solveMem(num, sum - num[i], dp);
            if (temp != INT_MAX) {
            ans = min(ans, temp + 1);
            }
        }

        return dp[sum] = ans;
    }
}

// Memoization---
int minimumElements(vector<int> &num, int x){
    
    int n = num.size();
    vector<int> dp(x+1, -1);
    int ans = solveMem(num, x, dp);

    return (ans == INT_MAX) ? -1 : ans;

}

// Tabulation--- & Space Optimisation---
int minimumElements(vector<int> &num, int x){
    
    vector<int> dp(x+1, INT_MAX);  
    dp[0] = 0; 
    //dp[i] represents min number of coins needed to make target i;

    for(int i=1 ; i<=x ; i++){
        for (int j = 0; j < num.size(); j++) {
            if(i-num[j] >= 0 && dp[i - num[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
        }
    }

    return (dp[x] == INT_MAX) ? -1 : dp[x];

}