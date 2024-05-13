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

// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

int Is_Celebrity(vector<vector<int>> &M, int n) {
    
    stack<int> s;

    for(int i=0 ; i<n ; i++){
        s.push(i);
    }
    
    while(s.size() > 1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        
        if(M[a][b]){    // a cannot be the celeb
            s.push(b);
        }
        
        else{
            s.push(a);
        }
    }
    
    // Now single element left will be the potential celeb
    
    int celeb = s.top();
    
    bool ColCheck = 1;
    
    for(int i=0 ; i<n ; i++){
        if(i != celeb){
            if(M[i][celeb] == 0){
                ColCheck = 0;
                break;
            }
        }
    }
    
    bool RowCheck = 1;
    
    for(int i=0 ; i<n ; i++){
        if(M[celeb][i] == 1){
            RowCheck = 0;
            break;
        }
    }
    
    if(!RowCheck || !ColCheck)     return -1;
    return celeb;
}

int main(){

    int n = 3;

    vector<vector<int>> M = { {0, 0, 0},
                              {0, 0, 0},
                              {0, 0, 0} };

    // vector<vector<int>> M = { {0, 1, 0},
    //                           {0, 0, 0},
    //                           {0, 1, 0} }

    cout << Is_Celebrity(M, n) << endl;
}