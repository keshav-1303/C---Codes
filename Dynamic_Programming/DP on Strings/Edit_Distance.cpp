// https://www.codingninjas.com/studio/problems/edit-distance_630420?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

#include <bits/stdc++.h> 
using namespace std;

// Given two strings s and t. Return the minimum number of operations required to convert s to t.
// The possible operations are permitted:
// Insert a character at any position of the string.
// Remove any character from the string.
// Replace any character from the string with any other character.

// Memoization ------------------------------------------------

int f(int i, int j, string &str1, string &str2, vector<vector<int>> &dp){

    if(i < 0)   return j+1;
    if(j < 0)   return i+1;

    if(dp[i][j] != -1)    return dp[i][j];

    else{
        if(str1[i] == str2[j]){
            return 0 + f(i-1, j-1, str1, str2, dp);
        }

        int ins = 1 + f(i, j-1, str1, str2, dp);
        int dlt = 1 + f(i-1, j, str1, str2, dp);
        int rplc = 1 + f(i-1, j-1, str1, str2, dp);

        return dp[i][j] = min(ins , min(dlt, rplc));
    }
}

int editDistance(string str1, string str2){
    int n = str1.size(), m = str2.size();    
    vector<vector<int>> dp (n, vector<int> (m, -1));
    return f(n-1, m-1, str1, str2, dp);
}

// Tabulation --------------------------------------------------

int editDistance(string str1, string str2){
    int n = str1.size(), m = str2.size();    
    vector<vector<int>> dp (n+1, vector<int> (m+1, 0));
    
    for(int j=0 ; j<=m ; j++){
        dp[0][j] = j;
    }
    for(int i=0 ; i<=n ; i++){
        dp[i][0] = i;
    }

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){

            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 0 + dp[i-1][j-1];
            }
            else{
                int ins = 1 + dp[i][j-1];
                int dlt = 1 + dp[i-1][j];
                int rplc = 1 + dp[i-1][j-1];

                dp[i][j] = min(ins , min(dlt, rplc)); 
            }           
        }
    }

    return dp[n][m];
}

// Space Optimised --------------------------------------------

int editDistance(string str1, string str2){
    int n = str1.size(), m = str2.size();    
    vector<int> prev (m+1, 0), curr (m+1, 0);

    for(int j=0 ; j<=m ; j++){
        prev[j] = j;
    }

    for(int i=1 ; i<=n ; i++){
        curr[0] = i;    // base case
        for(int j=1 ; j<=m ; j++){

            if(str1[i-1] == str2[j-1]){
                curr[j] = 0 + prev[j-1];
            }
            else{
                int ins = 1 + curr[j-1];
                int dlt = 1 + prev[j];
                int rplc = 1 + prev[j-1];

                curr[j] = min(ins , min(dlt, rplc)); 
            }           
        }
        prev = curr;
    }

    return prev[m];
}


