#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks
// https://practice.geeksforgeeks.org/problems/course-schedule/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=course-schedule

// Tasks 1 : Just return 1 OR 0.
bool isPossible(int N,int P, vector<pair<int, int>>& prerequisites) {
	    
    //make adjacency list
    vector<int> adj[N];
    for(auto i : prerequisites){
        adj[i.first].push_back(i.second);
    }
    
    int V = N;
    
    // Now check toposort
    vector<int> indegree(V, 0), ans;
    for(int i=0 ; i<V ; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    
    queue<int> q;
    for(int i=0 ; i<V ; i++){
        if(indegree[i] == 0)    q.push(i);
    }
    
    while(!q.empty()){
        
        int node = q.front();
        q.pop();
        ans.push_back(node);
        
        for(auto i : adj[node]){
            indegree[i]--;
            if(indegree[i] == 0)    q.push(i);
        }
    }
    
    if(ans.size() == V)   return 1;
    // if size == V, toposort is possible, thus no cycle present.
    return 0;
}

// Return the Ordering in which tasks have to be done.
vector<int> findOrder(int N, int P, vector<vector<int>> prerequisites) {
    //make adjacency list
    vector<int> adj[N];
    for(auto i : prerequisites){
        adj[i[1]].push_back(i[0]);
    }
    
    int V = N;
    
    // Now check toposort
    vector<int> indegree(V, 0), ans;
    for(int i=0 ; i<V ; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    
    queue<int> q;
    for(int i=0 ; i<V ; i++){
        if(indegree[i] == 0)    q.push(i);
    }
    
    while(!q.empty()){
        
        int node = q.front();
        q.pop();
        ans.push_back(node);
        
        for(auto i : adj[node]){
            indegree[i]--;
            if(indegree[i] == 0)    q.push(i);
        }
    }
    
    vector<int> v;
    
    if(ans.size() == V)   return ans;
    // if size == V, toposort is possible, thus no cycle present.
    return v;
}