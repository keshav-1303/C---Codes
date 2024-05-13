#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// Sort by END TIME

static bool cmp(pair<int, int> &a, pair<int, int> &b){
    if(a.second == b.second)    return a.first < b.first;
    return a.second < b.second;
}
    
int maxMeetings(int start[], int end[], int n){
    vector<pair<int, int>> a;
    for(int i=0 ; i<n ; i++){
        a.push_back({start[i], end[i]});
    }
    sort(a.begin(), a.end(), cmp);
    int cnt = 1, e = a[0].second;
    for(int i=1 ; i<n ; i++){
        if(a[i].first > e){
            cnt++;
            e = a[i].second;
        }
    }
    return cnt;
}