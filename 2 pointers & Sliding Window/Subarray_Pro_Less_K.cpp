#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/subarray-product-less-than-k/description/?envType=daily-question&envId=2024-03-27

int numSubarrayProductLessThanK(vector<int>& arr, int k) {
    if(k <= 1)   return 0;
    int n = arr.size(), pro = 1, cnt = 0;
    int i = 0, j = 0;
    while(i < n && j < n){
        pro = pro * arr[j];
        while(pro >= k){
            pro = pro / arr[i];
            i++;
        }
        if(pro < k){
            cnt += j-i+1;
            // for counting new subarrays including (len+1)th element 
            // eg - 4 new subarrays will be counted if len becomes 4 from 3  
        }
        j++;
    }
    return cnt;
}