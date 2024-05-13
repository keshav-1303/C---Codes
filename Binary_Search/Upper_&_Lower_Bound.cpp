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

// Function to implement lower_bound
ll lower_bound(vector<ll> &arr, ll N, ll X){
    ll mid;
    ll start = 0;
    ll end = N;
 
    while (start < end) {
        mid = start + (end - start) / 2;

        if (X <= arr[mid])    end = mid;

        else    start = mid + 1;
    }
   
    // if X is greater than arr[n-1]
    if(start < N && arr[start] < X) {
       start++;
    }
    
    return start;
}
 
// Function to implement upper_bound
ll upper_bound(vector<ll> &arr, ll N, ll X){
    ll mid;
    ll start = 0;
    ll end = N;

    while (start < end) {
        mid = start + (end - start) / 2;

        if (X >= arr[mid])    start = mid + 1;
        
        else    end = mid;
    }
   
    // if X is greater than arr[n-1]
    if(start < N && arr[start] <= X) {
       start++;
    }

    return start;
}

int main(){
 
    
    return 0;
}
 