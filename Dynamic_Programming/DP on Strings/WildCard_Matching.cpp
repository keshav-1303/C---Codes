#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/wildcard-pattern-matching_701650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

// Memoization -----------------------------------------------------

bool f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){

   if(i < 0 && j < 0){
      return 1;
   }
   if(i < 0 && j >= 0){
      return 0;
   }
   if(j < 0 && i >= 0){
      for(int ind=0 ; ind<=i ; ind++){
         if(s1[ind] != '*')   return 0;
      }
      return 1;
   }

   if(dp[i][j] != -1)   return dp[i][j];

   else{
      if(s1[i] == s2[j] || s1[i] == '?'){
         return dp[i][j] = f(i-1, j-1, s1, s2, dp);
      }
      else{
         if(s1[i] == '*'){
            return dp[i][j] = (f(i-1, j, s1, s2, dp) || f(i, j-1, s1, s2, dp));
         }
         else
            return dp[i][j] = 0;
      }
   }
}

bool wildcardMatching(string s1, string s2){
   int n = s1.size(), m = s2.size();
   vector<vector<int>> dp (n, vector<int> (m, -1));
   return f(n-1, m-1, s1, s2, dp);
}

// Tabulation --------------------------------------------------------

bool wildcardMatching(string s1, string s2){

    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp (n+1, vector<int> (m+1, 0));

    // Base Case...
    dp[0][0] = 1;

    for(int i=1 ; i<=n ; i++){
        bool flag = 1;
        for(int ind=1 ; ind<=i ; ind++){
            if(s1[ind-1] != '*') {
                flag = 0;
                break;
            }
        }
        dp[i][0] = flag;
    }
    // ............

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){

            if(s1[i-1] == s2[j-1] || s1[i-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                if(s1[i-1] == '*'){
                    dp[i][j] = ( dp[i-1][j] || dp[i][j-1] );
                }
                else
                    dp[i][j] = 0;
            }
        }
    }
   
    return dp[n][m];
}
