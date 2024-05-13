#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-multiplications-to-reach-end
// T.C = O(1e5).

int minimumMultiplications(vector<int>& arr, int start, int end) {
        
    int MOD = 100000;
    
    vector<int> dist (1e5, 1e9);   // to store steps for each node.
    // nodes will be [0, 1, 2, 3, 4 ............ 99999].
    dist[start] = 0;
    
    queue<pair<int, int>> q;
    // {steps, node}.
    q.push({0, start});
    
    while(!q.empty()){
        
        int node = q.front().second;
        int steps = q.front().first;
        q.pop();
        
        if(node == end)    return steps;
        
        int nextSteps = steps + 1;
        
        for(auto i : arr){
            
            int nextNode = (node * i) % MOD;
            
            if(nextSteps < dist[nextNode]){
                // matlab update karo..
                q.push({nextSteps, nextNode});
                dist[nextNode] = nextSteps;
            }
        }
    }
    
    return -1;
}