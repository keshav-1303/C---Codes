// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges
#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
        
    int n = grid.size(), m = grid[0].size();
    
    queue<pair<pair<int, int>, int>> q;
    // q stores <<row, col>, time for this> to rot.
    vector<vector<int>> v = grid;
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j] == 2){
                q.push({{i, j}, 0});
            }
        }
    }
    
    int ans = 0;
    
    while(!q.empty()){
        
        int x = q.front().first.first;
        int y = q.front().first.second;
        int temp = q.front().second;
        q.pop();
        
        // check in all directions if 1 found, make it 2.
        // up
        if(x > 0 && v[x-1][y] == 1){
            v[x-1][y] = 2;
            q.push({{x-1, y}, temp+1});
            ans = max(ans, temp+1);
        }
        // left
        if(y > 0 && v[x][y-1] == 1){
            v[x][y-1] = 2;
            q.push({{x, y-1}, temp+1});
            ans = max(ans, temp+1);
        }
        // down
        if(x < n-1 && v[x+1][y] == 1){
            v[x+1][y] = 2;
            q.push({{x+1, y}, temp+1});
            ans = max(ans, temp+1);
        }
        // right
        if(y < m-1 && v[x][y+1] == 1){
            v[x][y+1] = 2;
            q.push({{x, y+1}, temp+1});
            ans = max(ans, temp+1);
        }
    }
    
    for(auto i : v){
        for(auto j : i){
            if(j == 1){
                // if any orange is left to rot, ans will be -1.
                ans = -1;
                break;
            }
        }
    }
    
    return ans;
}