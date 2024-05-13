#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-increasing-subsequence/description/

// Memoization ------------------------------------------------------------

int f(vector<int> &arr, int n, int ind, int prevInd, vector<vector<int>>& dp) {
    // Base Case
    if (ind == n)
        return 0;
        
    if (dp[ind][prevInd+1] != -1)
        return dp[ind][prevInd+1];
    
    int notTake = 0 + f(arr, n, ind+1, prevInd+1, dp);
    
    int take = 0;
    
    if (prevInd == -1 || arr[ind] > arr[prevInd]) {
        take = 1 + f(arr, n, ind+1, ind+1, dp);
    }
    
    return dp[ind][prevInd+1] = max(notTake, take);
}

int lengthOfLIS(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return f(arr, n, 0, -1, dp);
}

// Tabulation --------------------------------------------------------------

int lengthOfLIS(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int ind = n-1; ind >= 0; ind--){
        for(int prevInd = ind-1; prevInd >= -1; prevInd--){

            int notTake = 0 + dp[ind+1][prevInd+1];
    
            int take = 0;
            if (prevInd == -1 || arr[ind] > arr[prevInd]) {
                take = 1 + dp[ind+1][ind+1];
            }
            
            dp[ind][prevInd+1] = max(notTake, take);
        }
    }
    return dp[0][-1 + 1];
}

// Space Optimised -------------------------------------------------------
// T.C = O(N * N), S.C = O(N * 2);

int lengthOfLIS(vector<int> &arr) {
    int n = arr.size();
    vector<int> curr(n+1, 0), next(n+1, 0);

    for(int ind = n-1; ind >= 0; ind--){
        for(int prevInd = ind-1; prevInd >= -1; prevInd--){

            int notTake = 0 + next[prevInd+1];
    
            int take = 0;
            if (prevInd == -1 || arr[ind] > arr[prevInd]) {
                take = 1 + next[ind+1];
            }
            
            curr[prevInd+1] = max(notTake, take);
        }
        next = curr;
    }

    return next[-1 + 1];
}

// MOST OPTIMISED --------------------------------------------------------
// T.C = O(N * N), S.C = O(N); 

int lengthOfLIS(vector<int> &arr) {
    int n = arr.size();

    vector<int> dp(n, 1);
    int maxi = 1;

    for(int ind = 0; ind < n; ind++){
        for(int prev = 0; prev < ind; prev++){
            if(arr[prev] < arr[ind]){
                dp[ind] = max(dp[ind], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[ind]);
    }

    return maxi;
}