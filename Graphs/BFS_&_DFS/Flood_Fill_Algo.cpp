#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &v, int x, int y, int newcolor, int oldcolor){
    
    v[x][y] = newcolor;
    int n = v.size(), m = v[0].size();
    
    //right
    if(x < n-1 && v[x+1][y] == oldcolor){
        dfs(v, x+1, y, newcolor, oldcolor);
    }
    
    //left
    if(x > 0 && v[x-1][y] == oldcolor){
        dfs(v, x-1, y, newcolor, oldcolor);
    }
    
    //up
    if(y < m-1 && v[x][y+1] == oldcolor){
        dfs(v, x, y+1, newcolor, oldcolor);
    }
    //down
    if(y > 0 && v[x][y-1] == oldcolor){
        dfs(v, x, y-1, newcolor, oldcolor);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    
    vector<vector<int>> v = image;
    int oldcolor = image[sr][sc];
    dfs(v, sr, sc, newColor, oldcolor);
    
    return v;
}