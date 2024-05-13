#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=path-with-minimum-effort

// Myself ---------------------------------------
int minimumEffortPath(vector<vector<int>>& arr) {
    int n = arr.size(), m = arr[0].size();

    if(n == 1){
        int maxdiff = 0;
        for(int i=0 ; i<m-1 ; i++){
            maxdiff = max(maxdiff, abs(arr[0][i] - arr[0][i+1]));
        }
        return maxdiff;
    }
    if(m == 1){
        int maxdiff = 0;
        for(int i=0 ; i<n-1 ; i++){
            maxdiff = max(maxdiff, abs(arr[i][0] - arr[i+1][0]));
        }
        return maxdiff;
    }

    set<pair<int, pair<int, int>>> S;
    vector<vector<int>> vis(n, vector<int> (m, 1e9));
    vis[0][0] = 0;
    vis[1][0] = abs(arr[1][0] - arr[0][0]);
    vis[0][1] = abs(arr[0][1] - arr[0][0]);
    S.insert({vis[1][0], {1, 0}});
    S.insert({vis[0][1], {0, 1}});

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while(!S.empty()){
        auto it = *S.begin();
        int Dist = it.first;
        int x = it.second.first;
        int y = it.second.second;
        vis[x][y] = min(vis[x][y], Dist);
        S.erase(it);

        for(int i=0 ; i<4 ; i++){
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X >= 0 && X < n && Y >= 0 && Y < m && vis[X][Y] == 1e9){
                int effort = abs(arr[X][Y] - arr[x][y]);
                S.insert({max(effort, Dist), {X, Y}});
            }
        }
    }
    return vis[n-1][m-1];
}

int MinimumEffort(vector<vector<int>>& heights) {
        
    int m = heights[0].size();
    int n = heights.size();
    
    vector<vector<int>> maxDiff (n, vector<int> (m, 1e9));
    maxDiff[0][0] = 0;
    
    set<pair<int,pair<int,int>>> st;
    st.insert({0,{0,0}});
    
    int drow[] = {0, -1, 0, 1};
    int dcol[] = {-1, 0, 1, 0};
    
    while(!st.empty()) {
        auto it = *(st.begin());
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;
        st.erase(it);
        
        if(row == n-1 && col == m-1)    return diff;
        
        for(int i=0 ; i<4 ; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow >= 0 &&  nrow < n && ncol >= 0 && ncol < m) {
                int ndiff = abs(heights[row][col] - heights[nrow][ncol]);
                ndiff = max(diff, ndiff);
                
                if(ndiff < maxDiff[nrow][ncol]) {
                    if(maxDiff[nrow][ncol] != 1e9) {
                        st.erase( {maxDiff[nrow][ncol], {nrow,ncol}} );
                    }
                    maxDiff[nrow][ncol] = ndiff;
                    st.insert({ndiff, {nrow,ncol}});
                }
            }
        }
    }
    
    return 0;
}