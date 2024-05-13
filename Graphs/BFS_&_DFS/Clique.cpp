#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/791/problem/B

void bfs(int node, vector<int> adj[], vector<int> &vis, map< pair<int, int>, bool> &visE, int &countE, int &countV){

    vis[node] = 1;
    countV++;
    for(auto j : adj[node]){
        if(!visE[{min(node, j), max(node, j)}]){
            countE++;
            visE[{min(node, j), max(node, j)}] = 1;
        }
    }

    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        for(auto i : adj[frontNode]){
            if(!vis[i]){
                vis[i] = 1;
                countV++;
                q.push(i);
                for(auto j : adj[i]){
                    if(!visE[{min(i, j), max(i, j)}]){
                        countE++;
                        visE[{min(i, j), max(i, j)}] = 1;
                    }
                }
            }
        }
    }
}

void __________(int testcases){

    int V, E;    cin >> V >> E;
    vector<int> adj[V+1];

    for(int i=0 ; i<E ; i++){
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Just check for clique, i.e connected component must be a complete graph.

    vector<int> vis (V+1, 0);
    map< pair<int, int>, bool> visE;

    for(int i=1 ; i<=V ; i++){
        if(!vis[i]){
            int countV = 0, countE = 0;
            bfs(i, adj, vis, visE, countE, countV);

            if(countE == countV * (countV-1) / 2){
                // it is a complete graph
                continue;
            }
            else{
                cout << "NO" << endl;
                return ;
            }
        }
    } 

    cout << "YES" << endl;
    return ;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int _ = 1;     

    while(_--){
        __________(_);
    }

    return 0;
}
