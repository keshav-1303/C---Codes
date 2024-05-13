#include<bits/stdc++.h>
using namespace std;

//https://www.codingninjas.com/studio/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// Memoization---
int solveMem(int n, int x, int y, int z, vector<int> &dp){

	if(n == 0){
		return 0;
	}

	if(n < 0){
		return INT_MIN;
	}

	if(dp[n] != -1)		return dp[n];

	int a = solveMem(n - x, x, y, z, dp) + 1;
	int b = solveMem(n - y, x, y, z, dp) + 1;
	int c = solveMem(n - z, x, y, z, dp) + 1;

	return dp[n] = max(a, max(b, c));
}

int cutSegments(int n, int x, int y, int z) {
	vector<int> dp(n+1, -1);
	int ans = solveMem(n, x, y, z, dp);
	return (ans > 0) ? ans : 0;
}

// Tabulation--- && Space Optimisation ---
int cutSegments(int n, int x, int y, int z) {

	vector<int> dp(n+1, INT_MIN);
	dp[0] = 0;

	for(int i=1 ; i<=n ; i++){
		int a = (i-x >= 0) ? dp[i-x] + 1 : INT_MIN;
		int b = (i-y >= 0) ? dp[i-y] + 1 : INT_MIN;
		int c = (i-z >= 0) ? dp[i-z] + 1 : INT_MIN;
		dp[i] = max(a, max(b, c));
	}

	return (dp[n] > 0) ? dp[n] : 0;
}
