#include <bits/stdc++.h> 
using namespace std;

// T.C = O(2^(m+n))

void solve(int i, int j, string s1, string s2, vector<vector<int>> &dp, vector<string> &ans, string t){
    if(i==0 || j==0){
        ans.push_back(t);
        return ;
    }
    
    if(s1[i-1] == s2[j-1]){
        solve(i-1, j-1, s1, s2, dp, ans, t+s1[i-1]);
    }
    else if(dp[i-1][j] > dp[i][j-1]){
        solve(i-1, j, s1, s2, dp, ans, t);
    }
    else if(dp[i][j-1] > dp[i-1][j]){
        solve(i, j-1, s1, s2, dp, ans, t);
    }
    else{
        solve(i-1, j, s1, s2, dp, ans, t);
        solve(i, j-1, s1, s2, dp, ans, t);
    }
}

vector<string> all_longest_common_subsequences(string s1, string s2){
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            }
        }
    }
    
    // Now get all strings from dp[][].
    vector<string> ans;
    solve(n, m, s1, s2, dp, ans, "");
    
    for(auto &i : ans){
        reverse(i.begin(), i.end());
    }
    sort(ans.begin(), ans.end());
    vector<string>::iterator ip = std::unique(ans.begin(), ans.end());
    ans.resize(std::distance(ans.begin(), ip));
    return ans;
}