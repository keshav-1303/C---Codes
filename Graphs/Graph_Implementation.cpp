#include <bits/stdc++.h>
using namespace std;

// Properties -- >
// 1. Total Degree of Graph = 2 * (Number of edges in Graph)

// Ways of representing -->
// M lines eg -
// here N=6 is vertices and M=3 are edges.
// 2 1
// 3 4 
// 5 6

// Adjacency Matrix --> adj[N+1][M+1]
// adj[i][j] represents is any edge is present between vertices i and j (1 OR 0)
// for weigthed graph, weight of edge will be used inseatd of 1 
// s.c = O(n*n)
// t.c = O(n*n)

// Adjacency List --> vector<int> adj(n+1)
// In each vertices, its neighbours are pushed in the list.
// for weigthed graph, weight of edge will also be stored along with neighbours. 
// s.c = O(2*E) ,where E -> number of edges.

class graph{
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction){
        // direction == 0 --> UNDIRECTED GRAPH
        // direction == 1 --> DIRECTED GRAPH
        adj[u].push_back(v);    // create edge from u to v
        if(direction == 0){    // undirected graph me dono side ka add krna padta h
            adj[v].push_back(u);    // create edge from v to u
        }
    }

    void printAdjList(){
        for(auto i : adj) {   
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    int n;    cout << "Enter number of nodes : ";     cin >> n;
    int m;    cout << "Enter number of edges : ";     cin >> m;

    graph g;
    for(int i=0 ; i<m ; i++){
        int u, v;     cin >> u >> v;
        g.addEdge(u, v, 0);    // 0 for undirected graph
    }
    g.printAdjList();
}

