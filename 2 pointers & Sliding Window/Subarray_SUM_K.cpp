#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/subarray-sum-equals-k/

int subarraySum(vector<int>& arr, int k) {
    int n = arr.size(), sum = 0, cnt = 0;
    map<int, int> prefSum;

    for(int i=0 ; i<n ; i++){
        sum += arr[i];
        if(sum == k)    cnt++;
        int req = sum - k;
        if(prefSum.find(req) != prefSum.end()){
            cnt += prefSum[req];
        }
        prefSum[sum]++;
    }
    return cnt;
}