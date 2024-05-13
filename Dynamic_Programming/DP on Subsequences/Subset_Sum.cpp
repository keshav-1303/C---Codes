// https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std;

// Memoization--------------------------------------------------------------

bool solve(vector<int> v, int ind, int sum, vector<vector<int>> &dp){

    if(sum == 0){
        return 1;
    }

    if(sum < 0){
        return 0;
    }

    if(ind == 0){
        if(v[ind] == sum)   return 1;
        else    return 0;
    }

    if(dp[ind][sum] != -1){
        return dp[ind][sum];
    }

    bool notpick = solve(v, ind-1, sum, dp);
    bool pick = solve(v, ind-1, sum - v[ind], dp);

    return dp[ind][sum] = max(pick, notpick);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
    
    return solve(arr, n-1, k, dp);
}

// Tabulation------------------------------------------------------------

bool subsetSumToK(int n, int k, vector<int> &v) {

    if(accumulate(v.begin(), v.end(), 0) == k){
        return 1;
    }

    vector<vector<int>> dp(n, vector<int> (k+1, 0));
    
    for(int j=0 ; j<=k ; j++){
        if(v[0] == k)   dp[0][j] = 1;
        else    dp[0][j] = 0;
    }

    for(int i=0 ; i<n ; i++){
        dp[i][0] = 1;
    }

    for(int ind=1 ; ind<n ; ind++){
        for(int sum=0 ; sum<=k ; sum++){

            bool notpick = dp[ind-1][sum];
            bool pick = (sum >= v[ind]) ? dp[ind-1][sum - v[ind]] : 0;

            dp[ind][sum] = max(pick, notpick);
        }
    }

    return dp[n-1][k];
}

// Space Optimised-------------------------------------------------------

bool subsetSumToK(int n, int k, vector<int> &v) {

    if(accumulate(v.begin(), v.end(), 0) == k){
        return 1;
    }

    vector<bool> prev(k+1, 0), curr(k+1, 0);
    
    prev[v[0]] = 1;

    prev[0] = curr[0] = 1;

    for(int ind=1 ; ind<n ; ind++){
        for(int sum=0 ; sum<=k ; sum++){

            bool notpick = prev[sum];
            bool pick = (sum >= v[ind]) ? prev[sum - v[ind]] : 0;

            curr[sum] = max(pick, notpick);
        }

		prev = curr;
    }

    return prev[k];
}
