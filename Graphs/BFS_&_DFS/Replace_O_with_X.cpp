#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        
    vector<vector<bool>> vis (n, vector<bool> (m, 0));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(mat[i][j] == 'X')    vis[i][j] = 1;
        }
    }
    
    vector<vector<char>> v = mat;
    
    // boundary traverse karo if 'O' found, then all Os connected to it will stay as it is.
    
    queue<pair<int, int>> q;
    
    // Traversing all 4 boundaries -------------------
    for(int j=0 ; j<m ; j++){
        if(v[0][j] == 'O')    q.push({0, j});
    }
    for(int i=0 ; i<n ; i++){
        if(v[i][0] == 'O')    q.push({i, 0});
    }
    for(int j=0 ; j<m ; j++){
        if(v[n-1][j] == 'O')    q.push({n-1, j});
    }
    for(int i=0 ; i<n ; i++){
        if(v[i][m-1] == 'O')    q.push({i, m-1});
    }
    //------------------------------------------------
    
    while(!q.empty()){
        
        int x = q.front().first, y = q.front().second;
        vis[x][y] = 1;
        q.pop();
        
        // up
        if(x > 0 && v[x-1][y] == 'O' && !vis[x-1][y]){
            vis[x-1][y] = 1;
            q.push({x-1, y});
        }
        // left
        if(y > 0 && v[x][y-1] == 'O' && !vis[x][y-1]){
            vis[x][y-1] = 1;
            q.push({x, y-1});
        }
        // down
        if(x < n-1 && v[x+1][y] == 'O' && !vis[x+1][y]){
            vis[x+1][y] = 1;
            q.push({x+1, y});
        }
        // right
        if(y < m-1 && v[x][y+1] == 'O' && !vis[x][y+1]){
            vis[x][y+1] = 1;
            q.push({x, y+1});
        }
    }

    // We marked all Os connected to boundary Os as visited.
    // And we already marked Xs as visited.
    // Thus, those indices which are not visited will be those Os that 
    // will be replaced by Xs.
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(vis[i][j] == 0)   v[i][j] = 'X';
        }
    }
    
    return v;
}