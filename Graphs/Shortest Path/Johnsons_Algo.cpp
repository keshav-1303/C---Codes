#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
    vector<int> dist (V, 1e9);
    dist[S] = 0;
    
    // (N-1) iterations...
    for(int i=0 ; i<V-1 ; i++){
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            int weight = i[2];
            
            if(dist[u] != 1e9 && dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
            }
        }
    }
    return dist;
}


vector<int> dijkstra(vector<vector<int>> edges, int V, int E, int src){

    // according to 0-based indexing
    vector<pair<int, int>> adj[V];
    for(int i=0 ; i<E ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        adj[u].push_back({v, weight});
    }
        
    set<pair<int, int>> s;
    s.insert({0, src});
    
    // min dist from src to all vertices
    vector<int> dist(V, 1e9);
    dist[src] = 0;
    
    while(!s.empty()){
        auto it = *(s.begin());
        int node = it.second;
        int nodeDist = it.first;
        s.erase(it);
        
        for(auto i : adj[node]){
            int adjNode = i.first;
            int edgeWeight = i.second;
            int oldDist = dist[adjNode];
            int newDist = nodeDist + edgeWeight;
            
            if(newDist < oldDist){
                // erase if already existed.
                if(oldDist != 1e9){
                    s.erase({oldDist, adjNode});
                }
                dist[adjNode] = newDist;
                s.insert({newDist, adjNode});
            }
        }
    }
    return dist;
}

vector<vector<int>> Johnsons(vector<vector<int>> edges, int V){
    int tempNode = V, E = edges.size();
    for(int i=0 ; i<V ; i++){
        edges.push_back({V, i, 0});
    }

    vector<int> h = bellman_ford(V+1, edges, tempNode);
    h.pop_back();

    for(int i=0 ; i<V ; i++){
        edges.pop_back();
    }
    for(int i=0 ; i<edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        edges[i][2] += h[u] - h[v];
    }
    // -----------------

    vector<vector<int>> Dist;
    for(int u=0 ; u<V ; u++){
        vector<int> dist = dijkstra(edges, V, E, u);
        for(int v=0 ; v<V ; v++){
            if(dist[v] != 1e9)   dist[v] -= h[u] - h[v];
        }
        Dist.push_back(dist);
    }
    return Dist;
}

int main(){
    int V = 4;
    vector<vector<int>> edges;
    edges.push_back({0, 1, -5});
    edges.push_back({0, 3, 3});
    edges.push_back({0, 2, 2});
    edges.push_back({1, 2, 4});
    edges.push_back({2, 3, 1});

    vector<vector<int>> dist = Johnsons(edges, V);

    for (int i = 0; i < dist.size(); i++){
        for (int j = 0; j < dist[0].size(); j++){
            if(dist[i][j] == 1e9)   cout << "NO ";
            else    cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}