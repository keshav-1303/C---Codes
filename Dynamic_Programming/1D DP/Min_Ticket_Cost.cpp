// https://www.codingninjas.com/studio/problems/minimum-coins_2180776?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include<bits/stdc++.h>
using namespace std;

// Memoization------------------------------------------------------------------
int solve(int n, int ind, vector<int> days, vector<int> cost, vector<int> &dp){

    if(ind >= n){
        return 0;
    }

    if(dp[ind] != -1){
        return dp[ind];
    }

    // 1 day pass
    int day1 = solve(n, ind+1, days, cost, dp) + cost[0];

    // 7 day pass
    int i=ind;
    for( ; i<n && days[i] < days[ind] + 7 ; i++){
    }

    int day7 = solve(n, i, days, cost, dp) + cost[1];

    // 30 day pass
    i=ind;
    for( ; i<n && days[i] < days[ind] + 30 ; i++){
    }

    int day30 = solve(n, i, days, cost, dp) + cost[2];

    return dp[ind] = min(day30, min(day1, day7));
}

int minimumCoins(int n, vector<int> days, vector<int> cost){

    vector<int> dp(n+1, -1);

    return solve(n, 0, days, cost, dp);
}

// Tabulation-----------------------------------------------------------------
int minimumCoins(int n, vector<int> days, vector<int> cost){

    vector<int> dp(n+1, -1);
    dp[n] = 0;

    for(int ind=n-1 ; ind>=0 ; ind--){

        // 1 day pass
        int day1 = dp[ind+1] + cost[0];

        // 7 day pass
        int i=ind;
        for( ; i<n && days[i] < days[ind] + 7 ; i++){
        }

        int day7 = dp[i] + cost[1];

        // 30 day pass
        i=ind;
        for( ; i<n && days[i] < days[ind] + 30 ; i++){
        }

        int day30 = dp[i] + cost[2];

        dp[ind] = min(day30, min(day1, day7));

    }

    return dp[0];
}

// Space Optimised--------------------------------------------------------------- 

