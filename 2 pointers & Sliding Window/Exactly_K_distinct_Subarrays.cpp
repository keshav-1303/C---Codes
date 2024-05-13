// Count Subarrays with EXACTLY K Different Integers
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/subarrays-with-k-different-integers/description/?envType=daily-question&envId=2024-03-30

void del(map<int, int> &mp, int key){
    if(mp[key] == 1)    mp.erase(key);
    else    mp[key]--;
}

int atmostK(vector<int> &arr, int k){
    map<int, int> freq;
    int i = 0, j = 0, n = arr.size(), cnt = 0;
    while(j < n){
        freq[arr[j]]++;
        while(i <= j && freq.size() > k){
            // if more than k chararcters, remove previous ones
            del(freq, arr[i]);
            i++;
        }
        cnt += j-i+1;
        j++;
    }
    return cnt;
}

int subarraysWithKDistinct(vector<int>& arr, int k) {
    // exactly(K) = atmost(K) - atmost(K-1)
    return atmostK(arr, k) - atmostK(arr, k-1);
}