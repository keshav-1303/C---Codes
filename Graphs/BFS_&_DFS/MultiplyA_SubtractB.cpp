#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/520/B

// Find minimum moves to make n to m.
// You can perform n = n * 2 OR n = n + 1;
// here a = 2, b = 1;

signed main(){

    int n, m;    cin >> n >> m;

    vector<int> steps(2e4+2, -1);
    queue<int> q;
    q.push(n); steps[n] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        if(node == m) { 
            cout << steps[node] << endl;
            return 0;
        }

        int first = node*2 , second = node-1 ;

        if(first <= 2e4 + 1 && steps[first] == -1 ) {
            q.push(first) ; 
            steps[first] = steps[node] + 1 ; 
        }
        if(second > 0 && steps[second ] == -1 ) {
            q.push(second) ; 
            steps[second] = steps[node] + 1 ; 
        }
    }

    return 0;
}
