//https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1
#include <bits/stdc++.h>
using namespace std;

// We found nearest 0's to all 1's,
// So, for those 0's answer will be equivalent to what we found.

vector<vector<int>>nearest(vector<vector<int>>grid){
	    
    int n = grid.size(), m = grid[0].size();
    
    vector<vector<bool>> vis(n, vector<bool> (m, 0));
    vector<vector<int>> ans = grid;
    
    queue<pair<pair<int, int>, int>> q;
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j] == 1){
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }
    
    while(!q.empty()){
        
        int x = q.front().first.first;
        int y = q.front().first.second;
        int temp = q.front().second;
        q.pop();
        ans[x][y] = temp;
        vis[x][y] = 1;
        
        // check in all directions if 1 found, make it 2.
        // up
        if(x > 0 && vis[x-1][y] == 0){
            vis[x-1][y] = 1;
            q.push({{x-1, y}, temp+1});
        }
        // left
        if(y > 0 && vis[x][y-1] == 0){
            vis[x][y-1] = 1;
            q.push({{x, y-1}, temp+1});
        }
        // down
        if(x < n-1 && vis[x+1][y] == 0){
            vis[x+1][y] = 1;
            q.push({{x+1, y}, temp+1});
        }
        // right
        if(y < m-1 && vis[x][y+1] == 0){
            vis[x][y+1] = 1;
            q.push({{x, y+1}, temp+1});
        }
    }
    
    return ans;
}