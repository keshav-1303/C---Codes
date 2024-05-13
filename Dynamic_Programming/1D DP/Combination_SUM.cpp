#include <bits/stdc++.h>
using namespace std;

// Memoisation-------------------------------------------------------------
int solve(vector<int> num, int target, vector<int> &dp){

    if(target < 0){
        return 0;
    }

    if(target == 0){
        return 1;
        // because for returning nothing, there is 1 way
    }

    if(dp[target] != -1){
        return dp[target];
    }

    int ans = 0;

    for(int i=0 ; i<num.size() ; i++){
        ans += solve(num, target - num[i], dp);
    }

    return dp[target] = ans; 
}

int findWays(vector<int> &num, int target){

    vector<int> dp(target+1, -1);
    
    return solve(num, target, dp);
}

// Tabulation--------------------------------------------------------------------

int findWays(vector<int> &num, int target){

    vector<int> dp(target+1, 0);
    dp[0] = 1;
    int ans = 0;
    
    for(int ind=1 ; ind<=target ; ind++){

        for (int i = 0; i < num.size(); i++) {

            if(ind - num[i] >= 0)
                dp[ind] += dp[ind - num[i]];
        }
    }

    return dp[target];

}