#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/largest-divisible-subset/submissions/

vector<int> largestDivisibleSubset(vector<int>& arr) {
    int n = arr.size();

    vector<int> dp(n, 1);
    vector<int> hash(n, 0);
    iota(hash.begin(), hash.end(), 0);   // hash[i] = i, for all i

    int maxi = 1, maxValInd = 0;
    sort(arr.begin(), arr.end());

    for(int ind = 0; ind < n; ind++){
        for(int prev = 0; prev < ind; prev++){
            if(arr[ind] % arr[prev] == 0 && dp[ind] < 1+dp[prev]){
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev;
            }
        }
        if(dp[ind] > maxi){
            maxi = dp[ind];
            maxValInd = ind;
        }
    }
    
    vector<int> LDS;
    LDS.push_back(arr[maxValInd]);
    while(hash[maxValInd] != maxValInd){
        maxValInd = hash[maxValInd];
        LDS.push_back(arr[maxValInd]);
    }
    
    return LDS;
}