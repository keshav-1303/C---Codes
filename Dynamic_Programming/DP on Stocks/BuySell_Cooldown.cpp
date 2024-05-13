#include <bits/stdc++.h> 
using namespace std;

// https://www.codingninjas.com/studio/problems/highway-billboards_3125969?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

// Tabulation ------------------------------------
int stockProfit(vector<int> &prices){

    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int> (2, 0));
    
    // Base case ...
    dp[n][0] = dp[n][1] = 0;
    dp[n-1][0] = 0;
    dp[n-1][1] = prices[n-1];
    // .............

    for(int ind=n-2 ; ind>=0 ; ind--){
        for(int buy = 0; buy <= 1; buy++){
            int profit = 0;
            if(buy == 0){   // i.e we will buy
                int Buy = -prices[ind] + dp[ind+1][1];
                int DontBuy = 0 + dp[ind+1][0];
                profit = max(Buy, DontBuy);
            }
            else{   // we need to sell
                int DontSell = 0 + dp[ind+1][1];
                int Sell = prices[ind] + dp[ind+2][0];
                profit = max(Sell, DontSell);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][0];
}

// Space Optimised -------------------------------
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> prev(2, 0), prev2(2, 0), curr(2, 0);
    
    // Base case ...
    prev2[0] = prev2[1] = 0;
    prev[0] = 0;
    prev[1] = prices[n-1];
    // .............

    for(int ind=n-2 ; ind>=0 ; ind--){
        for(int buy = 0; buy <= 1; buy++){
            int profit = 0;
            if(buy == 0){   // i.e we will buy
                int Buy = -prices[ind] + prev[1];
                int DontBuy = 0 + prev[0];
                profit = max(Buy, DontBuy);
            }
            else{   // we need to sell
                int DontSell = 0 + prev[1];
                int Sell = prices[ind] + prev2[0];
                profit = max(Sell, DontSell);
            }
            curr[buy] = profit;
        }
        prev2 = prev;
        prev = curr;
    }
    return prev[0];
}