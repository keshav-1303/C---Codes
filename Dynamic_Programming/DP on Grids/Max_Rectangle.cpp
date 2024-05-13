// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

#include <bits/stdc++.h>
using namespace std;

// Memoization------------------------------------------------------------------
int solve(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp){
    
    if(i >= mat.size() || j >= mat[0].size()){
        return 0;
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int right = solve(mat, i, j+1, maxi, dp);
    int down = solve(mat, i+1, j, maxi, dp);
    int diagonal = solve(mat, i+1, j+1, maxi, dp);
    
    if(mat[i][j] == 1){
        int ans = 1 + min(diagonal, min(right, down));
        maxi = max(maxi, ans);
        return dp[i][j] = ans;
    }
    
    else{
        return 0;
    }
}

int maxSquare(int n, int m, vector<vector<int>> mat){
    
    int maxi = 0;
    
    vector<vector<int>> dp (n, vector<int>(m, -1));
    solve(mat, 0, 0, maxi, dp);
    
    return maxi;
}

// Tabulation----------------------------------------------------------------
int maxSquare(int n, int m, vector<vector<int>> mat){
        
    int maxi = 0;
    
    vector<vector<int>> dp (n+1, vector<int>(m+1, 0));   // S.C = O(n * m)
        
    for(int i=n-1 ; i>=0 ; i--){
        for(int j=m-1 ; j>=0 ; j--){
            
            int right = dp[i][j+1];
            int down = dp[i+1][j];
            int diagonal = dp[i+1][j+1];
            
            if(mat[i][j] == 1){
                int ans = 1 + min(diagonal, min(right, down));
                maxi = max(maxi, ans);
                dp[i][j] = ans;
            }

            else{
                dp[i][j] = 0;
            }
        }
    }
    
    return maxi;
}

// Space Optimised in O(m) --------------------------------------------------------

int maxSquare(int n, int m, vector<vector<int>> mat){
        
    int maxi = 0;

    // n, m <= 50. We can use vector<int> curr(51, 0), next(51, 0) for
    // O(1) Space Complexity as no extra space is created.
    
    vector<int> curr(m+1, 0);  
    vector<int> next(m+1, 0);
        
    for(int i=n-1 ; i>=0 ; i--){
        for(int j=m-1 ; j>=0 ; j--){
            
            int right = curr[j+1];
            int down = next[j];
            int diagonal = next[j+1];
            
            if(mat[i][j] == 1){
                int ans = 1 + min(diagonal, min(right, down));
                maxi = max(maxi, ans);
                curr[j] = ans;
            }

            else{
                curr[j] = 0;
            }
        }
        
        next = curr;
    }
    
    return maxi;
}
