#include <bits/stdc++.h> 

//https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

int solve(vector<int> &nums, int ind, vector<int> &dp){ // Proper

    if(ind == 0){
        return nums[ind];
    }

    if(ind < 0){
        return 0;
    }

    if(dp[ind] != -1){
        return dp[ind];
    }

    int pick = solve(nums, ind-2, dp) + nums[ind];
    int notpick = solve(nums, ind-1, dp) + 0;

    return dp[ind] = max(pick, notpick);

}

int maximumNonAdjacentSum(vector<int> &nums){   // Tabulation
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];

    for(int ind=1 ; ind<n ; ind++){

        int pick = (ind > 1) ? dp[ind-2] + nums[ind] : nums[ind];
        int notpick = dp[ind-1] + 0;

        dp[ind] = max(pick, notpick);
    }

    return dp[n-1];
}

int maximumNonAdjacentSum(vector<int> &nums){   // Space Optimised
    int n = nums.size();

    int prev1 = nums[0];
    int prev2 = nums[0];

    for(int ind=1 ; ind<n ; ind++){

        int pick = (ind > 1) ? prev2 + nums[ind] : nums[ind];
        int notpick = prev1 + 0;

        int curr = max(pick, notpick);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}