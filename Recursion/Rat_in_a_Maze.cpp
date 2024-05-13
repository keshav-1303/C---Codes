/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. 
It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination.
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.                                     */

// https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool safe(vector<vector<int>> &m, int n, int x, int y, vector<vector<int>> visited){
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
    
        return true;

    return false;
}

void solve(vector<vector<int>> & m, int n, int x, int y, vector<string> &ans, string path, vector<vector<int>> visited){

    if (x == n - 1 && y == n - 1){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // down
    if (safe(m, n, x + 1, y, visited)){
        solve(m, n, x + 1, y, ans, path + "D", visited);
    }

    // left
    if (safe(m, n, x, y - 1, visited)){
        solve(m, n, x, y - 1, ans, path + "L", visited);
    }

    // right
    if (safe(m, n, x, y + 1, visited)){
        solve(m, n, x, y + 1, ans, path + "R", visited);
    }
    
    // up
    if (safe(m, n, x - 1, y, visited)){
        solve(m, n, x - 1, y, ans, path + "U", visited);
    }

    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> & m, int n){

    vector<vector<int>> visited = m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            visited[i][j] = 0;
        }
    }

    string path = "";

    vector<string> ans;

    if (m[0][0] == 0)    return ans;
    
    solve(m, n, 0, 0, ans, path, visited);

    return ans;
}

int main(){

    ll n = 4;
    
    vector<vector<int>> arr (n, vector<int> (n, 0));
    //                     (row)            (col)

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            int temp;    cin >> temp;
            arr[i][j] = temp;
        }
    }
    
    vector<string> ans;

    ans = findPath(arr, n);

    cout << endl << "Solutions are -- " << endl;

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }cout << endl;

    return 0;
}