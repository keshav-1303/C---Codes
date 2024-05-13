#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/longest-bitonic-sequence_1062688?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

vector<int> solve(vector<int>& arr, int n){
    vector<int> dp(n, 1);

    for(int ind = 0; ind < n; ind++){
        for(int prev = 0; prev < ind; prev++){
            if(arr[prev] < arr[ind] && 1+dp[prev] > dp[ind]){
                dp[ind] = 1 + dp[prev];
            }
        }
    }
    return dp;
}

int longestBitonicSubsequence(vector<int>& arr, int n){

    vector<int> dp1 = solve(arr, n);
    
    reverse(arr.begin(), arr.end());
    vector<int> dp2 = solve(arr, n);
    reverse(dp2.begin(), dp2.end());

    int maxBitonic = 0;
    for(int i=0 ; i<n ; i++){
        maxBitonic = max( maxBitonic, dp1[i]+dp2[i]-1 );
    }
    
    return maxBitonic;
}