#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/account-merge/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=account-merge

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

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        
    int n = accounts.size();
    Disjoint_Set ds(n);
    
    unordered_map<string, int> Map;
    for(int i=0 ; i<n ; i++){
        for(int j=1 ; j<accounts[i].size() ; j++){
            string str = accounts[i][j];
            if(Map.find(str) == Map.end()){
                Map[str] = i;
            }
            else{
                ds.UnionbyRank(i, Map[str]);
            }
        }
    }
    
    for(int i=0 ; i<n ; i++){
        int parent = ds.findUpar(i);
        for(int j=1 ; j<accounts[i].size() ; j++){
            string str = accounts[i][j];
            Map[str] = parent;
        }
    }

    map<int, vector<string>> mp;
    for(auto i : Map){
        mp[i.second].push_back(i.first);
    }

    vector<vector<string>> ans;
    for(auto i : mp){
        vector<string> temp;
        temp.push_back(accounts[i.first][0]);
        for(auto it : i.second){
            temp.push_back(it);
        }
        sort(temp.begin(), temp.end());
        ans.push_back(temp);
    }
    
    return ans;
}