// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<long long> printFirstNegativeInteger(ll arr[], ll, ll);

int main() {
    long long int t, i;
    
    long long int n;
    cin >> n;
    long long int arr[n];
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long int k;
    cin >> k;
    vector<long long> ans = printFirstNegativeInteger(arr, n, k);
    for (auto it : ans) cout << it << " ";
    cout << endl;

    return 0;
}

void print_queue(queue<ll> q){

    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

vector<ll> printFirstNegativeInteger(ll A[], ll N, ll K) {
                                                 
    queue<ll> q;
    
    vector<ll> ans;
    
    // process for 1st K sized window --------------------------------------------
    for(ll i=0 ; i<K ; i++){
        if(A[i] < 0)    q.push(i);
    }
    
    // store ans of 1st window ---------------------------------------------------
    if(q.size() > 0){
        ans.push_back(A[q.front()]);
    }
    else{
        ans.push_back(0);
    }

    // for remaining elements ----------------------------------------------------
    for(ll i=K ; i<N ; i++){
        
        // i - q.front() >= K matlab window ke bahar aa gaye
        if(!q.empty() && i - q.front() >= K){ 
            q.pop();
        }
        
        if(A[i] < 0){
            q.push(i);
        }
        
        // storing answer
        if(q.size() > 0){
            ans.push_back(A[q.front()]);
        }
        else{
            ans.push_back(0);
        }
    }

    return ans;                                           
}