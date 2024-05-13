// https://www.codingninjas.com/studio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>
using namespace std;

// Memoization-------------------------------------------------------------

int solve(int i, int j, int m, vector<vector<int>> matrix, vector<vector<int>> &dp){

    if(j<0 || j>=m)
        return -1e9;

    if(i == 0)
        return matrix[0][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int up = matrix[i][j] + solve(i-1,j,m,matrix,dp);
    int leftDiagonal = matrix[i][j] + solve(i-1,j-1,m,matrix,dp);
    int rightDiagonal = matrix[i][j] + solve(i-1,j+1,m,matrix,dp);
    
    return dp[i][j]= max(up,max(leftDiagonal,rightDiagonal));

}

int getMaxPathSum(vector<vector<int>> &mat){

    int row = mat.size();
    int col = mat[0].size();

    vector<vector<int>> dp(row+1, vector<int> (col+1, -1));
    int ans = INT_MIN;

    for (int j = col-1; j >= 0; j--) {
        ans = max(ans, solve(row-1, j, col, mat, dp));
    }

    return ans;
}

// Tabulation-------------------------------------------------------------

int getMaxPathSum(vector<vector<int>> &matrix){

    int row = matrix.size();
    int col = matrix[0].size();

    vector<vector<int>> dp(row, vector<int> (col, 0));
    int ans = INT_MIN;

    for(int j=0 ; j<col ; j++){
        dp[0][j] = matrix[0][j];
    }
    
    for (int i = 1; i < row; i++) {
        for (int j = 0 ; j < col; j++) {

            int up = matrix[i][j] + dp[i - 1][j];
            int leftDiagonal = (j >= 1) ? matrix[i][j] + dp[i - 1][j - 1] : -1e9;
            int rightDiagonal = (j <= col-2) ? matrix[i][j] + dp[i-1][j+1] : -1e9;

            dp[i][j]= max(up,max(leftDiagonal,rightDiagonal));
        }
    }

    for(int j=0 ; j<col ; j++){
        ans = max(ans, dp[row-1][j]);
    }

    return ans;
}

// Space Optimised --------------------------------------------------------

int getMaxPathSum(vector<vector<int>> &matrix){

    int row = matrix.size();
    int col = matrix[0].size();

    vector<int> prev(row, 0);
    vector<int> curr(col, 0);
    int ans = INT_MIN;

    for(int j=0 ; j<col ; j++){
        prev[j] = matrix[0][j];
    }
    
    for (int i = 1; i < row; i++) {
        for (int j = 0 ; j < col; j++) {

            int up = matrix[i][j] + prev[j];
            int leftDiagonal = (j >= 1) ? matrix[i][j] + prev[j-1] : -1e8;
            int rightDiagonal = (j <= col-2) ? matrix[i][j] + prev[j+1] : -1e8;

            curr[j] = max(up,max(leftDiagonal,rightDiagonal));
        }

        prev = curr;
    }

    for(int j=0 ; j<col ; j++){
        ans = max(ans, prev[j]);
    }

    return ans;
}

