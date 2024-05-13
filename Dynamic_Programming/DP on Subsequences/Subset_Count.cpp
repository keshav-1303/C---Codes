// https://www.codingninjas.com/studio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

#include <bits/stdc++.h> 
using namespace std;
#define MOD 1000000007

// Memoization--------------------------------------------------------------

int solve(vector<int> arr, int ind, int target, vector<vector<int>> &dp){

	if(target == 0){
		return 1;
	}

	if(target < 0){
		return 0;
	}

	if(ind == 0){
		if(target == arr[ind])	   return 1;
		// bec if you reach here target != 0, 
		// thus, if last element fulfills target, ans is "YES"
		else	return 0;
	}

	if(dp[ind][target] != -1){
		return dp[ind][target];
	}

	int pick = (target >= arr[ind]) ? solve(arr, ind-1, target - arr[ind], dp) % MOD : 0;
	int notpick = solve(arr, ind-1, target, dp) % MOD;

	return dp[ind][target] = (pick + notpick) % MOD;

}

int findWays(vector<int>& arr, int k){

	int n = arr.size();

	vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
	return solve(arr, n-1, k, dp);

}

// Tabulation -------------------------------------------------------------

int solve(vector<int> arr, int ind, int target, vector<vector<int>> &dp){

	int pick = (target >= arr[ind]) ? solve(arr, ind-1, target - arr[ind], dp) % MOD : 0;
	int notpick = solve(arr, ind-1, target, dp) % MOD;

	return dp[ind][target] = (pick + notpick) % MOD;

}

int findWays(vector<int>& arr, int k){

	int n = arr.size();

	vector<vector<int>> dp(n, vector<int> (k+1, 0));
	
	for(int j=0 ; j<=k ; j++){
		if(k == arr[0])		dp[0][j] = 1;
		else	dp[0][j] = 0;
	}

	for(int i=0 ; i<n ; i++){
		dp[i][0] = 1;
	}

	for(int ind=1 ; ind<n ; ind++){
		for(int target=0 ; target <= k ; target++){

			int pick = (target >= arr[ind]) ? dp[ind-1][target - arr[ind]] % MOD : 0;
			int notpick = dp[ind-1][target] % MOD;

			dp[ind][target] = (pick + notpick) % MOD;
		}
	}

	return dp[n-1][k];

}

// Space Optimised---------------------------------------------------------

int findWays(vector<int>& arr, int k){

	int n = arr.size();

	if(n == 1){
		if(arr[0] == k)	  return 1;
		else	return 0;
	}

	vector<int> prev(k+1, 0), curr(k+1, 0);
	
	if(arr[0] <= k)		prev[arr[0]] = 1;

	prev[0] = 1;

	for(int ind=1 ; ind<n ; ind++){
		for(int target=0 ; target <= k ; target++){

			int pick = (target >= arr[ind]) ? prev[target - arr[ind]] % MOD : 0;
			int notpick = prev[target] % MOD;

			curr[target] = (pick + notpick) % MOD;
		}

		prev = curr;
	}

	return curr[k] % MOD;

}
