#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/frequency-of-the-most-frequent-element/
int maxFrequency(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    int l = 0, r = 0, n = arr.size(), maxi = 0;
    long long sum = 0;
    while(r < n){
        sum += arr[r];
        while(1LL*arr[r]*(r-l+1) > k+sum){   
        // using opposite case so that window becomes valid again
            sum -= arr[l];
            l++;
        }
        maxi = max(maxi, r-l+1);
        r++;
    }
    return maxi;
}