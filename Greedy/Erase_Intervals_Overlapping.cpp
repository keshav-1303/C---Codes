#include <bits/stdc++.h>
using namespace std;

static bool cmp(const vector<int> &a, const vector<int> &b){
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& a) {
    sort(a.begin(), a.end(), cmp);   // We want that intervals khtm ho jitna jaldi ho sake
    int cnt = 0, end = a[0][1];
    for(int i=1 ; i<a.size() ; i++){
        if(a[i][0] < end){
            cnt++;
        }
        else    end = a[i][1];
    }
    return cnt;
}