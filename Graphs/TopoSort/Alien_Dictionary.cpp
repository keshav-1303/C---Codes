#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary

vector<int> Topo_Sort(int V,vector<int> adj[]){
    
    vector<int> indegree (V, 0);
    for(int i=0 ; i<V ; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    
    queue<int> q;
    for(int i=0 ; i<V ; i++){
        if(indegree[i] == 0)   q.push(i);
    }
    
    vector<int> ans;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        
        // Now we will remove elements so thier adjacents' indegree will decrease.
        for(auto i : adj[node]){
            indegree[i]--;
            if(indegree[i] == 0)    q.push(i);
        }
    }
    
    return ans;
}

string findOrder(string dict[], int N, int K) {
    
    vector<int> adj[26];
    
    for(int i=0 ; i<N-1 ; i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        for(int j=0 ; j<min(s1.size(),s2.size()) ; j++){
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }
    
    vector<int> topo = Topo_Sort(K, adj);
    
    string ans = "";
    for(int i=0 ; i<K ; i++){
        ans += (char)(topo[i] + 'a');
    }
    
    return ans;
}