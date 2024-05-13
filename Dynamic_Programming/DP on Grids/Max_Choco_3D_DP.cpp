#include <bits/stdc++.h> 
using namespace std;

// Memoization --------------------------------------------------------------

int solve(vector<vector<int>> &grid, int n, int m, int i, int j1, int j2, vector<vector<vector<int>>> &dp){

    if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m){
        return -1e9;
    }

    if(i == n-1){
        if(j1 == j2){
            return grid[i][j1];
        }
        else{
            return grid[i][j1] + grid[i][j2];
        }
    }

    int value = 0;
    if(j1 == j2){
        value = grid[i][j1];
    }
    else{
        value = grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1){
        return dp[i][j1][j2];
    }

    int ans = INT_MIN;

    // All possible movements
    for(int ind1 = -1 ; ind1 <= 1 ; ind1++){
        for(int ind2 = -1 ; ind2 <= 1 ; ind2++){
            int temp = solve(grid, n, m, i+1, j1+ind1, j2+ind2, dp) + value;
            ans = max(ans, temp);
        }
    }

    return dp[i][j1][j2] = ans;
    
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r+1, vector<vector<int>> (c+1, vector<int> (c+1, -1)));
    return solve(grid, r, c, 0, 0, c-1, dp);
}

// Tabulation ----------------------------------------------------------------
