#include <bits/stdc++.h>
using namespace std;
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
// Use it for visualising GRAPH -->
// https://csacademy.com/app/graph_editor/

class graph{

    public:

    int vertex;
    unordered_map<int, set<int>> adj;

    void addEdge(int u, int v, bool direction){
        // direction == 0 --> UNDIRECTED GRAPH
        // direction == 1 --> DIRECTED GRAPH

        adj[u].insert(v);    // create edge from u to v

        if(direction == 0){    // undirected graph me dono side ka add krna padta h
            adj[v].insert(u);    // create edge from v to u
        }
        vertex++;
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

// s.c = O(n), t.c = O(n) + O(2*E)
void bfs(unordered_map<int, set<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node){

    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        
        int frontNode = q.front();
        q.pop();

        // store frontNodes in ans array
        ans.push_back(frontNode);

        // traverse all neighbours of frontNode
        for(auto i : adj[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(graph g){

    vector<int> ans;
    unordered_map<int, bool> visited;

    // traverse all components
    for(int i=0 ; i<g.vertex ; i++){
        if(!visited[i]){
            bfs(g.adj, visited, ans, i);
        }
    }

    return ans;
}

int main(){

    int n;    cout << "Enter number of nodes : ";     cin >> n;

    int m;    cout << "Enter number of edges : ";     cin >> m;

    graph g;
    g.vertex = n;

    for(int i=0 ; i<m ; i++){
        int u, v;     cin >> u >> v;
        g.addEdge(u, v, 0);    // 0 for undirected graph
        // g.addEdge(u, v, 1);    // 1 for directed graph
    }
 
    g.printAdjList();

    //For input -->
    // 9 10
    // 0 8
    // 1 6
    // 1 7
    // 1 8
    // 5 8
    // 6 0
    // 7 3
    // 7 4
    // 8 7
    // 2 5
    
    // Ajacency List -->
    // 5 -> 2 8
    // 7 -> 1 3 4 8
    // 0 -> 6 8
    // 8 -> 0 1 5 7
    // 1 -> 6 7 8
    // 6 -> 0 1

    // BFS -->
    // 0 6 8 1 5 7 2 3 4

    print(BFS(g));

    return 0;
}


