#include <bits/stdc++.h> 
using namespace std;

// https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_975344?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

// Memoization ------------------------------------------------------

int f(vector<int> &arr, int i, int j, vector<vector<int>> &dp){

    if(i == j)   return 0;

    if(dp[i][j] != -1)    return dp[i][j];
    
    int mini = 1e9;
    for(int k=i ; k<=j-1 ; k++){
        int steps = arr[i-1]*arr[k]*arr[j] + f(arr, i, k, dp) + f(arr, k+1, j, dp);
        mini = min(mini, steps);
    }

    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N){
    vector<vector<int>> dp (N, vector<int> (N, -1));
    return f(arr, 1, N-1, dp);    
}

// Tabulation -------------------------------------------------------

int matrixMultiplication(vector<int> &arr, int N){
    vector<vector<int>> dp (N, vector<int> (N, 0));
    
    for(int i=N-1 ; i>=1 ; i--){
        for(int j=i+1 ; j<N ; j++){

            int mini = 1e9;
            for(int k=i ; k<j ; k++){
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;            
        }
    }

    return dp[1][N-1];
}
