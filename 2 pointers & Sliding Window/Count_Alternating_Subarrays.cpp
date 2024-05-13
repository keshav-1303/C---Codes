#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-alternating-subarrays/description/
// Break Problem into smaller subproblems -- >
// Subproblem = break array where arr[i] == arr[i+1], count left & right parts

long long countAlternatingSubarrays(vector<int>& arr){
    long long cnt = 0;
    int n = arr.size(), i = 0, j = 0;
    while(j < n){
        // Now we have same adjacent elements
        if(j+1 < n && arr[j] == arr[j+1]){
            int len = j-i+1;
            cnt += 1LL*len*(len+1)/2;
            i = j+1;
        }
        if(j == n-1){
            int len = j-i+1;
            cnt += 1LL*len*(len+1)/2;
        }
        j++;
    }
    return cnt;
}