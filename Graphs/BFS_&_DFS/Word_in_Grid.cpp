// Check is a word is present in GRID or not?
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-search/?envType=daily-question&envId=2024-04-03

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool dfs(int ind, int i, int j, vector<vector<char>>& arr, string s){
    if(ind == s.size())   return 1;
    int n = arr.size(), m = arr[0].size();
    char temp = arr[i][j];
    arr[i][j] = '*';    // to mark vivited cell
    for(int k=0 ; k<4 ; k++){
        int x = i+dx[k];
        int y = j+dy[k];
        if(x >= 0 && x < n && y >= 0 && y < m){
            if(s[ind] == arr[x][y]){
                if(dfs(ind+1, x, y, arr, s))    return true;
            }
        }
    }
    arr[i][j] = temp;
    return 0;
}

bool exist(vector<vector<char>> &arr, string s) {
    int n = arr.size(), m = arr[0].size();
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(arr[i][j] == s[0]){
                if(dfs(1, i, j, arr, s))    return true;
            }
        }
    }
    return false;
}
