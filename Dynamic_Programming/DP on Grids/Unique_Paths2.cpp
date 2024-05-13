// https://www.codingninjas.com/studio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>
using namespace std;

// Memoization-------------------------------------------------------------

#define MOD 1000000007

int solve(int n, int m, int i, int j, vector<vector<int>> mat, vector<vector<int>> &dp){

    if(i == 0 && j == 0){
        return 1;
    }

    if(mat[i][j] == -1){
        return 0;
    }

    if(i < 0 || j < 0){
        return 0;
    }

    if(dp[i][j] != -1)   return dp[i][j];

    int up = (i > 0) ? solve(n, m, i-1, j, mat, dp) : 0;
    int left = (j > 0) ? solve(n, m, i, j-1, mat, dp) : 0;

    return dp[i][j] = (up + left) % MOD;

}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    return solve(n, m, n-1, m-1, mat, dp);
}

// Space Optimised-----------------------------------------------------------

int mazeObstacles(int m, int n, vector<vector< int>> &mat) {
    
    vector<int> prev(m, 0);

	for(int i=0 ; i<m ; i++){
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++){

            if(mat[i][j] == -1)   curr[j] = 0;

            else if(i == 0 && j == 0)   curr[j] = 1;

            else {

              int up = (i > 0) ? prev[j] : 0;
              int left = (j > 0) ? curr[j - 1] : 0;
              curr[j] += (up + left) % MOD;
            }
        }

        prev = curr;
	}

	return prev[n-1];
}