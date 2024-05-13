// https://www.codingninjas.com/studio/problems/minimum-path-sum_985349?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

// Tabulation-------------------------------------------------------------

int minSumPath(vector<vector<int>> &grid) {
    
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int> (m, 0));

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){

          if(i == 0 && j == 0){
            dp[i][j] = grid[0][0];
          }

          else {

            int up = (i > 0) ? dp[i - 1][j] + grid[i][j] : INT_MAX;
            int left = (j > 0) ? dp[i][j - 1] + grid[i][j] : INT_MAX;

            dp[i][j] = min(up, left);
          }
        }
    }

    return dp[n-1][m-1];
}

// Space Optimised-----------------------------------------------------------------

int minSumPath(vector<vector<int>> &grid) {
    
    int n = grid.size();
    int m = grid[0].size();

    vector<int> prev(n, 0);

    for(int i=0 ; i<n ; i++){
      vector<int> curr(m, 0);
        for(int j=0 ; j<m ; j++){

          if(i == 0 && j == 0){
            curr[j] = grid[0][0];
          }

          else {

            int up = (i > 0) ? prev[j] + grid[i][j] : INT_MAX;
            int left = (j > 0) ? curr[j - 1] + grid[i][j] : INT_MAX;

            curr[j] = min(up, left);
          }
        }

        prev = curr;
    }

    return prev[m-1];
    
}
