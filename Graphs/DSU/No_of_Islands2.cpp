#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands

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

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
    Disjoint_Set ds(n*m);
    vector<vector<bool>> vis(n, vector<bool> (m, 0));
    
    int count = 0;
    
    vector<int> ans (operators.size());
    
    for(int i=0 ; i<operators.size() ; i++){
        int row = operators[i][0];
        int col = operators[i][1];
        
        int node = row*m + col;
        
        if(!vis[row][col]){
            vis[row][col] = 1;
            count++;
            
            // up
            if(row > 0 && vis[row-1][col]){
                int newNode = (row-1)*m + col;
                if(ds.findUpar(node) != ds.findUpar(newNode)){
                    // i.e they belong to different islands.
                    ds.UnionbyRank(node, newNode);
                    count--;
                }
            }
            // left
            if(col > 0 && vis[row][col-1]){
                int newNode = (row)*m + col-1;
                if(ds.findUpar(node) != ds.findUpar(newNode)){
                    // i.e they belong to different islands.
                    ds.UnionbyRank(node, newNode);
                    count--;
                }
            }
            // right
            if(col < m-1 && vis[row][col+1]){
                int newNode = (row)*m + col+1;
                if(ds.findUpar(node) != ds.findUpar(newNode)){
                    // i.e they belong to different islands.
                    ds.UnionbyRank(node, newNode);
                    count--;
                }
            }
            // down
            if(row < n-1 && vis[row+1][col]){
                int newNode = (row+1)*m + col;
                if(ds.findUpar(node) != ds.findUpar(newNode)){
                    // i.e they belong to different islands.
                    ds.UnionbyRank(node, newNode);
                    count--;
                }
            }
        }
        ans[i] = count;
    }
    return ans;
}