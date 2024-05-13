// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) 
// consisting of '0's (Water) and '1's(Land). Find the number of islands.
// Note: An island is either surrounded by water or boundary of grid and is formed 
// by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void bfs(int i, int j, vector<vector<int>> grid, vector<vector<bool>> &vis){
        
        int n = grid.size(), m = grid[0].size();
        vis[i][j] = 1;
        
        queue<pair<int, int>> q;
        q.push({i, j});
        
        while(!q.empty()){

            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            // up
            if(x > 0 && vis[x-1][y] == 0){
                vis[x-1][y] = 1;
                q.push({x-1, y});
            }
            // left
            if(y > 0 && vis[x][y-1] == 0){
                vis[x][y-1] = 1;
                q.push({x, y-1});
            }
            // down
            if(x < n-1 && vis[x+1][y] == 0){
                vis[x+1][y] = 1;
                q.push({x+1, y});
            }
            // right
            if(y < m-1 && vis[x][y+1] == 0){
                vis[x][y+1] = 1;
                q.push({x, y+1});
            }
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        int count=0;

        vector<vector<bool>> vis (n, vector<bool> (m, 0));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 0)   vis[i][j] = 1;
            }
        }
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    count++;
                    bfs(i, j, grid, vis);
                }
            }
        }

        return count;
    }
};

int main() {

    freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    cout << obj.countDistinctIslands(grid) << endl;
}