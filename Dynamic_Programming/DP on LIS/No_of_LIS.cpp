#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/number-of-longest-increasing-subsequence_3751627?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

int findNumberOfLIS(vector<int> &arr){
    
    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> count(n, 1);

    int maxi = 1;

    for(int ind = 0; ind < n; ind++){
        for(int prev = 0; prev < ind; prev++){
            if(arr[prev] < arr[ind] && 1+dp[prev] > dp[ind]){
                dp[ind] = 1 + dp[prev];
                count[ind] = count[prev];
            }
            else if(arr[prev] < arr[ind] && dp[ind] == 1+dp[prev]){
                count[ind] += count[prev];
            }
            maxi = max(maxi, dp[ind]);
        }
    }
    
    int cnt = 0;
    for(int i=0 ; i<n ; i++){
        if(dp[i] == maxi)   cnt += count[i];
    }

    return cnt;
}