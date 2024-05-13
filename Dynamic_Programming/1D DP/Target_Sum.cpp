#include <bits/stdc++.h> 

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
            
            int pick = (j >= arr[ind]) ? dp[ind-1][j - arr[ind]] : 0;
        	int notpick = dp[ind-1][j];
        	dp[ind][j] = (pick + notpick);
        }
    }
        
    return dp[n-1][target];
    
}

int targetSum(int n, int target, vector<int>& arr) {

    return countPartitions(n, target, arr);
}
