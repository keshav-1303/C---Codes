// Return LENGTH of shortest subarray with OR ATLEAST K
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/description/

int minimumSubarrayLength(vector<int>& arr, int k) {
    if(k == 0)   return 1;   // bec empty subarray is not allowed

    int OR = 0, n = arr.size();
    int i = 0, j = 0;

    vector<vector<int>> pref (n, vector<int> (32, 0));
    vector<int> sum(32, 0);
    for(int i=0 ; i<n ; i++){
        for(int K=0 ; K<32 ; K++){
            if(arr[i] & (1 << K))   sum[K]++;
        }
        pref[i] = sum;
    }

    int minlen = INT_MAX;
    while(j < n){
        OR = OR | arr[j];
        while(i < n && OR >= k){
            minlen = min(minlen, j-i+1);
            int temp = 0;   // stores OR value after removing arr[i]
            for(int K=0 ; K<32 ; K++){
                if(pref[j][K] - pref[i][K] > 0)   temp += (1 << K);
            }
            i++;
            OR = temp;
        }
        j++;
    }
    return (minlen == INT_MAX) ? -1 : minlen;
}