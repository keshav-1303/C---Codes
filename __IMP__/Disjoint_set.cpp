#include <bits/stdc++.h>
using namespace std;

class Disjoint_Set{

    public:
    vector<int> rank, parent, size;

    Disjoint_Set(int n){
        rank.resize(n+1, 0);
        int start = 0;
        parent.resize(n+1, 0);
        size.resize(n+1, 0);
        iota(parent.begin(), parent.end(), start);   // does parent[i] = i;
        iota(size.begin(), size.end(), start);   // does size[i] = i;
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

    void UnionBySize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main(){

    Disjoint_Set ds(7);
    ds.UnionbyRank(1, 2);
    ds.UnionbyRank(2, 3);
    ds.UnionbyRank(4, 5);
    ds.UnionbyRank(6, 7);
    ds.UnionbyRank(5, 6);

    // Lets check if 3 and 7 belong to same connected component.
    if(ds.findUpar(3) == ds.findUpar(7)){
        cout << "3 and 7 belong to same connected component" << endl;
    }
    else{
        cout << "Not Same component" << endl;
    }

    ds.UnionbyRank(3, 7);
    // Lets check if NOW 3 and 7 belong to same connected component.
    if(ds.findUpar(3) == ds.findUpar(7)){
        cout << "3 and 7 belong to same connected component" << endl;
    }
    else{
        cout << "Not Same component" << endl;
    }

}