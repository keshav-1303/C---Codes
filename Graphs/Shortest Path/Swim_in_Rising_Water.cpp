#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/swim-in-rising-water/description/
int swimInWater(vector<vector<int>>& arr) {
    int n = arr.size();
    set<pair<int, pair<int, int>>> S;    // <time, <x, y>>
    S.insert({arr[0][0], {0, 0}});
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    vector<vector<int>> time(n, vector<int> (n, 1e9));
    time[0][0] = arr[0][0];

    while(!S.empty()){
        auto it = *S.begin();
        int t = it.first;
        int x = it.second.first;
        int y = it.second.second;
        S.erase(it);

        for(int i=0 ; i<4 ; i++){
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X >= 0 && X < n && Y < n && Y >= 0){
                int newT = max(t, max(arr[X][Y], arr[x][y]));
                if(newT < time[X][Y]){
                    time[X][Y] = newT;
                    S.insert({newT, {X, Y}});
                }
            }
        }
    }
    return time[n-1][n-1];
}