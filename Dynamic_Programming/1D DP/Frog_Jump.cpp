// https://www.codingninjas.com/studio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

#include <bits/stdc++.h> 

// Memoisation------------------------------------------------------------------------
int solve(int curr, vector<int> &heights, vector<int> &dp){

    if(curr == 0){
        return 0;
    }

    if(dp[curr] != -1){
        return dp[curr];
    }

    int left = solve(curr - 1, heights, dp) + abs(heights[curr] - heights[curr - 1]);

    int right = left + 1;

    if(curr > 1){
        right = solve(curr - 2, heights, dp) + abs(heights[curr] - heights[curr - 2]);
    }

    return dp[curr] = min(left, right);
}

int frogJump(int n, vector<int> &heights){
    vector<int> dp(n+1, -1);  //0 and 1
    return solve(n-1, heights, dp);
}

// Tabulation-----------------------------------------------------------------
int frogJump(int n, vector<int> &heights){
    vector<int> dp(n, 0); 
    dp[0] = 0;

    for(int curr=1 ; curr<n ; curr++){

        int left = dp[curr - 1] + abs(heights[curr] - heights[curr - 1]);
        int right = left + 1;
        if(curr > 1){
            right = dp[curr - 2] + abs(heights[curr] - heights[curr - 2]);
        }
        dp[curr] = min(left, right);
    }

    return dp[n-1];
}

// Space Optimised-----------------------------------------------------------

int frogJump(int n, vector<int> &heights){
    int prev1 = 0, prev2 = 0;

    for(int curr=1 ; curr<n ; curr++){

        int left = prev1 + abs(heights[curr] - heights[curr - 1]);
        int right = left + 1;
        if(curr > 1){
            right = prev2 + abs(heights[curr] - heights[curr - 2]);
        }
        int curri = min(left, right);
        prev2 = prev1;
        prev1 = curri;
    }

    return prev1;
}