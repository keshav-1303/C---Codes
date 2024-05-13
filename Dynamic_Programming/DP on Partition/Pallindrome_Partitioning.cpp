#include <bits/stdc++.h> 
using namespace std;

// https://www.codingninjas.com/studio/problems/palindrome-partitioning_873266?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

// Memoization -----------------------------------------------------------

bool check(string &str, int i, int j){
    while(i < j){
        if(str[i] != str[j])    return 0;
        i++;
        j--;
    }
    return 1;
}

int f(int i, int n, string &str, vector<int> &dp){

    if(i == n)  return 0; 

    if(dp[i] != -1)    return dp[i];
    else{
        int mini = 1e9;
        for(int ind=i ; ind<n ; ind++){
            if (check(str, i, ind) == 1) {
                int cost = 1 + f(ind + 1, n, str, dp);
                mini = min(mini, cost);
            }
        }

        return dp[i] = mini;
    }
}

int palindromePartitioning(string str){
    int n = str.size();
    vector<int> dp(n, -1);
    int ans = f(0, n, str, dp) - 1;   // -1 bec it takes an empty partition at last.
    return ans;
}

// Tabulation -----------------------------------------------------------

bool check(string &str, int i, int j){
    while(i < j){
        if(str[i] != str[j])    return 0;
        i++;
        j--;
    }
    return 1;
}

int palindromePartitioning(string str){
    int n = str.size();
    vector<int> dp(n+1, 0);

    for(int i=n-1 ; i>=0 ; i--){

        int mini = 1e9;
        for(int ind=i ; ind<n ; ind++){
            if (check(str, i, ind) == 1) {
                int cost = 1 + dp[ind + 1];
                mini = min(mini, cost);
            }
        }
        dp[i] = mini;
    }

    return dp[0] - 1;    // -1 bec it takes an empty partition at last.
}