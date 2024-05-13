// https://practice.geeksforgeeks.org/problems/partitions-with-given-difference/1

#include <bits/stdc++.h>
using namespace std;

int MOD = (int)(1e9 + 7);

// Memoization ------------------------------------------------------------

int solve(vector<int> arr, int ind, int target, vector<vector<int>> &dp){

	if(target < 0){
		return 0;
	}

	if(ind == 0){

		if(target == 0 && arr[0] == 0)	  return 2;
		// bec 2 ways of getting sum = 0, take it or not take it.

		if(target == 0 || target == arr[ind])	   return 1;
		// bec if you reach here target != 0, 
		// thus, if last element fulfills target, ans is "YES"
		return 0;
	}

	if(dp[ind][target] != -1){
		return dp[ind][target] % MOD;
	}

	int pick = (target >= arr[ind]) ? solve(arr, ind-1, target - arr[ind], dp) % MOD : 0;
	int notpick = solve(arr, ind-1, target, dp) % MOD;

	return dp[ind][target] = (pick + notpick) % MOD;

}

// Tabulation ----------------------------------------------------------

int countPartitions(int n, int d, vector<int> &arr) {
    
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int target = (totalSum - d) / 2;

    if(totalSum < 0 || (totalSum - d) & 1 || totalSum < d){
        return 0;
    }
    vector<vector<int>> dp(n, vector<int> (target+1, 0));
    
    if(arr[0] == 0)    dp[0][0] = 2;
    else    dp[0][0] = 1;
    
    if(arr[0] != 0 && arr[0] <= target)    dp[0][arr[0]] = 1;
    
    for(int ind=1 ; ind<n ; ind++){
        for(int j=0 ; j<=target ; j++){
            
            int pick = (j >= arr[ind]) ? dp[ind-1][j - arr[ind]] % MOD : 0;
        	int notpick = dp[ind-1][j] % MOD;
        	dp[ind][j] = (pick + notpick) % MOD;
        }
    }
        
    return dp[n-1][target];
    
}
