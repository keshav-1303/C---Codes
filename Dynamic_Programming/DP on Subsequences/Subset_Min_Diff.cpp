#include <bits/stdc++.h> 
using namespace std;

int minSubsetSumDifference(vector<int>& v, int n){

	int k = accumulate(v.begin(), v.end(), 0);
	
    vector<vector<int>> dp(n, vector<int> (k+1, 0));
    
    for(int j=0 ; j<=k ; j++){
        if(v[0] == k)   dp[0][j] = 1;
        else    dp[0][j] = 0;
    }

    for(int i=0 ; i<n ; i++){
        dp[i][0] = 1;
    }

    for(int ind=1 ; ind<n ; ind++){
        for(int sum=0 ; sum<=k ; sum++){

            bool notpick = dp[ind-1][sum];
            bool pick = (sum >= v[ind]) ? dp[ind-1][sum - v[ind]] : 0;

            dp[ind][sum] = max(pick, notpick);
        }
    }

    int mini = 1e9;

	for(int i=0 ; i<=k ; i++){
		if(dp[n-1][i] == true){	 // i.e. sum = i is possible

			int s1 = i;
			int s2 = k - i;

			mini = min(mini, abs(s1 - s2));
		}
	}

	return mini;
}
