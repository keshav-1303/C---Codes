#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
    
    priority_queue<int> pq;
    
    for(int i=0 ; i<N ; i++)
        for(int j=0 ; j<N ; j++)
            pq.push(-1 * Mat[i][j]);
            
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            Mat[i][j] = -1 * pq.top();
            pq.pop();
        }
    }
    
    return Mat;
}

#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
using namespace std;
#define inputArr(arr, n)   for( auto i = 0 ; i < n ;  i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
#define printmap(m)    for(auto i : m){ cout << i.first << " : " << i.second << endl; }

int main(){
 
    
    return 0;
}

