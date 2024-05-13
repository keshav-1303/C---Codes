#include <bits/stdc++.h>
using namespace std;

// https://www.naukri.com/code360/problems/minimum-number-of-platforms_799400?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

static bool cmp(pair<char, int> &a, pair<char, int> &b){
    if(a.second == b.second)    return a.first < b.first;
    return a.second < b.second;
}
    
int calculateMinPlatforms(int arr[], int dep[], int n){
	vector<pair<char, int>> a;
	for(int i=0 ; i<n ; i++){
	    a.push_back({'B', arr[i]});
	    a.push_back({'E', dep[i]});
	}
	sort(a.begin(), a.end(), cmp);
	int cnt = 0, maxcnt = 0;
	for(int i=0 ; i<n ; i++){
	    if(a[i].first == 'B')   cnt++;
	    else    cnt--;
	    maxcnt = max(maxcnt, cnt);
	}
	return maxcnt;
}