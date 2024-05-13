#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves

int numberOfEnclaves(vector<vector<int>> &mat) {
        
    int n = mat.size(), m = mat[0].size();
    
    vector<vector<bool>> vis (n, vector<bool> (m, 0));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(mat[i][j] == 0)    vis[i][j] = 1;
        }
    }
    
    vector<vector<int>> v = mat;
    
    // boundary traverse karo if 1 found, then all 1s connected to it will not be in ans.
    
    queue<pair<int, int>> q;
    
    // Traversing all 4 boundaries -------------------
    for(int j=0 ; j<m ; j++){
        if(v[0][j] == 1)    q.push({0, j});
    }
    for(int i=0 ; i<n ; i++){
        if(v[i][0] == 1)    q.push({i, 0});
    }
    for(int j=0 ; j<m ; j++){
        if(v[n-1][j] == 1)    q.push({n-1, j});
    }
    for(int i=0 ; i<n ; i++){
        if(v[i][m-1] == 1)    q.push({i, m-1});
    }
    //------------------------------------------------
    
    while(!q.empty()){
        
        int x = q.front().first, y = q.front().second;
        vis[x][y] = 1;
        q.pop();
        
        // up
        if(x > 0 && v[x-1][y] == 1 && !vis[x-1][y]){
            vis[x-1][y] = 1;
            q.push({x-1, y});
        }
        // left
        if(y > 0 && v[x][y-1] == 1 && !vis[x][y-1]){
            vis[x][y-1] = 1;
            q.push({x, y-1});
        }
        // down
        if(x < n-1 && v[x+1][y] == 1 && !vis[x+1][y]){
            vis[x+1][y] = 1;
            q.push({x+1, y});
        }
        // right
        if(y < m-1 && v[x][y+1] == 1 && !vis[x][y+1]){
            vis[x][y+1] = 1;
            q.push({x, y+1});
        }
    }

    // We marked all 1s connected to boundary 1s as visited.
    // And we already marked 0s as visited.
    // Thus, those indices which are not visited will be those 1s that 
    // we will not be able to go through boundary.
    
    int count = 0;
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(vis[i][j] == 0)   count++;
        }
    }
    
    return count;
}