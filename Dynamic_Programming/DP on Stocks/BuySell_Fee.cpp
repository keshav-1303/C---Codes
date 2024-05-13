#include <bits/stdc++.h> 
using namespace std;

// https://www.codingninjas.com/studio/problems/rahul-and-his-chocolates_3118974?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

int maximumProfit(vector<int> &prices, int n, int fee){
    
    // Base case ...
    int prev0 = 0;
    int prev1 = 0;
    // .............

    int curr0 = 0, curr1 = 0;
    for(int ind=n-1 ; ind>=0 ; ind--){
        for(int buy = 0; buy <= 1; buy++){

            int profit = 0;
            if(buy == 0){   // i.e we will buy
                int Buy = -prices[ind] + prev1;
                int DontBuy = 0 + prev0;
                profit = max(Buy, DontBuy);
            }
            else{   // we need to sell
                int DontSell = 0 + prev1;
                int Sell = prices[ind] + prev0 - fee;
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
