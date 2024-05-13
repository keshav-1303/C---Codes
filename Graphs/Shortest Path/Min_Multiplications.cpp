// https://www.naukri.com/code360/problems/minimum-operations_8360665?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;

// Min multiplications req to convert start -> end
int minimumOperations(int n, int start, int end, vector<int> &a){
    set<pair<int, int>> S;
    S.insert({0, start});

    int MOD = 1000;
    vector<int> dist(MOD, 1e9);
    dist[start] = 0;

    while(!S.empty()){
        auto it = *S.begin();
        int op = it.first;
        int num = it.second;
        S.erase(it);

        if(num == end)   return op;

        for(auto i : a){
            int temp = (i*num) % MOD;
            int newDist = op+1, oldDist = dist[temp];
            if(newDist < oldDist){
                S.insert({newDist, temp});
                dist[temp] = op+1;
            }
        }
    }
    return -1;
}