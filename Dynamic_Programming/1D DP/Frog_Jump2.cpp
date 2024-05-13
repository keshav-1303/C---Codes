// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;

// Memoization ----------------------------------------------------------

int solve(vector<int> v, int k, int ind, vector<int> &dp){

    if(ind == 0){
        return 0;
    }

    if(dp[ind] != -1)   return dp[ind];

    int mini = INT_MAX;

    for(int i=1 ; i <= k ; i++){

        int ans = (ind - i >= 0) ? solve(v, k, ind - i, dp) + abs(v[ind - i] - v[ind]) : INT_MAX;
        mini = min(mini, ans);

    }

    return dp[ind] = mini;
}

// Tabulation & Space Optimised -------------------------------------------------

void ___(){

    int n, k;    cin >> n >> k;
    vector<int> v;    
    // inputVector(v, n);   Take vector input.

    vector<int> dp(n, 0);

    for(int ind=1 ; ind<n ; ind++){

        int mini = INT_MAX;

        for(int i=1 ; i <= k ; i++){

            int ans = (ind - i >= 0) ? dp[ind - i] + abs(v[ind - i] - v[ind]) : INT_MAX;
            mini = min(mini, ans);

        }
        dp[ind] = mini;
    }

    cout << dp[n-1] << endl;
    return ;

}

