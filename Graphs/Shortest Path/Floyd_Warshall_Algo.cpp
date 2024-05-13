#include <bits/stdc++.h>
using namespace std;

// Shortest path from each to each node
// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-floyd-warshall
// T.C = O(N*N*N), 

void shortest_distance(vector<vector<int>> &matrix){
    
    int n = matrix.size();
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 1e9;
            }
            if(i == j){
                matrix[i][j]=0;
            }
        }
    }
    
    for(int k=0 ; k<n ; k++){
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                matrix[i][j] = min(matrix[i][j], (matrix[i][k] + matrix[k][j]));
            }
        }
    }
    
    // TO DETECT NEGATIVE CYCLES...
    // for(int i=0 ; i<n ; i++){
    //     for(int j=0 ; i<n ; j++){
    //         if(matrix[i][j] < 0){
    //             cout << "Negative cycle" << endl;
    //         }
    //     }
    // }
   
   for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(matrix[i][j] == 1e9){
                matrix[i][j] = -1;
            }
        }
    }
}