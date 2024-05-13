#include <bits/stdc++.h>
using namespace std;

// You are given an n x n binary grid. 
// You can change at most one cell in grid from 0 to 1.
// You need to find the largest group of connected  1's.

// https://practice.geeksforgeeks.org/problems/maximum-connected-group/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-connected-group

class Disjoint_Set{

    vector<int> rank, parent;

    public:

    Disjoint_Set(int n){
        rank.resize(n+1, 0);
        int start = 0;
        parent.resize(n+1, 0);
        iota(parent.begin(), parent.end(), start);   // does parent[i] = i;
    }

    int findUpar(int node){
        if(node == parent[node])    return node;
        return parent[node] = findUpar(parent[node]);
    }

    void UnionbyRank(int u, int v){
        int ult_u = findUpar(u);
        int ult_v = findUpar(v);
        // if already same do nothing.
        if(ult_u == ult_v)    return ;
        if(rank[ult_u] < rank[ult_v]){
            // Smaller goes and gets attatched to the greater one.
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_u] > rank[ult_v]){
            // Smaller goes and gets attatched to the greater one.
            parent[ult_v] = ult_u;
        }
        else{
            // if they are same.
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};

void bfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& vis, Disjoint_Set &ds, vector<int> &howmany1s){
    
    int n = grid.size(), m = grid[0].size();
    
    vis[x][y] = 1;
    int node = x*m + y;    // node = row*m + col;
    queue<pair<int, int>> q;
    q.push({x, y});
    
    int count = 0;
    
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        int newNode = row*m + col;
        q.pop();
        count++;
        ds.UnionbyRank(node, newNode);
        
        //up
        if(row > 0 && !vis[row-1][col]){
            vis[row-1][col] = 1;
            q.push({row-1, col});
        }
        //down
        if(row < n-1 && !vis[row+1][col]){
            vis[row+1][col] = 1;
            q.push({row+1, col});
        }
        //left
        if(col > 0 && !vis[row][col-1]){
            vis[row][col-1] = 1;
            q.push({row, col-1});
        }
        //right
        if(col < m-1 && !vis[row][col+1]){
            vis[row][col+1] = 1;
            q.push({row, col+1});
        }
    }
    
    howmany1s[node] = count;
}

int MaxConnection(vector<vector<int>>& grid) {
    
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> vis (n, vector<bool> (m, 0));
    vector<int> howmany1s (n*m, 0);
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            vis[i][j] = 1 - grid[i][j];
        }
    }
    
    // Make COnnected Components as given in question...
    Disjoint_Set ds(n*m);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(!vis[i][j]){
                bfs(i, j, grid, vis, ds, howmany1s);
            }
        }
    }
    
    int ans = 0;
    
    // Now check for maximum possible answer...
    for(int row=0 ; row<n ; row++){
        for(int col=0 ; col<m ; col++){
            if(grid[row][col] == 0){
                
                int left=0, right=0, up=0, down=0;
                set<int> Upar;
                
                //up
                if(row > 0 && grid[row-1][col] == 1){
                    int newNode = (row-1)*m + col;
                    up = ds.findUpar(newNode);
                    Upar.insert(up);
                }
                //down
                if(row < n-1 && grid[row+1][col] == 1){
                    int newNode = (row+1)*m + col;
                    down = ds.findUpar(newNode);
                    Upar.insert(down);
                }
                //left
                if(col > 0 && grid[row][col-1] == 1){
                    int newNode = (row)*m + col-1;
                    left = ds.findUpar(newNode);
                    Upar.insert(left);
                }
                //right
                if(col < m-1 && grid[row][col+1] == 1){
                    int newNode = (row)*m + col+1;
                    right = ds.findUpar(newNode);
                    Upar.insert(right);
                }
                
                int temp = 0;
                
                for(auto i : Upar){
                    temp += howmany1s[i]; 
                } 
                
                ans = max(ans, temp+1);
            }
        }
    }
    
    if(ans == 0){
        // if no 0 present in array, return already max of present 0s.
        for(auto i : howmany1s){
            ans = max(ans, i);
        }
    }
    
    return ans;
    
}