#include <bits/stdc++.h> 
using namespace std;

// https://www.codingninjas.com/studio/problems/buy-and-sell-stock_1071012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

// Memoization -----------------------------------------------------

int f(int ind, vector<int> &prices, vector<vector<vector<int>>> &dp, int buy, int count){
    int n = prices.size();

    if(count == 0){
        return 0;
    }

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

    if(dp[ind][buy][count] != -1)    return dp[ind][buy][count];
    else{
        int profit = 0;
        if(buy == 0){   // i.e we will buy
            int Buy = -prices[ind] + f(ind+1, prices, dp, 1, count);
            int DontBuy = 0 + f(ind+1, prices, dp, 0, count);
            profit = max(Buy, DontBuy);
        }
        else{   // we need to sell
            int DontSell = 0 + f(ind+1, prices, dp, 1, count);
            int Sell = prices[ind] + f(ind+1, prices, dp, 0, count-1);
            profit = max(Sell, DontSell);
        }
        return dp[ind][buy][count] = profit;
    }
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
    int buy = 0;    // buy == 0 --> we need to buy.
    int count = 2;    // to store number of transactions.
    // we can do 0, 1 OR 2 transactions.
    return f(0, prices, dp, buy, count);
}

// Tabulation ------------------------------------------------------

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
    
    // Base case ...
    for(int count=0 ; count<3 ; count++){
        dp[n-1][0][count] = 0;
    }
    for(int count=0 ; count<3 ; count++){
        dp[n-1][1][count] = prices[n-1];
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<=1 ; j++){
            dp[i][j][0] = 0;
        }
    }
    // .............

    for(int ind=n-2 ; ind>=0 ; ind--){
        for(int buy = 0; buy <= 1; buy++){
            for(int count = 2; count > 0; count--){
                int profit = 0;
                if(buy == 0){   // i.e we will buy
                    int Buy = -prices[ind] + dp[ind+1][1][count];
                    int DontBuy = 0 + dp[ind+1][0][count];
                    profit = max(Buy, DontBuy);
                }
                else{   // we need to sell
                    int DontSell = 0 + dp[ind+1][1][count];
                    int Sell = prices[ind] + dp[ind+1][0][count-1];
                    profit = max(Sell, DontSell);
                }
                dp[ind][buy][count] = profit;
            }
        }
    }
    return dp[0][0][2];
}

// Space Optimised ---------------------------------------------
// T.C = O(n * 2 * 3), S.C = O(N + 2 + 3);

int maxProfit(vector<int>& prices) {
	int n = prices.size(), k = 2;
	
	vector<vector<int>> after(2, vector<int> (k+1, 0));
	vector<vector<int>> curr(2, vector<int> (k+1, 0));

	for (int ind = n-1; ind >= 0; ind--){
		for (int buy = 0; buy <= 1; buy++){
			for (int cap = k; cap > 0; cap--){

				int profit = 0;
				if (buy == 0)
					profit = max(-prices[ind] + after[1][cap], after[0][cap]);
				else
					profit = max(prices[ind] + after[0][cap-1], after[1][cap]);
				curr[buy][cap] = profit;
			}
		}
		after = curr;
	}

	return after[0][k];
}