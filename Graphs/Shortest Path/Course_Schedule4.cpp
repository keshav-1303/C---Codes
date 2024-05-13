#include <bits/stdc++.h>
using namespace std;

// ALL PAIR SHORTEST PATH problem

// https://leetcode.com/problems/course-schedule-iv/
vector<bool> checkIfPrerequisite(int N, vector<vector<int>>& pre, vector<vector<int>>& que) {
    // check the dist of [u, v] using Floyd Warshall if exist --> YES (my approach)
    vector<vector<int>> mat(N, vector<int> (N, 1e9));
    for(auto i : pre){
        int u = i[0], v = i[1];
        mat[u][v] = 1;
    }

    for(int i=0 ; i<N ; i++)    mat[i][i] = 0;
    for(int k=0 ; k<N ; k++){
        for(int i=0 ; i<N ; i++){
            for(int j=0 ; j<N ; j++){
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    vector<bool> ans;
    for(auto i : que){
        int u = i[0], v = i[1];
        if(mat[u][v] != 1e9)    ans.push_back(true);
        else    ans.push_back(false);
    }
    return ans;
}