#include <bits/stdc++.h> 
using namespace std;

// Using 1d DP --------------------------------------------------

int maximumProfit(vector<int> &prices){
    
    int n = prices.size();
    vector<int> dp (n, 0);
    dp[0] = prices[0];
    dp[1] = prices[0];   // bec for i=1, min will be prices[0].

    for(int i=1 ; i<n ; i++){
        if(prices[i] >= dp[i-1]){ 
            dp[i] = dp[i-1];
        }
        else{
            dp[i] = prices[i];
        }
    }

    int maxProfit = 0;
    for(int i=1 ; i<n ; i++){
        int profit = prices[i] - dp[i];
        maxProfit = max( maxProfit, profit );
    }

    return maxProfit;
}

// Space Optimised -------------------------------------------------

int maximumProfit(vector<int> &prices){
    
    int n = prices.size();
    int mini = prices[0];

    int maxProfit = 0;
    for(int i=1 ; i<n ; i++){
        int profit = prices[i] - mini;
        maxProfit = max( maxProfit, profit );
        mini = min( mini, prices[i] );
    }

    return maxProfit;
}

// Done by myself -------------------------------------------------
int maxProfit(vector<int>& arr) {
    int n = arr.size();
    int curr = arr[n-1];
    int ans = 0;
    for(int i=n-2 ; i>=0 ; i--){
        curr = max(curr, arr[i]);
        ans = max(ans, curr - arr[i]);
    }
    return ans;
}
