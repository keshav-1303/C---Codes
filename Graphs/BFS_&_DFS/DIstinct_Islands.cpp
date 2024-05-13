#include <bits/stdc++.h>
using namespace std;

// Given a boolean 2D matrix grid of size n * m. 
// You have to find the number of distinct islands where a group of connected 1s 
// (horizontally or vertically) forms an island. Two islands are considered to 
// be distinct if and only if one island is not equal to another (not rotated or reflected).

// https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands

// Now, how to know that islands are distinct?

vector<pair<int, int>> bfs(int i, int j, vector<vector<int>> grid, vector<vector<bool>> &vis){
        
    int n = grid.size(), m = grid[0].size();
    vis[i][j] = 1;
    // i & j will be baserow and basecolumn, used for telling distinct.
    vector<pair<int, int>> set;
    int baserow = i;
    int basecol = j;
    set.push_back({i-baserow, j-basecol});
    
    queue<pair<int, int>> q;
    q.push({i, j});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // up
        if(x > 0 && vis[x-1][y] == 0){
            vis[x-1][y] = 1;
            set.push_back({x-1-baserow, y-basecol});
            q.push({x-1, y});
        }
        // left
        if(y > 0 && vis[x][y-1] == 0){
            vis[x][y-1] = 1;
            set.push_back({x-baserow, y-1-basecol});
            q.push({x, y-1});
        }
        // down
        if(x < n-1 && vis[x+1][y] == 0){
            vis[x+1][y] = 1;
            set.push_back({x+1-baserow, y-basecol});
            q.push({x+1, y});
        }
        // right
        if(y < m-1 && vis[x][y+1] == 0){
            vis[x][y+1] = 1;
            set.push_back({x-baserow, y+1-basecol});
            q.push({x, y+1});
        }
    }
    return set;
}

int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> vis (n, vector<bool> (m, 0));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j] == 0)   vis[i][j] = 1;
        }
    }
    set<vector<pair<int, int>> > checkDist;
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(!vis[i][j]){
                checkDist.insert(bfs(i, j, grid, vis));
            }
        }
    }
    return checkDist.size();
}