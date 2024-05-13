// https://www.codingninjas.com/studio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>
using namespace std;

// Memoization-------------------------------------------------------------

#include <bits/stdc++.h> 

int solve(vector<vector<int>> triangle, int n, int m, int i, int j, vector<vector<int>>& dp){

	if(i == n-1){
		return triangle[i][j];
	}

	if(dp[i][j] != -1){
		return dp[i][j];
	}

	int down = solve(triangle, n, m, i+1, j, dp) + triangle[i][j];
	int diagonal = solve(triangle, n, m, i+1, j+1, dp) + triangle[i][j];

	return dp[i][j] = min(down, diagonal);

}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	
	int m = triangle[n-1].size();

	vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
	return solve(triangle, n, m, 0, 0, dp);
}

// Tabulation-------------------------------------------------------------

int minimumPathSum(vector<vector<int>>& triangle, int n){
	
	int m = triangle[n-1].size();

	vector<vector<int>> dp(n, vector<int> (m, 0));
	
	for(int j=0 ; j<m ; j++){
		dp[n-1][j] = triangle[n-1][j];
	}

	for(int i=n-2 ; i>=0 ; i--){
		for(int j=0 ; j<triangle[i].size() ; j++){

			int down = dp[i+1][j] + triangle[i][j];
			int diagonal = dp[i+1][j+1] + triangle[i][j];

			dp[i][j] = min(down, diagonal);
		}
	}

	return dp[0][0];
}

// Space Optimised---------------------------------------------------------

#include <bits/stdc++.h> 

int minimumPathSum(vector<vector<int>>& triangle, int n){
	
	int m = triangle[n-1].size();

	vector<int> prev(m, 0);
	
	for(int j=0 ; j<m ; j++){
		prev[j] = triangle[n-1][j];
	}

	for(int i=n-2 ; i>=0 ; i--){
		vector<int> curr(triangle[i].size(), 0);
		for(int j=0 ; j<triangle[i].size() ; j++){

			int down = prev[j] + triangle[i][j];
			int diagonal = prev[j+1] + triangle[i][j];

			curr[j] = min(down, diagonal);
		}

		prev = curr;
	}

	return prev[0];
}
