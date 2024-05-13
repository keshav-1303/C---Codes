#include <bits/stdc++.h> 
using namespace std;

// https://www.codingninjas.com/studio/problems/cost-to-cut-a-chocolate_3208460?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

// Memoization -----------------------------------------------------------

int f(vector<int> &cuts, int i, int j, vector<vector<int>> &dp){

    if(i > j)   return 0;

    if(dp[i][j] != -1)   return dp[i][j];
    else{
        int mini = 1e9;
        for (int ind = i; ind <= j; ind++) {
            int len = cuts[j + 1] - cuts[i - 1];
            int cost = len + f(cuts, i, ind - 1, dp) + f(cuts, ind + 1, j, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }
}

int cost(int n, int c, vector<int> &cuts){
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());    // MOST IMPORTANT
    vector<vector<int>> dp (n, vector<int> (n, -1));
    return f(cuts, 1, c, dp);
}

// Tabulation ------------------------------------------------------------

int cost(int n, int c, vector<int> &cuts){
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());    // MOST IMPORTANT
    vector<vector<int>> dp (c+2, vector<int> (c+2, 0));
    
    for(int i=c ; i>=1 ; i--){
        for(int j=1 ; j<=c ; j++){

            if(i > j)   continue;
            else{
                int mini = 1e9;
                for (int ind = i; ind <= j; ind++) {
                    int len = cuts[j + 1] - cuts[i - 1];
                    int cost = len + dp[i][ind - 1] + dp[ind + 1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
    }

    return dp[1][c];
}