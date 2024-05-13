#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& newInterval) {
    a.push_back(newInterval);
    sort(a.begin(), a.end());
    
    vector<vector<int>> ans;
    for(int i=0 ; i<a.size() ; i++){
        int start = a[i][0];
        int end = a[i][1];
        while(i+1 < a.size() && a[i+1][0] <= end){
            end = max(end, a[i+1][1]);
            i++;
        }
        ans.push_back({start, end});
    }
    return ans;
}