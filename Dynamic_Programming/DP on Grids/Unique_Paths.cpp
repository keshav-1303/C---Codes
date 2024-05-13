// https://www.codingninjas.com/studio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>
using namespace std;

// Memoization-------------------------------------------------------------
int solve(int row, int col, int i, int j, vector<vector<int>> &dp){

	if(i == 0 && j == 0){	// Pahuch Gaye
		return 1;
	}

	if(i < 0 || j < 0 || i > row || j > col){
		return 0;
	}

	if(dp[i][j] != -1){
		return dp[i][j];
	}

	int up = (i > 0) ? solve(row, col, i-1, j, dp) : 0;
	int left = (j > 0) ? solve(row, col, i, j-1, dp) : 0;

	return dp[i][j] = up + left;
}

int uniquePaths(int m, int n) {
	
	vector<vector<int>> dp(m+1, vector<int> (n+1, -1));

	return solve(m, n, m-1, n-1, dp);
}

// Tabulation------------------------------------------------------------
int uniquePaths(int m, int n) {
	
	vector<vector<int>> dp(m, vector<int> (n, 0));

	dp[0][0] = 1;

	for(int i=0 ; i<m ; i++){
        for (int j = 0; j < n; j++){

			int up = (i > 0) ? dp[i - 1][j] : 0;
			int left = (j > 0) ? dp[i][j - 1] : 0;
			dp[i][j] += up + left;
        }
	}

	return dp[m-1][n-1];
}

// Space Optimised-------------------------------------------------------
int uniquePaths(int m, int n) {
	
	vector<int>prev(m, 0);

	for(int i=0 ; i<m ; i++){
		vector<int> curr(n, 0);
        for (int j = 0; j < n; j++){

			if(i == 0 && j == 0)	curr[j] = 1;

			int up = (i > 0) ? prev[j] : 0;
			int left = (j > 0) ? curr[j - 1] : 0;
			curr[j] += up + left;
        }

		prev = curr;
	}

	return prev[n-1];
}