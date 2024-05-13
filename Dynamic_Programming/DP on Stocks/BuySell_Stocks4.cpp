#include <bits/stdc++.h> 
using namespace std;

// https://www.codingninjas.com/studio/problems/best-time-to-buy-and-sell-stock_1080698?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

int maximumProfit(vector<int> &prices, int n, int k){
	
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