#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/ninja%E2%80%99s-training_3621003?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

// Memoization -------------------------------------
int f(int i, vector<vector<int>> arr, int prev, vector<vector<int>> &dp){
    if(i == 0){
        return max(arr[0][(prev+1)%3], arr[0][(prev+2)%3]);
    }

    if(dp[i][prev] != -1)   return dp[i][prev];

    int op1 = (prev+1)%3, op2 = (prev+2)%3;
    int pick1 = f(i-1, arr, op1, dp) + arr[i][op1];
    int pick2 = f(i-1, arr, op2, dp) + arr[i][op2];

    return dp[i][prev] = max(pick1, pick2);
}

// Tabulation --------------------------------------
int solve(vector<vector<int>> &arr, int first_act){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (3, -1));

    // Base Case
    dp[0][0] = max(arr[0][1], arr[0][2]);
    dp[0][1] = max(arr[0][0], arr[0][2]);
    dp[0][2] = max(arr[0][1], arr[0][0]);

    for(int i=1 ; i<n ; i++){
        for(int prev=0 ; prev<=2 ; prev++){
            int op1 = (prev+1)%3, op2 = (prev+2)%3;
            int pick1 = dp[i-1][op1] + arr[i][op1];
            int pick2 = dp[i-1][op2] + arr[i][op2];
            dp[i][prev] = max(pick1, pick2);
        }
    }
    return dp[n-1][first_act];
}

int ninjaTraining(int n, vector<vector<int>> &arr){
    // activities are 0, 1 and 2
    int ans = 0;
    for(int i=0 ; i<=2 ; i++){
        ans = max(ans, solve(arr, i));
    }
    return ans;
}

// Space Optimised ---------------------------------
int solve(vector<vector<int>> &arr, int first_act){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (3, -1));

    vector<int> prev_Arr(3, -1), curr(3, -1);

    // Base Case
    prev_Arr[0] = max(arr[0][1], arr[0][2]);
    prev_Arr[1] = max(arr[0][0], arr[0][2]);
    prev_Arr[2] = max(arr[0][1], arr[0][0]);

    for(int i=1 ; i<n ; i++){
        for(int prev=0 ; prev<=2 ; prev++){
            int op1 = (prev+1)%3, op2 = (prev+2)%3;
            int pick1 = prev_Arr[op1] + arr[i][op1];
            int pick2 = prev_Arr[op2] + arr[i][op2];
            curr[prev] = max(pick1, pick2);
        }
        prev_Arr = curr;
    }
    return prev_Arr[first_act];
}

int ninjaTraining(int n, vector<vector<int>> &arr){
    // activities are 0, 1 and 2
    int ans = 0;
    for(int prev=0 ; prev<=2 ; prev++){
        ans = max(ans, solve(arr, prev));
    }
    return ans;
}