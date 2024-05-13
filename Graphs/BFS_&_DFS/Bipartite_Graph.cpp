#include <bits/stdc++.h>
using namespace std;

//if you can colour a graph with 2 colours s.t no two adjacent nodes are of same colour.
// Observation : Any graph of EVEN cycle length is also BIPARTITE.
// and Any graph of ODD cycle length CANNOT BE BIPARTITE.

void bfs(int node, vector<int> adj[], vector<int> &colour){
        
    queue<pair<int, int>> q;    // <node, colour of node>
    colour[node] = 0;
    q.push({node, colour[node]});
    
    while(!q.empty()){
        
        int frontNode = q.front().first;
        int nodecolour = q.front().second;
        q.pop();
        
        for(auto i : adj[frontNode]){
            if(colour[i] == -1){
                colour[i] = 1 - nodecolour;   // for giving oppsite colour from parent node
                q.push({i, colour[i]});
            }
        }
    }
}

void dfs(int node, vector<int> adj[], vector<int> &colour, int prevcolour){
        
    colour[node] = 1 - prevcolour;
    prevcolour = colour[node];
    
    for(auto i : adj[node]){
        if(colour[i] == -1){
            dfs(i, adj, colour, prevcolour);
        }
    }
}

bool isBipartite(int V, vector<int> adj[]){
    
    // we will colour graph with colours 0 and 1
    vector<int> colour (V, -1);    // -1 means uncoloured
    
    // Using BFS we will colour each with 1 OR 0,
    // then check if any 2 adjacent are of same colour.

    int prevcolour = 1;
    
    for(int i=0 ; i<V ; i++){
        if(colour[i] == -1)    bfs(i, adj, colour);   // using BFS
        if(colour[i] == -1)    dfs(i, adj, colour, prevcolour);   // using DFS
    }
    // Now we got colour array, we will check if any adjacent are of same colour.

    for(int i=0 ; i<V ; i++){
        int nodecolour = colour[i];
        for(auto j : adj[i]){
            if(colour[j] == nodecolour)    return false;
        }
    }

    return true;
}