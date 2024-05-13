#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-increasing-subsequence/description/
    
int lengthOfLIS(vector<int> &arr) {
    int n = arr.size();

    vector<int> dp(n, 1);
    vector<int> hash(n, 0);

    iota(hash.begin(), hash.end(), 0);   // hash[i] = i, for all i
    int maxi = 1, maxValInd = 0;

    for(int ind = 0; ind < n; ind++){
        for(int prev = 0; prev < ind; prev++){
            if(arr[prev] < arr[ind] && dp[ind] < 1+dp[prev]){
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev;
            }
        }
        if(dp[ind] > maxi){
            maxi = dp[ind];
            maxValInd = ind;
        }
    }

    vector<int> LIS;
    LIS.push_back(arr[maxValInd]);
    while(hash[maxValInd] != maxValInd){
        maxValInd = hash[maxValInd];
        LIS.push_back(arr[maxValInd]);
    }

    cout << "Longest Increasing Subsequence is ..." << endl;
    reverse(LIS.begin(), LIS.end());
    for(auto i : LIS){
        cout << i << " ";
    }
    cout << endl;
    
    return maxi;
}