#include <bits/stdc++.h> 
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

// Memoization -----------------------------------------------------

int f(int ind, vector<int> &prices, vector<vector<int>> &dp, int buy){
    int n = prices.size();
    if(ind == n-1){
        if(buy == 0){
            // waste to buy now.
            return 0;
        }
        else{
            // compulsary to sell now.
            return prices[ind]; 
        }
    }

    if(dp[ind][buy] != -1)    return dp[ind][buy];
    else{
        int profit = 0;
        if(buy == 0){   // i.e we will buy
            int Buy = -prices[ind] + f(ind+1, prices, dp, 1);
            int DontBuy = 0 + f(ind+1, prices, dp, 0);
            profit = max(Buy, DontBuy);
        }
        else{   // we need to sell
            int DontSell = 0 + f(ind+1, prices, dp, 1);
            int Sell = prices[ind] + f(ind+1, prices, dp, 0);
            profit = max(Sell, DontSell);
        }
        return dp[ind][buy] = profit;
    }
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int> (2, -1));
    int buy = 0;    // buy == 0 --> we need to buy.
    return f(0, prices, dp, buy);
}

// Tabulation ------------------------------------------------------

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int> (2, 0));
    
    // Base case ...
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
                int Sell = prices[ind] + dp[ind+1][0];
                profit = max(Sell, DontSell);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][0];
}

// Space Optimised (by me) ---------------------------------------
// T.C = O(n), S.C = O(1);

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    
    // Base case ...
    int prev0 = 0;
    int prev1 = prices[n-1];
    // .............

    int curr0 = 0, curr1 = 0;
    for(int ind=n-2 ; ind>=0 ; ind--){
        for(int buy = 0; buy <= 1; buy++){

            int profit = 0;
            if(buy == 0){   // i.e we will buy
                int Buy = -prices[ind] + prev1;
                int DontBuy = 0 + prev0;
                profit = max(Buy, DontBuy);
            }
            else{   // we need to sell
                int DontSell = 0 + prev1;
                int Sell = prices[ind] + prev0;
                profit = max(Sell, DontSell);
            }

            if(buy == 0)    curr0 = profit;
            else    curr1 = profit;

            prev0 = curr0;
            prev1 = curr1;
        }
    }

    return curr0;
}