// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/submissions/

#include<bits/stdc++.h>
using namespace std;

// Memoization ----------------------------------------------------------------

int solve(vector<int> values, int i, int j, vector<vector<int>> &dp){

    if(i + 1 == j){
        // Base case : 2 hi vertices h so no triangle
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int mini = INT_MAX;

    for(int k=i+1 ; k<=j-1 ; k++){
        int ans = values[i]*values[j]*values[k] + solve(values, i, k, dp) + solve(values, k, j, dp);
        mini = min(mini, ans);
    }

    return dp[i][j] = mini;
}

int minScoreTriangulation(vector<int>& values) {

    int n = values.size();
    
    vector<vector<int>> dp(n, vector<int> (n, -1));
    return solve(values, 0, n-1, dp);
}

// Tabulation ---------------------------------------------------------------

int minScoreTriangulation(vector<int>& values) {

    int n = values.size();
    
    vector<vector<int>> dp(n, vector<int> (n, 0));
    
    for(int i=n-1 ; i>=0 ; i--){
        for(int j=i+2 ; j<n ; j++){

            int mini = INT_MAX;

            for(int k=i+1 ; k<=j-1 ; k++){
                int ans = values[i]*values[j]*values[k] + dp[i][k] + dp[k][j];
                mini = min(mini, ans);
            }
            dp[i][j] = mini;
        }
    }
        
    return dp[0][n-1];
}