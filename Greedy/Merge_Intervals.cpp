#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/merge-intervals/
vector<vector<int>> merge(vector<vector<int>>& arr) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int n = arr.size();
    for(int i=0 ; i<n ; i++){
        int start = arr[i][0];
        int end = arr[i][1];
        while(i+1 < n && end >= arr[i+1][0]){
            i++;
            end = max(end, arr[i][1]);
        }
        end = max(end, arr[i][1]);
        ans.push_back({start, end});
    }
    return ans;
}