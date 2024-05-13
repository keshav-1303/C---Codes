#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze

int shortestPath(vector<vector<int>> &grid, pair<int, int> src, pair<int, int> dest) {
        
    int n = grid.size(), m = grid[0].size();
    
    vector<vector<int>> dist(n ,vector<int> (m, 1e9));
    dist[src.first][src.second] = 0;
    
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src.first, src.second}});
    
    while(!q.empty()){
        
        int x = q.front().second.first;
        int y = q.front().second.second;
        int nodeDist = q.front().first;
        q.pop();
        
        int newDist = nodeDist + 1;
        
        // up
        if(x > 0 && newDist < dist[x-1][y] && grid[x-1][y] == 1){
            q.push({newDist, {x-1, y}});
            dist[x-1][y] = newDist;
        }
        // down
        if(x < n-1 && newDist < dist[x+1][y] && grid[x+1][y] == 1){
            q.push({newDist, {x+1, y}});
            dist[x+1][y] = newDist;
        }
        // left
        if(y > 0 && newDist < dist[x][y-1] && grid[x][y-1] == 1){
            q.push({newDist, {x, y-1}});
            dist[x][y-1] = newDist;
        }
        // right
        if(y < m-1 && newDist < dist[x][y+1] && grid[x][y+1] == 1){
            q.push({newDist, {x, y+1}});
            dist[x][y+1] = newDist;
        }
    }
    
    int ans = dist[dest.first][dest.second];
    
    if(ans == 1e9)    return -1;
    return ans;
}