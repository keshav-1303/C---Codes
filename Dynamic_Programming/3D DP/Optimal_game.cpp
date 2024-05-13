#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1

// Memoization
long long f(int arr[], bool chance, int s, int e, vector<vector<vector<long long>>> dp){
    if(s == e){
        return (chance) ? arr[s] : 0;
    }
    
    if(dp[s][e][chance] != -1)   return dp[s][e][chance];
    
    long long maxi = 0;
    if(chance){
        int op1 = f(arr, 1-chance, s+1, e, dp) + arr[s];
        int op2 = f(arr, 1-chance, s, e-1, dp) + arr[e];
        maxi = max(op1, op2);
    }
    else{
        int op1 = f(arr, 1-chance, s+1, e, dp);
        int op2 = f(arr, 1-chance, s, e-1, dp);
        maxi = min(op1, op2);
    }
    return dp[s][e][chance] = maxi;
}

long long maximumAmount(int n, int arr[]){
    bool chance = 1;    // means my turn
    vector<vector<vector<long long>>> dp (n, vector<vector<long long>> (n, vector<long long> (2, -1)));
    return f(arr, 1, 0, n-1, dp);
}

// Tabulation
long long maximumAmount(int n, int arr[]){
    bool chance = 1;    // means my turn
    vector<vector<vector<long long>>> dp (n, vector<vector<long long>> (n, vector<long long> (2, 0)));
    // Base case
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            for(int k=0 ; k<=1 ; k++){
                if(i == j)   dp[i][j][k] = arr[i];
            }
        }
    }

    for(int s=n-1 ; s>=0 ; s--){
        for(int e=0 ; e<n ; e++){
            for(int chance=0 ; chance<=1 ; chance++){
                long long maxi = 0;
                if(chance){
                    int op1 = dp[s+1][e][1-chance] + arr[s];
                    int op2 = dp[s][e-1][1-chance] + arr[e];
                    maxi = max(op1, op2);
                }
                else{
                    int op1 = dp[s+1][e][1-chance];
                    int op2 = dp[s][e-1][1-chance];
                    maxi = min(op1, op2);
                }
                dp[s][e][chance] = maxi;
            }
        }
    }
    return dp[0][n-1][1];
}
