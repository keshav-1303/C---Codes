#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
using namespace std;
#define inputArr(arr, n)   for( auto i = 0 ; i < n ;  i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define printarr(arr, n)    for(int i=0 ; i<n ; i++) {cout << arr[i] << " ";}  cout << endl; 
#define printmap(m)    for(auto i : m){ cout << i.first << " : " << i.second << endl; }

int fib(int n){
    if(n == 1 || n == 0)    return n;
    return fib(n - 1) + fib(n - 2);
}

int fib_Memoization(int n, vector<int> &dp){  // TC = O(n)    SC = O(n)
    if(n == 1 || n == 0)    return n;

    if(dp[n] != -1)   return dp[n];

    return dp[n] = fib(n - 1) + fib(n - 2);
}

int fib_Tabulation(int n, vector<int> &dp){  // TC = O(n)    SC = O(n)
    if(n == 1 || n == 0)    return n;

    if(dp[n] != -1)   return dp[n];

    return dp[n] = dp[n - 1] + dp[n - 2];
}

int main(){

    int n;    
    cout << "Enter n : ";    cin >> n;

    vector<int> dp(n+1, -1);
    dp[0] = 0;    dp[1] = 1;

    // By DP -->
    for(int i=0 ; i<n ; i++){
        cout << fib_Tabulation(i, dp) << " ";
    }
    cout << endl;
 
    return 0;
}

