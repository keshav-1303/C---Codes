// https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

// Memoization----------------------------------------------------------------

#include <bits/stdc++.h> 
using namespace std;

long solve(int ind, int *arr, int n, int target, vector<vector<long int>> &dp){

    if(target < 0){
        return 0;
    }

    if(target == 0){
        return 1;
    }

    if(ind == 0){
        if(target % arr[0] == 0)    return 1;
        return 0;
    }

    if(dp[ind][target] != -1){
        return dp[ind][target];
    }

    long int nottake = solve(ind-1, arr, n, target, dp);
    long int take = solve(ind, arr, n, target - arr[ind], dp);
    // not ind-1 bec we can take same value any number of times.

    return dp[ind][target] = take + nottake;
}

long countWaysToMakeChange(int *denominations, int n, int value){
    vector<vector<long int>> dp(n+1, vector<long int> (value+1, -1));
    return solve(n-1, denominations, n, value, dp);
}



