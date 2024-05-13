// Length of Longest Subarray With at Most K Frequency
#include <bits/stdc++.h>
using namespace std;

int maxSubarrayLength(vector<int>& arr, int k) {
    int i=0 , j=0, maxlen = 0, n = arr.size();
    map<int, int> freq;
    while(j < n && i < n){
        freq[arr[j]]++;
        while(i < n && freq[arr[j]] > k){
            freq[arr[i]]--;
            i++;
        }
        maxlen = max(maxlen, j-i+1);
        j++;
    }
    return maxlen;
}