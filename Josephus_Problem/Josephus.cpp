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

/*
Given the total number of children n, a number i to start the counting from and a number k which indicates that k-1 children are skipped in each turn and the k-th child exits the circle. 
The task is to find the place in the initial circle (winning position), so that the child standing there would be the winner at last
*/

int solve(int n, int i, int k){

    if(n == 1)   return 1;

    return (i + solve(n-1, i, k) + k - 1) % n + 1;
}

int main(){

    int n, k, i;

    cout << "Enter n : ";     cin >> n;
    cout << "Enter k : ";     cin >> k;
    cout << "Enter i : ";     cin >> i;

    cout << solve(n, i - 1, k) << endl;
 
    return 0;
}

