#include <bits/stdc++.h> 
using namespace std;

// https://leetcode.com/problems/partition-array-for-maximum-sum/

// Memoization -----------------------------------------------------------

int f(int ind, int n, vector<int> &arr, int k, vector<int> &dp){

    if(ind == n)   return 0;

    if(dp[ind] != -1)   return dp[ind];
    else{
        int sum = 0, len = 0, maxAns = 0, maxi = 0;
        for(int j=ind ; j<min(ind + k, n) ; j++){
            len++;
            maxi = max(maxi, arr[j]);
            sum = len*maxi + f(j+1, n, arr, k, dp);
            maxAns = max(maxAns, sum);
        }

        return dp[ind] = maxAns;
    }
}

int maxSumAfterPartitioning(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> dp (n, -1);
    return f(0, n, arr, k, dp);
}

// Tabulation -----------------------------------------------------------

int maxSumAfterPartitioning(vector<int> &arr, int k){
    
    int n = arr.size();
    vector<int> dp (n+1, 0);

    for(int ind=n-1 ; ind>=0 ; ind--){

        int sum = 0, len = 0, maxAns = 0, maxi = 0;
        for(int j=ind ; j<min(ind + k, n) ; j++){
            len++;
            maxi = max(maxi, arr[j]);
            sum = len*maxi + dp[j+1];
            maxAns = max(maxAns, sum);
        }

        dp[ind] = maxAns;
    }

    return dp[0];
}