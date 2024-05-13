// Count Subarrays Where Max Element Appears at Least K Times
#include <bits/stdc++.h>
using namespace std;

long long countSubarrays(vector<int>& arr, int k) {
    long long ans = 0;
    int n = arr.size(), maxi = 0, cnt = 0;
    for(auto i : arr)   maxi = max(maxi, i);

    int i=0, j=0;
    if(arr[0] == maxi)   cnt++;
    while(j < n && i < n){
        while(j+1 < n && cnt < k){
            if(arr[j+1] == maxi)   cnt++;
            j++;
        }
        if(cnt < k)   break;
        // here cnt of amxi is exactly k
        ans += (n-j);
        if(arr[i] == maxi)   cnt--;
        i++;
    }
    return ans;
}